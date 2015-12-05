/*
 * File:          bHYPRE_SStructVector_Stub.c
 * Symbol:        bHYPRE.SStructVector-v1.0.0
 * Symbol Type:   class
 * Babel Version: 0.8.2
 * SIDL Created:  20030401 14:47:35 PST
 * Generated:     20030401 14:47:41 PST
 * Description:   Client-side glue code for bHYPRE.SStructVector
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 * babel-version = 0.8.2
 * source-line   = 1074
 * source-url    = file:/home/painter/linear_solvers/babel/Interfaces.idl
 */

#include "bHYPRE_SStructVector.h"
#include "bHYPRE_SStructVector_IOR.h"
#ifndef included_SIDL_interface_IOR_h
#include "SIDL_interface_IOR.h"
#endif
#include <stddef.h>
#include "SIDL_BaseInterface_IOR.h"
#include "babel_config.h"
#ifdef SIDL_DYNAMIC_LIBRARY
#include <stdio.h>
#include <stdlib.h>
#include "SIDL_Loader.h"
#endif

/*
 * Hold pointer to IOR functions.
 */

static const struct bHYPRE_SStructVector__external *_ior = NULL;
/*
 * Lookup the symbol to get the IOR functions.
 */

static const struct bHYPRE_SStructVector__external* _loadIOR(void)
/*
 * Return pointer to internal IOR functions.
 */

{
#ifdef SIDL_STATIC_LIBRARY
  _ior = bHYPRE_SStructVector__externals();
#else
  const struct bHYPRE_SStructVector__external*(*dll_f)(void) =
    (const struct bHYPRE_SStructVector__external*(*)(void)) 
      SIDL_Loader_lookupSymbol(
      "bHYPRE_SStructVector__externals");
  _ior = (dll_f ? (*dll_f)() : NULL);
  if (!_ior) {
    fputs("Babel: unable to load the implementation for bHYPRE.SStructVector; please set SIDL_DLL_PATH\n", stderr);
    exit(-1);
  }
#endif
  return _ior;
}

#define _getIOR() (_ior ? _ior : _loadIOR())

/*
 * Constructor function for the class.
 */

bHYPRE_SStructVector
bHYPRE_SStructVector__create()
{
  return (*(_getIOR()->createObject))();
}

/*
 * <p>
 * Add one to the intrinsic reference count in the underlying object.
 * Object in <code>SIDL</code> have an intrinsic reference count.
 * Objects continue to exist as long as the reference count is
 * positive. Clients should call this method whenever they
 * create another ongoing reference to an object or interface.
 * </p>
 * <p>
 * This does not have a return value because there is no language
 * independent type that can refer to an interface or a
 * class.
 * </p>
 */

void
bHYPRE_SStructVector_addRef(
  bHYPRE_SStructVector self)
{
  (*self->d_epv->f_addRef)(
    self);
}

/*
 * Decrease by one the intrinsic reference count in the underlying
 * object, and delete the object if the reference is non-positive.
 * Objects in <code>SIDL</code> have an intrinsic reference count.
 * Clients should call this method whenever they remove a
 * reference to an object or interface.
 */

void
bHYPRE_SStructVector_deleteRef(
  bHYPRE_SStructVector self)
{
  (*self->d_epv->f_deleteRef)(
    self);
}

/*
 * Return true if and only if <code>obj</code> refers to the same
 * object as this object.
 */

SIDL_bool
bHYPRE_SStructVector_isSame(
  bHYPRE_SStructVector self,
  SIDL_BaseInterface iobj)
{
  return (*self->d_epv->f_isSame)(
    self,
    iobj);
}

/*
 * Check whether the object can support the specified interface or
 * class.  If the <code>SIDL</code> type name in <code>name</code>
 * is supported, then a reference to that object is returned with the
 * reference count incremented.  The callee will be responsible for
 * calling <code>deleteRef</code> on the returned object.  If
 * the specified type is not supported, then a null reference is
 * returned.
 */

SIDL_BaseInterface
bHYPRE_SStructVector_queryInt(
  bHYPRE_SStructVector self,
  const char* name)
{
  return (*self->d_epv->f_queryInt)(
    self,
    name);
}

/*
 * Return whether this object is an instance of the specified type.
 * The string name must be the <code>SIDL</code> type name.  This
 * routine will return <code>true</code> if and only if a cast to
 * the string type name would succeed.
 */

SIDL_bool
bHYPRE_SStructVector_isType(
  bHYPRE_SStructVector self,
  const char* name)
{
  return (*self->d_epv->f_isType)(
    self,
    name);
}

