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

/******************************************************************************
 *
 * Header info for the BoxLoop
 *
 *****************************************************************************/

/*--------------------------------------------------------------------------
 * BoxLoop macros:
 *--------------------------------------------------------------------------*/

#ifndef HYPRE_NEWBOXLOOP_HEADER
#define HYPRE_NEWBOXLOOP_HEADER

#include <cuda.h>
#include <cuda_runtime.h>

struct cuda_traversal {HYPRE_Int cuda;};
struct omp_traversal  {HYPRE_Int omp;};
#define hypre_exec_policy cuda_traversal()
#define HYPER_LAMBDA [=] __device__

typedef struct hypre_Boxloop_struct
{
	HYPRE_Int lsize0,lsize1,lsize2;
	HYPRE_Int strides0,strides1,strides2;
	HYPRE_Int bstart0,bstart1,bstart2;
	HYPRE_Int bsize0,bsize1,bsize2;
} hypre_Boxloop;

#define AxCheckError(err) CheckError(err, __FUNCTION__, __LINE__)
inline void CheckError(cudaError_t const err, char const* const fun, const HYPRE_Int line)
{
    if (err)
    {
        printf("CUDA Error Code[%d]: %s\n%s() Line:%d\n", err, cudaGetErrorString(err), fun, line);
    }
}
#define BLOCKSIZE 128

#define hypre_fence() \
  cudaError err = cudaGetLastError();		\
if ( cudaSuccess != err )\
{\
   printf("\n ERROR hypre_newBoxLoop: %s in %s(%d) function %s\n",cudaGetErrorString(err),__FILE__,__LINE__,__FUNCTION__);\
}									\
AxCheckError(cudaDeviceSynchronize());

extern "C++" {
template <typename LOOP_BODY>
__global__ void forall_kernel(LOOP_BODY loop_body, HYPRE_Int length)
{
	HYPRE_Int idx = blockDim.x * blockIdx.x + threadIdx.x;
	if (idx < length)
		loop_body(idx);
}

template<typename LOOP_BODY>
void BoxLoopforall (cuda_traversal, HYPRE_Int length, LOOP_BODY loop_body)
{	
	size_t const blockSize = 128;
	size_t gridSize  = (length + blockSize - 1) / blockSize;
	if (gridSize == 0) gridSize = 1;
	
	//hypre_printf("length= %d, blocksize = %d, gridsize = %d\n",length,blockSize,gridSize);
	forall_kernel<<<gridSize, blockSize>>>(loop_body,length);
}

template<typename LOOP_BODY>
void BoxLoopforall (omp_traversal, HYPRE_Int length, LOOP_BODY loop_body)
{

#pragma omp parallel for schedule(static)
	for (HYPRE_Int idx = 0;idx < length;idx++)
		loop_body(idx);
}

#define zypre_BoxLoopIncK(k,box,i)					\
{       								\
HYPRE_Int idx = idx_local;						\
local_idx  = idx % box.lsize0;					\
idx        = idx / box.lsize0;					\
i += (local_idx*box.strides0 + box.bstart0) * hypre_boxD##k;		\
hypre_boxD##k *= hypre_max(0, box.bsize0 + 1);			\
local_idx  = idx % box.lsize1;					\
idx        = idx / box.lsize1;					\
i += (local_idx*box.strides1 + box.bstart1) * hypre_boxD##k;		\
hypre_boxD##k *= hypre_max(0, box.bsize1 + 1);			\
local_idx  = idx % box.lsize2;					\
idx  = idx / box.lsize2;					\
i += (local_idx*box.strides2 + box.bstart2) * hypre_boxD##k;		\
hypre_boxD##k *= hypre_max(0, box.bsize2 + 1);			\
}


template<class T>
__global__ void reduction_mult (T * a, T * b, HYPRE_Int hypre__tot,
				hypre_Boxloop box1)
{
    HYPRE_Int id = (blockIdx.x * blockDim.x) + threadIdx.x;
    HYPRE_Int local_idx;
    HYPRE_Int idx_local = id;
    HYPRE_Int hypre_boxD1 = 1;
    HYPRE_Int i1 = 0;
    //// reducted output
    __shared__ T shared_cache [BLOCKSIZE];
    T sum = 1;
    local_idx  = idx_local % box1.lsize0;
    idx_local  = idx_local / box1.lsize0;
    i1 += (local_idx*box1.strides0 + box1.bstart0) * hypre_boxD1;
    hypre_boxD1 *= hypre_max(0, box1.bsize0 + 1);
    local_idx  = idx_local % box1.lsize1;
    idx_local  = idx_local / box1.lsize1;
    i1 += (local_idx*box1.strides1 + box1.bstart1) * hypre_boxD1;
    hypre_boxD1 *= hypre_max(0, box1.bsize1 + 1);	
    local_idx  = idx_local % box1.lsize2;	      
    idx_local  = idx_local / box1.lsize2;		      
    i1 += (local_idx*box1.strides2 + box1.bstart2) * hypre_boxD1;
    hypre_boxD1 *= hypre_max(0, box1.bsize2 + 1);	
    if (id < hypre__tot)
      sum = a[i1];
    *(shared_cache + threadIdx.x) = sum;
    
    __syncthreads();
    
    ///////// sum of internal cache
    
    HYPRE_Int i;    
    
    for (i=(BLOCKSIZE /2); i>0 ; i= i/2){
      if (threadIdx.x < i){
	*(shared_cache + threadIdx.x) *= *(shared_cache + threadIdx.x + i);
      }
      __syncthreads();
    }
    
    if ( threadIdx.x == 0){
      *(b+ blockIdx.x) = shared_cache[0];
    }
}
}

