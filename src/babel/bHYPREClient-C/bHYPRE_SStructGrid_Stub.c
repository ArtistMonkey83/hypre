/*
 * File:          bHYPRE_SStructGrid_Stub.c
 * Symbol:        bHYPRE.SStructGrid-v1.0.0
 * Symbol Type:   class
 * Babel Version: 0.8.2
 * SIDL Created:  20030401 14:47:34 PST
 * Generated:     20030401 14:47:40 PST
 * Description:   Client-side glue code for bHYPRE.SStructGrid
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 * babel-version = 0.8.2
 * source-line   = 904
 * source-url    = file:/home/painter/linear_solvers/babel/Interfaces.idl
 */

#include "bHYPRE_SStructGrid.h"
#include "bHYPRE_SStructGrid_IOR.h"
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

static const struct bHYPRE_SStructGrid__external *_ior = NULL;
/*
 * Lookup the symbol to get the IOR functions.
 */

static const struct bHYPRE_SStructGrid__external* _loadIOR(void)
/*
 * Return pointer to internal IOR functions.
 */

{
#ifdef SIDL_STATIC_LIBRARY
  _ior = bHYPRE_SStructGrid__externals();
#else
  const struct bHYPRE_SStructGrid__external*(*dll_f)(void) =
    (const struct bHYPRE_SStructGrid__external*(*)(void)) 
      SIDL_Loader_lookupSymbol(
      "bHYPRE_SStructGrid__externals");
  _ior = (dll_f ? (*dll_f)() : NULL);
  if (!_ior) {
    fputs("Babel: unable to load the implementation for bHYPRE.SStructGrid; please set SIDL_DLL_PATH\n", stderr);
    exit(-1);
  }
#endif
  return _ior;
}

#define _getIOR() (_ior ? _ior : _loadIOR())

/*
 * Constructor function for the class.
 */

bHYPRE_SStructGrid
bHYPRE_SStructGrid__create()
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
bHYPRE_SStructGrid_addRef(
  bHYPRE_SStructGrid self)
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
bHYPRE_SStructGrid_deleteRef(
  bHYPRE_SStructGrid self)
{
  (*self->d_epv->f_deleteRef)(
    self);
}

/*
 * Return true if and only if <code>obj</code> refers to the same
 * object as this object.
 */

