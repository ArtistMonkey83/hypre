/*
 * File:          bHYPRE_GMRES_Impl.c
 * Symbol:        bHYPRE.GMRES-v1.0.0
 * Symbol Type:   class
 * Babel Version: 0.8.2
 * SIDL Created:  20030401 14:47:20 PST
 * Generated:     20030401 14:47:31 PST
 * Description:   Server-side implementation for bHYPRE.GMRES
 * 
 * WARNING: Automatically generated; only changes within splicers preserved
 * 
 * babel-version = 0.8.2
 * source-line   = 1247
 * source-url    = file:/home/painter/linear_solvers/babel/Interfaces.idl
 */

/*
 * DEVELOPERS ARE EXPECTED TO PROVIDE IMPLEMENTATIONS
 * FOR THE FOLLOWING METHODS BETWEEN SPLICER PAIRS.
 */

/*
 * Symbol "bHYPRE.GMRES" (version 1.0.0)
 * 
 * Objects of this type can be cast to PreconditionedSolver objects
 * using the {\tt \_\_cast} methods.
 * 
 * RDF: Documentation goes here.
 * 
 */

#include "bHYPRE_GMRES_Impl.h"

/* DO-NOT-DELETE splicer.begin(bHYPRE.GMRES._includes) */
/* Put additional includes or other arbitrary code here... */
#include "bHYPRE_IJParCSRMatrix.h"
#include "bHYPRE_IJParCSRMatrix_Impl.h"
#include "bHYPRE_IJParCSRVector.h"
#include "bHYPRE_IJParCSRVector_Impl.h"
#include "bHYPRE_BoomerAMG.h"
#include "bHYPRE_BoomerAMG_Impl.h"
#include "bHYPRE_ParCSRDiagScale.h"
#include "bHYPRE_ParCSRDiagScale_Impl.h"
#include <assert.h>
#include "mpi.h"

/* >>> To do: impl_bHYPRE_GMRES_Copy_Parameters_from_HYPRE_struct (see
 * comments in bHYPRE_PCG_Impl.c). */

int impl_bHYPRE_GMRES_Copy_Parameters_to_HYPRE_struct( bHYPRE_GMRES self )
/* Copy parameter cache from the bHYPRE_GMRES__data object into the
 * HYPRE_Solver object */
/* >>> Possible BUG if this routine is not called earlier (at
 * initialization).  See comment in bHYPRE_PCG_Impl.c */
{
   int ierr = 0;
   HYPRE_Solver solver;
   struct bHYPRE_GMRES__data * data;

   data = bHYPRE_GMRES__get_data( self );
   assert( data->solver != NULL );
   solver = data->solver;

   /* double parameters: */
   ierr += HYPRE_GMRESSetTol( solver, data->tol );

   /* int parameters: */
   ierr += HYPRE_GMRESSetKDim( solver, data->k_dim );
   ierr += HYPRE_GMRESSetMaxIter( solver, data->max_iter );
   ierr += HYPRE_GMRESSetMinIter( solver, data->min_iter );
   ierr += HYPRE_GMRESSetRelChange( solver, data->rel_change );
   ierr += HYPRE_GMRESSetStopCrit( solver, data->stop_crit );

   ierr += HYPRE_GMRESSetPrintLevel( solver, data->printlevel );
   ierr += HYPRE_GMRESSetLogging( solver, data->log_level );

   return ierr;
}

/* DO-NOT-DELETE splicer.end(bHYPRE.GMRES._includes) */