#define hypre_BoxLoopInit(ndim,loop_size)					\
	HYPRE_Int hypre__tot = 1;											\
	for (HYPRE_Int i = 0;i < ndim;i ++)									\
		hypre__tot *= loop_size[i];


#define hypre_newBoxLoopDeclare()\
	HYPRE_Int hypre__i,hypre__j,hypre__k;\
	HYPRE_Int idx_local = idx;

#define hypre_newBoxLoop0Begin(ndim, loop_size)				\
{									\
    hypre_BoxLoopInit(ndim,loop_size);						\
    BoxLoopforall(hypre_exec_policy,hypre__tot,HYPER_LAMBDA (HYPRE_Int idx) \
    {

#define hypre_newBoxLoop0End()					\
    });									\
    hypre_fence();							\
}

#define hypre_BoxLoopDataDeclareK(k,ndim,loop_size,dbox,start,stride)	\
	hypre_Boxloop databox##k;											\
	databox##k.lsize0 = loop_size[0];				\
	databox##k.strides0 = stride[0];				\
	databox##k.bstart0  = start[0] - dbox->imin[0];			\
	databox##k.bsize0   = dbox->imax[0]-dbox->imin[0];		\
	if (ndim > 1)							\
	{								\
	    databox##k.lsize1 = loop_size[1];				\
	    databox##k.strides1 = stride[1];				\
	    databox##k.bstart1  = start[1] - dbox->imin[1];		\
	    databox##k.bsize1   = dbox->imax[1]-dbox->imin[1];	\
	}								\
	else						        	\
	{							       	\
		databox##k.lsize1 = 1;				       	\
		databox##k.strides1 = 0;		       		\
		databox##k.bstart1  = 0;	       			\
		databox##k.bsize1   = 0;		       		\
	}								\
	if (ndim == 3)							\
	{							      	\
	      databox##k.lsize2 = loop_size[2];				\
	      databox##k.strides2 = stride[2];				\
	      databox##k.bstart2  = start[2] - dbox->imin[2];		\
	      databox##k.bsize2   = dbox->imax[2]-dbox->imin[2];	\
	}				                        	\
	else						        	\
	{							       	\
		databox##k.lsize2 = 1;				       	\
		databox##k.strides2 = 0;		       		\
		databox##k.bstart2  = 0;	       			\
		databox##k.bsize2   = 0;		       		\
	}

#define hypre_newBoxLoop1Begin(ndim, loop_size,				\
			       dbox1, start1, stride1, i1)		\
{									\
    hypre_BoxLoopInit(ndim,loop_size);				\
    hypre_BoxLoopDataDeclareK(1,ndim,loop_size,dbox1,start1,stride1);	\
    BoxLoopforall(hypre_exec_policy,hypre__tot,HYPER_LAMBDA (HYPRE_Int idx) \
    {									\
      hypre_newBoxLoopDeclare();					\
      HYPRE_Int hypre_boxD1 = 1;					\
      HYPRE_Int i1 = 0;							\
      hypre__i  = idx_local % databox1.lsize0;				\
      idx_local = idx_local / databox1.lsize0;				\
      i1 += (hypre__i*databox1.strides0 + databox1.bstart0) * hypre_boxD1; \
      hypre_boxD1 *= hypre_max(0, databox1.bsize0 + 1);			\
      hypre__j  = idx_local % databox1.lsize1;				\
      idx_local = idx_local / databox1.lsize1;				\
      i1 += (hypre__j*databox1.strides1 + databox1.bstart1) * hypre_boxD1; \
      hypre_boxD1 *= hypre_max(0, databox1.bsize1 + 1);			\
      hypre__k  = idx_local % databox1.lsize2;				\
      idx_local = idx_local / databox1.lsize2;				\
      i1 += (hypre__k*databox1.strides2 + databox1.bstart2) * hypre_boxD1; \
      hypre_boxD1 *= hypre_max(0, databox1.bsize2 + 1);
      
#define hypre_newBoxLoop1End(i1)				\
    });									\
    hypre_fence();							\
}
	
