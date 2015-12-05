/*
 * File:          bHYPRE_SStructStencil_IOR.c
 * Symbol:        bHYPRE.SStructStencil-v1.0.0
 * Symbol Type:   class
 * Babel Version: 0.8.2
 * SIDL Created:  20030401 14:47:20 PST
 * Generated:     20030401 14:47:24 PST
 * Description:   Intermediate Object Representation for bHYPRE.SStructStencil
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 * babel-version = 0.8.2
 * source-line   = 1001
 * source-url    = file:/home/painter/linear_solvers/babel/Interfaces.idl
 */

#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "bHYPRE_SStructStencil_IOR.h"
#ifndef included_SIDL_BaseClass_Impl_h
#include "SIDL_BaseClass_Impl.h"
#endif
#ifndef included_SIDL_BaseClass_h
#include "SIDL_BaseClass.h"
#endif
#ifndef included_SIDL_ClassInfo_h
#include "SIDL_ClassInfo.h"
#endif
#ifndef included_SIDL_ClassInfoI_h
#include "SIDL_ClassInfoI.h"
#endif

#ifndef NULL
#define NULL 0
#endif

/*
 * Static variables to hold version of IOR
 */

static const int32_t s_IOR_MAJOR_VERSION = 0;
static const int32_t s_IOR_MINOR_VERSION = 8;
/*
 * Static variable to hold shared ClassInfo interface.
 */

static SIDL_ClassInfo s_classInfo = NULL;
static int s_classInfo_init = 1;

/*
 * Static variables for managing EPV initialization.
 */

static int s_method_initialized = 0;
static int s_remote_initialized = 0;

static struct bHYPRE_SStructStencil__epv s_new__bhypre_sstructstencil;
static struct bHYPRE_SStructStencil__epv s_rem__bhypre_sstructstencil;

static struct SIDL_BaseClass__epv  s_new__sidl_baseclass;
static struct SIDL_BaseClass__epv* s_old__sidl_baseclass;
static struct SIDL_BaseClass__epv  s_rem__sidl_baseclass;

static struct SIDL_BaseInterface__epv  s_new__sidl_baseinterface;
static struct SIDL_BaseInterface__epv* s_old__sidl_baseinterface;
static struct SIDL_BaseInterface__epv  s_rem__sidl_baseinterface;

/*
 * Declare EPV routines defined in the skeleton file.
 */

extern void bHYPRE_SStructStencil__set_epv(
  struct bHYPRE_SStructStencil__epv* epv);

/*
 * CAST: dynamic type casting support.
 */

static void* ior_bHYPRE_SStructStencil__cast(
  struct bHYPRE_SStructStencil__object* self,
  const char* name)
{
  void* cast = NULL;

  struct bHYPRE_SStructStencil__object* s0 = self;
  struct SIDL_BaseClass__object*        s1 = &s0->d_sidl_baseclass;

  if (!strcmp(name, "bHYPRE.SStructStencil")) {
    cast = (void*) s0;
  } else if (!strcmp(name, "SIDL.BaseClass")) {
    cast = (void*) s1;
  } else if (!strcmp(name, "SIDL.BaseInterface")) {
    cast = (void*) &s1->d_sidl_baseinterface;
  }

  return cast;
}

/*
 * DELETE: call destructor and free object memory.
 */

static void ior_bHYPRE_SStructStencil__delete(
  struct bHYPRE_SStructStencil__object* self)
{
  bHYPRE_SStructStencil__fini(self);
  memset((void*)self, 0, sizeof(struct bHYPRE_SStructStencil__object));
  free((void*) self);
}

/*
 * EPV: create method entry point vector (EPV) structure.
 */

static void bHYPRE_SStructStencil__init_epv(
  struct bHYPRE_SStructStencil__object* self)
{
  struct bHYPRE_SStructStencil__object* s0 = self;
  struct SIDL_BaseClass__object*        s1 = &s0->d_sidl_baseclass;

  struct bHYPRE_SStructStencil__epv* epv = &s_new__bhypre_sstructstencil;
  struct SIDL_BaseClass__epv*        e0  = &s_new__sidl_baseclass;
  struct SIDL_BaseInterface__epv*    e1  = &s_new__sidl_baseinterface;

  s_old__sidl_baseinterface = s1->d_sidl_baseinterface.d_epv;
  s_old__sidl_baseclass     = s1->d_epv;

