/*BHEADER**********************************************************************
 * Copyright (c) 2008,  Lawrence Livermore National Security, LLC.
 * Produced at the Lawrence Livermore National Laboratory.
 * This file is part of HYPRE.  See file COPYRIGHT for details.
 *
 * HYPRE is free software; you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License (as published by the Free
 * Software Foundation) version 2.1 dated February 1999.
 *
 * $Revision: 2.5 $
 ***********************************************************************EHEADER*/




/******************************************************************************
 *
 *
 *****************************************************************************/

#include "headers.h"

/*--------------------------------------------------------------------------
 * hypre_SysSemiRestrictData data structure
 *--------------------------------------------------------------------------*/

typedef struct
{
   int                 nvars;
   void              **srestrict_data;
} hypre_SysSemiRestrictData;

/*--------------------------------------------------------------------------
 * hypre_SysSemiRestrictCreate
 *--------------------------------------------------------------------------*/

int
hypre_SysSemiRestrictCreate( void **sys_restrict_vdata_ptr) 
{
   int                        ierr = 0;
   hypre_SysSemiRestrictData *sys_restrict_data;

   sys_restrict_data = hypre_CTAlloc(hypre_SysSemiRestrictData, 1);
   *sys_restrict_vdata_ptr = (void *) sys_restrict_data;

   return ierr;
}

/*--------------------------------------------------------------------------
 * hypre_SysSemiRestrictSetup
 *--------------------------------------------------------------------------*/

int
hypre_SysSemiRestrictSetup( void                 *sys_restrict_vdata,
                            hypre_SStructPMatrix *R,
                            int                   R_stored_as_transpose,
                            hypre_SStructPVector *r,
                            hypre_SStructPVector *rc,
                            hypre_Index           cindex,
                            hypre_Index           findex,
                            hypre_Index           stride                )
{
   int                      ierr = 0;

   hypre_SysSemiRestrictData  *sys_restrict_data = sys_restrict_vdata;
   void                      **srestrict_data;

   int                         nvars;

   hypre_StructMatrix         *R_s;
   hypre_StructVector         *rc_s;
   hypre_StructVector         *r_s;

   int                         vi;

   nvars = hypre_SStructPMatrixNVars(R);
   srestrict_data = hypre_CTAlloc(void *, nvars);

   for (vi = 0; vi < nvars; vi++)
   {
      R_s  = hypre_SStructPMatrixSMatrix(R, vi, vi);
      rc_s = hypre_SStructPVectorSVector(rc, vi);
      r_s  = hypre_SStructPVectorSVector(r, vi);
      srestrict_data[vi] = hypre_SemiRestrictCreate( );
      hypre_SemiRestrictSetup( srestrict_data[vi], R_s, R_stored_as_transpose,
                             r_s, rc_s, cindex, findex, stride);
   }

   (sys_restrict_data -> nvars)        = nvars;
   (sys_restrict_data -> srestrict_data) = srestrict_data;

   return ierr;

}

/*--------------------------------------------------------------------------
 * hypre_SysSemiRestrict:
 *--------------------------------------------------------------------------*/

int
hypre_SysSemiRestrict( void                 *sys_restrict_vdata,
                       hypre_SStructPMatrix *R,
                       hypre_SStructPVector *r,
                       hypre_SStructPVector *rc             )
{
   int                         ierr = 0;
  
   hypre_SysSemiRestrictData  *sys_restrict_data = sys_restrict_vdata;
   void                      **srestrict_data
                                = (sys_restrict_data -> srestrict_data);
   int                         nvars = (sys_restrict_data -> nvars);

   void                       *sdata;
   hypre_StructMatrix         *R_s;
   hypre_StructVector         *rc_s;
   hypre_StructVector         *r_s;

   int                         vi;

   for (vi = 0; vi < nvars; vi++)
   {
      sdata = srestrict_data[vi];
      R_s  = hypre_SStructPMatrixSMatrix(R, vi, vi);
      rc_s = hypre_SStructPVectorSVector(rc, vi);
      r_s  = hypre_SStructPVectorSVector(r, vi);
      hypre_SemiRestrict(sdata, R_s, r_s, rc_s);
   }

   return ierr;

}

/*--------------------------------------------------------------------------
 * hypre_SysSemiRestrictDestroy
 *--------------------------------------------------------------------------*/

int
hypre_SysSemiRestrictDestroy( void *sys_restrict_vdata )
{
   int                     ierr = 0;

   hypre_SysSemiRestrictData *sys_restrict_data = sys_restrict_vdata;

   int                     nvars;
   void                  **srestrict_data;
   int                     vi;

   if (sys_restrict_data)
   {
      nvars        = (sys_restrict_data -> nvars);
      srestrict_data = (sys_restrict_data -> srestrict_data);
      for (vi = 0; vi < nvars; vi++)
      {
         if (srestrict_data[vi] != NULL)
         {
            hypre_SemiRestrictDestroy(srestrict_data[vi]);
         }
      }
      hypre_TFree(srestrict_data);
      hypre_TFree(sys_restrict_data);
   }
   return ierr;

}

