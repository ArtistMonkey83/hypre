/*
 * File:          bHYPRE_SStructVariable_fStub.c
 * Symbol:        bHYPRE.SStructVariable-v1.0.0
 * Symbol Type:   enumeration
 * Babel Version: 0.8.2
 * SIDL Created:  20030401 14:47:46 PST
 * Generated:     20030401 14:48:09 PST
 * Description:   Client-side glue code for bHYPRE.SStructVariable
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 * babel-version = 0.8.2
 * source-line   = 888
 * source-url    = file:/home/painter/linear_solvers/babel/Interfaces.idl
 */

#ifndef included_SIDL_int_IOR_h
#include "SIDL_int_IOR.h"
#endif
#ifndef included_SIDLfortran_h
#include "SIDLfortran.h"
#endif
#include <stddef.h>
void
SIDLFortran77Symbol(bhypre_sstructvariable__array_createcol_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_CREATECOL_F,
                  bHYPRE_SStructVariable__array_createCol_f)
  (int32_t *dimen,
   int32_t lower[],
   int32_t upper[],
   int64_t *result)
{
  *result = (ptrdiff_t)
    SIDL_int__array_createCol(*dimen, lower, upper);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_createrow_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_CREATEROW_F,
                  bHYPRE_SStructVariable__array_createRow_f)
  (int32_t *dimen,
   int32_t lower[],
   int32_t upper[],
   int64_t *result)
{
  *result = (ptrdiff_t)
    SIDL_int__array_createRow(*dimen, lower, upper);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_create1d_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_CREATE1D_F,
                  bHYPRE_SStructVariable__array_create1d_f)
  (int32_t *len, int64_t *result)
{
  *result = (ptrdiff_t)SIDL_int__array_create1d(*len);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_create2dcol_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_CREATE2DCOL_F,
                  bHYPRE_SStructVariable__array_create2dCol_f)
  (int32_t *m, int32_t *n, int64_t *result)
{
  *result = (ptrdiff_t)SIDL_int__array_create2dCol(*m, *n);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_create2drow_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_CREATE2DROW_F,
                  bHYPRE_SStructVariable__array_create2dRow_f)
  (int32_t *m, int32_t *n, int64_t *result)
{
  *result = (ptrdiff_t)SIDL_int__array_create2dRow(*m, *n);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_addref_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_ADDREF_F,
                  bHYPRE_SStructVariable__array_addRef_f)
  (int64_t *array)
{
  SIDL_int__array_addRef((struct SIDL_int__array *)(ptrdiff_t)*array);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_deleteref_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_DELETEREF_F,
                  bHYPRE_SStructVariable__array_deleteRef_f)
  (int64_t *array)
{
  SIDL_int__array_deleteRef((struct SIDL_int__array *)(ptrdiff_t)*array);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_get1_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_GET1_F,
                  bHYPRE_SStructVariable__array_get1_f)
  (int64_t *array, 
   int32_t *i1, 
   int64_t *result)
{
  *result = (ptrdiff_t)
    SIDL_int__array_get1((const struct SIDL_int__array *)(ptrdiff_t)*array
    , *i1);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_get2_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_GET2_F,
                  bHYPRE_SStructVariable__array_get2_f)
  (int64_t *array, 
   int32_t *i1, 
   int32_t *i2, 
   int64_t *result)
{
  *result = (ptrdiff_t)
    SIDL_int__array_get2((const struct SIDL_int__array *)(ptrdiff_t)*array
    , *i1, *i2);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_get3_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_GET3_F,
                  bHYPRE_SStructVariable__array_get3_f)
  (int64_t *array, 
   int32_t *i1, 
   int32_t *i2, 
   int32_t *i3, 
   int64_t *result)
{
  *result = (ptrdiff_t)
    SIDL_int__array_get3((const struct SIDL_int__array *)(ptrdiff_t)*array
    , *i1, *i2, *i3);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_get4_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_GET4_F,
                  bHYPRE_SStructVariable__array_get4_f)
  (int64_t *array, 
   int32_t *i1, 
   int32_t *i2, 
   int32_t *i3, 
   int32_t *i4, 
   int64_t *result)
{
  *result = (ptrdiff_t)
    SIDL_int__array_get4((const struct SIDL_int__array *)(ptrdiff_t)*array
    , *i1, *i2, *i3, *i4);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_get_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_GET_F,
                  bHYPRE_SStructVariable__array_get_f)
  (int64_t *array,
   int32_t indices[],
   int64_t *result)
{
  *result = (ptrdiff_t)
    SIDL_int__array_get((const struct SIDL_int__array *)(ptrdiff_t)*array,
      indices);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_set1_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_SET1_F,
                  bHYPRE_SStructVariable__array_set1_f)
  (int64_t *array,
   int32_t *i1,
   int64_t *value)
{
  SIDL_int__array_set1((struct SIDL_int__array *)(ptrdiff_t)*array
  , *i1, (int32_t)(ptrdiff_t)*value);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_set2_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_SET2_F,
                  bHYPRE_SStructVariable__array_set2_f)
  (int64_t *array,
   int32_t *i1,
   int32_t *i2,
   int64_t *value)
{
  SIDL_int__array_set2((struct SIDL_int__array *)(ptrdiff_t)*array
  , *i1, *i2, (int32_t)(ptrdiff_t)*value);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_set3_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_SET3_F,
                  bHYPRE_SStructVariable__array_set3_f)
  (int64_t *array,
   int32_t *i1,
   int32_t *i2,
   int32_t *i3,
   int64_t *value)
{
  SIDL_int__array_set3((struct SIDL_int__array *)(ptrdiff_t)*array
  , *i1, *i2, *i3, (int32_t)(ptrdiff_t)*value);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_set4_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_SET4_F,
                  bHYPRE_SStructVariable__array_set4_f)
  (int64_t *array,
   int32_t *i1,
   int32_t *i2,
   int32_t *i3,
   int32_t *i4,
   int64_t *value)
{
  SIDL_int__array_set4((struct SIDL_int__array *)(ptrdiff_t)*array
  , *i1, *i2, *i3, *i4, (int32_t)(ptrdiff_t)*value);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_set_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_SET_F,
                  bHYPRE_SStructVariable__array_set_f)
  (int64_t *array,
  int32_t indices[],
  int64_t *value)
{
  SIDL_int__array_set((struct SIDL_int__array *)(ptrdiff_t)*array, indices,
    (int32_t)(ptrdiff_t)*value);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_dimen_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_DIMEN_F,
                  bHYPRE_SStructVariable__array_dimen_f)
  (int64_t *array, int32_t *result)
{
  *result =
    SIDL_int__array_dimen((struct SIDL_int__array *)(ptrdiff_t)*array);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_lower_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_LOWER_F,
                  bHYPRE_SStructVariable__array_lower_f)
  (int64_t *array,
   int32_t *ind,
   int32_t *result)
{
  *result = 
    SIDL_int__array_lower((struct SIDL_int__array *)(ptrdiff_t)*array, *ind);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_upper_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_UPPER_F,
                  bHYPRE_SStructVariable__array_upper_f)
  (int64_t *array,
   int32_t *ind,
   int32_t *result)
{
  *result = 
    SIDL_int__array_upper((struct SIDL_int__array *)(ptrdiff_t)*array, *ind);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_stride_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_STRIDE_F,
                  bHYPRE_SStructVariable__array_stride_f)
  (int64_t *array,
   int32_t *ind,
   int32_t *result)
{
  *result = 
    SIDL_int__array_stride((struct SIDL_int__array *)(ptrdiff_t)*array, *ind);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_iscolumnorder_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_ISCOLUMNORDER_F,
                  bHYPRE_SStructVariable__array_isColumnOrder_f)
  (int64_t *array,
   SIDL_F77_Bool *result)
{
  *result = SIDL_int__array_isColumnOrder((struct SIDL_int__array 
    *)(ptrdiff_t)*array);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_isroworder_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_ISROWORDER_F,
                  bHYPRE_SStructVariable__array_isRowOrder_f)
  (int64_t *array,
   SIDL_F77_Bool *result)
{
  *result = SIDL_int__array_isRowOrder((struct SIDL_int__array 
    *)(ptrdiff_t)*array);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_copy_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_COPY_F,
                  bHYPRE_SStructVariable__array_copy_f)
  (int64_t *src,
   int64_t *dest)
{
  SIDL_int__array_copy((const struct SIDL_int__array *)(ptrdiff_t)*src,
                       (struct SIDL_int__array *)(ptrdiff_t)*dest);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_smartcopy_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_SMARTCOPY_F,
                  bHYPRE_SStructVariable__array_smartCopy_f)
  (int64_t *src)
{
  SIDL_int__array_smartCopy((struct SIDL_int__array *)(ptrdiff_t)*src);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_slice_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_SLICE_F,
                  bHYPRE_SStructVariable__array_slice_f)
  (int64_t *src,
   int32_t *dimen,
   int32_t numElem[],
   int32_t srcStart[],
   int32_t srcStride[],
   int32_t newStart[],
   int64_t *result)
{
  *result = (ptrdiff_t)
    SIDL_int__array_slice((struct SIDL_int__array *)(ptrdiff_t)*src,
      *dimen, numElem, srcStart, srcStride, newStart);
}

void
SIDLFortran77Symbol(bhypre_sstructvariable__array_ensure_f,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_ENSURE_F,
                  bHYPRE_SStructVariable__array_ensure_f)
  (int64_t *src,
   int32_t *dimen,
   int     *ordering,
   int64_t *result)
{
  *result = (ptrdiff_t)
    SIDL_int__array_ensure((struct SIDL_int__array *)(ptrdiff_t)*src,
    *dimen, *ordering);
}

