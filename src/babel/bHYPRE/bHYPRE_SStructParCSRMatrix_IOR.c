/*
 * File:          bHYPRE_SStructParCSRMatrix_IOR.c
 * Symbol:        bHYPRE.SStructParCSRMatrix-v1.0.0
 * Symbol Type:   class
 * Babel Version: 1.0.4
 * Description:   Intermediate Object Representation for bHYPRE.SStructParCSRMatrix
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

/*
 * Begin: RMI includes
 */

#include "sidl_rmi_InstanceHandle.h"
#include "sidl_rmi_InstanceRegistry.h"
#include "sidl_rmi_ServerRegistry.h"
#include "sidl_rmi_Call.h"
#include "sidl_rmi_Return.h"
#include "sidl_Exception.h"
#include "sidl_exec_err.h"
#include "sidl_PreViolation.h"
#include <stdio.h>
/*
 * End: RMI includes
 */

#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "bHYPRE_SStructParCSRMatrix_IOR.h"
#ifndef included_sidl_BaseClass_Impl_h
#include "sidl_BaseClass_Impl.h"
#endif
#ifndef included_sidl_BaseClass_h
#include "sidl_BaseClass.h"
#endif
#ifndef included_sidl_ClassInfo_h
#include "sidl_ClassInfo.h"
#endif
#ifndef included_sidl_ClassInfoI_h
#include "sidl_ClassInfoI.h"
#endif

#ifndef NULL
#define NULL 0
#endif

#include "sidl_thread.h"
#ifdef HAVE_PTHREAD
static struct sidl_recursive_mutex_t bHYPRE_SStructParCSRMatrix__mutex= SIDL_RECURSIVE_MUTEX_INITIALIZER;
#define LOCK_STATIC_GLOBALS sidl_recursive_mutex_lock( &bHYPRE_SStructParCSRMatrix__mutex )
#define UNLOCK_STATIC_GLOBALS sidl_recursive_mutex_unlock( &bHYPRE_SStructParCSRMatrix__mutex )
/* #define HAVE_LOCKED_STATIC_GLOBALS (sidl_recursive_mutex_trylock( &bHYPRE_SStructParCSRMatrix__mutex )==EDEADLOCK) */
#else
#define LOCK_STATIC_GLOBALS
#define UNLOCK_STATIC_GLOBALS
/* #define HAVE_LOCKED_STATIC_GLOBALS (1) */
#endif

/*
 * Static variables to hold version of IOR
 */

static const int32_t s_IOR_MAJOR_VERSION = 1;
static const int32_t s_IOR_MINOR_VERSION = 0;

/*
 * Static variable to hold shared ClassInfo interface.
 */

static sidl_ClassInfo s_classInfo = NULL;

/*
 * Static variable to make sure _load called no more than once
 */

static int s_load_called = 0;
/*
 * Static variables for managing EPV initialization.
 */

static int s_method_initialized = 0;
static int s_static_initialized = 0;

static struct bHYPRE_SStructParCSRMatrix__epv  
  s_new_epv__bhypre_sstructparcsrmatrix;
static struct bHYPRE_SStructParCSRMatrix__sepv 
  s_stc_epv__bhypre_sstructparcsrmatrix;

static struct bHYPRE_SStructParCSRMatrix__epv  
  s_new_epv_hooks__bhypre_sstructparcsrmatrix;
static struct bHYPRE_SStructParCSRMatrix__sepv 
  s_stc_epv_hooks__bhypre_sstructparcsrmatrix;

static struct bHYPRE_MatrixVectorView__epv s_new_epv__bhypre_matrixvectorview;
static struct bHYPRE_MatrixVectorView__epv 
  s_new_epv_hooks__bhypre_matrixvectorview;

static struct bHYPRE_Operator__epv s_new_epv__bhypre_operator;
static struct bHYPRE_Operator__epv s_new_epv_hooks__bhypre_operator;

static struct bHYPRE_ProblemDefinition__epv s_new_epv__bhypre_problemdefinition;
static struct bHYPRE_ProblemDefinition__epv 
  s_new_epv_hooks__bhypre_problemdefinition;

static struct bHYPRE_SStructMatrixVectorView__epv 
  s_new_epv__bhypre_sstructmatrixvectorview;
static struct bHYPRE_SStructMatrixVectorView__epv 
  s_new_epv_hooks__bhypre_sstructmatrixvectorview;

static struct bHYPRE_SStructMatrixView__epv s_new_epv__bhypre_sstructmatrixview;
static struct bHYPRE_SStructMatrixView__epv 
  s_new_epv_hooks__bhypre_sstructmatrixview;

static struct sidl_BaseClass__epv  s_new_epv__sidl_baseclass;
static struct sidl_BaseClass__epv  s_new_epv_hooks__sidl_baseclass;
static struct sidl_BaseClass__epv* s_old_epv__sidl_baseclass;
static struct sidl_BaseClass__epv* s_old_epv_hooks__sidl_baseclass;

static struct sidl_BaseInterface__epv  s_new_epv__sidl_baseinterface;
static struct sidl_BaseInterface__epv  s_new_epv_hooks__sidl_baseinterface;
static struct sidl_BaseInterface__epv* s_old_epv__sidl_baseinterface;
static struct sidl_BaseInterface__epv* s_old_epv_hooks__sidl_baseinterface;

/*
 * Declare EPV routines defined in the skeleton file.
 */

#ifdef __cplusplus
extern "C" {
#endif

extern void bHYPRE_SStructParCSRMatrix__set_epv(
  struct bHYPRE_SStructParCSRMatrix__epv* epv);
extern void bHYPRE_SStructParCSRMatrix__set_sepv(
  struct bHYPRE_SStructParCSRMatrix__sepv* sepv);
extern void bHYPRE_SStructParCSRMatrix__call_load(void);
#ifdef __cplusplus
}
#endif