/*
 * Class constructor called when the class is created.
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_GMRES__ctor"

void
impl_bHYPRE_GMRES__ctor(
  bHYPRE_GMRES self)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.GMRES._ctor) */
  /* Insert the implementation of the constructor method here... */

   struct bHYPRE_GMRES__data * data;
   data = hypre_CTAlloc( struct bHYPRE_GMRES__data, 1 );
   data -> comm = MPI_COMM_NULL;
   data -> solver = NULL;
   data -> matrix = NULL;
   data -> vector_type = NULL;
   /* We would like to call HYPRE_<vector type>GMRESCreate at this
    * point, but it's impossible until we know the vector type.
    * That's needed because the C-language Krylov solvers need to be
    * told exactly what functions to call.  If we were to switch to a
    * Babel-based GMRES solver, we would be able to use generic
    * function names; hence we could really initialize GMRES here. */

   /* default values (copied from gmres.c; better to get them by
    * function calls)...*/
   data -> tol        = 1.0e-06;
   data -> k_dim      = 5;
   data -> min_iter   = 0;
   data -> max_iter   = 1000;
   data -> rel_change = 0;
   data -> stop_crit  = 0; /* rel. residual norm */

   /* set any other data components here */

   bHYPRE_PCG__set_data( self, data );

  /* DO-NOT-DELETE splicer.end(bHYPRE.GMRES._ctor) */
}

/*
 * Class destructor called when the class is deleted.
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_GMRES__dtor"

void
impl_bHYPRE_GMRES__dtor(
  bHYPRE_GMRES self)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.GMRES._dtor) */
  /* Insert the implementation of the destructor method here... */

   int ierr = 0;
   struct bHYPRE_GMRES__data * data;
   data = bHYPRE_GMRES__get_data( self );

   if ( data->vector_type == "ParVector" )
   {
      ierr += HYPRE_ParCSRGMRESDestroy( data->solver );
   }
   /* To Do: support more vector types */
   else
   {
      /* Unsupported vector type.  We're unlikely to reach this point. */
      ierr++;
   }
   bHYPRE_Operator_deleteRef( data->matrix );
   /* delete any nontrivial data components here */
   hypre_TFree( data );

  /* DO-NOT-DELETE splicer.end(bHYPRE.GMRES._dtor) */
}

/*
 * Set the MPI Communicator.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_GMRES_SetCommunicator"

int32_t
impl_bHYPRE_GMRES_SetCommunicator(
  bHYPRE_GMRES self, void* mpi_comm)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.GMRES.SetCommunicator) */
  /* Insert the implementation of the SetCommunicator method here... */

   int ierr = 0;
   struct bHYPRE_GMRES__data * data;
   data = bHYPRE_GMRES__get_data( self );
   data -> comm = (MPI_Comm) mpi_comm;

   return ierr;

  /* DO-NOT-DELETE splicer.end(bHYPRE.GMRES.SetCommunicator) */
}

/*
 * Set the int parameter associated with {\tt name}.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_GMRES_SetIntParameter"

int32_t
impl_bHYPRE_GMRES_SetIntParameter(
  bHYPRE_GMRES self, const char* name, int32_t value)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.GMRES.SetIntParameter) */
  /* Insert the implementation of the SetIntParameter method here... */

   /* The normal way to implement this function would be to call the
    * corresponding HYPRE function to set the parameter.  That can't
    * always be done because the HYPRE struct may not exist.  The
    * HYPRE struct may not exist because it can't be created until we
    * know the vector type - and that is not known until Apply is
    * first called.  So what we do is save the parameter in a cache
    * belonging to this Babel interface, and copy it into the HYPRE
    * struct once Apply is called.  */
   int ierr = 0;
   struct bHYPRE_GMRES__data * data;
   data = bHYPRE_GMRES__get_data( self );

   if ( strcmp(name,"KDim")==0 )
   {
      data -> k_dim = value;
   }
   else if ( strcmp(name,"MinIter")==0 )
   {
      data -> min_iter = value;
   }
   else if ( strcmp(name,"RelChange")==0 )
   {
      data -> rel_change = value;
   }
   else
   {
      ierr=1;
   }

   return ierr;

  /* DO-NOT-DELETE splicer.end(bHYPRE.GMRES.SetIntParameter) */
}

/*
 * Set the double parameter associated with {\tt name}.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_GMRES_SetDoubleParameter"

int32_t
impl_bHYPRE_GMRES_SetDoubleParameter(
  bHYPRE_GMRES self, const char* name, double value)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.GMRES.SetDoubleParameter) */
  /* Insert the implementation of the SetDoubleParameter method here... */

   /* The normal way to implement this function would be to call the
    * corresponding HYPRE function to set the parameter.  That can't
    * always be done because the HYPRE struct may not exist.  The
    * HYPRE struct may not exist because it can't be created until we
    * know the vector type - and that is not known until Apply is
    * first called.  So what we do is save the parameter in a cache
    * belonging to this Babel interface, and copy it into the HYPRE
    * struct once Apply is called.  */
   int ierr = 0;
   struct bHYPRE_GMRES__data * data;
   data = bHYPRE_GMRES__get_data( self );

   ierr = 1;

   return ierr;

  /* DO-NOT-DELETE splicer.end(bHYPRE.GMRES.SetDoubleParameter) */
}