/*
 * Return the meta-data about the class implementing this interface.
 */

SIDL_ClassInfo
bHYPRE_SStructVector_getClassInfo(
  bHYPRE_SStructVector self)
{
  return (*self->d_epv->f_getClassInfo)(
    self);
}

/*
 * Set {\tt self} to 0.
 * 
 */

int32_t
bHYPRE_SStructVector_Clear(
  bHYPRE_SStructVector self)
{
  return (*self->d_epv->f_Clear)(
    self);
}

/*
 * Copy x into {\tt self}.
 * 
 */

int32_t
bHYPRE_SStructVector_Copy(
  bHYPRE_SStructVector self,
  bHYPRE_Vector x)
{
  return (*self->d_epv->f_Copy)(
    self,
    x);
}

/*
 * Create an {\tt x} compatible with {\tt self}.
 * 
 * NOTE: When this method is used in an inherited class, the
 * cloned {\tt Vector} object can be cast to an object with the
 * inherited class type.
 * 
 */

int32_t
bHYPRE_SStructVector_Clone(
  bHYPRE_SStructVector self,
  bHYPRE_Vector* x)
{
  return (*self->d_epv->f_Clone)(
    self,
    x);
}

/*
 * Scale {\tt self} by {\tt a}.
 * 
 */

int32_t
bHYPRE_SStructVector_Scale(
  bHYPRE_SStructVector self,
  double a)
{
  return (*self->d_epv->f_Scale)(
    self,
    a);
}

/*
 * Compute {\tt d}, the inner-product of {\tt self} and {\tt x}.
 * 
 */

int32_t
bHYPRE_SStructVector_Dot(
  bHYPRE_SStructVector self,
  bHYPRE_Vector x,
  double* d)
{
  return (*self->d_epv->f_Dot)(
    self,
    x,
    d);
}

/*
 * Add {\tt a}*{\tt x} to {\tt self}.
 * 
 */

int32_t
bHYPRE_SStructVector_Axpy(
  bHYPRE_SStructVector self,
  double a,
  bHYPRE_Vector x)
{
  return (*self->d_epv->f_Axpy)(
    self,
    a,
    x);
}

/*
 * Set the MPI Communicator.
 * 
 */

int32_t
bHYPRE_SStructVector_SetCommunicator(
  bHYPRE_SStructVector self,
  void* mpi_comm)
{
  return (*self->d_epv->f_SetCommunicator)(
    self,
    mpi_comm);
}

/*
 * Prepare an object for setting coefficient values, whether for
 * the first time or subsequently.
 * 
 */

int32_t
bHYPRE_SStructVector_Initialize(
  bHYPRE_SStructVector self)
{
  return (*self->d_epv->f_Initialize)(
    self);
}

/*
 * Finalize the construction of an object before using, either
 * for the first time or on subsequent uses. {\tt Initialize}
 * and {\tt Assemble} always appear in a matched set, with
 * Initialize preceding Assemble. Values can only be set in
 * between a call to Initialize and Assemble.
 * 
 */

int32_t
bHYPRE_SStructVector_Assemble(
  bHYPRE_SStructVector self)
{
  return (*self->d_epv->f_Assemble)(
    self);
}

/*
 * The problem definition interface is a {\it builder} that
 * creates an object that contains the problem definition
 * information, e.g. a matrix. To perform subsequent operations
 * with that object, it must be returned from the problem
 * definition object. {\tt GetObject} performs this function.
 * At compile time, the type of the returned object is unknown.
 * Thus, the returned type is a SIDL.BaseInterface.
 * QueryInterface or Cast must be used on the returned object to
 * convert it into a known type.
 * 
 */

int32_t
bHYPRE_SStructVector_GetObject(
  bHYPRE_SStructVector self,
  SIDL_BaseInterface* A)
{
  return (*self->d_epv->f_GetObject)(
    self,
    A);
}

/*
 * Set the vector grid.
 * 
 */

int32_t
bHYPRE_SStructVector_SetGrid(
  bHYPRE_SStructVector self,
  bHYPRE_SStructGrid grid)
{
  return (*self->d_epv->f_SetGrid)(
    self,
    grid);
}

/*
 * Set vector coefficients index by index.
 * 
 * NOTE: Users are required to set values on all processes that
 * own the associated variables.  This means that some data will
 * be multiply defined.
 * 
 * If the vector is complex, then {\tt value} consists of a pair
 * of doubles representing the real and imaginary parts of the
 * complex value.
 * 
 */

