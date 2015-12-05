/*BHEADER**********************************************************************
 * Copyright (c) 2008,  Lawrence Livermore National Security, LLC.
 * Produced at the Lawrence Livermore National Laboratory.
 * This file is part of HYPRE.  See file COPYRIGHT for details.
 *
 * HYPRE is free software; you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License (as published by the Free
 * Software Foundation) version 2.1 dated February 1999.
 *
 * $Revision: 2.9 $
 ***********************************************************************EHEADER*/




/******************************************************************************
 *
 * HYPRE_SStructGrid interface
 *
 *****************************************************************************/

#include "headers.h"
#include "fortran.h"

/*--------------------------------------------------------------------------
 * HYPRE_SStructGridCreate
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_sstructgridcreate, HYPRE_SSTRUCTGRIDCREATE)
                                                          (int        *comm,
                                                           int        *ndim,
                                                           int        *nparts,
                                                           long int   *grid_ptr,
                                                           int        *ierr)
{
   *ierr = (int) (HYPRE_SStructGridCreate( (MPI_Comm)           *comm,
                                           (int)                *ndim,
                                           (int)                *nparts,
                                           (HYPRE_SStructGrid *) grid_ptr ) );
}

/*--------------------------------------------------------------------------
 *  HYPRE_SStructGridDestroy
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_sstructgriddestroy, HYPRE_SSTRUCTGRIDDESTROY)
                                                           (long int   *grid,
                                                            int        *ierr)
{
   *ierr = (int) (HYPRE_SStructGridDestroy( (HYPRE_SStructGrid) *grid ) );
}

/*--------------------------------------------------------------------------
 *  HYPRE_SStructGridSetExtents
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_sstructgridsetextents, HYPRE_SSTRUCTGRIDSETEXTENTS)
                                                          (long int   *grid,
                                                           int        *part,
                                                           int        *ilower,
                                                           int        *iupper,
                                                           int        *ierr)
{
   *ierr = (int) (HYPRE_SStructGridSetExtents( (HYPRE_SStructGrid) *grid,
                                               (int)               *part,
                                               (int *)              ilower,
                                               (int *)              iupper ) );
}

/*--------------------------------------------------------------------------
 *  HYPRE_SStructGridSetVariables
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_sstructgridsetvariables, HYPRE_SSTRUCTGRIDSETVARIABLES)
                                                          (long int   *grid,
                                                           int        *part,
                                                           int        *nvars,
                                                           int        *vartypes,
                                                           int        *ierr)
{
   *ierr = (int) (HYPRE_SStructGridSetVariables( (HYPRE_SStructGrid)      *grid,
                                                 (int)                    *part,
                                                 (int)                    *nvars,
                                                 (HYPRE_SStructVariable *) vartypes ) );
}

/*--------------------------------------------------------------------------
 *  HYPRE_SStructGridSetVariable
 *     Like HYPRE_SStructGridSetVariables; except only one variable is done
 *     at a time; nvars is needed for memory allocation.
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_sstructgridsetvariable, HYPRE_SSTRUCTGRIDSETVARIABLE)
                                                          (long int   *grid,
                                                           int        *part,
                                                           int        *var,
                                                           int        *nvars,
                                                           int        *vartype,
                                                           int        *ierr)
{
   *ierr = (int) (HYPRE_SStructGridSetVariable( (HYPRE_SStructGrid)      *grid,
                                                (int)                    *part,
                                                (int)                    *var,
                                                (int)                    *nvars,
                                                (HYPRE_SStructVariable)  *vartype ) );
}

/*--------------------------------------------------------------------------
 *  HYPRE_SStructGridAddVariables
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_sstructgridaddvariables, HYPRE_SSTRUCTGRIDADDVARIABLES)
                                                          (long int   *grid,
                                                           int        *part,
                                                           int        *index,
                                                           int        *nvars,
                                                           int        *vartypes,
                                                           int        *ierr)
{
   *ierr = (int) (HYPRE_SStructGridAddVariables( (HYPRE_SStructGrid)      *grid,
                                                 (int)                    *part,
                                                 (int *)                   index,
                                                 (int)                    *nvars,
                                                 (HYPRE_SStructVariable *) vartypes ));
}

/*--------------------------------------------------------------------------
 *  HYPRE_SStructGridAddVariable
 *     Like HYPRE_SStructGridAddVariables; except only one variable is done
 *     at a time.
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_sstructgridaddvariable, HYPRE_SSTRUCTGRIDADDVARIABLE)
                                                          (long int   *grid,
                                                           int        *part,
                                                           int        *index,
                                                           int        *var,
                                                           int        *vartype,
                                                           int        *ierr)
{
   *ierr = (int) (HYPRE_SStructGridAddVariable( (HYPRE_SStructGrid)      *grid,
                                                (int)                    *part,
                                                (int *)                   index,
                                                (int)                    *var,
                                                (HYPRE_SStructVariable)  *vartype ));
}

/*--------------------------------------------------------------------------
 *  HYPRE_SStructGridSetNeighborBox
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_sstructgridsetneighborbox, HYPRE_SSTRUCTGRIDSETNEIGHBORBOX)
                                                          (long int   *grid,
                                                           int        *part,
                                                           int        *ilower,
                                                           int        *iupper,
                                                           int        *nbor_part,
                                                           int        *nbor_ilower,
                                                           int        *nbor_iupper,
                                                           int        *index_map,
                                                           int        *ierr)
{
   *ierr = (int) (HYPRE_SStructGridSetNeighborBox( (HYPRE_SStructGrid) *grid,
                                                   (int)               *part,
                                                   (int *)              ilower,
                                                   (int *)              iupper,
                                                   (int)               *nbor_part,
                                                   (int *)              nbor_ilower,
                                                   (int *)              nbor_iupper,
                                                   (int *)              index_map ) );
}

/*--------------------------------------------------------------------------
 * *** placeholder ***
 *  HYPRE_SStructGridAddUnstructuredPart
 *--------------------------------------------------------------------------*/

