/*
 * File:          bHYPRE_Operator.h
 * Symbol:        bHYPRE.Operator-v1.0.0
 * Symbol Type:   interface
 * Babel Version: 0.8.2
 * SIDL Created:  20030401 14:47:34 PST
 * Generated:     20030401 14:47:44 PST
 * Description:   Client-side glue code for bHYPRE.Operator
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 * babel-version = 0.8.2
 * source-line   = 590
 * source-url    = file:/home/painter/linear_solvers/babel/Interfaces.idl
 */

#ifndef included_bHYPRE_Operator_h
#define included_bHYPRE_Operator_h

/**
 * Symbol "bHYPRE.Operator" (version 1.0.0)
 * 
 * An Operator is anything that maps one Vector to another.  The
 * terms {\tt Setup} and {\tt Apply} are reserved for Operators.
 * The implementation is allowed to assume that supplied parameter
 * arrays will not be destroyed.
 * 
 */
struct bHYPRE_Operator__object;
struct bHYPRE_Operator__array;
typedef struct bHYPRE_Operator__object* bHYPRE_Operator;

/*
 * Includes for all header dependencies.
 */

#ifndef included_SIDL_header_h
#include "SIDL_header.h"
#endif
#ifndef included_SIDL_BaseInterface_h
#include "SIDL_BaseInterface.h"
#endif
#ifndef included_SIDL_ClassInfo_h
#include "SIDL_ClassInfo.h"
#endif
#ifndef included_bHYPRE_Vector_h
#include "bHYPRE_Vector.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

void
bHYPRE_Operator_addRef(
  bHYPRE_Operator self);

void
bHYPRE_Operator_deleteRef(
  bHYPRE_Operator self);

SIDL_bool
bHYPRE_Operator_isSame(
  bHYPRE_Operator self,
  SIDL_BaseInterface iobj);

SIDL_BaseInterface
bHYPRE_Operator_queryInt(
  bHYPRE_Operator self,
  const char* name);

SIDL_bool
bHYPRE_Operator_isType(
  bHYPRE_Operator self,
  const char* name);

SIDL_ClassInfo
bHYPRE_Operator_getClassInfo(
  bHYPRE_Operator self);

/**
 * Set the MPI Communicator.
 * 
 */
int32_t
bHYPRE_Operator_SetCommunicator(
  bHYPRE_Operator self,
  void* mpi_comm);

/**
 * Set the int parameter associated with {\tt name}.
 * 
 */
int32_t
bHYPRE_Operator_SetIntParameter(
  bHYPRE_Operator self,
  const char* name,
  int32_t value);

/**
 * Set the double parameter associated with {\tt name}.
 * 
 */
int32_t
bHYPRE_Operator_SetDoubleParameter(
  bHYPRE_Operator self,
  const char* name,
  double value);

/**
 * Set the string parameter associated with {\tt name}.
 * 
 */
int32_t
bHYPRE_Operator_SetStringParameter(
  bHYPRE_Operator self,
  const char* name,
  const char* value);

/**
 * Set the int 1-D array parameter associated with {\tt name}.
 * 
 */
int32_t
bHYPRE_Operator_SetIntArray1Parameter(
  bHYPRE_Operator self,
  const char* name,
  struct SIDL_int__array* value);

/**
 * Set the int 2-D array parameter associated with {\tt name}.
 * 
 */
int32_t
bHYPRE_Operator_SetIntArray2Parameter(
  bHYPRE_Operator self,
  const char* name,
  struct SIDL_int__array* value);

/**
 * Set the double 1-D array parameter associated with {\tt name}.
 * 
 */
int32_t
bHYPRE_Operator_SetDoubleArray1Parameter(
  bHYPRE_Operator self,
  const char* name,
  struct SIDL_double__array* value);

/**
 * Set the double 2-D array parameter associated with {\tt name}.
 * 
 */
int32_t
bHYPRE_Operator_SetDoubleArray2Parameter(
  bHYPRE_Operator self,
  const char* name,
  struct SIDL_double__array* value);

/**
 * Set the int parameter associated with {\tt name}.
 * 
 */
int32_t
bHYPRE_Operator_GetIntValue(
  bHYPRE_Operator self,
  const char* name,
  int32_t* value);

/**
 * Get the double parameter associated with {\tt name}.
 * 
 */
int32_t
bHYPRE_Operator_GetDoubleValue(
  bHYPRE_Operator self,
  const char* name,
  double* value);

/**
 * (Optional) Do any preprocessing that may be necessary in
 * order to execute {\tt Apply}.
 * 
 */
int32_t
bHYPRE_Operator_Setup(
  bHYPRE_Operator self,
  bHYPRE_Vector b,
  bHYPRE_Vector x);

/**
 * Apply the operator to {\tt b}, returning {\tt x}.
 * 
 */