#define hypre_newBoxLoop2Begin(ndim, loop_size,				\
			       dbox1, start1, stride1, i1,		\
			       dbox2, start2, stride2, i2)		\
{									\
    hypre_BoxLoopInit(ndim,loop_size);						\
    hypre_BoxLoopDataDeclareK(1,ndim,loop_size,dbox1,start1,stride1);	\
    hypre_BoxLoopDataDeclareK(2,ndim,loop_size,dbox2,start2,stride2);	\
    BoxLoopforall(hypre_exec_policy,hypre__tot,HYPER_LAMBDA (HYPRE_Int idx) \
    {									\
        hypre_newBoxLoopDeclare()					\
        HYPRE_Int hypre_boxD1 = 1,hypre_boxD2 = 1;			\
	HYPRE_Int i1 = 0, i2 = 0;					\
	hypre__i  = idx_local % databox1.lsize0;			\
	idx_local  = idx_local / databox1.lsize0;			\
	i1 += (hypre__i*databox1.strides0 + databox1.bstart0) * hypre_boxD1; \
	hypre_boxD1 *= hypre_max(0, databox1.bsize0 + 1);		\
	i2 += (hypre__i*databox2.strides0 + databox2.bstart0) * hypre_boxD2; \
	hypre_boxD2 *= hypre_max(0, databox2.bsize0 + 1);		\
	hypre__j  = idx_local % databox1.lsize1;			\
	idx_local  = idx_local / databox1.lsize1;			\
	i1 += (hypre__j*databox1.strides1 + databox1.bstart1) * hypre_boxD1; \
	hypre_boxD1 *= hypre_max(0, databox1.bsize1 + 1);		\
	i2 += (hypre__j*databox2.strides1 + databox2.bstart1) * hypre_boxD2; \
	hypre_boxD2 *= hypre_max(0, databox2.bsize1 + 1);		\
	hypre__k  = idx_local % databox1.lsize2;			\
	idx_local  = idx_local / databox1.lsize2;			\
	i1 += (hypre__k*databox1.strides2 + databox1.bstart2) * hypre_boxD1; \
	hypre_boxD1 *= hypre_max(0, databox1.bsize2 + 1);		\
	i2 += (hypre__k*databox2.strides2 + databox2.bstart2) * hypre_boxD2; \
	hypre_boxD2 *= hypre_max(0, databox2.bsize2 + 1);		\

#define hypre_newBoxLoop2End(i1, i2)			\
    });							\
    hypre_fence();					\
}