int32_t
bHYPRE_SStructVector_SetValues(
  bHYPRE_SStructVector self,
  int32_t part,
  struct SIDL_int__array* index,
  int32_t var,
  struct SIDL_double__array* value)
{
  return (*self->d_epv->f_SetValues)(
    self,
    part,
    index,
    var,
    value);
}

/*
 * Set vector coefficients a box at a time.
 * 
 * NOTE: Users are required to set values on all processes that
 * own the associated variables.  This means that some data will
 * be multiply defined.
 * 
 * If the vector is complex, then {\tt values} consists of pairs
 * of doubles representing the real and imaginary parts of each
 * complex value.
 * 
 */

int32_t
bHYPRE_SStructVector_SetBoxValues(
  bHYPRE_SStructVector self,
  int32_t part,
  struct SIDL_int__array* ilower,
  struct SIDL_int__array* iupper,
  int32_t var,
  struct SIDL_double__array* values)
{
  return (*self->d_epv->f_SetBoxValues)(
    self,
    part,
    ilower,
    iupper,
    var,
    values);
}

/*
 * Set vector coefficients index by index.
 * 
 * NOTE: Users are required to set values on all processes that
 * own the associated variables.  This means that some data will
 * be multiply defined.
 * 
 * If the vector is complex, then {\tt value} consists of a pair
 * of doubles representing the real and imaginary parts of the
 * complex value.
 * 
 */

int32_t
bHYPRE_SStructVector_AddToValues(
  bHYPRE_SStructVector self,
  int32_t part,
  struct SIDL_int__array* index,
  int32_t var,
  struct SIDL_double__array* value)
{
  return (*self->d_epv->f_AddToValues)(
    self,
    part,
    index,
    var,
    value);
}

/*
 * Set vector coefficients a box at a time.
 * 
 * NOTE: Users are required to set values on all processes that
 * own the associated variables.  This means that some data will
 * be multiply defined.
 * 
 * If the vector is complex, then {\tt values} consists of pairs
 * of doubles representing the real and imaginary parts of each
 * complex value.
 * 
 */

int32_t
bHYPRE_SStructVector_AddToBoxValues(
  bHYPRE_SStructVector self,
  int32_t part,
  struct SIDL_int__array* ilower,
  struct SIDL_int__array* iupper,
  int32_t var,
  struct SIDL_double__array* values)
{
  return (*self->d_epv->f_AddToBoxValues)(
    self,
    part,
    ilower,
    iupper,
    var,
    values);
}

/*
 * Gather vector data before calling {\tt GetValues}.
 * 
 */

int32_t
bHYPRE_SStructVector_Gather(
  bHYPRE_SStructVector self)
{
  return (*self->d_epv->f_Gather)(
    self);
}

/*
 * Get vector coefficients index by index.
 * 
 * NOTE: Users may only get values on processes that own the
 * associated variables.
 * 
 * If the vector is complex, then {\tt value} consists of a pair
 * of doubles representing the real and imaginary parts of the
 * complex value.
 * 
 */

int32_t
bHYPRE_SStructVector_GetValues(
  bHYPRE_SStructVector self,
  int32_t part,
  struct SIDL_int__array* index,
  int32_t var,
  double* value)
{
  return (*self->d_epv->f_GetValues)(
    self,
    part,
    index,
    var,
    value);
}

/*
 * Get vector coefficients a box at a time.
 * 
 * NOTE: Users may only get values on processes that own the
 * associated variables.
 * 
 * If the vector is complex, then {\tt values} consists of pairs
 * of doubles representing the real and imaginary parts of each
 * complex value.
 * 
 */

int32_t
bHYPRE_SStructVector_GetBoxValues(
  bHYPRE_SStructVector self,
  int32_t part,
  struct SIDL_int__array* ilower,
  struct SIDL_int__array* iupper,
  int32_t var,
  struct SIDL_double__array** values)
{
  return (*self->d_epv->f_GetBoxValues)(
    self,
    part,
    ilower,
    iupper,
    var,
    values);
}

/*
 * Set the vector to be complex.
 * 
 */

int32_t
bHYPRE_SStructVector_SetComplex(
  bHYPRE_SStructVector self)
{
  return (*self->d_epv->f_SetComplex)(
    self);
}

/*
 * Print the vector to file.  This is mainly for debugging
 * purposes.
 * 
 */

int32_t
bHYPRE_SStructVector_Print(
  bHYPRE_SStructVector self,
  const char* filename,
  int32_t all)
{
  return (*self->d_epv->f_Print)(
    self,
    filename,
    all);
}

