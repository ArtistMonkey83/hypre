/*
 * File:          bHYPRE_IJParCSRMatrix_fStub.h
 * Symbol:        bHYPRE.IJParCSRMatrix-v1.0.0
 * Symbol Type:   class
 * Babel Version: 1.0.4
 * Description:   Client-side documentation text for bHYPRE.IJParCSRMatrix
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#ifndef included_bHYPRE_IJParCSRMatrix_fStub_h
#define included_bHYPRE_IJParCSRMatrix_fStub_h

/**
 * Symbol "bHYPRE.IJParCSRMatrix" (version 1.0.0)
 * 
 * The IJParCSR matrix class.
 * 
 * Objects of this type can be cast to IJMatrixView, Operator, or
 * CoefficientAccess objects using the {\tt \_\_cast} methods.
 */

#ifndef included_bHYPRE_IJParCSRMatrix_IOR_h
#include "bHYPRE_IJParCSRMatrix_IOR.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif


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
