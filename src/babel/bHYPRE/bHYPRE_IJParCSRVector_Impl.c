/*
 * File:          bHYPRE_IJParCSRVector_Impl.c
 * Symbol:        bHYPRE.IJParCSRVector-v1.0.0
 * Symbol Type:   class
 * Babel Version: 0.8.2
 * SIDL Created:  20030401 14:47:20 PST
 * Generated:     20030401 14:47:33 PST
 * Description:   Server-side implementation for bHYPRE.IJParCSRVector
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 * babel-version = 0.8.2
 * source-line   = 815
 * source-url    = file:/home/painter/linear_solvers/babel/Interfaces.idl
 */

/*
 * DEVELOPERS ARE EXPECTED TO PROVIDE IMPLEMENTATIONS
 * FOR THE FOLLOWING METHODS BETWEEN SPLICER PAIRS.
 */

/*
 * Symbol "bHYPRE.IJParCSRVector" (version 1.0.0)
 * 
 * The IJParCSR vector class.
 * 
 * Objects of this type can be cast to IJBuildVector or Vector
 * objects using the {\tt \_\_cast} methods.
 * 
 */

#include "bHYPRE_IJParCSRVector_Impl.h"

/* DO-NOT-DELETE splicer.begin(bHYPRE.IJParCSRVector._includes) */
/* Put additional includes or other arbitrary code here... */
#include <assert.h>
#include "parcsr_mv.h"
#include "bHYPRE_IJBuildVector.h"
#include "mpi.h"
/* DO-NOT-DELETE splicer.end(bHYPRE.IJParCSRVector._includes) */

/*
 * Class constructor called when the class is created.
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_IJParCSRVector__ctor"

void
impl_bHYPRE_IJParCSRVector__ctor(
  bHYPRE_IJParCSRVector self)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.IJParCSRVector._ctor) */
  /* Insert the implementation of the constructor method here... */

   struct bHYPRE_IJParCSRVector__data * data;
   data = hypre_CTAlloc( struct bHYPRE_IJParCSRVector__data, 1 );
   data -> comm = MPI_COMM_NULL;
   data -> ij_b = NULL;
   bHYPRE_IJParCSRVector__set_data( self, data );

  /* DO-NOT-DELETE splicer.end(bHYPRE.IJParCSRVector._ctor) */
}

/*
 * Class destructor called when the class is deleted.
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_IJParCSRVector__dtor"

void
impl_bHYPRE_IJParCSRVector__dtor(
  bHYPRE_IJParCSRVector self)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.IJParCSRVector._dtor) */
  /* Insert the implementation of the destructor method here... */

   int ierr = 0;
   struct bHYPRE_IJParCSRVector__data * data;
   HYPRE_IJVector ij_b;
   data = bHYPRE_IJParCSRVector__get_data( self );
   ij_b = data -> ij_b;
   ierr = HYPRE_IJVectorDestroy( ij_b );
   assert( ierr==0 );
   hypre_TFree( data );

  /* DO-NOT-DELETE splicer.end(bHYPRE.IJParCSRVector._dtor) */
}

/*
 * Set {\tt self} to 0.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_IJParCSRVector_Clear"

int32_t
impl_bHYPRE_IJParCSRVector_Clear(
  bHYPRE_IJParCSRVector self)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.IJParCSRVector.Clear) */
  /* Insert the implementation of the Clear method here... */

   int ierr = 0;
   void * object;
   struct bHYPRE_IJParCSRVector__data * data;
   HYPRE_ParVector xx;
   HYPRE_IJVector ij_x;
   data = bHYPRE_IJParCSRVector__get_data( self );
   ij_x = data -> ij_b;

   ierr += HYPRE_IJVectorGetObject( ij_x, &object );
   xx = (HYPRE_ParVector) object;
   ierr += HYPRE_ParVectorSetConstantValues( xx, 0 );

   return( ierr );

  /* DO-NOT-DELETE splicer.end(bHYPRE.IJParCSRVector.Clear) */
}