  epv->f__cast         = ior_bHYPRE_SStructStencil__cast;
  epv->f__delete       = ior_bHYPRE_SStructStencil__delete;
  epv->f__ctor         = NULL;
  epv->f__dtor         = NULL;
  epv->f_addRef        = (void (*)(struct bHYPRE_SStructStencil__object*)) 
    s1->d_epv->f_addRef;
  epv->f_deleteRef     = (void (*)(struct bHYPRE_SStructStencil__object*)) 
    s1->d_epv->f_deleteRef;
  epv->f_isSame        = (SIDL_bool (*)(struct bHYPRE_SStructStencil__object*,
    struct SIDL_BaseInterface__object*)) s1->d_epv->f_isSame;
  epv->f_queryInt      = (struct SIDL_BaseInterface__object* (*)(struct 
    bHYPRE_SStructStencil__object*,const char*)) s1->d_epv->f_queryInt;
  epv->f_isType        = (SIDL_bool (*)(struct bHYPRE_SStructStencil__object*,
    const char*)) s1->d_epv->f_isType;
  epv->f_getClassInfo  = (struct SIDL_ClassInfo__object* (*)(struct 
    bHYPRE_SStructStencil__object*)) s1->d_epv->f_getClassInfo;
  epv->f_SetNumDimSize = NULL;
  epv->f_SetEntry      = NULL;

  bHYPRE_SStructStencil__set_epv(epv);

  e0->f__cast        = (void* (*)(struct SIDL_BaseClass__object*,
    const char*)) epv->f__cast;
  e0->f__delete      = (void (*)(struct SIDL_BaseClass__object*)) 
    epv->f__delete;
  e0->f_addRef       = (void (*)(struct SIDL_BaseClass__object*)) epv->f_addRef;
  e0->f_deleteRef    = (void (*)(struct SIDL_BaseClass__object*)) 
    epv->f_deleteRef;
  e0->f_isSame       = (SIDL_bool (*)(struct SIDL_BaseClass__object*,
    struct SIDL_BaseInterface__object*)) epv->f_isSame;
  e0->f_queryInt     = (struct SIDL_BaseInterface__object* (*)(struct 
    SIDL_BaseClass__object*,const char*)) epv->f_queryInt;
  e0->f_isType       = (SIDL_bool (*)(struct SIDL_BaseClass__object*,
    const char*)) epv->f_isType;
  e0->f_getClassInfo = (struct SIDL_ClassInfo__object* (*)(struct 
    SIDL_BaseClass__object*)) epv->f_getClassInfo;

  e1->f__cast        = (void* (*)(void*,const char*)) epv->f__cast;
  e1->f__delete      = (void (*)(void*)) epv->f__delete;
  e1->f_addRef       = (void (*)(void*)) epv->f_addRef;
  e1->f_deleteRef    = (void (*)(void*)) epv->f_deleteRef;
  e1->f_isSame       = (SIDL_bool (*)(void*,
    struct SIDL_BaseInterface__object*)) epv->f_isSame;
  e1->f_queryInt     = (struct SIDL_BaseInterface__object* (*)(void*,
    const char*)) epv->f_queryInt;
  e1->f_isType       = (SIDL_bool (*)(void*,const char*)) epv->f_isType;
  e1->f_getClassInfo = (struct SIDL_ClassInfo__object* (*)(void*)) 
    epv->f_getClassInfo;

  s_method_initialized = 1;
}

/*
 * initClassInfo: create a ClassInfo interface if necessary.
 */

static void
initClassInfo(SIDL_ClassInfo *info)
{
  if (s_classInfo_init) {
    SIDL_ClassInfoI impl;
    s_classInfo_init = 0;
    impl = SIDL_ClassInfoI__create();
    s_classInfo = SIDL_ClassInfo__cast(impl);
    if (impl) {
      SIDL_ClassInfoI_setName(impl, "bHYPRE.SStructStencil");
      SIDL_ClassInfoI_setIORVersion(impl, s_IOR_MAJOR_VERSION,
        s_IOR_MINOR_VERSION);
    }
  }
  if (s_classInfo) {
    if (*info) {
      SIDL_ClassInfo_deleteRef(*info);
    }
    *info = s_classInfo;
    SIDL_ClassInfo_addRef(*info);
  }
}

/*
 * initMetadata: store IOR version & class in SIDL.BaseClass's data
 */

static void
initMetadata(struct bHYPRE_SStructStencil__object* self)
{
  if (self) {
    struct SIDL_BaseClass__data *data = 
      SIDL_BaseClass__get_data(SIDL_BaseClass__cast(self));
    if (data) {
      data->d_IOR_major_version = s_IOR_MAJOR_VERSION;
      data->d_IOR_minor_version = s_IOR_MINOR_VERSION;
      initClassInfo(&(data->d_classinfo));
    }
  }
}

/*
 * NEW: allocate object and initialize it.
 */

