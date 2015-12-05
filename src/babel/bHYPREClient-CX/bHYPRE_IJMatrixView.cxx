// 
// File:          bHYPRE_IJMatrixView.cxx
// Symbol:        bHYPRE.IJMatrixView-v1.0.0
// Symbol Type:   interface
// Babel Version: 1.0.4
// Description:   Client-side glue code for bHYPRE.IJMatrixView
// 
// WARNING: Automatically generated; changes will be lost
// 
// 

#ifndef included_bHYPRE_IJMatrixView_hxx
#include "bHYPRE_IJMatrixView.hxx"
#endif
#ifndef included_sidl_BaseInterface_hxx
#include "sidl_BaseInterface.hxx"
#endif
#ifndef included_sidl_BaseClass_hxx
#include "sidl_BaseClass.hxx"
#endif
#ifndef included_sidl_BaseException_hxx
#include "sidl_BaseException.hxx"
#endif
#ifndef included_sidl_LangSpecificException_hxx
#include "sidl_LangSpecificException.hxx"
#endif
#ifndef included_sidl_RuntimeException_hxx
#include "sidl_RuntimeException.hxx"
#endif
#ifndef included_sidl_rmi_Call_hxx
#include "sidl_rmi_Call.hxx"
#endif
#ifndef included_sidl_rmi_Return_hxx
#include "sidl_rmi_Return.hxx"
#endif
#ifndef included_sidl_rmi_Ticket_hxx
#include "sidl_rmi_Ticket.hxx"
#endif
#ifndef included_sidl_rmi_InstanceHandle_hxx
#include "sidl_rmi_InstanceHandle.hxx"
#endif
#include "sidl_String.h"
#include "sidl_rmi_ConnectRegistry.h"
#include "babel_config.h"
#ifdef SIDL_DYNAMIC_LIBRARY
#include <stdio.h>
#include <stdlib.h>
#include "sidl_Loader.hxx"
#include "sidl_DLL.hxx"
#endif
// 
// Includes for all method dependencies.
// 
#ifndef included_bHYPRE_MPICommunicator_hxx
#include "bHYPRE_MPICommunicator.hxx"
#endif
#ifndef included_sidl_BaseInterface_hxx
#include "sidl_BaseInterface.hxx"
#endif
#ifndef included_sidl_ClassInfo_hxx
#include "sidl_ClassInfo.hxx"
#endif

