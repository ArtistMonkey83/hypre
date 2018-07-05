/*BHEADER**********************************************************************
 * Copyright (c) 2008,  Lawrence Livermore National Security, LLC.
 * Produced at the Lawrence Livermore National Laboratory.
 * This file is part of HYPRE.  See file COPYRIGHT for details.
 *
 * HYPRE is free software; you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License (as published by the Free
 * Software Foundation) version 2.1 dated February 1999.
 *
 * $Revision$
 ***********************************************************************EHEADER*/


#include "_hypre_parcsr_ls.h"
#include "par_amg.h"
#include "par_csr_block_matrix.h"	

HYPRE_Int
AddSolution( void *amg_vdata );

HYPRE_Int
ZeroInitialGuess( void *amg_vdata );

HYPRE_Int
PackResidualBuffer( HYPRE_Int proc, HYPRE_Complex *send_buffer, HYPRE_Int **send_flag, HYPRE_Int *num_send_nodes, hypre_ParCompGrid **compGrid, hypre_ParCompGridCommPkg *compGridCommPkg, HYPRE_Int processor, HYPRE_Int current_level, HYPRE_Int num_levels );

HYPRE_Int
UnpackResidualBuffer( HYPRE_Int proc, HYPRE_Complex *recv_buffer, HYPRE_Int **recv_map, hypre_ParCompGrid **compGrid, HYPRE_Int current_level, HYPRE_Int num_levels );

HYPRE_Int
hypre_BoomerAMGDD_Cycle( void *amg_vdata, HYPRE_Int num_comp_cycles, HYPRE_Int plot_iteration, HYPRE_Int first_iteration )
{
	HYPRE_Int   myid;
	hypre_MPI_Comm_rank(hypre_MPI_COMM_WORLD, &myid );

	HYPRE_Int i,j,k,level;
	hypre_ParAMGData	*amg_data = amg_vdata;
	hypre_ParCompGrid 	**compGrid = hypre_ParAMGDataCompGrid(amg_data);
  	HYPRE_Int num_levels = hypre_ParAMGDataNumLevels(amg_data);

	// Form residual and do residual communication
	if (!first_iteration) hypre_BoomerAMGDDResidualCommunication( amg_vdata );

	// Set zero initial guess for all comp grids on all levels
	ZeroInitialGuess( amg_vdata );

	// Do the cycles
	for (i = 0; i < num_comp_cycles; i++)
	{
		hypre_BoomerAMGDD_FAC_Cycle( amg_vdata );
	}

	// Update fine grid solution
	AddSolution( amg_vdata );

	return 0;
}

HYPRE_Int
AddSolution( void *amg_vdata )
{
	hypre_ParAMGData	*amg_data = amg_vdata;
   	HYPRE_Complex 		*u = hypre_VectorData( hypre_ParVectorLocalVector( hypre_ParAMGDataUArray(amg_data)[0] ) );
   	hypre_ParCompGrid 	**compGrid = hypre_ParAMGDataCompGrid(amg_data);
   	HYPRE_Complex 		*u_comp = hypre_ParCompGridU(compGrid[0]);
   	HYPRE_Int 			num_owned_nodes = hypre_ParCompGridNumOwnedNodes(compGrid[0]);
   	HYPRE_Int 			i;

   	for (i = 0; i < num_owned_nodes; i++) u[i] += u_comp[i];

   	return 0;
}

HYPRE_Int
ZeroInitialGuess( void *amg_vdata )
{
	HYPRE_Int   myid;
	hypre_MPI_Comm_rank(hypre_MPI_COMM_WORLD, &myid );

	hypre_ParAMGData	*amg_data = amg_vdata;
   	hypre_ParCompGrid 	**compGrid = hypre_ParAMGDataCompGrid(amg_data);
   	HYPRE_Int 			num_nodes;
   	HYPRE_Int 			i, level;
   	HYPRE_Int 			num_levels = hypre_ParAMGDataNumLevels(amg_data);

   	for (level = 0; level < num_levels; level++)
   	{
   		num_nodes = hypre_ParCompGridNumNodes(compGrid[level]);

   		for (i = 0; i < num_nodes; i++) hypre_ParCompGridU(compGrid[level])[i] = 0.0;
   	}

   	return 0;
}