struct bHYPRE_SStructStencil__object*
bHYPRE_SStructStencil__new(void)
{
  struct bHYPRE_SStructStencil__object* self =
    (struct bHYPRE_SStructStencil__object*) malloc(
      sizeof(struct bHYPRE_SStructStencil__object));
  bHYPRE_SStructStencil__init(self);
  initMetadata(self);
  return self;
}

/*
 * INIT: initialize a new instance of the class object.
 */

void bHYPRE_SStructStencil__init(
  struct bHYPRE_SStructStencil__object* self)
{
  struct bHYPRE_SStructStencil__object* s0 = self;
  struct SIDL_BaseClass__object*        s1 = &s0->d_sidl_baseclass;

  SIDL_BaseClass__init(s1);

  if (!s_method_initialized) {
    bHYPRE_SStructStencil__init_epv(s0);
  }

  s1->d_sidl_baseinterface.d_epv = &s_new__sidl_baseinterface;
  s1->d_epv                      = &s_new__sidl_baseclass;

  s0->d_epv    = &s_new__bhypre_sstructstencil;

  s0->d_data = NULL;

  (*(self->d_epv->f__ctor))(self);
}

/*
 * FINI: deallocate a class instance (destructor).
 */

void bHYPRE_SStructStencil__fini(
  struct bHYPRE_SStructStencil__object* self)
{
  struct bHYPRE_SStructStencil__object* s0 = self;
  struct SIDL_BaseClass__object*        s1 = &s0->d_sidl_baseclass;

  (*(s0->d_epv->f__dtor))(s0);

  s1->d_sidl_baseinterface.d_epv = s_old__sidl_baseinterface;
  s1->d_epv                      = s_old__sidl_baseclass;

  SIDL_BaseClass__fini(s1);
}

/*
 * VERSION: Return the version of the IOR used to generate this IOR.
 */

void
bHYPRE_SStructStencil__IOR_version(int32_t *major, int32_t *minor)
{
  *major = s_IOR_MAJOR_VERSION;
  *minor = s_IOR_MINOR_VERSION;
}
static const struct bHYPRE_SStructStencil__external
s_externalEntryPoints = {
  bHYPRE_SStructStencil__new,
  bHYPRE_SStructStencil__remote,
};

/*
 * This function returns a pointer to a static structure of
 * pointers to function entry points.  Its purpose is to provide
 * one-stop shopping for loading DLLs.
 * loading DLLs
 */

const struct bHYPRE_SStructStencil__external*
bHYPRE_SStructStencil__externals(void)
{
  return &s_externalEntryPoints;
}

/*
 * REMOTE CAST: dynamic type casting for remote objects.
 */

static void* remote_bHYPRE_SStructStencil__cast(
  struct bHYPRE_SStructStencil__object* self,
  const char* name)
{
  return NULL;
}

/*
 * REMOTE DELETE: call the remote destructor for the object.
 */

static void remote_bHYPRE_SStructStencil__delete(
  struct bHYPRE_SStructStencil__object* self)
{
  free((void*) self);
}

/*
 * REMOTE METHOD STUB:addRef
 */

static void
remote_bHYPRE_SStructStencil_addRef(
  struct bHYPRE_SStructStencil__object* self)
{
}

/*
 * REMOTE METHOD STUB:deleteRef
 */

static void
remote_bHYPRE_SStructStencil_deleteRef(
  struct bHYPRE_SStructStencil__object* self)
{
}

/*
 * REMOTE METHOD STUB:isSame
 */

static SIDL_bool
remote_bHYPRE_SStructStencil_isSame(
  struct bHYPRE_SStructStencil__object* self,
  struct SIDL_BaseInterface__object* iobj)
{
  return 0;
}

/*
 * REMOTE METHOD STUB:queryInt
 */

static struct SIDL_BaseInterface__object*
remote_bHYPRE_SStructStencil_queryInt(
  struct bHYPRE_SStructStencil__object* self,
  const char* name)
{
  return (struct SIDL_BaseInterface__object*) 0;
}

/*
 * REMOTE METHOD STUB:isType
 */

static SIDL_bool
remote_bHYPRE_SStructStencil_isType(
  struct bHYPRE_SStructStencil__object* self,
  const char* name)
{
  return 0;
}

/*
 * REMOTE METHOD STUB:getClassInfo
 */

static struct SIDL_ClassInfo__object*
remote_bHYPRE_SStructStencil_getClassInfo(
  struct bHYPRE_SStructStencil__object* self)
{
  return (struct SIDL_ClassInfo__object*) 0;
}

/*
 * REMOTE METHOD STUB:SetNumDimSize
 */

static int32_t
remote_bHYPRE_SStructStencil_SetNumDimSize(
  struct bHYPRE_SStructStencil__object* self,
  int32_t ndim,
  int32_t size)
{
  return 0;
}

/*
 * REMOTE METHOD STUB:SetEntry
 */

