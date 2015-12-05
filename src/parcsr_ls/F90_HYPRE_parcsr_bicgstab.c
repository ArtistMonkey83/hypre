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
 * $Revision: 2.5 $
 ***********************************************************************EHEADER*/



/******************************************************************************
 *
 * HYPRE_ParCSRBiCGSTAB Fortran interface
 *
 *****************************************************************************/

#include "headers.h"
#include "fortran.h"

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABCreate
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_parcsrbicgstabcreate, HYPRE_PARCSRBICGSTABCREATE)( int      *comm,
                                          long int *solver,
                                          int      *ierr    )

{
   *ierr = (int) ( HYPRE_ParCSRBiCGSTABCreate( (MPI_Comm)      *comm,
                                                (HYPRE_Solver *) solver ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABDestroy
 *--------------------------------------------------------------------------*/

void 
hypre_F90_IFACE(hypre_parcsrbicgstabdestroy, HYPRE_PARCSRBICGSTABDESTROY)( long int *solver,
                                            int      *ierr    )
{
   *ierr = (int) ( HYPRE_ParCSRBiCGSTABDestroy( (HYPRE_Solver) *solver ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABSetup
 *--------------------------------------------------------------------------*/

void 
hypre_F90_IFACE(hypre_parcsrbicgstabsetup, HYPRE_PARCSRBICGSTABSETUP)( long int *solver,
                                         long int *A,
                                         long int *b,
                                         long int *x,
                                         int      *ierr    )
{
   *ierr = (int) ( HYPRE_ParCSRBiCGSTABSetup( (HYPRE_Solver)       *solver,
                                           (HYPRE_ParCSRMatrix) *A,
                                           (HYPRE_ParVector)    *b,
                                           (HYPRE_ParVector)    *x       ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABSolve
 *--------------------------------------------------------------------------*/

void 
hypre_F90_IFACE(hypre_parcsrbicgstabsolve, HYPRE_PARCSRBICGSTABSOLVE)( long int *solver,
                                         long int *A,
                                         long int *b,
                                         long int *x,
                                         int      *ierr    )
{
   *ierr = (int) ( HYPRE_ParCSRBiCGSTABSolve( (HYPRE_Solver)       *solver,
                                           (HYPRE_ParCSRMatrix) *A,
                                           (HYPRE_ParVector)    *b,
                                           (HYPRE_ParVector)    *x       ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABSetTol
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_parcsrbicgstabsettol, HYPRE_PARCSRBICGSTABSETTOL)( long int *solver,
                                          double   *tol,
                                          int      *ierr    )
{
   *ierr = (int) ( HYPRE_ParCSRBiCGSTABSetTol( (HYPRE_Solver) *solver,
                                            (double)       *tol     ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABSetMinIter
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_parcsrbicgstabsetminiter, HYPRE_PARCSRBICGSTABSETMINITER)( long int *solver,
                                              int      *min_iter,
                                              int      *ierr      )
{
   *ierr = (int) ( HYPRE_ParCSRBiCGSTABSetMinIter( (HYPRE_Solver) *solver,
                                                (int)          *min_iter ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABSetMaxIter
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_parcsrbicgstabsetmaxiter, HYPRE_PARCSRBICGSTABSETMAXITER)( long int *solver,
                                              int      *max_iter,
                                              int      *ierr      )
{
   *ierr = (int) ( HYPRE_ParCSRBiCGSTABSetMaxIter( (HYPRE_Solver) *solver,
                                                (int)          *max_iter ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABSeStopCrit
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_parcsrbicgstabsetstopcrit, HYPRE_PARCSRBICGSTABSETSTOP)
                                            ( long int *solver,
                                              int      *stop_crit,
                                              int      *ierr      )
{
   *ierr = (int) ( HYPRE_ParCSRBiCGSTABSetStopCrit( (HYPRE_Solver) *solver,
                                                    (int)          *stop_crit ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABSetPrecond
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_parcsrbicgstabsetprecond, HYPRE_PARCSRBICGSTABSETPRECOND)( long int *solver,
                                              int      *precond_id,
                                              long int *precond_solver,
                                              int      *ierr          )
{
   /*------------------------------------------------------------
    * The precond_id flags mean :
    *  0 - no preconditioner
    *  1 - set up a ds preconditioner
    *  2 - set up an amg preconditioner
    *  3 - set up a pilut preconditioner
    *  4 - set up a parasails preconditioner
    *------------------------------------------------------------*/

   if (*precond_id == 0)
   {
      *ierr = 0;
   }
   else if (*precond_id == 1)
   {
      *ierr = (int)
              ( HYPRE_ParCSRBiCGSTABSetPrecond( (HYPRE_Solver) *solver,
                                             HYPRE_ParCSRDiagScale,
                                             HYPRE_ParCSRDiagScaleSetup,
                                             NULL                        ) );
   }
   else if (*precond_id == 2)
   {

   *ierr = (int) ( HYPRE_ParCSRBiCGSTABSetPrecond( (HYPRE_Solver) *solver,
                                                HYPRE_BoomerAMGSolve,
                                                HYPRE_BoomerAMGSetup,
                                                (void *)       *precond_solver ) );
   }
   else if (*precond_id == 3)
   {
      *ierr = (int)
              ( HYPRE_ParCSRBiCGSTABSetPrecond( (HYPRE_Solver) *solver,
                                             HYPRE_ParCSRPilutSolve,
                                             HYPRE_ParCSRPilutSetup,
                                             (void *)       *precond_solver ) );
   }
   else if (*precond_id == 4)
   {
      *ierr = (int)
              ( HYPRE_ParCSRBiCGSTABSetPrecond( (HYPRE_Solver) *solver,
                                             HYPRE_ParCSRParaSailsSolve,
                                             HYPRE_ParCSRParaSailsSetup,
                                             (void *)       *precond_solver ) );
   }
   else
   {
      *ierr = -1;
   }
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABGetPrecond
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_parcsrbicgstabgetprecond, HYPRE_PARCSRBICGSTABGETPRECOND)( long int *solver,
                                              long int *precond_solver_ptr,
                                              int      *ierr                )
{
    *ierr = (int)
            ( HYPRE_ParCSRBiCGSTABGetPrecond( (HYPRE_Solver)   *solver,
                                           (HYPRE_Solver *)  precond_solver_ptr ) );

}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABSetLogging
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_parcsrbicgstabsetlogging, HYPRE_PARCSRBICGSTABSETLOGGING)( long int *solver,
                                              int      *logging,
                                              int      *ierr     )
{
   *ierr = (int) ( HYPRE_ParCSRBiCGSTABSetLogging( (HYPRE_Solver) *solver,
                                                (int)          *logging ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABSetPrintLevel
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_parcsrbicgstabsetprintlev, HYPRE_PARCSRBICGSTABSETPRINTLEV)
                                            ( long int *solver,
                                              int      *print_level,
                                              int      *ierr     )
{
   *ierr = (int) ( HYPRE_ParCSRBiCGSTABSetPrintLevel( (HYPRE_Solver) *solver,
                                                      (int)          *print_level ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABGetNumIter
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_parcsrbicgstabgetnumiter, HYPRE_PARCSRBICGSTABGETNUMITER)( long int *solver,
                                                  int      *num_iterations,
                                                  int      *ierr            )
{
   *ierr = (int) ( HYPRE_ParCSRBiCGSTABGetNumIterations(
                            (HYPRE_Solver) *solver,
                            (int *)         num_iterations ) );
}

/*--------------------------------------------------------------------------
 * HYPRE_ParCSRBiCGSTABGetFinalRelativeResidualNorm
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_parcsrbicgstabgetfinalrel, HYPRE_PARCSRBICGSTABGETFINALREL)( long int *solver,
                                                  double   *norm,
                                                  int      *ierr    )
{
   *ierr = (int) ( HYPRE_ParCSRBiCGSTABGetFinalRelativeResidualNorm(
                            (HYPRE_Solver) *solver,
                            (double *)      norm    ) );
}