/*
 * Copy x into {\tt self}.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_IJParCSRVector_Copy"

int32_t
impl_bHYPRE_IJParCSRVector_Copy(
  bHYPRE_IJParCSRVector self, bHYPRE_Vector x)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.IJParCSRVector.Copy) */
  /* Insert the implementation of the Copy method here... */

   /* Copy the contents of x onto self.  This is a deep copy,
    * ultimately done by hypre_SeqVectorCopy.  */
   int ierr = 0;
   int type[1]; /* type[0] produces silly error messages on Sun */
   void * objectx, * objecty;
   struct bHYPRE_IJParCSRVector__data * data_y, * data_x;
   HYPRE_IJVector ij_y, ij_x;
   bHYPRE_IJParCSRVector bHYPREP_x;
   HYPRE_ParVector yy, xx;
   
   /* A bHYPRE_Vector is just an interface, we have no knowledge of its
    * contents.  Check whether it's something we know how to handle.
    * If not, die. */
   if ( bHYPRE_Vector_queryInt(x, "bHYPRE.IJParCSRVector" ) )
   {
      bHYPREP_x = bHYPRE_IJParCSRVector__cast( x );
   }
   else
   {
      assert( "Unrecognized vector type."==(char *)x );
   }

   data_y = bHYPRE_IJParCSRVector__get_data( self );
   data_x = bHYPRE_IJParCSRVector__get_data( bHYPREP_x );
   bHYPRE_IJParCSRVector_deleteRef( bHYPREP_x ); /* extra reference from queryInt */

   data_y->comm = data_x->comm;

   ij_x = data_x -> ij_b;
   ij_y = data_y -> ij_b;

   ierr += HYPRE_IJVectorGetObjectType( ij_y, type );
   /* ... don't know how to deal with other types */
   assert( *type == HYPRE_PARCSR );
   ierr += HYPRE_IJVectorGetObject( ij_y, &objecty );
   yy = (HYPRE_ParVector) objecty;

   ierr += HYPRE_IJVectorGetObjectType( ij_x, type );
   /* ... don't know how to deal with other types */
   assert( *type == HYPRE_PARCSR );
   ierr += HYPRE_IJVectorGetObject( ij_x, &objectx );
   xx = (HYPRE_ParVector) objectx;

   ierr += HYPRE_ParVectorCopy( xx, yy );

   return( ierr );

  /* DO-NOT-DELETE splicer.end(bHYPRE.IJParCSRVector.Copy) */
}

/*
 * Create an {\tt x} compatible with {\tt self}.
 * 
 * NOTE: When this method is used in an inherited class, the
 * cloned {\tt Vector} object can be cast to an object with the
 * inherited class type.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_IJParCSRVector_Clone"

int32_t
impl_bHYPRE_IJParCSRVector_Clone(
  bHYPRE_IJParCSRVector self, bHYPRE_Vector* x)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.IJParCSRVector.Clone) */
  /* Insert the implementation of the Clone method here... */

   int ierr = 0;
   int type[1];  /* type[0] produces silly error messages on Sun */
   int * partitioning, jlower, jupper, my_id;
   void * objectx, * objecty;
   struct bHYPRE_IJParCSRVector__data * data_y, * data_x;
   HYPRE_IJVector ij_y, ij_x;
   bHYPRE_IJBuildVector bHYPRE_ij_x;
   bHYPRE_IJParCSRVector bHYPREP_x;
   HYPRE_ParVector yy, xx;

   MPI_Comm_rank(MPI_COMM_WORLD, &my_id );

   bHYPREP_x = bHYPRE_IJParCSRVector__create();
   bHYPRE_ij_x = bHYPRE_IJBuildVector__cast( bHYPREP_x );

   data_y = bHYPRE_IJParCSRVector__get_data( self );
   data_x = bHYPRE_IJParCSRVector__get_data( bHYPREP_x );

   data_x->comm = data_y->comm;

   ij_y = data_y -> ij_b;
   ierr = HYPRE_IJVectorGetLocalRange( ij_y, &jlower, &jupper );

   ij_x = data_x->ij_b;
   ierr += HYPRE_IJVectorCreate( data_x->comm, jlower, jupper, &ij_x );
   ierr += HYPRE_IJVectorSetObjectType( ij_x, HYPRE_PARCSR );
   ierr += HYPRE_IJVectorInitialize( ij_x );
   data_x->ij_b = ij_x;

   ierr += HYPRE_IJVectorGetObjectType( ij_y, type );
   /* ... don't know how to deal with other types */
   assert( *type == HYPRE_PARCSR );
   ierr += HYPRE_IJVectorGetObject( ij_y, &objecty );
   yy = (HYPRE_ParVector) objecty;

   ierr += HYPRE_IJVectorGetObjectType( ij_x, type );
   /* ... don't know how to deal with other types */
   assert( *type == HYPRE_PARCSR );
   ierr += HYPRE_IJVectorGetObject( ij_x, &objectx );
   xx = (HYPRE_ParVector) objectx;

   /* Copy data in y to x... */
   HYPRE_ParVectorCopy( yy, xx );

   ierr += bHYPRE_IJBuildVector_Initialize( bHYPRE_ij_x );

   *x = bHYPRE_Vector__cast( bHYPRE_ij_x );

   return( ierr );

  /* DO-NOT-DELETE splicer.end(bHYPRE.IJParCSRVector.Clone) */
}

