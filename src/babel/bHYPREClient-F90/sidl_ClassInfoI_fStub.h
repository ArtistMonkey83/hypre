/*
 * File:          sidl_ClassInfoI_fStub.h
 * Symbol:        sidl.ClassInfoI-v0.9.15
 * Symbol Type:   class
 * Babel Version: 1.0.0
 * Release:       $Name: V2-4-0b $
 * Revision:      @(#) $Id: sidl_ClassInfoI_fStub.h,v 1.1 2007/02/06 01:23:06 painter Exp $
 * Description:   Client-side documentation text for sidl.ClassInfoI
 * 
 * Copyright (c) 2000-2002, The Regents of the University of California.
 * Produced at the Lawrence Livermore National Laboratory.
 * Written by the Components Team <components@llnl.gov>
 * All rights reserved.
 * 
 * This file is part of Babel. For more information, see
 * http://www.llnl.gov/CASC/components/. Please read the COPYRIGHT file
 * for Our Notice and the LICENSE file for the GNU Lesser General Public
 * License.
 * 
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License (as published by
 * the Free Software Foundation) version 2.1 dated February 1999.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the IMPLIED WARRANTY OF
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the terms and
 * conditions of the GNU Lesser General Public License for more details.
 * 
 * You should have recieved a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 * 
 * WARNING: Automatically generated; changes will be lost
 * 
 */

#ifndef included_sidl_ClassInfoI_fStub_h
#define included_sidl_ClassInfoI_fStub_h

/**
 * Symbol "sidl.ClassInfoI" (version 0.9.15)
 * 
 *  
 * An implementation of the <code>ClassInfo</code> interface. This
 * provides methods to set all the attributes that are read-only in
 * the <code>ClassInfo</code> interface.
 */

#ifndef included_sidl_ClassInfoI_IOR_h
#include "sidl_ClassInfoI_IOR.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif


#pragma weak sidl_ClassInfoI__connectI

#pragma weak sidl_ClassInfoI__rmicast

/**
 * Cast method for interface and class type conversions.
 */
struct sidl_ClassInfoI__object*
sidl_ClassInfoI__rmicast(
  void* obj, struct sidl_BaseInterface__object **_ex);

/**
 * RMI connector function for the class. (no addref)
 */
struct sidl_ClassInfoI__object*
sidl_ClassInfoI__connectI(const char * url, sidl_bool ar,
  struct sidl_BaseInterface__object **_ex);

#ifdef __cplusplus
}
#endif
#endif
