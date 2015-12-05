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
 * $Revision: 2.6 $
 ***********************************************************************EHEADER*/




/****************************************************************************/ 
/* data structures for local matrix and ml object                           */
/*--------------------------------------------------------------------------*/

#ifndef _MLMAXWELL_
#define _MLMAXWELL_

/* #define HAVE_MLMAXWELL */

#ifdef HAVE_MLMAXWELL
#include "ml_include.h"
#endif

#include "HYPRE_MLMatrix.h"

typedef struct
{
    HYPRE_ML_Matrix *Amat;
    MPI_Comm comm;
    int globalEqns;
    int *partition;
}
MLMaxwell_Context;
    
typedef struct
{
    MPI_Comm comm;
#ifdef HAVE_MLMAXWELL
    ML       *ml_ee;
    ML       *ml_nn;
#endif
    int      nlevels;
    int      smoothP_flag;
    double   ag_threshold;
    void     *edge_smoother;
    void     *node_smoother;
    HYPRE_ParCSRMatrix hypreG;
    HYPRE_ParCSRMatrix hypreAnn;
#ifdef HAVE_MLMAXWELL
    ML_Aggregate *ml_ag;
    ML_Operator  *Annmat;
    ML_Operator  *Gmat;
    ML_Operator  *GTmat;
    ML_Operator  **Gmat_array;
    ML_Operator  **GTmat_array;

#endif
    MLMaxwell_Context *Aee_contxt;
    MLMaxwell_Context *G_contxt;
    MLMaxwell_Context *Ann_contxt;
    void              **node_args;
    void              **edge_args;
} 
MLMaxwell_Link;

#endif