/*
 * Scale {\tt self} by {\tt a}.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_IJParCSRVector_Scale"

int32_t
impl_bHYPRE_IJParCSRVector_Scale(
  bHYPRE_IJParCSRVector self, double a)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.IJParCSRVector.Scale) */
  /* Insert the implementation of the Scale method here... */

   int ierr = 0;
   void * object;
   struct bHYPRE_IJParCSRVector__data * data;
   HYPRE_ParVector xx;
   HYPRE_IJVector ij_x;
   data = bHYPRE_IJParCSRVector__get_data( self );
   ij_x = data -> ij_b;

   ierr += HYPRE_IJVectorGetObject( ij_x, &object );
   xx = (HYPRE_ParVector) object;
   ierr += HYPRE_ParVectorScale( a, xx );

  /* DO-NOT-DELETE splicer.end(bHYPRE.IJParCSRVector.Scale) */
}

/*
 * Compute {\tt d}, the inner-product of {\tt self} and {\tt x}.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_IJParCSRVector_Dot"

int32_t
impl_bHYPRE_IJParCSRVector_Dot(
  bHYPRE_IJParCSRVector self, bHYPRE_Vector x, double* d)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.IJParCSRVector.Dot) */
  /* Insert the implementation of the Dot method here... */

   int ierr = 0;
   void * object;
   struct bHYPRE_IJParCSRVector__data * data;
   bHYPRE_IJParCSRVector bHYPREP_x;
   HYPRE_ParVector xx, yy;
   HYPRE_IJVector ij_x, ij_y;

   /* A bHYPRE_Vector is just an interface, we have no knowledge of its
    * contents.  Check whether it's something we know how to handle.
    * If not, die. */
   if ( bHYPRE_Vector_queryInt(x, "bHYPRE.IJParCSRVector" ) )
   {
      bHYPREP_x = bHYPRE_IJParCSRVector__cast( x );
   }
   else
   {
      assert( "Unrecognized vector type."==(char *)x );
   }

   data = bHYPRE_IJParCSRVector__get_data( self );
   ij_y = data -> ij_b;
   data = bHYPRE_IJParCSRVector__get_data( bHYPREP_x );
   bHYPRE_IJParCSRVector_deleteRef( bHYPREP_x );
   ij_x = data -> ij_b;

   ierr += HYPRE_IJVectorGetObject( ij_x, &object );
   xx = (HYPRE_ParVector) object;
   ierr += HYPRE_IJVectorGetObject( ij_y, &object );
   yy = (HYPRE_ParVector) object;

   ierr += HYPRE_ParVectorInnerProd( xx, yy, d );

   return( ierr );

  /* DO-NOT-DELETE splicer.end(bHYPRE.IJParCSRVector.Dot) */
}