SIDL_bool
bHYPRE_SStructGrid_isSame(
  bHYPRE_SStructGrid self,
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
bHYPRE_SStructGrid_queryInt(
  bHYPRE_SStructGrid self,
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
bHYPRE_SStructGrid_isType(
  bHYPRE_SStructGrid self,
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
bHYPRE_SStructGrid_getClassInfo(
  bHYPRE_SStructGrid self)
{
  return (*self->d_epv->f_getClassInfo)(
    self);
}

/*
 * Set the number of dimensions {\tt ndim} and the number of
 * structured parts {\tt nparts}.
 * 
 */

int32_t
bHYPRE_SStructGrid_SetNumDimParts(
  bHYPRE_SStructGrid self,
  int32_t ndim,
  int32_t nparts)
{
  return (*self->d_epv->f_SetNumDimParts)(
    self,
    ndim,
    nparts);
}

/*
 * Set the extents for a box on a structured part of the grid.
 * 
 */

int32_t
bHYPRE_SStructGrid_SetExtents(
  bHYPRE_SStructGrid self,
  int32_t part,
  struct SIDL_int__array* ilower,
  struct SIDL_int__array* iupper)
{
  return (*self->d_epv->f_SetExtents)(
    self,
    part,
    ilower,
    iupper);
}

/*
 * Describe the variables that live on a structured part of the
 * grid.
 * 
 */

int32_t
bHYPRE_SStructGrid_SetVariable(
  bHYPRE_SStructGrid self,
  int32_t part,
  int32_t var,
  enum bHYPRE_SStructVariable__enum vartype)
{
  return (*self->d_epv->f_SetVariable)(
    self,
    part,
    var,
    vartype);
}

/*
 * Describe additional variables that live at a particular
 * index.  These variables are appended to the array of
 * variables set in {\tt SetVariables}, and are referenced as
 * such.
 * 
 */

int32_t
bHYPRE_SStructGrid_AddVariable(
  bHYPRE_SStructGrid self,
  int32_t part,
  struct SIDL_int__array* index,
  int32_t var,
  enum bHYPRE_SStructVariable__enum vartype)
{
  return (*self->d_epv->f_AddVariable)(
    self,
    part,
    index,
    var,
    vartype);
}

/*
 * Describe how regions just outside of a part relate to other
 * parts.  This is done a box at a time.
 * 
 * The indexes {\tt ilower} and {\tt iupper} map directly to the
 * indexes {\tt nbor\_ilower} and {\tt nbor\_iupper}.  Although,
 * it is required that indexes increase from {\tt ilower} to
 * {\tt iupper}, indexes may increase and/or decrease from {\tt
 * nbor\_ilower} to {\tt nbor\_iupper}.
 * 
 * The {\tt index\_map} describes the mapping of indexes 0, 1,
 * and 2 on part {\tt part} to the corresponding indexes on part
 * {\tt nbor\_part}.  For example, triple (1, 2, 0) means that
 * indexes 0, 1, and 2 on part {\tt part} map to indexes 1, 2,
 * and 0 on part {\tt nbor\_part}, respectively.
 * 
 * NOTE: All parts related to each other via this routine must
 * have an identical list of variables and variable types.  For
 * example, if part 0 has only two variables on it, a cell
 * centered variable and a node centered variable, and we
 * declare part 1 to be a neighbor of part 0, then part 1 must
 * also have only two variables on it, and they must be of type
 * cell and node.
 * 
 */

int32_t
bHYPRE_SStructGrid_SetNeighborBox(
  bHYPRE_SStructGrid self,
  int32_t part,
  struct SIDL_int__array* ilower,
  struct SIDL_int__array* iupper,
  int32_t nbor_part,
  struct SIDL_int__array* nbor_ilower,
  struct SIDL_int__array* nbor_iupper,
  struct SIDL_int__array* index_map)
{
  return (*self->d_epv->f_SetNeighborBox)(
    self,
    part,
    ilower,
    iupper,
    nbor_part,
    nbor_ilower,
    nbor_iupper,
    index_map);
}

/*
 * Add an unstructured part to the grid.  The variables in the
 * unstructured part of the grid are referenced by a global rank
 * between 0 and the total number of unstructured variables
 * minus one.  Each process owns some unique consecutive range
 * of variables, defined by {\tt ilower} and {\tt iupper}.
 * 
 * NOTE: This is just a placeholder.  This part of the interface
 * is not finished.
 * 
 */

int32_t
bHYPRE_SStructGrid_AddUnstructuredPart(
  bHYPRE_SStructGrid self,
  int32_t ilower,
  int32_t iupper)
{
  return (*self->d_epv->f_AddUnstructuredPart)(
    self,
    ilower,
    iupper);
}

/*
 * (Optional) Set periodic for a particular part.
 * 
 */

int32_t
bHYPRE_SStructGrid_SetPeriodic(
  bHYPRE_SStructGrid self,
  int32_t part,
  struct SIDL_int__array* periodic)
{
  return (*self->d_epv->f_SetPeriodic)(
    self,
    part,
    periodic);
}

/*
 * Setting ghost in the sgrids.
 * 
 */

int32_t
bHYPRE_SStructGrid_SetNumGhost(
  bHYPRE_SStructGrid self,
  struct SIDL_int__array* num_ghost)
{
  return (*self->d_epv->f_SetNumGhost)(
    self,
    num_ghost);
}

/*
 * Cast method for interface and class type conversions.
 */

bHYPRE_SStructGrid
bHYPRE_SStructGrid__cast(
  void* obj)
{
  bHYPRE_SStructGrid cast = NULL;

  if (obj != NULL) {
    SIDL_BaseInterface base = (SIDL_BaseInterface) obj;
    cast = (bHYPRE_SStructGrid) (*base->d_epv->f__cast)(
      base->d_object,
      "bHYPRE.SStructGrid");
  }

  return cast;
}

/*
 * String cast method for interface and class type conversions.
 */

void*
bHYPRE_SStructGrid__cast2(
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
struct bHYPRE_SStructGrid__array*
bHYPRE_SStructGrid__array_createCol(int32_t        dimen,
                                    const int32_t lower[],
                                    const int32_t upper[])
{
  return (struct 
    bHYPRE_SStructGrid__array*)SIDL_interface__array_createCol(dimen, lower,
    upper);
}

struct bHYPRE_SStructGrid__array*
bHYPRE_SStructGrid__array_createRow(int32_t        dimen,
                                    const int32_t lower[],
                                    const int32_t upper[])
{
  return (struct 
    bHYPRE_SStructGrid__array*)SIDL_interface__array_createRow(dimen, lower,
    upper);
}

struct bHYPRE_SStructGrid__array*
bHYPRE_SStructGrid__array_create1d(int32_t len)
{
  return (struct bHYPRE_SStructGrid__array*)SIDL_interface__array_create1d(len);
}

struct bHYPRE_SStructGrid__array*
bHYPRE_SStructGrid__array_create2dCol(int32_t m, int32_t n)
{
  return (struct bHYPRE_SStructGrid__array*)SIDL_interface__array_create2dCol(m,
    n);
}

struct bHYPRE_SStructGrid__array*
bHYPRE_SStructGrid__array_create2dRow(int32_t m, int32_t n)
{
  return (struct bHYPRE_SStructGrid__array*)SIDL_interface__array_create2dRow(m,
    n);
}

struct bHYPRE_SStructGrid__array*
bHYPRE_SStructGrid__array_borrow(bHYPRE_SStructGrid*firstElement,
                                 int32_t       dimen,
const int32_t lower[],
const int32_t upper[],
const int32_t stride[])
{
  return (struct bHYPRE_SStructGrid__array*)SIDL_interface__array_borrow(
    (struct SIDL_BaseInterface__object **)
    firstElement, dimen, lower, upper, stride);
}

struct bHYPRE_SStructGrid__array*
bHYPRE_SStructGrid__array_smartCopy(struct bHYPRE_SStructGrid__array *array)
{
  return (struct bHYPRE_SStructGrid__array*)
    SIDL_interface__array_smartCopy((struct SIDL_interface__array *)array);
}

void
bHYPRE_SStructGrid__array_addRef(struct bHYPRE_SStructGrid__array* array)
{
  SIDL_interface__array_addRef((struct SIDL_interface__array *)array);
}

void
bHYPRE_SStructGrid__array_deleteRef(struct bHYPRE_SStructGrid__array* array)
{
  SIDL_interface__array_deleteRef((struct SIDL_interface__array *)array);
}

bHYPRE_SStructGrid
bHYPRE_SStructGrid__array_get1(const struct bHYPRE_SStructGrid__array* array,
                               const int32_t i1)
{
  return (bHYPRE_SStructGrid)
    SIDL_interface__array_get1((const struct SIDL_interface__array *)array
    , i1);
}

bHYPRE_SStructGrid
bHYPRE_SStructGrid__array_get2(const struct bHYPRE_SStructGrid__array* array,
                               const int32_t i1,
                               const int32_t i2)
{
  return (bHYPRE_SStructGrid)
    SIDL_interface__array_get2((const struct SIDL_interface__array *)array
    , i1, i2);
}

bHYPRE_SStructGrid
bHYPRE_SStructGrid__array_get3(const struct bHYPRE_SStructGrid__array* array,
                               const int32_t i1,
                               const int32_t i2,
                               const int32_t i3)
{
  return (bHYPRE_SStructGrid)
    SIDL_interface__array_get3((const struct SIDL_interface__array *)array
    , i1, i2, i3);
}

bHYPRE_SStructGrid
bHYPRE_SStructGrid__array_get4(const struct bHYPRE_SStructGrid__array* array,
                               const int32_t i1,
                               const int32_t i2,
                               const int32_t i3,
                               const int32_t i4)
{
  return (bHYPRE_SStructGrid)
    SIDL_interface__array_get4((const struct SIDL_interface__array *)array
    , i1, i2, i3, i4);
}

bHYPRE_SStructGrid
bHYPRE_SStructGrid__array_get(const struct bHYPRE_SStructGrid__array* array,
                              const int32_t indices[])
{
  return (bHYPRE_SStructGrid)
    SIDL_interface__array_get((const struct SIDL_interface__array *)array,
      indices);
}

void
bHYPRE_SStructGrid__array_set1(struct bHYPRE_SStructGrid__array* array,
                               const int32_t i1,
                               bHYPRE_SStructGrid const value)
{
  SIDL_interface__array_set1((struct SIDL_interface__array *)array
  , i1, (struct SIDL_BaseInterface__object *)value);
}

void
bHYPRE_SStructGrid__array_set2(struct bHYPRE_SStructGrid__array* array,
                               const int32_t i1,
                               const int32_t i2,
                               bHYPRE_SStructGrid const value)
{
  SIDL_interface__array_set2((struct SIDL_interface__array *)array
  , i1, i2, (struct SIDL_BaseInterface__object *)value);
}

void
bHYPRE_SStructGrid__array_set3(struct bHYPRE_SStructGrid__array* array,
                               const int32_t i1,
                               const int32_t i2,
                               const int32_t i3,
                               bHYPRE_SStructGrid const value)
{
  SIDL_interface__array_set3((struct SIDL_interface__array *)array
  , i1, i2, i3, (struct SIDL_BaseInterface__object *)value);
}

void
bHYPRE_SStructGrid__array_set4(struct bHYPRE_SStructGrid__array* array,
                               const int32_t i1,
                               const int32_t i2,
                               const int32_t i3,
                               const int32_t i4,
                               bHYPRE_SStructGrid const value)
{
  SIDL_interface__array_set4((struct SIDL_interface__array *)array
  , i1, i2, i3, i4, (struct SIDL_BaseInterface__object *)value);
}

void
bHYPRE_SStructGrid__array_set(struct bHYPRE_SStructGrid__array* array,
                              const int32_t indices[],
                              bHYPRE_SStructGrid const value)
{
  SIDL_interface__array_set((struct SIDL_interface__array *)array, indices,
    (struct SIDL_BaseInterface__object *)value);
}

int32_t
bHYPRE_SStructGrid__array_dimen(const struct bHYPRE_SStructGrid__array* array)
{
  return SIDL_interface__array_dimen((struct SIDL_interface__array *)array);
}

int32_t
bHYPRE_SStructGrid__array_lower(const struct bHYPRE_SStructGrid__array* array,
                                const int32_t ind)
{
  return SIDL_interface__array_lower((struct SIDL_interface__array *)array,
    ind);
}

int32_t
bHYPRE_SStructGrid__array_upper(const struct bHYPRE_SStructGrid__array* array,
                                const int32_t ind)
{
  return SIDL_interface__array_upper((struct SIDL_interface__array *)array,
    ind);
}

int32_t
bHYPRE_SStructGrid__array_stride(const struct bHYPRE_SStructGrid__array* array,
                                 const int32_t ind)
{
  return SIDL_interface__array_stride((struct SIDL_interface__array *)array,
    ind);
}

int
bHYPRE_SStructGrid__array_isColumnOrder(const struct bHYPRE_SStructGrid__array* 
  array)
{
  return SIDL_interface__array_isColumnOrder((struct SIDL_interface__array 
    *)array);
}

int
bHYPRE_SStructGrid__array_isRowOrder(const struct bHYPRE_SStructGrid__array* 
  array)
{
  return SIDL_interface__array_isRowOrder((struct SIDL_interface__array 
    *)array);
}

void
bHYPRE_SStructGrid__array_copy(const struct bHYPRE_SStructGrid__array* src,
                                     struct bHYPRE_SStructGrid__array* dest)
{
  SIDL_interface__array_copy((const struct SIDL_interface__array *)src,
                             (struct SIDL_interface__array *)dest);
}

struct bHYPRE_SStructGrid__array*
bHYPRE_SStructGrid__array_ensure(struct bHYPRE_SStructGrid__array* src,
                                 int32_t dimen,
                                 int     ordering)
{
  return (struct bHYPRE_SStructGrid__array*)
    SIDL_interface__array_ensure((struct SIDL_interface__array *)src, dimen,
      ordering);
}

