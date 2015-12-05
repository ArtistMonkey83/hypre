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
 * $Revision: 1.3 $
 ***********************************************************************EHEADER*/



#ifndef __MLGGB_
#define __MLGGB_



#define SHIFTS   0 
#define MAX_ITRS 2 
#define MODE     6 

#include <stdio.h>
#include <stdlib.h>
#include "ml_common.h"
#include "ml_mat_formats.h" 
#include "ml_lapack.h"
#include "ml_eigf2c.h"

#define DNAUPD_F77  F77_FUNC(dnaupd,DNAUPD)
#define PDNAUPD_F77  F77_FUNC(pdnaupd,PDNAUPD)


struct ML_Eigenvalue_Struct  {
  int     Max_Iter;                  /* User input from input file */ 
  int     Num_Eigenvalues;
  int     Arnoldi;
  double  Residual_Tol;
  int     Fattening;


  int     Nflag;          /* Flag to indicate the first Newton iteration */
  int     Pnconv;         /* Previous number of converged eigenvalues */
  double *Evec, *Eval;    /* eigenvectors and eigenvalues to be reused 
			     with MGGB */

};

#ifndef ML_CPP
#ifdef __cplusplus
extern "C" {
#endif
#endif



void  ML_ARPACK_driver(char which[],
			 char bmat[], int iparam[], int mode,
			 int nev, int ncv, double tol,  ML *ml,
		       struct ML_CSR_MSRdata  *mydata, int Fattening,
		       struct ML_Eigenvalue_Struct *eigen_struct,
		       int Debug_Flag, int GGB_alp_flag);


  void ML_GGB2CSR (double *v, int nconv, int MatSize, int proc_id,
		   struct ML_CSR_MSRdata  *mydata, int Debug_Flag );
  
  
  void  ML_GGBalp (double *NewVec, int nconv, int nloc2, struct ML_Eigenvalue_Struct 
		   *eigen_struct);
  
  extern double  ML_subspace (int nrows, double *inp1, int ncols1, double *inp2, int ncols2);
  
  
  
  extern void ML_ARPACK_GGB( 
			    struct ML_Eigenvalue_Struct *eigen_struct,ML *ml,
			    struct ML_CSR_MSRdata *mydata, int Debug_Flag, 
			    int GGB_alp_flag);
  
  extern int  ML_MGGB_angle(struct ML_Eigenvalue_Struct *eigen_struct,ML *ml,
			    struct ML_CSR_MSRdata *mydata);
  
  extern int  ML_Rayleigh (ML *ml, int nrows, double *q, int count);
  
  extern double *ML_complex_gdot(int leng, double *ureal, double *uimag, double *vreal, double *vimag, 
				 ML_Comm *comm);
  
  extern double ML_normc(double *real, double *imag,  int leng );  
  
  extern void ML_Eig_Destroy(void *data);
  
  extern int ML_OperatorGGB_Apply (double *densemat, int Nrows, int Ncols, double *din, double *dout, int Transpose);

void PREFIX DNAUPD_F77(int *, char *, int *, char *, int *, double *, double *,
		 int *, double *, int *, int *, int *, double *, double *,
	       int *, int *);
  
void PREFIX PDNAUPD_F77(int *, int *, char *, int *, char *, int *, double *, double *,
		int *, double *, int *, int *, int *, double *, double *,
		int *, int *);

 
#ifndef ML_CPP
#ifdef __cplusplus
}
#endif
#endif

#endif
