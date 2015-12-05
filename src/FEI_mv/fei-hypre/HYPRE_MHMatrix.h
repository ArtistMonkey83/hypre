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
/* data structures  for local matrix                                        */
/*--------------------------------------------------------------------------*/

#ifndef _MHMAT_
#define _MHMAT_

#ifdef HAVE_ML
#include "ml_struct.h"
#include "ml_aggregate.h"
#include "ml_amg.h"
#endif

typedef struct
{
    int      Nrows;
    int      *rowptr;
    int      *colnum;
    int      *map;
    double   *values;
    int      sendProcCnt;
    int      *sendProc;
    int      *sendLeng;
    int      **sendList;
    int      recvProcCnt;
    int      *recvProc;
    int      *recvLeng;
}
MH_Matrix;

typedef struct
{
    MH_Matrix   *Amat;
    MPI_Comm    comm;
    int         globalEqns;
    int         *partition;
}
MH_Context;
    
typedef struct
{
    MPI_Comm     comm;
#ifdef HAVE_ML
    ML           *ml_ptr;
#endif
    int          nlevels;
    int          method;
    int          num_PDEs;
    int          pre, post;
    int          pre_sweeps, post_sweeps;
    int          BGS_blocksize;
    double       jacobi_wt;
    double       ag_threshold;
    int          coarse_solver;
    int          coarsen_scheme;
#ifdef HAVE_ML
    ML_Aggregate *ml_ag;
    ML_AMG       *ml_amg;
#endif
    MH_Context   *contxt;
} 
MH_Link;

#endif