#define hypre_newBoxLoop3Begin(ndim, loop_size,				\
			       dbox1, start1, stride1, i1,		\
			       dbox2, start2, stride2, i2,		\
			       dbox3, start3, stride3, i3)		\
{									\
    hypre_BoxLoopInit(ndim,loop_size);						\
    hypre_BoxLoopDataDeclareK(1,ndim,loop_size,dbox1,start1,stride1);	\
    hypre_BoxLoopDataDeclareK(2,ndim,loop_size,dbox2,start2,stride2);	\
    hypre_BoxLoopDataDeclareK(3,ndim,loop_size,dbox3,start3,stride3);	\
    BoxLoopforall(hypre_exec_policy,hypre__tot,HYPER_LAMBDA (HYPRE_Int idx) \
    {									\
	hypre_newBoxLoopDeclare();					\
	HYPRE_Int hypre_boxD1 = 1,hypre_boxD2 = 1,hypre_boxD3 = 1; \
	HYPRE_Int i1 = 0, i2 = 0, i3 = 0;				\
	hypre__i  = idx_local % databox1.lsize0;				\
	idx_local  = idx_local / databox1.lsize0;				\
	i1 += (hypre__i*databox1.strides0 + databox1.bstart0) * hypre_boxD1;	\
	hypre_boxD1 *= hypre_max(0, databox1.bsize0 + 1);			\
	i2 += (hypre__i*databox2.strides0 + databox2.bstart0) * hypre_boxD2;	\
	hypre_boxD2 *= hypre_max(0, databox2.bsize0 + 1);			\
	i3 += (hypre__i*databox3.strides0 + databox3.bstart0) * hypre_boxD3;	\
	hypre_boxD3 *= hypre_max(0, databox3.bsize0 + 1);			\
	hypre__j   = idx_local % databox1.lsize1;				\
	idx_local  = idx_local / databox1.lsize1;				\
	i1 += (hypre__j*databox1.strides1 + databox1.bstart1) * hypre_boxD1;	\
	hypre_boxD1 *= hypre_max(0, databox1.bsize1 + 1);			\
	i2 += (hypre__j*databox2.strides1 + databox2.bstart1) * hypre_boxD2;	\
	hypre_boxD2 *= hypre_max(0, databox2.bsize1 + 1);			\
	i3 += (hypre__j*databox3.strides1 + databox3.bstart1) * hypre_boxD3;	\
	hypre_boxD3 *= hypre_max(0, databox3.bsize1 + 1);			\
	hypre__k  = idx_local % databox1.lsize2;				\
	idx_local  = idx_local / databox1.lsize2;				\
	i1 += (hypre__k*databox1.strides2 + databox1.bstart2) * hypre_boxD1;	\
	hypre_boxD1 *= hypre_max(0, databox1.bsize2 + 1);			\
	i2 += (hypre__k*databox2.strides2 + databox2.bstart2) * hypre_boxD2;	\
	hypre_boxD2 *= hypre_max(0, databox2.bsize2 + 1);			\
	i3 += (hypre__k*databox3.strides2 +databox3.bstart2) * hypre_boxD3;	\
	hypre_boxD3 *= hypre_max(0, databox3.bsize2 + 1);			\
	

#define hypre_newBoxLoop3End(i1, i2,i3)			\
    });									\
    hypre_fence();							\
}

#define hypre_newBoxLoop4Begin(ndim, loop_size,				\
			       dbox1, start1, stride1, i1,		\
			       dbox2, start2, stride2, i2,		\
			       dbox3, start3, stride3, i3,		\
			       dbox4, start4, stride4, i4)		\
{								       \
     hypre_BoxLoopInit(ndim,loop_size);			       \
     hypre_BoxLoopDataDeclareK(1,ndim,loop_size,dbox1,start1,stride1); \
     hypre_BoxLoopDataDeclareK(2,ndim,loop_size,dbox2,start2,stride2); \
     hypre_BoxLoopDataDeclareK(3,ndim,loop_size,dbox3,start3,stride3); \
     hypre_BoxLoopDataDeclareK(4,ndim,loop_size,dbox4,start4,stride4); \
     BoxLoopforall(hypre_exec_policy,hypre__tot,HYPER_LAMBDA (HYPRE_Int idx) \
     {									\
        hypre_newBoxLoopDeclare();					\
	HYPRE_Int hypre_boxD1 = 1,hypre_boxD2 = 1,hypre_boxD3 = 1,hypre_boxD4 = 1; \
	HYPRE_Int i1 = 0, i2 = 0, i3 = 0,i4 = 0;			\
	hypre__i  = idx_local % databox1.lsize0;			\
	idx_local  = idx_local / databox1.lsize0;			\
	i1 += (hypre__i*databox1.strides0 + databox1.bstart0) * hypre_boxD1; \
	hypre_boxD1 *= hypre_max(0, databox1.bsize0 + 1);		\
	i2 += (hypre__i*databox2.strides0 + databox2.bstart0) * hypre_boxD2; \
	hypre_boxD2 *= hypre_max(0, databox2.bsize0 + 1);		\
	i3 += (hypre__i*databox3.strides0 + databox3.bstart0) * hypre_boxD3; \
	hypre_boxD3 *= hypre_max(0, databox3.bsize0 + 1);		\
	i4 += (hypre__i*databox4.strides0 + databox4.bstart0) * hypre_boxD4; \
	hypre_boxD4 *= hypre_max(0, databox4.bsize0 + 1);		\
	hypre__j  = idx_local % databox1.lsize1;			\
	idx_local  = idx_local / databox1.lsize1;			\
	i1 += (hypre__j*databox1.strides1 + databox1.bstart1) * hypre_boxD1; \
	hypre_boxD1 *= hypre_max(0, databox1.bsize1 + 1);		\
	i2 += (hypre__j*databox2.strides1 + databox2.bstart1) * hypre_boxD2; \
	hypre_boxD2 *= hypre_max(0, databox2.bsize1 + 1);		\
	i3 += (hypre__j*databox3.strides1 + databox3.bstart1) * hypre_boxD3; \
	hypre_boxD3 *= hypre_max(0, databox3.bsize1 + 1);		\
	i4 += (hypre__j*databox4.strides1 + databox4.bstart1) * hypre_boxD4; \
	hypre_boxD4 *= hypre_max(0, databox4.bsize1 + 1);		\
	hypre__k  = idx_local % databox1.lsize2;			\
	idx_local  = idx_local / databox1.lsize2;			\
	i1 += (hypre__k*databox1.strides2 + databox1.bstart2) * hypre_boxD1; \
	hypre_boxD1 *= hypre_max(0, databox1.bsize2 + 1);		\
	i2 += (hypre__k*databox2.strides2 + databox2.bstart2) * hypre_boxD2; \
	hypre_boxD2 *= hypre_max(0, databox2.bsize2 + 1);		\
	i3 += (hypre__k*databox3.strides2 + databox3.bstart2) * hypre_boxD3; \
	hypre_boxD3 *= hypre_max(0, databox3.bsize2 + 1);		\
	i4 += (hypre__k*databox4.strides2 + databox4.bstart2) * hypre_boxD4; \
	hypre_boxD4 *= hypre_max(0, databox4.bsize2 + 1);		\
		
#define hypre_newBoxLoop4End(i1, i2, i3, i4)	\
    });						\
    hypre_fence();				\
}