#define LANG_SPECIFIC_INIT()
// 
// connect_loaded is a boolean value showing if the IHConnect for this object has been loaded into the connectRegistry
// 
static int connect_loaded = 0;
extern "C" {
#include <stdlib.h>
#include <string.h>
#ifndef included_sidl_BaseClass_h
#include "sidl_BaseClass.h"
#endif
#ifndef included_sidl_ClassInfo_h
#include "sidl_ClassInfo.h"
#endif
#ifndef included_sidl_rmi_ProtocolFactory_h
#include "sidl_rmi_ProtocolFactory.h"
#endif
#ifndef included_sidl_rmi_InstanceRegistry_h
#include "sidl_rmi_InstanceRegistry.h"
#endif
#ifndef included_sidl_rmi_InstanceHandle_h
#include "sidl_rmi_InstanceHandle.h"
#endif
#ifndef included_sidl_rmi_Invocation_h
#include "sidl_rmi_Invocation.h"
#endif
#ifndef included_sidl_rmi_Response_h
#include "sidl_rmi_Response.h"
#endif
#ifndef included_sidl_rmi_ServerRegistry_h
#include "sidl_rmi_ServerRegistry.h"
#endif
#ifndef included_sidl_rmi_ConnectRegistry_h
#include "sidl_rmi_ConnectRegistry.h"
#endif
#ifndef included_sidl_io_Serializable_h
#include "sidl_io_Serializable.h"
#endif
#include "sidl_Exception.h"

#ifndef NULL
#define NULL 0
#endif

#include "sidl_thread.h"
#ifdef HAVE_PTHREAD
static struct sidl_recursive_mutex_t bHYPRE__IJMatrixView__mutex= SIDL_RECURSIVE_MUTEX_INITIALIZER;
#define LOCK_STATIC_GLOBALS sidl_recursive_mutex_lock( &bHYPRE__IJMatrixView__mutex )
#define UNLOCK_STATIC_GLOBALS sidl_recursive_mutex_unlock( &bHYPRE__IJMatrixView__mutex )
/* #define HAVE_LOCKED_STATIC_GLOBALS (sidl_recursive_mutex_trylock( &bHYPRE__IJMatrixView__mutex )==EDEADLOCK) */
#else
#define LOCK_STATIC_GLOBALS
#define UNLOCK_STATIC_GLOBALS
/* #define HAVE_LOCKED_STATIC_GLOBALS (1) */
#endif

  // Static variables to hold version of IOR
  static const int32_t s_IOR_MAJOR_VERSION = 1;
  static const int32_t s_IOR_MINOR_VERSION = 0;

  // Static variables for managing EPV initialization.
  static int s_remote_initialized = 0;

  static struct bHYPRE__IJMatrixView__epv s_rem_epv__bhypre__ijmatrixview;

  static struct bHYPRE_IJMatrixView__epv s_rem_epv__bhypre_ijmatrixview;

  static struct bHYPRE_MatrixVectorView__epv s_rem_epv__bhypre_matrixvectorview;

  static struct bHYPRE_ProblemDefinition__epv 
    s_rem_epv__bhypre_problemdefinition;

  static struct sidl_BaseInterface__epv s_rem_epv__sidl_baseinterface;


  // REMOTE CAST: dynamic type casting for remote objects.
  static void* remote_bHYPRE__IJMatrixView__cast(
    struct bHYPRE__IJMatrixView__object* self,
    const char* name, sidl_BaseInterface* _ex)
  {
    int
      cmp0,
      cmp1,
      cmp2;
    void* cast = NULL;
    *_ex = NULL; /* default to no exception */
    cmp0 = strcmp(name, "bHYPRE.ProblemDefinition");
    if (!cmp0) {
      (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
      cast = &((*self).d_bhypre_problemdefinition);
      return cast;
    }
    else if (cmp0 < 0) {
      cmp1 = strcmp(name, "bHYPRE.MatrixVectorView");
      if (!cmp1) {
        (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
        cast = &((*self).d_bhypre_matrixvectorview);
        return cast;
      }
      else if (cmp1 < 0) {
        cmp2 = strcmp(name, "bHYPRE.IJMatrixView");
        if (!cmp2) {
          (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
          cast = &((*self).d_bhypre_ijmatrixview);
          return cast;
        }
      }
    }
    else if (cmp0 > 0) {
      cmp1 = strcmp(name, "sidl.BaseInterface");
      if (!cmp1) {
        (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
        cast = &((*self).d_sidl_baseinterface);
        return cast;
      }
      else if (cmp1 < 0) {
        cmp2 = strcmp(name, "bHYPRE._IJMatrixView");
        if (!cmp2) {
          (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
          cast = ((struct bHYPRE__IJMatrixView__object*)self);
          return cast;
        }
      }
    }
    if ((*self->d_epv->f_isType)(self,name, _ex)) {
      void* (*func)(struct sidl_rmi_InstanceHandle__object*, struct 
        sidl_BaseInterface__object**) = 
        (void* (*)(struct sidl_rmi_InstanceHandle__object*, struct 
          sidl_BaseInterface__object**)) 
        sidl_rmi_ConnectRegistry_getConnect(name, _ex);SIDL_CHECK(*_ex);
      cast =  (*func)(((struct 
        bHYPRE__IJMatrixView__remote*)self->d_data)->d_ih, _ex);
    }

    return cast;
    EXIT:
    return NULL;
  }

  // REMOTE DELETE: call the remote destructor for the object.
  static void remote_bHYPRE__IJMatrixView__delete(
    struct bHYPRE__IJMatrixView__object* self,
    sidl_BaseInterface* _ex)
  {
    *_ex = NULL;
    free((void*) self);
  }

  // REMOTE GETURL: call the getURL function for the object.
  static char* remote_bHYPRE__IJMatrixView__getURL(
    struct bHYPRE__IJMatrixView__object* self, sidl_BaseInterface* _ex)
  {
    struct sidl_rmi_InstanceHandle__object *conn = ((struct 
      bHYPRE__IJMatrixView__remote*)self->d_data)->d_ih;
    *_ex = NULL;
    if(conn != NULL) {
      return sidl_rmi_InstanceHandle_getObjectURL(conn, _ex);
    }
    return NULL;
  }

  // REMOTE ADDREF: For internal babel use only! Remote addRef.
  static void remote_bHYPRE__IJMatrixView__raddRef(
    struct bHYPRE__IJMatrixView__object* self,sidl_BaseInterface* _ex)
  {
    sidl_BaseException netex = NULL;
    // initialize a new invocation
    sidl_BaseInterface _throwaway = NULL;
    struct sidl_rmi_InstanceHandle__object *_conn = ((struct 
      bHYPRE__IJMatrixView__remote*)self->d_data)->d_ih;
    sidl_rmi_Response _rsvp = NULL;
    sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( _conn, 
      "addRef", _ex ); SIDL_CHECK(*_ex);
    // send actual RMI request
    _rsvp = sidl_rmi_Invocation_invokeMethod(_inv,_ex);SIDL_CHECK(*_ex);
    // Check for exceptions
    netex = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);
    if(netex != NULL) {
      sidl_BaseInterface throwaway_exception = NULL;
      *_ex = (sidl_BaseInterface) sidl_BaseInterface__rmicast(netex,
        &throwaway_exception);
      return;
    }

    // cleanup and return
    EXIT:
    if(_inv) { sidl_rmi_Invocation_deleteRef(_inv,&_throwaway); }
    if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp,&_throwaway); }
    return;
  }

  // REMOTE ISREMOTE: returns true if this object is Remote (it is).
  static sidl_bool
  remote_bHYPRE__IJMatrixView__isRemote(
      struct bHYPRE__IJMatrixView__object* self, 
      sidl_BaseInterface *_ex) {
    *_ex = NULL;
    return TRUE;
  }

  // REMOTE METHOD STUB:_set_hooks
  static void
  remote_bHYPRE__IJMatrixView__set_hooks(
    /* in */ struct bHYPRE__IJMatrixView__object* self ,
    /* in */ sidl_bool on,
    /* out */ struct sidl_BaseInterface__object* *_ex)
  {
    LANG_SPECIFIC_INIT();
    *_ex = NULL;
    {
      // initialize a new invocation
      sidl_BaseInterface _throwaway = NULL;
      sidl_BaseException _be = NULL;
      sidl_rmi_Response _rsvp = NULL;
      struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
        bHYPRE__IJMatrixView__remote*)self->d_data)->d_ih;
      sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( 
        _conn, "_set_hooks", _ex ); SIDL_CHECK(*_ex);

      // pack in and inout arguments
      sidl_rmi_Invocation_packBool( _inv, "on", on, _ex);SIDL_CHECK(*_ex);

      // send actual RMI request
      _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

      _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
      if(_be != NULL) {
        sidl_BaseInterface throwaway_exception = NULL;
sidl_BaseException_addLine(_be, "Exception unserialized from bHYPRE._IJMatrixView._set_hooks.", &throwaway_exception);
        *_ex = (sidl_BaseInterface) sidl_BaseInterface__rmicast(_be,
          &throwaway_exception);
        goto EXIT;
      }

      // unpack out and inout arguments

      // cleanup and return
      EXIT:
      if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
      if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
      return;
    }
  }

  // REMOTE EXEC: call the exec function for the object.
  static void remote_bHYPRE__IJMatrixView__exec(
    struct bHYPRE__IJMatrixView__object* self,const char* methodName,
    sidl_rmi_Call inArgs,
    sidl_rmi_Return outArgs,
    sidl_BaseInterface* _ex)
  {
    *_ex = NULL;
  }

  // REMOTE METHOD STUB:SetLocalRange
  static int32_t
  remote_bHYPRE__IJMatrixView_SetLocalRange(
    /* in */ struct bHYPRE__IJMatrixView__object* self ,
    /* in */ int32_t ilower,
    /* in */ int32_t iupper,
    /* in */ int32_t jlower,
    /* in */ int32_t jupper,
    /* out */ struct sidl_BaseInterface__object* *_ex)
  {
    LANG_SPECIFIC_INIT();
    *_ex = NULL;
    {
      // initialize a new invocation
      sidl_BaseInterface _throwaway = NULL;
      sidl_BaseException _be = NULL;
      sidl_rmi_Response _rsvp = NULL;
      int32_t _retval = 0;
      struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
        bHYPRE__IJMatrixView__remote*)self->d_data)->d_ih;
      sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( 
        _conn, "SetLocalRange", _ex ); SIDL_CHECK(*_ex);

      // pack in and inout arguments
      sidl_rmi_Invocation_packInt( _inv, "ilower", ilower, _ex);SIDL_CHECK(
        *_ex);
      sidl_rmi_Invocation_packInt( _inv, "iupper", iupper, _ex);SIDL_CHECK(
        *_ex);
      sidl_rmi_Invocation_packInt( _inv, "jlower", jlower, _ex);SIDL_CHECK(
        *_ex);
      sidl_rmi_Invocation_packInt( _inv, "jupper", jupper, _ex);SIDL_CHECK(
        *_ex);

      // send actual RMI request
      _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

      _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
      if(_be != NULL) {
        sidl_BaseInterface throwaway_exception = NULL;
sidl_BaseException_addLine(_be, "Exception unserialized from bHYPRE._IJMatrixView.SetLocalRange.", &throwaway_exception);
        *_ex = (sidl_BaseInterface) sidl_BaseInterface__rmicast(_be,
          &throwaway_exception);
        goto EXIT;
      }

      // extract return value
      sidl_rmi_Response_unpackInt( _rsvp, "_retval", &_retval, _ex);SIDL_CHECK(
        *_ex);

      // unpack out and inout arguments

      // cleanup and return
      EXIT:
      if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
      if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
      return _retval;
    }
  }

  // REMOTE METHOD STUB:SetValues
  static int32_t
  remote_bHYPRE__IJMatrixView_SetValues(
    /* in */ struct bHYPRE__IJMatrixView__object* self ,
    /* in rarray[nrows] */ struct sidl_int__array* ncols,
    /* in rarray[nrows] */ struct sidl_int__array* rows,
    /* in rarray[nnonzeros] */ struct sidl_int__array* cols,
    /* in rarray[nnonzeros] */ struct sidl_double__array* values,
    /* out */ struct sidl_BaseInterface__object* *_ex)
  {
    LANG_SPECIFIC_INIT();
    *_ex = NULL;
    {
      // initialize a new invocation
      sidl_BaseInterface _throwaway = NULL;
      sidl_BaseException _be = NULL;
      sidl_rmi_Response _rsvp = NULL;
      int32_t _retval = 0;
      struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
        bHYPRE__IJMatrixView__remote*)self->d_data)->d_ih;
      sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( 
        _conn, "SetValues", _ex ); SIDL_CHECK(*_ex);

      // pack in and inout arguments
      sidl_rmi_Invocation_packIntArray( _inv, "ncols", ncols,
        sidl_column_major_order,1,0, _ex);SIDL_CHECK(*_ex);
      sidl_rmi_Invocation_packIntArray( _inv, "rows", rows,
        sidl_column_major_order,1,0, _ex);SIDL_CHECK(*_ex);
      sidl_rmi_Invocation_packIntArray( _inv, "cols", cols,
        sidl_column_major_order,1,0, _ex);SIDL_CHECK(*_ex);
      sidl_rmi_Invocation_packDoubleArray( _inv, "values", values,
        sidl_column_major_order,1,0, _ex);SIDL_CHECK(*_ex);

      // send actual RMI request
      _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

      _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
      if(_be != NULL) {
        sidl_BaseInterface throwaway_exception = NULL;
sidl_BaseException_addLine(_be, "Exception unserialized from bHYPRE._IJMatrixView.SetValues.", &throwaway_exception);
        *_ex = (sidl_BaseInterface) sidl_BaseInterface__rmicast(_be,
          &throwaway_exception);
        goto EXIT;
      }

      // extract return value
      sidl_rmi_Response_unpackInt( _rsvp, "_retval", &_retval, _ex);SIDL_CHECK(
        *_ex);

      // unpack out and inout arguments

      // cleanup and return
      EXIT:
      if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
      if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
      return _retval;
    }
  }

  // REMOTE METHOD STUB:AddToValues
  static int32_t
  remote_bHYPRE__IJMatrixView_AddToValues(
    /* in */ struct bHYPRE__IJMatrixView__object* self ,
    /* in rarray[nrows] */ struct sidl_int__array* ncols,
    /* in rarray[nrows] */ struct sidl_int__array* rows,
    /* in rarray[nnonzeros] */ struct sidl_int__array* cols,
    /* in rarray[nnonzeros] */ struct sidl_double__array* values,
    /* out */ struct sidl_BaseInterface__object* *_ex)
  {
    LANG_SPECIFIC_INIT();
    *_ex = NULL;
    {
      // initialize a new invocation
      sidl_BaseInterface _throwaway = NULL;
      sidl_BaseException _be = NULL;
      sidl_rmi_Response _rsvp = NULL;
      int32_t _retval = 0;
      struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
        bHYPRE__IJMatrixView__remote*)self->d_data)->d_ih;
      sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( 
        _conn, "AddToValues", _ex ); SIDL_CHECK(*_ex);

      // pack in and inout arguments
      sidl_rmi_Invocation_packIntArray( _inv, "ncols", ncols,
        sidl_column_major_order,1,0, _ex);SIDL_CHECK(*_ex);
      sidl_rmi_Invocation_packIntArray( _inv, "rows", rows,
        sidl_column_major_order,1,0, _ex);SIDL_CHECK(*_ex);
      sidl_rmi_Invocation_packIntArray( _inv, "cols", cols,
        sidl_column_major_order,1,0, _ex);SIDL_CHECK(*_ex);
      sidl_rmi_Invocation_packDoubleArray( _inv, "values", values,
        sidl_column_major_order,1,0, _ex);SIDL_CHECK(*_ex);

      // send actual RMI request
      _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

      _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
      if(_be != NULL) {
        sidl_BaseInterface throwaway_exception = NULL;
sidl_BaseException_addLine(_be, "Exception unserialized from bHYPRE._IJMatrixView.AddToValues.", &throwaway_exception);
        *_ex = (sidl_BaseInterface) sidl_BaseInterface__rmicast(_be,
          &throwaway_exception);
        goto EXIT;
      }

      // extract return value
      sidl_rmi_Response_unpackInt( _rsvp, "_retval", &_retval, _ex);SIDL_CHECK(
        *_ex);

      // unpack out and inout arguments

      // cleanup and return
      EXIT:
      if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
      if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
      return _retval;
    }
  }

  // REMOTE METHOD STUB:GetLocalRange
  static int32_t
  remote_bHYPRE__IJMatrixView_GetLocalRange(
    /* in */ struct bHYPRE__IJMatrixView__object* self ,
    /* out */ int32_t* ilower,
    /* out */ int32_t* iupper,
    /* out */ int32_t* jlower,
    /* out */ int32_t* jupper,
    /* out */ struct sidl_BaseInterface__object* *_ex)
  {
    LANG_SPECIFIC_INIT();
    *_ex = NULL;
    {
      // initialize a new invocation
      sidl_BaseInterface _throwaway = NULL;
      sidl_BaseException _be = NULL;
      sidl_rmi_Response _rsvp = NULL;
      int32_t _retval = 0;
      struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
        bHYPRE__IJMatrixView__remote*)self->d_data)->d_ih;
      sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( 
        _conn, "GetLocalRange", _ex ); SIDL_CHECK(*_ex);

      // pack in and inout arguments

      // send actual RMI request
      _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

      _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
      if(_be != NULL) {
        sidl_BaseInterface throwaway_exception = NULL;
sidl_BaseException_addLine(_be, "Exception unserialized from bHYPRE._IJMatrixView.GetLocalRange.", &throwaway_exception);
        *_ex = (sidl_BaseInterface) sidl_BaseInterface__rmicast(_be,
          &throwaway_exception);
        goto EXIT;
      }

      // extract return value
      sidl_rmi_Response_unpackInt( _rsvp, "_retval", &_retval, _ex);SIDL_CHECK(
        *_ex);

      // unpack out and inout arguments
      sidl_rmi_Response_unpackInt( _rsvp, "ilower", ilower, _ex);SIDL_CHECK(
        *_ex);
      sidl_rmi_Response_unpackInt( _rsvp, "iupper", iupper, _ex);SIDL_CHECK(
        *_ex);
      sidl_rmi_Response_unpackInt( _rsvp, "jlower", jlower, _ex);SIDL_CHECK(
        *_ex);
      sidl_rmi_Response_unpackInt( _rsvp, "jupper", jupper, _ex);SIDL_CHECK(
        *_ex);

      // cleanup and return
      EXIT:
      if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
      if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
      return _retval;
    }
  }

  // REMOTE METHOD STUB:GetRowCounts
  static int32_t
  remote_bHYPRE__IJMatrixView_GetRowCounts(
    /* in */ struct bHYPRE__IJMatrixView__object* self ,
    /* in rarray[nrows] */ struct sidl_int__array* rows,
    /* inout rarray[nrows] */ struct sidl_int__array** ncols,
    /* out */ struct sidl_BaseInterface__object* *_ex)
  {
    LANG_SPECIFIC_INIT();
    *_ex = NULL;
    {
      // initialize a new invocation
      sidl_BaseInterface _throwaway = NULL;
      sidl_BaseException _be = NULL;
      sidl_rmi_Response _rsvp = NULL;
      int32_t _retval = 0;
      struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
        bHYPRE__IJMatrixView__remote*)self->d_data)->d_ih;
      sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( 
        _conn, "GetRowCounts", _ex ); SIDL_CHECK(*_ex);

      // pack in and inout arguments
      sidl_rmi_Invocation_packIntArray( _inv, "rows", rows,
        sidl_column_major_order,1,0, _ex);SIDL_CHECK(*_ex);
      sidl_rmi_Invocation_packIntArray( _inv, "ncols", *ncols,
        sidl_column_major_order,1,0, _ex);SIDL_CHECK(*_ex);

      // send actual RMI request
      _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

      _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
      if(_be != NULL) {
        sidl_BaseInterface throwaway_exception = NULL;
sidl_BaseException_addLine(_be, "Exception unserialized from bHYPRE._IJMatrixView.GetRowCounts.", &throwaway_exception);
        *_ex = (sidl_BaseInterface) sidl_BaseInterface__rmicast(_be,
          &throwaway_exception);
        goto EXIT;
      }

      // extract return value
      sidl_rmi_Response_unpackInt( _rsvp, "_retval", &_retval, _ex);SIDL_CHECK(
        *_ex);

      // unpack out and inout arguments
      sidl_rmi_Response_unpackIntArray( _rsvp, "ncols", ncols,
        sidl_column_major_order,1,TRUE, _ex);SIDL_CHECK(*_ex);

      // cleanup and return
      EXIT:
      if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
      if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
      return _retval;
    }
  }

  // REMOTE METHOD STUB:GetValues
  static int32_t
  remote_bHYPRE__IJMatrixView_GetValues(
    /* in */ struct bHYPRE__IJMatrixView__object* self ,
    /* in rarray[nrows] */ struct sidl_int__array* ncols,
    /* in rarray[nrows] */ struct sidl_int__array* rows,
    /* in rarray[nnonzeros] */ struct sidl_int__array* cols,
    /* inout rarray[nnonzeros] */ struct sidl_double__array** values,
    /* out */ struct sidl_BaseInterface__object* *_ex)
  {
    LANG_SPECIFIC_INIT();
    *_ex = NULL;
    {
      // initialize a new invocation
      sidl_BaseInterface _throwaway = NULL;
      sidl_BaseException _be = NULL;
      sidl_rmi_Response _rsvp = NULL;
      int32_t _retval = 0;
      struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
        bHYPRE__IJMatrixView__remote*)self->d_data)->d_ih;
      sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( 
        _conn, "GetValues", _ex ); SIDL_CHECK(*_ex);

      // pack in and inout arguments
      sidl_rmi_Invocation_packIntArray( _inv, "ncols", ncols,
        sidl_column_major_order,1,0, _ex);SIDL_CHECK(*_ex);
      sidl_rmi_Invocation_packIntArray( _inv, "rows", rows,
        sidl_column_major_order,1,0, _ex);SIDL_CHECK(*_ex);
      sidl_rmi_Invocation_packIntArray( _inv, "cols", cols,
        sidl_column_major_order,1,0, _ex);SIDL_CHECK(*_ex);
      sidl_rmi_Invocation_packDoubleArray( _inv, "values", *values,
        sidl_column_major_order,1,0, _ex);SIDL_CHECK(*_ex);

      // send actual RMI request
      _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

      _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
      if(_be != NULL) {
        sidl_BaseInterface throwaway_exception = NULL;
sidl_BaseException_addLine(_be, "Exception unserialized from bHYPRE._IJMatrixView.GetValues.", &throwaway_exception);
        *_ex = (sidl_BaseInterface) sidl_BaseInterface__rmicast(_be,
          &throwaway_exception);
        goto EXIT;
      }

      // extract return value
      sidl_rmi_Response_unpackInt( _rsvp, "_retval", &_retval, _ex);SIDL_CHECK(
        *_ex);

      // unpack out and inout arguments
      sidl_rmi_Response_unpackDoubleArray( _rsvp, "values", values,
        sidl_column_major_order,1,TRUE, _ex);SIDL_CHECK(*_ex);

      // cleanup and return
      EXIT:
      if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
      if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
      return _retval;
    }
  }

  // REMOTE METHOD STUB:SetRowSizes
  static int32_t
  remote_bHYPRE__IJMatrixView_SetRowSizes(
    /* in */ struct bHYPRE__IJMatrixView__object* self ,
    /* in rarray[nrows] */ struct sidl_int__array* sizes,
    /* out */ struct sidl_BaseInterface__object* *_ex)
  {
    LANG_SPECIFIC_INIT();
    *_ex = NULL;
    {
      // initialize a new invocation
      sidl_BaseInterface _throwaway = NULL;
      sidl_BaseException _be = NULL;
      sidl_rmi_Response _rsvp = NULL;
      int32_t _retval = 0;
      struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
        bHYPRE__IJMatrixView__remote*)self->d_data)->d_ih;
      sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( 
        _conn, "SetRowSizes", _ex ); SIDL_CHECK(*_ex);

      // pack in and inout arguments
      sidl_rmi_Invocation_packIntArray( _inv, "sizes", sizes,
        sidl_column_major_order,1,0, _ex);SIDL_CHECK(*_ex);

      // send actual RMI request
      _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

      _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
      if(_be != NULL) {
        sidl_BaseInterface throwaway_exception = NULL;
sidl_BaseException_addLine(_be, "Exception unserialized from bHYPRE._IJMatrixView.SetRowSizes.", &throwaway_exception);
        *_ex = (sidl_BaseInterface) sidl_BaseInterface__rmicast(_be,
          &throwaway_exception);
        goto EXIT;
      }

      // extract return value
      sidl_rmi_Response_unpackInt( _rsvp, "_retval", &_retval, _ex);SIDL_CHECK(
        *_ex);

      // unpack out and inout arguments

      // cleanup and return
      EXIT:
      if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
      if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
      return _retval;
    }
  }

  // REMOTE METHOD STUB:Print
  static int32_t
  remote_bHYPRE__IJMatrixView_Print(
    /* in */ struct bHYPRE__IJMatrixView__object* self ,
    /* in */ const char* filename,
    /* out */ struct sidl_BaseInterface__object* *_ex)
  {
    LANG_SPECIFIC_INIT();
    *_ex = NULL;
    {
      // initialize a new invocation
      sidl_BaseInterface _throwaway = NULL;
      sidl_BaseException _be = NULL;
      sidl_rmi_Response _rsvp = NULL;
      int32_t _retval = 0;
      struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
        bHYPRE__IJMatrixView__remote*)self->d_data)->d_ih;
      sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( 
        _conn, "Print", _ex ); SIDL_CHECK(*_ex);

      // pack in and inout arguments
      sidl_rmi_Invocation_packString( _inv, "filename", filename, 
        _ex);SIDL_CHECK(*_ex);

      // send actual RMI request
      _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

      _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
      if(_be != NULL) {
        sidl_BaseInterface throwaway_exception = NULL;
sidl_BaseException_addLine(_be, "Exception unserialized from bHYPRE._IJMatrixView.Print.", &throwaway_exception);
        *_ex = (sidl_BaseInterface) sidl_BaseInterface__rmicast(_be,
          &throwaway_exception);
        goto EXIT;
      }

      // extract return value
      sidl_rmi_Response_unpackInt( _rsvp, "_retval", &_retval, _ex);SIDL_CHECK(
        *_ex);

      // unpack out and inout arguments

      // cleanup and return
      EXIT:
      if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
      if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
      return _retval;
    }
  }

  // REMOTE METHOD STUB:Read
  static int32_t
  remote_bHYPRE__IJMatrixView_Read(
    /* in */ struct bHYPRE__IJMatrixView__object* self ,
    /* in */ const char* filename,
    /* in */ struct bHYPRE_MPICommunicator__object* comm,
    /* out */ struct sidl_BaseInterface__object* *_ex)
  {
    LANG_SPECIFIC_INIT();
    *_ex = NULL;
    {
      // initialize a new invocation
      sidl_BaseInterface _throwaway = NULL;
      sidl_BaseException _be = NULL;
      sidl_rmi_Response _rsvp = NULL;
      int32_t _retval = 0;
      struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
        bHYPRE__IJMatrixView__remote*)self->d_data)->d_ih;
      sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( 
        _conn, "Read", _ex ); SIDL_CHECK(*_ex);

      // pack in and inout arguments
      sidl_rmi_Invocation_packString( _inv, "filename", filename, 
        _ex);SIDL_CHECK(*_ex);
      if(comm){
        char* _url = sidl_BaseInterface__getURL((sidl_BaseInterface)comm, 
          _ex);SIDL_CHECK(*_ex);
        sidl_rmi_Invocation_packString( _inv, "comm", _url, _ex);SIDL_CHECK(
          *_ex);
        free((void*)_url);
      } else {
        sidl_rmi_Invocation_packString( _inv, "comm", NULL, _ex);SIDL_CHECK(
          *_ex);
      }

      // send actual RMI request
      _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

      _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
      if(_be != NULL) {
        sidl_BaseInterface throwaway_exception = NULL;
sidl_BaseException_addLine(_be, "Exception unserialized from bHYPRE._IJMatrixView.Read.", &throwaway_exception);
        *_ex = (sidl_BaseInterface) sidl_BaseInterface__rmicast(_be,
          &throwaway_exception);
        goto EXIT;
      }

      // extract return value
      sidl_rmi_Response_unpackInt( _rsvp, "_retval", &_retval, _ex);SIDL_CHECK(
        *_ex);

      // unpack out and inout arguments

      // cleanup and return
      EXIT:
      if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
      if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
      return _retval;
    }
  }

  // REMOTE METHOD STUB:SetCommunicator
  static int32_t
  remote_bHYPRE__IJMatrixView_SetCommunicator(
    /* in */ struct bHYPRE__IJMatrixView__object* self ,
    /* in */ struct bHYPRE_MPICommunicator__object* mpi_comm,
    /* out */ struct sidl_BaseInterface__object* *_ex)
  {
    LANG_SPECIFIC_INIT();
    *_ex = NULL;
    {
      // initialize a new invocation
      sidl_BaseInterface _throwaway = NULL;
      sidl_BaseException _be = NULL;
      sidl_rmi_Response _rsvp = NULL;
      int32_t _retval = 0;
      struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
        bHYPRE__IJMatrixView__remote*)self->d_data)->d_ih;
      sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( 
        _conn, "SetCommunicator", _ex ); SIDL_CHECK(*_ex);

      // pack in and inout arguments
      if(mpi_comm){
        char* _url = sidl_BaseInterface__getURL((sidl_BaseInterface)mpi_comm, 
          _ex);SIDL_CHECK(*_ex);
        sidl_rmi_Invocation_packString( _inv, "mpi_comm", _url, _ex);SIDL_CHECK(
          *_ex);
        free((void*)_url);
      } else {
        sidl_rmi_Invocation_packString( _inv, "mpi_comm", NULL, _ex);SIDL_CHECK(
          *_ex);
      }

      // send actual RMI request
      _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

      _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
      if(_be != NULL) {
        sidl_BaseInterface throwaway_exception = NULL;
sidl_BaseException_addLine(_be, "Exception unserialized from bHYPRE._IJMatrixView.SetCommunicator.", &throwaway_exception);
        *_ex = (sidl_BaseInterface) sidl_BaseInterface__rmicast(_be,
          &throwaway_exception);
        goto EXIT;
      }

      // extract return value
      sidl_rmi_Response_unpackInt( _rsvp, "_retval", &_retval, _ex);SIDL_CHECK(
        *_ex);

      // unpack out and inout arguments

      // cleanup and return
      EXIT:
      if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
      if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
      return _retval;
    }
  }

  // REMOTE METHOD STUB:Destroy
  static void
  remote_bHYPRE__IJMatrixView_Destroy(
    /* in */ struct bHYPRE__IJMatrixView__object* self ,
    /* out */ struct sidl_BaseInterface__object* *_ex)
  {
    LANG_SPECIFIC_INIT();
    *_ex = NULL;
    {
      // initialize a new invocation
      sidl_BaseInterface _throwaway = NULL;
      sidl_BaseException _be = NULL;
      sidl_rmi_Response _rsvp = NULL;
      struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
        bHYPRE__IJMatrixView__remote*)self->d_data)->d_ih;
      sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( 
        _conn, "Destroy", _ex ); SIDL_CHECK(*_ex);

      // pack in and inout arguments

      // send actual RMI request
      _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

      _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
      if(_be != NULL) {
        sidl_BaseInterface throwaway_exception = NULL;
sidl_BaseException_addLine(_be, "Exception unserialized from bHYPRE._IJMatrixView.Destroy.", &throwaway_exception);
        *_ex = (sidl_BaseInterface) sidl_BaseInterface__rmicast(_be,
          &throwaway_exception);
        goto EXIT;
      }

      // unpack out and inout arguments

      // cleanup and return
      EXIT:
      if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
      if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
      return;
    }
  }

  // REMOTE METHOD STUB:Initialize
  static int32_t
  remote_bHYPRE__IJMatrixView_Initialize(
    /* in */ struct bHYPRE__IJMatrixView__object* self ,
    /* out */ struct sidl_BaseInterface__object* *_ex)
  {
    LANG_SPECIFIC_INIT();
    *_ex = NULL;
    {
      // initialize a new invocation
      sidl_BaseInterface _throwaway = NULL;
      sidl_BaseException _be = NULL;
      sidl_rmi_Response _rsvp = NULL;
      int32_t _retval = 0;
      struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
        bHYPRE__IJMatrixView__remote*)self->d_data)->d_ih;
      sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( 
        _conn, "Initialize", _ex ); SIDL_CHECK(*_ex);

      // pack in and inout arguments

      // send actual RMI request
      _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

      _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
      if(_be != NULL) {
        sidl_BaseInterface throwaway_exception = NULL;
sidl_BaseException_addLine(_be, "Exception unserialized from bHYPRE._IJMatrixView.Initialize.", &throwaway_exception);
        *_ex = (sidl_BaseInterface) sidl_BaseInterface__rmicast(_be,
          &throwaway_exception);
        goto EXIT;
      }

      // extract return value
      sidl_rmi_Response_unpackInt( _rsvp, "_retval", &_retval, _ex);SIDL_CHECK(
        *_ex);

      // unpack out and inout arguments

      // cleanup and return
      EXIT:
      if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
      if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
      return _retval;
    }
  }

  // REMOTE METHOD STUB:Assemble
  static int32_t
  remote_bHYPRE__IJMatrixView_Assemble(
    /* in */ struct bHYPRE__IJMatrixView__object* self ,
    /* out */ struct sidl_BaseInterface__object* *_ex)
  {
    LANG_SPECIFIC_INIT();
    *_ex = NULL;
    {
      // initialize a new invocation
      sidl_BaseInterface _throwaway = NULL;
      sidl_BaseException _be = NULL;
      sidl_rmi_Response _rsvp = NULL;
      int32_t _retval = 0;
      struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
        bHYPRE__IJMatrixView__remote*)self->d_data)->d_ih;
      sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( 
        _conn, "Assemble", _ex ); SIDL_CHECK(*_ex);

      // pack in and inout arguments

      // send actual RMI request
      _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

      _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
      if(_be != NULL) {
        sidl_BaseInterface throwaway_exception = NULL;
sidl_BaseException_addLine(_be, "Exception unserialized from bHYPRE._IJMatrixView.Assemble.", &throwaway_exception);
        *_ex = (sidl_BaseInterface) sidl_BaseInterface__rmicast(_be,
          &throwaway_exception);
        goto EXIT;
      }

      // extract return value
      sidl_rmi_Response_unpackInt( _rsvp, "_retval", &_retval, _ex);SIDL_CHECK(
        *_ex);

      // unpack out and inout arguments

      // cleanup and return
      EXIT:
      if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
      if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
      return _retval;
    }
  }

  // REMOTE METHOD STUB:addRef
  static void
  remote_bHYPRE__IJMatrixView_addRef(
    /* in */ struct bHYPRE__IJMatrixView__object* self ,
    /* out */ struct sidl_BaseInterface__object* *_ex)
  {
    LANG_SPECIFIC_INIT();
    *_ex = NULL;
    {
      struct bHYPRE__IJMatrixView__remote* r_obj = (struct 
        bHYPRE__IJMatrixView__remote*)self->d_data;
      LOCK_STATIC_GLOBALS;
      r_obj->d_refcount++;
      UNLOCK_STATIC_GLOBALS;
    }
  }

  // REMOTE METHOD STUB:deleteRef
  static void
  remote_bHYPRE__IJMatrixView_deleteRef(
    /* in */ struct bHYPRE__IJMatrixView__object* self ,
    /* out */ struct sidl_BaseInterface__object* *_ex)
  {
    LANG_SPECIFIC_INIT();
    *_ex = NULL;
    {
      struct bHYPRE__IJMatrixView__remote* r_obj = (struct 
        bHYPRE__IJMatrixView__remote*)self->d_data;
      LOCK_STATIC_GLOBALS;
      r_obj->d_refcount--;
      if(r_obj->d_refcount == 0) {
        sidl_rmi_InstanceHandle_deleteRef(r_obj->d_ih, _ex);
        free(r_obj);
        free(self);
      }
      UNLOCK_STATIC_GLOBALS;
    }
  }

  // REMOTE METHOD STUB:isSame
  static sidl_bool
  remote_bHYPRE__IJMatrixView_isSame(
    /* in */ struct bHYPRE__IJMatrixView__object* self ,
    /* in */ struct sidl_BaseInterface__object* iobj,
    /* out */ struct sidl_BaseInterface__object* *_ex)
  {
    LANG_SPECIFIC_INIT();
    *_ex = NULL;
    {
      // initialize a new invocation
      sidl_BaseInterface _throwaway = NULL;
      sidl_BaseException _be = NULL;
      sidl_rmi_Response _rsvp = NULL;
      sidl_bool _retval = FALSE;
      struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
        bHYPRE__IJMatrixView__remote*)self->d_data)->d_ih;
      sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( 
        _conn, "isSame", _ex ); SIDL_CHECK(*_ex);

      // pack in and inout arguments
      if(iobj){
        char* _url = sidl_BaseInterface__getURL((sidl_BaseInterface)iobj, 
          _ex);SIDL_CHECK(*_ex);
        sidl_rmi_Invocation_packString( _inv, "iobj", _url, _ex);SIDL_CHECK(
          *_ex);
        free((void*)_url);
      } else {
        sidl_rmi_Invocation_packString( _inv, "iobj", NULL, _ex);SIDL_CHECK(
          *_ex);
      }

      // send actual RMI request
      _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

      _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
      if(_be != NULL) {
        sidl_BaseInterface throwaway_exception = NULL;
sidl_BaseException_addLine(_be, "Exception unserialized from bHYPRE._IJMatrixView.isSame.", &throwaway_exception);
        *_ex = (sidl_BaseInterface) sidl_BaseInterface__rmicast(_be,
          &throwaway_exception);
        goto EXIT;
      }

      // extract return value
      sidl_rmi_Response_unpackBool( _rsvp, "_retval", &_retval, _ex);SIDL_CHECK(
        *_ex);

      // unpack out and inout arguments

      // cleanup and return
      EXIT:
      if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
      if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
      return _retval;
    }
  }

  // REMOTE METHOD STUB:isType
  static sidl_bool
  remote_bHYPRE__IJMatrixView_isType(
    /* in */ struct bHYPRE__IJMatrixView__object* self ,
    /* in */ const char* name,
    /* out */ struct sidl_BaseInterface__object* *_ex)
  {
    LANG_SPECIFIC_INIT();
    *_ex = NULL;
    {
      // initialize a new invocation
      sidl_BaseInterface _throwaway = NULL;
      sidl_BaseException _be = NULL;
      sidl_rmi_Response _rsvp = NULL;
      sidl_bool _retval = FALSE;
      struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
        bHYPRE__IJMatrixView__remote*)self->d_data)->d_ih;
      sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( 
        _conn, "isType", _ex ); SIDL_CHECK(*_ex);

      // pack in and inout arguments
      sidl_rmi_Invocation_packString( _inv, "name", name, _ex);SIDL_CHECK(*_ex);

      // send actual RMI request
      _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

      _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
      if(_be != NULL) {
        sidl_BaseInterface throwaway_exception = NULL;
sidl_BaseException_addLine(_be, "Exception unserialized from bHYPRE._IJMatrixView.isType.", &throwaway_exception);
        *_ex = (sidl_BaseInterface) sidl_BaseInterface__rmicast(_be,
          &throwaway_exception);
        goto EXIT;
      }

      // extract return value
      sidl_rmi_Response_unpackBool( _rsvp, "_retval", &_retval, _ex);SIDL_CHECK(
        *_ex);

      // unpack out and inout arguments

      // cleanup and return
      EXIT:
      if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
      if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
      return _retval;
    }
  }

  // REMOTE METHOD STUB:getClassInfo
  static struct sidl_ClassInfo__object*
  remote_bHYPRE__IJMatrixView_getClassInfo(
    /* in */ struct bHYPRE__IJMatrixView__object* self ,
    /* out */ struct sidl_BaseInterface__object* *_ex)
  {
    LANG_SPECIFIC_INIT();
    *_ex = NULL;
    {
      // initialize a new invocation
      sidl_BaseInterface _throwaway = NULL;
      sidl_BaseException _be = NULL;
      sidl_rmi_Response _rsvp = NULL;
      char*_retval_str = NULL;
      struct sidl_ClassInfo__object* _retval = 0;
      struct sidl_rmi_InstanceHandle__object * _conn = ((struct 
        bHYPRE__IJMatrixView__remote*)self->d_data)->d_ih;
      sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( 
        _conn, "getClassInfo", _ex ); SIDL_CHECK(*_ex);

      // pack in and inout arguments

      // send actual RMI request
      _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

      _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
      if(_be != NULL) {
        sidl_BaseInterface throwaway_exception = NULL;
sidl_BaseException_addLine(_be, "Exception unserialized from bHYPRE._IJMatrixView.getClassInfo.", &throwaway_exception);
        *_ex = (sidl_BaseInterface) sidl_BaseInterface__rmicast(_be,
          &throwaway_exception);
        goto EXIT;
      }

      // extract return value
      sidl_rmi_Response_unpackString( _rsvp, "_retval", &_retval_str, 
        _ex);SIDL_CHECK(*_ex);
      _retval = sidl_ClassInfo__connectI(_retval_str, FALSE, _ex);SIDL_CHECK(
        *_ex);

      // unpack out and inout arguments

      // cleanup and return
      EXIT:
      if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
      if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
      return _retval;
    }
  }

  // REMOTE EPV: create remote entry point vectors (EPVs).
  static void bHYPRE__IJMatrixView__init_remote_epv(void)
  {
    // assert( HAVE_LOCKED_STATIC_GLOBALS );
    struct bHYPRE__IJMatrixView__epv*     epv = 
      &s_rem_epv__bhypre__ijmatrixview;
    struct bHYPRE_IJMatrixView__epv*      e0  = &s_rem_epv__bhypre_ijmatrixview;
    struct bHYPRE_MatrixVectorView__epv*  e1  = 
      &s_rem_epv__bhypre_matrixvectorview;
    struct bHYPRE_ProblemDefinition__epv* e2  = 
      &s_rem_epv__bhypre_problemdefinition;
    struct sidl_BaseInterface__epv*       e3  = &s_rem_epv__sidl_baseinterface;

    epv->f__cast                = remote_bHYPRE__IJMatrixView__cast;
    epv->f__delete              = remote_bHYPRE__IJMatrixView__delete;
    epv->f__exec                = remote_bHYPRE__IJMatrixView__exec;
    epv->f__getURL              = remote_bHYPRE__IJMatrixView__getURL;
    epv->f__raddRef             = remote_bHYPRE__IJMatrixView__raddRef;
    epv->f__isRemote            = remote_bHYPRE__IJMatrixView__isRemote;
    epv->f__set_hooks           = remote_bHYPRE__IJMatrixView__set_hooks;
    epv->f__ctor                = NULL;
    epv->f__ctor2               = NULL;
    epv->f__dtor                = NULL;
    epv->f_SetLocalRange        = remote_bHYPRE__IJMatrixView_SetLocalRange;
    epv->f_SetValues            = remote_bHYPRE__IJMatrixView_SetValues;
    epv->f_AddToValues          = remote_bHYPRE__IJMatrixView_AddToValues;
    epv->f_GetLocalRange        = remote_bHYPRE__IJMatrixView_GetLocalRange;
    epv->f_GetRowCounts         = remote_bHYPRE__IJMatrixView_GetRowCounts;
    epv->f_GetValues            = remote_bHYPRE__IJMatrixView_GetValues;
    epv->f_SetRowSizes          = remote_bHYPRE__IJMatrixView_SetRowSizes;
    epv->f_Print                = remote_bHYPRE__IJMatrixView_Print;
    epv->f_Read                 = remote_bHYPRE__IJMatrixView_Read;
    epv->f_SetCommunicator      = remote_bHYPRE__IJMatrixView_SetCommunicator;
    epv->f_Destroy              = remote_bHYPRE__IJMatrixView_Destroy;
    epv->f_Initialize           = remote_bHYPRE__IJMatrixView_Initialize;
    epv->f_Assemble             = remote_bHYPRE__IJMatrixView_Assemble;
    epv->f_addRef               = remote_bHYPRE__IJMatrixView_addRef;
    epv->f_deleteRef            = remote_bHYPRE__IJMatrixView_deleteRef;
    epv->f_isSame               = remote_bHYPRE__IJMatrixView_isSame;
    epv->f_isType               = remote_bHYPRE__IJMatrixView_isType;
    epv->f_getClassInfo         = remote_bHYPRE__IJMatrixView_getClassInfo;

    e0->f__cast           = (void* (*)(void*,const char*,sidl_BaseInterface*)) 
      epv->f__cast;
    e0->f__delete         = (void (*)(void*,sidl_BaseInterface*)) 
      epv->f__delete;
    e0->f__getURL         = (char* (*)(void*,sidl_BaseInterface*)) 
      epv->f__getURL;
    e0->f__raddRef        = (void (*)(void*,sidl_BaseInterface*)) 
      epv->f__raddRef;
    e0->f__isRemote       = (sidl_bool (*)(void*,sidl_BaseInterface*)) 
      epv->f__isRemote;
    e0->f__set_hooks      = (void (*)(void*,int32_t, sidl_BaseInterface*)) 
      epv->f__set_hooks;
    e0->f__exec           = (void (*)(void*,const char*,struct 
      sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
      sidl_BaseInterface__object **)) epv->f__exec;
    e0->f_SetLocalRange   = (int32_t (*)(void*,int32_t,int32_t,int32_t,int32_t,
      struct sidl_BaseInterface__object **)) epv->f_SetLocalRange;
    e0->f_SetValues       = (int32_t (*)(void*,struct sidl_int__array*,struct 
      sidl_int__array*,struct sidl_int__array*,struct sidl_double__array*,
      struct sidl_BaseInterface__object **)) epv->f_SetValues;
    e0->f_AddToValues     = (int32_t (*)(void*,struct sidl_int__array*,struct 
      sidl_int__array*,struct sidl_int__array*,struct sidl_double__array*,
      struct sidl_BaseInterface__object **)) epv->f_AddToValues;
    e0->f_GetLocalRange   = (int32_t (*)(void*,int32_t*,int32_t*,int32_t*,
      int32_t*,struct sidl_BaseInterface__object **)) epv->f_GetLocalRange;
    e0->f_GetRowCounts    = (int32_t (*)(void*,struct sidl_int__array*,struct 
      sidl_int__array**,struct sidl_BaseInterface__object **)) 
      epv->f_GetRowCounts;
    e0->f_GetValues       = (int32_t (*)(void*,struct sidl_int__array*,struct 
      sidl_int__array*,struct sidl_int__array*,struct sidl_double__array**,
      struct sidl_BaseInterface__object **)) epv->f_GetValues;
    e0->f_SetRowSizes     = (int32_t (*)(void*,struct sidl_int__array*,struct 
      sidl_BaseInterface__object **)) epv->f_SetRowSizes;
    e0->f_Print           = (int32_t (*)(void*,const char*,struct 
      sidl_BaseInterface__object **)) epv->f_Print;
    e0->f_Read            = (int32_t (*)(void*,const char*,struct 
      bHYPRE_MPICommunicator__object*,struct sidl_BaseInterface__object **)) 
      epv->f_Read;
    e0->f_SetCommunicator = (int32_t (*)(void*,struct 
      bHYPRE_MPICommunicator__object*,struct sidl_BaseInterface__object **)) 
      epv->f_SetCommunicator;
    e0->f_Destroy         = (void (*)(void*,struct sidl_BaseInterface__object 
      **)) epv->f_Destroy;
    e0->f_Initialize      = (int32_t (*)(void*,struct 
      sidl_BaseInterface__object **)) epv->f_Initialize;
    e0->f_Assemble        = (int32_t (*)(void*,struct 
      sidl_BaseInterface__object **)) epv->f_Assemble;
    e0->f_addRef          = (void (*)(void*,struct sidl_BaseInterface__object 
      **)) epv->f_addRef;
    e0->f_deleteRef       = (void (*)(void*,struct sidl_BaseInterface__object 
      **)) epv->f_deleteRef;
    e0->f_isSame          = (sidl_bool (*)(void*,struct 
      sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) 
      epv->f_isSame;
    e0->f_isType          = (sidl_bool (*)(void*,const char*,struct 
      sidl_BaseInterface__object **)) epv->f_isType;
    e0->f_getClassInfo    = (struct sidl_ClassInfo__object* (*)(void*,struct 
      sidl_BaseInterface__object **)) epv->f_getClassInfo;

    e1->f__cast           = (void* (*)(void*,const char*,sidl_BaseInterface*)) 
      epv->f__cast;
    e1->f__delete         = (void (*)(void*,sidl_BaseInterface*)) 
      epv->f__delete;
    e1->f__getURL         = (char* (*)(void*,sidl_BaseInterface*)) 
      epv->f__getURL;
    e1->f__raddRef        = (void (*)(void*,sidl_BaseInterface*)) 
      epv->f__raddRef;
    e1->f__isRemote       = (sidl_bool (*)(void*,sidl_BaseInterface*)) 
      epv->f__isRemote;
    e1->f__set_hooks      = (void (*)(void*,int32_t, sidl_BaseInterface*)) 
      epv->f__set_hooks;
    e1->f__exec           = (void (*)(void*,const char*,struct 
      sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
      sidl_BaseInterface__object **)) epv->f__exec;
    e1->f_SetCommunicator = (int32_t (*)(void*,struct 
      bHYPRE_MPICommunicator__object*,struct sidl_BaseInterface__object **)) 
      epv->f_SetCommunicator;
    e1->f_Destroy         = (void (*)(void*,struct sidl_BaseInterface__object 
      **)) epv->f_Destroy;
    e1->f_Initialize      = (int32_t (*)(void*,struct 
      sidl_BaseInterface__object **)) epv->f_Initialize;
    e1->f_Assemble        = (int32_t (*)(void*,struct 
      sidl_BaseInterface__object **)) epv->f_Assemble;
    e1->f_addRef          = (void (*)(void*,struct sidl_BaseInterface__object 
      **)) epv->f_addRef;
    e1->f_deleteRef       = (void (*)(void*,struct sidl_BaseInterface__object 
      **)) epv->f_deleteRef;
    e1->f_isSame          = (sidl_bool (*)(void*,struct 
      sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) 
      epv->f_isSame;
    e1->f_isType          = (sidl_bool (*)(void*,const char*,struct 
      sidl_BaseInterface__object **)) epv->f_isType;
    e1->f_getClassInfo    = (struct sidl_ClassInfo__object* (*)(void*,struct 
      sidl_BaseInterface__object **)) epv->f_getClassInfo;

    e2->f__cast           = (void* (*)(void*,const char*,sidl_BaseInterface*)) 
      epv->f__cast;
    e2->f__delete         = (void (*)(void*,sidl_BaseInterface*)) 
      epv->f__delete;
    e2->f__getURL         = (char* (*)(void*,sidl_BaseInterface*)) 
      epv->f__getURL;
    e2->f__raddRef        = (void (*)(void*,sidl_BaseInterface*)) 
      epv->f__raddRef;
    e2->f__isRemote       = (sidl_bool (*)(void*,sidl_BaseInterface*)) 
      epv->f__isRemote;
    e2->f__set_hooks      = (void (*)(void*,int32_t, sidl_BaseInterface*)) 
      epv->f__set_hooks;
    e2->f__exec           = (void (*)(void*,const char*,struct 
      sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
      sidl_BaseInterface__object **)) epv->f__exec;
    e2->f_SetCommunicator = (int32_t (*)(void*,struct 
      bHYPRE_MPICommunicator__object*,struct sidl_BaseInterface__object **)) 
      epv->f_SetCommunicator;
    e2->f_Destroy         = (void (*)(void*,struct sidl_BaseInterface__object 
      **)) epv->f_Destroy;
    e2->f_Initialize      = (int32_t (*)(void*,struct 
      sidl_BaseInterface__object **)) epv->f_Initialize;
    e2->f_Assemble        = (int32_t (*)(void*,struct 
      sidl_BaseInterface__object **)) epv->f_Assemble;
    e2->f_addRef          = (void (*)(void*,struct sidl_BaseInterface__object 
      **)) epv->f_addRef;
    e2->f_deleteRef       = (void (*)(void*,struct sidl_BaseInterface__object 
      **)) epv->f_deleteRef;
    e2->f_isSame          = (sidl_bool (*)(void*,struct 
      sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) 
      epv->f_isSame;
    e2->f_isType          = (sidl_bool (*)(void*,const char*,struct 
      sidl_BaseInterface__object **)) epv->f_isType;
    e2->f_getClassInfo    = (struct sidl_ClassInfo__object* (*)(void*,struct 
      sidl_BaseInterface__object **)) epv->f_getClassInfo;

    e3->f__cast        = (void* (*)(void*,const char*,sidl_BaseInterface*)) 
      epv->f__cast;
    e3->f__delete      = (void (*)(void*,sidl_BaseInterface*)) epv->f__delete;
    e3->f__getURL      = (char* (*)(void*,sidl_BaseInterface*)) epv->f__getURL;
    e3->f__raddRef     = (void (*)(void*,sidl_BaseInterface*)) epv->f__raddRef;
    e3->f__isRemote    = (sidl_bool (*)(void*,sidl_BaseInterface*)) 
      epv->f__isRemote;
    e3->f__set_hooks   = (void (*)(void*,int32_t, sidl_BaseInterface*)) 
      epv->f__set_hooks;
    e3->f__exec        = (void (*)(void*,const char*,struct 
      sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
      sidl_BaseInterface__object **)) epv->f__exec;
    e3->f_addRef       = (void (*)(void*,struct sidl_BaseInterface__object **)) 
      epv->f_addRef;
    e3->f_deleteRef    = (void (*)(void*,struct sidl_BaseInterface__object **)) 
      epv->f_deleteRef;
    e3->f_isSame       = (sidl_bool (*)(void*,struct 
      sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) 
      epv->f_isSame;
    e3->f_isType       = (sidl_bool (*)(void*,const char*,struct 
      sidl_BaseInterface__object **)) epv->f_isType;
    e3->f_getClassInfo = (struct sidl_ClassInfo__object* (*)(void*,struct 
      sidl_BaseInterface__object **)) epv->f_getClassInfo;

    s_remote_initialized = 1;
  }

  // Create an instance that connects to an existing remote object.
  static struct bHYPRE_IJMatrixView__object*
  bHYPRE_IJMatrixView__remoteConnect(const char *url, sidl_bool ar, 
    sidl_BaseInterface *_ex)
  {
    struct bHYPRE__IJMatrixView__object* self;

    struct bHYPRE__IJMatrixView__object* s0;

    struct bHYPRE__IJMatrixView__remote* r_obj;
    sidl_rmi_InstanceHandle instance = NULL;
    char* objectID = NULL;
    objectID = sidl_rmi_ServerRegistry_isLocalObject(url, _ex);
    if(objectID) {
      sidl_BaseInterface bi = (
        sidl_BaseInterface)sidl_rmi_InstanceRegistry_getInstanceByString(
        objectID, _ex);
      if(ar) {
        sidl_BaseInterface_addRef(bi, _ex);
      }
      return bHYPRE_IJMatrixView__rmicast(bi, _ex);
    }
    instance = sidl_rmi_ProtocolFactory_connectInstance(url, ar, _ex );
    if ( instance == NULL) { return NULL; }
    self =
      (struct bHYPRE__IJMatrixView__object*) malloc(
        sizeof(struct bHYPRE__IJMatrixView__object));

    r_obj =
      (struct bHYPRE__IJMatrixView__remote*) malloc(
        sizeof(struct bHYPRE__IJMatrixView__remote));

    r_obj->d_refcount = 1;
    r_obj->d_ih = instance;
    s0 =                                self;

    LOCK_STATIC_GLOBALS;
    if (!s_remote_initialized) {
      bHYPRE__IJMatrixView__init_remote_epv();
    }
    UNLOCK_STATIC_GLOBALS;

    s0->d_bhypre_ijmatrixview.d_epv    = &s_rem_epv__bhypre_ijmatrixview;
    s0->d_bhypre_ijmatrixview.d_object = (void*) self;

    s0->d_bhypre_matrixvectorview.d_epv    = 
      &s_rem_epv__bhypre_matrixvectorview;
    s0->d_bhypre_matrixvectorview.d_object = (void*) self;

    s0->d_bhypre_problemdefinition.d_epv    = 
      &s_rem_epv__bhypre_problemdefinition;
    s0->d_bhypre_problemdefinition.d_object = (void*) self;

    s0->d_sidl_baseinterface.d_epv    = &s_rem_epv__sidl_baseinterface;
    s0->d_sidl_baseinterface.d_object = (void*) self;

    s0->d_data = (void*) r_obj;
    s0->d_epv  = &s_rem_epv__bhypre__ijmatrixview;

    self->d_data = (void*) r_obj;

    return bHYPRE_IJMatrixView__rmicast(self, _ex);
  }
  // Create an instance that uses an already existing 
  // InstanceHandel to connect to an existing remote object.
  static struct bHYPRE_IJMatrixView__object*
  bHYPRE_IJMatrixView__IHConnect(sidl_rmi_InstanceHandle instance, 
    sidl_BaseInterface *_ex)
  {
    struct bHYPRE__IJMatrixView__object* self;

    struct bHYPRE__IJMatrixView__object* s0;

    struct bHYPRE__IJMatrixView__remote* r_obj;
    self =
      (struct bHYPRE__IJMatrixView__object*) malloc(
        sizeof(struct bHYPRE__IJMatrixView__object));

    r_obj =
      (struct bHYPRE__IJMatrixView__remote*) malloc(
        sizeof(struct bHYPRE__IJMatrixView__remote));

    r_obj->d_refcount = 1;
    r_obj->d_ih = instance;
    s0 =                                self;

    LOCK_STATIC_GLOBALS;
    if (!s_remote_initialized) {
      bHYPRE__IJMatrixView__init_remote_epv();
    }
    UNLOCK_STATIC_GLOBALS;

    s0->d_bhypre_ijmatrixview.d_epv    = &s_rem_epv__bhypre_ijmatrixview;
    s0->d_bhypre_ijmatrixview.d_object = (void*) self;

    s0->d_bhypre_matrixvectorview.d_epv    = 
      &s_rem_epv__bhypre_matrixvectorview;
    s0->d_bhypre_matrixvectorview.d_object = (void*) self;

    s0->d_bhypre_problemdefinition.d_epv    = 
      &s_rem_epv__bhypre_problemdefinition;
    s0->d_bhypre_problemdefinition.d_object = (void*) self;

    s0->d_sidl_baseinterface.d_epv    = &s_rem_epv__sidl_baseinterface;
    s0->d_sidl_baseinterface.d_object = (void*) self;

    s0->d_data = (void*) r_obj;
    s0->d_epv  = &s_rem_epv__bhypre__ijmatrixview;

    self->d_data = (void*) r_obj;

    sidl_rmi_InstanceHandle_addRef(instance, _ex);
    return bHYPRE_IJMatrixView__rmicast(self, _ex);
  }
  // 
  // Cast method for interface and class type conversions.
  // 
  struct bHYPRE_IJMatrixView__object*
  bHYPRE_IJMatrixView__rmicast(
    void* obj,
    sidl_BaseInterface* _ex)
  {
    struct bHYPRE_IJMatrixView__object* cast = NULL;

    *_ex = NULL;
    if(!connect_loaded) {
      sidl_rmi_ConnectRegistry_registerConnect("bHYPRE.IJMatrixView", (
        void*)bHYPRE_IJMatrixView__IHConnect, _ex);
      connect_loaded = 1;
    }
    if (obj != NULL) {
      struct sidl_BaseInterface__object* base = (struct 
        sidl_BaseInterface__object*) obj;
      cast = (struct bHYPRE_IJMatrixView__object*) (*base->d_epv->f__cast)(
        base->d_object,
        "bHYPRE.IJMatrixView", _ex); SIDL_CHECK(*_ex);
    }

    return cast;
    EXIT:
    return NULL;
  }

  // 
  // RMI connector function for the class.
  // 
  struct bHYPRE_IJMatrixView__object*
  bHYPRE_IJMatrixView__connectI(const char* url, sidl_bool ar, struct 
    sidl_BaseInterface__object **_ex)
  {
    return bHYPRE_IJMatrixView__remoteConnect(url, ar, _ex);
  }

}

//////////////////////////////////////////////////
// 
// Special methods for throwing exceptions
// 

void
bHYPRE::IJMatrixView::throwException0(
  struct sidl_BaseInterface__object *_exception
)
  // throws:
{
  void * _p = 0;
  struct sidl_BaseInterface__object *throwaway_exception;

  if ( (_p=(*(_exception->d_epv->f__cast))(_exception->d_object, 
    "sidl.RuntimeException", &throwaway_exception)) != 0 ) {
    struct sidl_RuntimeException__object * _realtype = reinterpret_cast< struct 
      sidl_RuntimeException__object*>(_p);
    (*_exception->d_epv->f_deleteRef)(_exception->d_object, 
      &throwaway_exception);
    // Note: alternate constructor does not increment refcount.
    ::sidl::RuntimeException _resolved_exception = ::sidl::RuntimeException( 
      _realtype, false );
    _resolved_exception.add(__FILE__,__LINE__, "C++ stub.");
    throw _resolved_exception;
  }
  // Any unresolved exception is treated as LangSpecificException
  ::sidl::LangSpecificException _unexpected = 
    ::sidl::LangSpecificException::_create();
  _unexpected.add(__FILE__,__LINE__, "Unknown method");
  _unexpected.setNote("Unexpected exception received by C++ stub.");
  throw _unexpected;
}

//////////////////////////////////////////////////
// 
// User Defined Methods
// 


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
int32_t
bHYPRE::IJMatrixView::SetLocalRange( /* in */int32_t ilower, /* in */int32_t 
  iupper, /* in */int32_t jlower, /* in */int32_t jupper )

{
  int32_t _result;
  ior_t* const loc_self = (struct bHYPRE_IJMatrixView__object*) 
    ::bHYPRE::IJMatrixView::_get_ior();
  sidl_BaseInterface__object * _exception;
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_SetLocalRange))(loc_self->d_object, /* in */ 
    ilower, /* in */ iupper, /* in */ jlower, /* in */ jupper, &_exception );
  /*dispatch to ior*/
  if (_exception != 0 ) {

    throwException0(_exception);
  }
  /*unpack results and cleanup*/
  return _result;
}



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
bHYPRE::IJMatrixView::SetValues( /* in */int32_t nrows, /* in rarray[nrows] 
  */int32_t* ncols, /* in rarray[nrows] */int32_t* rows, /* in 
  rarray[nnonzeros] */int32_t* cols, /* in rarray[nnonzeros] */double* values, 
  /* in */int32_t nnonzeros )

{
  int32_t _result;
  ior_t* const loc_self = (struct bHYPRE_IJMatrixView__object*) 
    ::bHYPRE::IJMatrixView::_get_ior();
  int32_t ncols_lower[1], ncols_upper[1], ncols_stride[1];
  struct sidl_int__array ncols_real;
  struct sidl_int__array *ncols_tmp = &ncols_real;
  ncols_upper[0] = nrows-1;
  sidl_int__array_init(ncols, ncols_tmp, 1, ncols_lower, ncols_upper, 
    ncols_stride);
  int32_t rows_lower[1], rows_upper[1], rows_stride[1];
  struct sidl_int__array rows_real;
  struct sidl_int__array *rows_tmp = &rows_real;
  rows_upper[0] = nrows-1;
  sidl_int__array_init(rows, rows_tmp, 1, rows_lower, rows_upper, rows_stride);
  int32_t cols_lower[1], cols_upper[1], cols_stride[1];
  struct sidl_int__array cols_real;
  struct sidl_int__array *cols_tmp = &cols_real;
  cols_upper[0] = nnonzeros-1;
  sidl_int__array_init(cols, cols_tmp, 1, cols_lower, cols_upper, cols_stride);
  int32_t values_lower[1], values_upper[1], values_stride[1];
  struct sidl_double__array values_real;
  struct sidl_double__array *values_tmp = &values_real;
  values_upper[0] = nnonzeros-1;
  sidl_double__array_init(values, values_tmp, 1, values_lower, values_upper, 
    values_stride);
  sidl_BaseInterface__object * _exception;
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_SetValues))(loc_self->d_object, /* in 
    rarray[nrows] */ ncols_tmp, /* in rarray[nrows] */ rows_tmp, /* in 
    rarray[nnonzeros] */ cols_tmp, /* in rarray[nnonzeros] */ values_tmp, 
    &_exception );
  /*dispatch to ior*/
  if (_exception != 0 ) {
    sidl__array_deleteRef((struct sidl__array *)ncols_tmp);
    sidl__array_deleteRef((struct sidl__array *)rows_tmp);
    sidl__array_deleteRef((struct sidl__array *)cols_tmp);
    sidl__array_deleteRef((struct sidl__array *)values_tmp);

    throwException0(_exception);
  }
  sidl__array_deleteRef((struct sidl__array *)ncols_tmp);
  sidl__array_deleteRef((struct sidl__array *)rows_tmp);
  sidl__array_deleteRef((struct sidl__array *)cols_tmp);
  sidl__array_deleteRef((struct sidl__array *)values_tmp);
  /*unpack results and cleanup*/
  return _result;
}



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
bHYPRE::IJMatrixView::SetValues( /* in rarray[nrows] */::sidl::array<int32_t> 
  ncols, /* in rarray[nrows] */::sidl::array<int32_t> rows, /* in 
  rarray[nnonzeros] */::sidl::array<int32_t> cols, /* in rarray[nnonzeros] 
  */::sidl::array<double> values )

