/*
 * File:          bHYPRE_IJParCSRVector.h
 * Symbol:        bHYPRE.IJParCSRVector-v1.0.0
 * Symbol Type:   class
 * Babel Version: 1.0.4
 * Description:   Client-side glue code for bHYPRE.IJParCSRVector
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#ifndef included_bHYPRE_IJParCSRVector_h
#define included_bHYPRE_IJParCSRVector_h

/**
 * Symbol "bHYPRE.IJParCSRVector" (version 1.0.0)
 * 
 * The IJParCSR vector class.
 * 
 * Objects of this type can be cast to IJVectorView or Vector
 * objects using the {\tt \_\_cast} methods.
 */
struct bHYPRE_IJParCSRVector__object;
struct bHYPRE_IJParCSRVector__array;
typedef struct bHYPRE_IJParCSRVector__object* bHYPRE_IJParCSRVector;

/*
 * Includes for all header dependencies.
 */

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
#ifndef included_bHYPRE_MPICommunicator_h
#include "bHYPRE_MPICommunicator.h"
#endif
#ifndef included_bHYPRE_Vector_h
#include "bHYPRE_Vector.h"
#endif
#ifndef included_sidl_BaseException_h
#include "sidl_BaseException.h"
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
#ifndef included_sidl_SIDLException_h
#include "sidl_SIDLException.h"
#endif

#ifndef included_sidl_rmi_Call_h
#include "sidl_rmi_Call.h"
#endif
#ifndef included_sidl_rmi_Return_h
#include "sidl_rmi_Return.h"
#endif
#ifdef SIDL_C_HAS_INLINE
#ifndef included_bHYPRE_IJParCSRVector_IOR_h
#include "bHYPRE_IJParCSRVector_IOR.h"
#endif
#endif /* SIDL_C_HAS_INLINE */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * Constructor function for the class.
 */
struct bHYPRE_IJParCSRVector__object*
bHYPRE_IJParCSRVector__create(sidl_BaseInterface* _ex);

/**
 * RMI constructor function for the class.
 */
bHYPRE_IJParCSRVector
bHYPRE_IJParCSRVector__createRemote(const char * url, sidl_BaseInterface *_ex);

/**
 * Wraps up the private data struct pointer (struct bHYPRE_IJParCSRVector__data) passed in rather than running the constructor.
 */
bHYPRE_IJParCSRVector
bHYPRE_IJParCSRVector__wrapObj(void * data, sidl_BaseInterface *_ex);

/**
 * RMI connector function for the class.(addrefs)
 */
bHYPRE_IJParCSRVector
bHYPRE_IJParCSRVector__connect(const char *, sidl_BaseInterface *_ex);

/**
 *  This function is the preferred way to create an IJParCSR Vector. 
 */
bHYPRE_IJParCSRVector
bHYPRE_IJParCSRVector_Create(
  /* in */ bHYPRE_MPICommunicator mpi_comm,
  /* in */ int32_t jlower,
  /* in */ int32_t jupper,
  /* out */ sidl_BaseInterface *_ex);

