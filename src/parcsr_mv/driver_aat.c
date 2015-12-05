/*BHEADER**********************************************************************
 * Copyright (c) 2006   The Regents of the University of California.
 * Produced at the Lawrence Livermore National Laboratory.
 * Written by the HYPRE team. UCRL-CODE-222953.
 * All rights reserved.
 *
 * This file is part of HYPRE (see http://www.llnl.gov/CASC/hypre/).
 * Please see the COPYRIGHT_and_LICENSE file for the copyright notice, 
 * disclaimer, contact information and the GNU Lesser General Public License.
 *
 * HYPRE is free software; you can redistribute it and/or modify it under the 
 * terms of the GNU General Public License (as published by the Free Software
 * Foundation) version 2.1 dated February 1999.
 *
 * HYPRE is distributed in the hope that it will be useful, but WITHOUT ANY 
 * WARRANTY; without even the IMPLIED WARRANTY OF MERCHANTABILITY or FITNESS 
 * FOR A PARTICULAR PURPOSE.  See the terms and conditions of the GNU General
 * Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * $Revision: 2.4 $
 ***********************************************************************EHEADER*/



#include "headers.h" 
 
/*--------------------------------------------------------------------------
 * Test driver for unstructured matrix interface , A * A^T
 *--------------------------------------------------------------------------*/
 
int
main( int   argc,
      char *argv[] )
{
   hypre_ParCSRMatrix     *A;
   hypre_ParCSRMatrix     *C;
   hypre_CSRMatrix *As;
   int *row_starts, *col_starts;
   int num_procs, my_id;

   /* Initialize MPI */
   MPI_Init(&argc, &argv);

   MPI_Comm_size(MPI_COMM_WORLD,&num_procs);
   MPI_Comm_rank(MPI_COMM_WORLD,&my_id);
   row_starts = NULL;
   col_starts = NULL;

   if (my_id == 0)
   {
   	As = hypre_CSRMatrixRead("inpr");
   	printf(" read input A\n");
   }
   A = hypre_CSRMatrixToParCSRMatrix(MPI_COMM_WORLD, As, row_starts,
	col_starts);
   row_starts = hypre_ParCSRMatrixRowStarts(A);
   col_starts = hypre_ParCSRMatrixColStarts(A);

   hypre_ParCSRMatrixPrint(A, "echo_A" );
   hypre_ParCSRMatrixPrintIJ(A, 0, 0, "echo_AIJ" );
   C = hypre_ParCSRAAt( A );
   hypre_ParCSRMatrixPrint(C, "result");
   hypre_ParCSRMatrixPrintIJ(C, 0, 0, "resultIJ");

   if (my_id == 0)
   {
	hypre_CSRMatrixDestroy(As);
   }
   hypre_ParCSRMatrixDestroy(A);
   hypre_ParCSRMatrixDestroy(C);

   MPI_Finalize();

   return 0;
}

