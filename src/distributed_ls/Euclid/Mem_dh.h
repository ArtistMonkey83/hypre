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



#ifndef MEM_DH_DH
#define MEM_DH_DH

#include "euclid_common.h"

extern void  Mem_dhCreate(Mem_dh *m);
extern void  Mem_dhDestroy(Mem_dh m);

extern void *Mem_dhMalloc(Mem_dh m, size_t size);
extern void  Mem_dhFree(Mem_dh m, void *ptr);
  /* preceeding two are called via the macros
     MALLOC_DH and FREE_DH; see "euclid_config.h"
   */

extern void  Mem_dhPrint(Mem_dh m, FILE* fp, bool allPrint);
  /* prints memory usage statistics;  "allPrint" is only
     meaningful when running in MPI mode.
   */

#endif
