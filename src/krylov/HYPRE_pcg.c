/*BHEADER**********************************************************************
 * (c) 2000   The Regents of the University of California
 *
 * See the file COPYRIGHT_and_DISCLAIMER for a complete copyright
 * notice, contact person, and disclaimer.
 *
 * $Revision: 2.9 $
 *********************************************************************EHEADER*/

/******************************************************************************
 *
 * HYPRE_PCG interface
 *
 *****************************************************************************/
#include "krylov.h"

/*--------------------------------------------------------------------------
 * HYPRE_PCGCreate does not exist.  Call the appropriate function which
 * also specifies the vector type, e.g. HYPRE_ParCSRPCGCreate
 *--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
 * HYPRE_PCGDestroy
 *--------------------------------------------------------------------------*/

/*
int 
HYPRE_PCGDestroy( HYPRE_Solver solver )*/
/* >>> This is something we can't do without knowing the vector_type.
   We can't save it in and pull it out of solver because that isn't
   really a known struct. */
/*
{
   if ( vector_type=="ParCSR" ) {
      return HYPRE_ParCSRPCGDestroy( HYPRE_Solver solver );
   }
   else {
      return 0;
   }
}*/

/*--------------------------------------------------------------------------
 * HYPRE_PCGSetup
 *--------------------------------------------------------------------------*/

int 
HYPRE_PCGSetup( HYPRE_Solver solver,
                HYPRE_Matrix A,
                HYPRE_Vector b,
                HYPRE_Vector x      )
{
   return( hypre_PCGSetup( solver,
                           A,
                           b,
                           x ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_PCGSolve
 *--------------------------------------------------------------------------*/

int 
HYPRE_PCGSolve( HYPRE_Solver solver,
                HYPRE_Matrix A,
                HYPRE_Vector b,
                HYPRE_Vector x      )
{
   return( hypre_PCGSolve( (void *) solver,
                           (void *) A,
                           (void *) b,
                           (void *) x ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_PCGSetTol
 *--------------------------------------------------------------------------*/

int
HYPRE_PCGSetTol( HYPRE_Solver solver,
                 double             tol    )
{
   return( hypre_PCGSetTol( (void *) solver, tol ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_PCGSetAbsoluteTolFactor
 *--------------------------------------------------------------------------*/

int
HYPRE_PCGSetAbsoluteTolFactor( HYPRE_Solver solver,
                               double abstolf )
{
   return( hypre_PCGSetAbsoluteTolFactor( (void *) solver, abstolf ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_PCGSetConvergenceFactorTol
 *--------------------------------------------------------------------------*/
int
HYPRE_PCGSetConvergenceFactorTol( HYPRE_Solver solver,
                                  double cf_tol )
{
   return hypre_PCGSetConvergenceFactorTol( (void *) solver,
                                            cf_tol   );
}

/*--------------------------------------------------------------------------
 * HYPRE_PCGSetMaxIter
 *--------------------------------------------------------------------------*/

int
HYPRE_PCGSetMaxIter( HYPRE_Solver solver,
                     int                max_iter )
{
   return( hypre_PCGSetMaxIter( (void *) solver, max_iter ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_PCGSetStopCrit
 *--------------------------------------------------------------------------*/

int
HYPRE_PCGSetStopCrit( HYPRE_Solver solver,
                      int          stop_crit )
{
   return( hypre_PCGSetStopCrit( (void *) solver, stop_crit ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_PCGSetTwoNorm
 *--------------------------------------------------------------------------*/

int
HYPRE_PCGSetTwoNorm( HYPRE_Solver solver,
                     int                two_norm )
{
   return( hypre_PCGSetTwoNorm( (void *) solver, two_norm ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_PCGSetRelChange
 *--------------------------------------------------------------------------*/

int
HYPRE_PCGSetRelChange( HYPRE_Solver solver,
                       int                rel_change )
{
   return( hypre_PCGSetRelChange( (void *) solver, rel_change ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_PCGSetPrecond
 *--------------------------------------------------------------------------*/

int
HYPRE_PCGSetPrecond( HYPRE_Solver         solver,
                     HYPRE_PtrToSolverFcn precond,
                     HYPRE_PtrToSolverFcn precond_setup,
                     HYPRE_Solver         precond_solver )
{
   return( hypre_PCGSetPrecond( (void *) solver,
                                precond, precond_setup,
                                (void *) precond_solver ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_PCGGetPrecond
 *--------------------------------------------------------------------------*/

int
HYPRE_PCGGetPrecond( HYPRE_Solver  solver,
                     HYPRE_Solver *precond_data_ptr )
{
   return( hypre_PCGGetPrecond( (void *)     solver,
                                (HYPRE_Solver *) precond_data_ptr ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_PCGSetLogging
 * sets both the print and log level, for backwards compatibility.
 * Soon the SetPrintLevel call should be deleted.
 *--------------------------------------------------------------------------*/

int
HYPRE_PCGSetLogging( HYPRE_Solver solver,
                     int          level )
{
   return ( hypre_PCGSetLogging( (void *) solver, level ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_PCGSetPrintLevel
 *--------------------------------------------------------------------------*/

int
HYPRE_PCGSetPrintLevel( HYPRE_Solver solver,
                        int          level )
{
   return( hypre_PCGSetPrintLevel( (void *) solver, level ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_PCGGetNumIterations
 *--------------------------------------------------------------------------*/

int
HYPRE_PCGGetNumIterations( HYPRE_Solver  solver,
                           int                *num_iterations )
{
   return( hypre_PCGGetNumIterations( (void *) solver, num_iterations ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_PCGGetFinalRelativeResidualNorm
 *--------------------------------------------------------------------------*/

int
HYPRE_PCGGetFinalRelativeResidualNorm( HYPRE_Solver  solver,
                                       double             *norm   )
{
   return( hypre_PCGGetFinalRelativeResidualNorm( (void *) solver, norm ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_PCGGetResidual
 *--------------------------------------------------------------------------*/

int HYPRE_PCGGetResidual( HYPRE_Solver solver, void **residual )
{
   /* returns a pointer to the residual vector */
   return hypre_PCGGetResidual( (void *) solver, residual );
}