#define MAX_BLOCK 512

extern "C++" {
template<class T>
__inline__ __device__
HYPRE_Int fake_shfl_down(T val, HYPRE_Int offset, HYPRE_Int width=32) {
  static __shared__ T shared[MAX_BLOCK];
  HYPRE_Int lane=threadIdx.x%32;

  shared[threadIdx.x]=val;
  __syncthreads();

  val = (lane+offset<width) ? shared[threadIdx.x+offset] : 0;
  __syncthreads();

  return val;
}

template<class T>  
__inline__ __device__
HYPRE_Real warpReduceSum (T val) {
  for (HYPRE_Int offset = warpSize/2; offset > 0; offset /= 2)
    val += __shfl_down(val,offset);
  return val;
}


template<class T> 
__inline__ __device__
HYPRE_Real blockReduceSum(T val) {
  static __shared__ T shared[32];
  HYPRE_Int lane=threadIdx.x%warpSize;
  HYPRE_Int wid=threadIdx.x/warpSize;
  val=warpReduceSum<T>(val);

  //write reduced value to shared memory
  if(lane==0) shared[wid]=val;
  __syncthreads();

  //ensure we only grab a value from shared memory if that warp existed
  val = (threadIdx.x<blockDim.x/warpSize) ? shared[lane] : HYPRE_Int(0);
  if(wid==0) val=warpReduceSum<T>(val);

  return val;
}

template<class T>
__global__ void hypre_device_reduce_stable_kernel(T*a, T*b, T* out, HYPRE_Int N,
						  hypre_Boxloop box1,hypre_Boxloop box2) {
  HYPRE_Int local_idx;
  HYPRE_Int idx_local;
  HYPRE_Int hypre_boxD1 = 1,hypre_boxD2 = 1;
  HYPRE_Int i1 = 0, i2 = 0;
  T sum=T(0);
  HYPRE_Int i;
  
  for(i=blockIdx.x*blockDim.x+threadIdx.x;i<N;i+=blockDim.x*gridDim.x)
  {
    idx_local = i;
    local_idx  = idx_local % box1.lsize0;
    idx_local  = idx_local / box1.lsize0;
    i1 += (local_idx*box1.strides0 + box1.bstart0) * hypre_boxD1;
    hypre_boxD1 *= hypre_max(0, box1.bsize0 + 1);
    i2 += (local_idx*box2.strides0 + box2.bstart0) * hypre_boxD2;
    hypre_boxD2 *= hypre_max(0, box2.bsize0 + 1);
    local_idx  = idx_local % box1.lsize1;
    idx_local  = idx_local / box1.lsize1;
    i1 += (local_idx*box1.strides1 + box1.bstart1) * hypre_boxD1;
    hypre_boxD1 *= hypre_max(0, box1.bsize1 + 1);
    i2 += (local_idx*box2.strides1 + box2.bstart1) * hypre_boxD2;   
    hypre_boxD2 *= hypre_max(0, box2.bsize1 + 1);	
    local_idx  = idx_local % box1.lsize2;	      
    idx_local  = idx_local / box1.lsize2;		      
    i1 += (local_idx*box1.strides2 + box1.bstart2) * hypre_boxD1;
    hypre_boxD1 *= hypre_max(0, box1.bsize2 + 1);	
    i2 += (local_idx*box2.strides2 + box2.bstart2) * hypre_boxD2;
    hypre_boxD2 *= hypre_max(0, box2.bsize2 + 1);
    sum += a[i1] * hypre_conj(b[i2]);
  }
  sum=blockReduceSum<T>(sum);
  if(threadIdx.x==0)
    out[blockIdx.x]=sum;
}

template<class T>       
__global__ void hypre_device_reduce_stable_kernel2(T *in, T* out, HYPRE_Int N) {
  T sum=T(0);
  for(HYPRE_Int i=blockIdx.x*blockDim.x+threadIdx.x;i<N;i+=blockDim.x*gridDim.x) {
    sum+=in[i];
  }
  sum=blockReduceSum<T>(sum);
  if(threadIdx.x==0)
    out[blockIdx.x]=sum;
}

template<class T>   
void hypre_device_reduce_stable(T*a,T*b, T* out, HYPRE_Int N,
				hypre_Boxloop box1,hypre_Boxloop box2) {
  HYPRE_Int threads=512;
  HYPRE_Int blocks=min((N+threads-1)/threads,1024);

  hypre_device_reduce_stable_kernel<T><<<blocks,threads>>>(a,b,out,N,box1,box2);
  hypre_device_reduce_stable_kernel2<T><<<1,1024>>>(out,out,blocks); 
}

}