/*
 * Set the string parameter associated with {\tt name}.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_GMRES_SetStringParameter"

int32_t
impl_bHYPRE_GMRES_SetStringParameter(
  bHYPRE_GMRES self, const char* name, const char* value)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.GMRES.SetStringParameter) */
  /* Insert the implementation of the SetStringParameter method here... */

   return 1;

  /* DO-NOT-DELETE splicer.end(bHYPRE.GMRES.SetStringParameter) */
}

/*
 * Set the int 1-D array parameter associated with {\tt name}.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_GMRES_SetIntArray1Parameter"

int32_t
impl_bHYPRE_GMRES_SetIntArray1Parameter(
  bHYPRE_GMRES self, const char* name, struct SIDL_int__array* value)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.GMRES.SetIntArray1Parameter) */
  /* Insert the implementation of the SetIntArray1Parameter method here... */
   return 1;
  /* DO-NOT-DELETE splicer.end(bHYPRE.GMRES.SetIntArray1Parameter) */
}

/*
 * Set the int 2-D array parameter associated with {\tt name}.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_GMRES_SetIntArray2Parameter"

int32_t
impl_bHYPRE_GMRES_SetIntArray2Parameter(
  bHYPRE_GMRES self, const char* name, struct SIDL_int__array* value)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.GMRES.SetIntArray2Parameter) */
  /* Insert the implementation of the SetIntArray2Parameter method here... */
   return 1;
  /* DO-NOT-DELETE splicer.end(bHYPRE.GMRES.SetIntArray2Parameter) */
}

/*
 * Set the double 1-D array parameter associated with {\tt name}.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_GMRES_SetDoubleArray1Parameter"

int32_t
impl_bHYPRE_GMRES_SetDoubleArray1Parameter(
  bHYPRE_GMRES self, const char* name, struct SIDL_double__array* value)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.GMRES.SetDoubleArray1Parameter) */
  /* Insert the implementation of the SetDoubleArray1Parameter method here... */
   return 1;
  /* DO-NOT-DELETE splicer.end(bHYPRE.GMRES.SetDoubleArray1Parameter) */
}

/*
 * Set the double 2-D array parameter associated with {\tt name}.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_GMRES_SetDoubleArray2Parameter"

int32_t
impl_bHYPRE_GMRES_SetDoubleArray2Parameter(
  bHYPRE_GMRES self, const char* name, struct SIDL_double__array* value)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.GMRES.SetDoubleArray2Parameter) */
  /* Insert the implementation of the SetDoubleArray2Parameter method here... */
  /* DO-NOT-DELETE splicer.end(bHYPRE.GMRES.SetDoubleArray2Parameter) */
}

/*
 * Set the int parameter associated with {\tt name}.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_GMRES_GetIntValue"

int32_t
impl_bHYPRE_GMRES_GetIntValue(
  bHYPRE_GMRES self, const char* name, int32_t* value)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.GMRES.GetIntValue) */
  /* Insert the implementation of the GetIntValue method here... */

   /* >>> We should add a Get for everything in SetParameter.  There
    * are two values for each parameter: the bHYPRE cache, and the
    * HYPRE value.  The cache gets copied to HYPRE when Apply is
    * called.  What we want to return is the cache value if the
    * corresponding Set had been called, otherwise the real (HYPRE)
    * value.  Assuming the HYPRE interface is not used simultaneously
    * with the Babel interface, it is sufficient to initialize the
    * cache with whatever HYPRE is using. */
   int ierr = 0;
   HYPRE_Solver solver;
   struct bHYPRE_GMRES__data * data;

   data = bHYPRE_GMRES__get_data( self );
   assert( data->solver != NULL );
   solver = data->solver;

   ierr = 1;

   return ierr;

  /* DO-NOT-DELETE splicer.end(bHYPRE.GMRES.GetIntValue) */
}

