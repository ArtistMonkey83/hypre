/*
 * File:          bHYPRE_SStructParCSRMatrix_fStub.c
 * Symbol:        bHYPRE.SStructParCSRMatrix-v1.0.0
 * Symbol Type:   class
 * Babel Version: 0.8.2
 * SIDL Created:  20030401 14:47:46 PST
 * Generated:     20030401 14:48:06 PST
 * Description:   Client-side glue code for bHYPRE.SStructParCSRMatrix
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 * babel-version = 0.8.2
 * source-line   = 827
 * source-url    = file:/home/painter/linear_solvers/babel/Interfaces.idl
 */

/*
 * Symbol "bHYPRE.SStructParCSRMatrix" (version 1.0.0)
 * 
 * The SStructParCSR matrix class.
 * 
 * Objects of this type can be cast to SStructBuildMatrix or
 * Operator objects using the {\tt \_\_cast} methods.
 * 
 */

#include <stddef.h>
#include <stdlib.h>
#include "SIDLfortran.h"
#include "SIDL_header.h"
#ifndef included_SIDL_interface_IOR_h
#include "SIDL_interface_IOR.h"
#endif
#include "babel_config.h"
#ifdef SIDL_DYNAMIC_LIBRARY
#include <stdio.h>
#include "SIDL_Loader.h"
#endif
#include "bHYPRE_SStructParCSRMatrix_IOR.h"
#include "SIDL_BaseInterface_IOR.h"
#include "SIDL_ClassInfo_IOR.h"
#include "bHYPRE_SStructGraph_IOR.h"
#include "bHYPRE_Vector_IOR.h"

/*
 * Return pointer to internal IOR functions.
 */

static const struct bHYPRE_SStructParCSRMatrix__external* _getIOR(void)
{
  static const struct bHYPRE_SStructParCSRMatrix__external *_ior = NULL;
  if (!_ior) {
#ifdef SIDL_STATIC_LIBRARY
    _ior = bHYPRE_SStructParCSRMatrix__externals();
#else
    const struct bHYPRE_SStructParCSRMatrix__external*(*dll_f)(void) =
      (const struct bHYPRE_SStructParCSRMatrix__external*(*)(void)) 
        SIDL_Loader_lookupSymbol(
        "bHYPRE_SStructParCSRMatrix__externals");
    _ior = (dll_f ? (*dll_f)() : NULL);
    if (!_ior) {
      fputs("Unable to find the implementation for bHYPRE.SStructParCSRMatrix; please set SIDL_DLL_PATH\n", stderr);
      exit(-1);
    }
#endif
  }
  return _ior;
}