HYPRE_Int 
hypre_BoomerAMGDDResidualCommunication( void *amg_vdata )
{
   HYPRE_Int   myid;
   hypre_MPI_Comm_rank(hypre_MPI_COMM_WORLD, &myid );

   #if DEBUGGING_MESSAGES
   hypre_printf("Began residual communication on rank %d\n", myid);
   #endif

   MPI_Comm          comm;
   hypre_ParAMGData   *amg_data = amg_vdata;
   
   /* Data Structure variables */

   // level counters, indices, and parameters
   HYPRE_Int                  num_levels;
   HYPRE_Real                 alpha, beta;
   HYPRE_Int                  level,i;

   // info from amg
   hypre_ParCSRMatrix         **A_array;
   hypre_ParVector            **F_array;
   hypre_ParVector            **U_array;
   hypre_ParCSRMatrix         **P_array;
   hypre_ParVector            *Vtemp;
   HYPRE_Int                  *proc_first_index, *proc_last_index;
   HYPRE_Int                  *global_nodes;
   hypre_ParCompGrid          **compGrid;

   // info from comp grid comm pkg
   hypre_ParCompGridCommPkg   *compGridCommPkg;
   HYPRE_Int                  num_sends, num_recvs;
   HYPRE_Int                  **send_procs;
   HYPRE_Int                  **recv_procs;
   HYPRE_Int                  **send_buffer_size;
   HYPRE_Int                  **recv_buffer_size;
   HYPRE_Int                  ***num_send_nodes;
   HYPRE_Int                  ****send_flag;
   HYPRE_Int                  ****recv_map;

   // temporary arrays used for communication during comp grid setup
   HYPRE_Complex              **send_buffer;
   HYPRE_Complex              **recv_buffer;

   // temporary vectors used to copy data into composite grid structures
   hypre_Vector      *residual_local;
   HYPRE_Complex     *residual_data;

   // mpi stuff
   hypre_MPI_Request          *requests;
   hypre_MPI_Status           *status;
   HYPRE_Int                  request_counter = 0;

   // get info from amg
   A_array = hypre_ParAMGDataAArray(amg_data);
   P_array = hypre_ParAMGDataPArray(amg_data);
   F_array = hypre_ParAMGDataFArray(amg_data);
   U_array = hypre_ParAMGDataUArray(amg_data);
   Vtemp = hypre_ParAMGDataVtemp(amg_data);
   num_levels = hypre_ParAMGDataNumLevels(amg_data);
   compGrid = hypre_ParAMGDataCompGrid(amg_data);
   compGridCommPkg = hypre_ParAMGDataCompGridCommPkg(amg_data);

   // get info from comp grid comm pkg
   send_procs = hypre_ParCompGridCommPkgSendProcs(compGridCommPkg);
   recv_procs = hypre_ParCompGridCommPkgRecvProcs(compGridCommPkg);
   send_buffer_size = hypre_ParCompGridCommPkgSendBufferSize(compGridCommPkg);
   recv_buffer_size = hypre_ParCompGridCommPkgRecvBufferSize(compGridCommPkg);
   num_send_nodes = hypre_ParCompGridCommPkgNumSendNodes(compGridCommPkg);
   send_flag = hypre_ParCompGridCommPkgSendFlag(compGridCommPkg);
   recv_map = hypre_ParCompGridCommPkgRecvMap(compGridCommPkg);

   // get first and last global indices on each level for this proc
   proc_first_index = hypre_CTAlloc(HYPRE_Int, num_levels, HYPRE_MEMORY_HOST);
   proc_last_index = hypre_CTAlloc(HYPRE_Int, num_levels, HYPRE_MEMORY_HOST);
   global_nodes = hypre_CTAlloc(HYPRE_Int, num_levels, HYPRE_MEMORY_HOST);
   for (level = 0; level < num_levels; level++)
   {
      proc_first_index[level] = hypre_ParVectorFirstIndex(F_array[level]);
      proc_last_index[level] = hypre_ParVectorLastIndex(F_array[level]);
      global_nodes[level] = hypre_ParCSRMatrixGlobalNumRows(A_array[level]);
   }

   /* Form residual and restrict down to all levels and initialize composite grids 
      Note that from here on, residuals will be stored in F_array and the fine grid RHS will be stored in Vtemp */
   hypre_ParVectorCopy(F_array[0],Vtemp);
   alpha = -1.0;
   beta = 1.0;
   hypre_ParCSRMatrixMatvec(alpha, A_array[0], U_array[0],
                        beta, F_array[0]);

   for (level = 0; level < num_levels-1; level++)
   {
      alpha = 1.0;
      beta = 0.0;
      hypre_ParCSRMatrixMatvecT(alpha,P_array[level],F_array[level],
                            beta,F_array[level+1]);
   }

   // copy new restricted residual into comp grid structure
   for (level = 0; level < num_levels; level++)
   {
      // Access the residual data
      residual_local = hypre_ParVectorLocalVector(F_array[level]);
      residual_data = hypre_VectorData(residual_local);
      for (i = 0; i < hypre_VectorSize(residual_local); i++)
      {
         hypre_ParCompGridF(compGrid[level])[i] = residual_data[i];
      }
   }

   // Copy RHS back into F_array[0]
   hypre_ParVectorCopy(Vtemp,F_array[0]);

   /* Outer loop over levels:
   Start from coarsest level and work up to finest */
   for (level = num_levels-1; level > -1; level--)
   {      
      // Get some communication info
      comm = hypre_ParCSRMatrixComm(A_array[level]);
      num_sends = hypre_ParCompGridCommPkgNumSends(compGridCommPkg)[level];
      num_recvs = hypre_ParCompGridCommPkgNumRecvs(compGridCommPkg)[level];

      if ( proc_last_index[level] >= proc_first_index[level] && num_sends ) // If there are any owned nodes on this level
      {

         // allocate space for the buffers, buffer sizes, requests and status, psiComposite_send, psiComposite_recv, send and recv maps
         requests = hypre_CTAlloc(hypre_MPI_Request, num_sends + num_recvs, HYPRE_MEMORY_HOST );
         status = hypre_CTAlloc(hypre_MPI_Status, num_sends + num_recvs, HYPRE_MEMORY_HOST );
         request_counter = 0;
         send_buffer = hypre_CTAlloc(HYPRE_Complex*, num_sends, HYPRE_MEMORY_HOST);
         recv_buffer = hypre_CTAlloc(HYPRE_Complex*, num_recvs, HYPRE_MEMORY_HOST);


         // allocate space for the receive buffers and post the receives
         for (i = 0; i < num_recvs; i++)
         {
            recv_buffer[i] = hypre_CTAlloc(HYPRE_Complex, recv_buffer_size[level][i], HYPRE_MEMORY_HOST );
            hypre_MPI_Irecv( recv_buffer[i], recv_buffer_size[level][i], HYPRE_MPI_COMPLEX, recv_procs[level][i], 3, comm, &requests[request_counter++]);
         }

         // pack and send the buffers
         for (i = 0; i < num_sends; i++)
         {
            send_buffer[i] = hypre_CTAlloc(HYPRE_Complex, send_buffer_size[level][i], HYPRE_MEMORY_HOST);
            PackResidualBuffer(send_procs[level][i], send_buffer[i], send_flag[level][i], num_send_nodes[level][i], compGrid, compGridCommPkg, i, level, num_levels);
            hypre_MPI_Isend(send_buffer[i], send_buffer_size[level][i], HYPRE_MPI_COMPLEX, send_procs[level][i], 3, comm, &requests[request_counter++]);
         }

         // wait for buffers to be received
         hypre_MPI_Waitall( num_sends + num_recvs, requests, status );

         // loop over received buffers
         for (i = 0; i < num_recvs; i++)
         {
            // unpack the buffers
            UnpackResidualBuffer(recv_procs[level][i], recv_buffer[i], recv_map[level][i], compGrid, level, num_levels);
         }

         // clean up memory for this level
         hypre_TFree(requests, HYPRE_MEMORY_HOST);
         hypre_TFree(status, HYPRE_MEMORY_HOST);
         for (i = 0; i < num_sends; i++)
         {
            hypre_TFree(send_buffer[i], HYPRE_MEMORY_HOST);
         }
         for (i = 0; i < num_recvs; i++)
         {
            hypre_TFree(recv_buffer[i], HYPRE_MEMORY_HOST);
         }
         hypre_TFree(send_buffer, HYPRE_MEMORY_HOST);
         hypre_TFree(recv_buffer, HYPRE_MEMORY_HOST);
      }
   }

   #if DEBUGGING_MESSAGES
   hypre_printf("Finished residual communication on rank %d\n", myid);
   #endif

   // Cleanup memory
   hypre_TFree(proc_first_index, HYPRE_MEMORY_HOST);
   hypre_TFree(proc_last_index, HYPRE_MEMORY_HOST);
   hypre_TFree(global_nodes, HYPRE_MEMORY_HOST);
   
   return 0;
}

