/*BHEADER**********************************************************************
 * (c) 2000   The Regents of the University of California
 *
 * See the file COPYRIGHT_and_DISCLAIMER for a complete copyright
 * notice, contact person, and disclaimer.
 *
 * $Revision: 2.0 $
 *********************************************************************EHEADER*/

/******************************************************************************
 *
 * Preconditioned conjugate gradient (Omin) headers
 *
 *****************************************************************************/

#ifndef HYPRE_KRYLOV_PCG_HEADER
#define HYPRE_KRYLOV_PCG_HEADER

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

/**
 * @name Generic PCG Interface
 *
 * A general description of the interface goes here...
 *
 * @memo A generic PCG linear solver interface
 * @version 0.1
 * @author Jeffrey F. Painter
 **/
/*@{*/

/*--------------------------------------------------------------------------
 *--------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
 * hypre_PCGData and hypre_PCGFunctions
 *--------------------------------------------------------------------------*/


/**
 * @name PCG structs
 *
 * Description...
 **/
/*@{*/

/**
 * The {\tt hypre\_PCGSFunctions} object ...
 **/

typedef struct
{
   char * (*CAlloc)        ( int count, int elt_size );
   int    (*Free)          ( char *ptr );
   void * (*CreateVector)  ( void *vector );
   int    (*DestroyVector) ( void *vector );
   void * (*MatvecCreate)  ( void *A, void *x );
   int    (*Matvec)        ( void *matvec_data, double alpha, void *A,
                             void *x, double beta, void *y );
   int    (*MatvecDestroy) ( void *matvec_data );
   double (*InnerProd)     ( void *x, void *y );
   int    (*CopyVector)    ( void *x, void *y );
   int    (*ClearVector)   ( void *x );
   int    (*ScaleVector)   ( double alpha, void *x );
   int    (*Axpy)          ( double alpha, void *x, void *y );

   int    (*precond)();
   int    (*precond_setup)();
} hypre_PCGFunctions;

/**
 * The {\tt hypre\_PCGData} object ...
 **/

/* rel_change!=0 means: if pass the other stopping criteria,
 also check the relative change in the solution x.
   stop_crit!=0 means: absolute error tolerance rather than
 the usual relative error tolerance on the residual.  Never
 applies if rel_change!=0.
*/

typedef struct
{
   double   tol;
   double   cf_tol;
   int      max_iter;
   int      two_norm;
   int      rel_change;
   int      stop_crit;

   void    *A;
   void    *p;
   void    *s;
   void    *r;

   void    *matvec_data;
   void    *precond_data;

   hypre_PCGFunctions * functions;

   /* log info (always logged) */
   int      num_iterations;

   /* additional log info (logged when `logging' > 0) */
   int      logging;
   double  *norms;
   double  *rel_norms;

} hypre_PCGData;

#ifdef __cplusplus
extern "C" {
#endif


/**
 * @name generic PCG Solver
 *
 * Description...
 **/
/*@{*/

/**
 * Description...
 *
 * @param param [IN] ...
 **/

hypre_PCGFunctions *
hypre_PCGFunctionsCreate(
   char * (*CAlloc)        ( int count, int elt_size ),
   int    (*Free)          ( char *ptr ),
   void * (*CreateVector)  ( void *vector ),
   int    (*DestroyVector) ( void *vector ),
   void * (*MatvecCreate)  ( void *A, void *x ),
   int    (*Matvec)        ( void *matvec_data, double alpha, void *A,
                             void *x, double beta, void *y ),
   int    (*MatvecDestroy) ( void *matvec_data ),
   double (*InnerProd)     ( void *x, void *y ),
   int    (*CopyVector)    ( void *x, void *y ),
   int    (*ClearVector)   ( void *x ),
   int    (*ScaleVector)   ( double alpha, void *x ),
   int    (*Axpy)          ( double alpha, void *x, void *y ),
   int    (*PrecondSetup)  ( void *vdata, void *A, void *b, void *x ),
   int    (*Precond)       ( void *vdata, void *A, void *b, void *x )
   );

/**
 * Description...
 *
 * @param param [IN] ...
 **/

void *
hypre_PCGCreate( hypre_PCGFunctions *pcg_functions );

#ifdef __cplusplus
}
#endif

#endif
