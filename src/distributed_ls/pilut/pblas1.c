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



/*
 * pblas1.c
 *
 * This file contains functions that implement various distributed
 * level 1 BLAS routines
 *
 * Started 11/28/95
 * George
 *
 * $Id: pblas1.c,v 2.4 2006/09/22 22:06:01 hill66 Exp $
 *
 */

#include "ilu.h"
#include "DistributedMatrixPilutSolver.h"


/*************************************************************************
* This function computes the 2 norm of a vector. The result is returned
* at all the processors
**************************************************************************/
double hypre_p_dnrm2(DataDistType *ddist, double *x, hypre_PilutSolverGlobals *globals)
{
  int incx=1;
  double sum;

  sum = SNRM2(&(ddist->ddist_lnrows), x, &incx);
  return sqrt(hypre_GlobalSESumDouble(sum*sum, pilut_comm));
}


/*************************************************************************
* This function computes the dot product of 2 vectors. 
* The result is returned at all the processors
**************************************************************************/
double hypre_p_ddot(DataDistType *ddist, double *x, double *y,
              hypre_PilutSolverGlobals *globals)
{
  int incx=1;

  return hypre_GlobalSESumDouble(SDOT(&(ddist->ddist_lnrows), x, &incx, y, &incx), 
         pilut_comm );
}


/*************************************************************************
* This function performs y = alpha*x, where alpha resides on pe 0
**************************************************************************/
void hypre_p_daxy(DataDistType *ddist, double alpha, double *x, double *y)
{
  int i, local_lnrows=ddist->ddist_lnrows;

  for (i=0; i<local_lnrows; i++)
    y[i] = alpha*x[i];
}


/*************************************************************************
* This function performs y = alpha*x+y, where alpha resides on pe 0
**************************************************************************/
void hypre_p_daxpy(DataDistType *ddist, double alpha, double *x, double *y)
{
  int i, local_lnrows=ddist->ddist_lnrows;

  for (i=0; i<local_lnrows; i++)
    y[i] += alpha*x[i];
}



/*************************************************************************
* This function performs z = alpha*x+beta*y, where alpha resides on pe 0
**************************************************************************/
void hypre_p_daxbyz(DataDistType *ddist, double alpha, double *x, double beta, 
              double *y, double *z)
{
  int i, local_lnrows=ddist->ddist_lnrows;

  for (i=0; i<local_lnrows; i++)
    z[i] = alpha*x[i] + beta*y[i];
}

/*************************************************************************
* This function prints a vector
**************************************************************************/
int hypre_p_vprintf(DataDistType *ddist, double *x,
                    hypre_PilutSolverGlobals *globals )
{
  int pe, i;

  for (pe=0; pe<npes; pe++) {
    if (mype == pe) {
      for (i=0; i<ddist->ddist_lnrows; i++)
        printf("%d:%f, ", ddist->ddist_rowdist[mype]+i, x[i]);
      if (pe == npes-1)
        printf("\n");
    }
    MPI_Barrier( pilut_comm );
  }
  fflush(stdout);
  MPI_Barrier( pilut_comm );

  return 0;
}
