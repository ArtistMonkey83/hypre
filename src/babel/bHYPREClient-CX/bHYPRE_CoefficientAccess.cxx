// 
// File:          bHYPRE_CoefficientAccess.cxx
// Symbol:        bHYPRE.CoefficientAccess-v1.0.0
// Symbol Type:   interface
// Babel Version: 1.0.4
// Description:   Client-side glue code for bHYPRE.CoefficientAccess
// 
// WARNING: Automatically generated; changes will be lost
// 
// 

#ifndef included_bHYPRE_CoefficientAccess_hxx
#include "bHYPRE_CoefficientAccess.hxx"
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
static struct sidl_recursive_mutex_t bHYPRE__CoefficientAccess__mutex= SIDL_RECURSIVE_MUTEX_INITIALIZER;
#define LOCK_STATIC_GLOBALS sidl_recursive_mutex_lock( &bHYPRE__CoefficientAccess__mutex )
#define UNLOCK_STATIC_GLOBALS sidl_recursive_mutex_unlock( &bHYPRE__CoefficientAccess__mutex )
/* #define HAVE_LOCKED_STATIC_GLOBALS (sidl_recursive_mutex_trylock( &bHYPRE__CoefficientAccess__mutex )==EDEADLOCK) */
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

  static struct bHYPRE__CoefficientAccess__epv 
    s_rem_epv__bhypre__coefficientaccess;

  static struct bHYPRE_CoefficientAccess__epv 
    s_rem_epv__bhypre_coefficientaccess;

  static struct sidl_BaseInterface__epv s_rem_epv__sidl_baseinterface;


  // REMOTE CAST: dynamic type casting for remote objects.
  static void* remote_bHYPRE__CoefficientAccess__cast(
    struct bHYPRE__CoefficientAccess__object* self,
    const char* name, sidl_BaseInterface* _ex)
  {
    int
      cmp0,
      cmp1;
    void* cast = NULL;
    *_ex = NULL; /* default to no exception */
    cmp0 = strcmp(name, "bHYPRE._CoefficientAccess");
    if (!cmp0) {
      (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
      cast = ((struct bHYPRE__CoefficientAccess__object*)self);
      return cast;
    }
    else if (cmp0 < 0) {
      cmp1 = strcmp(name, "bHYPRE.CoefficientAccess");
      if (!cmp1) {
        (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
        cast = &((*self).d_bhypre_coefficientaccess);
        return cast;
      }
    }
    else if (cmp0 > 0) {
      cmp1 = strcmp(name, "sidl.BaseInterface");
      if (!cmp1) {
        (*self->d_epv->f_addRef)(self, _ex); SIDL_CHECK(*_ex);
        cast = &((*self).d_sidl_baseinterface);
        return cast;
      }
    }
    if ((*self->d_epv->f_isType)(self,name, _ex)) {
      void* (*func)(struct sidl_rmi_InstanceHandle__object*, struct 
        sidl_BaseInterface__object**) = 
        (void* (*)(struct sidl_rmi_InstanceHandle__object*, struct 
          sidl_BaseInterface__object**)) 
        sidl_rmi_ConnectRegistry_getConnect(name, _ex);SIDL_CHECK(*_ex);
      cast =  (*func)(((struct 
        bHYPRE__CoefficientAccess__remote*)self->d_data)->d_ih, _ex);
    }

    return cast;
    EXIT:
    return NULL;
  }

  // REMOTE DELETE: call the remote destructor for the object.
  static void remote_bHYPRE__CoefficientAccess__delete(
    struct bHYPRE__CoefficientAccess__object* self,
    sidl_BaseInterface* _ex)
  {
    *_ex = NULL;
    free((void*) self);
  }

  // REMOTE GETURL: call the getURL function for the object.
  static char* remote_bHYPRE__CoefficientAccess__getURL(
    struct bHYPRE__CoefficientAccess__object* self, sidl_BaseInterface* _ex)
  {
    struct sidl_rmi_InstanceHandle__object *conn = ((struct 
      bHYPRE__CoefficientAccess__remote*)self->d_data)->d_ih;
    *_ex = NULL;
    if(conn != NULL) {
      return sidl_rmi_InstanceHandle_getObjectURL(conn, _ex);
    }
    return NULL;
  }

  // REMOTE ADDREF: For internal babel use only! Remote addRef.
  static void remote_bHYPRE__CoefficientAccess__raddRef(
    struct bHYPRE__CoefficientAccess__object* self,sidl_BaseInterface* _ex)
  {
    sidl_BaseException netex = NULL;
    // initialize a new invocation
    sidl_BaseInterface _throwaway = NULL;
    struct sidl_rmi_InstanceHandle__object *_conn = ((struct 
      bHYPRE__CoefficientAccess__remote*)self->d_data)->d_ih;
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
  remote_bHYPRE__CoefficientAccess__isRemote(
      struct bHYPRE__CoefficientAccess__object* self, 
      sidl_BaseInterface *_ex) {
    *_ex = NULL;
    return TRUE;
  }

  // REMOTE METHOD STUB:_set_hooks
  static void
  remote_bHYPRE__CoefficientAccess__set_hooks(
    /* in */ struct bHYPRE__CoefficientAccess__object* self ,
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
        bHYPRE__CoefficientAccess__remote*)self->d_data)->d_ih;
      sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( 
        _conn, "_set_hooks", _ex ); SIDL_CHECK(*_ex);

      // pack in and inout arguments
      sidl_rmi_Invocation_packBool( _inv, "on", on, _ex);SIDL_CHECK(*_ex);

      // send actual RMI request
      _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

      _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
      if(_be != NULL) {
        sidl_BaseInterface throwaway_exception = NULL;
sidl_BaseException_addLine(_be, "Exception unserialized from bHYPRE._CoefficientAccess._set_hooks.", &throwaway_exception);
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
  static void remote_bHYPRE__CoefficientAccess__exec(
    struct bHYPRE__CoefficientAccess__object* self,const char* methodName,
    sidl_rmi_Call inArgs,
    sidl_rmi_Return outArgs,
    sidl_BaseInterface* _ex)
  {
    *_ex = NULL;
  }

  // REMOTE METHOD STUB:GetRow
  static int32_t
  remote_bHYPRE__CoefficientAccess_GetRow(
    /* in */ struct bHYPRE__CoefficientAccess__object* self ,
    /* in */ int32_t row,
    /* out */ int32_t* size,
    /* out array<int,column-major> */ struct sidl_int__array** col_ind,
    /* out array<double,column-major> */ struct sidl_double__array** values,
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
        bHYPRE__CoefficientAccess__remote*)self->d_data)->d_ih;
      sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( 
        _conn, "GetRow", _ex ); SIDL_CHECK(*_ex);

      // pack in and inout arguments
      sidl_rmi_Invocation_packInt( _inv, "row", row, _ex);SIDL_CHECK(*_ex);

      // send actual RMI request
      _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

      _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
      if(_be != NULL) {
        sidl_BaseInterface throwaway_exception = NULL;
sidl_BaseException_addLine(_be, "Exception unserialized from bHYPRE._CoefficientAccess.GetRow.", &throwaway_exception);
        *_ex = (sidl_BaseInterface) sidl_BaseInterface__rmicast(_be,
          &throwaway_exception);
        goto EXIT;
      }

      // extract return value
      sidl_rmi_Response_unpackInt( _rsvp, "_retval", &_retval, _ex);SIDL_CHECK(
        *_ex);

      // unpack out and inout arguments
      sidl_rmi_Response_unpackInt( _rsvp, "size", size, _ex);SIDL_CHECK(*_ex);
      sidl_rmi_Response_unpackIntArray( _rsvp, "col_ind", col_ind,
        sidl_column_major_order,1,FALSE, _ex);SIDL_CHECK(*_ex);
      sidl_rmi_Response_unpackDoubleArray( _rsvp, "values", values,
        sidl_column_major_order,1,FALSE, _ex);SIDL_CHECK(*_ex);

      // cleanup and return
      EXIT:
      if(_inv) { sidl_rmi_Invocation_deleteRef(_inv, &_throwaway); }
      if(_rsvp) { sidl_rmi_Response_deleteRef(_rsvp, &_throwaway); }
      return _retval;
    }
  }

  // REMOTE METHOD STUB:addRef
  static void
  remote_bHYPRE__CoefficientAccess_addRef(
    /* in */ struct bHYPRE__CoefficientAccess__object* self ,
    /* out */ struct sidl_BaseInterface__object* *_ex)
  {
    LANG_SPECIFIC_INIT();
    *_ex = NULL;
    {
      struct bHYPRE__CoefficientAccess__remote* r_obj = (struct 
        bHYPRE__CoefficientAccess__remote*)self->d_data;
      LOCK_STATIC_GLOBALS;
      r_obj->d_refcount++;
      UNLOCK_STATIC_GLOBALS;
    }
  }

  // REMOTE METHOD STUB:deleteRef
  static void
  remote_bHYPRE__CoefficientAccess_deleteRef(
    /* in */ struct bHYPRE__CoefficientAccess__object* self ,
    /* out */ struct sidl_BaseInterface__object* *_ex)
  {
    LANG_SPECIFIC_INIT();
    *_ex = NULL;
    {
      struct bHYPRE__CoefficientAccess__remote* r_obj = (struct 
        bHYPRE__CoefficientAccess__remote*)self->d_data;
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
  remote_bHYPRE__CoefficientAccess_isSame(
    /* in */ struct bHYPRE__CoefficientAccess__object* self ,
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
        bHYPRE__CoefficientAccess__remote*)self->d_data)->d_ih;
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
sidl_BaseException_addLine(_be, "Exception unserialized from bHYPRE._CoefficientAccess.isSame.", &throwaway_exception);
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
  remote_bHYPRE__CoefficientAccess_isType(
    /* in */ struct bHYPRE__CoefficientAccess__object* self ,
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
        bHYPRE__CoefficientAccess__remote*)self->d_data)->d_ih;
      sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( 
        _conn, "isType", _ex ); SIDL_CHECK(*_ex);

      // pack in and inout arguments
      sidl_rmi_Invocation_packString( _inv, "name", name, _ex);SIDL_CHECK(*_ex);

      // send actual RMI request
      _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

      _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
      if(_be != NULL) {
        sidl_BaseInterface throwaway_exception = NULL;
sidl_BaseException_addLine(_be, "Exception unserialized from bHYPRE._CoefficientAccess.isType.", &throwaway_exception);
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
  remote_bHYPRE__CoefficientAccess_getClassInfo(
    /* in */ struct bHYPRE__CoefficientAccess__object* self ,
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
        bHYPRE__CoefficientAccess__remote*)self->d_data)->d_ih;
      sidl_rmi_Invocation _inv = sidl_rmi_InstanceHandle_createInvocation( 
        _conn, "getClassInfo", _ex ); SIDL_CHECK(*_ex);

      // pack in and inout arguments

      // send actual RMI request
      _rsvp = sidl_rmi_Invocation_invokeMethod(_inv, _ex);SIDL_CHECK(*_ex);

      _be = sidl_rmi_Response_getExceptionThrown(_rsvp, _ex);SIDL_CHECK(*_ex);
      if(_be != NULL) {
        sidl_BaseInterface throwaway_exception = NULL;
sidl_BaseException_addLine(_be, "Exception unserialized from bHYPRE._CoefficientAccess.getClassInfo.", &throwaway_exception);
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
  static void bHYPRE__CoefficientAccess__init_remote_epv(void)
  {
    // assert( HAVE_LOCKED_STATIC_GLOBALS );
    struct bHYPRE__CoefficientAccess__epv* epv = 
      &s_rem_epv__bhypre__coefficientaccess;
    struct bHYPRE_CoefficientAccess__epv*  e0  = 
      &s_rem_epv__bhypre_coefficientaccess;
    struct sidl_BaseInterface__epv*        e1  = &s_rem_epv__sidl_baseinterface;

    epv->f__cast             = remote_bHYPRE__CoefficientAccess__cast;
    epv->f__delete           = remote_bHYPRE__CoefficientAccess__delete;
    epv->f__exec             = remote_bHYPRE__CoefficientAccess__exec;
    epv->f__getURL           = remote_bHYPRE__CoefficientAccess__getURL;
    epv->f__raddRef          = remote_bHYPRE__CoefficientAccess__raddRef;
    epv->f__isRemote         = remote_bHYPRE__CoefficientAccess__isRemote;
    epv->f__set_hooks        = remote_bHYPRE__CoefficientAccess__set_hooks;
    epv->f__ctor             = NULL;
    epv->f__ctor2            = NULL;
    epv->f__dtor             = NULL;
    epv->f_GetRow            = remote_bHYPRE__CoefficientAccess_GetRow;
    epv->f_addRef            = remote_bHYPRE__CoefficientAccess_addRef;
    epv->f_deleteRef         = remote_bHYPRE__CoefficientAccess_deleteRef;
    epv->f_isSame            = remote_bHYPRE__CoefficientAccess_isSame;
    epv->f_isType            = remote_bHYPRE__CoefficientAccess_isType;
    epv->f_getClassInfo      = remote_bHYPRE__CoefficientAccess_getClassInfo;

    e0->f__cast        = (void* (*)(void*,const char*,sidl_BaseInterface*)) 
      epv->f__cast;
    e0->f__delete      = (void (*)(void*,sidl_BaseInterface*)) epv->f__delete;
    e0->f__getURL      = (char* (*)(void*,sidl_BaseInterface*)) epv->f__getURL;
    e0->f__raddRef     = (void (*)(void*,sidl_BaseInterface*)) epv->f__raddRef;
    e0->f__isRemote    = (sidl_bool (*)(void*,sidl_BaseInterface*)) 
      epv->f__isRemote;
    e0->f__set_hooks   = (void (*)(void*,int32_t, sidl_BaseInterface*)) 
      epv->f__set_hooks;
    e0->f__exec        = (void (*)(void*,const char*,struct 
      sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
      sidl_BaseInterface__object **)) epv->f__exec;
    e0->f_GetRow       = (int32_t (*)(void*,int32_t,int32_t*,struct 
      sidl_int__array**,struct sidl_double__array**,struct 
      sidl_BaseInterface__object **)) epv->f_GetRow;
    e0->f_addRef       = (void (*)(void*,struct sidl_BaseInterface__object **)) 
      epv->f_addRef;
    e0->f_deleteRef    = (void (*)(void*,struct sidl_BaseInterface__object **)) 
      epv->f_deleteRef;
    e0->f_isSame       = (sidl_bool (*)(void*,struct 
      sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) 
      epv->f_isSame;
    e0->f_isType       = (sidl_bool (*)(void*,const char*,struct 
      sidl_BaseInterface__object **)) epv->f_isType;
    e0->f_getClassInfo = (struct sidl_ClassInfo__object* (*)(void*,struct 
      sidl_BaseInterface__object **)) epv->f_getClassInfo;

    e1->f__cast        = (void* (*)(void*,const char*,sidl_BaseInterface*)) 
      epv->f__cast;
    e1->f__delete      = (void (*)(void*,sidl_BaseInterface*)) epv->f__delete;
    e1->f__getURL      = (char* (*)(void*,sidl_BaseInterface*)) epv->f__getURL;
    e1->f__raddRef     = (void (*)(void*,sidl_BaseInterface*)) epv->f__raddRef;
    e1->f__isRemote    = (sidl_bool (*)(void*,sidl_BaseInterface*)) 
      epv->f__isRemote;
    e1->f__set_hooks   = (void (*)(void*,int32_t, sidl_BaseInterface*)) 
      epv->f__set_hooks;
    e1->f__exec        = (void (*)(void*,const char*,struct 
      sidl_rmi_Call__object*,struct sidl_rmi_Return__object*,struct 
      sidl_BaseInterface__object **)) epv->f__exec;
    e1->f_addRef       = (void (*)(void*,struct sidl_BaseInterface__object **)) 
      epv->f_addRef;
    e1->f_deleteRef    = (void (*)(void*,struct sidl_BaseInterface__object **)) 
      epv->f_deleteRef;
    e1->f_isSame       = (sidl_bool (*)(void*,struct 
      sidl_BaseInterface__object*,struct sidl_BaseInterface__object **)) 
      epv->f_isSame;
    e1->f_isType       = (sidl_bool (*)(void*,const char*,struct 
      sidl_BaseInterface__object **)) epv->f_isType;
    e1->f_getClassInfo = (struct sidl_ClassInfo__object* (*)(void*,struct 
      sidl_BaseInterface__object **)) epv->f_getClassInfo;

    s_remote_initialized = 1;
  }

  // Create an instance that connects to an existing remote object.
  static struct bHYPRE_CoefficientAccess__object*
  bHYPRE_CoefficientAccess__remoteConnect(const char *url, sidl_bool ar, 
    sidl_BaseInterface *_ex)
  {
    struct bHYPRE__CoefficientAccess__object* self;

    struct bHYPRE__CoefficientAccess__object* s0;

    struct bHYPRE__CoefficientAccess__remote* r_obj;
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
      return bHYPRE_CoefficientAccess__rmicast(bi, _ex);
    }
    instance = sidl_rmi_ProtocolFactory_connectInstance(url, ar, _ex );
    if ( instance == NULL) { return NULL; }
    self =
      (struct bHYPRE__CoefficientAccess__object*) malloc(
        sizeof(struct bHYPRE__CoefficientAccess__object));

    r_obj =
      (struct bHYPRE__CoefficientAccess__remote*) malloc(
        sizeof(struct bHYPRE__CoefficientAccess__remote));

    r_obj->d_refcount = 1;
    r_obj->d_ih = instance;
    s0 =                                     self;

    LOCK_STATIC_GLOBALS;
    if (!s_remote_initialized) {
      bHYPRE__CoefficientAccess__init_remote_epv();
    }
    UNLOCK_STATIC_GLOBALS;

    s0->d_bhypre_coefficientaccess.d_epv    = 
      &s_rem_epv__bhypre_coefficientaccess;
    s0->d_bhypre_coefficientaccess.d_object = (void*) self;

    s0->d_sidl_baseinterface.d_epv    = &s_rem_epv__sidl_baseinterface;
    s0->d_sidl_baseinterface.d_object = (void*) self;

    s0->d_data = (void*) r_obj;
    s0->d_epv  = &s_rem_epv__bhypre__coefficientaccess;

    self->d_data = (void*) r_obj;

    return bHYPRE_CoefficientAccess__rmicast(self, _ex);
  }
  // Create an instance that uses an already existing 
  // InstanceHandel to connect to an existing remote object.
  static struct bHYPRE_CoefficientAccess__object*
  bHYPRE_CoefficientAccess__IHConnect(sidl_rmi_InstanceHandle instance, 
    sidl_BaseInterface *_ex)
  {
    struct bHYPRE__CoefficientAccess__object* self;

    struct bHYPRE__CoefficientAccess__object* s0;

    struct bHYPRE__CoefficientAccess__remote* r_obj;
    self =
      (struct bHYPRE__CoefficientAccess__object*) malloc(
        sizeof(struct bHYPRE__CoefficientAccess__object));

    r_obj =
      (struct bHYPRE__CoefficientAccess__remote*) malloc(
        sizeof(struct bHYPRE__CoefficientAccess__remote));

    r_obj->d_refcount = 1;
    r_obj->d_ih = instance;
    s0 =                                     self;

    LOCK_STATIC_GLOBALS;
    if (!s_remote_initialized) {
      bHYPRE__CoefficientAccess__init_remote_epv();
    }
    UNLOCK_STATIC_GLOBALS;

    s0->d_bhypre_coefficientaccess.d_epv    = 
      &s_rem_epv__bhypre_coefficientaccess;
    s0->d_bhypre_coefficientaccess.d_object = (void*) self;

    s0->d_sidl_baseinterface.d_epv    = &s_rem_epv__sidl_baseinterface;
    s0->d_sidl_baseinterface.d_object = (void*) self;

    s0->d_data = (void*) r_obj;
    s0->d_epv  = &s_rem_epv__bhypre__coefficientaccess;

    self->d_data = (void*) r_obj;

    sidl_rmi_InstanceHandle_addRef(instance, _ex);
    return bHYPRE_CoefficientAccess__rmicast(self, _ex);
  }
  // 
  // Cast method for interface and class type conversions.
  // 
  struct bHYPRE_CoefficientAccess__object*
  bHYPRE_CoefficientAccess__rmicast(
    void* obj,
    sidl_BaseInterface* _ex)
  {
    struct bHYPRE_CoefficientAccess__object* cast = NULL;

    *_ex = NULL;
    if(!connect_loaded) {
      sidl_rmi_ConnectRegistry_registerConnect("bHYPRE.CoefficientAccess", (
        void*)bHYPRE_CoefficientAccess__IHConnect, _ex);
      connect_loaded = 1;
    }
    if (obj != NULL) {
      struct sidl_BaseInterface__object* base = (struct 
        sidl_BaseInterface__object*) obj;
      cast = (struct bHYPRE_CoefficientAccess__object*) (*base->d_epv->f__cast)(
        base->d_object,
        "bHYPRE.CoefficientAccess", _ex); SIDL_CHECK(*_ex);
    }

    return cast;
    EXIT:
    return NULL;
  }

  // 
  // RMI connector function for the class.
  // 
  struct bHYPRE_CoefficientAccess__object*
  bHYPRE_CoefficientAccess__connectI(const char* url, sidl_bool ar, struct 
    sidl_BaseInterface__object **_ex)
  {
    return bHYPRE_CoefficientAccess__remoteConnect(url, ar, _ex);
  }

}