/*
 * Add {\tt a}*{\tt x} to {\tt self}.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_IJParCSRVector_Axpy"

int32_t
impl_bHYPRE_IJParCSRVector_Axpy(
  bHYPRE_IJParCSRVector self, double a, bHYPRE_Vector x)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.IJParCSRVector.Axpy) */
  /* Insert the implementation of the Axpy method here... */

   int ierr = 0;
   int type[1];
   void * object;
   struct bHYPRE_IJParCSRVector__data * data, * data_x;
   bHYPRE_IJParCSRVector bHYPREP_x;
   HYPRE_IJVector ij_y, ij_x;
   HYPRE_ParVector yy, xx;
   data = bHYPRE_IJParCSRVector__get_data( self );
   ij_y = data -> ij_b;

   ierr += HYPRE_IJVectorGetObjectType( ij_y, type );
   /* ... don't know how to deal with other types */
   assert( *type == HYPRE_PARCSR );
   ierr += HYPRE_IJVectorGetObject( ij_y, &object );
   yy = (HYPRE_ParVector) object;

   /* A bHYPRE_Vector is just an interface, we have no knowledge of its
    * contents.  Check whether it's something we know how to handle.
    * If not, die. */
   if ( bHYPRE_Vector_queryInt(x, "bHYPRE.IJParCSRVector" ) )
   {
      bHYPREP_x = bHYPRE_IJParCSRVector__cast( x );
   }
   else
   {
      assert( "Unrecognized vector type."==(char *)x );
   }

   data_x = bHYPRE_IJParCSRVector__get_data( bHYPREP_x );
   bHYPRE_IJParCSRVector_deleteRef( bHYPREP_x );
   ij_x = data_x->ij_b;
   ierr += HYPRE_IJVectorGetObjectType( ij_x, type );
   /* ... don't know how to deal with other types */
   assert( *type == HYPRE_PARCSR );
   ierr += HYPRE_IJVectorGetObject( ij_x, &object );
   xx = (HYPRE_ParVector) object;

   ierr += hypre_ParVectorAxpy( a, (hypre_ParVector *) xx,
                                (hypre_ParVector *) yy );

   return( ierr );

  /* DO-NOT-DELETE splicer.end(bHYPRE.IJParCSRVector.Axpy) */
}

/*
 * Set the MPI Communicator.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_IJParCSRVector_SetCommunicator"

int32_t
impl_bHYPRE_IJParCSRVector_SetCommunicator(
  bHYPRE_IJParCSRVector self, void* mpi_comm)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.IJParCSRVector.SetCommunicator) */
  /* Insert the implementation of the SetCommunicator method here... */

   int ierr = 0;
   struct bHYPRE_IJParCSRVector__data * data;
   data = bHYPRE_IJParCSRVector__get_data( self );
   data -> comm = (MPI_Comm) mpi_comm;
   return ierr;

  /* DO-NOT-DELETE splicer.end(bHYPRE.IJParCSRVector.SetCommunicator) */
}

/*
 * Prepare an object for setting coefficient values, whether for
 * the first time or subsequently.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_IJParCSRVector_Initialize"

int32_t
impl_bHYPRE_IJParCSRVector_Initialize(
  bHYPRE_IJParCSRVector self)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.IJParCSRVector.Initialize) */
  /* Insert the implementation of the Initialize method here... */

   int ierr = 0;
   struct bHYPRE_IJParCSRVector__data * data;
   HYPRE_IJVector ij_b;
   data = bHYPRE_IJParCSRVector__get_data( self );
   ij_b = data -> ij_b;
   ierr = HYPRE_IJVectorInitialize( ij_b );
   return( ierr );

  /* DO-NOT-DELETE splicer.end(bHYPRE.IJParCSRVector.Initialize) */
}

/*
 * Finalize the construction of an object before using, either
 * for the first time or on subsequent uses. {\tt Initialize}
 * and {\tt Assemble} always appear in a matched set, with
 * Initialize preceding Assemble. Values can only be set in
 * between a call to Initialize and Assemble.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_IJParCSRVector_Assemble"

int32_t
impl_bHYPRE_IJParCSRVector_Assemble(
  bHYPRE_IJParCSRVector self)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.IJParCSRVector.Assemble) */
  /* Insert the implementation of the Assemble method here... */

   int ierr = 0;
   struct bHYPRE_IJParCSRVector__data * data;
   HYPRE_IJVector ij_b;
   data = bHYPRE_IJParCSRVector__get_data( self );
   ij_b = data -> ij_b;

   ierr = HYPRE_IJVectorAssemble( ij_b );
   return( ierr );

  /* DO-NOT-DELETE splicer.end(bHYPRE.IJParCSRVector.Assemble) */
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

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_IJParCSRVector_GetObject"

