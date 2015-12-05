/*
 * File:          SIDL_BaseException_Skel.c
 * Symbol:        SIDL.BaseException-v0.8.2
 * Symbol Type:   class
 * Babel Version: 0.8.4
 * Release:       $Name: V1-9-0b $
 * Revision:      @(#) $Id: SIDL_BaseException_Skel.c,v 1.4 2003/04/07 21:44:31 painter Exp $
 * Description:   Server-side glue code for SIDL.BaseException
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
 * babel-version = 0.8.4
 */

#include "SIDL_BaseException_IOR.h"
#include "SIDL_BaseException.h"
#include <stddef.h>

extern void
impl_SIDL_BaseException__ctor(
  SIDL_BaseException);

extern void
impl_SIDL_BaseException__dtor(
  SIDL_BaseException);

extern char*
impl_SIDL_BaseException_getNote(
  SIDL_BaseException);

extern void
impl_SIDL_BaseException_setNote(
  SIDL_BaseException,
  const char*);

extern char*
impl_SIDL_BaseException_getTrace(
  SIDL_BaseException);

extern void
impl_SIDL_BaseException_addLine(
  SIDL_BaseException,
  const char*);

extern void
impl_SIDL_BaseException_add(
  SIDL_BaseException,
  const char*,
  int32_t,
  const char*);

void
SIDL_BaseException__set_epv(struct SIDL_BaseException__epv *epv)
{
  epv->f__ctor = impl_SIDL_BaseException__ctor;
  epv->f__dtor = impl_SIDL_BaseException__dtor;
  epv->f_getNote = impl_SIDL_BaseException_getNote;
  epv->f_setNote = impl_SIDL_BaseException_setNote;
  epv->f_getTrace = impl_SIDL_BaseException_getTrace;
  epv->f_addLine = impl_SIDL_BaseException_addLine;
  epv->f_add = impl_SIDL_BaseException_add;
}

struct SIDL_BaseException__data*
SIDL_BaseException__get_data(SIDL_BaseException self)
{
  return (struct SIDL_BaseException__data*)(self ? self->d_data : NULL);
}

void SIDL_BaseException__set_data(
  SIDL_BaseException self,
  struct SIDL_BaseException__data* data)
{
  if (self) {
    self->d_data = data;
  }
}