extern "C++" {
template <typename LOOP_BODY>
__global__ void hypre_device_reduction_kernel(HYPRE_Real* out,
					      HYPRE_Int N,hypre_Boxloop box1,hypre_Boxloop box2,
					      LOOP_BODY loop_body)
{
    HYPRE_Int local_idx;
    HYPRE_Int idx_local;
    HYPRE_Int hypre_boxD1 = 1,hypre_boxD2 = 1;
    HYPRE_Int i1 = 0, i2 = 0;
    HYPRE_Real sum = HYPRE_Real(0);
    HYPRE_Int i;
    
    for(i=blockIdx.x*blockDim.x+threadIdx.x;i<N;i+=blockDim.x*gridDim.x)
      {
	idx_local = i;
	local_idx  = idx_local % box1.lsize0;
	idx_local  = idx_local / box1.lsize0;
	i1 += (local_idx*box1.strides0 + box1.bstart0) * hypre_boxD1;
	hypre_boxD1 *= hypre_max(0, box1.bsize0 + 1);
	i2 += (local_idx*box2.strides0 + box2.bstart0) * hypre_boxD2;
	hypre_boxD2 *= hypre_max(0, box2.bsize0 + 1);
	local_idx  = idx_local % box1.lsize1;
	idx_local  = idx_local / box1.lsize1;
	i1 += (local_idx*box1.strides1 + box1.bstart1) * hypre_boxD1;
	hypre_boxD1 *= hypre_max(0, box1.bsize1 + 1);
	i2 += (local_idx*box2.strides1 + box2.bstart1) * hypre_boxD2;   
	hypre_boxD2 *= hypre_max(0, box2.bsize1 + 1);	
	local_idx  = idx_local % box1.lsize2;	      
	idx_local  = idx_local / box1.lsize2;		      
	i1 += (local_idx*box1.strides2 + box1.bstart2) * hypre_boxD1;
	hypre_boxD1 *= hypre_max(0, box1.bsize2 + 1);	
	i2 += (local_idx*box2.strides2 + box2.bstart2) * hypre_boxD2;
	hypre_boxD2 *= hypre_max(0, box2.bsize2 + 1);
	sum = loop_body(i1,i2,sum);
      }
    sum=blockReduceSum<HYPRE_Real>(sum);
    if(threadIdx.x==0)
      out[blockIdx.x]=sum;
}

template<typename LOOP_BODY>
void hypre_device_reduction (HYPRE_Real* out,
			     HYPRE_Int N,hypre_Boxloop box1,hypre_Boxloop box2,
			     LOOP_BODY loop_body)
{	
  HYPRE_Int threads=512;
  HYPRE_Int blocks=min((N+threads-1)/threads,1024);

  hypre_device_reduction_kernel<<<blocks,threads>>>(out,N,box1,box2,loop_body);
  hypre_device_reduce_stable_kernel2<HYPRE_Real><<<1,1024>>>(out,out,blocks);

}
}

