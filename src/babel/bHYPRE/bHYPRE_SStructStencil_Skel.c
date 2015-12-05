/*
 * File:          bHYPRE_SStructStencil_Skel.c
 * Symbol:        bHYPRE.SStructStencil-v1.0.0
 * Symbol Type:   class
 * Babel Version: 1.0.4
 * Description:   Server-side glue code for bHYPRE.SStructStencil
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#include "bHYPRE_SStructStencil_IOR.h"
#include "bHYPRE_SStructStencil.h"
#include <stddef.h>

extern
void
impl_bHYPRE_SStructStencil__load(
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_bHYPRE_SStructStencil__ctor(
  /* in */ bHYPRE_SStructStencil self,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_bHYPRE_SStructStencil__ctor2(
  /* in */ bHYPRE_SStructStencil self,
  /* in */ void* private_data,
  /* out */ sidl_BaseInterface *_ex);

extern
void
impl_bHYPRE_SStructStencil__dtor(
  /* in */ bHYPRE_SStructStencil self,
  /* out */ sidl_BaseInterface *_ex);

extern
bHYPRE_SStructStencil
impl_bHYPRE_SStructStencil_Create(
  /* in */ int32_t ndim,
  /* in */ int32_t size,
  /* out */ sidl_BaseInterface *_ex);

