/*
 * File:          bHYPRE_SStructParCSRMatrix.h
 * Symbol:        bHYPRE.SStructParCSRMatrix-v1.0.0
 * Symbol Type:   class
 * Babel Version: 1.0.4
 * Description:   Client-side glue code for bHYPRE.SStructParCSRMatrix
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#ifndef included_bHYPRE_SStructParCSRMatrix_h
#define included_bHYPRE_SStructParCSRMatrix_h

/**
 * Symbol "bHYPRE.SStructParCSRMatrix" (version 1.0.0)
 * 
 * The SStructParCSR matrix class.
 * 
 * Objects of this type can be cast to SStructMatrixView or
 * Operator objects using the {\tt \_\_cast} methods.
 */
struct bHYPRE_SStructParCSRMatrix__object;
struct bHYPRE_SStructParCSRMatrix__array;
typedef struct bHYPRE_SStructParCSRMatrix__object* bHYPRE_SStructParCSRMatrix;

/*
 * Includes for all header dependencies.
 */

#ifndef included_sidl_header_h
#include "sidl_header.h"
#endif
#ifndef included_bHYPRE_MPICommunicator_h
#include "bHYPRE_MPICommunicator.h"
#endif
#ifndef included_bHYPRE_SStructGraph_h
#include "bHYPRE_SStructGraph.h"
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
#ifndef included_bHYPRE_SStructParCSRMatrix_IOR_h
#include "bHYPRE_SStructParCSRMatrix_IOR.h"
#endif
#endif /* SIDL_C_HAS_INLINE */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * Constructor function for the class.
 */
struct bHYPRE_SStructParCSRMatrix__object*
bHYPRE_SStructParCSRMatrix__create(sidl_BaseInterface* _ex);

/**
 * RMI constructor function for the class.
 */
bHYPRE_SStructParCSRMatrix
bHYPRE_SStructParCSRMatrix__createRemote(const char * url, sidl_BaseInterface 
  *_ex);

/**
 * Wraps up the private data struct pointer (struct bHYPRE\_SStructParCSRMatrix\_\_data) passed in rather than running the constructor.
 */
bHYPRE_SStructParCSRMatrix
bHYPRE_SStructParCSRMatrix__wrapObj(void * data, sidl_BaseInterface *_ex);

/**
 * RMI connector function for the class.(addrefs)
 */
bHYPRE_SStructParCSRMatrix
bHYPRE_SStructParCSRMatrix__connect(const char *, sidl_BaseInterface *_ex);

/**
 *  This function is the preferred way to create a SStruct ParCSR Matrix. 
 */
bHYPRE_SStructParCSRMatrix
bHYPRE_SStructParCSRMatrix_Create(
  /* in */ bHYPRE_MPICommunicator mpi_comm,
  /* in */ bHYPRE_SStructGraph graph,
  /* out */ sidl_BaseInterface *_ex);

