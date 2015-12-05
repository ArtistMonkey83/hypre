/*
 * File:          bHYPRE_Pilut_Impl.h
 * Symbol:        bHYPRE.Pilut-v1.0.0
 * Symbol Type:   class
 * Babel Version: 1.0.4
 * Description:   Server-side implementation for bHYPRE.Pilut
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 */

#ifndef included_bHYPRE_Pilut_Impl_h
#define included_bHYPRE_Pilut_Impl_h

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
#ifndef included_bHYPRE_MPICommunicator_h
#include "bHYPRE_MPICommunicator.h"
#endif
#ifndef included_bHYPRE_Operator_h
#include "bHYPRE_Operator.h"
#endif
#ifndef included_bHYPRE_Pilut_h
#include "bHYPRE_Pilut.h"
#endif
#ifndef included_bHYPRE_Solver_h
#include "bHYPRE_Solver.h"
#endif
#ifndef included_bHYPRE_Vector_h
#include "bHYPRE_Vector.h"
#endif
#ifndef included_sidl_BaseClass_h
#include "sidl_BaseClass.h"
#endif
#ifndef included_sidl_BaseInterface_h
#include "sidl_BaseInterface.h"
#endif
#ifndef included_sidl_ClassInfo_h
#include "sidl_ClassInfo.h"
#endif
#ifndef included_sidl_RuntimeException_h
#include "sidl_RuntimeException.h"
#endif

/* DO-NOT-DELETE splicer.begin(bHYPRE.Pilut._includes) */
/* Insert-Code-Here {bHYPRE.Pilut._includes} (include files) */
/* DO-NOT-DELETE splicer.end(bHYPRE.Pilut._includes) */

/*
 * Private data for class bHYPRE.Pilut
 */

struct bHYPRE_Pilut__data {
  /* DO-NOT-DELETE splicer.begin(bHYPRE.Pilut._data) */
  /* Put private data members here... */
  int ignore; /* dummy to force non-empty struct; remove if you add data */
  /* DO-NOT-DELETE splicer.end(bHYPRE.Pilut._data) */
};

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Access functions for class private data and built-in methods
 */

extern struct bHYPRE_Pilut__data*
bHYPRE_Pilut__get_data(
  bHYPRE_Pilut);

extern void
bHYPRE_Pilut__set_data(
  bHYPRE_Pilut,
  struct bHYPRE_Pilut__data*);

