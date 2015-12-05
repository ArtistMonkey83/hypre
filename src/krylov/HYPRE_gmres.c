/*BHEADER**********************************************************************
 * (c) 2000   The Regents of the University of California
 *
 * See the file COPYRIGHT_and_DISCLAIMER for a complete copyright
 * notice, contact person, and disclaimer.
 *
 * $Revision: 2.1 $
 *********************************************************************EHEADER*/

/******************************************************************************
 *
 * HYPRE_GMRES interface
 *
 *****************************************************************************/
#include "krylov.h"

/*--------------------------------------------------------------------------
 * HYPRE_GMRESDestroy
 *--------------------------------------------------------------------------*/
/* to do, not trivial */
/*
int 
HYPRE_ParCSRGMRESDestroy( HYPRE_Solver solver )
{
   return( hypre_GMRESDestroy( (void *) solver ) );
}
*/

/*--------------------------------------------------------------------------
 * HYPRE_GMRESSetup
 *--------------------------------------------------------------------------*/

int 
HYPRE_GMRESSetup( HYPRE_Solver solver,
                        HYPRE_Matrix A,
                        HYPRE_Vector b,
                        HYPRE_Vector x      )
{
   return( hypre_GMRESSetup( solver,
                             A,
                             b,
                             x ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_GMRESSolve
 *--------------------------------------------------------------------------*/

int 
HYPRE_GMRESSolve( HYPRE_Solver solver,
                        HYPRE_Matrix A,
                        HYPRE_Vector b,
                        HYPRE_Vector x      )
{
   return( hypre_GMRESSolve( solver,
                             A,
                             b,
                             x ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_GMRESSetKDim
 *--------------------------------------------------------------------------*/

int
HYPRE_GMRESSetKDim( HYPRE_Solver solver,
                          int             k_dim    )
{
   return( hypre_GMRESSetKDim( (void *) solver, k_dim ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_GMRESSetTol
 *--------------------------------------------------------------------------*/

int
HYPRE_GMRESSetTol( HYPRE_Solver solver,
                         double             tol    )
{
   return( hypre_GMRESSetTol( (void *) solver, tol ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_GMRESSetMinIter
 *--------------------------------------------------------------------------*/

int
HYPRE_GMRESSetMinIter( HYPRE_Solver solver,
                             int          min_iter )
{
   return( hypre_GMRESSetMinIter( (void *) solver, min_iter ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_GMRESSetMaxIter
 *--------------------------------------------------------------------------*/

int
HYPRE_GMRESSetMaxIter( HYPRE_Solver solver,
                             int          max_iter )
{
   return( hypre_GMRESSetMaxIter( (void *) solver, max_iter ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_GMRESSetStopCrit
 *--------------------------------------------------------------------------*/

int
HYPRE_GMRESSetStopCrit( HYPRE_Solver solver,
                              int          stop_crit )
{
   return( hypre_GMRESSetStopCrit( (void *) solver, stop_crit ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_GMRESSetRelChange
 *--------------------------------------------------------------------------*/

int
HYPRE_GMRESSetRelChange( HYPRE_Solver solver,
                         int                rel_change )
{
   return( hypre_GMRESSetRelChange( (void *) solver, rel_change ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_GMRESSetPrecond
 *--------------------------------------------------------------------------*/

int
HYPRE_GMRESSetPrecond( HYPRE_Solver          solver,
                             HYPRE_PtrToSolverFcn  precond,
                             HYPRE_PtrToSolverFcn  precond_setup,
                             HYPRE_Solver          precond_solver )
{
   return( hypre_GMRESSetPrecond( (void *) solver,
                                  precond, precond_setup,
                                  (void *) precond_solver ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_GMRESGetPrecond
 *--------------------------------------------------------------------------*/

int
HYPRE_GMRESGetPrecond( HYPRE_Solver  solver,
                             HYPRE_Solver *precond_data_ptr )
{
   return( hypre_GMRESGetPrecond( (void *)     solver,
                                  (HYPRE_Solver *) precond_data_ptr ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_GMRESSetLogging
 *--------------------------------------------------------------------------*/

int
HYPRE_GMRESSetLogging( HYPRE_Solver solver,
                             int logging)
{
   return( hypre_GMRESSetLogging( (void *) solver, logging ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_GMRESGetNumIterations
 *--------------------------------------------------------------------------*/

int
HYPRE_GMRESGetNumIterations( HYPRE_Solver  solver,
                                   int                *num_iterations )
{
   return( hypre_GMRESGetNumIterations( (void *) solver, num_iterations ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_GMRESGetFinalRelativeResidualNorm
 *--------------------------------------------------------------------------*/

int
HYPRE_GMRESGetFinalRelativeResidualNorm( HYPRE_Solver  solver,
                                               double             *norm   )
{
   return( hypre_GMRESGetFinalRelativeResidualNorm( (void *) solver, norm ) );
}