extern struct bHYPRE_SStructStencil__object* 
  impl_bHYPRE_SStructStencil_fconnect_bHYPRE_SStructStencil(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_SStructStencil__object* 
  impl_bHYPRE_SStructStencil_fcast_bHYPRE_SStructStencil(void* bi, 
  sidl_BaseInterface* _ex);
extern struct sidl_BaseClass__object* 
  impl_bHYPRE_SStructStencil_fconnect_sidl_BaseClass(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseClass__object* 
  impl_bHYPRE_SStructStencil_fcast_sidl_BaseClass(void* bi, sidl_BaseInterface* 
  _ex);
extern struct sidl_BaseInterface__object* 
  impl_bHYPRE_SStructStencil_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_bHYPRE_SStructStencil_fcast_sidl_BaseInterface(void* bi, 
  sidl_BaseInterface* _ex);
extern struct sidl_ClassInfo__object* 
  impl_bHYPRE_SStructStencil_fconnect_sidl_ClassInfo(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex);
extern struct sidl_ClassInfo__object* 
  impl_bHYPRE_SStructStencil_fcast_sidl_ClassInfo(void* bi, sidl_BaseInterface* 
  _ex);
extern struct sidl_RuntimeException__object* 
  impl_bHYPRE_SStructStencil_fconnect_sidl_RuntimeException(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_RuntimeException__object* 
  impl_bHYPRE_SStructStencil_fcast_sidl_RuntimeException(void* bi, 
  sidl_BaseInterface* _ex);
extern
void
impl_bHYPRE_SStructStencil_Destroy(
  /* in */ bHYPRE_SStructStencil self,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_SStructStencil_SetNumDimSize(
  /* in */ bHYPRE_SStructStencil self,
  /* in */ int32_t ndim,
  /* in */ int32_t size,
  /* out */ sidl_BaseInterface *_ex);

extern
int32_t
impl_bHYPRE_SStructStencil_SetEntry(
  /* in */ bHYPRE_SStructStencil self,
  /* in */ int32_t entry,
  /* in rarray[dim] */ int32_t* offset,
  /* in */ int32_t dim,
  /* in */ int32_t var,
  /* out */ sidl_BaseInterface *_ex);

extern struct bHYPRE_SStructStencil__object* 
  impl_bHYPRE_SStructStencil_fconnect_bHYPRE_SStructStencil(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct bHYPRE_SStructStencil__object* 
  impl_bHYPRE_SStructStencil_fcast_bHYPRE_SStructStencil(void* bi, 
  sidl_BaseInterface* _ex);
extern struct sidl_BaseClass__object* 
  impl_bHYPRE_SStructStencil_fconnect_sidl_BaseClass(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseClass__object* 
  impl_bHYPRE_SStructStencil_fcast_sidl_BaseClass(void* bi, sidl_BaseInterface* 
  _ex);
extern struct sidl_BaseInterface__object* 
  impl_bHYPRE_SStructStencil_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_BaseInterface__object* 
  impl_bHYPRE_SStructStencil_fcast_sidl_BaseInterface(void* bi, 
  sidl_BaseInterface* _ex);
extern struct sidl_ClassInfo__object* 
  impl_bHYPRE_SStructStencil_fconnect_sidl_ClassInfo(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex);
extern struct sidl_ClassInfo__object* 
  impl_bHYPRE_SStructStencil_fcast_sidl_ClassInfo(void* bi, sidl_BaseInterface* 
  _ex);
extern struct sidl_RuntimeException__object* 
  impl_bHYPRE_SStructStencil_fconnect_sidl_RuntimeException(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex);
extern struct sidl_RuntimeException__object* 
  impl_bHYPRE_SStructStencil_fcast_sidl_RuntimeException(void* bi, 
  sidl_BaseInterface* _ex);
static int32_t
skel_bHYPRE_SStructStencil_SetEntry(
  /* in */ bHYPRE_SStructStencil self,
  /* in */ int32_t entry,
  /* in rarray[dim] */ struct sidl_int__array* offset,
  /* in */ int32_t var,
/* out */ sidl_BaseInterface *_ex)
{
  int32_t _return;
  struct sidl_int__array* offset_proxy = sidl_int__array_ensure(offset, 1, 
    sidl_column_major_order);
  int32_t* offset_tmp = offset_proxy->d_firstElement;
  int32_t dim = sidlLength(offset_proxy,0);
  _return =
    impl_bHYPRE_SStructStencil_SetEntry(
      self,
      entry,
      offset_tmp,
      dim,
      var,
      _ex);
  sidl_int__array_deleteRef(offset_proxy);
  return _return;
}

#ifdef __cplusplus
extern "C" {
#endif

void
bHYPRE_SStructStencil__set_epv(struct bHYPRE_SStructStencil__epv *epv)
{
  epv->f__ctor = impl_bHYPRE_SStructStencil__ctor;
  epv->f__ctor2 = impl_bHYPRE_SStructStencil__ctor2;
  epv->f__dtor = impl_bHYPRE_SStructStencil__dtor;
  epv->f_Destroy = impl_bHYPRE_SStructStencil_Destroy;
  epv->f_SetNumDimSize = impl_bHYPRE_SStructStencil_SetNumDimSize;
  epv->f_SetEntry = skel_bHYPRE_SStructStencil_SetEntry;

}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void
bHYPRE_SStructStencil__set_sepv(struct bHYPRE_SStructStencil__sepv *sepv)
{
  sepv->f_Create = impl_bHYPRE_SStructStencil_Create;
}
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

void bHYPRE_SStructStencil__call_load(void) { 
  sidl_BaseInterface _throwaway_exception = NULL;
  impl_bHYPRE_SStructStencil__load(&_throwaway_exception);
}
struct bHYPRE_SStructStencil__object* 
  skel_bHYPRE_SStructStencil_fconnect_bHYPRE_SStructStencil(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructStencil_fconnect_bHYPRE_SStructStencil(url, ar, 
    _ex);
}

struct bHYPRE_SStructStencil__object* 
  skel_bHYPRE_SStructStencil_fcast_bHYPRE_SStructStencil(void* bi, 
  sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructStencil_fcast_bHYPRE_SStructStencil(bi, _ex);
}

struct sidl_BaseClass__object* 
  skel_bHYPRE_SStructStencil_fconnect_sidl_BaseClass(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructStencil_fconnect_sidl_BaseClass(url, ar, _ex);
}

struct sidl_BaseClass__object* skel_bHYPRE_SStructStencil_fcast_sidl_BaseClass(
  void* bi, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructStencil_fcast_sidl_BaseClass(bi, _ex);
}

struct sidl_BaseInterface__object* 
  skel_bHYPRE_SStructStencil_fconnect_sidl_BaseInterface(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructStencil_fconnect_sidl_BaseInterface(url, ar, _ex);
}

struct sidl_BaseInterface__object* 
  skel_bHYPRE_SStructStencil_fcast_sidl_BaseInterface(void* bi, 
  sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructStencil_fcast_sidl_BaseInterface(bi, _ex);
}

struct sidl_ClassInfo__object* 
  skel_bHYPRE_SStructStencil_fconnect_sidl_ClassInfo(const char* url, sidl_bool 
  ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructStencil_fconnect_sidl_ClassInfo(url, ar, _ex);
}

struct sidl_ClassInfo__object* skel_bHYPRE_SStructStencil_fcast_sidl_ClassInfo(
  void* bi, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructStencil_fcast_sidl_ClassInfo(bi, _ex);
}

struct sidl_RuntimeException__object* 
  skel_bHYPRE_SStructStencil_fconnect_sidl_RuntimeException(const char* url, 
  sidl_bool ar, sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructStencil_fconnect_sidl_RuntimeException(url, ar, 
    _ex);
}

struct sidl_RuntimeException__object* 
  skel_bHYPRE_SStructStencil_fcast_sidl_RuntimeException(void* bi, 
  sidl_BaseInterface *_ex) { 
  return impl_bHYPRE_SStructStencil_fcast_sidl_RuntimeException(bi, _ex);
}

struct bHYPRE_SStructStencil__data*
bHYPRE_SStructStencil__get_data(bHYPRE_SStructStencil self)
{
  return (struct bHYPRE_SStructStencil__data*)(self ? self->d_data : NULL);
}

void bHYPRE_SStructStencil__set_data(
  bHYPRE_SStructStencil self,
  struct bHYPRE_SStructStencil__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
#ifdef __cplusplus
}
#endif