HYPRE_Int
PackResidualBuffer( HYPRE_Int proc, HYPRE_Complex *send_buffer, HYPRE_Int **send_flag, HYPRE_Int *num_send_nodes, hypre_ParCompGrid **compGrid, hypre_ParCompGridCommPkg *compGridCommPkg, HYPRE_Int processor, HYPRE_Int current_level, HYPRE_Int num_levels )
{
   HYPRE_Int                  level,i,cnt = 0;

   HYPRE_Int   myid;
   hypre_MPI_Comm_rank(hypre_MPI_COMM_WORLD, &myid );

   FILE *file;
   char filename[256];

   // pack the send buffer
   for (level = current_level; level < num_levels; level++)
   {
      sprintf(filename,"outputs/send_flag_rank%d_current_level%d_proc%d_level%d.txt", myid, current_level, proc, level);
      file = fopen(filename,"w");
      for (i = 0; i < num_send_nodes[level]; i++) fprintf(file, "%d ", hypre_ParCompGridGlobalIndices(compGrid[level])[ send_flag[level][i] ]);
      fclose(file);

      // store number of nodes to send on this level
      send_buffer[cnt++] = num_send_nodes[level];

      // pack up nodes marked in send_flag
      for (i = 0; i < num_send_nodes[level]; i++) send_buffer[cnt++] = hypre_ParCompGridF(compGrid[level])[ send_flag[level][i] ];
   }

   return 0;

}

HYPRE_Int
UnpackResidualBuffer( HYPRE_Int proc, HYPRE_Complex *recv_buffer, HYPRE_Int **recv_map, hypre_ParCompGrid **compGrid, HYPRE_Int current_level, HYPRE_Int num_levels)
{
   HYPRE_Int                  level,i,cnt = 0, map_cnt, num_nodes;

   HYPRE_Int   myid;
   hypre_MPI_Comm_rank(hypre_MPI_COMM_WORLD, &myid );

   FILE *file;
   char filename[256];

   // loop over levels
   for (level = current_level; level < num_levels; level++)
   {
      // get number of nodes to unpack on this level
      num_nodes = recv_buffer[cnt++];

      sprintf(filename,"outputs/recv_map_rank%d_current_level%d_proc%d_level%d.txt", myid, current_level, proc, level);
      file = fopen(filename,"w");
      for (i = 0; i < num_nodes; i++) fprintf(file, "%d ", hypre_ParCompGridGlobalIndices(compGrid[level])[ recv_map[level][i] ]);
      fclose(file);

      for (i = 0; i < num_nodes; i++)
      {
         hypre_ParCompGridF(compGrid[level])[ recv_map[level][i] ] = recv_buffer[cnt++];
      }
   }

   return 0;
}