SIDL_C_INLINE_DECL
void
bHYPRE_IJParCSRVector_addRef(
  /* in */ bHYPRE_IJParCSRVector self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  (*self->d_epv->f_addRef)(
    self,
    _ex);
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


SIDL_C_INLINE_DECL
void
bHYPRE_IJParCSRVector_deleteRef(
  /* in */ bHYPRE_IJParCSRVector self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  (*self->d_epv->f_deleteRef)(
    self,
    _ex);
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


SIDL_C_INLINE_DECL
sidl_bool
bHYPRE_IJParCSRVector_isSame(
  /* in */ bHYPRE_IJParCSRVector self,
  /* in */ sidl_BaseInterface iobj,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  sidl_bool _result;
  _result = (*self->d_epv->f_isSame)(
    self,
    iobj,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


SIDL_C_INLINE_DECL
sidl_bool
bHYPRE_IJParCSRVector_isType(
  /* in */ bHYPRE_IJParCSRVector self,
  /* in */ const char* name,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  sidl_bool _result;
  _result = (*self->d_epv->f_isType)(
    self,
    name,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


SIDL_C_INLINE_DECL
sidl_ClassInfo
bHYPRE_IJParCSRVector_getClassInfo(
  /* in */ bHYPRE_IJParCSRVector self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  sidl_ClassInfo _result;
  _result = (*self->d_epv->f_getClassInfo)(
    self,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


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
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_IJParCSRVector_SetLocalRange(
  /* in */ bHYPRE_IJParCSRVector self,
  /* in */ int32_t jlower,
  /* in */ int32_t jupper,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_SetLocalRange)(
    self,
    jlower,
    jupper,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Sets values in vector.  The arrays {\tt values} and {\tt
 * indices} are of dimension {\tt nvalues} and contain the
 * vector values to be set and the corresponding global vector
 * indices, respectively.  Erases any previous values at the
 * specified locations and replaces them with new ones.
 * 
 * Not collective.
 */
int32_t
bHYPRE_IJParCSRVector_SetValues(
  /* in */ bHYPRE_IJParCSRVector self,
  /* in */ int32_t nvalues,
  /* in rarray[nvalues] */ int32_t* indices,
  /* in rarray[nvalues] */ double* values,
  /* out */ sidl_BaseInterface *_ex);

/**
 * Adds to values in vector.  Usage details are analogous to
 * {\tt SetValues}.
 * 
 * Not collective.
 */
int32_t
bHYPRE_IJParCSRVector_AddToValues(
  /* in */ bHYPRE_IJParCSRVector self,
  /* in */ int32_t nvalues,
  /* in rarray[nvalues] */ int32_t* indices,
  /* in rarray[nvalues] */ double* values,
  /* out */ sidl_BaseInterface *_ex);

/**
 * Returns range of the part of the vector owned by this
 * processor.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_IJParCSRVector_GetLocalRange(
  /* in */ bHYPRE_IJParCSRVector self,
  /* out */ int32_t* jlower,
  /* out */ int32_t* jupper,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_GetLocalRange)(
    self,
    jlower,
    jupper,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Gets values in vector.  Usage details are analogous to {\tt
 * SetValues}.
 * 
 * Not collective.
 */
int32_t
bHYPRE_IJParCSRVector_GetValues(
  /* in */ bHYPRE_IJParCSRVector self,
  /* in */ int32_t nvalues,
  /* in rarray[nvalues] */ int32_t* indices,
  /* inout rarray[nvalues] */ double* values,
  /* out */ sidl_BaseInterface *_ex);

/**
 * Print the vector to file.  This is mainly for debugging
 * purposes.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_IJParCSRVector_Print(
  /* in */ bHYPRE_IJParCSRVector self,
  /* in */ const char* filename,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_Print)(
    self,
    filename,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Read the vector from file.  This is mainly for debugging
 * purposes.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_IJParCSRVector_Read(
  /* in */ bHYPRE_IJParCSRVector self,
  /* in */ const char* filename,
  /* in */ bHYPRE_MPICommunicator comm,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_Read)(
    self,
    filename,
    comm,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Set the MPI Communicator.  DEPRECATED, Use Create()
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_IJParCSRVector_SetCommunicator(
  /* in */ bHYPRE_IJParCSRVector self,
  /* in */ bHYPRE_MPICommunicator mpi_comm,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_SetCommunicator)(
    self,
    mpi_comm,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * The Destroy function doesn't necessarily destroy anything.
 * It is just another name for deleteRef.  Thus it decrements the
 * object's reference count.  The Babel memory management system will
 * destroy the object if the reference count goes to zero.
 */
SIDL_C_INLINE_DECL
void
bHYPRE_IJParCSRVector_Destroy(
  /* in */ bHYPRE_IJParCSRVector self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  (*self->d_epv->f_Destroy)(
    self,
    _ex);
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Prepare an object for setting coefficient values, whether for
 * the first time or subsequently.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_IJParCSRVector_Initialize(
  /* in */ bHYPRE_IJParCSRVector self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_Initialize)(
    self,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Finalize the construction of an object before using, either
 * for the first time or on subsequent uses. {\tt Initialize}
 * and {\tt Assemble} always appear in a matched set, with
 * Initialize preceding Assemble. Values can only be set in
 * between a call to Initialize and Assemble.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_IJParCSRVector_Assemble(
  /* in */ bHYPRE_IJParCSRVector self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_Assemble)(
    self,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Set {\tt self} to 0.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_IJParCSRVector_Clear(
  /* in */ bHYPRE_IJParCSRVector self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_Clear)(
    self,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Copy data from x into {\tt self}.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_IJParCSRVector_Copy(
  /* in */ bHYPRE_IJParCSRVector self,
  /* in */ bHYPRE_Vector x,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_Copy)(
    self,
    x,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Create an {\tt x} compatible with {\tt self}.
 * The new vector's data is not specified.
 * 
 * NOTE: When this method is used in an inherited class, the
 * cloned {\tt Vector} object can be cast to an object with the
 * inherited class type.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_IJParCSRVector_Clone(
  /* in */ bHYPRE_IJParCSRVector self,
  /* out */ bHYPRE_Vector* x,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_Clone)(
    self,
    x,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Scale {\tt self} by {\tt a}.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_IJParCSRVector_Scale(
  /* in */ bHYPRE_IJParCSRVector self,
  /* in */ double a,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_Scale)(
    self,
    a,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Compute {\tt d}, the inner-product of {\tt self} and {\tt x}.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_IJParCSRVector_Dot(
  /* in */ bHYPRE_IJParCSRVector self,
  /* in */ bHYPRE_Vector x,
  /* out */ double* d,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_Dot)(
    self,
    x,
    d,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Add {\tt a}{\tt x} to {\tt self}.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_IJParCSRVector_Axpy(
  /* in */ bHYPRE_IJParCSRVector self,
  /* in */ double a,
  /* in */ bHYPRE_Vector x,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_Axpy)(
    self,
    a,
    x,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Cast method for interface and class type conversions.
 */
struct bHYPRE_IJParCSRVector__object*
bHYPRE_IJParCSRVector__cast(
  void* obj,
  sidl_BaseInterface* _ex);

/**
 * String cast method for interface and class type conversions.
 */
void*
bHYPRE_IJParCSRVector__cast2(
  void* obj,
  const char* type,
  sidl_BaseInterface *_ex);

/**
 * Select and execute a method by name
 */
SIDL_C_INLINE_DECL
void
bHYPRE_IJParCSRVector__exec(
  /* in */ bHYPRE_IJParCSRVector self,
  /* in */ const char* methodName,
  /* in */ sidl_rmi_Call inArgs,
  /* in */ sidl_rmi_Return outArgs,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  (*self->d_epv->f__exec)(
    self,
    methodName,
    inArgs,
    outArgs,
    _ex);
}
#else
;
#endif /* SIDL_C_HAS_INLINE */

/**
 * Get the URL of the Implementation of this object (for RMI)
 */
SIDL_C_INLINE_DECL
char*
bHYPRE_IJParCSRVector__getURL(
  /* in */ bHYPRE_IJParCSRVector self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  char* _result;
  _result = (*self->d_epv->f__getURL)(
    self,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */

/**
 * On a remote object, addrefs the remote instance.
 */
SIDL_C_INLINE_DECL
void
bHYPRE_IJParCSRVector__raddRef(
  /* in */ bHYPRE_IJParCSRVector self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  (*self->d_epv->f__raddRef)(
    self,
    _ex);
}
#else
;
#endif /* SIDL_C_HAS_INLINE */

/**
 * TRUE if this object is remote, false if local
 */
SIDL_C_INLINE_DECL
sidl_bool
bHYPRE_IJParCSRVector__isRemote(
  /* in */ bHYPRE_IJParCSRVector self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  sidl_bool _result;
  _result = (*self->d_epv->f__isRemote)(
    self,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */

/**
 * TRUE if this object is remote, false if local
 */
sidl_bool
bHYPRE_IJParCSRVector__isLocal(
  /* in */ bHYPRE_IJParCSRVector self,
  /* out */ sidl_BaseInterface *_ex);
struct bHYPRE_IJParCSRVector__array*
bHYPRE_IJParCSRVector__array_createCol(
  int32_t       dimen,
  const int32_t lower[],
  const int32_t upper[]);

struct bHYPRE_IJParCSRVector__array*
bHYPRE_IJParCSRVector__array_createRow(
  int32_t       dimen,
  const int32_t lower[],
  const int32_t upper[]);

struct bHYPRE_IJParCSRVector__array*
bHYPRE_IJParCSRVector__array_create1d(int32_t len);

struct bHYPRE_IJParCSRVector__array*
bHYPRE_IJParCSRVector__array_create1dInit(
  int32_t len, 
  bHYPRE_IJParCSRVector* data);

struct bHYPRE_IJParCSRVector__array*
bHYPRE_IJParCSRVector__array_create2dCol(int32_t m, int32_t n);

struct bHYPRE_IJParCSRVector__array*
bHYPRE_IJParCSRVector__array_create2dRow(int32_t m, int32_t n);

struct bHYPRE_IJParCSRVector__array*
bHYPRE_IJParCSRVector__array_borrow(
  bHYPRE_IJParCSRVector* firstElement,
  int32_t       dimen,
  const int32_t lower[],
  const int32_t upper[],
  const int32_t stride[]);

struct bHYPRE_IJParCSRVector__array*
bHYPRE_IJParCSRVector__array_smartCopy(
  struct bHYPRE_IJParCSRVector__array *array);

void
bHYPRE_IJParCSRVector__array_addRef(
  struct bHYPRE_IJParCSRVector__array* array);

void
bHYPRE_IJParCSRVector__array_deleteRef(
  struct bHYPRE_IJParCSRVector__array* array);

bHYPRE_IJParCSRVector
bHYPRE_IJParCSRVector__array_get1(
  const struct bHYPRE_IJParCSRVector__array* array,
  const int32_t i1);

bHYPRE_IJParCSRVector
bHYPRE_IJParCSRVector__array_get2(
  const struct bHYPRE_IJParCSRVector__array* array,
  const int32_t i1,
  const int32_t i2);

bHYPRE_IJParCSRVector
bHYPRE_IJParCSRVector__array_get3(
  const struct bHYPRE_IJParCSRVector__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3);

bHYPRE_IJParCSRVector
bHYPRE_IJParCSRVector__array_get4(
  const struct bHYPRE_IJParCSRVector__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4);

bHYPRE_IJParCSRVector
bHYPRE_IJParCSRVector__array_get5(
  const struct bHYPRE_IJParCSRVector__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5);

bHYPRE_IJParCSRVector
bHYPRE_IJParCSRVector__array_get6(
  const struct bHYPRE_IJParCSRVector__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6);

bHYPRE_IJParCSRVector
bHYPRE_IJParCSRVector__array_get7(
  const struct bHYPRE_IJParCSRVector__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6,
  const int32_t i7);

bHYPRE_IJParCSRVector
bHYPRE_IJParCSRVector__array_get(
  const struct bHYPRE_IJParCSRVector__array* array,
  const int32_t indices[]);

void
bHYPRE_IJParCSRVector__array_set1(
  struct bHYPRE_IJParCSRVector__array* array,
  const int32_t i1,
  bHYPRE_IJParCSRVector const value);

void
bHYPRE_IJParCSRVector__array_set2(
  struct bHYPRE_IJParCSRVector__array* array,
  const int32_t i1,
  const int32_t i2,
  bHYPRE_IJParCSRVector const value);

void
bHYPRE_IJParCSRVector__array_set3(
  struct bHYPRE_IJParCSRVector__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  bHYPRE_IJParCSRVector const value);

void
bHYPRE_IJParCSRVector__array_set4(
  struct bHYPRE_IJParCSRVector__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  bHYPRE_IJParCSRVector const value);

void
bHYPRE_IJParCSRVector__array_set5(
  struct bHYPRE_IJParCSRVector__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  bHYPRE_IJParCSRVector const value);

void
bHYPRE_IJParCSRVector__array_set6(
  struct bHYPRE_IJParCSRVector__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6,
  bHYPRE_IJParCSRVector const value);

void
bHYPRE_IJParCSRVector__array_set7(
  struct bHYPRE_IJParCSRVector__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6,
  const int32_t i7,
  bHYPRE_IJParCSRVector const value);

void
bHYPRE_IJParCSRVector__array_set(
  struct bHYPRE_IJParCSRVector__array* array,
  const int32_t indices[],
  bHYPRE_IJParCSRVector const value);

int32_t
bHYPRE_IJParCSRVector__array_dimen(
  const struct bHYPRE_IJParCSRVector__array* array);

int32_t
bHYPRE_IJParCSRVector__array_lower(
  const struct bHYPRE_IJParCSRVector__array* array,
  const int32_t ind);

int32_t
bHYPRE_IJParCSRVector__array_upper(
  const struct bHYPRE_IJParCSRVector__array* array,
  const int32_t ind);

int32_t
bHYPRE_IJParCSRVector__array_length(
  const struct bHYPRE_IJParCSRVector__array* array,
  const int32_t ind);

int32_t
bHYPRE_IJParCSRVector__array_stride(
  const struct bHYPRE_IJParCSRVector__array* array,
  const int32_t ind);

int
bHYPRE_IJParCSRVector__array_isColumnOrder(
  const struct bHYPRE_IJParCSRVector__array* array);

int
bHYPRE_IJParCSRVector__array_isRowOrder(
  const struct bHYPRE_IJParCSRVector__array* array);

struct bHYPRE_IJParCSRVector__array*
bHYPRE_IJParCSRVector__array_slice(
  struct bHYPRE_IJParCSRVector__array* src,
  int32_t        dimen,
  const int32_t  numElem[],
  const int32_t  *srcStart,
  const int32_t  *srcStride,
  const int32_t  *newStart);

void
bHYPRE_IJParCSRVector__array_copy(
  const struct bHYPRE_IJParCSRVector__array* src,
  struct bHYPRE_IJParCSRVector__array* dest);

struct bHYPRE_IJParCSRVector__array*
bHYPRE_IJParCSRVector__array_ensure(
  struct bHYPRE_IJParCSRVector__array* src,
  int32_t dimen,
  int     ordering);


#pragma weak bHYPRE_IJParCSRVector__connectI

#pragma weak bHYPRE_IJParCSRVector__rmicast

/**
 * Cast method for interface and class type conversions.
 */
struct bHYPRE_IJParCSRVector__object*
bHYPRE_IJParCSRVector__rmicast(
  void* obj, struct sidl_BaseInterface__object **_ex);

/**
 * RMI connector function for the class. (no addref)
 */
struct bHYPRE_IJParCSRVector__object*
bHYPRE_IJParCSRVector__connectI(const char * url, sidl_bool ar, struct 
  sidl_BaseInterface__object **_ex);

#ifdef __cplusplus
}
#endif
#endif
