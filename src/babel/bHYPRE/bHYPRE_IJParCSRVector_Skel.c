/*
 * File:          bHYPRE_IJParCSRVector_Skel.c
 * Symbol:        bHYPRE.IJParCSRVector-v1.0.0
 * Symbol Type:   class
 * Babel Version: 0.8.2
 * SIDL Created:  20030401 14:47:20 PST
 * Generated:     20030401 14:47:33 PST
 * Description:   Server-side glue code for bHYPRE.IJParCSRVector
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 * babel-version = 0.8.2
 * source-line   = 815
 * source-url    = file:/home/painter/linear_solvers/babel/Interfaces.idl
 */

#include "bHYPRE_IJParCSRVector_IOR.h"
#include "bHYPRE_IJParCSRVector.h"
#include <stddef.h>

extern void
impl_bHYPRE_IJParCSRVector__ctor(
  bHYPRE_IJParCSRVector);

extern void
impl_bHYPRE_IJParCSRVector__dtor(
  bHYPRE_IJParCSRVector);

extern int32_t
impl_bHYPRE_IJParCSRVector_Clear(
  bHYPRE_IJParCSRVector);

extern int32_t
impl_bHYPRE_IJParCSRVector_Copy(
  bHYPRE_IJParCSRVector,
  bHYPRE_Vector);

extern int32_t
impl_bHYPRE_IJParCSRVector_Clone(
  bHYPRE_IJParCSRVector,
  bHYPRE_Vector*);

extern int32_t
impl_bHYPRE_IJParCSRVector_Scale(
  bHYPRE_IJParCSRVector,
  double);

extern int32_t
impl_bHYPRE_IJParCSRVector_Dot(
  bHYPRE_IJParCSRVector,
  bHYPRE_Vector,
  double*);

extern int32_t
impl_bHYPRE_IJParCSRVector_Axpy(
  bHYPRE_IJParCSRVector,
  double,
  bHYPRE_Vector);

extern int32_t
impl_bHYPRE_IJParCSRVector_SetCommunicator(
  bHYPRE_IJParCSRVector,
  void*);

extern int32_t
impl_bHYPRE_IJParCSRVector_Initialize(
  bHYPRE_IJParCSRVector);

extern int32_t
impl_bHYPRE_IJParCSRVector_Assemble(
  bHYPRE_IJParCSRVector);

extern int32_t
impl_bHYPRE_IJParCSRVector_GetObject(
  bHYPRE_IJParCSRVector,
  SIDL_BaseInterface*);

extern int32_t
impl_bHYPRE_IJParCSRVector_SetLocalRange(
  bHYPRE_IJParCSRVector,
  int32_t,
  int32_t);

extern int32_t
impl_bHYPRE_IJParCSRVector_SetValues(
  bHYPRE_IJParCSRVector,
  int32_t,
  struct SIDL_int__array*,
  struct SIDL_double__array*);

extern int32_t
impl_bHYPRE_IJParCSRVector_AddToValues(
  bHYPRE_IJParCSRVector,
  int32_t,
  struct SIDL_int__array*,
  struct SIDL_double__array*);

extern int32_t
impl_bHYPRE_IJParCSRVector_GetLocalRange(
  bHYPRE_IJParCSRVector,
  int32_t*,
  int32_t*);

extern int32_t
impl_bHYPRE_IJParCSRVector_GetValues(
  bHYPRE_IJParCSRVector,
  int32_t,
  struct SIDL_int__array*,
  struct SIDL_double__array**);

extern int32_t
impl_bHYPRE_IJParCSRVector_Print(
  bHYPRE_IJParCSRVector,
  const char*);

extern int32_t
impl_bHYPRE_IJParCSRVector_Read(
  bHYPRE_IJParCSRVector,
  const char*,
  void*);

static int32_t
skel_bHYPRE_IJParCSRVector_SetValues(
  bHYPRE_IJParCSRVector self,
  int32_t nvalues,
  struct SIDL_int__array* indices,
  struct SIDL_double__array* values)
{
  int32_t _return;
  struct SIDL_int__array* indices_proxy = SIDL_int__array_ensure(indices, 1,
    SIDL_column_major_order);
  struct SIDL_double__array* values_proxy = SIDL_double__array_ensure(values, 1,
    SIDL_column_major_order);
  _return =
    impl_bHYPRE_IJParCSRVector_SetValues(
      self,
      nvalues,
      indices_proxy,
      values_proxy);
  SIDL_int__array_deleteRef(indices_proxy);
  SIDL_double__array_deleteRef(values_proxy);
  return _return;
}