//////////////////////////////////////////////////
// 
// Special methods for throwing exceptions
// 

void
bHYPRE::CoefficientAccess::throwException0(
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
 * The GetRow method will allocate space for its two output
 * arrays on the first call.  The space will be reused on
 * subsequent calls.  Thus the user must not delete them, yet
 * must not depend on the data from GetRow to persist beyond the
 * next GetRow call.
 */
int32_t
bHYPRE::CoefficientAccess::GetRow( /* in */int32_t row, /* out */int32_t& size, 
  /* out array<int,column-major> */::sidl::array<int32_t>& col_ind, /* out 
  array<double,column-major> */::sidl::array<double>& values )

{
  int32_t _result;
  ior_t* const loc_self = (struct bHYPRE_CoefficientAccess__object*) 
    ::bHYPRE::CoefficientAccess::_get_ior();
  struct sidl_int__array* _local_col_ind;
  struct sidl_double__array* _local_values;
  sidl_BaseInterface__object * _exception;
  /*pack args to dispatch to ior*/
  _result = (*(loc_self->d_epv->f_GetRow))(loc_self->d_object, /* in */ row, /* 
    out */ &size, /* out array<int,column-major> */ &_local_col_ind, /* out 
    array<double,column-major> */ &_local_values, &_exception );
  /*dispatch to ior*/
  if (_exception != 0 ) {

    throwException0(_exception);
  }
  col_ind._set_ior(_local_col_ind);
  values._set_ior(_local_values);
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
::bHYPRE::CoefficientAccess
bHYPRE::CoefficientAccess::_connect(const std::string& url, const bool ar ) {
  ior_t* ior_self;
  struct sidl_BaseInterface__object *_exception;
  ior_self = bHYPRE_CoefficientAccess__remoteConnect( url.c_str(), 
    ar?TRUE:FALSE, &_exception );
  if (_exception != 0 ) {
    throwException0(_exception);
  }
  return ::bHYPRE::CoefficientAccess( ior_self, false );
}

// copy constructor
bHYPRE::CoefficientAccess::CoefficientAccess ( const 
  ::bHYPRE::CoefficientAccess& original ) {
  d_self = (struct bHYPRE_CoefficientAccess__object*) 
    original.::bHYPRE::CoefficientAccess::_get_ior();
  bHYPRE_CoefficientAccess_IORCache = (ior_t*) d_self;
  if(d_self) {
    addRef();
  }
  d_weak_reference = false;
}

// assignment operator
::bHYPRE::CoefficientAccess&
bHYPRE::CoefficientAccess::operator=( const ::bHYPRE::CoefficientAccess& rhs ) {
  if ( d_self != rhs.d_self ) {
    if ( d_self != 0 ) {
      deleteRef();
    }
    d_self = (struct bHYPRE_CoefficientAccess__object*) 
      rhs.::bHYPRE::CoefficientAccess::_get_ior();
    bHYPRE_CoefficientAccess_IORCache = (ior_t*) d_self;
    if(d_self) {
      addRef();
    }
    d_weak_reference = false;
  }
  return *this;
}

// conversion from ior to C++ class
bHYPRE::CoefficientAccess::CoefficientAccess ( 
  ::bHYPRE::CoefficientAccess::ior_t* ior ) 
   : StubBase(reinterpret_cast< void*>(ior)) { 
  bHYPRE_CoefficientAccess_IORCache = (ior_t*) d_self;
}

// Alternate constructor: does not call addRef()
// (sets d_weak_reference=isWeak)
// For internal use by Impls (fixes bug#275)
bHYPRE::CoefficientAccess::CoefficientAccess ( 
  ::bHYPRE::CoefficientAccess::ior_t* ior, bool isWeak ) : 
StubBase(reinterpret_cast< void*>(ior), isWeak){ 
  bHYPRE_CoefficientAccess_IORCache = (ior_t*) d_self;
}

// exec has special argument passing to avoid #include circularities
void ::bHYPRE::CoefficientAccess::_exec( const std::string& methodName, 
                        sidl::rmi::Call& inArgs,
                        sidl::rmi::Return& outArgs) { 
  ::bHYPRE::CoefficientAccess::ior_t* const loc_self = _get_ior();
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
bHYPRE::CoefficientAccess::_getURL(  )
// throws:
//       ::sidl::RuntimeException

{
  ::std::string _result;
  ior_t* const loc_self = (struct bHYPRE_CoefficientAccess__object*) 
    ::bHYPRE::CoefficientAccess::_get_ior();
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
bHYPRE::CoefficientAccess::_set_hooks( /* in */bool on )
// throws:
//       ::sidl::RuntimeException

{

  ior_t* const loc_self = (struct bHYPRE_CoefficientAccess__object*) 
    ::bHYPRE::CoefficientAccess::_get_ior();
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
struct bHYPRE_CoefficientAccess__object* bHYPRE::CoefficientAccess::_cast(const 
  void* src)
{
  ior_t* cast = NULL;

  if(!connect_loaded) {
    struct sidl_BaseInterface__object *throwaway_exception;
    sidl_rmi_ConnectRegistry_registerConnect("bHYPRE.CoefficientAccess", (
      void*)bHYPRE_CoefficientAccess__IHConnect, &throwaway_exception);
    connect_loaded = 1;
  }
  if ( src != 0 ) {
    // Actually, this thing is still const
    void* tmp = const_cast<void*>(src);
    struct sidl_BaseInterface__object *throwaway_exception;
    struct sidl_BaseInterface__object * base = reinterpret_cast< struct 
      sidl_BaseInterface__object *>(tmp);
    cast = reinterpret_cast< ior_t*>((*base->d_epv->f__cast)(base->d_object, 
      "bHYPRE.CoefficientAccess", &throwaway_exception));
  }
  return cast;
}

