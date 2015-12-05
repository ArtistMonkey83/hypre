/*
 * File:          bHYPRE_IJParCSRMatrix_Impl.h
 * Symbol:        bHYPRE.IJParCSRMatrix-v1.0.0
 * Symbol Type:   class
 * Babel Version: 0.8.2
 * SIDL Created:  20030401 14:47:20 PST
 * Generated:     20030401 14:47:33 PST
 * Description:   Server-side implementation for bHYPRE.IJParCSRMatrix
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 * babel-version = 0.8.2
 * source-line   = 789
 * source-url    = file:/home/painter/linear_solvers/babel/Interfaces.idl
 */

#ifndef included_bHYPRE_IJParCSRMatrix_Impl_h
#define included_bHYPRE_IJParCSRMatrix_Impl_h

/* DO-NOT-DELETE splicer.begin(bHYPRE.IJParCSRMatrix._includes) */
/* Put additional include files here... */
#include "HYPRE_IJ_mv.h"
#include "HYPRE.h"
#include "utilities.h"
/* DO-NOT-DELETE splicer.end(bHYPRE.IJParCSRMatrix._includes) */

#ifndef included_SIDL_header_h
#include "SIDL_header.h"
#endif
#ifndef included_SIDL_BaseInterface_h
#include "SIDL_BaseInterface.h"
#endif
#ifndef included_bHYPRE_Vector_h
#include "bHYPRE_Vector.h"
#endif
#ifndef included_bHYPRE_IJParCSRMatrix_h
#include "bHYPRE_IJParCSRMatrix.h"
#endif

/*
 * Private data for class bHYPRE.IJParCSRMatrix
 */

struct bHYPRE_IJParCSRMatrix__data {
  /* DO-NOT-DELETE splicer.begin(bHYPRE.IJParCSRMatrix._data) */
  /* Put private data members here... */
  HYPRE_IJMatrix ij_A;
  MPI_Comm comm;
  /* DO-NOT-DELETE splicer.end(bHYPRE.IJParCSRMatrix._data) */
};

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Access functions for class private data and built-in methods
 */

extern struct bHYPRE_IJParCSRMatrix__data*
bHYPRE_IJParCSRMatrix__get_data(
  bHYPRE_IJParCSRMatrix);

extern void
bHYPRE_IJParCSRMatrix__set_data(
  bHYPRE_IJParCSRMatrix,
  struct bHYPRE_IJParCSRMatrix__data*);

extern void
impl_bHYPRE_IJParCSRMatrix__ctor(
  bHYPRE_IJParCSRMatrix);

extern void
impl_bHYPRE_IJParCSRMatrix__dtor(
  bHYPRE_IJParCSRMatrix);

/*
 * User-defined object methods
 */

extern int32_t
impl_bHYPRE_IJParCSRMatrix_SetDiagOffdSizes(
  bHYPRE_IJParCSRMatrix,
  struct SIDL_int__array*,
  struct SIDL_int__array*);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_SetCommunicator(
  bHYPRE_IJParCSRMatrix,
  void*);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_Initialize(
  bHYPRE_IJParCSRMatrix);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_Assemble(
  bHYPRE_IJParCSRMatrix);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_GetObject(
  bHYPRE_IJParCSRMatrix,
  SIDL_BaseInterface*);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_SetLocalRange(
  bHYPRE_IJParCSRMatrix,
  int32_t,
  int32_t,
  int32_t,
  int32_t);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_SetValues(
  bHYPRE_IJParCSRMatrix,
  int32_t,
  struct SIDL_int__array*,
  struct SIDL_int__array*,
  struct SIDL_int__array*,
  struct SIDL_double__array*);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_AddToValues(
  bHYPRE_IJParCSRMatrix,
  int32_t,
  struct SIDL_int__array*,
  struct SIDL_int__array*,
  struct SIDL_int__array*,
  struct SIDL_double__array*);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_GetLocalRange(
  bHYPRE_IJParCSRMatrix,
  int32_t*,
  int32_t*,
  int32_t*,
  int32_t*);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_GetRowCounts(
  bHYPRE_IJParCSRMatrix,
  int32_t,
  struct SIDL_int__array*,
  struct SIDL_int__array**);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_GetValues(
  bHYPRE_IJParCSRMatrix,
  int32_t,
  struct SIDL_int__array*,
  struct SIDL_int__array*,
  struct SIDL_int__array*,
  struct SIDL_double__array**);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_SetRowSizes(
  bHYPRE_IJParCSRMatrix,
  struct SIDL_int__array*);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_Print(
  bHYPRE_IJParCSRMatrix,
  const char*);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_Read(
  bHYPRE_IJParCSRMatrix,
  const char*,
  void*);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_SetIntParameter(
  bHYPRE_IJParCSRMatrix,
  const char*,
  int32_t);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_SetDoubleParameter(
  bHYPRE_IJParCSRMatrix,
  const char*,
  double);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_SetStringParameter(
  bHYPRE_IJParCSRMatrix,
  const char*,
  const char*);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_SetIntArray1Parameter(
  bHYPRE_IJParCSRMatrix,
  const char*,
  struct SIDL_int__array*);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_SetIntArray2Parameter(
  bHYPRE_IJParCSRMatrix,
  const char*,
  struct SIDL_int__array*);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_SetDoubleArray1Parameter(
  bHYPRE_IJParCSRMatrix,
  const char*,
  struct SIDL_double__array*);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_SetDoubleArray2Parameter(
  bHYPRE_IJParCSRMatrix,
  const char*,
  struct SIDL_double__array*);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_GetIntValue(
  bHYPRE_IJParCSRMatrix,
  const char*,
  int32_t*);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_GetDoubleValue(
  bHYPRE_IJParCSRMatrix,
  const char*,
  double*);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_Setup(
  bHYPRE_IJParCSRMatrix,
  bHYPRE_Vector,
  bHYPRE_Vector);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_Apply(
  bHYPRE_IJParCSRMatrix,
  bHYPRE_Vector,
  bHYPRE_Vector*);

extern int32_t
impl_bHYPRE_IJParCSRMatrix_GetRow(
  bHYPRE_IJParCSRMatrix,
  int32_t,
  int32_t*,
  struct SIDL_int__array**,
  struct SIDL_double__array**);

#ifdef __cplusplus
}
#endif
#endif