static int32_t
skel_bHYPRE_IJParCSRVector_AddToValues(
  bHYPRE_IJParCSRVector self,
  int32_t nvalues,
  struct SIDL_int__array* indices,
  struct SIDL_double__array* values)
{
  int32_t _return;
  struct SIDL_int__array* indices_proxy = SIDL_int__array_ensure(indices, 1,
    SIDL_column_major_order);
  _return =
    impl_bHYPRE_IJParCSRVector_AddToValues(
      self,
      nvalues,
      indices_proxy,
      values);
  SIDL_int__array_deleteRef(indices_proxy);
  return _return;
}

static int32_t
skel_bHYPRE_IJParCSRVector_GetValues(
  bHYPRE_IJParCSRVector self,
  int32_t nvalues,
  struct SIDL_int__array* indices,
  struct SIDL_double__array** values)
{
  int32_t _return;
  struct SIDL_int__array* indices_proxy = SIDL_int__array_ensure(indices, 1,
    SIDL_column_major_order);
  struct SIDL_double__array* values_proxy = SIDL_double__array_ensure(*values,
    1, SIDL_column_major_order);
  SIDL_double__array_deleteRef(*values);
  _return =
    impl_bHYPRE_IJParCSRVector_GetValues(
      self,
      nvalues,
      indices_proxy,
      &values_proxy);
  SIDL_int__array_deleteRef(indices_proxy);
  *values = SIDL_double__array_ensure(values_proxy, 1, SIDL_column_major_order);
  SIDL_double__array_deleteRef(values_proxy);
  return _return;
}

void
bHYPRE_IJParCSRVector__set_epv(struct bHYPRE_IJParCSRVector__epv *epv)
{
  epv->f__ctor = impl_bHYPRE_IJParCSRVector__ctor;
  epv->f__dtor = impl_bHYPRE_IJParCSRVector__dtor;
  epv->f_Clear = impl_bHYPRE_IJParCSRVector_Clear;
  epv->f_Copy = impl_bHYPRE_IJParCSRVector_Copy;
  epv->f_Clone = impl_bHYPRE_IJParCSRVector_Clone;
  epv->f_Scale = impl_bHYPRE_IJParCSRVector_Scale;
  epv->f_Dot = impl_bHYPRE_IJParCSRVector_Dot;
  epv->f_Axpy = impl_bHYPRE_IJParCSRVector_Axpy;
  epv->f_SetCommunicator = impl_bHYPRE_IJParCSRVector_SetCommunicator;
  epv->f_Initialize = impl_bHYPRE_IJParCSRVector_Initialize;
  epv->f_Assemble = impl_bHYPRE_IJParCSRVector_Assemble;
  epv->f_GetObject = impl_bHYPRE_IJParCSRVector_GetObject;
  epv->f_SetLocalRange = impl_bHYPRE_IJParCSRVector_SetLocalRange;
  epv->f_SetValues = skel_bHYPRE_IJParCSRVector_SetValues;
  epv->f_AddToValues = skel_bHYPRE_IJParCSRVector_AddToValues;
  epv->f_GetLocalRange = impl_bHYPRE_IJParCSRVector_GetLocalRange;
  epv->f_GetValues = skel_bHYPRE_IJParCSRVector_GetValues;
  epv->f_Print = impl_bHYPRE_IJParCSRVector_Print;
  epv->f_Read = impl_bHYPRE_IJParCSRVector_Read;
}

struct bHYPRE_IJParCSRVector__data*
bHYPRE_IJParCSRVector__get_data(bHYPRE_IJParCSRVector self)
{
  return (struct bHYPRE_IJParCSRVector__data*)(self ? self->d_data : NULL);
}

void bHYPRE_IJParCSRVector__set_data(
  bHYPRE_IJParCSRVector self,
  struct bHYPRE_IJParCSRVector__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