/*
 * Cast method for interface and class type conversions.
 */

bHYPRE_SStructVector
bHYPRE_SStructVector__cast(
  void* obj)
{
  bHYPRE_SStructVector cast = NULL;

  if (obj != NULL) {
    SIDL_BaseInterface base = (SIDL_BaseInterface) obj;
    cast = (bHYPRE_SStructVector) (*base->d_epv->f__cast)(
      base->d_object,
      "bHYPRE.SStructVector");
  }

  return cast;
}

/*
 * String cast method for interface and class type conversions.
 */

void*
bHYPRE_SStructVector__cast2(
  void* obj,
  const char* type)
{
  void* cast = NULL;

  if (obj != NULL) {
    SIDL_BaseInterface base = (SIDL_BaseInterface) obj;
    cast = (*base->d_epv->f__cast)(base->d_object, type);
  }

  return cast;
}
struct bHYPRE_SStructVector__array*
bHYPRE_SStructVector__array_createCol(int32_t        dimen,
                                      const int32_t lower[],
                                      const int32_t upper[])
{
  return (struct 
    bHYPRE_SStructVector__array*)SIDL_interface__array_createCol(dimen, lower,
    upper);
}

struct bHYPRE_SStructVector__array*
bHYPRE_SStructVector__array_createRow(int32_t        dimen,
                                      const int32_t lower[],
                                      const int32_t upper[])
{
  return (struct 
    bHYPRE_SStructVector__array*)SIDL_interface__array_createRow(dimen, lower,
    upper);
}

struct bHYPRE_SStructVector__array*
bHYPRE_SStructVector__array_create1d(int32_t len)
{
  return (struct 
    bHYPRE_SStructVector__array*)SIDL_interface__array_create1d(len);
}

struct bHYPRE_SStructVector__array*
bHYPRE_SStructVector__array_create2dCol(int32_t m, int32_t n)
{
  return (struct 
    bHYPRE_SStructVector__array*)SIDL_interface__array_create2dCol(m, n);
}

struct bHYPRE_SStructVector__array*
bHYPRE_SStructVector__array_create2dRow(int32_t m, int32_t n)
{
  return (struct 
    bHYPRE_SStructVector__array*)SIDL_interface__array_create2dRow(m, n);
}

struct bHYPRE_SStructVector__array*
bHYPRE_SStructVector__array_borrow(bHYPRE_SStructVector*firstElement,
                                   int32_t       dimen,
const int32_t lower[],
const int32_t upper[],
const int32_t stride[])
{
  return (struct bHYPRE_SStructVector__array*)SIDL_interface__array_borrow(
    (struct SIDL_BaseInterface__object **)
    firstElement, dimen, lower, upper, stride);
}

struct bHYPRE_SStructVector__array*
bHYPRE_SStructVector__array_smartCopy(struct bHYPRE_SStructVector__array *array)
{
  return (struct bHYPRE_SStructVector__array*)
    SIDL_interface__array_smartCopy((struct SIDL_interface__array *)array);
}

void
bHYPRE_SStructVector__array_addRef(struct bHYPRE_SStructVector__array* array)
{
  SIDL_interface__array_addRef((struct SIDL_interface__array *)array);
}

void
bHYPRE_SStructVector__array_deleteRef(struct bHYPRE_SStructVector__array* array)
{
  SIDL_interface__array_deleteRef((struct SIDL_interface__array *)array);
}

bHYPRE_SStructVector
bHYPRE_SStructVector__array_get1(const struct bHYPRE_SStructVector__array* 
  array,
                                 const int32_t i1)
{
  return (bHYPRE_SStructVector)
    SIDL_interface__array_get1((const struct SIDL_interface__array *)array
    , i1);
}

bHYPRE_SStructVector
bHYPRE_SStructVector__array_get2(const struct bHYPRE_SStructVector__array* 
  array,
                                 const int32_t i1,
                                 const int32_t i2)
{
  return (bHYPRE_SStructVector)
    SIDL_interface__array_get2((const struct SIDL_interface__array *)array
    , i1, i2);
}

bHYPRE_SStructVector
bHYPRE_SStructVector__array_get3(const struct bHYPRE_SStructVector__array* 
  array,
                                 const int32_t i1,
                                 const int32_t i2,
                                 const int32_t i3)
{
  return (bHYPRE_SStructVector)
    SIDL_interface__array_get3((const struct SIDL_interface__array *)array
    , i1, i2, i3);
}