{
  int32_t _result;
  ior_t* const loc_self = (struct bHYPRE_IJMatrixView__object*) 
    ::bHYPRE::IJMatrixView::_get_ior();
  sidl_BaseInterface__object * _exception;
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_SetValues))(loc_self->d_object, /* in 
    rarray[nrows] */ ncols._get_ior(), /* in rarray[nrows] */ rows._get_ior(), 
    /* in rarray[nnonzeros] */ cols._get_ior(), /* in rarray[nnonzeros] */ 
    values._get_ior(), &_exception );
  /*dispatch to ior*/
  if (_exception != 0 ) {

    throwException0(_exception);
  }
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Adds to values for {\tt nrows} of the matrix.  Usage details
 * are analogous to {\tt SetValues}.  Adds to any previous
 * values at the specified locations, or, if there was no value
 * there before, inserts a new one.
 * 
 * Not collective.
 */
int32_t
bHYPRE::IJMatrixView::AddToValues( /* in */int32_t nrows, /* in rarray[nrows] 
  */int32_t* ncols, /* in rarray[nrows] */int32_t* rows, /* in 
  rarray[nnonzeros] */int32_t* cols, /* in rarray[nnonzeros] */double* values, 
  /* in */int32_t nnonzeros )

{
  int32_t _result;
  ior_t* const loc_self = (struct bHYPRE_IJMatrixView__object*) 
    ::bHYPRE::IJMatrixView::_get_ior();
  int32_t ncols_lower[1], ncols_upper[1], ncols_stride[1];
  struct sidl_int__array ncols_real;
  struct sidl_int__array *ncols_tmp = &ncols_real;
  ncols_upper[0] = nrows-1;
  sidl_int__array_init(ncols, ncols_tmp, 1, ncols_lower, ncols_upper, 
    ncols_stride);
  int32_t rows_lower[1], rows_upper[1], rows_stride[1];
  struct sidl_int__array rows_real;
  struct sidl_int__array *rows_tmp = &rows_real;
  rows_upper[0] = nrows-1;
  sidl_int__array_init(rows, rows_tmp, 1, rows_lower, rows_upper, rows_stride);
  int32_t cols_lower[1], cols_upper[1], cols_stride[1];
  struct sidl_int__array cols_real;
  struct sidl_int__array *cols_tmp = &cols_real;
  cols_upper[0] = nnonzeros-1;
  sidl_int__array_init(cols, cols_tmp, 1, cols_lower, cols_upper, cols_stride);
  int32_t values_lower[1], values_upper[1], values_stride[1];
  struct sidl_double__array values_real;
  struct sidl_double__array *values_tmp = &values_real;
  values_upper[0] = nnonzeros-1;
  sidl_double__array_init(values, values_tmp, 1, values_lower, values_upper, 
    values_stride);
  sidl_BaseInterface__object * _exception;
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_AddToValues))(loc_self->d_object, /* in 
    rarray[nrows] */ ncols_tmp, /* in rarray[nrows] */ rows_tmp, /* in 
    rarray[nnonzeros] */ cols_tmp, /* in rarray[nnonzeros] */ values_tmp, 
    &_exception );
  /*dispatch to ior*/
  if (_exception != 0 ) {
    sidl__array_deleteRef((struct sidl__array *)ncols_tmp);
    sidl__array_deleteRef((struct sidl__array *)rows_tmp);
    sidl__array_deleteRef((struct sidl__array *)cols_tmp);
    sidl__array_deleteRef((struct sidl__array *)values_tmp);

    throwException0(_exception);
  }
  sidl__array_deleteRef((struct sidl__array *)ncols_tmp);
  sidl__array_deleteRef((struct sidl__array *)rows_tmp);
  sidl__array_deleteRef((struct sidl__array *)cols_tmp);
  sidl__array_deleteRef((struct sidl__array *)values_tmp);
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Adds to values for {\tt nrows} of the matrix.  Usage details
 * are analogous to {\tt SetValues}.  Adds to any previous
 * values at the specified locations, or, if there was no value
 * there before, inserts a new one.
 * 
 * Not collective.
 */