static void
bHYPRE_SStructParCSRMatrix_addRef__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */

  /* make the call */
  (self->d_epv->f_addRef)(
    self,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  /* pack out and inout argments */
  /* clean-up dangling references */
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_deleteRef__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */

  /* make the call */
  (self->d_epv->f_deleteRef)(
    self,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  /* pack out and inout argments */
  /* clean-up dangling references */
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_isSame__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* iobj_str = NULL;
  struct sidl_BaseInterface__object* iobj = NULL;
  sidl_bool _retval = FALSE;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "iobj", &iobj_str, _ex);SIDL_CHECK(*_ex);
  iobj = skel_bHYPRE_SStructParCSRMatrix_fconnect_sidl_BaseInterface(iobj_str, 
    TRUE, _ex);SIDL_CHECK(*_ex);

  /* make the call */
  _retval = (self->d_epv->f_isSame)(
    self,
    iobj,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packBool( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  /* clean-up dangling references */
  if(iobj) {
    sidl_BaseInterface_deleteRef((sidl_BaseInterface)iobj, _ex); SIDL_CHECK(
      *_ex);
    if(iobj_str) {free(iobj_str);}
  }
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_isType__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* name= NULL;
  sidl_bool _retval = FALSE;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "name", &name, _ex);SIDL_CHECK(*_ex);

  /* make the call */
  _retval = (self->d_epv->f_isType)(
    self,
    name,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packBool( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  /* clean-up dangling references */
  if(name) {free(name);}
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_getClassInfo__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  struct sidl_ClassInfo__object* _retval = NULL;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */

  /* make the call */
  _retval = (self->d_epv->f_getClassInfo)(
    self,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  if(_retval){
    char* _url = sidl_BaseInterface__getURL((sidl_BaseInterface)_retval, 
      _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Return_packString( outArgs, "_retval", _url, _ex);SIDL_CHECK(*_ex);
    free((void*)_url);
  } else {
    sidl_rmi_Return_packString( outArgs, "_retval", NULL, _ex);SIDL_CHECK(*_ex);
  }
  /* pack out and inout argments */
  /* clean-up dangling references */
  if(_retval && sidl_BaseInterface__isRemote((sidl_BaseInterface)_retval, _ex)) 
    {
    (*((sidl_BaseInterface)_retval)->d_epv->f__raddRef)(((
      sidl_BaseInterface)_retval)->d_object, _ex); SIDL_CHECK(*_ex);
    sidl_BaseInterface_deleteRef((sidl_BaseInterface)_retval, _ex); SIDL_CHECK(
      *_ex);
  }
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_SetGraph__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* graph_str = NULL;
  struct bHYPRE_SStructGraph__object* graph = NULL;
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "graph", &graph_str, _ex);SIDL_CHECK(
    *_ex);
  graph = skel_bHYPRE_SStructParCSRMatrix_fconnect_bHYPRE_SStructGraph(
    graph_str, TRUE, _ex);SIDL_CHECK(*_ex);

  /* make the call */
  _retval = (self->d_epv->f_SetGraph)(
    self,
    graph,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  /* clean-up dangling references */
  if(graph) {
    sidl_BaseInterface_deleteRef((sidl_BaseInterface)graph, _ex); SIDL_CHECK(
      *_ex);
    if(graph_str) {free(graph_str);}
  }
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_SetValues__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  int32_t part = 0;
  struct sidl_int__array* index = NULL;
  int32_t var = 0;
  struct sidl_int__array* entries = NULL;
  struct sidl_double__array* values = NULL;
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackInt( inArgs, "part", &part, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackIntArray( inArgs, "index", &index,sidl_column_major_order,
    1,TRUE, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackInt( inArgs, "var", &var, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackIntArray( inArgs, "entries", &entries,
    sidl_column_major_order,1,TRUE, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackDoubleArray( inArgs, "values", &values,
    sidl_column_major_order,1,TRUE, _ex);SIDL_CHECK(*_ex);

  /* make the call */
  _retval = (self->d_epv->f_SetValues)(
    self,
    part,
    index,
    var,
    entries,
    values,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  /* clean-up dangling references */
  sidl__array_deleteRef((struct sidl__array*)index);
  sidl__array_deleteRef((struct sidl__array*)entries);
  sidl__array_deleteRef((struct sidl__array*)values);
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_SetBoxValues__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  int32_t part = 0;
  struct sidl_int__array* ilower = NULL;
  struct sidl_int__array* iupper = NULL;
  int32_t var = 0;
  struct sidl_int__array* entries = NULL;
  struct sidl_double__array* values = NULL;
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackInt( inArgs, "part", &part, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackIntArray( inArgs, "ilower", &ilower,
    sidl_column_major_order,1,TRUE, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackIntArray( inArgs, "iupper", &iupper,
    sidl_column_major_order,1,TRUE, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackInt( inArgs, "var", &var, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackIntArray( inArgs, "entries", &entries,
    sidl_column_major_order,1,TRUE, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackDoubleArray( inArgs, "values", &values,
    sidl_column_major_order,1,TRUE, _ex);SIDL_CHECK(*_ex);

  /* make the call */
  _retval = (self->d_epv->f_SetBoxValues)(
    self,
    part,
    ilower,
    iupper,
    var,
    entries,
    values,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  /* clean-up dangling references */
  sidl__array_deleteRef((struct sidl__array*)ilower);
  sidl__array_deleteRef((struct sidl__array*)iupper);
  sidl__array_deleteRef((struct sidl__array*)entries);
  sidl__array_deleteRef((struct sidl__array*)values);
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_AddToValues__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  int32_t part = 0;
  struct sidl_int__array* index = NULL;
  int32_t var = 0;
  struct sidl_int__array* entries = NULL;
  struct sidl_double__array* values = NULL;
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackInt( inArgs, "part", &part, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackIntArray( inArgs, "index", &index,sidl_column_major_order,
    1,TRUE, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackInt( inArgs, "var", &var, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackIntArray( inArgs, "entries", &entries,
    sidl_column_major_order,1,TRUE, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackDoubleArray( inArgs, "values", &values,
    sidl_column_major_order,1,TRUE, _ex);SIDL_CHECK(*_ex);

  /* make the call */
  _retval = (self->d_epv->f_AddToValues)(
    self,
    part,
    index,
    var,
    entries,
    values,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  /* clean-up dangling references */
  sidl__array_deleteRef((struct sidl__array*)index);
  sidl__array_deleteRef((struct sidl__array*)entries);
  sidl__array_deleteRef((struct sidl__array*)values);
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_AddToBoxValues__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  int32_t part = 0;
  struct sidl_int__array* ilower = NULL;
  struct sidl_int__array* iupper = NULL;
  int32_t var = 0;
  struct sidl_int__array* entries = NULL;
  struct sidl_double__array* values = NULL;
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackInt( inArgs, "part", &part, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackIntArray( inArgs, "ilower", &ilower,
    sidl_column_major_order,1,TRUE, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackIntArray( inArgs, "iupper", &iupper,
    sidl_column_major_order,1,TRUE, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackInt( inArgs, "var", &var, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackIntArray( inArgs, "entries", &entries,
    sidl_column_major_order,1,TRUE, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackDoubleArray( inArgs, "values", &values,
    sidl_column_major_order,1,TRUE, _ex);SIDL_CHECK(*_ex);

  /* make the call */
  _retval = (self->d_epv->f_AddToBoxValues)(
    self,
    part,
    ilower,
    iupper,
    var,
    entries,
    values,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  /* clean-up dangling references */
  sidl__array_deleteRef((struct sidl__array*)ilower);
  sidl__array_deleteRef((struct sidl__array*)iupper);
  sidl__array_deleteRef((struct sidl__array*)entries);
  sidl__array_deleteRef((struct sidl__array*)values);
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_SetSymmetric__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  int32_t part = 0;
  int32_t var = 0;
  int32_t to_var = 0;
  int32_t symmetric = 0;
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackInt( inArgs, "part", &part, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackInt( inArgs, "var", &var, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackInt( inArgs, "to_var", &to_var, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackInt( inArgs, "symmetric", &symmetric, _ex);SIDL_CHECK(
    *_ex);

  /* make the call */
  _retval = (self->d_epv->f_SetSymmetric)(
    self,
    part,
    var,
    to_var,
    symmetric,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  /* clean-up dangling references */
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_SetNSSymmetric__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  int32_t symmetric = 0;
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackInt( inArgs, "symmetric", &symmetric, _ex);SIDL_CHECK(
    *_ex);

  /* make the call */
  _retval = (self->d_epv->f_SetNSSymmetric)(
    self,
    symmetric,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  /* clean-up dangling references */
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_SetComplex__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */

  /* make the call */
  _retval = (self->d_epv->f_SetComplex)(
    self,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  /* clean-up dangling references */
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_Print__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* filename= NULL;
  int32_t all = 0;
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "filename", &filename, _ex);SIDL_CHECK(
    *_ex);
  sidl_rmi_Call_unpackInt( inArgs, "all", &all, _ex);SIDL_CHECK(*_ex);

  /* make the call */
  _retval = (self->d_epv->f_Print)(
    self,
    filename,
    all,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  /* clean-up dangling references */
  if(filename) {free(filename);}
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_GetObject__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  struct sidl_BaseInterface__object* A_data = NULL;
  struct sidl_BaseInterface__object** A = &A_data;
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */

  /* make the call */
  _retval = (self->d_epv->f_GetObject)(
    self,
    A,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  if(*A){
    char* _url = sidl_BaseInterface__getURL((sidl_BaseInterface)*A, 
      _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Return_packString( outArgs, "A", _url, _ex);SIDL_CHECK(*_ex);
    free((void*)_url);
  } else {
    sidl_rmi_Return_packString( outArgs, "A", NULL, _ex);SIDL_CHECK(*_ex);
  }
  /* clean-up dangling references */
  if(*A && sidl_BaseInterface__isRemote((sidl_BaseInterface)*A, _ex)) {
    (*((sidl_BaseInterface)*A)->d_epv->f__raddRef)(((
      sidl_BaseInterface)*A)->d_object, _ex); SIDL_CHECK(*_ex);
    sidl_BaseInterface_deleteRef((sidl_BaseInterface)*A, _ex); SIDL_CHECK(*_ex);
  }
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_SetCommunicator__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* mpi_comm_str = NULL;
  struct bHYPRE_MPICommunicator__object* mpi_comm = NULL;
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "mpi_comm", &mpi_comm_str, 
    _ex);SIDL_CHECK(*_ex);
  mpi_comm = skel_bHYPRE_SStructParCSRMatrix_fconnect_bHYPRE_MPICommunicator(
    mpi_comm_str, TRUE, _ex);SIDL_CHECK(*_ex);

  /* make the call */
  _retval = (self->d_epv->f_SetCommunicator)(
    self,
    mpi_comm,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  /* clean-up dangling references */
  if(mpi_comm) {
    sidl_BaseInterface_deleteRef((sidl_BaseInterface)mpi_comm, _ex); SIDL_CHECK(
      *_ex);
    if(mpi_comm_str) {free(mpi_comm_str);}
  }
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_Destroy__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */

  /* make the call */
  (self->d_epv->f_Destroy)(
    self,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  /* pack out and inout argments */
  /* clean-up dangling references */
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_Initialize__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */

  /* make the call */
  _retval = (self->d_epv->f_Initialize)(
    self,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  /* clean-up dangling references */
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_Assemble__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */

  /* make the call */
  _retval = (self->d_epv->f_Assemble)(
    self,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  /* clean-up dangling references */
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_SetIntParameter__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* name= NULL;
  int32_t value = 0;
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "name", &name, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackInt( inArgs, "value", &value, _ex);SIDL_CHECK(*_ex);

  /* make the call */
  _retval = (self->d_epv->f_SetIntParameter)(
    self,
    name,
    value,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  /* clean-up dangling references */
  if(name) {free(name);}
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_SetDoubleParameter__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* name= NULL;
  double value = 0;
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "name", &name, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackDouble( inArgs, "value", &value, _ex);SIDL_CHECK(*_ex);

  /* make the call */
  _retval = (self->d_epv->f_SetDoubleParameter)(
    self,
    name,
    value,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  /* clean-up dangling references */
  if(name) {free(name);}
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_SetStringParameter__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* name= NULL;
  char* value= NULL;
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "name", &name, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackString( inArgs, "value", &value, _ex);SIDL_CHECK(*_ex);

  /* make the call */
  _retval = (self->d_epv->f_SetStringParameter)(
    self,
    name,
    value,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  /* clean-up dangling references */
  if(name) {free(name);}
  if(value) {free(value);}
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_SetIntArray1Parameter__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* name= NULL;
  struct sidl_int__array* value = NULL;
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "name", &name, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackIntArray( inArgs, "value", &value,sidl_column_major_order,
    1,TRUE, _ex);SIDL_CHECK(*_ex);

  /* make the call */
  _retval = (self->d_epv->f_SetIntArray1Parameter)(
    self,
    name,
    value,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  /* clean-up dangling references */
  if(name) {free(name);}
  sidl__array_deleteRef((struct sidl__array*)value);
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_SetIntArray2Parameter__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* name= NULL;
  struct sidl_int__array* value = NULL;
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "name", &name, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackIntArray( inArgs, "value", &value,sidl_column_major_order,
    2,FALSE, _ex);SIDL_CHECK(*_ex);

  /* make the call */
  _retval = (self->d_epv->f_SetIntArray2Parameter)(
    self,
    name,
    value,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  /* clean-up dangling references */
  if(name) {free(name);}
  sidl__array_deleteRef((struct sidl__array*)value);
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_SetDoubleArray1Parameter__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* name= NULL;
  struct sidl_double__array* value = NULL;
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "name", &name, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackDoubleArray( inArgs, "value", &value,
    sidl_column_major_order,1,TRUE, _ex);SIDL_CHECK(*_ex);

  /* make the call */
  _retval = (self->d_epv->f_SetDoubleArray1Parameter)(
    self,
    name,
    value,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  /* clean-up dangling references */
  if(name) {free(name);}
  sidl__array_deleteRef((struct sidl__array*)value);
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_SetDoubleArray2Parameter__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* name= NULL;
  struct sidl_double__array* value = NULL;
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "name", &name, _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackDoubleArray( inArgs, "value", &value,
    sidl_column_major_order,2,FALSE, _ex);SIDL_CHECK(*_ex);

  /* make the call */
  _retval = (self->d_epv->f_SetDoubleArray2Parameter)(
    self,
    name,
    value,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  /* clean-up dangling references */
  if(name) {free(name);}
  sidl__array_deleteRef((struct sidl__array*)value);
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_GetIntValue__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* name= NULL;
  int32_t value_data = 0;
  int32_t* value = &value_data;
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "name", &name, _ex);SIDL_CHECK(*_ex);

  /* make the call */
  _retval = (self->d_epv->f_GetIntValue)(
    self,
    name,
    value,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  sidl_rmi_Return_packInt( outArgs, "value", *value, _ex);SIDL_CHECK(*_ex);
  /* clean-up dangling references */
  if(name) {free(name);}
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_GetDoubleValue__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* name= NULL;
  double value_data = 0;
  double* value = &value_data;
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "name", &name, _ex);SIDL_CHECK(*_ex);

  /* make the call */
  _retval = (self->d_epv->f_GetDoubleValue)(
    self,
    name,
    value,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  sidl_rmi_Return_packDouble( outArgs, "value", *value, _ex);SIDL_CHECK(*_ex);
  /* clean-up dangling references */
  if(name) {free(name);}
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_Setup__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* b_str = NULL;
  struct bHYPRE_Vector__object* b = NULL;
  char* x_str = NULL;
  struct bHYPRE_Vector__object* x = NULL;
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "b", &b_str, _ex);SIDL_CHECK(*_ex);
  b = skel_bHYPRE_SStructParCSRMatrix_fconnect_bHYPRE_Vector(b_str, TRUE, 
    _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackString( inArgs, "x", &x_str, _ex);SIDL_CHECK(*_ex);
  x = skel_bHYPRE_SStructParCSRMatrix_fconnect_bHYPRE_Vector(x_str, TRUE, 
    _ex);SIDL_CHECK(*_ex);

  /* make the call */
  _retval = (self->d_epv->f_Setup)(
    self,
    b,
    x,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  /* clean-up dangling references */
  if(b) {
    sidl_BaseInterface_deleteRef((sidl_BaseInterface)b, _ex); SIDL_CHECK(*_ex);
    if(b_str) {free(b_str);}
  }
  if(x) {
    sidl_BaseInterface_deleteRef((sidl_BaseInterface)x, _ex); SIDL_CHECK(*_ex);
    if(x_str) {free(x_str);}
  }
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_Apply__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* b_str = NULL;
  struct bHYPRE_Vector__object* b = NULL;
  char* x_str = NULL;
  struct bHYPRE_Vector__object* x_data = NULL;
  struct bHYPRE_Vector__object** x = &x_data;
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "b", &b_str, _ex);SIDL_CHECK(*_ex);
  b = skel_bHYPRE_SStructParCSRMatrix_fconnect_bHYPRE_Vector(b_str, TRUE, 
    _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackString( inArgs, "x", &x_str, _ex);SIDL_CHECK(*_ex);
  *x = skel_bHYPRE_SStructParCSRMatrix_fconnect_bHYPRE_Vector(x_str, FALSE, 
    _ex);SIDL_CHECK(*_ex);

  /* make the call */
  _retval = (self->d_epv->f_Apply)(
    self,
    b,
    x,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  if(*x){
    char* _url = sidl_BaseInterface__getURL((sidl_BaseInterface)*x, 
      _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Return_packString( outArgs, "x", _url, _ex);SIDL_CHECK(*_ex);
    free((void*)_url);
  } else {
    sidl_rmi_Return_packString( outArgs, "x", NULL, _ex);SIDL_CHECK(*_ex);
  }
  /* clean-up dangling references */
  if(b) {
    sidl_BaseInterface_deleteRef((sidl_BaseInterface)b, _ex); SIDL_CHECK(*_ex);
    if(b_str) {free(b_str);}
  }
  if(*x && sidl_BaseInterface__isRemote((sidl_BaseInterface)*x, _ex)) {
    (*((sidl_BaseInterface)*x)->d_epv->f__raddRef)(((
      sidl_BaseInterface)*x)->d_object, _ex); SIDL_CHECK(*_ex);
    sidl_BaseInterface_deleteRef((sidl_BaseInterface)*x, _ex); SIDL_CHECK(*_ex);
  }
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void
bHYPRE_SStructParCSRMatrix_ApplyAdjoint__exec(
        struct bHYPRE_SStructParCSRMatrix__object* self,
        struct sidl_rmi_Call__object* inArgs,
        struct sidl_rmi_Return__object* outArgs,
        struct sidl_BaseInterface__object ** _ex) {
  /* stack space for arguments */
  char* b_str = NULL;
  struct bHYPRE_Vector__object* b = NULL;
  char* x_str = NULL;
  struct bHYPRE_Vector__object* x_data = NULL;
  struct bHYPRE_Vector__object** x = &x_data;
  int32_t _retval = 0;
  sidl_BaseInterface _ex3   = NULL;
  sidl_BaseException _SIDLex = NULL;
  /* unpack in and inout argments */
  sidl_rmi_Call_unpackString( inArgs, "b", &b_str, _ex);SIDL_CHECK(*_ex);
  b = skel_bHYPRE_SStructParCSRMatrix_fconnect_bHYPRE_Vector(b_str, TRUE, 
    _ex);SIDL_CHECK(*_ex);
  sidl_rmi_Call_unpackString( inArgs, "x", &x_str, _ex);SIDL_CHECK(*_ex);
  *x = skel_bHYPRE_SStructParCSRMatrix_fconnect_bHYPRE_Vector(x_str, FALSE, 
    _ex);SIDL_CHECK(*_ex);

  /* make the call */
  _retval = (self->d_epv->f_ApplyAdjoint)(
    self,
    b,
    x,
    _ex);  SIDL_CHECK(*_ex);

  /* pack return value */
  sidl_rmi_Return_packInt( outArgs, "_retval", _retval, _ex);SIDL_CHECK(*_ex);
  /* pack out and inout argments */
  if(*x){
    char* _url = sidl_BaseInterface__getURL((sidl_BaseInterface)*x, 
      _ex);SIDL_CHECK(*_ex);
    sidl_rmi_Return_packString( outArgs, "x", _url, _ex);SIDL_CHECK(*_ex);
    free((void*)_url);
  } else {
    sidl_rmi_Return_packString( outArgs, "x", NULL, _ex);SIDL_CHECK(*_ex);
  }
  /* clean-up dangling references */
  if(b) {
    sidl_BaseInterface_deleteRef((sidl_BaseInterface)b, _ex); SIDL_CHECK(*_ex);
    if(b_str) {free(b_str);}
  }
  if(*x && sidl_BaseInterface__isRemote((sidl_BaseInterface)*x, _ex)) {
    (*((sidl_BaseInterface)*x)->d_epv->f__raddRef)(((
      sidl_BaseInterface)*x)->d_object, _ex); SIDL_CHECK(*_ex);
    sidl_BaseInterface_deleteRef((sidl_BaseInterface)*x, _ex); SIDL_CHECK(*_ex);
  }
  return;

  EXIT:
  _SIDLex = sidl_BaseException__cast(*_ex,&_ex3); EXEC_CHECK(_ex3);
  sidl_rmi_Return_throwException(outArgs, _SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseException_deleteRef(_SIDLex, &_ex3); EXEC_CHECK(_ex3);
  sidl_BaseInterface_deleteRef(*_ex, &_ex3); EXEC_CHECK(_ex3);
  *_ex = NULL;
  return;
  EXEC_ERR:
  {
    sidl_BaseInterface _throwaway = NULL;
    sidl_BaseInterface_deleteRef(_ex3, &_throwaway);
    return;
  }
}

static void ior_bHYPRE_SStructParCSRMatrix__ensure_load_called(void) {
  /*
   * assert( HAVE_LOCKED_STATIC_GLOBALS );
   */

  if (! s_load_called ) {
    bHYPRE_SStructParCSRMatrix__call_load();
    s_load_called=1;
  }
}

/* CAST: dynamic type casting support. */
static void* ior_bHYPRE_SStructParCSRMatrix__cast(
  struct bHYPRE_SStructParCSRMatrix__object* self,
  const char* name, sidl_BaseInterface* _ex)
{
  int
    cmp0,
    cmp1,
    cmp2,
    cmp3;
  void* cast = NULL;
  *_ex = NULL; /* default to no exception */
  cmp0 = strcmp(name, "bHYPRE.SStructMatrixView");
  if (!cmp0) {
    (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
    cast = &((*self).d_bhypre_sstructmatrixview);
    return cast;
  }
  else if (cmp0 < 0) {
    cmp1 = strcmp(name, "bHYPRE.ProblemDefinition");
    if (!cmp1) {
      (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
      cast = &((*self).d_bhypre_problemdefinition);
      return cast;
    }
    else if (cmp1 < 0) {
      cmp2 = strcmp(name, "bHYPRE.Operator");
      if (!cmp2) {
        (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
        cast = &((*self).d_bhypre_operator);
        return cast;
      }
      else if (cmp2 < 0) {
        cmp3 = strcmp(name, "bHYPRE.MatrixVectorView");
        if (!cmp3) {
          (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
          cast = &((*self).d_bhypre_matrixvectorview);
          return cast;
        }
      }
    }
    else if (cmp1 > 0) {
      cmp2 = strcmp(name, "bHYPRE.SStructMatrixVectorView");
      if (!cmp2) {
        (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
        cast = &((*self).d_bhypre_sstructmatrixvectorview);
        return cast;
      }
    }
  }
  else if (cmp0 > 0) {
    cmp1 = strcmp(name, "sidl.BaseClass");
    if (!cmp1) {
      (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
      cast = ((struct sidl_BaseClass__object*)self);
      return cast;
    }
    else if (cmp1 < 0) {
      cmp2 = strcmp(name, "bHYPRE.SStructParCSRMatrix");
      if (!cmp2) {
        (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
        cast = ((struct bHYPRE_SStructParCSRMatrix__object*)self);
        return cast;
      }
    }
    else if (cmp1 > 0) {
      cmp2 = strcmp(name, "sidl.BaseInterface");
      if (!cmp2) {
        (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
        cast = &((*self).d_sidl_baseclass.d_sidl_baseinterface);
        return cast;
      }
    }
  }
  return cast;
  EXIT:
  return NULL;
}

/*
 * HOOKS: set static hooks activation.
 */

static void ior_bHYPRE_SStructParCSRMatrix__set_hooks_static(
  int on, struct sidl_BaseInterface__object **_ex ) { 
  *_ex = NULL;
  /*
   * Nothing else to do since hooks support not needed.
   */

}

/*
 * HOOKS: set hooks activation.
 */

static void ior_bHYPRE_SStructParCSRMatrix__set_hooks(
  struct bHYPRE_SStructParCSRMatrix__object* self,
  int on, struct sidl_BaseInterface__object **_ex ) { 
  *_ex = NULL;
  /*
   * Nothing else to do since hooks support not needed.
   */

}

/*
 * DELETE: call destructor and free object memory.
 */

static void ior_bHYPRE_SStructParCSRMatrix__delete(
  struct bHYPRE_SStructParCSRMatrix__object* self, struct 
    sidl_BaseInterface__object **_ex)
{
  *_ex = NULL; /* default to no exception */
  bHYPRE_SStructParCSRMatrix__fini(self,_ex);
  memset((void*)self, 0, sizeof(struct bHYPRE_SStructParCSRMatrix__object));
  free((void*) self);
}

static char*
ior_bHYPRE_SStructParCSRMatrix__getURL(
    struct bHYPRE_SStructParCSRMatrix__object* self,
    struct sidl_BaseInterface__object **_ex) {
  char* ret = NULL;
  char* objid = sidl_rmi_InstanceRegistry_getInstanceByClass((
    sidl_BaseClass)self, _ex); SIDL_CHECK(*_ex);
  if(!objid) {
    objid = sidl_rmi_InstanceRegistry_registerInstance((sidl_BaseClass)self, 
      _ex); SIDL_CHECK(*_ex);
  }
  ret = sidl_rmi_ServerRegistry_getServerURL(objid, _ex); SIDL_CHECK(*_ex);
  return ret;
  EXIT:
  return NULL;
}
static void
ior_bHYPRE_SStructParCSRMatrix__raddRef(
    struct bHYPRE_SStructParCSRMatrix__object* self, sidl_BaseInterface* _ex) {
  sidl_BaseInterface_addRef((sidl_BaseInterface)self, _ex);
}

static sidl_bool
ior_bHYPRE_SStructParCSRMatrix__isRemote(
    struct bHYPRE_SStructParCSRMatrix__object* self, sidl_BaseInterface* _ex) {
  *_ex = NULL; /* default to no exception */
  return FALSE;
}

struct bHYPRE_SStructParCSRMatrix__method {
  const char *d_name;
  void (*d_func)(struct bHYPRE_SStructParCSRMatrix__object*,
    struct sidl_rmi_Call__object *,
    struct sidl_rmi_Return__object *,
    struct sidl_BaseInterface__object **);
};

static void
ior_bHYPRE_SStructParCSRMatrix__exec(
    struct bHYPRE_SStructParCSRMatrix__object* self,
    const char* methodName,
    struct sidl_rmi_Call__object* inArgs,
    struct sidl_rmi_Return__object* outArgs,
    struct sidl_BaseInterface__object **_ex ) { 
  static const struct bHYPRE_SStructParCSRMatrix__method  s_methods[] = {
    { "AddToBoxValues", bHYPRE_SStructParCSRMatrix_AddToBoxValues__exec },
    { "AddToValues", bHYPRE_SStructParCSRMatrix_AddToValues__exec },
    { "Apply", bHYPRE_SStructParCSRMatrix_Apply__exec },
    { "ApplyAdjoint", bHYPRE_SStructParCSRMatrix_ApplyAdjoint__exec },
    { "Assemble", bHYPRE_SStructParCSRMatrix_Assemble__exec },
    { "Destroy", bHYPRE_SStructParCSRMatrix_Destroy__exec },
    { "GetDoubleValue", bHYPRE_SStructParCSRMatrix_GetDoubleValue__exec },
    { "GetIntValue", bHYPRE_SStructParCSRMatrix_GetIntValue__exec },
    { "GetObject", bHYPRE_SStructParCSRMatrix_GetObject__exec },
    { "Initialize", bHYPRE_SStructParCSRMatrix_Initialize__exec },
    { "Print", bHYPRE_SStructParCSRMatrix_Print__exec },
    { "SetBoxValues", bHYPRE_SStructParCSRMatrix_SetBoxValues__exec },
    { "SetCommunicator", bHYPRE_SStructParCSRMatrix_SetCommunicator__exec },
    { "SetComplex", bHYPRE_SStructParCSRMatrix_SetComplex__exec },
    { "SetDoubleArray1Parameter", 
      bHYPRE_SStructParCSRMatrix_SetDoubleArray1Parameter__exec },
    { "SetDoubleArray2Parameter", 
      bHYPRE_SStructParCSRMatrix_SetDoubleArray2Parameter__exec },
    { "SetDoubleParameter", bHYPRE_SStructParCSRMatrix_SetDoubleParameter__exec 
      },
    { "SetGraph", bHYPRE_SStructParCSRMatrix_SetGraph__exec },
    { "SetIntArray1Parameter", 
      bHYPRE_SStructParCSRMatrix_SetIntArray1Parameter__exec },
    { "SetIntArray2Parameter", 
      bHYPRE_SStructParCSRMatrix_SetIntArray2Parameter__exec },
    { "SetIntParameter", bHYPRE_SStructParCSRMatrix_SetIntParameter__exec },
    { "SetNSSymmetric", bHYPRE_SStructParCSRMatrix_SetNSSymmetric__exec },
    { "SetStringParameter", bHYPRE_SStructParCSRMatrix_SetStringParameter__exec 
      },
    { "SetSymmetric", bHYPRE_SStructParCSRMatrix_SetSymmetric__exec },
    { "SetValues", bHYPRE_SStructParCSRMatrix_SetValues__exec },
    { "Setup", bHYPRE_SStructParCSRMatrix_Setup__exec },
    { "addRef", bHYPRE_SStructParCSRMatrix_addRef__exec },
    { "deleteRef", bHYPRE_SStructParCSRMatrix_deleteRef__exec },
    { "getClassInfo", bHYPRE_SStructParCSRMatrix_getClassInfo__exec },
    { "isSame", bHYPRE_SStructParCSRMatrix_isSame__exec },
    { "isType", bHYPRE_SStructParCSRMatrix_isType__exec }
  };
  int i, cmp, l = 0;
  int u = sizeof(s_methods)/sizeof(struct bHYPRE_SStructParCSRMatrix__method);
  *_ex = NULL; /* default to no exception */
  if (methodName) {
    /* Use binary search to locate method */
    while (l < u) {
      i = (l + u) >> 1;
      if (!(cmp=strcmp(methodName, s_methods[i].d_name))) {
        (s_methods[i].d_func)(self, inArgs, outArgs, _ex); SIDL_CHECK(*_ex);
        return;
      }
      else if (cmp < 0) u = i;
      else l = i + 1;
    }
  }
  /* TODO: add code for method not found */
  SIDL_THROW(*_ex,sidl_PreViolation,"method name not found");
  EXIT:
  return;
}
/*
 * EPV: create method entry point vector (EPV) structure.
 */

static void bHYPRE_SStructParCSRMatrix__init_epv(void)
{
/*
 * assert( HAVE_LOCKED_STATIC_GLOBALS );
 */

  struct bHYPRE_SStructParCSRMatrix__epv*     epv  = 
    &s_new_epv__bhypre_sstructparcsrmatrix;
  struct bHYPRE_SStructParCSRMatrix__epv*     hepv = 
    &s_new_epv_hooks__bhypre_sstructparcsrmatrix;
  struct bHYPRE_MatrixVectorView__epv*        e0   = 
    &s_new_epv__bhypre_matrixvectorview;
  struct bHYPRE_MatrixVectorView__epv*        he0  = 
    &s_new_epv_hooks__bhypre_matrixvectorview;
  struct bHYPRE_Operator__epv*                e1   = 
    &s_new_epv__bhypre_operator;
  struct bHYPRE_Operator__epv*                he1  = 
    &s_new_epv_hooks__bhypre_operator;
  struct bHYPRE_ProblemDefinition__epv*       e2   = 
    &s_new_epv__bhypre_problemdefinition;
  struct bHYPRE_ProblemDefinition__epv*       he2  = 
    &s_new_epv_hooks__bhypre_problemdefinition;
  struct bHYPRE_SStructMatrixVectorView__epv* e3   = 
    &s_new_epv__bhypre_sstructmatrixvectorview;
  struct bHYPRE_SStructMatrixVectorView__epv* he3  = 
    &s_new_epv_hooks__bhypre_sstructmatrixvectorview;
  struct bHYPRE_SStructMatrixView__epv*       e4   = 
    &s_new_epv__bhypre_sstructmatrixview;
  struct bHYPRE_SStructMatrixView__epv*       he4  = 
    &s_new_epv_hooks__bhypre_sstructmatrixview;
  struct sidl_BaseClass__epv*                 e5   = &s_new_epv__sidl_baseclass;
  struct sidl_BaseClass__epv*                 he5  = 
    &s_new_epv_hooks__sidl_baseclass;
  struct sidl_BaseInterface__epv*             e6   = 
    &s_new_epv__sidl_baseinterface;
  struct sidl_BaseInterface__epv*             he6  = 
    &s_new_epv_hooks__sidl_baseinterface;

  struct sidl_BaseClass__epv*             s1 = NULL;
  struct sidl_BaseClass__epv*             h1 = NULL;

  sidl_BaseClass__getEPVs(
    &s_old_epv__sidl_baseinterface,
    &s_old_epv_hooks__sidl_baseinterface,
    &s_old_epv__sidl_baseclass,&s_old_epv_hooks__sidl_baseclass);
  /*
   * Here we alias the static epvs to some handy small names
   */

  s1  =  s_old_epv__sidl_baseclass;
  h1  =  s_old_epv_hooks__sidl_baseclass;

  epv->f__cast                         = ior_bHYPRE_SStructParCSRMatrix__cast;
  epv->f__delete                       = ior_bHYPRE_SStructParCSRMatrix__delete;
  epv->f__exec                         = ior_bHYPRE_SStructParCSRMatrix__exec;
  epv->f__getURL                       = ior_bHYPRE_SStructParCSRMatrix__getURL;
  epv->f__raddRef                      = 
    ior_bHYPRE_SStructParCSRMatrix__raddRef;
  epv->f__isRemote                     = 
    ior_bHYPRE_SStructParCSRMatrix__isRemote;
  epv->f__set_hooks                    = 
    ior_bHYPRE_SStructParCSRMatrix__set_hooks;
  epv->f__ctor                         = NULL;
  epv->f__ctor2                        = NULL;
  epv->f__dtor                         = NULL;
  epv->f_addRef                        = (void (*)(struct 
    bHYPRE_SStructParCSRMatrix__object*,struct sidl_BaseInterface__object **)) 
    s1->f_addRef;
  epv->f_deleteRef                     = (void (*)(struct 
    bHYPRE_SStructParCSRMatrix__object*,struct sidl_BaseInterface__object **)) 
    s1->f_deleteRef;
  epv->f_isSame                        = (sidl_bool (*)(struct 
    bHYPRE_SStructParCSRMatrix__object*,struct sidl_BaseInterface__object*,
    struct sidl_BaseInterface__object **)) s1->f_isSame;
  epv->f_isType                        = (sidl_bool (*)(struct 
    bHYPRE_SStructParCSRMatrix__object*,const char*,struct 
    sidl_BaseInterface__object **)) s1->f_isType;
  epv->f_getClassInfo                  = (struct sidl_ClassInfo__object* (*)(
    struct bHYPRE_SStructParCSRMatrix__object*,struct 
    sidl_BaseInterface__object **)) s1->f_getClassInfo;
  epv->f_SetGraph                      = NULL;
  epv->f_SetValues                     = NULL;
  epv->f_SetBoxValues                  = NULL;
  epv->f_AddToValues                   = NULL;
  epv->f_AddToBoxValues                = NULL;
  epv->f_SetSymmetric                  = NULL;
  epv->f_SetNSSymmetric                = NULL;
  epv->f_SetComplex                    = NULL;
  epv->f_Print                         = NULL;
  epv->f_GetObject                     = NULL;
  epv->f_SetCommunicator               = NULL;
  epv->f_Destroy                       = NULL;
  epv->f_Initialize                    = NULL;
  epv->f_Assemble                      = NULL;
  epv->f_SetIntParameter               = NULL;
  epv->f_SetDoubleParameter            = NULL;
  epv->f_SetStringParameter            = NULL;
  epv->f_SetIntArray1Parameter         = NULL;
  epv->f_SetIntArray2Parameter         = NULL;
  epv->f_SetDoubleArray1Parameter      = NULL;
  epv->f_SetDoubleArray2Parameter      = NULL;
  epv->f_GetIntValue                   = NULL;
  epv->f_GetDoubleValue                = NULL;
  epv->f_Setup                         = NULL;
  epv->f_Apply                         = NULL;
  epv->f_ApplyAdjoint                  = NULL;

  bHYPRE_SStructParCSRMatrix__set_epv(epv);

  memcpy((void*)hepv, epv, sizeof(struct bHYPRE_SStructParCSRMatrix__epv));
  e0->f__cast               = (void* (*)(void*,const char*, struct 
    sidl_BaseInterface__object**)) epv->f__cast;
  e0->f__delete             = (void (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__delete;
  e0->f__getURL             = (char* (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__getURL;
  e0->f__raddRef            = (void (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__raddRef;
  e0->f__isRemote           = (sidl_bool (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__isRemote;
  e0->f__exec               = (void (*)(void*,const char*,struct 
    sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
    sidl_BaseInterface__object **)) epv->f__exec;
  e0->f_SetCommunicator     = (int32_t (*)(void*,struct 
    bHYPRE_MPICommunicator__object*,struct sidl_BaseInterface__object **)) 
    epv->f_SetCommunicator;
  e0->f_Destroy             = (void (*)(void*,struct sidl_BaseInterface__object 
    **)) epv->f_Destroy;
  e0->f_Initialize          = (int32_t (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_Initialize;
  e0->f_Assemble            = (int32_t (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_Assemble;
  e0->f_addRef              = (void (*)(void*,struct sidl_BaseInterface__object 
    **)) epv->f_addRef;
  e0->f_deleteRef           = (void (*)(void*,struct sidl_BaseInterface__object 
    **)) epv->f_deleteRef;
  e0->f_isSame              = (sidl_bool (*)(void*,struct 
    sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) 
    epv->f_isSame;
  e0->f_isType              = (sidl_bool (*)(void*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_isType;
  e0->f_getClassInfo        = (struct sidl_ClassInfo__object* (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_getClassInfo;

  memcpy((void*) he0, e0, sizeof(struct bHYPRE_MatrixVectorView__epv));

  e1->f__cast                    = (void* (*)(void*,const char*, struct 
    sidl_BaseInterface__object**)) epv->f__cast;
  e1->f__delete                  = (void (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__delete;
  e1->f__getURL                  = (char* (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__getURL;
  e1->f__raddRef                 = (void (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__raddRef;
  e1->f__isRemote                = (sidl_bool (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__isRemote;
  e1->f__exec                    = (void (*)(void*,const char*,struct 
    sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
    sidl_BaseInterface__object **)) epv->f__exec;
  e1->f_SetCommunicator          = (int32_t (*)(void*,struct 
    bHYPRE_MPICommunicator__object*,struct sidl_BaseInterface__object **)) 
    epv->f_SetCommunicator;
  e1->f_Destroy                  = (void (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_Destroy;
  e1->f_SetIntParameter          = (int32_t (*)(void*,const char*,int32_t,
    struct sidl_BaseInterface__object **)) epv->f_SetIntParameter;
  e1->f_SetDoubleParameter       = (int32_t (*)(void*,const char*,double,struct 
    sidl_BaseInterface__object **)) epv->f_SetDoubleParameter;
  e1->f_SetStringParameter       = (int32_t (*)(void*,const char*,const char*,
    struct sidl_BaseInterface__object **)) epv->f_SetStringParameter;
  e1->f_SetIntArray1Parameter    = (int32_t (*)(void*,const char*,struct 
    sidl_int__array*,struct sidl_BaseInterface__object **)) 
    epv->f_SetIntArray1Parameter;
  e1->f_SetIntArray2Parameter    = (int32_t (*)(void*,const char*,struct 
    sidl_int__array*,struct sidl_BaseInterface__object **)) 
    epv->f_SetIntArray2Parameter;
  e1->f_SetDoubleArray1Parameter = (int32_t (*)(void*,const char*,struct 
    sidl_double__array*,struct sidl_BaseInterface__object **)) 
    epv->f_SetDoubleArray1Parameter;
  e1->f_SetDoubleArray2Parameter = (int32_t (*)(void*,const char*,struct 
    sidl_double__array*,struct sidl_BaseInterface__object **)) 
    epv->f_SetDoubleArray2Parameter;
  e1->f_GetIntValue              = (int32_t (*)(void*,const char*,int32_t*,
    struct sidl_BaseInterface__object **)) epv->f_GetIntValue;
  e1->f_GetDoubleValue           = (int32_t (*)(void*,const char*,double*,
    struct sidl_BaseInterface__object **)) epv->f_GetDoubleValue;
  e1->f_Setup                    = (int32_t (*)(void*,struct 
    bHYPRE_Vector__object*,struct bHYPRE_Vector__object*,struct 
    sidl_BaseInterface__object **)) epv->f_Setup;
  e1->f_Apply                    = (int32_t (*)(void*,struct 
    bHYPRE_Vector__object*,struct bHYPRE_Vector__object**,struct 
    sidl_BaseInterface__object **)) epv->f_Apply;
  e1->f_ApplyAdjoint             = (int32_t (*)(void*,struct 
    bHYPRE_Vector__object*,struct bHYPRE_Vector__object**,struct 
    sidl_BaseInterface__object **)) epv->f_ApplyAdjoint;
  e1->f_addRef                   = (void (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_addRef;
  e1->f_deleteRef                = (void (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_deleteRef;
  e1->f_isSame                   = (sidl_bool (*)(void*,struct 
    sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) 
    epv->f_isSame;
  e1->f_isType                   = (sidl_bool (*)(void*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_isType;
  e1->f_getClassInfo             = (struct sidl_ClassInfo__object* (*)(void*,
    struct sidl_BaseInterface__object **)) epv->f_getClassInfo;

  memcpy((void*) he1, e1, sizeof(struct bHYPRE_Operator__epv));

  e2->f__cast               = (void* (*)(void*,const char*, struct 
    sidl_BaseInterface__object**)) epv->f__cast;
  e2->f__delete             = (void (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__delete;
  e2->f__getURL             = (char* (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__getURL;
  e2->f__raddRef            = (void (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__raddRef;
  e2->f__isRemote           = (sidl_bool (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__isRemote;
  e2->f__exec               = (void (*)(void*,const char*,struct 
    sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
    sidl_BaseInterface__object **)) epv->f__exec;
  e2->f_SetCommunicator     = (int32_t (*)(void*,struct 
    bHYPRE_MPICommunicator__object*,struct sidl_BaseInterface__object **)) 
    epv->f_SetCommunicator;
  e2->f_Destroy             = (void (*)(void*,struct sidl_BaseInterface__object 
    **)) epv->f_Destroy;
  e2->f_Initialize          = (int32_t (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_Initialize;
  e2->f_Assemble            = (int32_t (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_Assemble;
  e2->f_addRef              = (void (*)(void*,struct sidl_BaseInterface__object 
    **)) epv->f_addRef;
  e2->f_deleteRef           = (void (*)(void*,struct sidl_BaseInterface__object 
    **)) epv->f_deleteRef;
  e2->f_isSame              = (sidl_bool (*)(void*,struct 
    sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) 
    epv->f_isSame;
  e2->f_isType              = (sidl_bool (*)(void*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_isType;
  e2->f_getClassInfo        = (struct sidl_ClassInfo__object* (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_getClassInfo;

  memcpy((void*) he2, e2, sizeof(struct bHYPRE_ProblemDefinition__epv));

  e3->f__cast               = (void* (*)(void*,const char*, struct 
    sidl_BaseInterface__object**)) epv->f__cast;
  e3->f__delete             = (void (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__delete;
  e3->f__getURL             = (char* (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__getURL;
  e3->f__raddRef            = (void (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__raddRef;
  e3->f__isRemote           = (sidl_bool (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__isRemote;
  e3->f__exec               = (void (*)(void*,const char*,struct 
    sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
    sidl_BaseInterface__object **)) epv->f__exec;
  e3->f_GetObject           = (int32_t (*)(void*,struct 
    sidl_BaseInterface__object**,struct sidl_BaseInterface__object **)) 
    epv->f_GetObject;
  e3->f_SetCommunicator     = (int32_t (*)(void*,struct 
    bHYPRE_MPICommunicator__object*,struct sidl_BaseInterface__object **)) 
    epv->f_SetCommunicator;
  e3->f_Destroy             = (void (*)(void*,struct sidl_BaseInterface__object 
    **)) epv->f_Destroy;
  e3->f_Initialize          = (int32_t (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_Initialize;
  e3->f_Assemble            = (int32_t (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_Assemble;
  e3->f_addRef              = (void (*)(void*,struct sidl_BaseInterface__object 
    **)) epv->f_addRef;
  e3->f_deleteRef           = (void (*)(void*,struct sidl_BaseInterface__object 
    **)) epv->f_deleteRef;
  e3->f_isSame              = (sidl_bool (*)(void*,struct 
    sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) 
    epv->f_isSame;
  e3->f_isType              = (sidl_bool (*)(void*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_isType;
  e3->f_getClassInfo        = (struct sidl_ClassInfo__object* (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_getClassInfo;

  memcpy((void*) he3, e3, sizeof(struct bHYPRE_SStructMatrixVectorView__epv));

  e4->f__cast               = (void* (*)(void*,const char*, struct 
    sidl_BaseInterface__object**)) epv->f__cast;
  e4->f__delete             = (void (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__delete;
  e4->f__getURL             = (char* (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__getURL;
  e4->f__raddRef            = (void (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__raddRef;
  e4->f__isRemote           = (sidl_bool (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__isRemote;
  e4->f__exec               = (void (*)(void*,const char*,struct 
    sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
    sidl_BaseInterface__object **)) epv->f__exec;
  e4->f_SetGraph            = (int32_t (*)(void*,struct 
    bHYPRE_SStructGraph__object*,struct sidl_BaseInterface__object **)) 
    epv->f_SetGraph;
  e4->f_SetValues           = (int32_t (*)(void*,int32_t,struct 
    sidl_int__array*,int32_t,struct sidl_int__array*,struct sidl_double__array*,
    struct sidl_BaseInterface__object **)) epv->f_SetValues;
  e4->f_SetBoxValues        = (int32_t (*)(void*,int32_t,struct 
    sidl_int__array*,struct sidl_int__array*,int32_t,struct sidl_int__array*,
    struct sidl_double__array*,struct sidl_BaseInterface__object **)) 
    epv->f_SetBoxValues;
  e4->f_AddToValues         = (int32_t (*)(void*,int32_t,struct 
    sidl_int__array*,int32_t,struct sidl_int__array*,struct sidl_double__array*,
    struct sidl_BaseInterface__object **)) epv->f_AddToValues;
  e4->f_AddToBoxValues      = (int32_t (*)(void*,int32_t,struct 
    sidl_int__array*,struct sidl_int__array*,int32_t,struct sidl_int__array*,
    struct sidl_double__array*,struct sidl_BaseInterface__object **)) 
    epv->f_AddToBoxValues;
  e4->f_SetSymmetric        = (int32_t (*)(void*,int32_t,int32_t,int32_t,
    int32_t,struct sidl_BaseInterface__object **)) epv->f_SetSymmetric;
  e4->f_SetNSSymmetric      = (int32_t (*)(void*,int32_t,struct 
    sidl_BaseInterface__object **)) epv->f_SetNSSymmetric;
  e4->f_SetComplex          = (int32_t (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_SetComplex;
  e4->f_Print               = (int32_t (*)(void*,const char*,int32_t,struct 
    sidl_BaseInterface__object **)) epv->f_Print;
  e4->f_GetObject           = (int32_t (*)(void*,struct 
    sidl_BaseInterface__object**,struct sidl_BaseInterface__object **)) 
    epv->f_GetObject;
  e4->f_SetCommunicator     = (int32_t (*)(void*,struct 
    bHYPRE_MPICommunicator__object*,struct sidl_BaseInterface__object **)) 
    epv->f_SetCommunicator;
  e4->f_Destroy             = (void (*)(void*,struct sidl_BaseInterface__object 
    **)) epv->f_Destroy;
  e4->f_Initialize          = (int32_t (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_Initialize;
  e4->f_Assemble            = (int32_t (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_Assemble;
  e4->f_addRef              = (void (*)(void*,struct sidl_BaseInterface__object 
    **)) epv->f_addRef;
  e4->f_deleteRef           = (void (*)(void*,struct sidl_BaseInterface__object 
    **)) epv->f_deleteRef;
  e4->f_isSame              = (sidl_bool (*)(void*,struct 
    sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) 
    epv->f_isSame;
  e4->f_isType              = (sidl_bool (*)(void*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_isType;
  e4->f_getClassInfo        = (struct sidl_ClassInfo__object* (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_getClassInfo;

  memcpy((void*) he4, e4, sizeof(struct bHYPRE_SStructMatrixView__epv));

  e5->f__cast               = (void* (*)(struct sidl_BaseClass__object*,const 
    char*, struct sidl_BaseInterface__object**)) epv->f__cast;
  e5->f__delete             = (void (*)(struct sidl_BaseClass__object*, struct 
    sidl_BaseInterface__object **)) epv->f__delete;
  e5->f__getURL             = (char* (*)(struct sidl_BaseClass__object*, struct 
    sidl_BaseInterface__object **)) epv->f__getURL;
  e5->f__raddRef            = (void (*)(struct sidl_BaseClass__object*, struct 
    sidl_BaseInterface__object **)) epv->f__raddRef;
  e5->f__isRemote           = (sidl_bool (*)(struct sidl_BaseClass__object*, 
    struct sidl_BaseInterface__object **)) epv->f__isRemote;
  e5->f__exec               = (void (*)(struct sidl_BaseClass__object*,const 
    char*,struct sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
    sidl_BaseInterface__object **)) epv->f__exec;
  e5->f_addRef              = (void (*)(struct sidl_BaseClass__object*,struct 
    sidl_BaseInterface__object **)) epv->f_addRef;
  e5->f_deleteRef           = (void (*)(struct sidl_BaseClass__object*,struct 
    sidl_BaseInterface__object **)) epv->f_deleteRef;
  e5->f_isSame              = (sidl_bool (*)(struct sidl_BaseClass__object*,
    struct sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) 
    epv->f_isSame;
  e5->f_isType              = (sidl_bool (*)(struct sidl_BaseClass__object*,
    const char*,struct sidl_BaseInterface__object **)) epv->f_isType;
  e5->f_getClassInfo        = (struct sidl_ClassInfo__object* (*)(struct 
    sidl_BaseClass__object*,struct sidl_BaseInterface__object **)) 
    epv->f_getClassInfo;

  memcpy((void*) he5, e5, sizeof(struct sidl_BaseClass__epv));

  e6->f__cast               = (void* (*)(void*,const char*, struct 
    sidl_BaseInterface__object**)) epv->f__cast;
  e6->f__delete             = (void (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__delete;
  e6->f__getURL             = (char* (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__getURL;
  e6->f__raddRef            = (void (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__raddRef;
  e6->f__isRemote           = (sidl_bool (*)(void*, struct 
    sidl_BaseInterface__object **)) epv->f__isRemote;
  e6->f__exec               = (void (*)(void*,const char*,struct 
    sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
    sidl_BaseInterface__object **)) epv->f__exec;
  e6->f_addRef              = (void (*)(void*,struct sidl_BaseInterface__object 
    **)) epv->f_addRef;
  e6->f_deleteRef           = (void (*)(void*,struct sidl_BaseInterface__object 
    **)) epv->f_deleteRef;
  e6->f_isSame              = (sidl_bool (*)(void*,struct 
    sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) 
    epv->f_isSame;
  e6->f_isType              = (sidl_bool (*)(void*,const char*,struct 
    sidl_BaseInterface__object **)) epv->f_isType;
  e6->f_getClassInfo        = (struct sidl_ClassInfo__object* (*)(void*,struct 
    sidl_BaseInterface__object **)) epv->f_getClassInfo;

  memcpy((void*) he6, e6, sizeof(struct sidl_BaseInterface__epv));

  s_method_initialized = 1;
  ior_bHYPRE_SStructParCSRMatrix__ensure_load_called();
}

/*
 * SEPV: create the static entry point vector (SEPV).
 */

static void bHYPRE_SStructParCSRMatrix__init_sepv(void)
{
  /*
   * assert( HAVE_LOCKED_STATIC_GLOBALS );
   */

  struct sidl_BaseInterface__object *throwaway_exception = NULL;
  struct bHYPRE_SStructParCSRMatrix__sepv*  s = 
    &s_stc_epv__bhypre_sstructparcsrmatrix;
  struct bHYPRE_SStructParCSRMatrix__sepv* hs = 
    &s_stc_epv_hooks__bhypre_sstructparcsrmatrix;

  s->f__set_hooks_static                       = 
    ior_bHYPRE_SStructParCSRMatrix__set_hooks_static;
  s->f_Create         = NULL;

  bHYPRE_SStructParCSRMatrix__set_sepv(s);

  memcpy((void*)hs, s, sizeof(struct bHYPRE_SStructParCSRMatrix__sepv));

  ior_bHYPRE_SStructParCSRMatrix__set_hooks_static(FALSE, &throwaway_exception);
  s_static_initialized = 1;
  ior_bHYPRE_SStructParCSRMatrix__ensure_load_called();
}

void bHYPRE_SStructParCSRMatrix__getEPVs(
  struct sidl_BaseInterface__epv **s_arg_epv__sidl_baseinterface,
  struct sidl_BaseInterface__epv **s_arg_epv_hooks__sidl_baseinterface,
  struct sidl_BaseClass__epv **s_arg_epv__sidl_baseclass,struct 
    sidl_BaseClass__epv **s_arg_epv_hooks__sidl_baseclass,
  struct bHYPRE_MatrixVectorView__epv **s_arg_epv__bhypre_matrixvectorview,
  struct bHYPRE_MatrixVectorView__epv 
    **s_arg_epv_hooks__bhypre_matrixvectorview,
  struct bHYPRE_Operator__epv **s_arg_epv__bhypre_operator,
  struct bHYPRE_Operator__epv **s_arg_epv_hooks__bhypre_operator,
  struct bHYPRE_ProblemDefinition__epv **s_arg_epv__bhypre_problemdefinition,
  struct bHYPRE_ProblemDefinition__epv 
    **s_arg_epv_hooks__bhypre_problemdefinition,
  struct bHYPRE_SStructMatrixVectorView__epv 
    **s_arg_epv__bhypre_sstructmatrixvectorview,
  struct bHYPRE_SStructMatrixVectorView__epv 
    **s_arg_epv_hooks__bhypre_sstructmatrixvectorview,
  struct bHYPRE_SStructMatrixView__epv **s_arg_epv__bhypre_sstructmatrixview,
  struct bHYPRE_SStructMatrixView__epv 
    **s_arg_epv_hooks__bhypre_sstructmatrixview,
  struct bHYPRE_SStructParCSRMatrix__epv 
    **s_arg_epv__bhypre_sstructparcsrmatrix,struct 
    bHYPRE_SStructParCSRMatrix__epv 
    **s_arg_epv_hooks__bhypre_sstructparcsrmatrix)
{
  LOCK_STATIC_GLOBALS;
  if (!s_method_initialized) {
    bHYPRE_SStructParCSRMatrix__init_epv();
  }
  UNLOCK_STATIC_GLOBALS;

  *s_arg_epv__sidl_baseinterface = &s_new_epv__sidl_baseinterface;
  *s_arg_epv_hooks__sidl_baseinterface = &s_new_epv_hooks__sidl_baseinterface;
  *s_arg_epv__sidl_baseclass = &s_new_epv__sidl_baseclass;
  *s_arg_epv_hooks__sidl_baseclass = &s_new_epv_hooks__sidl_baseclass;
  *s_arg_epv__bhypre_matrixvectorview = &s_new_epv__bhypre_matrixvectorview;
  *s_arg_epv_hooks__bhypre_matrixvectorview = 
    &s_new_epv_hooks__bhypre_matrixvectorview;
  *s_arg_epv__bhypre_operator = &s_new_epv__bhypre_operator;
  *s_arg_epv_hooks__bhypre_operator = &s_new_epv_hooks__bhypre_operator;
  *s_arg_epv__bhypre_problemdefinition = &s_new_epv__bhypre_problemdefinition;
  *s_arg_epv_hooks__bhypre_problemdefinition = 
    &s_new_epv_hooks__bhypre_problemdefinition;
  *s_arg_epv__bhypre_sstructmatrixvectorview = 
    &s_new_epv__bhypre_sstructmatrixvectorview;
  *s_arg_epv_hooks__bhypre_sstructmatrixvectorview = 
    &s_new_epv_hooks__bhypre_sstructmatrixvectorview;
  *s_arg_epv__bhypre_sstructmatrixview = &s_new_epv__bhypre_sstructmatrixview;
  *s_arg_epv_hooks__bhypre_sstructmatrixview = 
    &s_new_epv_hooks__bhypre_sstructmatrixview;
  *s_arg_epv__bhypre_sstructparcsrmatrix = 
    &s_new_epv__bhypre_sstructparcsrmatrix;
  *s_arg_epv_hooks__bhypre_sstructparcsrmatrix = 
    &s_new_epv_hooks__bhypre_sstructparcsrmatrix;
}
/*
 * STATIC: return pointer to static EPV structure.
 */

struct bHYPRE_SStructParCSRMatrix__sepv*
bHYPRE_SStructParCSRMatrix__statics(void)
{
  LOCK_STATIC_GLOBALS;
  if (!s_static_initialized) {
    bHYPRE_SStructParCSRMatrix__init_sepv();
  }
  UNLOCK_STATIC_GLOBALS;
  return &s_stc_epv__bhypre_sstructparcsrmatrix;
}

/*
 * SUPER: returns parent's non-overrided EPV
 */

static struct sidl_BaseClass__epv* bHYPRE_SStructParCSRMatrix__super(void) {
  return s_old_epv__sidl_baseclass;
}

/*
 * initClassInfo: create a ClassInfo interface if necessary.
 */

static void
initClassInfo(sidl_ClassInfo *info, struct sidl_BaseInterface__object **_ex)
{
  LOCK_STATIC_GLOBALS;
  *_ex = NULL; /* default to no exception */
  if (!s_classInfo) {
    sidl_ClassInfoI impl;
    impl = sidl_ClassInfoI__create(_ex);
    s_classInfo = sidl_ClassInfo__cast(impl,_ex);
    if (impl) {
      sidl_ClassInfoI_setName(impl, "bHYPRE.SStructParCSRMatrix",_ex);
      sidl_ClassInfoI_setIORVersion(impl, s_IOR_MAJOR_VERSION, 
        s_IOR_MINOR_VERSION,_ex);
      sidl_ClassInfoI_deleteRef(impl,_ex);
      sidl_atexit(sidl_deleteRef_atexit, &s_classInfo);
    }
  }
  UNLOCK_STATIC_GLOBALS;
  if (s_classInfo) {
    if (*info) {
      sidl_ClassInfo_deleteRef(*info,_ex);
    }
    *info = s_classInfo;
    sidl_ClassInfo_addRef(*info,_ex);
  }
}

/*
 * initMetadata: store IOR version & class in sidl.BaseClass's data
 */

static void
initMetadata(struct bHYPRE_SStructParCSRMatrix__object* self, 
  sidl_BaseInterface* _ex)
{
  *_ex = 0; /* default no exception */
  if (self) {
    struct sidl_BaseClass__data *data = (struct sidl_BaseClass__data*)((
      *self).d_sidl_baseclass.d_data);
    if (data) {
      data->d_IOR_major_version = s_IOR_MAJOR_VERSION;
      data->d_IOR_minor_version = s_IOR_MINOR_VERSION;
      initClassInfo(&(data->d_classinfo),_ex); SIDL_CHECK(*_ex);
    }
  }
EXIT:
return;
}

/*
 * NEW: allocate object and initialize it.
 */

struct bHYPRE_SStructParCSRMatrix__object*
bHYPRE_SStructParCSRMatrix__new(void* ddata, struct sidl_BaseInterface__object 
  ** _ex)
{
  struct bHYPRE_SStructParCSRMatrix__object* self =
    (struct bHYPRE_SStructParCSRMatrix__object*) malloc(
      sizeof(struct bHYPRE_SStructParCSRMatrix__object));
  *_ex = NULL; /* default to no exception */
  bHYPRE_SStructParCSRMatrix__init(self, ddata, _ex); SIDL_CHECK(*_ex);
  initMetadata(self, _ex); SIDL_CHECK(*_ex);
  return self;
  EXIT:
  return NULL;
}

/*
 * INIT: initialize a new instance of the class object.
 */

void bHYPRE_SStructParCSRMatrix__init(
  struct bHYPRE_SStructParCSRMatrix__object* self,
   void* ddata,
  struct sidl_BaseInterface__object **_ex)
{
  struct bHYPRE_SStructParCSRMatrix__object* s0 = self;
  struct sidl_BaseClass__object*             s1 = &s0->d_sidl_baseclass;

  *_ex = 0; /* default no exception */
  LOCK_STATIC_GLOBALS;
  if (!s_method_initialized) {
    bHYPRE_SStructParCSRMatrix__init_epv();
  }
  UNLOCK_STATIC_GLOBALS;

  sidl_BaseClass__init(s1, NULL, _ex); SIDL_CHECK(*_ex);

  s1->d_sidl_baseinterface.d_epv = &s_new_epv__sidl_baseinterface;
  s1->d_epv                      = &s_new_epv__sidl_baseclass;

  s0->d_bhypre_matrixvectorview.d_epv        = 
    &s_new_epv__bhypre_matrixvectorview;
  s0->d_bhypre_operator.d_epv                = &s_new_epv__bhypre_operator;
  s0->d_bhypre_problemdefinition.d_epv       = 
    &s_new_epv__bhypre_problemdefinition;
  s0->d_bhypre_sstructmatrixvectorview.d_epv = 
    &s_new_epv__bhypre_sstructmatrixvectorview;
  s0->d_bhypre_sstructmatrixview.d_epv       = 
    &s_new_epv__bhypre_sstructmatrixview;
  s0->d_epv                                  = 
    &s_new_epv__bhypre_sstructparcsrmatrix;

  s0->d_bhypre_matrixvectorview.d_object = self;

  s0->d_bhypre_operator.d_object = self;

  s0->d_bhypre_problemdefinition.d_object = self;

  s0->d_bhypre_sstructmatrixvectorview.d_object = self;

  s0->d_bhypre_sstructmatrixview.d_object = self;

  s0->d_data = NULL;

  ior_bHYPRE_SStructParCSRMatrix__set_hooks(s0, FALSE, _ex);

  if(ddata) {
    self->d_data = ddata;
    (*(self->d_epv->f__ctor2))(self,ddata,_ex); SIDL_CHECK(*_ex);
  } else { 
    (*(self->d_epv->f__ctor))(self,_ex); SIDL_CHECK(*_ex);
  }
  EXIT:
  return;
}

/*
 * FINI: deallocate a class instance (destructor).
 */

void bHYPRE_SStructParCSRMatrix__fini(
  struct bHYPRE_SStructParCSRMatrix__object* self,
  struct sidl_BaseInterface__object **_ex)
{
  struct bHYPRE_SStructParCSRMatrix__object* s0 = self;
  struct sidl_BaseClass__object*             s1 = &s0->d_sidl_baseclass;

  *_ex = NULL; /* default to no exception */
  (*(s0->d_epv->f__dtor))(s0,_ex);
  SIDL_CHECK(*_ex);

  s1->d_sidl_baseinterface.d_epv = s_old_epv__sidl_baseinterface;
  s1->d_epv                      = s_old_epv__sidl_baseclass;

  sidl_BaseClass__fini(s1, _ex); SIDL_CHECK(*_ex);
  EXIT:
  return;
}

/*
 * VERSION: Return the version of the IOR used to generate this IOR.
 */

void
bHYPRE_SStructParCSRMatrix__IOR_version(int32_t *major, int32_t *minor)
{
  *major = s_IOR_MAJOR_VERSION;
  *minor = s_IOR_MINOR_VERSION;
}

static const struct bHYPRE_SStructParCSRMatrix__external
s_externalEntryPoints = {
  bHYPRE_SStructParCSRMatrix__new,
  bHYPRE_SStructParCSRMatrix__statics,
  bHYPRE_SStructParCSRMatrix__super,
  1, 
  0
};

/*
 * This function returns a pointer to a static structure of
 * pointers to function entry points.  Its purpose is to provide
 * one-stop shopping for loading DLLs.
 */

const struct bHYPRE_SStructParCSRMatrix__external*
bHYPRE_SStructParCSRMatrix__externals(void)
{
  return &s_externalEntryPoints;
}

