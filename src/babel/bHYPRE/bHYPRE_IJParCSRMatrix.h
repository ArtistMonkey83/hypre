/*
 * File:          bHYPRE_IJParCSRMatrix.h
 * Symbol:        bHYPRE.IJParCSRMatrix-v1.0.0
 * Symbol Type:   class
 * Babel Version: 1.0.4
 * Description:   Client-side glue code for bHYPRE.IJParCSRMatrix
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#ifndef included_bHYPRE_IJParCSRMatrix_h
#define included_bHYPRE_IJParCSRMatrix_h

/**
 * Symbol "bHYPRE.IJParCSRMatrix" (version 1.0.0)
 * 
 * The IJParCSR matrix class.
 * 
 * Objects of this type can be cast to IJMatrixView, Operator, or
 * CoefficientAccess objects using the {\tt \_\_cast} methods.
 */
struct bHYPRE_IJParCSRMatrix__object;
struct bHYPRE_IJParCSRMatrix__array;
typedef struct bHYPRE_IJParCSRMatrix__object* bHYPRE_IJParCSRMatrix;

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
#ifndef included_bHYPRE_IJParCSRMatrix_IOR_h
#include "bHYPRE_IJParCSRMatrix_IOR.h"
#endif
#endif /* SIDL_C_HAS_INLINE */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * Constructor function for the class.
 */
struct bHYPRE_IJParCSRMatrix__object*
bHYPRE_IJParCSRMatrix__create(sidl_BaseInterface* _ex);

/**
 * RMI constructor function for the class.
 */
bHYPRE_IJParCSRMatrix
bHYPRE_IJParCSRMatrix__createRemote(const char * url, sidl_BaseInterface *_ex);

/**
 * Wraps up the private data struct pointer (struct bHYPRE_IJParCSRMatrix__data) passed in rather than running the constructor.
 */
bHYPRE_IJParCSRMatrix
bHYPRE_IJParCSRMatrix__wrapObj(void * data, sidl_BaseInterface *_ex);

/**
 * RMI connector function for the class.(addrefs)
 */
bHYPRE_IJParCSRMatrix
bHYPRE_IJParCSRMatrix__connect(const char *, sidl_BaseInterface *_ex);

/**
 *  This function is the preferred way to create an IJParCSR Matrix. 
 */
bHYPRE_IJParCSRMatrix
bHYPRE_IJParCSRMatrix_Create(
  /* in */ bHYPRE_MPICommunicator mpi_comm,
  /* in */ int32_t ilower,
  /* in */ int32_t iupper,
  /* in */ int32_t jlower,
  /* in */ int32_t jupper,
  /* out */ sidl_BaseInterface *_ex);

/**
 * Method:  GenerateLaplacian[]
 */
bHYPRE_IJParCSRMatrix
bHYPRE_IJParCSRMatrix_GenerateLaplacian(
  /* in */ bHYPRE_MPICommunicator mpi_comm,
  /* in */ int32_t nx,
  /* in */ int32_t ny,
  /* in */ int32_t nz,
  /* in */ int32_t Px,
  /* in */ int32_t Py,
  /* in */ int32_t Pz,
  /* in */ int32_t p,
  /* in */ int32_t q,
  /* in */ int32_t r,
  /* in rarray[nvalues] */ double* values,
  /* in */ int32_t nvalues,
  /* in */ int32_t discretization,
  /* out */ sidl_BaseInterface *_ex);

/**
 * (Optional) Set the max number of nonzeros to expect in each
 * row of the diagonal and off-diagonal blocks.  The diagonal
 * block is the submatrix whose column numbers correspond to
 * rows owned by this process, and the off-diagonal block is
 * everything else.  The arrays {\tt diag\_sizes} and {\tt
 * offdiag\_sizes} contain estimated sizes for each row of the
 * diagonal and off-diagonal blocks, respectively.  This routine
 * can significantly improve the efficiency of matrix
 * construction, and should always be utilized if possible.
 * 
 * Not collective.
 */