int32_t
bHYPRE::IJMatrixView::AddToValues( /* in rarray[nrows] */::sidl::array<int32_t> 
  ncols, /* in rarray[nrows] */::sidl::array<int32_t> rows, /* in 
  rarray[nnonzeros] */::sidl::array<int32_t> cols, /* in rarray[nnonzeros] 
  */::sidl::array<double> values )

{
  int32_t _result;
  ior_t* const loc_self = (struct bHYPRE_IJMatrixView__object*) 
    ::bHYPRE::IJMatrixView::_get_ior();
  sidl_BaseInterface__object * _exception;
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_AddToValues))(loc_self->d_object, /* in 
    rarray[nrows] */ ncols._get_ior(), /* in rarray[nrows] */ rows._get_ior(), 
    /* in rarray[nnonzeros] */ cols._get_ior(), /* in rarray[nnonzeros] */ 
    values._get_ior(), &_exception );
  /*dispatch to ior*/
  if (_exception != 0 ) {

    throwException0(_exception);
  }
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Gets range of rows owned by this processor and range of
 * column partitioning for this processor.
 */
int32_t
bHYPRE::IJMatrixView::GetLocalRange( /* out */int32_t& ilower, /* out 
  */int32_t& iupper, /* out */int32_t& jlower, /* out */int32_t& jupper )