/*
 * Get the double parameter associated with {\tt name}.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_GMRES_GetDoubleValue"

int32_t
impl_bHYPRE_GMRES_GetDoubleValue(
  bHYPRE_GMRES self, const char* name, double* value)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.GMRES.GetDoubleValue) */
  /* Insert the implementation of the GetDoubleValue method here... */

   /* >>> We should add a Get for everything in SetParameter.  There
    * are two values for each parameter: the bHYPRE cache, and the
    * HYPRE value.  The cache gets copied to HYPRE when Apply is
    * called.  What we want to return is the cache value if the
    * corresponding Set had been called, otherwise the real (HYPRE)
    * value.  Assuming the HYPRE interface is not used simultaneously
    * with the Babel interface, it is sufficient to initialize the
    * cache with whatever HYPRE is using. */
   int ierr = 0;
   HYPRE_Solver solver;
   struct bHYPRE_GMRES__data * data;

   data = bHYPRE_GMRES__get_data( self );
   assert( data->solver != NULL );
   solver = data->solver;

   ierr = 1;

   return ierr;

  /* DO-NOT-DELETE splicer.end(bHYPRE.GMRES.GetDoubleValue) */
}

/*
 * (Optional) Do any preprocessing that may be necessary in
 * order to execute {\tt Apply}.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_GMRES_Setup"

int32_t
impl_bHYPRE_GMRES_Setup(
  bHYPRE_GMRES self, bHYPRE_Vector b, bHYPRE_Vector x)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.GMRES.Setup) */
  /* Insert the implementation of the Setup method here... */

   int ierr=0;
   MPI_Comm comm;
   HYPRE_Solver solver;
   HYPRE_Solver * psolver = &solver; /* will get a real value later */
   struct bHYPRE_GMRES__data * data;
   bHYPRE_Operator mat;
   HYPRE_Matrix HYPRE_A;
   bHYPRE_IJParCSRMatrix bHYPREP_A;
   HYPRE_ParCSRMatrix AA;
   HYPRE_IJMatrix ij_A;
   HYPRE_Vector HYPRE_x, HYPRE_b;
   bHYPRE_IJParCSRVector bHYPREP_b, bHYPREP_x;
   HYPRE_ParVector bb, xx;
   HYPRE_IJVector ij_b, ij_x;
   struct bHYPRE_IJParCSRMatrix__data * dataA;
   struct bHYPRE_IJParCSRVector__data * datab, * datax;
   void * objectA, * objectb, * objectx;

   data = bHYPRE_GMRES__get_data( self );
   comm = data->comm;
   /* SetCommunicator should have been called earlier */
   assert( comm != MPI_COMM_NULL );
   mat = data->matrix;
   /* SetOperator should have been called earlier */
   assert( mat != NULL );

   if ( data -> vector_type == NULL )
   {
      /* This is the first time this Babel GMRES object has seen a
       * vector.  So we are ready to create the bHYPRE GMRES object. */
      if ( bHYPRE_Vector_queryInt( b, "bHYPRE.IJParCSRVector") )
      {
         bHYPRE_Vector_deleteRef( b );  /* extra ref created by queryInt */
         data -> vector_type = "ParVector";
         HYPRE_ParCSRGMRESCreate( comm, psolver );
         assert( solver != NULL );
         data -> solver = *psolver;
      }
      /* Add more vector types here */
      else
      {
         assert( "only IJParCSRVector supported by GMRES"==0 );
      }
      bHYPRE_GMRES__set_data( self, data );
   }
   else
   {
      solver = data->solver;
      assert( solver != NULL );
   }
   /* The SetParameter functions set parameters in the local
    * Babel-interface struct, "data".  That is because the HYPRE
    * struct (where they are actually used) may not exist yet when the
    * functions are called.  At this point we finally know the HYPRE
    * struct exists, so we copy the parameters to it. */
   ierr += impl_bHYPRE_GMRES_Copy_Parameters_to_HYPRE_struct( self );
   if ( data->vector_type == "ParVector" )
   {
      bHYPREP_b = bHYPRE_IJParCSRVector__cast
         ( bHYPRE_Vector_queryInt( b, "bHYPRE.IJParCSRVector") );
      datab = bHYPRE_IJParCSRVector__get_data( bHYPREP_b );
      bHYPRE_IJParCSRVector_deleteRef( bHYPREP_b );
      ij_b = datab -> ij_b;
      ierr += HYPRE_IJVectorGetObject( ij_b, &objectb );
      bb = (HYPRE_ParVector) objectb;
      HYPRE_b = (HYPRE_Vector) bb;

      bHYPREP_x = bHYPRE_IJParCSRVector__cast
         ( bHYPRE_Vector_queryInt( x, "bHYPRE.IJParCSRVector") );
      datax = bHYPRE_IJParCSRVector__get_data( bHYPREP_x );
      bHYPRE_IJParCSRVector_deleteRef( bHYPREP_x );
      ij_x = datax -> ij_b;
      ierr += HYPRE_IJVectorGetObject( ij_x, &objectx );
      xx = (HYPRE_ParVector) objectx;
      HYPRE_x = (HYPRE_Vector) xx;

      bHYPREP_A = bHYPRE_IJParCSRMatrix__cast
         ( bHYPRE_Operator_queryInt( mat, "bHYPRE.IJParCSRMatrix") );
      assert( bHYPREP_A != NULL );
      dataA = bHYPRE_IJParCSRMatrix__get_data( bHYPREP_A );
      ij_A = dataA -> ij_A;
      bHYPRE_IJParCSRMatrix_deleteRef( bHYPREP_A );
      ierr += HYPRE_IJMatrixGetObject( ij_A, &objectA );
      AA = (HYPRE_ParCSRMatrix) objectA;
      HYPRE_A = (HYPRE_Matrix) AA;
   }
   else
   {
      assert( "only IJParCSRVector supported by GMRES"==0 );
   }
      
   ierr += HYPRE_GMRESSetPrecond( solver, data->precond, data->precond_setup,
                                  *(data->solverprecond) );
   HYPRE_GMRESSetup( solver, HYPRE_A, HYPRE_b, HYPRE_x );

   return ierr;

  /* DO-NOT-DELETE splicer.end(bHYPRE.GMRES.Setup) */
}