extern
void
impl_bHYPRE_Pilut__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_bHYPRE_Pilut__ctor(
  /* in */ bHYPRE_Pilut self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_bHYPRE_Pilut__ctor2(
  /* in */ bHYPRE_Pilut self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_bHYPRE_Pilut__dtor(
  /* in */ bHYPRE_Pilut self,
  /* out */ sidl_BaseInterface *_ex);

/*
 * User-defined object methods
 */

extern
bHYPRE_Pilut
impl_bHYPRE_Pilut_Create(
  /* in */ bHYPRE_MPICommunicator mpi_comm,
  /* in */ bHYPRE_Operator A,
  /* out */ sidl_BaseInterface *_ex);

extern struct bHYPRE_MPICommunicator__object* 
  impl_bHYPRE_Pilut_fconnect_bHYPRE_MPICommunicator(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_MPICommunicator__object* 
  impl_bHYPRE_Pilut_fcast_bHYPRE_MPICommunicator(void* bi, sidl_BaseInterface* 
  _ex);
extern struct bHYPRE_Operator__object* 
  impl_bHYPRE_Pilut_fconnect_bHYPRE_Operator(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
extern struct bHYPRE_Operator__object* impl_bHYPRE_Pilut_fcast_bHYPRE_Operator(
  void* bi, sidl_BaseInterface* _ex);
extern struct bHYPRE_Pilut__object* impl_bHYPRE_Pilut_fconnect_bHYPRE_Pilut(
  const char* url, sidl_bool ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_Pilut__object* impl_bHYPRE_Pilut_fcast_bHYPRE_Pilut(void* 
  bi, sidl_BaseInterface* _ex);
extern struct bHYPRE_Solver__object* impl_bHYPRE_Pilut_fconnect_bHYPRE_Solver(
  const char* url, sidl_bool ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_Solver__object* impl_bHYPRE_Pilut_fcast_bHYPRE_Solver(
  void* bi, sidl_BaseInterface* _ex);
extern struct bHYPRE_Vector__object* impl_bHYPRE_Pilut_fconnect_bHYPRE_Vector(
  const char* url, sidl_bool ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_Vector__object* impl_bHYPRE_Pilut_fcast_bHYPRE_Vector(
  void* bi, sidl_BaseInterface* _ex);
extern struct sidl_BaseClass__object* impl_bHYPRE_Pilut_fconnect_sidl_BaseClass(
  const char* url, sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseClass__object* impl_bHYPRE_Pilut_fcast_sidl_BaseClass(
  void* bi, sidl_BaseInterface* _ex);
extern struct sidl_BaseInterface__object* 
  impl_bHYPRE_Pilut_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_bHYPRE_Pilut_fcast_sidl_BaseInterface(void* bi, sidl_BaseInterface* _ex);
extern struct sidl_ClassInfo__object* impl_bHYPRE_Pilut_fconnect_sidl_ClassInfo(
  const char* url, sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_ClassInfo__object* impl_bHYPRE_Pilut_fcast_sidl_ClassInfo(
  void* bi, sidl_BaseInterface* _ex);
extern struct sidl_RuntimeException__object* 
  impl_bHYPRE_Pilut_fconnect_sidl_RuntimeException(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex);
extern struct sidl_RuntimeException__object* 
  impl_bHYPRE_Pilut_fcast_sidl_RuntimeException(void* bi, sidl_BaseInterface* 
  _ex);
extern
int32_t
impl_bHYPRE_Pilut_SetOperator(
  /* in */ bHYPRE_Pilut self,
  /* in */ bHYPRE_Operator A,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_Pilut_SetTolerance(
  /* in */ bHYPRE_Pilut self,
  /* in */ double tolerance,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_Pilut_SetMaxIterations(
  /* in */ bHYPRE_Pilut self,
  /* in */ int32_t max_iterations,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_Pilut_SetLogging(
  /* in */ bHYPRE_Pilut self,
  /* in */ int32_t level,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_Pilut_SetPrintLevel(
  /* in */ bHYPRE_Pilut self,
  /* in */ int32_t level,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_Pilut_GetNumIterations(
  /* in */ bHYPRE_Pilut self,
  /* out */ int32_t* num_iterations,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_Pilut_GetRelResidualNorm(
  /* in */ bHYPRE_Pilut self,
  /* out */ double* norm,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_Pilut_SetCommunicator(
  /* in */ bHYPRE_Pilut self,
  /* in */ bHYPRE_MPICommunicator mpi_comm,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_bHYPRE_Pilut_Destroy(
  /* in */ bHYPRE_Pilut self,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_Pilut_SetIntParameter(
  /* in */ bHYPRE_Pilut self,
  /* in */ const char* name,
  /* in */ int32_t value,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_Pilut_SetDoubleParameter(
  /* in */ bHYPRE_Pilut self,
  /* in */ const char* name,
  /* in */ double value,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_Pilut_SetStringParameter(
  /* in */ bHYPRE_Pilut self,
  /* in */ const char* name,
  /* in */ const char* value,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_Pilut_SetIntArray1Parameter(
  /* in */ bHYPRE_Pilut self,
  /* in */ const char* name,
  /* in rarray[nvalues] */ int32_t* value,
  /* in */ int32_t nvalues,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_Pilut_SetIntArray2Parameter(
  /* in */ bHYPRE_Pilut self,
  /* in */ const char* name,
  /* in array<int,2,column-major> */ struct sidl_int__array* value,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_Pilut_SetDoubleArray1Parameter(
  /* in */ bHYPRE_Pilut self,
  /* in */ const char* name,
  /* in rarray[nvalues] */ double* value,
  /* in */ int32_t nvalues,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_Pilut_SetDoubleArray2Parameter(
  /* in */ bHYPRE_Pilut self,
  /* in */ const char* name,
  /* in array<double,2,column-major> */ struct sidl_double__array* value,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_Pilut_GetIntValue(
  /* in */ bHYPRE_Pilut self,
  /* in */ const char* name,
  /* out */ int32_t* value,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_Pilut_GetDoubleValue(
  /* in */ bHYPRE_Pilut self,
  /* in */ const char* name,
  /* out */ double* value,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_Pilut_Setup(
  /* in */ bHYPRE_Pilut self,
  /* in */ bHYPRE_Vector b,
  /* in */ bHYPRE_Vector x,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_Pilut_Apply(
  /* in */ bHYPRE_Pilut self,
  /* in */ bHYPRE_Vector b,
  /* inout */ bHYPRE_Vector* x,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_Pilut_ApplyAdjoint(
  /* in */ bHYPRE_Pilut self,
  /* in */ bHYPRE_Vector b,
  /* inout */ bHYPRE_Vector* x,
  /* out */ sidl_BaseInterface *_ex);

extern struct bHYPRE_MPICommunicator__object* 
  impl_bHYPRE_Pilut_fconnect_bHYPRE_MPICommunicator(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_MPICommunicator__object* 
  impl_bHYPRE_Pilut_fcast_bHYPRE_MPICommunicator(void* bi, sidl_BaseInterface* 
  _ex);
extern struct bHYPRE_Operator__object* 
  impl_bHYPRE_Pilut_fconnect_bHYPRE_Operator(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
extern struct bHYPRE_Operator__object* impl_bHYPRE_Pilut_fcast_bHYPRE_Operator(
  void* bi, sidl_BaseInterface* _ex);
extern struct bHYPRE_Pilut__object* impl_bHYPRE_Pilut_fconnect_bHYPRE_Pilut(
  const char* url, sidl_bool ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_Pilut__object* impl_bHYPRE_Pilut_fcast_bHYPRE_Pilut(void* 
  bi, sidl_BaseInterface* _ex);
extern struct bHYPRE_Solver__object* impl_bHYPRE_Pilut_fconnect_bHYPRE_Solver(
  const char* url, sidl_bool ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_Solver__object* impl_bHYPRE_Pilut_fcast_bHYPRE_Solver(
  void* bi, sidl_BaseInterface* _ex);
extern struct bHYPRE_Vector__object* impl_bHYPRE_Pilut_fconnect_bHYPRE_Vector(
  const char* url, sidl_bool ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_Vector__object* impl_bHYPRE_Pilut_fcast_bHYPRE_Vector(
  void* bi, sidl_BaseInterface* _ex);
extern struct sidl_BaseClass__object* impl_bHYPRE_Pilut_fconnect_sidl_BaseClass(
  const char* url, sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseClass__object* impl_bHYPRE_Pilut_fcast_sidl_BaseClass(
  void* bi, sidl_BaseInterface* _ex);
extern struct sidl_BaseInterface__object* 
  impl_bHYPRE_Pilut_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_bHYPRE_Pilut_fcast_sidl_BaseInterface(void* bi, sidl_BaseInterface* _ex);
extern struct sidl_ClassInfo__object* impl_bHYPRE_Pilut_fconnect_sidl_ClassInfo(
  const char* url, sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_ClassInfo__object* impl_bHYPRE_Pilut_fcast_sidl_ClassInfo(
  void* bi, sidl_BaseInterface* _ex);
extern struct sidl_RuntimeException__object* 
  impl_bHYPRE_Pilut_fconnect_sidl_RuntimeException(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex);
extern struct sidl_RuntimeException__object* 
  impl_bHYPRE_Pilut_fcast_sidl_RuntimeException(void* bi, sidl_BaseInterface* 
  _ex);

#ifdef __cplusplus
}
#endif
#endif