{
  int32_t _result;
  ior_t* const loc_self = (struct bHYPRE_IJMatrixView__object*) 
    ::bHYPRE::IJMatrixView::_get_ior();
  sidl_BaseInterface__object * _exception;
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_GetLocalRange))(loc_self->d_object, /* out */ 
    &ilower, /* out */ &iupper, /* out */ &jlower, /* out */ &jupper, 
    &_exception );
  /*dispatch to ior*/
  if (_exception != 0 ) {

    throwException0(_exception);
  }
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Gets number of nonzeros elements for {\tt nrows} rows
 * specified in {\tt rows} and returns them in {\tt ncols},
 * which needs to be allocated by the user.
 */
int32_t
bHYPRE::IJMatrixView::GetRowCounts( /* in */int32_t nrows, /* in rarray[nrows] 
  */int32_t* rows, /* inout rarray[nrows] */int32_t* ncols )

{
  int32_t _result;
  ior_t* const loc_self = (struct bHYPRE_IJMatrixView__object*) 
    ::bHYPRE::IJMatrixView::_get_ior();
  int32_t rows_lower[1], rows_upper[1], rows_stride[1];
  struct sidl_int__array rows_real;
  struct sidl_int__array *rows_tmp = &rows_real;
  rows_upper[0] = nrows-1;
  sidl_int__array_init(rows, rows_tmp, 1, rows_lower, rows_upper, rows_stride);
  int32_t ncols_lower[1], ncols_upper[1], ncols_stride[1];
  struct sidl_int__array ncols_real;
  struct sidl_int__array *ncols_tmp = &ncols_real;
  ncols_upper[0] = nrows-1;
  sidl_int__array_init(ncols, ncols_tmp, 1, ncols_lower, ncols_upper, 
    ncols_stride);
  sidl_BaseInterface__object * _exception;
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_GetRowCounts))(loc_self->d_object, /* in 
    rarray[nrows] */ rows_tmp, /* inout rarray[nrows] */ &ncols_tmp, 
    &_exception );
  /*dispatch to ior*/
  if (_exception != 0 ) {
    sidl__array_deleteRef((struct sidl__array *)rows_tmp);
    sidl__array_deleteRef((struct sidl__array *)ncols_tmp);

    throwException0(_exception);
  }
  sidl__array_deleteRef((struct sidl__array *)rows_tmp);
  sidl__array_deleteRef((struct sidl__array *)ncols_tmp);
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Gets number of nonzeros elements for {\tt nrows} rows
 * specified in {\tt rows} and returns them in {\tt ncols},
 * which needs to be allocated by the user.
 */
