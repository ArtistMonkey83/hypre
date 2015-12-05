/*
 * File:          bHYPRE_IJBuildVector.h
 * Symbol:        bHYPRE.IJBuildVector-v1.0.0
 * Symbol Type:   interface
 * Babel Version: 0.8.2
 * SIDL Created:  20030401 14:47:20 PST
 * Generated:     20030401 14:47:25 PST
 * Description:   Client-side glue code for bHYPRE.IJBuildVector
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 * babel-version = 0.8.2
 * source-line   = 203
 * source-url    = file:/home/painter/linear_solvers/babel/Interfaces.idl
 */

#ifndef included_bHYPRE_IJBuildVector_h
#define included_bHYPRE_IJBuildVector_h

/**
 * Symbol "bHYPRE.IJBuildVector" (version 1.0.0)
 */
struct bHYPRE_IJBuildVector__object;
struct bHYPRE_IJBuildVector__array;
typedef struct bHYPRE_IJBuildVector__object* bHYPRE_IJBuildVector;

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

#ifdef __cplusplus
extern "C" {
#endif

void
bHYPRE_IJBuildVector_addRef(
  bHYPRE_IJBuildVector self);

void
bHYPRE_IJBuildVector_deleteRef(
  bHYPRE_IJBuildVector self);

SIDL_bool
bHYPRE_IJBuildVector_isSame(
  bHYPRE_IJBuildVector self,
  SIDL_BaseInterface iobj);

SIDL_BaseInterface
bHYPRE_IJBuildVector_queryInt(
  bHYPRE_IJBuildVector self,
  const char* name);

SIDL_bool
bHYPRE_IJBuildVector_isType(
  bHYPRE_IJBuildVector self,
  const char* name);

SIDL_ClassInfo
bHYPRE_IJBuildVector_getClassInfo(
  bHYPRE_IJBuildVector self);

int32_t
bHYPRE_IJBuildVector_SetCommunicator(
  bHYPRE_IJBuildVector self,
  void* mpi_comm);

int32_t
bHYPRE_IJBuildVector_Initialize(
  bHYPRE_IJBuildVector self);

int32_t
bHYPRE_IJBuildVector_Assemble(
  bHYPRE_IJBuildVector self);

int32_t
bHYPRE_IJBuildVector_GetObject(
  bHYPRE_IJBuildVector self,
  SIDL_BaseInterface* A);

/**
 * Set the local range for a vector object.  Each process owns
 * some unique consecutive range of vector unknowns, indicated
 * by the global indices {\tt jlower} and {\tt jupper}.  The
 * data is required to be such that the value of {\tt jlower} on
 * any process $p$ be exactly one more than the value of {\tt
 * jupper} on process $p-1$.  Note that the first index of the
 * global vector may start with any integer value.  In
 * particular, one may use zero- or one-based indexing.
 * 
 * Collective.
 * 
 */
int32_t
bHYPRE_IJBuildVector_SetLocalRange(
  bHYPRE_IJBuildVector self,
  int32_t jlower,
  int32_t jupper);

/**
 * Sets values in vector.  The arrays {\tt values} and {\tt
 * indices} are of dimension {\tt nvalues} and contain the
 * vector values to be set and the corresponding global vector
 * indices, respectively.  Erases any previous values at the
 * specified locations and replaces them with new ones.
 * 
 * Not collective.
 * 
 */
int32_t
bHYPRE_IJBuildVector_SetValues(
  bHYPRE_IJBuildVector self,
  int32_t nvalues,
  struct SIDL_int__array* indices,
  struct SIDL_double__array* values);

/**
 * Adds to values in vector.  Usage details are analogous to
 * {\tt SetValues}.
 * 
 * Not collective.
 * 
 */
int32_t
bHYPRE_IJBuildVector_AddToValues(
  bHYPRE_IJBuildVector self,
  int32_t nvalues,
  struct SIDL_int__array* indices,
  struct SIDL_double__array* values);

/**
 * Returns range of the part of the vector owned by this
 * processor.
 * 
 */
int32_t
bHYPRE_IJBuildVector_GetLocalRange(
  bHYPRE_IJBuildVector self,
  int32_t* jlower,
  int32_t* jupper);

/**
 * Gets values in vector.  Usage details are analogous to {\tt
 * SetValues}.
 * 
 * Not collective.
 * 
 */
int32_t
bHYPRE_IJBuildVector_GetValues(
  bHYPRE_IJBuildVector self,
  int32_t nvalues,
  struct SIDL_int__array* indices,
  struct SIDL_double__array** values);

/**
 * Print the vector to file.  This is mainly for debugging
 * purposes.
 * 
 */
int32_t
bHYPRE_IJBuildVector_Print(
  bHYPRE_IJBuildVector self,
  const char* filename);

/**
 * Read the vector from file.  This is mainly for debugging
 * purposes.
 * 
 */
int32_t
bHYPRE_IJBuildVector_Read(
  bHYPRE_IJBuildVector self,
  const char* filename,
  void* comm);

/**
 * Cast method for interface and class type conversions.
 */
bHYPRE_IJBuildVector
bHYPRE_IJBuildVector__cast(
  void* obj);

/**
 * String cast method for interface and class type conversions.
 */
void*
bHYPRE_IJBuildVector__cast2(
  void* obj,
  const char* type);

struct bHYPRE_IJBuildVector__array*
bHYPRE_IJBuildVector__array_createCol(int32_t        dimen,
                                      const int32_t lower[],
                                      const int32_t upper[]);

struct bHYPRE_IJBuildVector__array*
bHYPRE_IJBuildVector__array_createRow(int32_t        dimen,
                                      const int32_t lower[],
                                      const int32_t upper[]);

struct bHYPRE_IJBuildVector__array*
bHYPRE_IJBuildVector__array_create1d(int32_t len);

struct bHYPRE_IJBuildVector__array*
bHYPRE_IJBuildVector__array_create2dCol(int32_t m, int32_t n);

struct bHYPRE_IJBuildVector__array*
bHYPRE_IJBuildVector__array_create2dRow(int32_t m, int32_t n);

struct bHYPRE_IJBuildVector__array*
bHYPRE_IJBuildVector__array_borrow(bHYPRE_IJBuildVector*firstElement,
                                   int32_t       dimen,
const int32_t lower[],
const int32_t upper[],
const int32_t stride[]);

struct bHYPRE_IJBuildVector__array*
bHYPRE_IJBuildVector__array_smartCopy(struct bHYPRE_IJBuildVector__array 
  *array);

void
bHYPRE_IJBuildVector__array_addRef(struct bHYPRE_IJBuildVector__array* array);

void
bHYPRE_IJBuildVector__array_deleteRef(struct bHYPRE_IJBuildVector__array* 
  array);

bHYPRE_IJBuildVector
bHYPRE_IJBuildVector__array_get1(const struct bHYPRE_IJBuildVector__array* 
  array,
                                 const int32_t i1);

bHYPRE_IJBuildVector
bHYPRE_IJBuildVector__array_get2(const struct bHYPRE_IJBuildVector__array* 
  array,
                                 const int32_t i1,
                                 const int32_t i2);

bHYPRE_IJBuildVector
bHYPRE_IJBuildVector__array_get3(const struct bHYPRE_IJBuildVector__array* 
  array,
                                 const int32_t i1,
                                 const int32_t i2,
                                 const int32_t i3);

bHYPRE_IJBuildVector
bHYPRE_IJBuildVector__array_get4(const struct bHYPRE_IJBuildVector__array* 
  array,
                                 const int32_t i1,
                                 const int32_t i2,
                                 const int32_t i3,
                                 const int32_t i4);

bHYPRE_IJBuildVector
bHYPRE_IJBuildVector__array_get(const struct bHYPRE_IJBuildVector__array* array,
                                const int32_t indices[]);

void
bHYPRE_IJBuildVector__array_set1(struct bHYPRE_IJBuildVector__array* array,
                                 const int32_t i1,
                                 bHYPRE_IJBuildVector const value);

void
bHYPRE_IJBuildVector__array_set2(struct bHYPRE_IJBuildVector__array* array,
                                 const int32_t i1,
                                 const int32_t i2,
                                 bHYPRE_IJBuildVector const value);

void
bHYPRE_IJBuildVector__array_set3(struct bHYPRE_IJBuildVector__array* array,
                                 const int32_t i1,
                                 const int32_t i2,
                                 const int32_t i3,
                                 bHYPRE_IJBuildVector const value);

void
bHYPRE_IJBuildVector__array_set4(struct bHYPRE_IJBuildVector__array* array,
                                 const int32_t i1,
                                 const int32_t i2,
                                 const int32_t i3,
                                 const int32_t i4,
                                 bHYPRE_IJBuildVector const value);

void
bHYPRE_IJBuildVector__array_set(struct bHYPRE_IJBuildVector__array* array,
                                const int32_t indices[],
                                bHYPRE_IJBuildVector const value);

int32_t
bHYPRE_IJBuildVector__array_dimen(const struct bHYPRE_IJBuildVector__array* 
  array);

int32_t
bHYPRE_IJBuildVector__array_lower(const struct bHYPRE_IJBuildVector__array* 
  array,
                                  const int32_t ind);

int32_t
bHYPRE_IJBuildVector__array_upper(const struct bHYPRE_IJBuildVector__array* 
  array,
                                  const int32_t ind);

int32_t
bHYPRE_IJBuildVector__array_stride(const struct bHYPRE_IJBuildVector__array* 
  array,
                                   const int32_t ind);

int
bHYPRE_IJBuildVector__array_isColumnOrder(const struct 
  bHYPRE_IJBuildVector__array* array);

int
bHYPRE_IJBuildVector__array_isRowOrder(const struct 
  bHYPRE_IJBuildVector__array* array);

void
bHYPRE_IJBuildVector__array_slice(const struct bHYPRE_IJBuildVector__array* src,
                                        int32_t        dimen,
                                        const int32_t  numElem[],
                                        const int32_t  *srcStart,
                                        const int32_t  *srcStride,
                                        const int32_t  *newStart);

void
bHYPRE_IJBuildVector__array_copy(const struct bHYPRE_IJBuildVector__array* src,
                                       struct bHYPRE_IJBuildVector__array* 
  dest);

struct bHYPRE_IJBuildVector__array*
bHYPRE_IJBuildVector__array_ensure(struct bHYPRE_IJBuildVector__array* src,
                                   int32_t dimen,
                                   int     ordering);

#ifdef __cplusplus
}
#endif
#endif
