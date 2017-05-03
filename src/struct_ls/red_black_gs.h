/*BHEADER**********************************************************************
 * Copyright (c) 2008,  Lawrence Livermore National Security, LLC.
 * Produced at the Lawrence Livermore National Laboratory.
 * This file is part of HYPRE.  See file COPYRIGHT for details.
 *
 * HYPRE is free software; you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License (as published by the Free
 * Software Foundation) version 2.1 dated February 1999.
 *
 * $Revision$
 ***********************************************************************EHEADER*/




/*--------------------------------------------------------------------------
 * hypre_RedBlackGSData data structure
 *--------------------------------------------------------------------------*/

typedef struct
{
   MPI_Comm                comm;

   HYPRE_Real              tol;                /* not yet used */
   HYPRE_Int               max_iter;
   HYPRE_Int               rel_change;         /* not yet used */
   HYPRE_Int               zero_guess;
   HYPRE_Int               rb_start;

   hypre_StructMatrix     *A;
   hypre_StructVector     *b;
   hypre_StructVector     *x;

   HYPRE_Int               diag_rank;

   hypre_ComputePkg       *compute_pkg;

   /* log info (always logged) */
   HYPRE_Int               num_iterations;
   HYPRE_Int               time_index;
   HYPRE_Int               flops;

} hypre_RedBlackGSData;

#ifdef HYPRE_USE_RAJA
#define HYPRE_REDBLACK_PRIVATE hypre__global_error
#define hypre_RedBlackLoopInit()
#define hypre_RedBlackLoopBegin(ni,nj,nk,redblack,\
				Astart,Ani,Anj,Ai,	\
				bstart,bni,bnj,bi,	\
				xstart,xni,xnj,xi)	\
{					  \
    HYPRE_Int hypre__tot = nk*nj*((ni+1)/2);				\
    forall< hypre_exec_policy >(0, hypre__tot, [=] RAJA_DEVICE (HYPRE_Int idx) \
    {									\
        HYPRE_Int idx_local = idx;					\
	HYPRE_Int ii,jj,kk,Ai,bi,xi;					\
	HYPRE_Int local_ii;						\
	kk = idx_local % nk;						\
	idx_local = idx_local / nk;					\
	jj = idx_local % nj;						\
	idx_local = idx_local / nj;					\
	local_ii = (kk + jj + redblack) % 2;				\
	ii = 2*idx_local + local_ii;					\
	if (ii < ni)							\
	{								\
	    Ai = Astart + kk*Anj*Ani + jj*Ani + ii;			\
	    bi = bstart + kk*bnj*bni + jj*bni + ii;			\
	    xi = xstart + kk*xnj*xni + jj*xni + ii;			\

#define hypre_RedBlackLoopEnd()			\
         }						\
     });						\
     hypre_fence();					\
}

#define hypre_RedBlackConstantcoefLoopBegin(ni,nj,nk,redblack,\
				bstart,bni,bnj,bi,	\
				xstart,xni,xnj,xi)	\
{					  \
    HYPRE_Int hypre__tot = nk*nj*((ni+1)/2);				\
    forall< hypre_exec_policy >(0, hypre__tot, [=] RAJA_DEVICE (HYPRE_Int idx) \
    {									\
        HYPRE_Int idx_local = idx;					\
	HYPRE_Int ii,jj,kk,bi,xi;					\
	HYPRE_Int local_ii;						\
	kk = idx_local % nk;						\
	idx_local = idx_local / nk;					\
	jj = idx_local % nj;						\
	idx_local = idx_local / nj;					\
	local_ii = (kk + jj + redblack) % 2;				\
	ii = 2*idx_local + local_ii;					\
	if (ii < ni)							\
	{								\
	    bi = bstart + kk*bnj*bni + jj*bni + ii;			\
	    xi = xstart + kk*xnj*xni + jj*xni + ii;			\

#define hypre_RedBlackConstantcoefLoopEnd()			\
         }						\
     });						\
     hypre_fence();					\
}  
#elif defined(HYPRE_USE_KOKKOS)
#define HYPRE_REDBLACK_PRIVATE hypre__global_error
#define hypre_RedBlackLoopInit()
#define hypre_RedBlackLoopBegin(ni,nj,nk,redblack,\
				Astart,Ani,Anj,Ai,	\
				bstart,bni,bnj,bi,	\
				xstart,xni,xnj,xi)	\
{					  \
    HYPRE_Int hypre__tot = nk*nj*((ni+1)/2);				\
    HYPRE_Int hypre_fake = 0;						\
    Kokkos::parallel_for (hypre__tot, KOKKOS_LAMBDA (HYPRE_Int idx) \
    {									\
        HYPRE_Int idx_local = idx;					\
	HYPRE_Int ii,jj,kk,Ai,bi,xi;					\
	HYPRE_Int local_ii;						\
	kk = idx_local % nk;						\
	idx_local = idx_local / nk;					\
	jj = idx_local % nj;						\
	idx_local = idx_local / nj;					\
	local_ii = (kk + jj + redblack) % 2;				\
	ii = 2*idx_local + local_ii;					\
	if (ii < ni)							\
	{								\
	    Ai = Astart + kk*Anj*Ani + jj*Ani + ii;			\
	    bi = bstart + kk*bnj*bni + jj*bni + ii;			\
	    xi = xstart + kk*xnj*xni + jj*xni + ii;			\

#define hypre_RedBlackLoopEnd()			\
         }						\
     });						\
     hypre_fence();					\
}