int32_t
bHYPRE::IJMatrixView::GetRowCounts( /* in rarray[nrows] 
  */::sidl::array<int32_t> rows, /* inout rarray[nrows] 
  */::sidl::array<int32_t>& ncols )

{
  int32_t _result;
  ior_t* const loc_self = (struct bHYPRE_IJMatrixView__object*) 
    ::bHYPRE::IJMatrixView::_get_ior();
  if (ncols) {
    ncols.addRef();
  }
  struct sidl_int__array* _local_ncols = ncols._get_ior();
  sidl_BaseInterface__object * _exception;
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_GetRowCounts))(loc_self->d_object, /* in 
    rarray[nrows] */ rows._get_ior(), /* inout rarray[nrows] */ &_local_ncols, 
    &_exception );
  /*dispatch to ior*/
  if (_exception != 0 ) {

    throwException0(_exception);
  }
  ncols._set_ior(_local_ncols);
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Gets values for {\tt nrows} rows or partial rows of the
 * matrix.  Usage details are analogous to {\tt SetValues}.
 */
int32_t
bHYPRE::IJMatrixView::GetValues( /* in */int32_t nrows, /* in rarray[nrows] 
  */int32_t* ncols, /* in rarray[nrows] */int32_t* rows, /* in 
  rarray[nnonzeros] */int32_t* cols, /* inout rarray[nnonzeros] */double* 
  values, /* in */int32_t nnonzeros )

