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
 * $Revision: 1.3 $
 ***********************************************************************EHEADER*/




/******************************************************************************
 *
 * Header info for the Compatible relaxation-based multilevel method
 *
 *****************************************************************************/

#ifndef __MLIMETHODAMGCRH__
#define __MLIMETHODAMGCRH__

#include "utilities/utilities.h"
#include "parcsr_mv/parcsr_mv.h"
#include "base/mli.h"
#include "matrix/mli_matrix.h"
#include "amgs/mli_method.h"

/* ***********************************************************************
 * definition of the classical Ruge Stuben AMG data structure
 * ----------------------------------------------------------------------*/

class MLI_Method_AMGCR : public MLI_Method
{
   int      maxLevels_;
   int      numLevels_;
   int      currLevel_;
   int      outputLevel_;
   int      findMIS_;
   int      numTrials_;
   int      numVectors_;
   int      minCoarseSize_;
   double   cutThreshold_;
   double   targetMu_;
   char     smoother_[20];
   int      smootherNum_;
   double   *smootherWgts_;
   char     coarseSolver_[20];
   int      coarseSolverNum_;
   double   *coarseSolverWgts_;
   double   RAPTime_;
   double   totalTime_;
   char     paramFile_[50];
   int      PDegree_;

public :

   MLI_Method_AMGCR(MPI_Comm comm);
   ~MLI_Method_AMGCR();
   int    setup( MLI *mli );
   int    setParams(char *name, int argc, char *argv[]);

   int    setOutputLevel(int outputLevel);
   int    setNumLevels(int nlevels);
   int    selectIndepSet(MLI_Matrix *, int **indepSet);
   MLI_Matrix *performCR(MLI_Matrix *, int *indepSet, MLI_Matrix **);
   MLI_Matrix *createPmat(int *indepSet,MLI_Matrix *,MLI_Matrix *,MLI_Matrix *);
   MLI_Matrix *createRmat(int *indepSet, MLI_Matrix *, MLI_Matrix *);
   int    print();
   int    printStatistics(MLI *mli);
};

#endif

