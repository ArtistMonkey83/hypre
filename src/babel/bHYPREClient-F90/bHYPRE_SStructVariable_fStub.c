/*
 * File:          bHYPRE_SStructVariable_fStub.c
 * Symbol:        bHYPRE.SStructVariable-v1.0.0
 * Symbol Type:   enumeration
 * Babel Version: 1.0.0
 * Description:   Client-side glue code for bHYPRE.SStructVariable
 * 
 * WARNING: Automatically generated; changes will be lost
 */

#ifndef included_sidl_int_IOR_h
#include "sidl_int_IOR.h"
#endif
#ifndef included_sidlfortran_h
#include "sidlfortran.h"
#endif
#include <stddef.h>
#include "bHYPRE_SStructVariable_fAbbrev.h"
void
SIDLFortran90Symbol(bhypre_sstructvariable__array_createcol_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_CREATECOL_M,
                  bHYPRE_SStructVariable__array_createCol_m)
  (int32_t *dimen,
   int32_t lower[],
   int32_t upper[],
   int64_t *result)
{
  *result = (ptrdiff_t)
    sidl_int__array_createCol(*dimen, lower, upper);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_createrow_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_CREATEROW_M,
                  bHYPRE_SStructVariable__array_createRow_m)
  (int32_t *dimen,
   int32_t lower[],
   int32_t upper[],
   int64_t *result)
{
  *result = (ptrdiff_t)
    sidl_int__array_createRow(*dimen, lower, upper);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_create1d_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_CREATE1D_M,
                  bHYPRE_SStructVariable__array_create1d_m)
  (int32_t *len, int64_t *result)
{
  *result = (ptrdiff_t)sidl_int__array_create1d(*len);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_create2dcol_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_CREATE2DCOL_M,
                  bHYPRE_SStructVariable__array_create2dCol_m)
  (int32_t *m, int32_t *n, int64_t *result)
{
  *result = (ptrdiff_t)sidl_int__array_create2dCol(*m, *n);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_create2drow_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_CREATE2DROW_M,
                  bHYPRE_SStructVariable__array_create2dRow_m)
  (int32_t *m, int32_t *n, int64_t *result)
{
  *result = (ptrdiff_t)sidl_int__array_create2dRow(*m, *n);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_addref_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_ADDREF_M,
                  bHYPRE_SStructVariable__array_addRef_m)
  (int64_t *array)
{
  sidl_int__array_addRef((struct sidl_int__array *)(ptrdiff_t)*array);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_deleteref_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_DELETEREF_M,
                  bHYPRE_SStructVariable__array_deleteRef_m)
  (int64_t *array)
{
  sidl_int__array_deleteRef((struct sidl_int__array *)(ptrdiff_t)*array);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_get1_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_GET1_M,
                  bHYPRE_SStructVariable__array_get1_m)
  (int64_t *array, 
   int32_t *i1, 
   int32_t *result)
{
  *result = 
    sidl_int__array_get1((const struct sidl_int__array *)(ptrdiff_t)*array
    , *i1);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_get2_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_GET2_M,
                  bHYPRE_SStructVariable__array_get2_m)
  (int64_t *array, 
   int32_t *i1, 
   int32_t *i2, 
   int32_t *result)
{
  *result = 
    sidl_int__array_get2((const struct sidl_int__array *)(ptrdiff_t)*array
    , *i1, *i2);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_get3_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_GET3_M,
                  bHYPRE_SStructVariable__array_get3_m)
  (int64_t *array, 
   int32_t *i1, 
   int32_t *i2, 
   int32_t *i3, 
   int32_t *result)
{
  *result = 
    sidl_int__array_get3((const struct sidl_int__array *)(ptrdiff_t)*array
    , *i1, *i2, *i3);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_get4_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_GET4_M,
                  bHYPRE_SStructVariable__array_get4_m)
  (int64_t *array, 
   int32_t *i1, 
   int32_t *i2, 
   int32_t *i3, 
   int32_t *i4, 
   int32_t *result)
{
  *result = 
    sidl_int__array_get4((const struct sidl_int__array *)(ptrdiff_t)*array
    , *i1, *i2, *i3, *i4);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_get5_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_GET5_M,
                  bHYPRE_SStructVariable__array_get5_m)
  (int64_t *array, 
   int32_t *i1, 
   int32_t *i2, 
   int32_t *i3, 
   int32_t *i4, 
   int32_t *i5, 
   int32_t *result)
{
  *result = 
    sidl_int__array_get5((const struct sidl_int__array *)(ptrdiff_t)*array
    , *i1, *i2, *i3, *i4, *i5);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_get6_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_GET6_M,
                  bHYPRE_SStructVariable__array_get6_m)
  (int64_t *array, 
   int32_t *i1, 
   int32_t *i2, 
   int32_t *i3, 
   int32_t *i4, 
   int32_t *i5, 
   int32_t *i6, 
   int32_t *result)
{
  *result = 
    sidl_int__array_get6((const struct sidl_int__array *)(ptrdiff_t)*array
    , *i1, *i2, *i3, *i4, *i5, *i6);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_get7_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_GET7_M,
                  bHYPRE_SStructVariable__array_get7_m)
  (int64_t *array, 
   int32_t *i1, 
   int32_t *i2, 
   int32_t *i3, 
   int32_t *i4, 
   int32_t *i5, 
   int32_t *i6, 
   int32_t *i7, 
   int32_t *result)
{
  *result = 
    sidl_int__array_get7((const struct sidl_int__array *)(ptrdiff_t)*array
    , *i1, *i2, *i3, *i4, *i5, *i6, *i7);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_get_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_GET_M,
                  bHYPRE_SStructVariable__array_get_m)
  (int64_t *array,
   int32_t indices[],
   int32_t *result)
{
  *result = 
    sidl_int__array_get((const struct sidl_int__array *)(ptrdiff_t)*array,
      indices);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_set1_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_SET1_M,
                  bHYPRE_SStructVariable__array_set1_m)
  (int64_t *array,
   int32_t *i1,
   int32_t *value)
{
  sidl_int__array_set1((struct sidl_int__array *)(ptrdiff_t)*array
  , *i1, *value);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_set2_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_SET2_M,
                  bHYPRE_SStructVariable__array_set2_m)
  (int64_t *array,
   int32_t *i1,
   int32_t *i2,
   int32_t *value)
{
  sidl_int__array_set2((struct sidl_int__array *)(ptrdiff_t)*array
  , *i1, *i2, *value);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_set3_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_SET3_M,
                  bHYPRE_SStructVariable__array_set3_m)
  (int64_t *array,
   int32_t *i1,
   int32_t *i2,
   int32_t *i3,
   int32_t *value)
{
  sidl_int__array_set3((struct sidl_int__array *)(ptrdiff_t)*array
  , *i1, *i2, *i3, *value);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_set4_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_SET4_M,
                  bHYPRE_SStructVariable__array_set4_m)
  (int64_t *array,
   int32_t *i1,
   int32_t *i2,
   int32_t *i3,
   int32_t *i4,
   int32_t *value)
{
  sidl_int__array_set4((struct sidl_int__array *)(ptrdiff_t)*array
  , *i1, *i2, *i3, *i4, *value);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_set5_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_SET5_M,
                  bHYPRE_SStructVariable__array_set5_m)
  (int64_t *array,
   int32_t *i1,
   int32_t *i2,
   int32_t *i3,
   int32_t *i4,
   int32_t *i5,
   int32_t *value)
{
  sidl_int__array_set5((struct sidl_int__array *)(ptrdiff_t)*array
  , *i1, *i2, *i3, *i4, *i5, *value);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_set6_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_SET6_M,
                  bHYPRE_SStructVariable__array_set6_m)
  (int64_t *array,
   int32_t *i1,
   int32_t *i2,
   int32_t *i3,
   int32_t *i4,
   int32_t *i5,
   int32_t *i6,
   int32_t *value)
{
  sidl_int__array_set6((struct sidl_int__array *)(ptrdiff_t)*array
  , *i1, *i2, *i3, *i4, *i5, *i6, *value);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_set7_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_SET7_M,
                  bHYPRE_SStructVariable__array_set7_m)
  (int64_t *array,
   int32_t *i1,
   int32_t *i2,
   int32_t *i3,
   int32_t *i4,
   int32_t *i5,
   int32_t *i6,
   int32_t *i7,
   int32_t *value)
{
  sidl_int__array_set7((struct sidl_int__array *)(ptrdiff_t)*array
  , *i1, *i2, *i3, *i4, *i5, *i6, *i7, *value);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_set_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_SET_M,
                  bHYPRE_SStructVariable__array_set_m)
  (int64_t *array,
  int32_t indices[],
  int32_t *value)
{
  sidl_int__array_set((struct sidl_int__array *)(ptrdiff_t)*array, indices,
    *value);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_dimen_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_DIMEN_M,
                  bHYPRE_SStructVariable__array_dimen_m)
  (int64_t *array, int32_t *result)
{
  *result =
    sidl_int__array_dimen((struct sidl_int__array *)(ptrdiff_t)*array);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_lower_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_LOWER_M,
                  bHYPRE_SStructVariable__array_lower_m)
  (int64_t *array,
   int32_t *ind,
   int32_t *result)
{
  *result = 
    sidl_int__array_lower((struct sidl_int__array *)(ptrdiff_t)*array, *ind);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_upper_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_UPPER_M,
                  bHYPRE_SStructVariable__array_upper_m)
  (int64_t *array,
   int32_t *ind,
   int32_t *result)
{
  *result = 
    sidl_int__array_upper((struct sidl_int__array *)(ptrdiff_t)*array, *ind);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_length_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_LENGTH_M,
                  bHYPRE_SStructVariable__array_length_m)
  (int64_t *array,
   int32_t *ind,
   int32_t *result)
{
  *result = 
    sidl_int__array_length((struct sidl_int__array *)(ptrdiff_t)*array, *ind);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_stride_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_STRIDE_M,
                  bHYPRE_SStructVariable__array_stride_m)
  (int64_t *array,
   int32_t *ind,
   int32_t *result)
{
  *result = 
    sidl_int__array_stride((struct sidl_int__array *)(ptrdiff_t)*array, *ind);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_iscolumnorder_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_ISCOLUMNORDER_M,
                  bHYPRE_SStructVariable__array_isColumnOrder_m)
  (int64_t *array,
   SIDL_F90_Bool *result)
{
  *result = sidl_int__array_isColumnOrder((struct sidl_int__array 
    *)(ptrdiff_t)*array);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_isroworder_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_ISROWORDER_M,
                  bHYPRE_SStructVariable__array_isRowOrder_m)
  (int64_t *array,
   SIDL_F90_Bool *result)
{
  *result = sidl_int__array_isRowOrder((struct sidl_int__array 
    *)(ptrdiff_t)*array);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_copy_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_COPY_M,
                  bHYPRE_SStructVariable__array_copy_m)
  (int64_t *src,
   int64_t *dest)
{
  sidl_int__array_copy((const struct sidl_int__array *)(ptrdiff_t)*src,
                       (struct sidl_int__array *)(ptrdiff_t)*dest);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_smartcopy_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_SMARTCOPY_M,
                  bHYPRE_SStructVariable__array_smartCopy_m)
  (int64_t *src)
{
  sidl_int__array_smartCopy((struct sidl_int__array *)(ptrdiff_t)*src);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_slice_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_SLICE_M,
                  bHYPRE_SStructVariable__array_slice_m)
  (int64_t *src,
   int32_t *dimen,
   int32_t numElem[],
   int32_t srcStart[],
   int32_t srcStride[],
   int32_t newStart[],
   int64_t *result)
{
  *result = (ptrdiff_t)
    sidl_int__array_slice((struct sidl_int__array *)(ptrdiff_t)*src,
      *dimen, numElem, srcStart, srcStride, newStart);
}

void
SIDLFortran90Symbol(bhypre_sstructvariable__array_ensure_m,
                  BHYPRE_SSTRUCTVARIABLE__ARRAY_ENSURE_M,
                  bHYPRE_SStructVariable__array_ensure_m)
  (int64_t *src,
   int32_t *dimen,
   int     *ordering,
   int64_t *result)
{
  *result = (ptrdiff_t)
    sidl_int__array_ensure((struct sidl_int__array *)(ptrdiff_t)*src,
    *dimen, *ordering);
}

