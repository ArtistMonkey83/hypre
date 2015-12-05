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
 * $Revision: 2.3 $
 ***********************************************************************EHEADER*/




/******************************************************************************
 *
 * HYPRE_CSRPCG interface
 *
 *****************************************************************************/
#include "headers.h"
#include "krylov.h"

/*--------------------------------------------------------------------------
 * HYPRE_CSRPCGCreate
 *--------------------------------------------------------------------------*/

int
HYPRE_CSRPCGCreate( HYPRE_Solver *solver )
{
   /* The function names with a CG in them are in
      seq_ls/pamg/cg_fun.c .  These functions do rather little -
      e.g., cast to the correct type - before calling something else.
   */
   hypre_PCGFunctions * pcg_functions =
      hypre_PCGFunctionsCreate(
         hypre_CAlloc, hypre_CGFree, hypre_CGCommInfo,
         hypre_CGCreateVector,
         hypre_CGDestroyVector, hypre_CGMatvecCreate,
         hypre_CGMatvec, hypre_CGMatvecDestroy,
         hypre_CGInnerProd, hypre_CGCopyVector,
         hypre_CGClearVector,
         hypre_CGScaleVector, hypre_CGAxpy,
         hypre_CGIdentitySetup, hypre_CGIdentity );

   *solver = ( (HYPRE_Solver) hypre_PCGCreate( pcg_functions ) );

   return 0;
}

/*--------------------------------------------------------------------------
 * HYPRE_CSRPCGDestroy
 *--------------------------------------------------------------------------*/

int 
HYPRE_CSRPCGDestroy( HYPRE_Solver solver )
{
   return( hypre_PCGDestroy( (void *) solver ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_CSRPCGSetup
 *--------------------------------------------------------------------------*/

int 
HYPRE_CSRPCGSetup( HYPRE_Solver solver,
                      HYPRE_CSRMatrix A,
                      HYPRE_Vector b,
                      HYPRE_Vector x      )
{
   return( HYPRE_PCGSetup( solver,
                           (HYPRE_Matrix) A,
                           b, x ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_CSRPCGSolve
 *--------------------------------------------------------------------------*/

int 
HYPRE_CSRPCGSolve( HYPRE_Solver solver,
                      HYPRE_CSRMatrix A,
                      HYPRE_Vector b,
                      HYPRE_Vector x      )
{
   return( HYPRE_PCGSolve( solver,
                           (HYPRE_Matrix) A,
                           b, x ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_CSRPCGSetTol
 *--------------------------------------------------------------------------*/

int
HYPRE_CSRPCGSetTol( HYPRE_Solver solver,
                       double             tol    )
{
   return( HYPRE_PCGSetTol( solver, tol ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_CSRPCGSetMaxIter
 *--------------------------------------------------------------------------*/

int
HYPRE_CSRPCGSetMaxIter( HYPRE_Solver solver,
                           int                max_iter )
{
   return( HYPRE_PCGSetMaxIter( solver, max_iter ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_CSRPCGSetStopCrit
 *--------------------------------------------------------------------------*/

/* not supported by krylov/pcg.c.  was supported by old cg.c.  TO DO:
 decide whether this has any functionality. If so, add the parameter and
 implement this function.  If not, delete this function.
int
HYPRE_CSRPCGSetStopCrit( HYPRE_Solver solver,
                           int          stop_crit )
{
   return( hypre_PCGSetStopCrit( (void *) solver, stop_crit ) );
}
*/

/*--------------------------------------------------------------------------
 * HYPRE_CSRPCGSetTwoNorm
 *--------------------------------------------------------------------------*/

int
HYPRE_CSRPCGSetTwoNorm( HYPRE_Solver solver,
                           int                two_norm )
{
   return( HYPRE_PCGSetTwoNorm( solver, two_norm ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_CSRPCGSetRelChange
 *--------------------------------------------------------------------------*/

int
HYPRE_CSRPCGSetRelChange( HYPRE_Solver solver,
                             int                rel_change )
{
   return( HYPRE_PCGSetRelChange( solver, rel_change ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_CSRPCGSetPrecond
 *--------------------------------------------------------------------------*/

int
HYPRE_CSRPCGSetPrecond( HYPRE_Solver  solver,
                           int (*precond)      (HYPRE_Solver sol,
						HYPRE_CSRMatrix matrix,
						HYPRE_Vector b,
						HYPRE_Vector x),
                           int (*precond_setup)(HYPRE_Solver sol,
						HYPRE_CSRMatrix matrix,
						HYPRE_Vector b,
						HYPRE_Vector x),
                           void                *precond_data )
{
   return( HYPRE_PCGSetPrecond( solver,
                                (HYPRE_PtrToSolverFcn) precond,
                                (HYPRE_PtrToSolverFcn) precond_setup,
                                (HYPRE_Solver) precond_data ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_CSRPCGGetPrecond
 *--------------------------------------------------------------------------*/

int
HYPRE_CSRPCGGetPrecond( HYPRE_Solver  solver,
                           HYPRE_Solver *precond_data_ptr )
{
   return( HYPRE_PCGGetPrecond( solver, precond_data_ptr ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_CSRPCGSetLogging
 *--------------------------------------------------------------------------*/

int
HYPRE_CSRPCGSetLogging( HYPRE_Solver solver,
                           int                logging )
{
   return( HYPRE_PCGSetLogging( solver, logging ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_CSRPCGGetNumIterations
 *--------------------------------------------------------------------------*/

int
HYPRE_CSRPCGGetNumIterations( HYPRE_Solver  solver,
                                 int                *num_iterations )
{
   return( HYPRE_PCGGetNumIterations( solver, num_iterations ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_CSRPCGGetFinalRelativeResidualNorm
 *--------------------------------------------------------------------------*/

int
HYPRE_CSRPCGGetFinalRelativeResidualNorm( HYPRE_Solver  solver,
                                             double             *norm   )
{
   return( HYPRE_PCGGetFinalRelativeResidualNorm( solver, norm ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_CSRDiagScaleSetup
 *--------------------------------------------------------------------------*/
 
int 
HYPRE_CSRDiagScaleSetup( HYPRE_Solver solver,
                            HYPRE_CSRMatrix A,
                            HYPRE_Vector y,
                            HYPRE_Vector x      )
{
   return 0;
}
 
/*--------------------------------------------------------------------------
 * HYPRE_CSRDiagScale
 *--------------------------------------------------------------------------*/
 
int 
HYPRE_CSRDiagScale( HYPRE_Solver solver,
                       HYPRE_CSRMatrix HA,
                       HYPRE_Vector Hy,
                       HYPRE_Vector Hx      )
{
   hypre_CSRMatrix *A = (hypre_CSRMatrix *) HA;
   hypre_Vector    *y = (hypre_Vector *) Hy;
   hypre_Vector    *x = (hypre_Vector *) Hx;
   double *x_data = hypre_VectorData(x);
   double *y_data = hypre_VectorData(y);
   double *A_data = hypre_CSRMatrixData(A);
   int *A_i = hypre_CSRMatrixI(A);

   int i, ierr = 0;

   for (i=0; i < hypre_VectorSize(x); i++)
   {
	x_data[i] = y_data[i]/A_data[A_i[i]];
   } 
 
   return ierr;
}
