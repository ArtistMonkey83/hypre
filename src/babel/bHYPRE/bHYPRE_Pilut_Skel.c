/*
 * File:          bHYPRE_Pilut_Skel.c
 * Symbol:        bHYPRE.Pilut-v1.0.0
 * Symbol Type:   class
 * Babel Version: 1.0.4
 * Description:   Server-side glue code for bHYPRE.Pilut
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#include "bHYPRE_Pilut_IOR.h"
#include "bHYPRE_Pilut.h"
#include <stddef.h>

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
static int32_t
skel_bHYPRE_Pilut_SetIntArray1Parameter(
  /* in */ bHYPRE_Pilut self,
  /* in */ const char* name,
  /* in rarray[nvalues] */ struct sidl_int__array* value,
/* out */ sidl_BaseInterface *_ex)
{
  int32_t _return;
  struct sidl_int__array* value_proxy = sidl_int__array_ensure(value, 1, 
    sidl_column_major_order);
  int32_t* value_tmp = value_proxy->d_firstElement;
  int32_t nvalues = sidlLength(value_proxy,0);
  _return =
    impl_bHYPRE_Pilut_SetIntArray1Parameter(
      self,
      name,
      value_tmp,
      nvalues,
      _ex);
  sidl_int__array_deleteRef(value_proxy);
  return _return;
}

static int32_t
skel_bHYPRE_Pilut_SetIntArray2Parameter(
  /* in */ bHYPRE_Pilut self,
  /* in */ const char* name,
  /* in array<int,2,column-major> */ struct sidl_int__array* value,
/* out */ sidl_BaseInterface *_ex)
{
  int32_t _return;
  struct sidl_int__array* value_proxy = sidl_int__array_ensure(value, 2, 
    sidl_column_major_order);
  _return =
    impl_bHYPRE_Pilut_SetIntArray2Parameter(
      self,
      name,
      value_proxy,
      _ex);
  sidl_int__array_deleteRef(value_proxy);
  return _return;
}

static int32_t
skel_bHYPRE_Pilut_SetDoubleArray1Parameter(
  /* in */ bHYPRE_Pilut self,
  /* in */ const char* name,
  /* in rarray[nvalues] */ struct sidl_double__array* value,
/* out */ sidl_BaseInterface *_ex)
{
  int32_t _return;
  struct sidl_double__array* value_proxy = sidl_double__array_ensure(value, 1, 
    sidl_column_major_order);
  double* value_tmp = value_proxy->d_firstElement;
  int32_t nvalues = sidlLength(value_proxy,0);
  _return =
    impl_bHYPRE_Pilut_SetDoubleArray1Parameter(
      self,
      name,
      value_tmp,
      nvalues,
      _ex);
  sidl_double__array_deleteRef(value_proxy);
  return _return;
}

static int32_t
skel_bHYPRE_Pilut_SetDoubleArray2Parameter(
  /* in */ bHYPRE_Pilut self,
  /* in */ const char* name,
  /* in array<double,2,column-major> */ struct sidl_double__array* value,
/* out */ sidl_BaseInterface *_ex)
{
  int32_t _return;
  struct sidl_double__array* value_proxy = sidl_double__array_ensure(value, 2, 
    sidl_column_major_order);
  _return =
    impl_bHYPRE_Pilut_SetDoubleArray2Parameter(
      self,
      name,
      value_proxy,
      _ex);
  sidl_double__array_deleteRef(value_proxy);
  return _return;
}