bHYPRE_SStructVector
bHYPRE_SStructVector__array_get4(const struct bHYPRE_SStructVector__array* 
  array,
                                 const int32_t i1,
                                 const int32_t i2,
                                 const int32_t i3,
                                 const int32_t i4)
{
  return (bHYPRE_SStructVector)
    SIDL_interface__array_get4((const struct SIDL_interface__array *)array
    , i1, i2, i3, i4);
}

bHYPRE_SStructVector
bHYPRE_SStructVector__array_get(const struct bHYPRE_SStructVector__array* array,
                                const int32_t indices[])
{
  return (bHYPRE_SStructVector)
    SIDL_interface__array_get((const struct SIDL_interface__array *)array,
      indices);
}

void
bHYPRE_SStructVector__array_set1(struct bHYPRE_SStructVector__array* array,
                                 const int32_t i1,
                                 bHYPRE_SStructVector const value)
{
  SIDL_interface__array_set1((struct SIDL_interface__array *)array
  , i1, (struct SIDL_BaseInterface__object *)value);
}

void
bHYPRE_SStructVector__array_set2(struct bHYPRE_SStructVector__array* array,
                                 const int32_t i1,
                                 const int32_t i2,
                                 bHYPRE_SStructVector const value)
{
  SIDL_interface__array_set2((struct SIDL_interface__array *)array
  , i1, i2, (struct SIDL_BaseInterface__object *)value);
}

void
bHYPRE_SStructVector__array_set3(struct bHYPRE_SStructVector__array* array,
                                 const int32_t i1,
                                 const int32_t i2,
                                 const int32_t i3,
                                 bHYPRE_SStructVector const value)
{
  SIDL_interface__array_set3((struct SIDL_interface__array *)array
  , i1, i2, i3, (struct SIDL_BaseInterface__object *)value);
}

void
bHYPRE_SStructVector__array_set4(struct bHYPRE_SStructVector__array* array,
                                 const int32_t i1,
                                 const int32_t i2,
                                 const int32_t i3,
                                 const int32_t i4,
                                 bHYPRE_SStructVector const value)
{
  SIDL_interface__array_set4((struct SIDL_interface__array *)array
  , i1, i2, i3, i4, (struct SIDL_BaseInterface__object *)value);
}

void
bHYPRE_SStructVector__array_set(struct bHYPRE_SStructVector__array* array,
                                const int32_t indices[],
                                bHYPRE_SStructVector const value)
{
  SIDL_interface__array_set((struct SIDL_interface__array *)array, indices,
    (struct SIDL_BaseInterface__object *)value);
}

int32_t
bHYPRE_SStructVector__array_dimen(const struct bHYPRE_SStructVector__array* 
  array)
{
  return SIDL_interface__array_dimen((struct SIDL_interface__array *)array);
}

int32_t
bHYPRE_SStructVector__array_lower(const struct bHYPRE_SStructVector__array* 
  array,
                                  const int32_t ind)
{
  return SIDL_interface__array_lower((struct SIDL_interface__array *)array,
    ind);
}

int32_t
bHYPRE_SStructVector__array_upper(const struct bHYPRE_SStructVector__array* 
  array,
                                  const int32_t ind)
{
  return SIDL_interface__array_upper((struct SIDL_interface__array *)array,
    ind);
}

int32_t
bHYPRE_SStructVector__array_stride(const struct bHYPRE_SStructVector__array* 
  array,
                                   const int32_t ind)
{
  return SIDL_interface__array_stride((struct SIDL_interface__array *)array,
    ind);
}

int
bHYPRE_SStructVector__array_isColumnOrder(const struct 
  bHYPRE_SStructVector__array* array)
{
  return SIDL_interface__array_isColumnOrder((struct SIDL_interface__array 
    *)array);
}

int
bHYPRE_SStructVector__array_isRowOrder(const struct 
  bHYPRE_SStructVector__array* array)
{
  return SIDL_interface__array_isRowOrder((struct SIDL_interface__array 
    *)array);
}

void
bHYPRE_SStructVector__array_copy(const struct bHYPRE_SStructVector__array* src,
                                       struct bHYPRE_SStructVector__array* dest)
{
  SIDL_interface__array_copy((const struct SIDL_interface__array *)src,
                             (struct SIDL_interface__array *)dest);
}

struct bHYPRE_SStructVector__array*
bHYPRE_SStructVector__array_ensure(struct bHYPRE_SStructVector__array* src,
                                   int32_t dimen,
                                   int     ordering)
{
  return (struct bHYPRE_SStructVector__array*)
    SIDL_interface__array_ensure((struct SIDL_interface__array *)src, dimen,
      ordering);
}