int32_t
impl_bHYPRE_IJParCSRVector_GetObject(
  bHYPRE_IJParCSRVector self, SIDL_BaseInterface* A)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.IJParCSRVector.GetObject) */
  /* Insert the implementation of the GetObject method here... */

   bHYPRE_IJParCSRVector_addRef( self );
   *A = SIDL_BaseInterface__cast( self );
   return( 0 );

  /* DO-NOT-DELETE splicer.end(bHYPRE.IJParCSRVector.GetObject) */
}

/*
 * Set the local range for a vector object.  Each process owns
 * some unique consecutive range of vector unknowns, indicated
 * by the global indices {\tt jlower} and {\tt jupper}.  The
 * data is required to be such that the value of {\tt jlower} on
 * any process $p$ be exactly one more than the value of {\tt
 * jupper} on process $p-1$.  Note that the first index of the
 * global vector may start with any integer value.  In
 * particular, one may use zero- or one-based indexing.
 * 
 * Collective.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_IJParCSRVector_SetLocalRange"

int32_t
impl_bHYPRE_IJParCSRVector_SetLocalRange(
  bHYPRE_IJParCSRVector self, int32_t jlower, int32_t jupper)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.IJParCSRVector.SetLocalRange) */
  /* Insert the implementation of the SetLocalRange method here... */

   int ierr = 0;
   struct bHYPRE_IJParCSRVector__data * data;
   HYPRE_IJVector ij_b;
   data = bHYPRE_IJParCSRVector__get_data( self );
   ij_b = data -> ij_b;
   /* SetCommunicator should be called before Create */
   assert( data->comm != MPI_COMM_NULL );

   ierr = HYPRE_IJVectorCreate( data->comm, jlower, jupper, &ij_b );
   ierr += HYPRE_IJVectorSetObjectType( ij_b, HYPRE_PARCSR );
   data -> ij_b = ij_b;

   return( ierr );

  /* DO-NOT-DELETE splicer.end(bHYPRE.IJParCSRVector.SetLocalRange) */
}

/*
 * Sets values in vector.  The arrays {\tt values} and {\tt
 * indices} are of dimension {\tt nvalues} and contain the
 * vector values to be set and the corresponding global vector
 * indices, respectively.  Erases any previous values at the
 * specified locations and replaces them with new ones.
 * 
 * Not collective.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_IJParCSRVector_SetValues"

int32_t
impl_bHYPRE_IJParCSRVector_SetValues(
  bHYPRE_IJParCSRVector self, int32_t nvalues, struct SIDL_int__array* indices,
    struct SIDL_double__array* values)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.IJParCSRVector.SetValues) */
  /* Insert the implementation of the SetValues method here... */

   int ierr = 0;
   struct bHYPRE_IJParCSRVector__data * data;
   HYPRE_IJVector ij_b;
   data = bHYPRE_IJParCSRVector__get_data( self );
   ij_b = data -> ij_b;

   ierr = HYPRE_IJVectorSetValues( ij_b, nvalues,
                                   SIDLArrayAddr1( indices, 0 ),
                                   SIDLArrayAddr1( values, 0 ) );
   return( ierr );

  /* DO-NOT-DELETE splicer.end(bHYPRE.IJParCSRVector.SetValues) */
}

/*
 * Adds to values in vector.  Usage details are analogous to
 * {\tt SetValues}.
 * 
 * Not collective.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_IJParCSRVector_AddToValues"

int32_t
impl_bHYPRE_IJParCSRVector_AddToValues(
  bHYPRE_IJParCSRVector self, int32_t nvalues, struct SIDL_int__array* indices,
    struct SIDL_double__array* values)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.IJParCSRVector.AddToValues) */
  /* Insert the implementation of the AddToValues method here... */

   int ierr = 0;
   struct bHYPRE_IJParCSRVector__data * data;
   HYPRE_IJVector ij_b;
   data = bHYPRE_IJParCSRVector__get_data( self );
   ij_b = data->ij_b;

   ierr = HYPRE_IJVectorAddToValues( ij_b, nvalues,
                                     SIDLArrayAddr1( indices, 0 ),
                                     SIDLArrayAddr1( values, 0 ) );
   return( ierr );

  /* DO-NOT-DELETE splicer.end(bHYPRE.IJParCSRVector.AddToValues) */
}