#define hypre_RedBlackConstantcoefLoopBegin(ni,nj,nk,redblack,\
				bstart,bni,bnj,bi,	\
				xstart,xni,xnj,xi)	\
{					  \
    HYPRE_Int hypre__tot = nk*nj*((ni+1)/2);				\
    Kokkos::parallel_for (hypre__tot, KOKKOS_LAMBDA (HYPRE_Int idx) \
    {									\
        HYPRE_Int idx_local = idx;					\
	HYPRE_Int ii,jj,kk,bi,xi;					\
	HYPRE_Int local_ii;						\
	kk = idx_local % nk;						\
	idx_local = idx_local / nk;					\
	jj = idx_local % nj;						\
	idx_local = idx_local / nj;					\
	local_ii = (kk + jj + redblack) % 2;				\
	ii = 2*idx_local + local_ii;					\
	if (ii < ni)							\
	{								\
	    bi = bstart + kk*bnj*bni + jj*bni + ii;			\
	    xi = xstart + kk*xnj*xni + jj*xni + ii;			\

#define hypre_RedBlackConstantcoefLoopEnd()			\
         }						\
     });						\
     hypre_fence();					\
}  
#elif defined(HYPRE_USE_CUDA)
#define HYPRE_REDBLACK_PRIVATE hypre__global_error
#define hypre_RedBlackLoopInit()
#define hypre_RedBlackLoopBegin(ni,nj,nk,redblack,\
				Astart,Ani,Anj,Ai,	\
				bstart,bni,bnj,bi,	\
				xstart,xni,xnj,xi)	\
{					  \
    HYPRE_Int hypre__tot = nk*nj*((ni+1)/2);				\
    BoxLoopforall(cuda_traversal(),hypre__tot,[=] __device__ (HYPRE_Int idx) \
    {									\
        HYPRE_Int idx_local = idx;					\
	HYPRE_Int ii,jj,kk,Ai,bi,xi;					\
	HYPRE_Int local_ii;						\
	kk = idx_local % nk;						\
	idx_local = idx_local / nk;					\
	jj = idx_local % nj;						\
	idx_local = idx_local / nj;					\
	local_ii = (kk + jj + redblack) % 2;				\
	ii = 2*idx_local + local_ii;					\
	if (ii < ni)							\
	{								\
	    Ai = Astart + kk*Anj*Ani + jj*Ani + ii;			\
	    bi = bstart + kk*bnj*bni + jj*bni + ii;			\
	    xi = xstart + kk*xnj*xni + jj*xni + ii;			\

#define hypre_RedBlackLoopEnd()			\
         }						\
     });						\
     hypre_fence();					\
}
	   
#define hypre_RedBlackConstantcoefLoopBegin(ni,nj,nk,redblack,\
					    bstart,bni,bnj,bi,	\
					    xstart,xni,xnj,xi)	\
{					  \
    HYPRE_Int hypre__tot = nk*nj*((ni+1)/2);				\
    BoxLoopforall(cuda_traversal(),hypre__tot,[=] __device__ (HYPRE_Int idx) \
    {									\
        HYPRE_Int idx_local = idx;					\
	HYPRE_Int ii,jj,kk,bi,xi;					\
	HYPRE_Int local_ii;						\
	kk = idx_local % nk;						\
	idx_local = idx_local / nk;					\
	jj = idx_local % nj;						\
	idx_local = idx_local / nj;					\
	local_ii = (kk + jj + redblack) % 2;				\
	ii = 2*idx_local + local_ii;					\
	if (ii < ni)							\
	{								\
	    bi = bstart + kk*bnj*bni + jj*bni + ii;			\
	    xi = xstart + kk*xnj*xni + jj*xni + ii;			\

#define hypre_RedBlackConstantcoefLoopEnd()			\
         }						\
     });						\
     hypre_fence();					\
}
#else
#define HYPRE_REDBLACK_PRIVATE hypre__kk
#define hypre_RedBlackLoopInit()\
{\
   HYPRE_Int hypre__kk;

#define hypre_RedBlackLoopBegin(ni,nj,nk,redblack,\
				Astart,Ani,Anj,Ai,\
				bstart,bni,bnj,bi,\
				xstart,xni,xnj,xi)\
   for (hypre__kk = 0; hypre__kk < nk; hypre__kk++)\
   {\
      HYPRE_Int ii,jj,Ai,bi,xi;\
      for (jj = 0; jj < nj; jj++)\
      {\
         ii = (hypre__kk + jj + redblack) % 2;\
         Ai = Astart + hypre__kk*Anj*Ani + jj*Ani + ii;\
         bi = bstart + hypre__kk*bnj*bni + jj*bni + ii;\
         xi = xstart + hypre__kk*xnj*xni + jj*xni + ii;\
         for (; ii < ni; ii+=2, Ai+=2, bi+=2, xi+=2)\
         {

#define hypre_RedBlackLoopEnd()\
         }\
      }\
   }\
}

#define hypre_RedBlackConstantcoefLoopBegin(ni,nj,nk,redblack,\
                                            bstart,bni,bnj,bi,\
                                            xstart,xni,xnj,xi)\
   for (hypre__kk = 0; hypre__kk < nk; hypre__kk++)\
   {\
      HYPRE_Int ii,jj,bi,xi;\
      for (jj = 0; jj < nj; jj++)\
      {\
         ii = (hypre__kk + jj + redblack) % 2;\
         bi = bstart + hypre__kk*bnj*bni + jj*bni + ii;\
         xi = xstart + hypre__kk*xnj*xni + jj*xni + ii;\
         for (; ii < ni; ii+=2, Ai+=2, bi+=2, xi+=2)\
         {

#define hypre_RedBlackConstantcoefLoopEnd()\
         }\
      }\
   }\
}
#endif