#if 0

void
hypre_F90_IFACE(hypre_sstructgridaddunstructure, HYPRE_SSTRUCTGRIDADDUNSTRUCTURE)
                                                          (long int   *grid,
                                                           int        *ilower,
                                                           int        *iupper,
                                                           int        *ierr)
{
   *ierr = (int) (HYPRE_SStructGridAddUnstructuredPart( (HYPRE_SStructGrid) *grid,
                                                        (int *)              ilower,
                                                        (int *)              iupper) );
}
#endif

/*--------------------------------------------------------------------------
 *  HYPRE_SStructGridAssemble
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_sstructgridassemble, HYPRE_SSTRUCTGRIDASSEMBLE)
                                                          (long int   *grid,
                                                           int        *ierr)
{
   *ierr = (int) (HYPRE_SStructGridAssemble( (HYPRE_SStructGrid) *grid ) );
}

/*--------------------------------------------------------------------------
 *  HYPRE_SStructGridSetPeriodic
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_sstructgridsetperiodic, HYPRE_SSTRUCTGRIDSETPERIODIC)
                                                          (long int   *grid,
                                                           int        *part,
                                                           int        *periodic,
                                                           int        *ierr)
{
   *ierr = (int) (HYPRE_SStructGridSetPeriodic( (HYPRE_SStructGrid) *grid,
                                                (int)               *part,
                                                (int *)              periodic ) );
}

/*--------------------------------------------------------------------------
 *  HYPRE_SStructGridSetNumGhost
 *--------------------------------------------------------------------------*/

void
hypre_F90_IFACE(hypre_sstructgridsetnumghost, HYPRE_SSTRUCTGRIDSETNUMGHOST)
                                                          (long int   *grid,
                                                           int        *num_ghost,
                                                           int        *ierr)
{
   *ierr = (int) (HYPRE_SStructGridSetNumGhost( (HYPRE_SStructGrid) *grid,
                                                (int *)              num_ghost));       
}