/*
 * Apply the operator to {\tt b}, returning {\tt x}.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_GMRES_Apply"

int32_t
impl_bHYPRE_GMRES_Apply(
  bHYPRE_GMRES self, bHYPRE_Vector b, bHYPRE_Vector* x)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.GMRES.Apply) */
  /* Insert the implementation of the Apply method here... */

   /* In the long run, the solver should be implemented right here,
    * calling the appropriate bHYPRE functions.  But for now we are
    * calling the existing HYPRE solver.  Advantages: don't want to
    * have two versions of the same GMRES solver lying around.
    * Disadvantage: we have to cache user-supplied parameters until
    * the Apply call, where we make the GMRES object and really set
    * the parameters - messy and unnatural. */
   int ierr=0;
   MPI_Comm comm;
   HYPRE_Solver solver;
   HYPRE_Solver * psolver = &solver; /* will get a real value later */
   struct bHYPRE_GMRES__data * data;
   bHYPRE_Operator mat;
   HYPRE_Matrix HYPRE_A;
   bHYPRE_IJParCSRMatrix bHYPREP_A;
   HYPRE_ParCSRMatrix AA;
   HYPRE_IJMatrix ij_A;
   HYPRE_Vector HYPRE_x, HYPRE_b;
   bHYPRE_IJParCSRVector bHYPREP_b, bHYPREP_x;
   HYPRE_ParVector bb, xx;
   HYPRE_IJVector ij_b, ij_x;
   struct bHYPRE_IJParCSRMatrix__data * dataA;
   struct bHYPRE_IJParCSRVector__data * datab, * datax;
   void * objectA, * objectb, * objectx;

   data = bHYPRE_GMRES__get_data( self );
   comm = data->comm;
   /* SetCommunicator should have been called earlier */
   assert( comm != MPI_COMM_NULL );
   mat = data->matrix;
   /* SetOperator should have been called earlier */
   assert( mat != NULL );

   if ( data -> vector_type == NULL )
   {
      /* This is the first time this Babel GMRES object has seen a
       * vector.  So we are ready to create the bHYPRE GMRES object. */
      if ( bHYPRE_Vector_queryInt( b, "bHYPRE.IJParCSRVector") )
      {
         bHYPRE_Vector_deleteRef( b ); /* extra ref created by queryInt */
         data -> vector_type = "ParVector";
         HYPRE_ParCSRGMRESCreate( comm, psolver );
         assert( solver != NULL );
         data -> solver = *psolver;
      }
      /* Add more vector types here */
      else
      {
         assert( "only IJParCSRVector supported by GMRES"==0 );
      }
      bHYPRE_GMRES__set_data( self, data );
   }
   else
   {
      solver = data->solver;
      assert( solver != NULL );
   }
   /* The SetParameter functions set parameters in the local
    * Babel-interface struct, "data".  That is because the HYPRE
    * struct (where they are actually used) may not exist yet when the
    * functions are called.  At this point we finally know the HYPRE
    * struct exists, so we copy the parameters to it. */
   ierr += impl_bHYPRE_GMRES_Copy_Parameters_to_HYPRE_struct( self );
   if ( data->vector_type == "ParVector" )
   {
      bHYPREP_b = bHYPRE_IJParCSRVector__cast
         ( bHYPRE_Vector_queryInt( b, "bHYPRE.IJParCSRVector") );
      datab = bHYPRE_IJParCSRVector__get_data( bHYPREP_b );
      bHYPRE_IJParCSRVector_deleteRef( bHYPREP_b );
      ij_b = datab -> ij_b;
      ierr += HYPRE_IJVectorGetObject( ij_b, &objectb );
      bb = (HYPRE_ParVector) objectb;
      HYPRE_b = (HYPRE_Vector) bb;

      bHYPREP_x = bHYPRE_IJParCSRVector__cast
         ( bHYPRE_Vector_queryInt( *x, "bHYPRE.IJParCSRVector") );
      datax = bHYPRE_IJParCSRVector__get_data( bHYPREP_x );
      bHYPRE_IJParCSRVector_deleteRef( bHYPREP_x );
      ij_x = datax -> ij_b;
      ierr += HYPRE_IJVectorGetObject( ij_x, &objectx );
      xx = (HYPRE_ParVector) objectx;
      HYPRE_x = (HYPRE_Vector) xx;

      bHYPREP_A = bHYPRE_IJParCSRMatrix__cast
         ( bHYPRE_Operator_queryInt( mat, "bHYPRE.IJParCSRMatrix") );
      assert( bHYPREP_A != NULL );
      dataA = bHYPRE_IJParCSRMatrix__get_data( bHYPREP_A );
      bHYPRE_IJParCSRMatrix_deleteRef( bHYPREP_A );
      ij_A = dataA -> ij_A;
      ierr += HYPRE_IJMatrixGetObject( ij_A, &objectA );
      AA = (HYPRE_ParCSRMatrix) objectA;
      HYPRE_A = (HYPRE_Matrix) AA;
   }
   else
   {
      assert( "only IJParCSRVector supported by GMRES"==0 );
   }
      
   ierr += HYPRE_GMRESSetPrecond( solver, data->precond, data->precond_setup,
                                  *(data->solverprecond) );

   HYPRE_GMRESSolve( solver, HYPRE_A, HYPRE_b, HYPRE_x );

   return ierr;

  /* DO-NOT-DELETE splicer.end(bHYPRE.GMRES.Apply) */
}