{
  int32_t _result;
  ior_t* const loc_self = (struct bHYPRE_IJMatrixView__object*) 
    ::bHYPRE::IJMatrixView::_get_ior();
  int32_t ncols_lower[1], ncols_upper[1], ncols_stride[1];
  struct sidl_int__array ncols_real;
  struct sidl_int__array *ncols_tmp = &ncols_real;
  ncols_upper[0] = nrows-1;
  sidl_int__array_init(ncols, ncols_tmp, 1, ncols_lower, ncols_upper, 
    ncols_stride);
  int32_t rows_lower[1], rows_upper[1], rows_stride[1];
  struct sidl_int__array rows_real;
  struct sidl_int__array *rows_tmp = &rows_real;
  rows_upper[0] = nrows-1;
  sidl_int__array_init(rows, rows_tmp, 1, rows_lower, rows_upper, rows_stride);
  int32_t cols_lower[1], cols_upper[1], cols_stride[1];
  struct sidl_int__array cols_real;
  struct sidl_int__array *cols_tmp = &cols_real;
  cols_upper[0] = nnonzeros-1;
  sidl_int__array_init(cols, cols_tmp, 1, cols_lower, cols_upper, cols_stride);
  int32_t values_lower[1], values_upper[1], values_stride[1];
  struct sidl_double__array values_real;
  struct sidl_double__array *values_tmp = &values_real;
  values_upper[0] = nnonzeros-1;
  sidl_double__array_init(values, values_tmp, 1, values_lower, values_upper, 
    values_stride);
  sidl_BaseInterface__object * _exception;
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_GetValues))(loc_self->d_object, /* in 
    rarray[nrows] */ ncols_tmp, /* in rarray[nrows] */ rows_tmp, /* in 
    rarray[nnonzeros] */ cols_tmp, /* inout rarray[nnonzeros] */ &values_tmp, 
    &_exception );
  /*dispatch to ior*/
  if (_exception != 0 ) {
    sidl__array_deleteRef((struct sidl__array *)ncols_tmp);
    sidl__array_deleteRef((struct sidl__array *)rows_tmp);
    sidl__array_deleteRef((struct sidl__array *)cols_tmp);
    sidl__array_deleteRef((struct sidl__array *)values_tmp);

    throwException0(_exception);
  }
  sidl__array_deleteRef((struct sidl__array *)ncols_tmp);
  sidl__array_deleteRef((struct sidl__array *)rows_tmp);
  sidl__array_deleteRef((struct sidl__array *)cols_tmp);
  sidl__array_deleteRef((struct sidl__array *)values_tmp);
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Gets values for {\tt nrows} rows or partial rows of the
 * matrix.  Usage details are analogous to {\tt SetValues}.
 */