SIDL_C_INLINE_DECL
void
bHYPRE_SStructParCSRMatrix_addRef(
  /* in */ bHYPRE_SStructParCSRMatrix self,
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
bHYPRE_SStructParCSRMatrix_deleteRef(
  /* in */ bHYPRE_SStructParCSRMatrix self,
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
bHYPRE_SStructParCSRMatrix_isSame(
  /* in */ bHYPRE_SStructParCSRMatrix self,
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
bHYPRE_SStructParCSRMatrix_isType(
  /* in */ bHYPRE_SStructParCSRMatrix self,
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
bHYPRE_SStructParCSRMatrix_getClassInfo(
  /* in */ bHYPRE_SStructParCSRMatrix self,
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
 * Set the matrix graph.
 * DEPRECATED     Use Create
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_SStructParCSRMatrix_SetGraph(
  /* in */ bHYPRE_SStructParCSRMatrix self,
  /* in */ bHYPRE_SStructGraph graph,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_SetGraph)(
    self,
    graph,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Set matrix coefficients index by index.
 * 
 * NOTE: Users are required to set values on all processes that
 * own the associated variables.  This means that some data will
 * be multiply defined.
 * 
 * NOTE: The entries in this routine must all be of the same
 * type: either stencil or non-stencil, but not both.  Also, if
 * they are stencil entries, they must all represent couplings
 * to the same variable type (there are no such restrictions for
 * non-stencil entries).
 * 
 * If the matrix is complex, then {\tt values} consists of pairs
 * of doubles representing the real and imaginary parts of each
 * complex value.
 */
int32_t
bHYPRE_SStructParCSRMatrix_SetValues(
  /* in */ bHYPRE_SStructParCSRMatrix self,
  /* in */ int32_t part,
  /* in rarray[dim] */ int32_t* index,
  /* in */ int32_t dim,
  /* in */ int32_t var,
  /* in */ int32_t nentries,
  /* in rarray[nentries] */ int32_t* entries,
  /* in rarray[nentries] */ double* values,
  /* out */ sidl_BaseInterface *_ex);

/**
 * Set matrix coefficients a box at a time.
 * 
 * NOTE: Users are required to set values on all processes that
 * own the associated variables.  This means that some data will
 * be multiply defined.
 * 
 * NOTE: The entries in this routine must all be of the same
 * type: either stencil or non-stencil, but not both.  Also, if
 * they are stencil entries, they must all represent couplings
 * to the same variable type (there are no such restrictions for
 * non-stencil entries).
 * 
 * If the matrix is complex, then {\tt values} consists of pairs
 * of doubles representing the real and imaginary parts of each
 * complex value.
 */
int32_t
bHYPRE_SStructParCSRMatrix_SetBoxValues(
  /* in */ bHYPRE_SStructParCSRMatrix self,
  /* in */ int32_t part,
  /* in rarray[dim] */ int32_t* ilower,
  /* in rarray[dim] */ int32_t* iupper,
  /* in */ int32_t dim,
  /* in */ int32_t var,
  /* in */ int32_t nentries,
  /* in rarray[nentries] */ int32_t* entries,
  /* in rarray[nvalues] */ double* values,
  /* in */ int32_t nvalues,
  /* out */ sidl_BaseInterface *_ex);

/**
 * Add to matrix coefficients index by index.
 * 
 * NOTE: Users are required to set values on all processes that
 * own the associated variables.  This means that some data will
 * be multiply defined.
 * 
 * NOTE: The entries in this routine must all be of the same
 * type: either stencil or non-stencil, but not both.  Also, if
 * they are stencil entries, they must all represent couplings
 * to the same variable type.
 * 
 * If the matrix is complex, then {\tt values} consists of pairs
 * of doubles representing the real and imaginary parts of each
 * complex value.
 */
int32_t
bHYPRE_SStructParCSRMatrix_AddToValues(
  /* in */ bHYPRE_SStructParCSRMatrix self,
  /* in */ int32_t part,
  /* in rarray[dim] */ int32_t* index,
  /* in */ int32_t dim,
  /* in */ int32_t var,
  /* in */ int32_t nentries,
  /* in rarray[nentries] */ int32_t* entries,
  /* in rarray[nentries] */ double* values,
  /* out */ sidl_BaseInterface *_ex);

/**
 * Add to matrix coefficients a box at a time.
 * 
 * NOTE: Users are required to set values on all processes that
 * own the associated variables.  This means that some data will
 * be multiply defined.
 * 
 * NOTE: The entries in this routine must all be of stencil
 * type.  Also, they must all represent couplings to the same
 * variable type.
 * 
 * If the matrix is complex, then {\tt values} consists of pairs
 * of doubles representing the real and imaginary parts of each
 * complex value.
 */
int32_t
bHYPRE_SStructParCSRMatrix_AddToBoxValues(
  /* in */ bHYPRE_SStructParCSRMatrix self,
  /* in */ int32_t part,
  /* in rarray[dim] */ int32_t* ilower,
  /* in rarray[dim] */ int32_t* iupper,
  /* in */ int32_t dim,
  /* in */ int32_t var,
  /* in */ int32_t nentries,
  /* in rarray[nentries] */ int32_t* entries,
  /* in rarray[nvalues] */ double* values,
  /* in */ int32_t nvalues,
  /* out */ sidl_BaseInterface *_ex);

/**
 * Define symmetry properties for the stencil entries in the
 * matrix.  The boolean argument {\tt symmetric} is applied to
 * stencil entries on part {\tt part} that couple variable {\tt
 * var} to variable {\tt to\_var}.  A value of -1 may be used
 * for {\tt part}, {\tt var}, or {\tt to\_var} to specify
 * ``all''.  For example, if {\tt part} and {\tt to\_var} are
 * set to -1, then the boolean is applied to stencil entries on
 * all parts that couple variable {\tt var} to all other
 * variables.
 * 
 * By default, matrices are assumed to be nonsymmetric.
 * Significant storage savings can be made if the matrix is
 * symmetric.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_SStructParCSRMatrix_SetSymmetric(
  /* in */ bHYPRE_SStructParCSRMatrix self,
  /* in */ int32_t part,
  /* in */ int32_t var,
  /* in */ int32_t to_var,
  /* in */ int32_t symmetric,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_SetSymmetric)(
    self,
    part,
    var,
    to_var,
    symmetric,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Define symmetry properties for all non-stencil matrix
 * entries.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_SStructParCSRMatrix_SetNSSymmetric(
  /* in */ bHYPRE_SStructParCSRMatrix self,
  /* in */ int32_t symmetric,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_SetNSSymmetric)(
    self,
    symmetric,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Set the matrix to be complex.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_SStructParCSRMatrix_SetComplex(
  /* in */ bHYPRE_SStructParCSRMatrix self,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_SetComplex)(
    self,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Print the matrix to file.  This is mainly for debugging
 * purposes.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_SStructParCSRMatrix_Print(
  /* in */ bHYPRE_SStructParCSRMatrix self,
  /* in */ const char* filename,
  /* in */ int32_t all,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_Print)(
    self,
    filename,
    all,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * A semi-structured matrix or vector contains a Struct or IJ matrix
 * or vector.  GetObject returns it.
 * The returned type is a sidl.BaseInterface.
 * A cast must be used on the returned object to convert it into a known type.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_SStructParCSRMatrix_GetObject(
  /* in */ bHYPRE_SStructParCSRMatrix self,
  /* out */ sidl_BaseInterface* A,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_GetObject)(
    self,
    A,
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
bHYPRE_SStructParCSRMatrix_SetCommunicator(
  /* in */ bHYPRE_SStructParCSRMatrix self,
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
bHYPRE_SStructParCSRMatrix_Destroy(
  /* in */ bHYPRE_SStructParCSRMatrix self,
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
bHYPRE_SStructParCSRMatrix_Initialize(
  /* in */ bHYPRE_SStructParCSRMatrix self,
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
bHYPRE_SStructParCSRMatrix_Assemble(
  /* in */ bHYPRE_SStructParCSRMatrix self,
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
 * Set the int parameter associated with {\tt name}.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_SStructParCSRMatrix_SetIntParameter(
  /* in */ bHYPRE_SStructParCSRMatrix self,
  /* in */ const char* name,
  /* in */ int32_t value,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_SetIntParameter)(
    self,
    name,
    value,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Set the double parameter associated with {\tt name}.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_SStructParCSRMatrix_SetDoubleParameter(
  /* in */ bHYPRE_SStructParCSRMatrix self,
  /* in */ const char* name,
  /* in */ double value,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_SetDoubleParameter)(
    self,
    name,
    value,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Set the string parameter associated with {\tt name}.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_SStructParCSRMatrix_SetStringParameter(
  /* in */ bHYPRE_SStructParCSRMatrix self,
  /* in */ const char* name,
  /* in */ const char* value,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_SetStringParameter)(
    self,
    name,
    value,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Set the int 1-D array parameter associated with {\tt name}.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_SStructParCSRMatrix_SetIntArray1Parameter(
  /* in */ bHYPRE_SStructParCSRMatrix self,
  /* in */ const char* name,
  /* in rarray[nvalues] */ int32_t* value,
  /* in */ int32_t nvalues,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  int32_t value_lower[1], value_upper[1], value_stride[1]; 
  struct sidl_int__array value_real;
  struct sidl_int__array*value_tmp = &value_real;
  value_upper[0] = nvalues-1;
  sidl_int__array_init(value, value_tmp, 1, value_lower, value_upper, 
    value_stride);
  _result = (*self->d_epv->f_SetIntArray1Parameter)(
    self,
    name,
    value_tmp,
    _ex);
#ifdef SIDL_DEBUG_REFCOUNT
  sidl__array_deleteRef((struct sidl__array*)value_tmp);
#endif /* SIDL_DEBUG_REFCOUNT */
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Set the int 2-D array parameter associated with {\tt name}.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_SStructParCSRMatrix_SetIntArray2Parameter(
  /* in */ bHYPRE_SStructParCSRMatrix self,
  /* in */ const char* name,
  /* in array<int,2,column-major> */ struct sidl_int__array* value,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_SetIntArray2Parameter)(
    self,
    name,
    value,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Set the double 1-D array parameter associated with {\tt name}.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_SStructParCSRMatrix_SetDoubleArray1Parameter(
  /* in */ bHYPRE_SStructParCSRMatrix self,
  /* in */ const char* name,
  /* in rarray[nvalues] */ double* value,
  /* in */ int32_t nvalues,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  int32_t value_lower[1], value_upper[1], value_stride[1]; 
  struct sidl_double__array value_real;
  struct sidl_double__array*value_tmp = &value_real;
  value_upper[0] = nvalues-1;
  sidl_double__array_init(value, value_tmp, 1, value_lower, value_upper, 
    value_stride);
  _result = (*self->d_epv->f_SetDoubleArray1Parameter)(
    self,
    name,
    value_tmp,
    _ex);
#ifdef SIDL_DEBUG_REFCOUNT
  sidl__array_deleteRef((struct sidl__array*)value_tmp);
#endif /* SIDL_DEBUG_REFCOUNT */
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Set the double 2-D array parameter associated with {\tt name}.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_SStructParCSRMatrix_SetDoubleArray2Parameter(
  /* in */ bHYPRE_SStructParCSRMatrix self,
  /* in */ const char* name,
  /* in array<double,2,column-major> */ struct sidl_double__array* value,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_SetDoubleArray2Parameter)(
    self,
    name,
    value,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Set the int parameter associated with {\tt name}.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_SStructParCSRMatrix_GetIntValue(
  /* in */ bHYPRE_SStructParCSRMatrix self,
  /* in */ const char* name,
  /* out */ int32_t* value,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_GetIntValue)(
    self,
    name,
    value,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Get the double parameter associated with {\tt name}.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_SStructParCSRMatrix_GetDoubleValue(
  /* in */ bHYPRE_SStructParCSRMatrix self,
  /* in */ const char* name,
  /* out */ double* value,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_GetDoubleValue)(
    self,
    name,
    value,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * (Optional) Do any preprocessing that may be necessary in
 * order to execute {\tt Apply}.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_SStructParCSRMatrix_Setup(
  /* in */ bHYPRE_SStructParCSRMatrix self,
  /* in */ bHYPRE_Vector b,
  /* in */ bHYPRE_Vector x,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_Setup)(
    self,
    b,
    x,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Apply the operator to {\tt b}, returning {\tt x}.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_SStructParCSRMatrix_Apply(
  /* in */ bHYPRE_SStructParCSRMatrix self,
  /* in */ bHYPRE_Vector b,
  /* inout */ bHYPRE_Vector* x,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_Apply)(
    self,
    b,
    x,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Apply the adjoint of the operator to {\tt b}, returning {\tt x}.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_SStructParCSRMatrix_ApplyAdjoint(
  /* in */ bHYPRE_SStructParCSRMatrix self,
  /* in */ bHYPRE_Vector b,
  /* inout */ bHYPRE_Vector* x,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_ApplyAdjoint)(
    self,
    b,
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
struct bHYPRE_SStructParCSRMatrix__object*
bHYPRE_SStructParCSRMatrix__cast(
  void* obj,
  sidl_BaseInterface* _ex);

/**
 * String cast method for interface and class type conversions.
 */
void*
bHYPRE_SStructParCSRMatrix__cast2(
  void* obj,
  const char* type,
  sidl_BaseInterface *_ex);

/**
 * Select and execute a method by name
 */
SIDL_C_INLINE_DECL
void
bHYPRE_SStructParCSRMatrix__exec(
  /* in */ bHYPRE_SStructParCSRMatrix self,
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
bHYPRE_SStructParCSRMatrix__getURL(
  /* in */ bHYPRE_SStructParCSRMatrix self,
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
bHYPRE_SStructParCSRMatrix__raddRef(
  /* in */ bHYPRE_SStructParCSRMatrix self,
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
bHYPRE_SStructParCSRMatrix__isRemote(
  /* in */ bHYPRE_SStructParCSRMatrix self,
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
bHYPRE_SStructParCSRMatrix__isLocal(
  /* in */ bHYPRE_SStructParCSRMatrix self,
  /* out */ sidl_BaseInterface *_ex);
struct bHYPRE_SStructParCSRMatrix__array*
bHYPRE_SStructParCSRMatrix__array_createCol(
  int32_t       dimen,
  const int32_t lower[],
  const int32_t upper[]);

struct bHYPRE_SStructParCSRMatrix__array*
bHYPRE_SStructParCSRMatrix__array_createRow(
  int32_t       dimen,
  const int32_t lower[],
  const int32_t upper[]);

struct bHYPRE_SStructParCSRMatrix__array*
bHYPRE_SStructParCSRMatrix__array_create1d(int32_t len);

struct bHYPRE_SStructParCSRMatrix__array*
bHYPRE_SStructParCSRMatrix__array_create1dInit(
  int32_t len, 
  bHYPRE_SStructParCSRMatrix* data);

struct bHYPRE_SStructParCSRMatrix__array*
bHYPRE_SStructParCSRMatrix__array_create2dCol(int32_t m, int32_t n);

struct bHYPRE_SStructParCSRMatrix__array*
bHYPRE_SStructParCSRMatrix__array_create2dRow(int32_t m, int32_t n);

struct bHYPRE_SStructParCSRMatrix__array*
bHYPRE_SStructParCSRMatrix__array_borrow(
  bHYPRE_SStructParCSRMatrix* firstElement,
  int32_t       dimen,
  const int32_t lower[],
  const int32_t upper[],
  const int32_t stride[]);

struct bHYPRE_SStructParCSRMatrix__array*
bHYPRE_SStructParCSRMatrix__array_smartCopy(
  struct bHYPRE_SStructParCSRMatrix__array *array);

void
bHYPRE_SStructParCSRMatrix__array_addRef(
  struct bHYPRE_SStructParCSRMatrix__array* array);

void
bHYPRE_SStructParCSRMatrix__array_deleteRef(
  struct bHYPRE_SStructParCSRMatrix__array* array);

bHYPRE_SStructParCSRMatrix
bHYPRE_SStructParCSRMatrix__array_get1(
  const struct bHYPRE_SStructParCSRMatrix__array* array,
  const int32_t i1);

bHYPRE_SStructParCSRMatrix
bHYPRE_SStructParCSRMatrix__array_get2(
  const struct bHYPRE_SStructParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2);

bHYPRE_SStructParCSRMatrix
bHYPRE_SStructParCSRMatrix__array_get3(
  const struct bHYPRE_SStructParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3);

bHYPRE_SStructParCSRMatrix
bHYPRE_SStructParCSRMatrix__array_get4(
  const struct bHYPRE_SStructParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4);

bHYPRE_SStructParCSRMatrix
bHYPRE_SStructParCSRMatrix__array_get5(
  const struct bHYPRE_SStructParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5);

bHYPRE_SStructParCSRMatrix
bHYPRE_SStructParCSRMatrix__array_get6(
  const struct bHYPRE_SStructParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6);

bHYPRE_SStructParCSRMatrix
bHYPRE_SStructParCSRMatrix__array_get7(
  const struct bHYPRE_SStructParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6,
  const int32_t i7);

bHYPRE_SStructParCSRMatrix
bHYPRE_SStructParCSRMatrix__array_get(
  const struct bHYPRE_SStructParCSRMatrix__array* array,
  const int32_t indices[]);

void
bHYPRE_SStructParCSRMatrix__array_set1(
  struct bHYPRE_SStructParCSRMatrix__array* array,
  const int32_t i1,
  bHYPRE_SStructParCSRMatrix const value);

void
bHYPRE_SStructParCSRMatrix__array_set2(
  struct bHYPRE_SStructParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2,
  bHYPRE_SStructParCSRMatrix const value);

void
bHYPRE_SStructParCSRMatrix__array_set3(
  struct bHYPRE_SStructParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  bHYPRE_SStructParCSRMatrix const value);

void
bHYPRE_SStructParCSRMatrix__array_set4(
  struct bHYPRE_SStructParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  bHYPRE_SStructParCSRMatrix const value);

void
bHYPRE_SStructParCSRMatrix__array_set5(
  struct bHYPRE_SStructParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  bHYPRE_SStructParCSRMatrix const value);

void
bHYPRE_SStructParCSRMatrix__array_set6(
  struct bHYPRE_SStructParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6,
  bHYPRE_SStructParCSRMatrix const value);

void
bHYPRE_SStructParCSRMatrix__array_set7(
  struct bHYPRE_SStructParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6,
  const int32_t i7,
  bHYPRE_SStructParCSRMatrix const value);

void
bHYPRE_SStructParCSRMatrix__array_set(
  struct bHYPRE_SStructParCSRMatrix__array* array,
  const int32_t indices[],
  bHYPRE_SStructParCSRMatrix const value);

int32_t
bHYPRE_SStructParCSRMatrix__array_dimen(
  const struct bHYPRE_SStructParCSRMatrix__array* array);

int32_t
bHYPRE_SStructParCSRMatrix__array_lower(
  const struct bHYPRE_SStructParCSRMatrix__array* array,
  const int32_t ind);

int32_t
bHYPRE_SStructParCSRMatrix__array_upper(
  const struct bHYPRE_SStructParCSRMatrix__array* array,
  const int32_t ind);

int32_t
bHYPRE_SStructParCSRMatrix__array_length(
  const struct bHYPRE_SStructParCSRMatrix__array* array,
  const int32_t ind);

int32_t
bHYPRE_SStructParCSRMatrix__array_stride(
  const struct bHYPRE_SStructParCSRMatrix__array* array,
  const int32_t ind);

int
bHYPRE_SStructParCSRMatrix__array_isColumnOrder(
  const struct bHYPRE_SStructParCSRMatrix__array* array);

int
bHYPRE_SStructParCSRMatrix__array_isRowOrder(
  const struct bHYPRE_SStructParCSRMatrix__array* array);

struct bHYPRE_SStructParCSRMatrix__array*
bHYPRE_SStructParCSRMatrix__array_slice(
  struct bHYPRE_SStructParCSRMatrix__array* src,
  int32_t        dimen,
  const int32_t  numElem[],
  const int32_t  *srcStart,
  const int32_t  *srcStride,
  const int32_t  *newStart);

void
bHYPRE_SStructParCSRMatrix__array_copy(
  const struct bHYPRE_SStructParCSRMatrix__array* src,
  struct bHYPRE_SStructParCSRMatrix__array* dest);

struct bHYPRE_SStructParCSRMatrix__array*
bHYPRE_SStructParCSRMatrix__array_ensure(
  struct bHYPRE_SStructParCSRMatrix__array* src,
  int32_t dimen,
  int     ordering);


#pragma weak bHYPRE_SStructParCSRMatrix__connectI

#pragma weak bHYPRE_SStructParCSRMatrix__rmicast

/**
 * Cast method for interface and class type conversions.
 */
struct bHYPRE_SStructParCSRMatrix__object*
bHYPRE_SStructParCSRMatrix__rmicast(
  void* obj, struct sidl_BaseInterface__object **_ex);

/**
 * RMI connector function for the class. (no addref)
 */
struct bHYPRE_SStructParCSRMatrix__object*
bHYPRE_SStructParCSRMatrix__connectI(const char * url, sidl_bool ar, struct 
  sidl_BaseInterface__object **_ex);

#ifdef __cplusplus
}
#endif
#endif