/*
 * Set the operator for the linear system being solved.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_GMRES_SetOperator"

int32_t
impl_bHYPRE_GMRES_SetOperator(
  bHYPRE_GMRES self, bHYPRE_Operator A)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.GMRES.SetOperator) */
  /* Insert the implementation of the SetOperator method here... */
   int ierr = 0;
   struct bHYPRE_GMRES__data * data;

   data = bHYPRE_GMRES__get_data( self );
   data->matrix = A;

   return ierr;
  /* DO-NOT-DELETE splicer.end(bHYPRE.GMRES.SetOperator) */
}

/*
 * (Optional) Set the convergence tolerance.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_GMRES_SetTolerance"

int32_t
impl_bHYPRE_GMRES_SetTolerance(
  bHYPRE_GMRES self, double tolerance)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.GMRES.SetTolerance) */
  /* Insert the implementation of the SetTolerance method here... */

   int ierr = 0;
   struct bHYPRE_GMRES__data * data;
   data = bHYPRE_GMRES__get_data( self );

   data -> tol = tolerance;

   return ierr;

  /* DO-NOT-DELETE splicer.end(bHYPRE.GMRES.SetTolerance) */
}

/*
 * (Optional) Set maximum number of iterations.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_GMRES_SetMaxIterations"

int32_t
impl_bHYPRE_GMRES_SetMaxIterations(
  bHYPRE_GMRES self, int32_t max_iterations)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.GMRES.SetMaxIterations) */
  /* Insert the implementation of the SetMaxIterations method here... */

   int ierr = 0;
   struct bHYPRE_GMRES__data * data;
   data = bHYPRE_GMRES__get_data( self );

   data -> max_iter = max_iterations;

   return ierr;

  /* DO-NOT-DELETE splicer.end(bHYPRE.GMRES.SetMaxIterations) */
}

