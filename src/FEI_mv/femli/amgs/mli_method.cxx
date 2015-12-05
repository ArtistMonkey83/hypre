/*BHEADER**********************************************************************
 * Copyright (c) 2006   The Regents of the University of California.
 * Produced at the Lawrence Livermore National Laboratory.
 * Written by the HYPRE team. UCRL-CODE-222953.
 * All rights reserved.
 *
 * This file is part of HYPRE (see http://www.llnl.gov/CASC/hypre/).
 * Please see the COPYRIGHT_and_LICENSE file for the copyright notice, 
 * disclaimer, contact information and the GNU Lesser General Public License.
 *
 * HYPRE is free software; you can redistribute it and/or modify it under the 
 * terms of the GNU General Public License (as published by the Free Software
 * Foundation) version 2.1 dated February 1999.
 *
 * HYPRE is distributed in the hope that it will be useful, but WITHOUT ANY 
 * WARRANTY; without even the IMPLIED WARRANTY OF MERCHANTABILITY or FITNESS 
 * FOR A PARTICULAR PURPOSE.  See the terms and conditions of the GNU General
 * Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * $Revision: 1.8 $
 ***********************************************************************EHEADER*/




/******************************************************************************
 *
 * functions for creating MLI_Method 
 *
 *****************************************************************************/

/*--------------------------------------------------------------------------
 * include files 
 *--------------------------------------------------------------------------*/

#ifdef WIN32
#define strcmp _stricmp
#endif

#include <string.h>
#include "amgs/mli_method.h"
#include "amgs/mli_method_amgsa.h"
#include "amgs/mli_method_amgrs.h"
#include "amgs/mli_method_amgcr.h"

/*****************************************************************************
 * constructor
 *--------------------------------------------------------------------------*/

MLI_Method::MLI_Method( MPI_Comm comm ) 
{ 
   mpiComm_ = comm; 
   methodID_ = -1; 
   strcpy(methodName_, "MLI_NONE");
}

/*****************************************************************************
 * destructor
 *--------------------------------------------------------------------------*/

MLI_Method::~MLI_Method() 
{ 
}

/*****************************************************************************
 * virtual setup function
 *--------------------------------------------------------------------------*/

int MLI_Method::setup( MLI *mli ) 
{
   (void) mli; 
   return -1;
}

/*****************************************************************************
 * virtual set parameter function
 *--------------------------------------------------------------------------*/

int MLI_Method::setParams(char *name, int argc, char *argv[])
{
   (void) name; 
   (void) argc;
   (void) argv;
   return -1;
}

/*****************************************************************************
 * virtual get parameter function
 *--------------------------------------------------------------------------*/

int MLI_Method::getParams(char *name, int *argc, char *argv[])
{
   (void) name;
   (void) argc;
   (void) argv;
   return -1;
}

/*****************************************************************************
 * get method name
 *--------------------------------------------------------------------------*/

char *MLI_Method::getName()
{
   return methodName_;
}

/*****************************************************************************
 * set method name
 *--------------------------------------------------------------------------*/

int MLI_Method::setName( char *inName )                                      
{
   strcpy(methodName_, inName);
   return 0;
}

/*****************************************************************************
 * set method ID
 *--------------------------------------------------------------------------*/

int MLI_Method::setID( int inID )                                      
{
   methodID_ = inID;
   return 0;
}

/*****************************************************************************
 * get method ID
 *--------------------------------------------------------------------------*/

int MLI_Method::getID()
{
   return methodID_;
}

/*****************************************************************************
 * get communicator 
 *--------------------------------------------------------------------------*/

MPI_Comm MLI_Method::getComm()
{
   return mpiComm_;
}

/*****************************************************************************
 * create a method from method name
 *--------------------------------------------------------------------------*/