static int32_t
remote_bHYPRE_SStructStencil_SetEntry(
  struct bHYPRE_SStructStencil__object* self,
  int32_t entry,
  struct SIDL_int__array* offset,
  int32_t var)
{
  return 0;
}

/*
 * REMOTE EPV: create remote entry point vectors (EPVs).
 */

static void bHYPRE_SStructStencil__init_remote_epv(void)
{
  struct bHYPRE_SStructStencil__epv* epv = &s_rem__bhypre_sstructstencil;
  struct SIDL_BaseClass__epv*        e0  = &s_rem__sidl_baseclass;
  struct SIDL_BaseInterface__epv*    e1  = &s_rem__sidl_baseinterface;

  epv->f__cast         = remote_bHYPRE_SStructStencil__cast;
  epv->f__delete       = remote_bHYPRE_SStructStencil__delete;
  epv->f__ctor         = NULL;
  epv->f__dtor         = NULL;
  epv->f_addRef        = remote_bHYPRE_SStructStencil_addRef;
  epv->f_deleteRef     = remote_bHYPRE_SStructStencil_deleteRef;
  epv->f_isSame        = remote_bHYPRE_SStructStencil_isSame;
  epv->f_queryInt      = remote_bHYPRE_SStructStencil_queryInt;
  epv->f_isType        = remote_bHYPRE_SStructStencil_isType;
  epv->f_getClassInfo  = remote_bHYPRE_SStructStencil_getClassInfo;
  epv->f_SetNumDimSize = remote_bHYPRE_SStructStencil_SetNumDimSize;
  epv->f_SetEntry      = remote_bHYPRE_SStructStencil_SetEntry;

  e0->f__cast        = (void* (*)(struct SIDL_BaseClass__object*,
    const char*)) epv->f__cast;
  e0->f__delete      = (void (*)(struct SIDL_BaseClass__object*)) 
    epv->f__delete;
  e0->f_addRef       = (void (*)(struct SIDL_BaseClass__object*)) epv->f_addRef;
  e0->f_deleteRef    = (void (*)(struct SIDL_BaseClass__object*)) 
    epv->f_deleteRef;
  e0->f_isSame       = (SIDL_bool (*)(struct SIDL_BaseClass__object*,
    struct SIDL_BaseInterface__object*)) epv->f_isSame;
  e0->f_queryInt     = (struct SIDL_BaseInterface__object* (*)(struct 
    SIDL_BaseClass__object*,const char*)) epv->f_queryInt;
  e0->f_isType       = (SIDL_bool (*)(struct SIDL_BaseClass__object*,
    const char*)) epv->f_isType;
  e0->f_getClassInfo = (struct SIDL_ClassInfo__object* (*)(struct 
    SIDL_BaseClass__object*)) epv->f_getClassInfo;

  e1->f__cast        = (void* (*)(void*,const char*)) epv->f__cast;
  e1->f__delete      = (void (*)(void*)) epv->f__delete;
  e1->f_addRef       = (void (*)(void*)) epv->f_addRef;
  e1->f_deleteRef    = (void (*)(void*)) epv->f_deleteRef;
  e1->f_isSame       = (SIDL_bool (*)(void*,
    struct SIDL_BaseInterface__object*)) epv->f_isSame;
  e1->f_queryInt     = (struct SIDL_BaseInterface__object* (*)(void*,
    const char*)) epv->f_queryInt;
  e1->f_isType       = (SIDL_bool (*)(void*,const char*)) epv->f_isType;
  e1->f_getClassInfo = (struct SIDL_ClassInfo__object* (*)(void*)) 
    epv->f_getClassInfo;

  s_remote_initialized = 1;
}

/*
 * REMOTE: generate remote instance given URL string.
 */

struct bHYPRE_SStructStencil__object*
bHYPRE_SStructStencil__remote(const char *url)
{
  struct bHYPRE_SStructStencil__object* self =
    (struct bHYPRE_SStructStencil__object*) malloc(
      sizeof(struct bHYPRE_SStructStencil__object));

  struct bHYPRE_SStructStencil__object* s0 = self;
  struct SIDL_BaseClass__object*        s1 = &s0->d_sidl_baseclass;

  if (!s_remote_initialized) {
    bHYPRE_SStructStencil__init_remote_epv();
  }

  s1->d_sidl_baseinterface.d_epv    = &s_rem__sidl_baseinterface;
  s1->d_sidl_baseinterface.d_object = NULL; /* FIXME */

  s1->d_data = NULL; /* FIXME */
  s1->d_epv  = &s_rem__sidl_baseclass;

  s0->d_data = NULL; /* FIXME */
  s0->d_epv  = &s_rem__bhypre_sstructstencil;

  return self;
}