/*
 * (Optional) Set the {\it logging level}, specifying the degree
 * of additional informational data to be accumulated.  Does
 * nothing by default (level = 0).  Other levels (if any) are
 * implementation-specific.  Must be called before {\tt Setup}
 * and {\tt Apply}.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_GMRES_SetLogging"

int32_t
impl_bHYPRE_GMRES_SetLogging(
  bHYPRE_GMRES self, int32_t level)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.GMRES.SetLogging) */
  /* Insert the implementation of the SetLogging method here... */
   int ierr = 0;
   struct bHYPRE_GMRES__data * data;
   data = bHYPRE_GMRES__get_data( self );

   data -> log_level = level;

   return ierr;
  /* DO-NOT-DELETE splicer.end(bHYPRE.GMRES.SetLogging) */
}

/*
 * (Optional) Set the {\it print level}, specifying the degree
 * of informational data to be printed either to the screen or
 * to a file.  Does nothing by default (level=0).  Other levels
 * (if any) are implementation-specific.  Must be called before
 * {\tt Setup} and {\tt Apply}.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_GMRES_SetPrintLevel"

int32_t
impl_bHYPRE_GMRES_SetPrintLevel(
  bHYPRE_GMRES self, int32_t level)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.GMRES.SetPrintLevel) */
  /* Insert the implementation of the SetPrintLevel method here... */

   /* The normal way to implement this function would be to call the
    * corresponding HYPRE function to set the print level.  That can't
    * always be done because the HYPRE struct may not exist.  The
    * HYPRE struct may not exist because it can't be created until we
    * know the vector type - and that is not known until Apply is
    * first called.  So what we do is save the print level in a cache
    * belonging to this Babel interface, and copy it into the HYPRE
    * struct once Apply is called.  */
   int ierr = 0;
   struct bHYPRE_GMRES__data * data;
   data = bHYPRE_GMRES__get_data( self );

   data -> printlevel = level;

   return ierr;

  /* DO-NOT-DELETE splicer.end(bHYPRE.GMRES.SetPrintLevel) */
}

/*
 * (Optional) Return the number of iterations taken.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_GMRES_GetNumIterations"

int32_t
impl_bHYPRE_GMRES_GetNumIterations(
  bHYPRE_GMRES self, int32_t* num_iterations)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.GMRES.GetNumIterations) */
  /* Insert the implementation of the GetNumIterations method here... */

   int ierr = 0;
   HYPRE_Solver solver;
   struct bHYPRE_GMRES__data * data;

   data = bHYPRE_GMRES__get_data( self );
   assert( data->solver != NULL );
   solver = data->solver;

   ierr += HYPRE_GMRESGetNumIterations( solver, num_iterations );

   return ierr;

  /* DO-NOT-DELETE splicer.end(bHYPRE.GMRES.GetNumIterations) */
}