int32_t
bHYPRE_Operator_Apply(
  bHYPRE_Operator self,
  bHYPRE_Vector b,
  bHYPRE_Vector* x);

/**
 * Cast method for interface and class type conversions.
 */
bHYPRE_Operator
bHYPRE_Operator__cast(
  void* obj);

/**
 * String cast method for interface and class type conversions.
 */
void*
bHYPRE_Operator__cast2(
  void* obj,
  const char* type);

struct bHYPRE_Operator__array*
bHYPRE_Operator__array_createCol(int32_t        dimen,
                                 const int32_t lower[],
                                 const int32_t upper[]);

struct bHYPRE_Operator__array*
bHYPRE_Operator__array_createRow(int32_t        dimen,
                                 const int32_t lower[],
                                 const int32_t upper[]);

struct bHYPRE_Operator__array*
bHYPRE_Operator__array_create1d(int32_t len);

struct bHYPRE_Operator__array*
bHYPRE_Operator__array_create2dCol(int32_t m, int32_t n);

struct bHYPRE_Operator__array*
bHYPRE_Operator__array_create2dRow(int32_t m, int32_t n);

struct bHYPRE_Operator__array*
bHYPRE_Operator__array_borrow(bHYPRE_Operator*firstElement,
                              int32_t       dimen,
const int32_t lower[],
const int32_t upper[],
const int32_t stride[]);

struct bHYPRE_Operator__array*
bHYPRE_Operator__array_smartCopy(struct bHYPRE_Operator__array *array);

void
bHYPRE_Operator__array_addRef(struct bHYPRE_Operator__array* array);

void
bHYPRE_Operator__array_deleteRef(struct bHYPRE_Operator__array* array);

bHYPRE_Operator
bHYPRE_Operator__array_get1(const struct bHYPRE_Operator__array* array,
                            const int32_t i1);

bHYPRE_Operator
bHYPRE_Operator__array_get2(const struct bHYPRE_Operator__array* array,
                            const int32_t i1,
                            const int32_t i2);

bHYPRE_Operator
bHYPRE_Operator__array_get3(const struct bHYPRE_Operator__array* array,
                            const int32_t i1,
                            const int32_t i2,
                            const int32_t i3);

bHYPRE_Operator
bHYPRE_Operator__array_get4(const struct bHYPRE_Operator__array* array,
                            const int32_t i1,
                            const int32_t i2,
                            const int32_t i3,
                            const int32_t i4);

bHYPRE_Operator
bHYPRE_Operator__array_get(const struct bHYPRE_Operator__array* array,
                           const int32_t indices[]);

void
bHYPRE_Operator__array_set1(struct bHYPRE_Operator__array* array,
                            const int32_t i1,
                            bHYPRE_Operator const value);

void
bHYPRE_Operator__array_set2(struct bHYPRE_Operator__array* array,
                            const int32_t i1,
                            const int32_t i2,
                            bHYPRE_Operator const value);

void
bHYPRE_Operator__array_set3(struct bHYPRE_Operator__array* array,
                            const int32_t i1,
                            const int32_t i2,
                            const int32_t i3,
                            bHYPRE_Operator const value);

void
bHYPRE_Operator__array_set4(struct bHYPRE_Operator__array* array,
                            const int32_t i1,
                            const int32_t i2,
                            const int32_t i3,
                            const int32_t i4,
                            bHYPRE_Operator const value);

void
bHYPRE_Operator__array_set(struct bHYPRE_Operator__array* array,
                           const int32_t indices[],
                           bHYPRE_Operator const value);

int32_t
bHYPRE_Operator__array_dimen(const struct bHYPRE_Operator__array* array);

int32_t
bHYPRE_Operator__array_lower(const struct bHYPRE_Operator__array* array,
                             const int32_t ind);

int32_t
bHYPRE_Operator__array_upper(const struct bHYPRE_Operator__array* array,
                             const int32_t ind);

int32_t
bHYPRE_Operator__array_stride(const struct bHYPRE_Operator__array* array,
                              const int32_t ind);

int
bHYPRE_Operator__array_isColumnOrder(const struct bHYPRE_Operator__array* 
  array);

int
bHYPRE_Operator__array_isRowOrder(const struct bHYPRE_Operator__array* array);

void
bHYPRE_Operator__array_slice(const struct bHYPRE_Operator__array* src,
                                   int32_t        dimen,
                                   const int32_t  numElem[],
                                   const int32_t  *srcStart,
                                   const int32_t  *srcStride,
                                   const int32_t  *newStart);

void
bHYPRE_Operator__array_copy(const struct bHYPRE_Operator__array* src,
                                  struct bHYPRE_Operator__array* dest);

struct bHYPRE_Operator__array*
bHYPRE_Operator__array_ensure(struct bHYPRE_Operator__array* src,
                              int32_t dimen,
                              int     ordering);

#ifdef __cplusplus
}
#endif
#endif