/*
 * Constructor for the class.
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__create_f,BHYPRE_SSTRUCTPARCSRMATRIX__CREATE_F,bHYPRE_SStructParCSRMatrix__create_f)
(
  int64_t *self
)
{
  *self = (ptrdiff_t) (*(_getIOR()->createObject))();
}

/*
 * Cast method for interface and type conversions.
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__cast_f,BHYPRE_SSTRUCTPARCSRMATRIX__CAST_F,bHYPRE_SStructParCSRMatrix__cast_f)
(
  int64_t *ref,
  int64_t *retval
)
{
  struct SIDL_BaseInterface__object  *_base =
    (struct SIDL_BaseInterface__object *)(ptrdiff_t)*ref;
  if (_base) {
    *retval = (ptrdiff_t)(
      *_base->d_epv->f__cast)(
      _base->d_object,
      "bHYPRE.SStructParCSRMatrix");
  }
  else {
    *retval = 0;
  }
}

/*
 * Cast method for interface and class type conversions.
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__cast2_f,BHYPRE_SSTRUCTPARCSRMATRIX__CAST2_F,bHYPRE_SStructParCSRMatrix__cast2_f)
(
  int64_t *self,
  SIDL_F77_String name
  SIDL_F77_STR_NEAR_LEN_DECL(name),
  int64_t *retval
  SIDL_F77_STR_FAR_LEN_DECL(name)
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  char* _proxy_name = NULL;
  void* _proxy_retval = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _proxy_name =
    SIDL_copy_fortran_str(SIDL_F77_STR(name),
      SIDL_F77_STR_LEN(name));
  _epv = _proxy_self->d_epv;
  _proxy_retval = 
    (*(_epv->f__cast))(
      _proxy_self,
      _proxy_name
    );
  *retval = (ptrdiff_t)_proxy_retval;
  free((void *)_proxy_name);
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
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_addref_f,BHYPRE_SSTRUCTPARCSRMATRIX_ADDREF_F,bHYPRE_SStructParCSRMatrix_addRef_f)
(
  int64_t *self
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _epv = _proxy_self->d_epv;
  (*(_epv->f_addRef))(
    _proxy_self
  );
}

/*
 * Decrease by one the intrinsic reference count in the underlying
 * object, and delete the object if the reference is non-positive.
 * Objects in <code>SIDL</code> have an intrinsic reference count.
 * Clients should call this method whenever they remove a
 * reference to an object or interface.
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_deleteref_f,BHYPRE_SSTRUCTPARCSRMATRIX_DELETEREF_F,bHYPRE_SStructParCSRMatrix_deleteRef_f)
(
  int64_t *self
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _epv = _proxy_self->d_epv;
  (*(_epv->f_deleteRef))(
    _proxy_self
  );
}

/*
 * Return true if and only if <code>obj</code> refers to the same
 * object as this object.
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_issame_f,BHYPRE_SSTRUCTPARCSRMATRIX_ISSAME_F,bHYPRE_SStructParCSRMatrix_isSame_f)
(
  int64_t *self,
  int64_t *iobj,
  SIDL_F77_Bool *retval
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  struct SIDL_BaseInterface__object* _proxy_iobj = NULL;
  SIDL_bool _proxy_retval;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _proxy_iobj =
    (struct SIDL_BaseInterface__object*)
    (ptrdiff_t)(*iobj);
  _epv = _proxy_self->d_epv;
  _proxy_retval = 
    (*(_epv->f_isSame))(
      _proxy_self,
      _proxy_iobj
    );
  *retval = ((_proxy_retval == TRUE) ? SIDL_F77_TRUE : SIDL_F77_FALSE);
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

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_queryint_f,BHYPRE_SSTRUCTPARCSRMATRIX_QUERYINT_F,bHYPRE_SStructParCSRMatrix_queryInt_f)
(
  int64_t *self,
  SIDL_F77_String name
  SIDL_F77_STR_NEAR_LEN_DECL(name),
  int64_t *retval
  SIDL_F77_STR_FAR_LEN_DECL(name)
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  char* _proxy_name = NULL;
  struct SIDL_BaseInterface__object* _proxy_retval = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _proxy_name =
    SIDL_copy_fortran_str(SIDL_F77_STR(name),
      SIDL_F77_STR_LEN(name));
  _epv = _proxy_self->d_epv;
  _proxy_retval = 
    (*(_epv->f_queryInt))(
      _proxy_self,
      _proxy_name
    );
  *retval = (ptrdiff_t)_proxy_retval;
  free((void *)_proxy_name);
}

/*
 * Return whether this object is an instance of the specified type.
 * The string name must be the <code>SIDL</code> type name.  This
 * routine will return <code>true</code> if and only if a cast to
 * the string type name would succeed.
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_istype_f,BHYPRE_SSTRUCTPARCSRMATRIX_ISTYPE_F,bHYPRE_SStructParCSRMatrix_isType_f)
(
  int64_t *self,
  SIDL_F77_String name
  SIDL_F77_STR_NEAR_LEN_DECL(name),
  SIDL_F77_Bool *retval
  SIDL_F77_STR_FAR_LEN_DECL(name)
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  char* _proxy_name = NULL;
  SIDL_bool _proxy_retval;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _proxy_name =
    SIDL_copy_fortran_str(SIDL_F77_STR(name),
      SIDL_F77_STR_LEN(name));
  _epv = _proxy_self->d_epv;
  _proxy_retval = 
    (*(_epv->f_isType))(
      _proxy_self,
      _proxy_name
    );
  *retval = ((_proxy_retval == TRUE) ? SIDL_F77_TRUE : SIDL_F77_FALSE);
  free((void *)_proxy_name);
}

/*
 * Return the meta-data about the class implementing this interface.
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_getclassinfo_f,BHYPRE_SSTRUCTPARCSRMATRIX_GETCLASSINFO_F,bHYPRE_SStructParCSRMatrix_getClassInfo_f)
(
  int64_t *self,
  int64_t *retval
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  struct SIDL_ClassInfo__object* _proxy_retval = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _epv = _proxy_self->d_epv;
  _proxy_retval = 
    (*(_epv->f_getClassInfo))(
      _proxy_self
    );
  *retval = (ptrdiff_t)_proxy_retval;
}

/*
 * Set the MPI Communicator.
 * 
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_setcommunicator_f,BHYPRE_SSTRUCTPARCSRMATRIX_SETCOMMUNICATOR_F,bHYPRE_SStructParCSRMatrix_SetCommunicator_f)
(
  int64_t *self,
  int64_t *mpi_comm,
  int32_t *retval
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  void* _proxy_mpi_comm = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _proxy_mpi_comm =
    (void*)
    (ptrdiff_t)(*mpi_comm);
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_SetCommunicator))(
      _proxy_self,
      _proxy_mpi_comm
    );
}

/*
 * Prepare an object for setting coefficient values, whether for
 * the first time or subsequently.
 * 
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_initialize_f,BHYPRE_SSTRUCTPARCSRMATRIX_INITIALIZE_F,bHYPRE_SStructParCSRMatrix_Initialize_f)
(
  int64_t *self,
  int32_t *retval
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_Initialize))(
      _proxy_self
    );
}

/*
 * Finalize the construction of an object before using, either
 * for the first time or on subsequent uses. {\tt Initialize}
 * and {\tt Assemble} always appear in a matched set, with
 * Initialize preceding Assemble. Values can only be set in
 * between a call to Initialize and Assemble.
 * 
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_assemble_f,BHYPRE_SSTRUCTPARCSRMATRIX_ASSEMBLE_F,bHYPRE_SStructParCSRMatrix_Assemble_f)
(
  int64_t *self,
  int32_t *retval
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_Assemble))(
      _proxy_self
    );
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

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_getobject_f,BHYPRE_SSTRUCTPARCSRMATRIX_GETOBJECT_F,bHYPRE_SStructParCSRMatrix_GetObject_f)
(
  int64_t *self,
  int64_t *A,
  int32_t *retval
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  struct SIDL_BaseInterface__object* _proxy_A = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_GetObject))(
      _proxy_self,
      &_proxy_A
    );
  *A = (ptrdiff_t)_proxy_A;
}

/*
 * Set the matrix graph.
 * 
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_setgraph_f,BHYPRE_SSTRUCTPARCSRMATRIX_SETGRAPH_F,bHYPRE_SStructParCSRMatrix_SetGraph_f)
(
  int64_t *self,
  int64_t *graph,
  int32_t *retval
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  struct bHYPRE_SStructGraph__object* _proxy_graph = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _proxy_graph =
    (struct bHYPRE_SStructGraph__object*)
    (ptrdiff_t)(*graph);
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_SetGraph))(
      _proxy_self,
      _proxy_graph
    );
}

/*
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
 * 
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_setvalues_f,BHYPRE_SSTRUCTPARCSRMATRIX_SETVALUES_F,bHYPRE_SStructParCSRMatrix_SetValues_f)
(
  int64_t *self,
  int32_t *part,
  int64_t *index,
  int32_t *var,
  int32_t *nentries,
  int64_t *entries,
  int64_t *values,
  int32_t *retval
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  struct SIDL_int__array* _proxy_index = NULL;
  struct SIDL_int__array* _proxy_entries = NULL;
  struct SIDL_double__array* _proxy_values = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _proxy_index =
    (struct SIDL_int__array*)
    (ptrdiff_t)(*index);
  _proxy_entries =
    (struct SIDL_int__array*)
    (ptrdiff_t)(*entries);
  _proxy_values =
    (struct SIDL_double__array*)
    (ptrdiff_t)(*values);
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_SetValues))(
      _proxy_self,
      *part,
      _proxy_index,
      *var,
      *nentries,
      _proxy_entries,
      _proxy_values
    );
}

/*
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
 * 
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_setboxvalues_f,BHYPRE_SSTRUCTPARCSRMATRIX_SETBOXVALUES_F,bHYPRE_SStructParCSRMatrix_SetBoxValues_f)
(
  int64_t *self,
  int32_t *part,
  int64_t *ilower,
  int64_t *iupper,
  int32_t *var,
  int32_t *nentries,
  int64_t *entries,
  int64_t *values,
  int32_t *retval
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  struct SIDL_int__array* _proxy_ilower = NULL;
  struct SIDL_int__array* _proxy_iupper = NULL;
  struct SIDL_int__array* _proxy_entries = NULL;
  struct SIDL_double__array* _proxy_values = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _proxy_ilower =
    (struct SIDL_int__array*)
    (ptrdiff_t)(*ilower);
  _proxy_iupper =
    (struct SIDL_int__array*)
    (ptrdiff_t)(*iupper);
  _proxy_entries =
    (struct SIDL_int__array*)
    (ptrdiff_t)(*entries);
  _proxy_values =
    (struct SIDL_double__array*)
    (ptrdiff_t)(*values);
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_SetBoxValues))(
      _proxy_self,
      *part,
      _proxy_ilower,
      _proxy_iupper,
      *var,
      *nentries,
      _proxy_entries,
      _proxy_values
    );
}

/*
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
 * 
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_addtovalues_f,BHYPRE_SSTRUCTPARCSRMATRIX_ADDTOVALUES_F,bHYPRE_SStructParCSRMatrix_AddToValues_f)
(
  int64_t *self,
  int32_t *part,
  int64_t *index,
  int32_t *var,
  int32_t *nentries,
  int64_t *entries,
  int64_t *values,
  int32_t *retval
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  struct SIDL_int__array* _proxy_index = NULL;
  struct SIDL_int__array* _proxy_entries = NULL;
  struct SIDL_double__array* _proxy_values = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _proxy_index =
    (struct SIDL_int__array*)
    (ptrdiff_t)(*index);
  _proxy_entries =
    (struct SIDL_int__array*)
    (ptrdiff_t)(*entries);
  _proxy_values =
    (struct SIDL_double__array*)
    (ptrdiff_t)(*values);
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_AddToValues))(
      _proxy_self,
      *part,
      _proxy_index,
      *var,
      *nentries,
      _proxy_entries,
      _proxy_values
    );
}

/*
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
 * 
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_addtoboxvalues_f,BHYPRE_SSTRUCTPARCSRMATRIX_ADDTOBOXVALUES_F,bHYPRE_SStructParCSRMatrix_AddToBoxValues_f)
(
  int64_t *self,
  int32_t *part,
  int64_t *ilower,
  int64_t *iupper,
  int32_t *var,
  int32_t *nentries,
  int64_t *entries,
  int64_t *values,
  int32_t *retval
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  struct SIDL_int__array* _proxy_ilower = NULL;
  struct SIDL_int__array* _proxy_iupper = NULL;
  struct SIDL_int__array* _proxy_entries = NULL;
  struct SIDL_double__array* _proxy_values = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _proxy_ilower =
    (struct SIDL_int__array*)
    (ptrdiff_t)(*ilower);
  _proxy_iupper =
    (struct SIDL_int__array*)
    (ptrdiff_t)(*iupper);
  _proxy_entries =
    (struct SIDL_int__array*)
    (ptrdiff_t)(*entries);
  _proxy_values =
    (struct SIDL_double__array*)
    (ptrdiff_t)(*values);
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_AddToBoxValues))(
      _proxy_self,
      *part,
      _proxy_ilower,
      _proxy_iupper,
      *var,
      *nentries,
      _proxy_entries,
      _proxy_values
    );
}

/*
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
 * 
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_setsymmetric_f,BHYPRE_SSTRUCTPARCSRMATRIX_SETSYMMETRIC_F,bHYPRE_SStructParCSRMatrix_SetSymmetric_f)
(
  int64_t *self,
  int32_t *part,
  int32_t *var,
  int32_t *to_var,
  int32_t *symmetric,
  int32_t *retval
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_SetSymmetric))(
      _proxy_self,
      *part,
      *var,
      *to_var,
      *symmetric
    );
}

/*
 * Define symmetry properties for all non-stencil matrix
 * entries.
 * 
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_setnssymmetric_f,BHYPRE_SSTRUCTPARCSRMATRIX_SETNSSYMMETRIC_F,bHYPRE_SStructParCSRMatrix_SetNSSymmetric_f)
(
  int64_t *self,
  int32_t *symmetric,
  int32_t *retval
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_SetNSSymmetric))(
      _proxy_self,
      *symmetric
    );
}

/*
 * Set the matrix to be complex.
 * 
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_setcomplex_f,BHYPRE_SSTRUCTPARCSRMATRIX_SETCOMPLEX_F,bHYPRE_SStructParCSRMatrix_SetComplex_f)
(
  int64_t *self,
  int32_t *retval
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_SetComplex))(
      _proxy_self
    );
}

/*
 * Print the matrix to file.  This is mainly for debugging
 * purposes.
 * 
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_print_f,BHYPRE_SSTRUCTPARCSRMATRIX_PRINT_F,bHYPRE_SStructParCSRMatrix_Print_f)
(
  int64_t *self,
  SIDL_F77_String filename
  SIDL_F77_STR_NEAR_LEN_DECL(filename),
  int32_t *all,
  int32_t *retval
  SIDL_F77_STR_FAR_LEN_DECL(filename)
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  char* _proxy_filename = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _proxy_filename =
    SIDL_copy_fortran_str(SIDL_F77_STR(filename),
      SIDL_F77_STR_LEN(filename));
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_Print))(
      _proxy_self,
      _proxy_filename,
      *all
    );
  free((void *)_proxy_filename);
}

/*
 * Set the int parameter associated with {\tt name}.
 * 
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_setintparameter_f,BHYPRE_SSTRUCTPARCSRMATRIX_SETINTPARAMETER_F,bHYPRE_SStructParCSRMatrix_SetIntParameter_f)
(
  int64_t *self,
  SIDL_F77_String name
  SIDL_F77_STR_NEAR_LEN_DECL(name),
  int32_t *value,
  int32_t *retval
  SIDL_F77_STR_FAR_LEN_DECL(name)
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  char* _proxy_name = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _proxy_name =
    SIDL_copy_fortran_str(SIDL_F77_STR(name),
      SIDL_F77_STR_LEN(name));
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_SetIntParameter))(
      _proxy_self,
      _proxy_name,
      *value
    );
  free((void *)_proxy_name);
}

/*
 * Set the double parameter associated with {\tt name}.
 * 
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_setdoubleparameter_f,BHYPRE_SSTRUCTPARCSRMATRIX_SETDOUBLEPARAMETER_F,bHYPRE_SStructParCSRMatrix_SetDoubleParameter_f)
(
  int64_t *self,
  SIDL_F77_String name
  SIDL_F77_STR_NEAR_LEN_DECL(name),
  double *value,
  int32_t *retval
  SIDL_F77_STR_FAR_LEN_DECL(name)
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  char* _proxy_name = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _proxy_name =
    SIDL_copy_fortran_str(SIDL_F77_STR(name),
      SIDL_F77_STR_LEN(name));
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_SetDoubleParameter))(
      _proxy_self,
      _proxy_name,
      *value
    );
  free((void *)_proxy_name);
}

/*
 * Set the string parameter associated with {\tt name}.
 * 
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_setstringparameter_f,BHYPRE_SSTRUCTPARCSRMATRIX_SETSTRINGPARAMETER_F,bHYPRE_SStructParCSRMatrix_SetStringParameter_f)
(
  int64_t *self,
  SIDL_F77_String name
  SIDL_F77_STR_NEAR_LEN_DECL(name),
  SIDL_F77_String value
  SIDL_F77_STR_NEAR_LEN_DECL(value),
  int32_t *retval
  SIDL_F77_STR_FAR_LEN_DECL(name)
  SIDL_F77_STR_FAR_LEN_DECL(value)
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  char* _proxy_name = NULL;
  char* _proxy_value = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _proxy_name =
    SIDL_copy_fortran_str(SIDL_F77_STR(name),
      SIDL_F77_STR_LEN(name));
  _proxy_value =
    SIDL_copy_fortran_str(SIDL_F77_STR(value),
      SIDL_F77_STR_LEN(value));
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_SetStringParameter))(
      _proxy_self,
      _proxy_name,
      _proxy_value
    );
  free((void *)_proxy_name);
  free((void *)_proxy_value);
}

/*
 * Set the int 1-D array parameter associated with {\tt name}.
 * 
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_setintarray1parameter_f,BHYPRE_SSTRUCTPARCSRMATRIX_SETINTARRAY1PARAMETER_F,bHYPRE_SStructParCSRMatrix_SetIntArray1Parameter_f)
(
  int64_t *self,
  SIDL_F77_String name
  SIDL_F77_STR_NEAR_LEN_DECL(name),
  int64_t *value,
  int32_t *retval
  SIDL_F77_STR_FAR_LEN_DECL(name)
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  char* _proxy_name = NULL;
  struct SIDL_int__array* _proxy_value = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _proxy_name =
    SIDL_copy_fortran_str(SIDL_F77_STR(name),
      SIDL_F77_STR_LEN(name));
  _proxy_value =
    (struct SIDL_int__array*)
    (ptrdiff_t)(*value);
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_SetIntArray1Parameter))(
      _proxy_self,
      _proxy_name,
      _proxy_value
    );
  free((void *)_proxy_name);
}

/*
 * Set the int 2-D array parameter associated with {\tt name}.
 * 
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_setintarray2parameter_f,BHYPRE_SSTRUCTPARCSRMATRIX_SETINTARRAY2PARAMETER_F,bHYPRE_SStructParCSRMatrix_SetIntArray2Parameter_f)
(
  int64_t *self,
  SIDL_F77_String name
  SIDL_F77_STR_NEAR_LEN_DECL(name),
  int64_t *value,
  int32_t *retval
  SIDL_F77_STR_FAR_LEN_DECL(name)
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  char* _proxy_name = NULL;
  struct SIDL_int__array* _proxy_value = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _proxy_name =
    SIDL_copy_fortran_str(SIDL_F77_STR(name),
      SIDL_F77_STR_LEN(name));
  _proxy_value =
    (struct SIDL_int__array*)
    (ptrdiff_t)(*value);
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_SetIntArray2Parameter))(
      _proxy_self,
      _proxy_name,
      _proxy_value
    );
  free((void *)_proxy_name);
}

/*
 * Set the double 1-D array parameter associated with {\tt name}.
 * 
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_setdoublearray1parameter_f,BHYPRE_SSTRUCTPARCSRMATRIX_SETDOUBLEARRAY1PARAMETER_F,bHYPRE_SStructParCSRMatrix_SetDoubleArray1Parameter_f)
(
  int64_t *self,
  SIDL_F77_String name
  SIDL_F77_STR_NEAR_LEN_DECL(name),
  int64_t *value,
  int32_t *retval
  SIDL_F77_STR_FAR_LEN_DECL(name)
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  char* _proxy_name = NULL;
  struct SIDL_double__array* _proxy_value = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _proxy_name =
    SIDL_copy_fortran_str(SIDL_F77_STR(name),
      SIDL_F77_STR_LEN(name));
  _proxy_value =
    (struct SIDL_double__array*)
    (ptrdiff_t)(*value);
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_SetDoubleArray1Parameter))(
      _proxy_self,
      _proxy_name,
      _proxy_value
    );
  free((void *)_proxy_name);
}

/*
 * Set the double 2-D array parameter associated with {\tt name}.
 * 
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_setdoublearray2parameter_f,BHYPRE_SSTRUCTPARCSRMATRIX_SETDOUBLEARRAY2PARAMETER_F,bHYPRE_SStructParCSRMatrix_SetDoubleArray2Parameter_f)
(
  int64_t *self,
  SIDL_F77_String name
  SIDL_F77_STR_NEAR_LEN_DECL(name),
  int64_t *value,
  int32_t *retval
  SIDL_F77_STR_FAR_LEN_DECL(name)
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  char* _proxy_name = NULL;
  struct SIDL_double__array* _proxy_value = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _proxy_name =
    SIDL_copy_fortran_str(SIDL_F77_STR(name),
      SIDL_F77_STR_LEN(name));
  _proxy_value =
    (struct SIDL_double__array*)
    (ptrdiff_t)(*value);
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_SetDoubleArray2Parameter))(
      _proxy_self,
      _proxy_name,
      _proxy_value
    );
  free((void *)_proxy_name);
}

/*
 * Set the int parameter associated with {\tt name}.
 * 
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_getintvalue_f,BHYPRE_SSTRUCTPARCSRMATRIX_GETINTVALUE_F,bHYPRE_SStructParCSRMatrix_GetIntValue_f)
(
  int64_t *self,
  SIDL_F77_String name
  SIDL_F77_STR_NEAR_LEN_DECL(name),
  int32_t *value,
  int32_t *retval
  SIDL_F77_STR_FAR_LEN_DECL(name)
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  char* _proxy_name = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _proxy_name =
    SIDL_copy_fortran_str(SIDL_F77_STR(name),
      SIDL_F77_STR_LEN(name));
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_GetIntValue))(
      _proxy_self,
      _proxy_name,
      value
    );
  free((void *)_proxy_name);
}

/*
 * Get the double parameter associated with {\tt name}.
 * 
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_getdoublevalue_f,BHYPRE_SSTRUCTPARCSRMATRIX_GETDOUBLEVALUE_F,bHYPRE_SStructParCSRMatrix_GetDoubleValue_f)
(
  int64_t *self,
  SIDL_F77_String name
  SIDL_F77_STR_NEAR_LEN_DECL(name),
  double *value,
  int32_t *retval
  SIDL_F77_STR_FAR_LEN_DECL(name)
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  char* _proxy_name = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _proxy_name =
    SIDL_copy_fortran_str(SIDL_F77_STR(name),
      SIDL_F77_STR_LEN(name));
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_GetDoubleValue))(
      _proxy_self,
      _proxy_name,
      value
    );
  free((void *)_proxy_name);
}

/*
 * (Optional) Do any preprocessing that may be necessary in
 * order to execute {\tt Apply}.
 * 
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_setup_f,BHYPRE_SSTRUCTPARCSRMATRIX_SETUP_F,bHYPRE_SStructParCSRMatrix_Setup_f)
(
  int64_t *self,
  int64_t *b,
  int64_t *x,
  int32_t *retval
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  struct bHYPRE_Vector__object* _proxy_b = NULL;
  struct bHYPRE_Vector__object* _proxy_x = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _proxy_b =
    (struct bHYPRE_Vector__object*)
    (ptrdiff_t)(*b);
  _proxy_x =
    (struct bHYPRE_Vector__object*)
    (ptrdiff_t)(*x);
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_Setup))(
      _proxy_self,
      _proxy_b,
      _proxy_x
    );
}

/*
 * Apply the operator to {\tt b}, returning {\tt x}.
 * 
 */

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix_apply_f,BHYPRE_SSTRUCTPARCSRMATRIX_APPLY_F,bHYPRE_SStructParCSRMatrix_Apply_f)
(
  int64_t *self,
  int64_t *b,
  int64_t *x,
  int32_t *retval
)
{
  struct bHYPRE_SStructParCSRMatrix__epv *_epv = NULL;
  struct bHYPRE_SStructParCSRMatrix__object* _proxy_self = NULL;
  struct bHYPRE_Vector__object* _proxy_b = NULL;
  struct bHYPRE_Vector__object* _proxy_x = NULL;
  _proxy_self =
    (struct bHYPRE_SStructParCSRMatrix__object*)
    (ptrdiff_t)(*self);
  _proxy_b =
    (struct bHYPRE_Vector__object*)
    (ptrdiff_t)(*b);
  _proxy_x =
    (struct bHYPRE_Vector__object*)
    (ptrdiff_t)(*x);
  _epv = _proxy_self->d_epv;
  *retval = 
    (*(_epv->f_Apply))(
      _proxy_self,
      _proxy_b,
      &_proxy_x
    );
  *x = (ptrdiff_t)_proxy_x;
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_createcol_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_CREATECOL_F,
                  bHYPRE_SStructParCSRMatrix__array_createCol_f)
  (int32_t *dimen,
   int32_t lower[],
   int32_t upper[],
   int64_t *result)
{
  *result = (ptrdiff_t)
    SIDL_interface__array_createCol(*dimen, lower, upper);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_createrow_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_CREATEROW_F,
                  bHYPRE_SStructParCSRMatrix__array_createRow_f)
  (int32_t *dimen,
   int32_t lower[],
   int32_t upper[],
   int64_t *result)
{
  *result = (ptrdiff_t)
    SIDL_interface__array_createRow(*dimen, lower, upper);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_create1d_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_CREATE1D_F,
                  bHYPRE_SStructParCSRMatrix__array_create1d_f)
  (int32_t *len, int64_t *result)
{
  *result = (ptrdiff_t)SIDL_interface__array_create1d(*len);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_create2dcol_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_CREATE2DCOL_F,
                  bHYPRE_SStructParCSRMatrix__array_create2dCol_f)
  (int32_t *m, int32_t *n, int64_t *result)
{
  *result = (ptrdiff_t)SIDL_interface__array_create2dCol(*m, *n);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_create2drow_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_CREATE2DROW_F,
                  bHYPRE_SStructParCSRMatrix__array_create2dRow_f)
  (int32_t *m, int32_t *n, int64_t *result)
{
  *result = (ptrdiff_t)SIDL_interface__array_create2dRow(*m, *n);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_addref_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_ADDREF_F,
                  bHYPRE_SStructParCSRMatrix__array_addRef_f)
  (int64_t *array)
{
  SIDL_interface__array_addRef((struct SIDL_interface__array 
    *)(ptrdiff_t)*array);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_deleteref_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_DELETEREF_F,
                  bHYPRE_SStructParCSRMatrix__array_deleteRef_f)
  (int64_t *array)
{
  SIDL_interface__array_deleteRef((struct SIDL_interface__array 
    *)(ptrdiff_t)*array);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_get1_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_GET1_F,
                  bHYPRE_SStructParCSRMatrix__array_get1_f)
  (int64_t *array, 
   int32_t *i1, 
   int64_t *result)
{
  *result = (ptrdiff_t)
    SIDL_interface__array_get1((const struct SIDL_interface__array 
      *)(ptrdiff_t)*array
    , *i1);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_get2_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_GET2_F,
                  bHYPRE_SStructParCSRMatrix__array_get2_f)
  (int64_t *array, 
   int32_t *i1, 
   int32_t *i2, 
   int64_t *result)
{
  *result = (ptrdiff_t)
    SIDL_interface__array_get2((const struct SIDL_interface__array 
      *)(ptrdiff_t)*array
    , *i1, *i2);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_get3_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_GET3_F,
                  bHYPRE_SStructParCSRMatrix__array_get3_f)
  (int64_t *array, 
   int32_t *i1, 
   int32_t *i2, 
   int32_t *i3, 
   int64_t *result)
{
  *result = (ptrdiff_t)
    SIDL_interface__array_get3((const struct SIDL_interface__array 
      *)(ptrdiff_t)*array
    , *i1, *i2, *i3);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_get4_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_GET4_F,
                  bHYPRE_SStructParCSRMatrix__array_get4_f)
  (int64_t *array, 
   int32_t *i1, 
   int32_t *i2, 
   int32_t *i3, 
   int32_t *i4, 
   int64_t *result)
{
  *result = (ptrdiff_t)
    SIDL_interface__array_get4((const struct SIDL_interface__array 
      *)(ptrdiff_t)*array
    , *i1, *i2, *i3, *i4);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_get_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_GET_F,
                  bHYPRE_SStructParCSRMatrix__array_get_f)
  (int64_t *array,
   int32_t indices[],
   int64_t *result)
{
  *result = (ptrdiff_t)
    SIDL_interface__array_get((const struct SIDL_interface__array 
      *)(ptrdiff_t)*array, indices);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_set1_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_SET1_F,
                  bHYPRE_SStructParCSRMatrix__array_set1_f)
  (int64_t *array,
   int32_t *i1,
   int64_t *value)
{
  SIDL_interface__array_set1((struct SIDL_interface__array *)(ptrdiff_t)*array
  , *i1, (struct SIDL_BaseInterface__object *)(ptrdiff_t)*value);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_set2_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_SET2_F,
                  bHYPRE_SStructParCSRMatrix__array_set2_f)
  (int64_t *array,
   int32_t *i1,
   int32_t *i2,
   int64_t *value)
{
  SIDL_interface__array_set2((struct SIDL_interface__array *)(ptrdiff_t)*array
  , *i1, *i2, (struct SIDL_BaseInterface__object *)(ptrdiff_t)*value);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_set3_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_SET3_F,
                  bHYPRE_SStructParCSRMatrix__array_set3_f)
  (int64_t *array,
   int32_t *i1,
   int32_t *i2,
   int32_t *i3,
   int64_t *value)
{
  SIDL_interface__array_set3((struct SIDL_interface__array *)(ptrdiff_t)*array
  , *i1, *i2, *i3, (struct SIDL_BaseInterface__object *)(ptrdiff_t)*value);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_set4_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_SET4_F,
                  bHYPRE_SStructParCSRMatrix__array_set4_f)
  (int64_t *array,
   int32_t *i1,
   int32_t *i2,
   int32_t *i3,
   int32_t *i4,
   int64_t *value)
{
  SIDL_interface__array_set4((struct SIDL_interface__array *)(ptrdiff_t)*array
  , *i1, *i2, *i3, *i4, (struct SIDL_BaseInterface__object *)(ptrdiff_t)*value);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_set_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_SET_F,
                  bHYPRE_SStructParCSRMatrix__array_set_f)
  (int64_t *array,
  int32_t indices[],
  int64_t *value)
{
  SIDL_interface__array_set((struct SIDL_interface__array *)(ptrdiff_t)*array,
    indices, (struct SIDL_BaseInterface__object *)(ptrdiff_t)*value);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_dimen_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_DIMEN_F,
                  bHYPRE_SStructParCSRMatrix__array_dimen_f)
  (int64_t *array, int32_t *result)
{
  *result =
    SIDL_interface__array_dimen((struct SIDL_interface__array 
      *)(ptrdiff_t)*array);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_lower_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_LOWER_F,
                  bHYPRE_SStructParCSRMatrix__array_lower_f)
  (int64_t *array,
   int32_t *ind,
   int32_t *result)
{
  *result = 
    SIDL_interface__array_lower((struct SIDL_interface__array 
      *)(ptrdiff_t)*array, *ind);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_upper_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_UPPER_F,
                  bHYPRE_SStructParCSRMatrix__array_upper_f)
  (int64_t *array,
   int32_t *ind,
   int32_t *result)
{
  *result = 
    SIDL_interface__array_upper((struct SIDL_interface__array 
      *)(ptrdiff_t)*array, *ind);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_stride_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_STRIDE_F,
                  bHYPRE_SStructParCSRMatrix__array_stride_f)
  (int64_t *array,
   int32_t *ind,
   int32_t *result)
{
  *result = 
    SIDL_interface__array_stride((struct SIDL_interface__array 
      *)(ptrdiff_t)*array, *ind);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_iscolumnorder_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_ISCOLUMNORDER_F,
                  bHYPRE_SStructParCSRMatrix__array_isColumnOrder_f)
  (int64_t *array,
   SIDL_F77_Bool *result)
{
  *result = SIDL_interface__array_isColumnOrder((struct SIDL_interface__array 
    *)(ptrdiff_t)*array);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_isroworder_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_ISROWORDER_F,
                  bHYPRE_SStructParCSRMatrix__array_isRowOrder_f)
  (int64_t *array,
   SIDL_F77_Bool *result)
{
  *result = SIDL_interface__array_isRowOrder((struct SIDL_interface__array 
    *)(ptrdiff_t)*array);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_copy_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_COPY_F,
                  bHYPRE_SStructParCSRMatrix__array_copy_f)
  (int64_t *src,
   int64_t *dest)
{
  SIDL_interface__array_copy((const struct SIDL_interface__array 
    *)(ptrdiff_t)*src,
                             (struct SIDL_interface__array *)(ptrdiff_t)*dest);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_smartcopy_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_SMARTCOPY_F,
                  bHYPRE_SStructParCSRMatrix__array_smartCopy_f)
  (int64_t *src)
{
  SIDL_interface__array_smartCopy((struct SIDL_interface__array 
    *)(ptrdiff_t)*src);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_slice_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_SLICE_F,
                  bHYPRE_SStructParCSRMatrix__array_slice_f)
  (int64_t *src,
   int32_t *dimen,
   int32_t numElem[],
   int32_t srcStart[],
   int32_t srcStride[],
   int32_t newStart[],
   int64_t *result)
{
  *result = (ptrdiff_t)
    SIDL_interface__array_slice((struct SIDL_interface__array *)(ptrdiff_t)*src,
      *dimen, numElem, srcStart, srcStride, newStart);
}

void
SIDLFortran77Symbol(bhypre_sstructparcsrmatrix__array_ensure_f,
                  BHYPRE_SSTRUCTPARCSRMATRIX__ARRAY_ENSURE_F,
                  bHYPRE_SStructParCSRMatrix__array_ensure_f)
  (int64_t *src,
   int32_t *dimen,
   int     *ordering,
   int64_t *result)
{
  *result = (ptrdiff_t)
    SIDL_interface__array_ensure((struct SIDL_interface__array 
      *)(ptrdiff_t)*src,
    *dimen, *ordering);
}