/*
 * Returns range of the part of the vector owned by this
 * processor.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_IJParCSRVector_GetLocalRange"

int32_t
impl_bHYPRE_IJParCSRVector_GetLocalRange(
  bHYPRE_IJParCSRVector self, int32_t* jlower, int32_t* jupper)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.IJParCSRVector.GetLocalRange) */
  /* Insert the implementation of the GetLocalRange method here... */

   int ierr = 0;
   struct bHYPRE_IJParCSRVector__data * data;
   HYPRE_IJVector ij_b;
   data = bHYPRE_IJParCSRVector__get_data( self );
   ij_b = data -> ij_b;

   ierr = HYPRE_IJVectorGetLocalRange( ij_b, jlower, jupper );

   return( ierr );

  /* DO-NOT-DELETE splicer.end(bHYPRE.IJParCSRVector.GetLocalRange) */
}

/*
 * Gets values in vector.  Usage details are analogous to {\tt
 * SetValues}.
 * 
 * Not collective.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_IJParCSRVector_GetValues"

int32_t
impl_bHYPRE_IJParCSRVector_GetValues(
  bHYPRE_IJParCSRVector self, int32_t nvalues, struct SIDL_int__array* indices,
    struct SIDL_double__array** values)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.IJParCSRVector.GetValues) */
  /* Insert the implementation of the GetValues method here... */

   int ierr = 0;
   struct bHYPRE_IJParCSRVector__data * data;
   HYPRE_IJVector ij_b;
   data = bHYPRE_IJParCSRVector__get_data( self );
   ij_b = data -> ij_b;

   ierr = HYPRE_IJVectorGetValues( ij_b, nvalues,
                                   SIDLArrayAddr1( indices, 0 ),
                                   SIDLArrayAddr1( *values, 0 ) );
   return( ierr );

  /* DO-NOT-DELETE splicer.end(bHYPRE.IJParCSRVector.GetValues) */
}

/*
 * Print the vector to file.  This is mainly for debugging
 * purposes.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_IJParCSRVector_Print"

int32_t
impl_bHYPRE_IJParCSRVector_Print(
  bHYPRE_IJParCSRVector self, const char* filename)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.IJParCSRVector.Print) */
  /* Insert the implementation of the Print method here... */

   int ierr = 0;
   struct bHYPRE_IJParCSRVector__data * data;
   HYPRE_IJVector ij_b;
   data = bHYPRE_IJParCSRVector__get_data( self );
   ij_b = data->ij_b;

   ierr = HYPRE_IJVectorPrint( ij_b, filename );

   return ierr;

  /* DO-NOT-DELETE splicer.end(bHYPRE.IJParCSRVector.Print) */
}

/*
 * Read the vector from file.  This is mainly for debugging
 * purposes.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_IJParCSRVector_Read"

int32_t
impl_bHYPRE_IJParCSRVector_Read(
  bHYPRE_IJParCSRVector self, const char* filename, void* comm)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.IJParCSRVector.Read) */
  /* Insert the implementation of the Read method here... */

   int ierr = 0;
   struct bHYPRE_IJParCSRVector__data * data;
   HYPRE_IJVector ij_b;
   data = bHYPRE_IJParCSRVector__get_data( self );
   ij_b = data->ij_b;

   /* HYPRE_IJVectorRead will make a new one */
   ierr = HYPRE_IJVectorDestroy( ij_b );

   ierr = HYPRE_IJVectorRead( filename, data->comm,
                              HYPRE_PARCSR, &ij_b );
   data->ij_b = ij_b;
   bHYPRE_IJParCSRVector__set_data( self, data );

   return( ierr );

  /* DO-NOT-DELETE splicer.end(bHYPRE.IJParCSRVector.Read) */
}
