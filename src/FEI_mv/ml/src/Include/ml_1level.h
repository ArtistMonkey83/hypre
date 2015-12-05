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



/* ******************************************************************** */
/* See the file COPYRIGHT for a complete copyright notice, contact      */
/* person and disclaimer.                                               */        
/* ******************************************************************** */

/* ******************************************************************** */
/* Declaration of the ML_1Level structure                               */
/* ******************************************************************** */
/* Author        : Charles Tong (LLNL) and Raymond Tuminaro (SNL)       */
/* Date          : March, 1999                                          */
/* ******************************************************************** */

#ifndef __ML1LEVEL__
#define __ML1LEVEL__

/* ******************************************************************** */
/* data structure type definition                                       */
/* ******************************************************************** */

typedef struct ML_1Level_Struct ML_1Level;

/* ******************************************************************** */
/* include files                                                        */
/* ******************************************************************** */

#include "ml_common.h"
#include "ml_defs.h"
#include "ml_bdrypts.h"
#include "ml_mapper.h"
#include "ml_grid.h"
#include "ml_comm.h"
#include "ml_comminfoop.h"
#include "ml_operator.h"
#include "ml_smoother.h"
#include "ml_csolve.h"
#include "ml_vec.h"

/* ******************************************************************** */
/* data definition for the ML_1Level Class                              */
/* ******************************************************************** */
/* -------------------------------------------------------------------- */
/* This data structure defines the components of a grid level in a      */
/* multilevel environment.                                              */
/* -------------------------------------------------------------------- */

struct ML_1Level_Struct 
{
   int          id, levelnum;
   ML_Operator  *Amat, *Rmat, *Pmat;
   ML_BdryPts   *BCs;
   ML_Mapper    *eqn2grid;
   ML_Mapper    *grid2eqn;
   ML_Grid      *Grid;
   ML_DVector   *Amat_Normalization;
   ML_Smoother  *pre_smoother;
   ML_Smoother  *post_smoother;
   ML_CSolve    *csolve;
   ML_Comm      *comm;
};

#endif