#ifdef __cplusplus
extern "C" {
#endif

void
bHYPRE_Pilut__set_epv(struct bHYPRE_Pilut__epv *epv)
{
  epv->f__ctor = impl_bHYPRE_Pilut__ctor;
  epv->f__ctor2 = impl_bHYPRE_Pilut__ctor2;
  epv->f__dtor = impl_bHYPRE_Pilut__dtor;
  epv->f_SetOperator = impl_bHYPRE_Pilut_SetOperator;
  epv->f_SetTolerance = impl_bHYPRE_Pilut_SetTolerance;
  epv->f_SetMaxIterations = impl_bHYPRE_Pilut_SetMaxIterations;
  epv->f_SetLogging = impl_bHYPRE_Pilut_SetLogging;
  epv->f_SetPrintLevel = impl_bHYPRE_Pilut_SetPrintLevel;
  epv->f_GetNumIterations = impl_bHYPRE_Pilut_GetNumIterations;
  epv->f_GetRelResidualNorm = impl_bHYPRE_Pilut_GetRelResidualNorm;
  epv->f_SetCommunicator = impl_bHYPRE_Pilut_SetCommunicator;
  epv->f_Destroy = impl_bHYPRE_Pilut_Destroy;
  epv->f_SetIntParameter = impl_bHYPRE_Pilut_SetIntParameter;
  epv->f_SetDoubleParameter = impl_bHYPRE_Pilut_SetDoubleParameter;
  epv->f_SetStringParameter = impl_bHYPRE_Pilut_SetStringParameter;
  epv->f_SetIntArray1Parameter = skel_bHYPRE_Pilut_SetIntArray1Parameter;
  epv->f_SetIntArray2Parameter = skel_bHYPRE_Pilut_SetIntArray2Parameter;
  epv->f_SetDoubleArray1Parameter = skel_bHYPRE_Pilut_SetDoubleArray1Parameter;
  epv->f_SetDoubleArray2Parameter = skel_bHYPRE_Pilut_SetDoubleArray2Parameter;
  epv->f_GetIntValue = impl_bHYPRE_Pilut_GetIntValue;
  epv->f_GetDoubleValue = impl_bHYPRE_Pilut_GetDoubleValue;
  epv->f_Setup = impl_bHYPRE_Pilut_Setup;
  epv->f_Apply = impl_bHYPRE_Pilut_Apply;
  epv->f_ApplyAdjoint = impl_bHYPRE_Pilut_ApplyAdjoint;

}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void
bHYPRE_Pilut__set_sepv(struct bHYPRE_Pilut__sepv *sepv)
{
  sepv->f_Create = impl_bHYPRE_Pilut_Create;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void bHYPRE_Pilut__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_bHYPRE_Pilut__load(&_throwaway_exception);
}
struct bHYPRE_MPICommunicator__object* 
  skel_bHYPRE_Pilut_fconnect_bHYPRE_MPICommunicator(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_Pilut_fconnect_bHYPRE_MPICommunicator(url, ar, _ex);
}

struct bHYPRE_MPICommunicator__object* 
  skel_bHYPRE_Pilut_fcast_bHYPRE_MPICommunicator(void* bi, sidl_BaseInterface 
  *_ex) { 
  return impl_bHYPRE_Pilut_fcast_bHYPRE_MPICommunicator(bi, _ex);
}

struct bHYPRE_Operator__object* skel_bHYPRE_Pilut_fconnect_bHYPRE_Operator(
  const char* url, sidl_bool ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_Pilut_fconnect_bHYPRE_Operator(url, ar, _ex);
}

struct bHYPRE_Operator__object* skel_bHYPRE_Pilut_fcast_bHYPRE_Operator(void* 
  bi, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_Pilut_fcast_bHYPRE_Operator(bi, _ex);
}

struct bHYPRE_Pilut__object* skel_bHYPRE_Pilut_fconnect_bHYPRE_Pilut(const 
  char* url, sidl_bool ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_Pilut_fconnect_bHYPRE_Pilut(url, ar, _ex);
}

struct bHYPRE_Pilut__object* skel_bHYPRE_Pilut_fcast_bHYPRE_Pilut(void* bi, 
  sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_Pilut_fcast_bHYPRE_Pilut(bi, _ex);
}

struct bHYPRE_Solver__object* skel_bHYPRE_Pilut_fconnect_bHYPRE_Solver(const 
  char* url, sidl_bool ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_Pilut_fconnect_bHYPRE_Solver(url, ar, _ex);
}

struct bHYPRE_Solver__object* skel_bHYPRE_Pilut_fcast_bHYPRE_Solver(void* bi, 
  sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_Pilut_fcast_bHYPRE_Solver(bi, _ex);
}

struct bHYPRE_Vector__object* skel_bHYPRE_Pilut_fconnect_bHYPRE_Vector(const 
  char* url, sidl_bool ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_Pilut_fconnect_bHYPRE_Vector(url, ar, _ex);
}

struct bHYPRE_Vector__object* skel_bHYPRE_Pilut_fcast_bHYPRE_Vector(void* bi, 
  sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_Pilut_fcast_bHYPRE_Vector(bi, _ex);
}

struct sidl_BaseClass__object* skel_bHYPRE_Pilut_fconnect_sidl_BaseClass(const 
  char* url, sidl_bool ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_Pilut_fconnect_sidl_BaseClass(url, ar, _ex);
}

struct sidl_BaseClass__object* skel_bHYPRE_Pilut_fcast_sidl_BaseClass(void* bi, 
  sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_Pilut_fcast_sidl_BaseClass(bi, _ex);
}

struct sidl_BaseInterface__object* 
  skel_bHYPRE_Pilut_fconnect_sidl_BaseInterface(const char* url, sidl_bool ar, 
  sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_Pilut_fconnect_sidl_BaseInterface(url, ar, _ex);
}

struct sidl_BaseInterface__object* skel_bHYPRE_Pilut_fcast_sidl_BaseInterface(
  void* bi, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_Pilut_fcast_sidl_BaseInterface(bi, _ex);
}

struct sidl_ClassInfo__object* skel_bHYPRE_Pilut_fconnect_sidl_ClassInfo(const 
  char* url, sidl_bool ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_Pilut_fconnect_sidl_ClassInfo(url, ar, _ex);
}

struct sidl_ClassInfo__object* skel_bHYPRE_Pilut_fcast_sidl_ClassInfo(void* bi, 
  sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_Pilut_fcast_sidl_ClassInfo(bi, _ex);
}

struct sidl_RuntimeException__object* 
  skel_bHYPRE_Pilut_fconnect_sidl_RuntimeException(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_Pilut_fconnect_sidl_RuntimeException(url, ar, _ex);
}

struct sidl_RuntimeException__object* 
  skel_bHYPRE_Pilut_fcast_sidl_RuntimeException(void* bi, sidl_BaseInterface 
  *_ex) { 
  return impl_bHYPRE_Pilut_fcast_sidl_RuntimeException(bi, _ex);
}

struct bHYPRE_Pilut__data*
bHYPRE_Pilut__get_data(bHYPRE_Pilut self)
{
  return (struct bHYPRE_Pilut__data*)(self ? self->d_data : NULL);
}

void bHYPRE_Pilut__set_data(
  bHYPRE_Pilut self,
  struct bHYPRE_Pilut__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