#define hypre_newBoxLoop1ReductionBegin(ndim, loop_size,		\
					dbox1, start1, stride1, i1, sum) \
{    									   \
   HYPRE_Real sum_old = sum;						\
   sum = 0.0;								\
   hypre_BoxLoopInit(ndim,loop_size);					\
   hypre_BoxLoopDataDeclareK(1,ndim,loop_size,dbox1,start1,stride1);	\
   HYPRE_Real *d_c;							\
   cudaMalloc((void**) &d_c, 1024 * sizeof(HYPRE_Real));		\
   hypre_device_reduction(d_c,hypre__tot,databox1,databox1,HYPER_LAMBDA(HYPRE_Int i1, HYPRE_Int i2, HYPRE_Real sum) \
   {

#define hypre_newBoxLoop1ReductionEnd(i1, sum)			\
       return sum;								\
   });									\
  cudaMemcpy(&sum,d_c,sizeof(HYPRE_Real),cudaMemcpyDeviceToHost);	\
  sum += sum_old;							\
  cudaFree(d_c);							\
}

#define hypre_newBoxLoop2ReductionBegin(ndim, loop_size,		\
					dbox1, start1, stride1, i1,	\
					dbox2, start2, stride2, i2,sum) \
{    									   \
   HYPRE_Real sum_old = sum;						\
   sum = 0.0;								\
   hypre_BoxLoopInit(ndim,loop_size);					\
   hypre_BoxLoopDataDeclareK(1,ndim,loop_size,dbox1,start1,stride1);	\
   hypre_BoxLoopDataDeclareK(2,ndim,loop_size,dbox2,start2,stride2);	\
   HYPRE_Real *d_c;							\
   cudaMalloc((void**) &d_c, 1024 * sizeof(HYPRE_Real));		\
   hypre_device_reduction(d_c,hypre__tot,databox1,databox2,HYPER_LAMBDA(HYPRE_Int i1, HYPRE_Int i2, HYPRE_Real sum) \
   {

#define hypre_newBoxLoop2ReductionEnd(i1, i2, sum)			\
      return sum;								\
   });									\
  cudaMemcpy(&sum,d_c,sizeof(HYPRE_Real),cudaMemcpyDeviceToHost);	\
  sum += sum_old;							\
  cudaFree(d_c);							\
}



#define hypre_newBoxLoop1ReductionMult(ndim, loop_size,			  \
				       dbox1, start1, stride1, i1,xp,sum) \
{    									  \
   HYPRE_Real sum_old = sum;\
   sum = 1.0;\
   hypre_BoxLoopInit(ndim,loop_size);				  \
   hypre_BoxLoopDataDeclareK(1,ndim,loop_size,dbox1,start1,stride1);	  \
   HYPRE_Int n_blocks = (hypre__tot+BLOCKSIZE-1)/BLOCKSIZE;		  \
   HYPRE_Real *d_b;				        		  \
   HYPRE_Real * b = new HYPRE_Real[n_blocks];				  \
   cudaMalloc((void**) &d_b, n_blocks * sizeof(HYPRE_Real));			\
   reduction_mult<HYPRE_Real><<< n_blocks ,BLOCKSIZE>>>(xp,d_b,hypre__tot,databox1);		\
   hypre_fence();							\
   for (HYPRE_Int j = 0 ; j< n_blocks ; ++j){								\
     sum *= b[j];							\
   }	  		\
   delete [] b;		\
   sum *=sum_old;\
}

#define hypre_LoopBegin(size,idx)					\
{    														\
	BoxLoopforall(hypre_exec_policy,size,HYPER_LAMBDA (HYPRE_Int idx) \
	{

#define hypre_LoopEnd()					\
	});											\
        hypre_fence();\
}

#define hypre_BoxBoundaryCopyBegin(ndim, loop_size, stride1, i1, idx) 	\
{    														\
    HYPRE_Int hypre__tot = 1;											\
    hypre_Boxloop databox1;						\
    databox1.lsize0 = loop_size[0];					\
    databox1.lsize1 = loop_size[1];					\
    databox1.lsize2 = loop_size[2];					\
    databox1.strides0 = stride1[0];					\
    databox1.strides1 = stride1[1];					\
    databox1.strides2 = stride1[2];					\
    for (HYPRE_Int d = 0;d < ndim;d ++)					\
    {									\
	hypre__tot *= loop_size[d];					\
    }									\
    BoxLoopforall(hypre_exec_policy,hypre__tot,HYPER_LAMBDA (HYPRE_Int idx) \
    {									\
	    hypre_newBoxLoopDeclare()											\
	    HYPRE_Int i1 = 0;											\
	    hypre__i  = idx_local % databox1.lsize0;			\
	    idx_local  = idx_local / databox1.lsize0;			\
	    i1 += hypre__i*databox1.strides0;				\
	    hypre__j  = idx_local % databox1.lsize1;			\
	    idx_local  = idx_local / databox1.lsize1;			\
	    i1 += hypre__j*databox1.strides1;				\
	    hypre__k  = idx_local % databox1.lsize2;			\
	    idx_local  = idx_local / databox1.lsize2;			\
	    i1 += hypre__k*databox1.strides2;				\
		
#define hypre_BoxBoundaryCopyEnd()				\
    });									\
    hypre_fence();							\
}

