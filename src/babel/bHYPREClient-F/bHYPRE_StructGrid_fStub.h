/*
 * File:          bHYPRE_StructGrid_fStub.h
 * Symbol:        bHYPRE.StructGrid-v1.0.0
 * Symbol Type:   class
 * Babel Version: 1.0.4
 * Description:   Client-side documentation text for bHYPRE.StructGrid
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#ifndef included_bHYPRE_StructGrid_fStub_h
#define included_bHYPRE_StructGrid_fStub_h

/**
 * Symbol "bHYPRE.StructGrid" (version 1.0.0)
 * 
 * Define a structured grid class.
 */

#ifndef included_bHYPRE_StructGrid_IOR_h
#include "bHYPRE_StructGrid_IOR.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif


#pragma weak bHYPRE_StructGrid__connectI

#pragma weak bHYPRE_StructGrid__rmicast

/**
 * Cast method for interface and class type conversions.
 */
struct bHYPRE_StructGrid__object*
bHYPRE_StructGrid__rmicast(
  void* obj, struct sidl_BaseInterface__object **_ex);

/**
 * RMI connector function for the class. (no addref)
 */
struct bHYPRE_StructGrid__object*
bHYPRE_StructGrid__connectI(const char * url, sidl_bool ar, struct 
  sidl_BaseInterface__object **_ex);

#ifdef __cplusplus
}
#endif
#endif