int32_t
bHYPRE::IJMatrixView::GetValues( /* in rarray[nrows] */::sidl::array<int32_t> 
  ncols, /* in rarray[nrows] */::sidl::array<int32_t> rows, /* in 
  rarray[nnonzeros] */::sidl::array<int32_t> cols, /* inout rarray[nnonzeros] 
  */::sidl::array<double>& values )

{
  int32_t _result;
  ior_t* const loc_self = (struct bHYPRE_IJMatrixView__object*) 
    ::bHYPRE::IJMatrixView::_get_ior();
  if (values) {
    values.addRef();
  }
  struct sidl_double__array* _local_values = values._get_ior();
  sidl_BaseInterface__object * _exception;
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_GetValues))(loc_self->d_object, /* in 
    rarray[nrows] */ ncols._get_ior(), /* in rarray[nrows] */ rows._get_ior(), 
    /* in rarray[nnonzeros] */ cols._get_ior(), /* inout rarray[nnonzeros] */ 
    &_local_values, &_exception );
  /*dispatch to ior*/
  if (_exception != 0 ) {

    throwException0(_exception);
  }
  values._set_ior(_local_values);
  /*unpack results and cleanup*/
  return _result;
}



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
int32_t
bHYPRE::IJMatrixView::SetRowSizes( /* in rarray[nrows] */int32_t* sizes, /* in 
  */int32_t nrows )

{
  int32_t _result;
  ior_t* const loc_self = (struct bHYPRE_IJMatrixView__object*) 
    ::bHYPRE::IJMatrixView::_get_ior();
  int32_t sizes_lower[1], sizes_upper[1], sizes_stride[1];
  struct sidl_int__array sizes_real;
  struct sidl_int__array *sizes_tmp = &sizes_real;
  sizes_upper[0] = nrows-1;
  sidl_int__array_init(sizes, sizes_tmp, 1, sizes_lower, sizes_upper, 
    sizes_stride);
  sidl_BaseInterface__object * _exception;
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_SetRowSizes))(loc_self->d_object, /* in 
    rarray[nrows] */ sizes_tmp, &_exception );
  /*dispatch to ior*/
  if (_exception != 0 ) {
    sidl__array_deleteRef((struct sidl__array *)sizes_tmp);

    throwException0(_exception);
  }
  sidl__array_deleteRef((struct sidl__array *)sizes_tmp);
  /*unpack results and cleanup*/
  return _result;
}



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
int32_t
bHYPRE::IJMatrixView::SetRowSizes( /* in rarray[nrows] */::sidl::array<int32_t> 
  sizes )

{
  int32_t _result;
  ior_t* const loc_self = (struct bHYPRE_IJMatrixView__object*) 
    ::bHYPRE::IJMatrixView::_get_ior();
  sidl_BaseInterface__object * _exception;
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_SetRowSizes))(loc_self->d_object, /* in 
    rarray[nrows] */ sizes._get_ior(), &_exception );
  /*dispatch to ior*/
  if (_exception != 0 ) {

    throwException0(_exception);
  }
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Print the matrix to file.  This is mainly for debugging
 * purposes.
 */
int32_t
bHYPRE::IJMatrixView::Print( /* in */const ::std::string& filename )

{
  int32_t _result;
  ior_t* const loc_self = (struct bHYPRE_IJMatrixView__object*) 
    ::bHYPRE::IJMatrixView::_get_ior();
  sidl_BaseInterface__object * _exception;
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_Print))(loc_self->d_object, /* in */ 
    filename.c_str(), &_exception );
  /*dispatch to ior*/
  if (_exception != 0 ) {

    throwException0(_exception);
  }
  /*unpack results and cleanup*/
  return _result;
}



/**
 * Read the matrix from file.  This is mainly for debugging
 * purposes.
 */
int32_t
bHYPRE::IJMatrixView::Read( /* in */const ::std::string& filename, /* in 
  */::bHYPRE::MPICommunicator comm )

{
  int32_t _result;
  ior_t* const loc_self = (struct bHYPRE_IJMatrixView__object*) 
    ::bHYPRE::IJMatrixView::_get_ior();
  struct bHYPRE_MPICommunicator__object* _local_comm = (struct 
    bHYPRE_MPICommunicator__object*) comm.::bHYPRE::MPICommunicator::_get_ior();
  sidl_BaseInterface__object * _exception;
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_Read))(loc_self->d_object, /* in */ 
    filename.c_str(), /* in */ _local_comm, &_exception );
  /*dispatch to ior*/
  if (_exception != 0 ) {

    throwException0(_exception);
  }
  /*unpack results and cleanup*/
  return _result;
}



//////////////////////////////////////////////////
// 
// End User Defined Methods
// (everything else in this file is specific to
//  Babel's C++ bindings)
// 

// remote connector
::bHYPRE::IJMatrixView
bHYPRE::IJMatrixView::_connect(const std::string& url, const bool ar ) {
  ior_t* ior_self;
  struct sidl_BaseInterface__object *_exception;
  ior_self = bHYPRE_IJMatrixView__remoteConnect( url.c_str(), ar?TRUE:FALSE, 
    &_exception );
  if (_exception != 0 ) {
    throwException0(_exception);
  }
  return ::bHYPRE::IJMatrixView( ior_self, false );
}

// copy constructor
bHYPRE::IJMatrixView::IJMatrixView ( const ::bHYPRE::IJMatrixView& original ) {
  d_self = (struct bHYPRE_IJMatrixView__object*) 
    original.::bHYPRE::IJMatrixView::_get_ior();
  bHYPRE_IJMatrixView_IORCache = (ior_t*) d_self;
  if(d_self) {
    addRef();
  }
  d_weak_reference = false;
}

// assignment operator
::bHYPRE::IJMatrixView&
bHYPRE::IJMatrixView::operator=( const ::bHYPRE::IJMatrixView& rhs ) {
  if ( d_self != rhs.d_self ) {
    if ( d_self != 0 ) {
      deleteRef();
    }
    d_self = (struct bHYPRE_IJMatrixView__object*) 
      rhs.::bHYPRE::IJMatrixView::_get_ior();
    bHYPRE_IJMatrixView_IORCache = (ior_t*) d_self;
    if(d_self) {
      addRef();
    }
    d_weak_reference = false;
  }
  return *this;
}

// conversion from ior to C++ class
bHYPRE::IJMatrixView::IJMatrixView ( ::bHYPRE::IJMatrixView::ior_t* ior ) 
   : StubBase(reinterpret_cast< void*>(ior)) { 
  bHYPRE_IJMatrixView_IORCache = (ior_t*) d_self;
}

// Alternate constructor: does not call addRef()
// (sets d_weak_reference=isWeak)
// For internal use by Impls (fixes bug#275)
bHYPRE::IJMatrixView::IJMatrixView ( ::bHYPRE::IJMatrixView::ior_t* ior, bool 
  isWeak ) : 
StubBase(reinterpret_cast< void*>(ior), isWeak){ 
  bHYPRE_IJMatrixView_IORCache = (ior_t*) d_self;
}

// exec has special argument passing to avoid #include circularities
void ::bHYPRE::IJMatrixView::_exec( const std::string& methodName, 
                        sidl::rmi::Call& inArgs,
                        sidl::rmi::Return& outArgs) { 
  ::bHYPRE::IJMatrixView::ior_t* const loc_self = _get_ior();
  struct sidl_BaseInterface__object *throwaway_exception;
  (*loc_self->d_epv->f__exec)(loc_self->d_object,
                                methodName.c_str(),
                                inArgs._get_ior(),
                                outArgs._get_ior(),
                                &throwaway_exception);
}


/**
 * Get the URL of the Implementation of this object (for RMI)
 */
::std::string
bHYPRE::IJMatrixView::_getURL(  )
// throws:
//       ::sidl::RuntimeException

{
  ::std::string _result;
  ior_t* const loc_self = (struct bHYPRE_IJMatrixView__object*) 
    ::bHYPRE::IJMatrixView::_get_ior();
  char * _local_result;
  sidl_BaseInterface__object * _exception;
  /*pack args to dispatch to ior*/
  _local_result = (*(loc_self->d_epv->f__getURL))(loc_self->d_object, 
    &_exception );
  /*dispatch to ior*/
  if (_exception != 0 ) {

    throwException0(_exception);
  }
  if (_local_result) {
    _result = _local_result;
    ::sidl_String_free( _local_result );
  }
  /*unpack results and cleanup*/
  return _result;
}


/**
 * Method to set whether or not method hooks should be invoked.
 */
void
bHYPRE::IJMatrixView::_set_hooks( /* in */bool on )
// throws:
//       ::sidl::RuntimeException

{

  ior_t* const loc_self = (struct bHYPRE_IJMatrixView__object*) 
    ::bHYPRE::IJMatrixView::_get_ior();
  sidl_bool _local_on = on;
  sidl_BaseInterface__object * _exception;
  /*pack args to dispatch to ior*/
  (*(loc_self->d_epv->f__set_hooks))(loc_self->d_object, /* in */ _local_on, 
    &_exception );
  /*dispatch to ior*/
  if (_exception != 0 ) {

    throwException0(_exception);
  }
  /*unpack results and cleanup*/
}

// protected method that implements casting
struct bHYPRE_IJMatrixView__object* bHYPRE::IJMatrixView::_cast(const void* src)
{
  ior_t* cast = NULL;

  if(!connect_loaded) {
    struct sidl_BaseInterface__object *throwaway_exception;
    sidl_rmi_ConnectRegistry_registerConnect("bHYPRE.IJMatrixView", (
      void*)bHYPRE_IJMatrixView__IHConnect, &throwaway_exception);
    connect_loaded = 1;
  }
  if ( src != 0 ) {
    // Actually, this thing is still const
    void* tmp = const_cast<void*>(src);
    struct sidl_BaseInterface__object *throwaway_exception;
    struct sidl_BaseInterface__object * base = reinterpret_cast< struct 
      sidl_BaseInterface__object *>(tmp);
    cast = reinterpret_cast< ior_t*>((*base->d_epv->f__cast)(base->d_object, 
      "bHYPRE.IJMatrixView", &throwaway_exception));
  }
  return cast;
}