int32_t
bHYPRE_IJParCSRMatrix_SetDiagOffdSizes(
  /* in */ bHYPRE_IJParCSRMatrix self,
  /* in rarray[local_nrows] */ int32_t* diag_sizes,
  /* in rarray[local_nrows] */ int32_t* offdiag_sizes,
  /* in */ int32_t local_nrows,
  /* out */ sidl_BaseInterface *_ex);

SIDL_C_INLINE_DECL
void
bHYPRE_IJParCSRMatrix_addRef(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix_deleteRef(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix_isSame(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix_isType(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix_getClassInfo(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
 * Set the local range for a matrix object.  Each process owns
 * some unique consecutive range of rows, indicated by the
 * global row indices {\tt ilower} and {\tt iupper}.  The row
 * data is required to be such that the value of {\tt ilower} on
 * any process $p$ be exactly one more than the value of {\tt
 * iupper} on process $p-1$.  Note that the first row of the
 * global matrix may start with any integer value.  In
 * particular, one may use zero- or one-based indexing.
 * 
 * For square matrices, {\tt jlower} and {\tt jupper} typically
 * should match {\tt ilower} and {\tt iupper}, respectively.
 * For rectangular matrices, {\tt jlower} and {\tt jupper}
 * should define a partitioning of the columns.  This
 * partitioning must be used for any vector $v$ that will be
 * used in matrix-vector products with the rectangular matrix.
 * The matrix data structure may use {\tt jlower} and {\tt
 * jupper} to store the diagonal blocks (rectangular in general)
 * of the matrix separately from the rest of the matrix.
 * 
 * Collective.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_IJParCSRMatrix_SetLocalRange(
  /* in */ bHYPRE_IJParCSRMatrix self,
  /* in */ int32_t ilower,
  /* in */ int32_t iupper,
  /* in */ int32_t jlower,
  /* in */ int32_t jupper,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_SetLocalRange)(
    self,
    ilower,
    iupper,
    jlower,
    jupper,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Sets values for {\tt nrows} of the matrix.  The arrays {\tt
 * ncols} and {\tt rows} are of dimension {\tt nrows} and
 * contain the number of columns in each row and the row
 * indices, respectively.  The array {\tt cols} contains the
 * column indices for each of the {\tt rows}, and is ordered by
 * rows.  The data in the {\tt values} array corresponds
 * directly to the column entries in {\tt cols}.  The last argument
 * is the size of the cols and values arrays, i.e. the total number
 * of nonzeros being provided, i.e. the sum of all values in ncols.
 * This functin erases any previous values at the specified locations and
 * replaces them with new ones, or, if there was no value there before,
 * inserts a new one.
 * 
 * Not collective.
 */
int32_t
bHYPRE_IJParCSRMatrix_SetValues(
  /* in */ bHYPRE_IJParCSRMatrix self,
  /* in */ int32_t nrows,
  /* in rarray[nrows] */ int32_t* ncols,
  /* in rarray[nrows] */ int32_t* rows,
  /* in rarray[nnonzeros] */ int32_t* cols,
  /* in rarray[nnonzeros] */ double* values,
  /* in */ int32_t nnonzeros,
  /* out */ sidl_BaseInterface *_ex);

/**
 * Adds to values for {\tt nrows} of the matrix.  Usage details
 * are analogous to {\tt SetValues}.  Adds to any previous
 * values at the specified locations, or, if there was no value
 * there before, inserts a new one.
 * 
 * Not collective.
 */
int32_t
bHYPRE_IJParCSRMatrix_AddToValues(
  /* in */ bHYPRE_IJParCSRMatrix self,
  /* in */ int32_t nrows,
  /* in rarray[nrows] */ int32_t* ncols,
  /* in rarray[nrows] */ int32_t* rows,
  /* in rarray[nnonzeros] */ int32_t* cols,
  /* in rarray[nnonzeros] */ double* values,
  /* in */ int32_t nnonzeros,
  /* out */ sidl_BaseInterface *_ex);

/**
 * Gets range of rows owned by this processor and range of
 * column partitioning for this processor.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_IJParCSRMatrix_GetLocalRange(
  /* in */ bHYPRE_IJParCSRMatrix self,
  /* out */ int32_t* ilower,
  /* out */ int32_t* iupper,
  /* out */ int32_t* jlower,
  /* out */ int32_t* jupper,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_GetLocalRange)(
    self,
    ilower,
    iupper,
    jlower,
    jupper,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Gets number of nonzeros elements for {\tt nrows} rows
 * specified in {\tt rows} and returns them in {\tt ncols},
 * which needs to be allocated by the user.
 */
int32_t
bHYPRE_IJParCSRMatrix_GetRowCounts(
  /* in */ bHYPRE_IJParCSRMatrix self,
  /* in */ int32_t nrows,
  /* in rarray[nrows] */ int32_t* rows,
  /* inout rarray[nrows] */ int32_t* ncols,
  /* out */ sidl_BaseInterface *_ex);

/**
 * Gets values for {\tt nrows} rows or partial rows of the
 * matrix.  Usage details are analogous to {\tt SetValues}.
 */
int32_t
bHYPRE_IJParCSRMatrix_GetValues(
  /* in */ bHYPRE_IJParCSRMatrix self,
  /* in */ int32_t nrows,
  /* in rarray[nrows] */ int32_t* ncols,
  /* in rarray[nrows] */ int32_t* rows,
  /* in rarray[nnonzeros] */ int32_t* cols,
  /* inout rarray[nnonzeros] */ double* values,
  /* in */ int32_t nnonzeros,
  /* out */ sidl_BaseInterface *_ex);

/**
 * (Optional) Set the max number of nonzeros to expect in each
 * row.  The array {\tt sizes} contains estimated sizes for each
 * row on this process.  The integer nrows is the number of rows in
 * the local matrix.  This call can significantly improve the
 * efficiency of matrix construction, and should always be
 * utilized if possible.
 * 
 * Not collective.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_IJParCSRMatrix_SetRowSizes(
  /* in */ bHYPRE_IJParCSRMatrix self,
  /* in rarray[nrows] */ int32_t* sizes,
  /* in */ int32_t nrows,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  int32_t sizes_lower[1], sizes_upper[1], sizes_stride[1]; 
  struct sidl_int__array sizes_real;
  struct sidl_int__array*sizes_tmp = &sizes_real;
  sizes_upper[0] = nrows-1;
  sidl_int__array_init(sizes, sizes_tmp, 1, sizes_lower, sizes_upper, 
    sizes_stride);
  _result = (*self->d_epv->f_SetRowSizes)(
    self,
    sizes_tmp,
    _ex);
#ifdef SIDL_DEBUG_REFCOUNT
  sidl__array_deleteRef((struct sidl__array*)sizes_tmp);
#endif /* SIDL_DEBUG_REFCOUNT */
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
bHYPRE_IJParCSRMatrix_Print(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
 * Read the matrix from file.  This is mainly for debugging
 * purposes.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_IJParCSRMatrix_Read(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix_SetCommunicator(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix_Destroy(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix_Initialize(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix_Assemble(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix_SetIntParameter(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix_SetDoubleParameter(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix_SetStringParameter(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix_SetIntArray1Parameter(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix_SetIntArray2Parameter(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix_SetDoubleArray1Parameter(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix_SetDoubleArray2Parameter(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix_GetIntValue(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix_GetDoubleValue(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix_Setup(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix_Apply(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix_ApplyAdjoint(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
 * The GetRow method will allocate space for its two output
 * arrays on the first call.  The space will be reused on
 * subsequent calls.  Thus the user must not delete them, yet
 * must not depend on the data from GetRow to persist beyond the
 * next GetRow call.
 */
SIDL_C_INLINE_DECL
int32_t
bHYPRE_IJParCSRMatrix_GetRow(
  /* in */ bHYPRE_IJParCSRMatrix self,
  /* in */ int32_t row,
  /* out */ int32_t* size,
  /* out array<int,column-major> */ struct sidl_int__array** col_ind,
  /* out array<double,column-major> */ struct sidl_double__array** values,
  /* out */ sidl_BaseInterface *_ex)
#ifdef SIDL_C_HAS_INLINE
{
  int32_t _result;
  _result = (*self->d_epv->f_GetRow)(
    self,
    row,
    size,
    col_ind,
    values,
    _ex);
  return _result;
}
#else
;
#endif /* SIDL_C_HAS_INLINE */


/**
 * Cast method for interface and class type conversions.
 */
struct bHYPRE_IJParCSRMatrix__object*
bHYPRE_IJParCSRMatrix__cast(
  void* obj,
  sidl_BaseInterface* _ex);

/**
 * String cast method for interface and class type conversions.
 */
void*
bHYPRE_IJParCSRMatrix__cast2(
  void* obj,
  const char* type,
  sidl_BaseInterface *_ex);

/**
 * Select and execute a method by name
 */
SIDL_C_INLINE_DECL
void
bHYPRE_IJParCSRMatrix__exec(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix__getURL(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix__raddRef(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix__isRemote(
  /* in */ bHYPRE_IJParCSRMatrix self,
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
bHYPRE_IJParCSRMatrix__isLocal(
  /* in */ bHYPRE_IJParCSRMatrix self,
  /* out */ sidl_BaseInterface *_ex);
struct bHYPRE_IJParCSRMatrix__array*
bHYPRE_IJParCSRMatrix__array_createCol(
  int32_t       dimen,
  const int32_t lower[],
  const int32_t upper[]);

struct bHYPRE_IJParCSRMatrix__array*
bHYPRE_IJParCSRMatrix__array_createRow(
  int32_t       dimen,
  const int32_t lower[],
  const int32_t upper[]);

struct bHYPRE_IJParCSRMatrix__array*
bHYPRE_IJParCSRMatrix__array_create1d(int32_t len);

struct bHYPRE_IJParCSRMatrix__array*
bHYPRE_IJParCSRMatrix__array_create1dInit(
  int32_t len, 
  bHYPRE_IJParCSRMatrix* data);

struct bHYPRE_IJParCSRMatrix__array*
bHYPRE_IJParCSRMatrix__array_create2dCol(int32_t m, int32_t n);

struct bHYPRE_IJParCSRMatrix__array*
bHYPRE_IJParCSRMatrix__array_create2dRow(int32_t m, int32_t n);

struct bHYPRE_IJParCSRMatrix__array*
bHYPRE_IJParCSRMatrix__array_borrow(
  bHYPRE_IJParCSRMatrix* firstElement,
  int32_t       dimen,
  const int32_t lower[],
  const int32_t upper[],
  const int32_t stride[]);

struct bHYPRE_IJParCSRMatrix__array*
bHYPRE_IJParCSRMatrix__array_smartCopy(
  struct bHYPRE_IJParCSRMatrix__array *array);

void
bHYPRE_IJParCSRMatrix__array_addRef(
  struct bHYPRE_IJParCSRMatrix__array* array);

void
bHYPRE_IJParCSRMatrix__array_deleteRef(
  struct bHYPRE_IJParCSRMatrix__array* array);

bHYPRE_IJParCSRMatrix
bHYPRE_IJParCSRMatrix__array_get1(
  const struct bHYPRE_IJParCSRMatrix__array* array,
  const int32_t i1);

bHYPRE_IJParCSRMatrix
bHYPRE_IJParCSRMatrix__array_get2(
  const struct bHYPRE_IJParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2);

bHYPRE_IJParCSRMatrix
bHYPRE_IJParCSRMatrix__array_get3(
  const struct bHYPRE_IJParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3);

bHYPRE_IJParCSRMatrix
bHYPRE_IJParCSRMatrix__array_get4(
  const struct bHYPRE_IJParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4);

bHYPRE_IJParCSRMatrix
bHYPRE_IJParCSRMatrix__array_get5(
  const struct bHYPRE_IJParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5);

bHYPRE_IJParCSRMatrix
bHYPRE_IJParCSRMatrix__array_get6(
  const struct bHYPRE_IJParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6);

bHYPRE_IJParCSRMatrix
bHYPRE_IJParCSRMatrix__array_get7(
  const struct bHYPRE_IJParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6,
  const int32_t i7);

bHYPRE_IJParCSRMatrix
bHYPRE_IJParCSRMatrix__array_get(
  const struct bHYPRE_IJParCSRMatrix__array* array,
  const int32_t indices[]);

void
bHYPRE_IJParCSRMatrix__array_set1(
  struct bHYPRE_IJParCSRMatrix__array* array,
  const int32_t i1,
  bHYPRE_IJParCSRMatrix const value);

void
bHYPRE_IJParCSRMatrix__array_set2(
  struct bHYPRE_IJParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2,
  bHYPRE_IJParCSRMatrix const value);

void
bHYPRE_IJParCSRMatrix__array_set3(
  struct bHYPRE_IJParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  bHYPRE_IJParCSRMatrix const value);

void
bHYPRE_IJParCSRMatrix__array_set4(
  struct bHYPRE_IJParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  bHYPRE_IJParCSRMatrix const value);

void
bHYPRE_IJParCSRMatrix__array_set5(
  struct bHYPRE_IJParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  bHYPRE_IJParCSRMatrix const value);

void
bHYPRE_IJParCSRMatrix__array_set6(
  struct bHYPRE_IJParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6,
  bHYPRE_IJParCSRMatrix const value);

void
bHYPRE_IJParCSRMatrix__array_set7(
  struct bHYPRE_IJParCSRMatrix__array* array,
  const int32_t i1,
  const int32_t i2,
  const int32_t i3,
  const int32_t i4,
  const int32_t i5,
  const int32_t i6,
  const int32_t i7,
  bHYPRE_IJParCSRMatrix const value);

void
bHYPRE_IJParCSRMatrix__array_set(
  struct bHYPRE_IJParCSRMatrix__array* array,
  const int32_t indices[],
  bHYPRE_IJParCSRMatrix const value);

int32_t
bHYPRE_IJParCSRMatrix__array_dimen(
  const struct bHYPRE_IJParCSRMatrix__array* array);

int32_t
bHYPRE_IJParCSRMatrix__array_lower(
  const struct bHYPRE_IJParCSRMatrix__array* array,
  const int32_t ind);

int32_t
bHYPRE_IJParCSRMatrix__array_upper(
  const struct bHYPRE_IJParCSRMatrix__array* array,
  const int32_t ind);

int32_t
bHYPRE_IJParCSRMatrix__array_length(
  const struct bHYPRE_IJParCSRMatrix__array* array,
  const int32_t ind);

int32_t
bHYPRE_IJParCSRMatrix__array_stride(
  const struct bHYPRE_IJParCSRMatrix__array* array,
  const int32_t ind);

int
bHYPRE_IJParCSRMatrix__array_isColumnOrder(
  const struct bHYPRE_IJParCSRMatrix__array* array);

int
bHYPRE_IJParCSRMatrix__array_isRowOrder(
  const struct bHYPRE_IJParCSRMatrix__array* array);

struct bHYPRE_IJParCSRMatrix__array*
bHYPRE_IJParCSRMatrix__array_slice(
  struct bHYPRE_IJParCSRMatrix__array* src,
  int32_t        dimen,
  const int32_t  numElem[],
  const int32_t  *srcStart,
  const int32_t  *srcStride,
  const int32_t  *newStart);

void
bHYPRE_IJParCSRMatrix__array_copy(
  const struct bHYPRE_IJParCSRMatrix__array* src,
  struct bHYPRE_IJParCSRMatrix__array* dest);

struct bHYPRE_IJParCSRMatrix__array*
bHYPRE_IJParCSRMatrix__array_ensure(
  struct bHYPRE_IJParCSRMatrix__array* src,
  int32_t dimen,
  int     ordering);


#pragma weak bHYPRE_IJParCSRMatrix__connectI

#pragma weak bHYPRE_IJParCSRMatrix__rmicast

/**
 * Cast method for interface and class type conversions.
 */
struct bHYPRE_IJParCSRMatrix__object*
bHYPRE_IJParCSRMatrix__rmicast(
  void* obj, struct sidl_BaseInterface__object **_ex);

/**
 * RMI connector function for the class. (no addref)
 */
struct bHYPRE_IJParCSRMatrix__object*
bHYPRE_IJParCSRMatrix__connectI(const char * url, sidl_bool ar, struct 
  sidl_BaseInterface__object **_ex);

#ifdef __cplusplus
}
#endif
#endif
