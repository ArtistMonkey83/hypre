/*
 * File:          bHYPRE_BoomerAMG_Impl.h
 * Symbol:        bHYPRE.BoomerAMG-v1.0.0
 * Symbol Type:   class
 * Babel Version: 0.8.2
 * SIDL Created:  20030401 14:47:20 PST
 * Generated:     20030401 14:47:31 PST
 * Description:   Server-side implementation for bHYPRE.BoomerAMG
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 * babel-version = 0.8.2
 * source-line   = 1217
 * source-url    = file:/home/painter/linear_solvers/babel/Interfaces.idl
 */

#ifndef included_bHYPRE_BoomerAMG_Impl_h
#define included_bHYPRE_BoomerAMG_Impl_h

/* DO-NOT-DELETE splicer.begin(bHYPRE.BoomerAMG._includes) */
/* Put additional include files here... */
#include "HYPRE_parcsr_ls.h"
#include "HYPRE.h"
#include "utilities.h"
#include "bHYPRE_IJParCSRMatrix.h"
#include "bHYPRE_IJParCSRVector.h"
/* DO-NOT-DELETE splicer.end(bHYPRE.BoomerAMG._includes) */

#ifndef included_SIDL_header_h
#include "SIDL_header.h"
#endif
#ifndef included_bHYPRE_BoomerAMG_h
#include "bHYPRE_BoomerAMG.h"
#endif
#ifndef included_bHYPRE_Operator_h
#include "bHYPRE_Operator.h"
#endif
#ifndef included_bHYPRE_Vector_h
#include "bHYPRE_Vector.h"
#endif

/*
 * Private data for class bHYPRE.BoomerAMG
 */

struct bHYPRE_BoomerAMG__data {
  /* DO-NOT-DELETE splicer.begin(bHYPRE.BoomerAMG._data) */
  /* Put private data members here... */
   MPI_Comm * comm;
   HYPRE_Solver solver;
   bHYPRE_IJParCSRMatrix matrix;
  /* DO-NOT-DELETE splicer.end(bHYPRE.BoomerAMG._data) */
};

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Access functions for class private data and built-in methods
 */

extern struct bHYPRE_BoomerAMG__data*
bHYPRE_BoomerAMG__get_data(
  bHYPRE_BoomerAMG);

extern void
bHYPRE_BoomerAMG__set_data(
  bHYPRE_BoomerAMG,
  struct bHYPRE_BoomerAMG__data*);

extern void
impl_bHYPRE_BoomerAMG__ctor(
  bHYPRE_BoomerAMG);

extern void
impl_bHYPRE_BoomerAMG__dtor(
  bHYPRE_BoomerAMG);

/*
 * User-defined object methods
 */

extern int32_t
impl_bHYPRE_BoomerAMG_SetCommunicator(
  bHYPRE_BoomerAMG,
  void*);

extern int32_t
impl_bHYPRE_BoomerAMG_SetIntParameter(
  bHYPRE_BoomerAMG,
  const char*,
  int32_t);

extern int32_t
impl_bHYPRE_BoomerAMG_SetDoubleParameter(
  bHYPRE_BoomerAMG,
  const char*,
  double);

extern int32_t
impl_bHYPRE_BoomerAMG_SetStringParameter(
  bHYPRE_BoomerAMG,
  const char*,
  const char*);

extern int32_t
impl_bHYPRE_BoomerAMG_SetIntArray1Parameter(
  bHYPRE_BoomerAMG,
  const char*,
  struct SIDL_int__array*);

extern int32_t
impl_bHYPRE_BoomerAMG_SetIntArray2Parameter(
  bHYPRE_BoomerAMG,
  const char*,
  struct SIDL_int__array*);

extern int32_t
impl_bHYPRE_BoomerAMG_SetDoubleArray1Parameter(
  bHYPRE_BoomerAMG,
  const char*,
  struct SIDL_double__array*);

extern int32_t
impl_bHYPRE_BoomerAMG_SetDoubleArray2Parameter(
  bHYPRE_BoomerAMG,
  const char*,
  struct SIDL_double__array*);

extern int32_t
impl_bHYPRE_BoomerAMG_GetIntValue(
  bHYPRE_BoomerAMG,
  const char*,
  int32_t*);

extern int32_t
impl_bHYPRE_BoomerAMG_GetDoubleValue(
  bHYPRE_BoomerAMG,
  const char*,
  double*);

extern int32_t
impl_bHYPRE_BoomerAMG_Setup(
  bHYPRE_BoomerAMG,
  bHYPRE_Vector,
  bHYPRE_Vector);

extern int32_t
impl_bHYPRE_BoomerAMG_Apply(
  bHYPRE_BoomerAMG,
  bHYPRE_Vector,
  bHYPRE_Vector*);

extern int32_t
impl_bHYPRE_BoomerAMG_SetOperator(
  bHYPRE_BoomerAMG,
  bHYPRE_Operator);

extern int32_t
impl_bHYPRE_BoomerAMG_SetTolerance(
  bHYPRE_BoomerAMG,
  double);

extern int32_t
impl_bHYPRE_BoomerAMG_SetMaxIterations(
  bHYPRE_BoomerAMG,
  int32_t);

extern int32_t
impl_bHYPRE_BoomerAMG_SetLogging(
  bHYPRE_BoomerAMG,
  int32_t);

extern int32_t
impl_bHYPRE_BoomerAMG_SetPrintLevel(
  bHYPRE_BoomerAMG,
  int32_t);

extern int32_t
impl_bHYPRE_BoomerAMG_GetNumIterations(
  bHYPRE_BoomerAMG,
  int32_t*);

extern int32_t
impl_bHYPRE_BoomerAMG_GetRelResidualNorm(
  bHYPRE_BoomerAMG,
  double*);

#ifdef __cplusplus
}
#endif
#endif