#define hypre_BoxDataExchangeBegin(ndim, loop_size,				\
                                   stride1, i1,	\
                                   stride2, i2)	\
{    														\
    HYPRE_Int hypre__tot = 1;											\
    hypre_Boxloop databox1,databox2;					\
    databox1.lsize0 = loop_size[0];					\
    databox1.lsize1 = loop_size[1];									\
    databox1.lsize2 = loop_size[2];					\
    databox1.strides0 = stride1[0];					\
    databox1.strides1 = stride1[1];					\
    databox1.strides2 = stride1[2];					\
    databox2.lsize0 = loop_size[0];					\
    databox2.lsize1 = loop_size[1];									\
    databox2.lsize2 = loop_size[2];					\
    databox2.strides0 = stride2[0];					\
    databox2.strides1 = stride2[1];					\
    databox2.strides2 = stride2[2];					\
    for (HYPRE_Int d = 0;d < ndim;d ++)					\
      {									\
	hypre__tot *= loop_size[d];					\
      }									\
    BoxLoopforall(hypre_exec_policy,hypre__tot,HYPER_LAMBDA (HYPRE_Int idx) \
    {									\
        hypre_newBoxLoopDeclare()					\
	HYPRE_Int i1 = 0, i2 = 0;					\
	hypre__i  = idx_local % databox1.lsize0;			\
	idx_local  = idx_local / databox1.lsize0;			\
	i1 += hypre__i*databox1.strides0;				\
	i2 += hypre__i*databox2.strides0;				\
	hypre__j  = idx_local % databox1.lsize1;			\
	idx_local  = idx_local / databox1.lsize1;			\
	i1 += hypre__j*databox1.strides1;				\
	i2 += hypre__j*databox2.strides1;				\
	hypre__k  = idx_local % databox1.lsize2;			\
	idx_local  = idx_local / databox1.lsize2;			\
	i1 += hypre__k*databox1.strides2;				\
	i2 += hypre__k*databox2.strides2;


#define hypre_BoxDataExchangeEnd()				\
     });								\
     hypre_fence();							\
}
  
#define hypre_newBoxLoop0For()

#define hypre_newBoxLoop1For(i1)

#define hypre_newBoxLoop2For(i1, i2) 
 
#define hypre_newBoxLoop3For(i1, i2, i3)

#define hypre_newBoxLoop4For(i1, i2, i3, i4)

#define hypre_newBoxLoopGetIndex(index)					\
  index[0] = hypre__i; index[1] = hypre__j; index[2] = hypre__k
  
#define hypre_BoxLoopGetIndex    zypre_BoxLoopGetIndex  
#define hypre_BoxLoopSetOneBlock() ; 
#define hypre_BoxLoopBlock()       0

#define hypre_BoxLoop0Begin      hypre_newBoxLoop0Begin
#define hypre_BoxLoop0For        hypre_newBoxLoop0For
#define hypre_BoxLoop0End        hypre_newBoxLoop0End
#define hypre_BoxLoop1Begin      hypre_newBoxLoop1Begin
#define hypre_BoxLoop1For        hypre_newBoxLoop1For
#define hypre_BoxLoop1End        hypre_newBoxLoop1End
#define hypre_BoxLoop2Begin      hypre_newBoxLoop2Begin
#define hypre_BoxLoop2For        hypre_newBoxLoop2For
#define hypre_BoxLoop2End        hypre_newBoxLoop2End
#define hypre_BoxLoop3Begin      hypre_newBoxLoop3Begin
#define hypre_BoxLoop3For        hypre_newBoxLoop3For
#define hypre_BoxLoop3End        hypre_newBoxLoop3End
#define hypre_BoxLoop4Begin      hypre_newBoxLoop4Begin
#define hypre_BoxLoop4For        hypre_newBoxLoop4For
#define hypre_BoxLoop4End        hypre_newBoxLoop4End
#endif