/*
 * (Optional) Return the norm of the relative residual.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_GMRES_GetRelResidualNorm"

int32_t
impl_bHYPRE_GMRES_GetRelResidualNorm(
  bHYPRE_GMRES self, double* norm)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.GMRES.GetRelResidualNorm) */
  /* Insert the implementation of the GetRelResidualNorm method here... */

   int ierr = 0;
   HYPRE_Solver solver;
   struct bHYPRE_GMRES__data * data;

   data = bHYPRE_GMRES__get_data( self );
   assert( data->solver != NULL );
   solver = data->solver;

   ierr += HYPRE_GMRESGetFinalRelativeResidualNorm( solver, norm );

   return ierr;

  /* DO-NOT-DELETE splicer.end(bHYPRE.GMRES.GetRelResidualNorm) */
}

/*
 * Set the preconditioner.
 * 
 */

#undef __FUNC__
#define __FUNC__ "impl_bHYPRE_GMRES_SetPreconditioner"

int32_t
impl_bHYPRE_GMRES_SetPreconditioner(
  bHYPRE_GMRES self, bHYPRE_Solver s)
{
  /* DO-NOT-DELETE splicer.begin(bHYPRE.GMRES.SetPreconditioner) */
  /* Insert the implementation of the SetPreconditioner method here... */

   int ierr = 0;
   HYPRE_Solver * solverprecond;
   struct bHYPRE_GMRES__data * dataself;
   struct bHYPRE_BoomerAMG__data * AMG_dataprecond;
   bHYPRE_BoomerAMG AMG_s;
   HYPRE_PtrToSolverFcn precond, precond_setup; /* functions */

   dataself = bHYPRE_GMRES__get_data( self );

   if ( bHYPRE_Solver_queryInt( s, "bHYPRE.BoomerAMG" ) )
   {
      /* s is a bHYPRE_BoomerAMG */
      AMG_s = bHYPRE_BoomerAMG__cast
         ( bHYPRE_Solver_queryInt( s, "bHYPRE.BoomerAMG") );
      AMG_dataprecond = bHYPRE_BoomerAMG__get_data( AMG_s );
      solverprecond = &AMG_dataprecond->solver;
      assert( solverprecond != NULL );
      precond = (HYPRE_PtrToSolverFcn) HYPRE_BoomerAMGSolve;
      precond_setup = (HYPRE_PtrToSolverFcn) HYPRE_BoomerAMGSetup;
      bHYPRE_BoomerAMG_deleteRef( AMG_s ); /* extra reference from queryInt */
   }
   else if ( bHYPRE_Solver_queryInt( s, "bHYPRE.ParCSRDiagScale" ) )
   {
      bHYPRE_Solver_deleteRef( s ); /* extra reference from queryInt */
      solverprecond = (HYPRE_Solver *) hypre_CTAlloc( double, 1 );
      /* ... HYPRE diagonal scaling needs no solver object, but we
       * must provide a HYPRE_Solver object.  It will be totally
       * ignored. */
      precond = (HYPRE_PtrToSolverFcn) HYPRE_ParCSRDiagScale;
      precond_setup = (HYPRE_PtrToSolverFcn) HYPRE_ParCSRDiagScaleSetup;
   }
   /* put other preconditioner types here */
   else
   {
      assert( "GMRES_SetPreconditioner cannot recognize preconditioner"==0 );
   }

   /* We can't actually set the HYPRE preconditioner, because that
    * requires knowing what the solver object is - but that requires
    * knowing its data type but _that_ requires knowing the kind of
    * matrix and vectors we'll need; not known until Apply is called.
    * So save the information in the bHYPRE data structure, and stick
    * it in HYPRE later... */
   dataself->precond = precond;
   dataself->precond_setup = precond_setup;
   dataself->solverprecond = solverprecond;
   /* For an example call, see test/IJ_linear_solvers.c, line 1686.
    * The four arguments are: self's (solver) data; and, for the
    * preconditioner: solver function, setup function, data */

   return ierr;

  /* DO-NOT-DELETE splicer.end(bHYPRE.GMRES.SetPreconditioner) */
}