MLI_Method *MLI_Method_CreateFromName( char *str, MPI_Comm comm )
{
   MLI_Method *methodPtr;
   char       paramString[80];

   if ( !strcmp(str, "AMGSA" ) )
   {
      methodPtr  = new MLI_Method_AMGSA(comm);
   }
   else if ( !strcmp(str, "AMGSAe" ) )
   {
      methodPtr  = new MLI_Method_AMGSA(comm);
      strcpy( paramString, "useSAMGe" );
      methodPtr->setParams( paramString, 0, NULL );
   }
   else if ( !strcmp(str, "AMGSADD" ) )
   {
      methodPtr  = new MLI_Method_AMGSA(comm);
      strcpy( paramString, "useSAMGDD" );
      methodPtr->setParams( paramString, 0, NULL );
      strcpy( paramString, "setNumLevels 2" );
      methodPtr->setParams( paramString, 0, NULL );
   }
   else if ( !strcmp(str, "AMGSADDe" ) )
   {
      methodPtr  = new MLI_Method_AMGSA(comm);
      strcpy( paramString, "useSAMGe" );
      methodPtr->setParams( paramString, 0, NULL );
      strcpy( paramString, "useSAMGDD" );
      methodPtr->setParams( paramString, 0, NULL );
      strcpy( paramString, "setNumLevels 2" );
      methodPtr->setParams( paramString, 0, NULL );
   }
   else if ( !strcmp(str, "AMGRS" ) )
   {
      methodPtr  = new MLI_Method_AMGRS(comm);
   }
   else if ( !strcmp(str, "AMGCR" ) )
   {
      methodPtr  = new MLI_Method_AMGCR(comm);
   }
   else
   {
      printf("MLI_Method_Create ERROR : method %s not defined.\n", str);
      printf("    valid ones are : \n\n");
      printf("    (1) AMGSA (%d)\n", MLI_METHOD_AMGSA_ID); 
      printf("    (2) AMGSAe (%d)\n", MLI_METHOD_AMGSAE_ID); 
      printf("    (3) AMGSADD (%d)\n", MLI_METHOD_AMGSADD_ID); 
      printf("    (4) AMGSADDe (%d)\n", MLI_METHOD_AMGSADDE_ID); 
      printf("    (5) AMGRS (%d)\n", MLI_METHOD_AMGRS_ID); 
      printf("    (6) AMGCR (%d)\n", MLI_METHOD_AMGCR_ID); 
      exit(1);
   }
   return methodPtr;
}

/*****************************************************************************
 * create a method from method ID
 *--------------------------------------------------------------------------*/

MLI_Method *MLI_Method_CreateFromID( int methodID, MPI_Comm comm )
{
   MLI_Method *methodPtr;
   char       paramString[80];

   switch ( methodID )
   {
      case MLI_METHOD_AMGSA_ID :
           methodPtr = new MLI_Method_AMGSA(comm);
           break;
      case MLI_METHOD_AMGSAE_ID :
           methodPtr = new MLI_Method_AMGSA(comm);
           strcpy( paramString, "useSAMGe" );
           methodPtr->setParams(paramString, 0, NULL);
           break;
      case MLI_METHOD_AMGSADD_ID :
           methodPtr = new MLI_Method_AMGSA(comm);
           strcpy( paramString, "useSAMGDD" );
           methodPtr->setParams(paramString, 0, NULL);
           strcpy( paramString, "setNumLevels 2" );
           methodPtr->setParams(paramString, 0, NULL);
           break;
      case MLI_METHOD_AMGSADDE_ID :
           methodPtr = new MLI_Method_AMGSA(comm);
           strcpy( paramString, "useSAMGe" );
           methodPtr->setParams(paramString, 0, NULL);
           strcpy( paramString, "useSAMGDD" );
           methodPtr->setParams(paramString, 0, NULL);
           strcpy( paramString, "setNumLevels 2" );
           methodPtr->setParams(paramString, 0, NULL);
           break;
      case MLI_METHOD_AMGRS_ID :
           methodPtr  = new MLI_Method_AMGRS(comm);
           break;
      case MLI_METHOD_AMGCR_ID :
           methodPtr  = new MLI_Method_AMGCR(comm);
           break;
      default :
           printf("MLI_Method_Create ERROR : method %d not defined\n",
                  methodID);
           printf("    valid ones are : \n\n");
           printf("    (1) AMGSA (%d)\n", MLI_METHOD_AMGSA_ID); 
           printf("    (2) AMGSAe (%d)\n", MLI_METHOD_AMGSAE_ID); 
           printf("    (3) AMGSADD (%d)\n", MLI_METHOD_AMGSADD_ID); 
           printf("    (4) AMGSADDe (%d)\n", MLI_METHOD_AMGSADDE_ID); 
           printf("    (5) AMGRS (%d)\n", MLI_METHOD_AMGRS_ID); 
           printf("    (6) AMGCR (%d)\n", MLI_METHOD_AMGCR_ID); 
           exit(1);
   }
   return methodPtr;
}

