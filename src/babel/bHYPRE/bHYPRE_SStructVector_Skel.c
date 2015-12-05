/*
 * File:          bHYPRE_SStructVector_Skel.c
 * Symbol:        bHYPRE.SStructVector-v1.0.0
 * Symbol Type:   class
 * Babel Version: 1.0.4
 * Description:   Server-side glue code for bHYPRE.SStructVector
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#include "bHYPRE_SStructVector_IOR.h"
#include "bHYPRE_SStructVector.h"
#include <stddef.h>

extern
void
impl_bHYPRE_SStructVector__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_bHYPRE_SStructVector__ctor(
  /* in */ bHYPRE_SStructVector self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_bHYPRE_SStructVector__ctor2(
  /* in */ bHYPRE_SStructVector self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_bHYPRE_SStructVector__dtor(
  /* in */ bHYPRE_SStructVector self,
  /* out */ sidl_BaseInterface *_ex);

extern
bHYPRE_SStructVector
impl_bHYPRE_SStructVector_Create(
  /* in */ bHYPRE_MPICommunicator mpi_comm,
  /* in */ bHYPRE_SStructGrid grid,
  /* out */ sidl_BaseInterface *_ex);

extern struct bHYPRE_MPICommunicator__object* 
  impl_bHYPRE_SStructVector_fconnect_bHYPRE_MPICommunicator(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_MPICommunicator__object* 
  impl_bHYPRE_SStructVector_fcast_bHYPRE_MPICommunicator(void* bi, 
  sidl_BaseInterface* _ex);
extern struct bHYPRE_MatrixVectorView__object* 
  impl_bHYPRE_SStructVector_fconnect_bHYPRE_MatrixVectorView(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_MatrixVectorView__object* 
  impl_bHYPRE_SStructVector_fcast_bHYPRE_MatrixVectorView(void* bi, 
  sidl_BaseInterface* _ex);
extern struct bHYPRE_ProblemDefinition__object* 
  impl_bHYPRE_SStructVector_fconnect_bHYPRE_ProblemDefinition(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_ProblemDefinition__object* 
  impl_bHYPRE_SStructVector_fcast_bHYPRE_ProblemDefinition(void* bi, 
  sidl_BaseInterface* _ex);
extern struct bHYPRE_SStructGrid__object* 
  impl_bHYPRE_SStructVector_fconnect_bHYPRE_SStructGrid(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_SStructGrid__object* 
  impl_bHYPRE_SStructVector_fcast_bHYPRE_SStructGrid(void* bi, 
  sidl_BaseInterface* _ex);
extern struct bHYPRE_SStructMatrixVectorView__object* 
  impl_bHYPRE_SStructVector_fconnect_bHYPRE_SStructMatrixVectorView(const char* 
  url, sidl_bool ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_SStructMatrixVectorView__object* 
  impl_bHYPRE_SStructVector_fcast_bHYPRE_SStructMatrixVectorView(void* bi, 
  sidl_BaseInterface* _ex);
extern struct bHYPRE_SStructVector__object* 
  impl_bHYPRE_SStructVector_fconnect_bHYPRE_SStructVector(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_SStructVector__object* 
  impl_bHYPRE_SStructVector_fcast_bHYPRE_SStructVector(void* bi, 
  sidl_BaseInterface* _ex);
extern struct bHYPRE_SStructVectorView__object* 
  impl_bHYPRE_SStructVector_fconnect_bHYPRE_SStructVectorView(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_SStructVectorView__object* 
  impl_bHYPRE_SStructVector_fcast_bHYPRE_SStructVectorView(void* bi, 
  sidl_BaseInterface* _ex);
extern struct bHYPRE_Vector__object* 
  impl_bHYPRE_SStructVector_fconnect_bHYPRE_Vector(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_Vector__object* 
  impl_bHYPRE_SStructVector_fcast_bHYPRE_Vector(void* bi, sidl_BaseInterface* 
  _ex);
extern struct sidl_BaseClass__object* 
  impl_bHYPRE_SStructVector_fconnect_sidl_BaseClass(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseClass__object* 
  impl_bHYPRE_SStructVector_fcast_sidl_BaseClass(void* bi, sidl_BaseInterface* 
  _ex);
extern struct sidl_BaseInterface__object* 
  impl_bHYPRE_SStructVector_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_bHYPRE_SStructVector_fcast_sidl_BaseInterface(void* bi, 
  sidl_BaseInterface* _ex);
extern struct sidl_ClassInfo__object* 
  impl_bHYPRE_SStructVector_fconnect_sidl_ClassInfo(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex);
extern struct sidl_ClassInfo__object* 
  impl_bHYPRE_SStructVector_fcast_sidl_ClassInfo(void* bi, sidl_BaseInterface* 
  _ex);
extern struct sidl_RuntimeException__object* 
  impl_bHYPRE_SStructVector_fconnect_sidl_RuntimeException(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_RuntimeException__object* 
  impl_bHYPRE_SStructVector_fcast_sidl_RuntimeException(void* bi, 
  sidl_BaseInterface* _ex);
extern
int32_t
impl_bHYPRE_SStructVector_SetObjectType(
  /* in */ bHYPRE_SStructVector self,
  /* in */ int32_t type,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_SStructVector_SetGrid(
  /* in */ bHYPRE_SStructVector self,
  /* in */ bHYPRE_SStructGrid grid,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_SStructVector_SetValues(
  /* in */ bHYPRE_SStructVector self,
  /* in */ int32_t part,
  /* in rarray[dim] */ int32_t* index,
  /* in */ int32_t dim,
  /* in */ int32_t var,
  /* in */ double value,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_SStructVector_SetBoxValues(
  /* in */ bHYPRE_SStructVector self,
  /* in */ int32_t part,
  /* in rarray[dim] */ int32_t* ilower,
  /* in rarray[dim] */ int32_t* iupper,
  /* in */ int32_t dim,
  /* in */ int32_t var,
  /* in rarray[nvalues] */ double* values,
  /* in */ int32_t nvalues,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_SStructVector_AddToValues(
  /* in */ bHYPRE_SStructVector self,
  /* in */ int32_t part,
  /* in rarray[dim] */ int32_t* index,
  /* in */ int32_t dim,
  /* in */ int32_t var,
  /* in */ double value,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_SStructVector_AddToBoxValues(
  /* in */ bHYPRE_SStructVector self,
  /* in */ int32_t part,
  /* in rarray[dim] */ int32_t* ilower,
  /* in rarray[dim] */ int32_t* iupper,
  /* in */ int32_t dim,
  /* in */ int32_t var,
  /* in rarray[nvalues] */ double* values,
  /* in */ int32_t nvalues,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_SStructVector_Gather(
  /* in */ bHYPRE_SStructVector self,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_SStructVector_GetValues(
  /* in */ bHYPRE_SStructVector self,
  /* in */ int32_t part,
  /* in rarray[dim] */ int32_t* index,
  /* in */ int32_t dim,
  /* in */ int32_t var,
  /* out */ double* value,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_SStructVector_GetBoxValues(
  /* in */ bHYPRE_SStructVector self,
  /* in */ int32_t part,
  /* in rarray[dim] */ int32_t* ilower,
  /* in rarray[dim] */ int32_t* iupper,
  /* in */ int32_t dim,
  /* in */ int32_t var,
  /* inout rarray[nvalues] */ double* values,
  /* in */ int32_t nvalues,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_SStructVector_SetComplex(
  /* in */ bHYPRE_SStructVector self,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_SStructVector_Print(
  /* in */ bHYPRE_SStructVector self,
  /* in */ const char* filename,
  /* in */ int32_t all,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_SStructVector_GetObject(
  /* in */ bHYPRE_SStructVector self,
  /* out */ sidl_BaseInterface* A,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_SStructVector_SetCommunicator(
  /* in */ bHYPRE_SStructVector self,
  /* in */ bHYPRE_MPICommunicator mpi_comm,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_bHYPRE_SStructVector_Destroy(
  /* in */ bHYPRE_SStructVector self,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_SStructVector_Initialize(
  /* in */ bHYPRE_SStructVector self,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_SStructVector_Assemble(
  /* in */ bHYPRE_SStructVector self,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_SStructVector_Clear(
  /* in */ bHYPRE_SStructVector self,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_SStructVector_Copy(
  /* in */ bHYPRE_SStructVector self,
  /* in */ bHYPRE_Vector x,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_SStructVector_Clone(
  /* in */ bHYPRE_SStructVector self,
  /* out */ bHYPRE_Vector* x,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_SStructVector_Scale(
  /* in */ bHYPRE_SStructVector self,
  /* in */ double a,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_SStructVector_Dot(
  /* in */ bHYPRE_SStructVector self,
  /* in */ bHYPRE_Vector x,
  /* out */ double* d,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_SStructVector_Axpy(
  /* in */ bHYPRE_SStructVector self,
  /* in */ double a,
  /* in */ bHYPRE_Vector x,
  /* out */ sidl_BaseInterface *_ex);

extern struct bHYPRE_MPICommunicator__object* 
  impl_bHYPRE_SStructVector_fconnect_bHYPRE_MPICommunicator(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_MPICommunicator__object* 
  impl_bHYPRE_SStructVector_fcast_bHYPRE_MPICommunicator(void* bi, 
  sidl_BaseInterface* _ex);
extern struct bHYPRE_MatrixVectorView__object* 
  impl_bHYPRE_SStructVector_fconnect_bHYPRE_MatrixVectorView(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_MatrixVectorView__object* 
  impl_bHYPRE_SStructVector_fcast_bHYPRE_MatrixVectorView(void* bi, 
  sidl_BaseInterface* _ex);
extern struct bHYPRE_ProblemDefinition__object* 
  impl_bHYPRE_SStructVector_fconnect_bHYPRE_ProblemDefinition(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_ProblemDefinition__object* 
  impl_bHYPRE_SStructVector_fcast_bHYPRE_ProblemDefinition(void* bi, 
  sidl_BaseInterface* _ex);
extern struct bHYPRE_SStructGrid__object* 
  impl_bHYPRE_SStructVector_fconnect_bHYPRE_SStructGrid(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_SStructGrid__object* 
  impl_bHYPRE_SStructVector_fcast_bHYPRE_SStructGrid(void* bi, 
  sidl_BaseInterface* _ex);
extern struct bHYPRE_SStructMatrixVectorView__object* 
  impl_bHYPRE_SStructVector_fconnect_bHYPRE_SStructMatrixVectorView(const char* 
  url, sidl_bool ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_SStructMatrixVectorView__object* 
  impl_bHYPRE_SStructVector_fcast_bHYPRE_SStructMatrixVectorView(void* bi, 
  sidl_BaseInterface* _ex);
extern struct bHYPRE_SStructVector__object* 
  impl_bHYPRE_SStructVector_fconnect_bHYPRE_SStructVector(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_SStructVector__object* 
  impl_bHYPRE_SStructVector_fcast_bHYPRE_SStructVector(void* bi, 
  sidl_BaseInterface* _ex);
extern struct bHYPRE_SStructVectorView__object* 
  impl_bHYPRE_SStructVector_fconnect_bHYPRE_SStructVectorView(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_SStructVectorView__object* 
  impl_bHYPRE_SStructVector_fcast_bHYPRE_SStructVectorView(void* bi, 
  sidl_BaseInterface* _ex);
extern struct bHYPRE_Vector__object* 
  impl_bHYPRE_SStructVector_fconnect_bHYPRE_Vector(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_Vector__object* 
  impl_bHYPRE_SStructVector_fcast_bHYPRE_Vector(void* bi, sidl_BaseInterface* 
  _ex);
extern struct sidl_BaseClass__object* 
  impl_bHYPRE_SStructVector_fconnect_sidl_BaseClass(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseClass__object* 
  impl_bHYPRE_SStructVector_fcast_sidl_BaseClass(void* bi, sidl_BaseInterface* 
  _ex);
extern struct sidl_BaseInterface__object* 
  impl_bHYPRE_SStructVector_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_bHYPRE_SStructVector_fcast_sidl_BaseInterface(void* bi, 
  sidl_BaseInterface* _ex);
extern struct sidl_ClassInfo__object* 
  impl_bHYPRE_SStructVector_fconnect_sidl_ClassInfo(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex);
extern struct sidl_ClassInfo__object* 
  impl_bHYPRE_SStructVector_fcast_sidl_ClassInfo(void* bi, sidl_BaseInterface* 
  _ex);
extern struct sidl_RuntimeException__object* 
  impl_bHYPRE_SStructVector_fconnect_sidl_RuntimeException(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_RuntimeException__object* 
  impl_bHYPRE_SStructVector_fcast_sidl_RuntimeException(void* bi, 
  sidl_BaseInterface* _ex);
static int32_t
skel_bHYPRE_SStructVector_SetValues(
  /* in */ bHYPRE_SStructVector self,
  /* in */ int32_t part,
  /* in rarray[dim] */ struct sidl_int__array* index,
  /* in */ int32_t var,
  /* in */ double value,
/* out */ sidl_BaseInterface *_ex)
{
  int32_t _return;
  struct sidl_int__array* index_proxy = sidl_int__array_ensure(index, 1, 
    sidl_column_major_order);
  int32_t* index_tmp = index_proxy->d_firstElement;
  int32_t dim = sidlLength(index_proxy,0);
  _return =
    impl_bHYPRE_SStructVector_SetValues(
      self,
      part,
      index_tmp,
      dim,
      var,
      value,
      _ex);
  sidl_int__array_deleteRef(index_proxy);
  return _return;
}

static int32_t
skel_bHYPRE_SStructVector_SetBoxValues(
  /* in */ bHYPRE_SStructVector self,
  /* in */ int32_t part,
  /* in rarray[dim] */ struct sidl_int__array* ilower,
  /* in rarray[dim] */ struct sidl_int__array* iupper,
  /* in */ int32_t var,
  /* in rarray[nvalues] */ struct sidl_double__array* values,
/* out */ sidl_BaseInterface *_ex)
{
  int32_t _return;
  struct sidl_int__array* ilower_proxy = sidl_int__array_ensure(ilower, 1, 
    sidl_column_major_order);
  int32_t* ilower_tmp = ilower_proxy->d_firstElement;
  struct sidl_int__array* iupper_proxy = sidl_int__array_ensure(iupper, 1, 
    sidl_column_major_order);
  int32_t* iupper_tmp = iupper_proxy->d_firstElement;
  struct sidl_double__array* values_proxy = sidl_double__array_ensure(values, 1,
    sidl_column_major_order);
  double* values_tmp = values_proxy->d_firstElement;
  int32_t nvalues = sidlLength(values_proxy,0);
  int32_t dim = sidlLength(iupper_proxy,0);
  _return =
    impl_bHYPRE_SStructVector_SetBoxValues(
      self,
      part,
      ilower_tmp,
      iupper_tmp,
      dim,
      var,
      values_tmp,
      nvalues,
      _ex);
  sidl_int__array_deleteRef(ilower_proxy);
  sidl_int__array_deleteRef(iupper_proxy);
  sidl_double__array_deleteRef(values_proxy);
  return _return;
}

static int32_t
skel_bHYPRE_SStructVector_AddToValues(
  /* in */ bHYPRE_SStructVector self,
  /* in */ int32_t part,
  /* in rarray[dim] */ struct sidl_int__array* index,
  /* in */ int32_t var,
  /* in */ double value,
/* out */ sidl_BaseInterface *_ex)
{
  int32_t _return;
  struct sidl_int__array* index_proxy = sidl_int__array_ensure(index, 1, 
    sidl_column_major_order);
  int32_t* index_tmp = index_proxy->d_firstElement;
  int32_t dim = sidlLength(index_proxy,0);
  _return =
    impl_bHYPRE_SStructVector_AddToValues(
      self,
      part,
      index_tmp,
      dim,
      var,
      value,
      _ex);
  sidl_int__array_deleteRef(index_proxy);
  return _return;
}

static int32_t
skel_bHYPRE_SStructVector_AddToBoxValues(
  /* in */ bHYPRE_SStructVector self,
  /* in */ int32_t part,
  /* in rarray[dim] */ struct sidl_int__array* ilower,
  /* in rarray[dim] */ struct sidl_int__array* iupper,
  /* in */ int32_t var,
  /* in rarray[nvalues] */ struct sidl_double__array* values,
/* out */ sidl_BaseInterface *_ex)
{
  int32_t _return;
  struct sidl_int__array* ilower_proxy = sidl_int__array_ensure(ilower, 1, 
    sidl_column_major_order);
  int32_t* ilower_tmp = ilower_proxy->d_firstElement;
  struct sidl_int__array* iupper_proxy = sidl_int__array_ensure(iupper, 1, 
    sidl_column_major_order);
  int32_t* iupper_tmp = iupper_proxy->d_firstElement;
  struct sidl_double__array* values_proxy = sidl_double__array_ensure(values, 1,
    sidl_column_major_order);
  double* values_tmp = values_proxy->d_firstElement;
  int32_t nvalues = sidlLength(values_proxy,0);
  int32_t dim = sidlLength(iupper_proxy,0);
  _return =
    impl_bHYPRE_SStructVector_AddToBoxValues(
      self,
      part,
      ilower_tmp,
      iupper_tmp,
      dim,
      var,
      values_tmp,
      nvalues,
      _ex);
  sidl_int__array_deleteRef(ilower_proxy);
  sidl_int__array_deleteRef(iupper_proxy);
  sidl_double__array_deleteRef(values_proxy);
  return _return;
}

static int32_t
skel_bHYPRE_SStructVector_GetValues(
  /* in */ bHYPRE_SStructVector self,
  /* in */ int32_t part,
  /* in rarray[dim] */ struct sidl_int__array* index,
  /* in */ int32_t var,
  /* out */ double* value,
/* out */ sidl_BaseInterface *_ex)
{
  int32_t _return;
  struct sidl_int__array* index_proxy = sidl_int__array_ensure(index, 1, 
    sidl_column_major_order);
  int32_t* index_tmp = index_proxy->d_firstElement;
  int32_t dim = sidlLength(index_proxy,0);
  _return =
    impl_bHYPRE_SStructVector_GetValues(
      self,
      part,
      index_tmp,
      dim,
      var,
      value,
      _ex);
  sidl_int__array_deleteRef(index_proxy);
  return _return;
}

static int32_t
skel_bHYPRE_SStructVector_GetBoxValues(
  /* in */ bHYPRE_SStructVector self,
  /* in */ int32_t part,
  /* in rarray[dim] */ struct sidl_int__array* ilower,
  /* in rarray[dim] */ struct sidl_int__array* iupper,
  /* in */ int32_t var,
  /* inout rarray[nvalues] */ struct sidl_double__array** values,
/* out */ sidl_BaseInterface *_ex)
{
  int32_t _return;
  struct sidl_int__array* ilower_proxy = sidl_int__array_ensure(ilower, 1, 
    sidl_column_major_order);
  int32_t* ilower_tmp = ilower_proxy->d_firstElement;
  struct sidl_int__array* iupper_proxy = sidl_int__array_ensure(iupper, 1, 
    sidl_column_major_order);
  int32_t* iupper_tmp = iupper_proxy->d_firstElement;
  struct sidl_double__array* values_proxy = sidl_double__array_ensure(*values, 
    1, sidl_column_major_order);
  double* values_tmp = values_proxy->d_firstElement;
  int32_t nvalues = sidlLength(values_proxy,0);
  int32_t dim = sidlLength(iupper_proxy,0);
  sidl_double__array_deleteRef(*values);
  _return =
    impl_bHYPRE_SStructVector_GetBoxValues(
      self,
      part,
      ilower_tmp,
      iupper_tmp,
      dim,
      var,
      values_tmp,
      nvalues,
      _ex);
  *values = values_proxy;
  values_proxy = NULL;
  sidl_int__array_deleteRef(ilower_proxy);
  sidl_int__array_deleteRef(iupper_proxy);
  sidl_double__array_deleteRef(values_proxy);
  return _return;
}

#ifdef __cplusplus
extern "C" {
#endif

void
bHYPRE_SStructVector__set_epv(struct bHYPRE_SStructVector__epv *epv)
{
  epv->f__ctor = impl_bHYPRE_SStructVector__ctor;
  epv->f__ctor2 = impl_bHYPRE_SStructVector__ctor2;
  epv->f__dtor = impl_bHYPRE_SStructVector__dtor;
  epv->f_SetObjectType = impl_bHYPRE_SStructVector_SetObjectType;
  epv->f_SetGrid = impl_bHYPRE_SStructVector_SetGrid;
  epv->f_SetValues = skel_bHYPRE_SStructVector_SetValues;
  epv->f_SetBoxValues = skel_bHYPRE_SStructVector_SetBoxValues;
  epv->f_AddToValues = skel_bHYPRE_SStructVector_AddToValues;
  epv->f_AddToBoxValues = skel_bHYPRE_SStructVector_AddToBoxValues;
  epv->f_Gather = impl_bHYPRE_SStructVector_Gather;
  epv->f_GetValues = skel_bHYPRE_SStructVector_GetValues;
  epv->f_GetBoxValues = skel_bHYPRE_SStructVector_GetBoxValues;
  epv->f_SetComplex = impl_bHYPRE_SStructVector_SetComplex;
  epv->f_Print = impl_bHYPRE_SStructVector_Print;
  epv->f_GetObject = impl_bHYPRE_SStructVector_GetObject;
  epv->f_SetCommunicator = impl_bHYPRE_SStructVector_SetCommunicator;
  epv->f_Destroy = impl_bHYPRE_SStructVector_Destroy;
  epv->f_Initialize = impl_bHYPRE_SStructVector_Initialize;
  epv->f_Assemble = impl_bHYPRE_SStructVector_Assemble;
  epv->f_Clear = impl_bHYPRE_SStructVector_Clear;
  epv->f_Copy = impl_bHYPRE_SStructVector_Copy;
  epv->f_Clone = impl_bHYPRE_SStructVector_Clone;
  epv->f_Scale = impl_bHYPRE_SStructVector_Scale;
  epv->f_Dot = impl_bHYPRE_SStructVector_Dot;
  epv->f_Axpy = impl_bHYPRE_SStructVector_Axpy;

}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void
bHYPRE_SStructVector__set_sepv(struct bHYPRE_SStructVector__sepv *sepv)
{
  sepv->f_Create = impl_bHYPRE_SStructVector_Create;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void bHYPRE_SStructVector__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_bHYPRE_SStructVector__load(&_throwaway_exception);
}
struct bHYPRE_MPICommunicator__object* 
  skel_bHYPRE_SStructVector_fconnect_bHYPRE_MPICommunicator(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fconnect_bHYPRE_MPICommunicator(url, ar, 
    _ex);
}

struct bHYPRE_MPICommunicator__object* 
  skel_bHYPRE_SStructVector_fcast_bHYPRE_MPICommunicator(void* bi, 
  sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fcast_bHYPRE_MPICommunicator(bi, _ex);
}

struct bHYPRE_MatrixVectorView__object* 
  skel_bHYPRE_SStructVector_fconnect_bHYPRE_MatrixVectorView(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fconnect_bHYPRE_MatrixVectorView(url, ar, 
    _ex);
}

struct bHYPRE_MatrixVectorView__object* 
  skel_bHYPRE_SStructVector_fcast_bHYPRE_MatrixVectorView(void* bi, 
  sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fcast_bHYPRE_MatrixVectorView(bi, _ex);
}

struct bHYPRE_ProblemDefinition__object* 
  skel_bHYPRE_SStructVector_fconnect_bHYPRE_ProblemDefinition(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fconnect_bHYPRE_ProblemDefinition(url, ar, 
    _ex);
}

struct bHYPRE_ProblemDefinition__object* 
  skel_bHYPRE_SStructVector_fcast_bHYPRE_ProblemDefinition(void* bi, 
  sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fcast_bHYPRE_ProblemDefinition(bi, _ex);
}

struct bHYPRE_SStructGrid__object* 
  skel_bHYPRE_SStructVector_fconnect_bHYPRE_SStructGrid(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fconnect_bHYPRE_SStructGrid(url, ar, _ex);
}

struct bHYPRE_SStructGrid__object* 
  skel_bHYPRE_SStructVector_fcast_bHYPRE_SStructGrid(void* bi, 
  sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fcast_bHYPRE_SStructGrid(bi, _ex);
}

struct bHYPRE_SStructMatrixVectorView__object* 
  skel_bHYPRE_SStructVector_fconnect_bHYPRE_SStructMatrixVectorView(const char* 
  url, sidl_bool ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fconnect_bHYPRE_SStructMatrixVectorView(url, 
    ar, _ex);
}

struct bHYPRE_SStructMatrixVectorView__object* 
  skel_bHYPRE_SStructVector_fcast_bHYPRE_SStructMatrixVectorView(void* bi, 
  sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fcast_bHYPRE_SStructMatrixVectorView(bi, 
    _ex);
}

struct bHYPRE_SStructVector__object* 
  skel_bHYPRE_SStructVector_fconnect_bHYPRE_SStructVector(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fconnect_bHYPRE_SStructVector(url, ar, _ex);
}

struct bHYPRE_SStructVector__object* 
  skel_bHYPRE_SStructVector_fcast_bHYPRE_SStructVector(void* bi, 
  sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fcast_bHYPRE_SStructVector(bi, _ex);
}

struct bHYPRE_SStructVectorView__object* 
  skel_bHYPRE_SStructVector_fconnect_bHYPRE_SStructVectorView(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fconnect_bHYPRE_SStructVectorView(url, ar, 
    _ex);
}

struct bHYPRE_SStructVectorView__object* 
  skel_bHYPRE_SStructVector_fcast_bHYPRE_SStructVectorView(void* bi, 
  sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fcast_bHYPRE_SStructVectorView(bi, _ex);
}

struct bHYPRE_Vector__object* skel_bHYPRE_SStructVector_fconnect_bHYPRE_Vector(
  const char* url, sidl_bool ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fconnect_bHYPRE_Vector(url, ar, _ex);
}

struct bHYPRE_Vector__object* skel_bHYPRE_SStructVector_fcast_bHYPRE_Vector(
  void* bi, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fcast_bHYPRE_Vector(bi, _ex);
}

struct sidl_BaseClass__object* 
  skel_bHYPRE_SStructVector_fconnect_sidl_BaseClass(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fconnect_sidl_BaseClass(url, ar, _ex);
}

struct sidl_BaseClass__object* skel_bHYPRE_SStructVector_fcast_sidl_BaseClass(
  void* bi, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fcast_sidl_BaseClass(bi, _ex);
}

struct sidl_BaseInterface__object* 
  skel_bHYPRE_SStructVector_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fconnect_sidl_BaseInterface(url, ar, _ex);
}

struct sidl_BaseInterface__object* 
  skel_bHYPRE_SStructVector_fcast_sidl_BaseInterface(void* bi, 
  sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fcast_sidl_BaseInterface(bi, _ex);
}

struct sidl_ClassInfo__object* 
  skel_bHYPRE_SStructVector_fconnect_sidl_ClassInfo(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fconnect_sidl_ClassInfo(url, ar, _ex);
}

struct sidl_ClassInfo__object* skel_bHYPRE_SStructVector_fcast_sidl_ClassInfo(
  void* bi, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fcast_sidl_ClassInfo(bi, _ex);
}

struct sidl_RuntimeException__object* 
  skel_bHYPRE_SStructVector_fconnect_sidl_RuntimeException(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fconnect_sidl_RuntimeException(url, ar, _ex);
}

struct sidl_RuntimeException__object* 
  skel_bHYPRE_SStructVector_fcast_sidl_RuntimeException(void* bi, 
  sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructVector_fcast_sidl_RuntimeException(bi, _ex);
}

struct bHYPRE_SStructVector__data*
bHYPRE_SStructVector__get_data(bHYPRE_SStructVector self)
{
  return (struct bHYPRE_SStructVector__data*)(self ? self->d_data : NULL);
}

void bHYPRE_SStructVector__set_data(
  bHYPRE_SStructVector self,
  struct bHYPRE_SStructVector__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
