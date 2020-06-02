/******************************************************************************
 * Copyright 1998-2019 Lawrence Livermore National Security, LLC and other
 * HYPRE Project Developers. See the top-level COPYRIGHT file for details.
 *
 * SPDX-License-Identifier: (Apache-2.0 OR MIT)
 ******************************************************************************/

/******************************************************************************
 *
 * Matrix operation functions for hypre_CSRMatrix class.
 *
 *****************************************************************************/

#include "seq_mv.h"
#include "csr_matrix.h"

#if defined(HYPRE_USING_CUDA)

hypre_CSRMatrix*
hypre_CSRMatrixAddDevice ( hypre_CSRMatrix *A,
                           hypre_CSRMatrix *B )
{
   HYPRE_Complex    *A_data   = hypre_CSRMatrixData(A);
   HYPRE_Int        *A_i      = hypre_CSRMatrixI(A);
   HYPRE_Int        *A_j      = hypre_CSRMatrixJ(A);
   HYPRE_Int         nrows_A  = hypre_CSRMatrixNumRows(A);
   HYPRE_Int         ncols_A  = hypre_CSRMatrixNumCols(A);
   HYPRE_Int         nnz_A    = hypre_CSRMatrixNumNonzeros(A);
   HYPRE_Complex    *B_data   = hypre_CSRMatrixData(B);
   HYPRE_Int        *B_i      = hypre_CSRMatrixI(B);
   HYPRE_Int        *B_j      = hypre_CSRMatrixJ(B);
   HYPRE_Int         nrows_B  = hypre_CSRMatrixNumRows(B);
   HYPRE_Int         ncols_B  = hypre_CSRMatrixNumCols(B);
   HYPRE_Int         nnz_B    = hypre_CSRMatrixNumNonzeros(B);
   HYPRE_Complex    *C_data;
   HYPRE_Int        *C_i;
   HYPRE_Int        *C_j;
   HYPRE_Int         nnzC;
   hypre_CSRMatrix  *C;

   if (nrows_A != nrows_B || ncols_A != ncols_B)
   {
      hypre_error_w_msg(HYPRE_ERROR_GENERIC,"Warning! incompatible matrix dimensions!\n");

      return NULL;
   }

   hypreDevice_CSRSpAdd(nrows_A, nrows_B, ncols_A, nnz_A, nnz_B, A_i, A_j, A_data, B_i, B_j, B_data, NULL,
                        &nnzC, &C_i, &C_j, &C_data);

   C = hypre_CSRMatrixCreate(nrows_A, ncols_B, nnzC);
   hypre_CSRMatrixI(C) = C_i;
   hypre_CSRMatrixJ(C) = C_j;
   hypre_CSRMatrixData(C) = C_data;
   hypre_CSRMatrixMemoryLocation(C) = HYPRE_MEMORY_DEVICE;

   hypre_SyncCudaComputeStream(hypre_handle());

   return C;
}

hypre_CSRMatrix*
hypre_CSRMatrixMultiplyDevice( hypre_CSRMatrix *A,
                               hypre_CSRMatrix *B)
{
   HYPRE_Complex    *A_data   = hypre_CSRMatrixData(A);
   HYPRE_Int        *A_i      = hypre_CSRMatrixI(A);
   HYPRE_Int        *A_j      = hypre_CSRMatrixJ(A);
   HYPRE_Int         nrows_A  = hypre_CSRMatrixNumRows(A);
   HYPRE_Int         ncols_A  = hypre_CSRMatrixNumCols(A);
   HYPRE_Int         nnz_A    = hypre_CSRMatrixNumNonzeros(A);
   HYPRE_Complex    *B_data   = hypre_CSRMatrixData(B);
   HYPRE_Int        *B_i      = hypre_CSRMatrixI(B);
   HYPRE_Int        *B_j      = hypre_CSRMatrixJ(B);
   HYPRE_Int         nrows_B  = hypre_CSRMatrixNumRows(B);
   HYPRE_Int         ncols_B  = hypre_CSRMatrixNumCols(B);
   HYPRE_Int         nnz_B    = hypre_CSRMatrixNumNonzeros(B);
   HYPRE_Complex    *C_data;
   HYPRE_Int        *C_i;
   HYPRE_Int        *C_j;
   HYPRE_Int         nnzC;
   hypre_CSRMatrix  *C;

   /* HYPRE_Int         allsquare = 0; */

   if (ncols_A != nrows_B)
   {
      hypre_printf("Warning! incompatible matrix dimensions!\n");
      hypre_error_w_msg(HYPRE_ERROR_GENERIC,"Warning! incompatible matrix dimensions!\n");

      return NULL;
   }

   /*
   if (nrows_A == ncols_B)
   {
      allsquare = 1;
   }
   */

   hypreDevice_CSRSpGemm(nrows_A, ncols_A, ncols_B, nnz_A, nnz_B, A_i, A_j, A_data, B_i, B_j, B_data,
                         &C_i, &C_j, &C_data, &nnzC);

   C = hypre_CSRMatrixCreate(nrows_A, ncols_B, nnzC);
   hypre_CSRMatrixI(C) = C_i;
   hypre_CSRMatrixJ(C) = C_j;
   hypre_CSRMatrixData(C) = C_data;
   hypre_CSRMatrixMemoryLocation(C) = HYPRE_MEMORY_DEVICE;

   hypre_SyncCudaComputeStream(hypre_handle());

   return C;
}

/* split CSR matrix B_ext (extended rows of parcsr B) into diag part and offd part
 * corresponding to B.
 * Input  col_map_offd_B:
 * Output col_map_offd_C: union of col_map_offd_B and offd-indices of Bext_offd
 *        map_B_to_C: mapping from col_map_offd_B to col_map_offd_C
 */

HYPRE_Int
hypre_CSRMatrixSplitDevice( hypre_CSRMatrix  *B_ext,
                            HYPRE_BigInt      first_col_diag_B,
                            HYPRE_BigInt      last_col_diag_B,
                            HYPRE_Int         num_cols_offd_B,
                            HYPRE_BigInt     *col_map_offd_B,
                            HYPRE_Int       **map_B_to_C_ptr,
                            HYPRE_Int        *num_cols_offd_C_ptr,
                            HYPRE_BigInt    **col_map_offd_C_ptr,
                            hypre_CSRMatrix **B_ext_diag_ptr,
                            hypre_CSRMatrix **B_ext_offd_ptr )
{
   HYPRE_Int num_rows = hypre_CSRMatrixNumRows(B_ext);
   HYPRE_Int B_ext_nnz = hypre_CSRMatrixNumNonzeros(B_ext);

   HYPRE_Int *B_ext_row_indices = hypre_TAlloc(HYPRE_Int, B_ext_nnz, HYPRE_MEMORY_DEVICE);
   hypreDevice_CsrRowPtrsToIndices_v2(num_rows, B_ext_nnz, hypre_CSRMatrixI(B_ext), B_ext_row_indices);

   HYPRE_Int      B_ext_diag_nnz;
   HYPRE_Int      B_ext_offd_nnz;
   HYPRE_Int     *B_ext_diag_row_indices;
   HYPRE_Int     *B_ext_diag_j;
   HYPRE_Complex *B_ext_diag_a;
   HYPRE_Int     *B_ext_offd_row_indices;
   HYPRE_Int     *B_ext_offd_j;
   HYPRE_Complex *B_ext_offd_a;

   HYPRE_Int ierr = hypre_CSRMatrixSplitDevice_core( num_rows,
                                                     B_ext_nnz,
                                                     B_ext_row_indices,
                                                     hypre_CSRMatrixBigJ(B_ext),
                                                     hypre_CSRMatrixData(B_ext),
                                                     NULL,
                                                     first_col_diag_B,
                                                     last_col_diag_B,
                                                     num_cols_offd_B,
                                                     col_map_offd_B,
                                                     map_B_to_C_ptr,
                                                     num_cols_offd_C_ptr,
                                                     col_map_offd_C_ptr,
                                                     &B_ext_diag_nnz,
                                                     &B_ext_diag_row_indices,
                                                     &B_ext_diag_j,
                                                     &B_ext_diag_a,
                                                     NULL,
                                                     &B_ext_offd_nnz,
                                                     &B_ext_offd_row_indices,
                                                     &B_ext_offd_j,
                                                     &B_ext_offd_a,
                                                     NULL );

   hypre_TFree(B_ext_row_indices, HYPRE_MEMORY_DEVICE);

   /* convert to row ptrs */
   HYPRE_Int *B_ext_diag_i = hypreDevice_CsrRowIndicesToPtrs(num_rows, B_ext_diag_nnz, B_ext_diag_row_indices);
   HYPRE_Int *B_ext_offd_i = hypreDevice_CsrRowIndicesToPtrs(num_rows, B_ext_offd_nnz, B_ext_offd_row_indices);

   hypre_TFree(B_ext_diag_row_indices, HYPRE_MEMORY_DEVICE);
   hypre_TFree(B_ext_offd_row_indices, HYPRE_MEMORY_DEVICE);

   /* create diag and offd CSR */
   hypre_CSRMatrix *B_ext_diag = hypre_CSRMatrixCreate(num_rows, last_col_diag_B - first_col_diag_B + 1, B_ext_diag_nnz);
   hypre_CSRMatrix *B_ext_offd = hypre_CSRMatrixCreate(num_rows, *num_cols_offd_C_ptr, B_ext_offd_nnz);

   hypre_CSRMatrixI(B_ext_diag) = B_ext_diag_i;
   hypre_CSRMatrixJ(B_ext_diag) = B_ext_diag_j;
   hypre_CSRMatrixData(B_ext_diag) = B_ext_diag_a;
   hypre_CSRMatrixNumNonzeros(B_ext_diag) = B_ext_diag_nnz;
   hypre_CSRMatrixMemoryLocation(B_ext_diag) = HYPRE_MEMORY_DEVICE;

   hypre_CSRMatrixI(B_ext_offd) = B_ext_offd_i;
   hypre_CSRMatrixJ(B_ext_offd) = B_ext_offd_j;
   hypre_CSRMatrixData(B_ext_offd) = B_ext_offd_a;
   hypre_CSRMatrixNumNonzeros(B_ext_offd) = B_ext_offd_nnz;
   hypre_CSRMatrixMemoryLocation(B_ext_offd) = HYPRE_MEMORY_DEVICE;

   *B_ext_diag_ptr = B_ext_diag;
   *B_ext_offd_ptr = B_ext_offd;

   hypre_SyncCudaComputeStream(hypre_handle());

   return ierr;
}

HYPRE_Int
hypre_CSRMatrixSplitDevice_core( HYPRE_Int         num_rows,
                                 HYPRE_Int         B_ext_nnz,
                                 HYPRE_Int        *B_ext_row_indices,   /* Note: this is NOT row pointers as in CSR but row indices as in COO */
                                 HYPRE_BigInt     *B_ext_j,             /* Note: [BigInt] global column indices */
                                 HYPRE_Complex    *B_ext_data,
                                 char             *B_ext_xata,          /* companion with B_ext_data; NULL if not needed */
                                 HYPRE_BigInt      first_col_diag_B,
                                 HYPRE_BigInt      last_col_diag_B,
                                 HYPRE_Int         num_cols_offd_B,
                                 HYPRE_BigInt     *col_map_offd_B,
                                 HYPRE_Int       **map_B_to_C_ptr,
                                 HYPRE_Int        *num_cols_offd_C_ptr,
                                 HYPRE_BigInt    **col_map_offd_C_ptr,
                                 HYPRE_Int        *B_ext_diag_nnz_ptr,
                                 HYPRE_Int       **B_ext_diag_row_indices_ptr,
                                 HYPRE_Int       **B_ext_diag_j_ptr,
                                 HYPRE_Complex   **B_ext_diag_data_ptr,
                                 char            **B_ext_diag_xata_ptr, /* companion with B_ext_diag_data_ptr; NULL if not needed */
                                 HYPRE_Int        *B_ext_offd_nnz_ptr,
                                 HYPRE_Int       **B_ext_offd_row_indices_ptr,
                                 HYPRE_Int       **B_ext_offd_j_ptr,
                                 HYPRE_Complex   **B_ext_offd_data_ptr,
                                 char            **B_ext_offd_xata_ptr  /* companion with B_ext_offd_data_ptr; NULL if not needed */ )
{
   HYPRE_Int        B_ext_diag_nnz = 0;
   HYPRE_Int        B_ext_offd_nnz = 0;
   HYPRE_Int       *tmpi;
   HYPRE_Complex   *tmpc;

   HYPRE_Int     *B_ext_diag_row_indices;
   HYPRE_Int     *B_ext_offd_row_indices;
   HYPRE_Int     *B_ext_diag_j    = NULL;
   HYPRE_Complex *B_ext_diag_a    = NULL;
   HYPRE_Int     *B_ext_offd_j    = NULL;
   HYPRE_Complex *B_ext_offd_a    = NULL;

   char          *B_ext_diag_x    = NULL;
   char          *B_ext_offd_x    = NULL;

   HYPRE_BigInt  *col_map_offd_C;
   HYPRE_Int     *map_B_to_C = NULL;
   HYPRE_Int      num_cols_offd_C;

   in_range<HYPRE_BigInt>     pred1(first_col_diag_B, last_col_diag_B);
   out_of_range<HYPRE_BigInt> pred2(first_col_diag_B, last_col_diag_B);

   /* get diag and offd nnz */
   B_ext_diag_nnz = HYPRE_THRUST_CALL(count_if, B_ext_j, B_ext_j + B_ext_nnz, pred1);
   B_ext_offd_nnz = B_ext_nnz - B_ext_diag_nnz;

   /* allocate memory */
   B_ext_diag_j = hypre_TAlloc(HYPRE_Int,     B_ext_diag_nnz, HYPRE_MEMORY_DEVICE);
   B_ext_diag_a = hypre_TAlloc(HYPRE_Complex, B_ext_diag_nnz, HYPRE_MEMORY_DEVICE);

   B_ext_offd_j = hypre_TAlloc(HYPRE_Int,     B_ext_offd_nnz, HYPRE_MEMORY_DEVICE);
   B_ext_offd_a = hypre_TAlloc(HYPRE_Complex, B_ext_offd_nnz, HYPRE_MEMORY_DEVICE);

   B_ext_diag_row_indices = hypre_TAlloc(HYPRE_Int, B_ext_diag_nnz, HYPRE_MEMORY_DEVICE);
   B_ext_offd_row_indices = hypre_TAlloc(HYPRE_Int, B_ext_offd_nnz, HYPRE_MEMORY_DEVICE);

   if (B_ext_xata)
   {
      if (B_ext_diag_xata_ptr)
      {
         B_ext_diag_x = hypre_TAlloc(char, B_ext_diag_nnz, HYPRE_MEMORY_DEVICE);
      }
      if (B_ext_offd_xata_ptr)
      {
         B_ext_offd_x = hypre_TAlloc(char, B_ext_offd_nnz, HYPRE_MEMORY_DEVICE);
      }
   }

   /* copy to diag */
   tmpi = HYPRE_THRUST_CALL(copy_if, B_ext_j, B_ext_j + B_ext_nnz, B_ext_j, B_ext_diag_j, pred1);
   hypre_assert(tmpi - B_ext_diag_j == B_ext_diag_nnz);

   tmpc = HYPRE_THRUST_CALL(copy_if, B_ext_data, B_ext_data + B_ext_nnz, B_ext_j, B_ext_diag_a, pred1);
   hypre_assert(tmpc - B_ext_diag_a == B_ext_diag_nnz);

   if (B_ext_diag_x)
   {
      HYPRE_THRUST_CALL(copy_if, B_ext_xata, B_ext_xata + B_ext_nnz, B_ext_j, B_ext_diag_x, pred1);
   }

   tmpi = HYPRE_THRUST_CALL(copy_if, B_ext_row_indices, B_ext_row_indices + B_ext_nnz, B_ext_j,
                            B_ext_diag_row_indices, pred1);
   hypre_assert(tmpi - B_ext_diag_row_indices == B_ext_diag_nnz);

   /* copy to offd */
   tmpi = HYPRE_THRUST_CALL(copy_if, B_ext_j, B_ext_j + B_ext_nnz, B_ext_j, B_ext_offd_j, pred2);
   hypre_assert(tmpi - B_ext_offd_j == B_ext_offd_nnz);

   tmpc = HYPRE_THRUST_CALL(copy_if, B_ext_data, B_ext_data + B_ext_nnz, B_ext_j, B_ext_offd_a, pred2);
   hypre_assert(tmpc - B_ext_offd_a == B_ext_offd_nnz);

   if (B_ext_offd_x)
   {
      HYPRE_THRUST_CALL(copy_if, B_ext_xata, B_ext_xata + B_ext_nnz, B_ext_j, B_ext_offd_x, pred1);
   }

   tmpi = HYPRE_THRUST_CALL(copy_if, B_ext_row_indices, B_ext_row_indices + B_ext_nnz, B_ext_j,
                            B_ext_offd_row_indices, pred2);
   hypre_assert(tmpi - B_ext_offd_row_indices == B_ext_offd_nnz);

   /* offd map of B_ext_offd Union col_map_offd_B */
   col_map_offd_C = hypre_TAlloc(HYPRE_BigInt, B_ext_offd_nnz + num_cols_offd_B, HYPRE_MEMORY_DEVICE);
   hypre_TMemcpy(col_map_offd_C, B_ext_offd_j, HYPRE_Int, B_ext_offd_nnz, HYPRE_MEMORY_DEVICE, HYPRE_MEMORY_DEVICE);
   hypre_TMemcpy(col_map_offd_C + B_ext_offd_nnz, col_map_offd_B, HYPRE_Int, num_cols_offd_B, HYPRE_MEMORY_DEVICE, HYPRE_MEMORY_DEVICE);
   HYPRE_THRUST_CALL(sort, col_map_offd_C, col_map_offd_C + B_ext_offd_nnz + num_cols_offd_B);
   tmpi = HYPRE_THRUST_CALL(unique, col_map_offd_C, col_map_offd_C + B_ext_offd_nnz + num_cols_offd_B);
   num_cols_offd_C = tmpi - col_map_offd_C;
#if 1
   HYPRE_BigInt *tmp = hypre_TAlloc(HYPRE_BigInt, num_cols_offd_C, HYPRE_MEMORY_DEVICE);
   hypre_TMemcpy(tmp, col_map_offd_C, HYPRE_BigInt, num_cols_offd_C, HYPRE_MEMORY_DEVICE, HYPRE_MEMORY_DEVICE);
   hypre_TFree(col_map_offd_C, HYPRE_MEMORY_DEVICE);
   col_map_offd_C = tmp;
#else
   col_map_offd_C = hypre_TReAlloc_v2(col_map_offd_C, HYPRE_Int, B_ext_offd_nnz + num_cols_offd_B, HYPRE_Int, num_cols_offd_C, HYPRE_MEMORY_DEVICE);
#endif

   /* create map from col_map_offd_B */
   if (num_cols_offd_B)
   {
      map_B_to_C = hypre_TAlloc(HYPRE_Int, num_cols_offd_B, HYPRE_MEMORY_DEVICE);
      HYPRE_THRUST_CALL(lower_bound, col_map_offd_C, col_map_offd_C + num_cols_offd_C, col_map_offd_B,
                        col_map_offd_B + num_cols_offd_B, map_B_to_C);
   }

   /* adjust diag and offd col indices */
   HYPRE_THRUST_CALL(transform, B_ext_diag_j, B_ext_diag_j + B_ext_diag_nnz,
                     thrust::make_constant_iterator(first_col_diag_B), B_ext_diag_j,
                     thrust::minus<HYPRE_Int>());
   HYPRE_THRUST_CALL(lower_bound, col_map_offd_C, col_map_offd_C + num_cols_offd_C,
                       B_ext_offd_j, B_ext_offd_j + B_ext_offd_nnz, B_ext_offd_j);

   if (map_B_to_C_ptr)
   {
      *map_B_to_C_ptr   = map_B_to_C;
   }
   *num_cols_offd_C_ptr        = num_cols_offd_C;
   *col_map_offd_C_ptr         = col_map_offd_C;
   *B_ext_diag_nnz_ptr         = B_ext_diag_nnz;
   *B_ext_diag_row_indices_ptr = B_ext_diag_row_indices;
   *B_ext_diag_j_ptr           = B_ext_diag_j;
   *B_ext_diag_data_ptr        = B_ext_diag_a;
   *B_ext_offd_nnz_ptr         = B_ext_offd_nnz;
   *B_ext_offd_row_indices_ptr = B_ext_offd_row_indices;
   *B_ext_offd_j_ptr           = B_ext_offd_j;
   *B_ext_offd_data_ptr        = B_ext_offd_a;

   if (B_ext_diag_xata_ptr)
   {
      *B_ext_diag_xata_ptr = B_ext_diag_x;
   }

   if (B_ext_offd_xata_ptr)
   {
      *B_ext_offd_xata_ptr = B_ext_offd_x;
   }

   return hypre_error_flag;
}


HYPRE_Int
hypre_CSRMatrixTransposeDevice(hypre_CSRMatrix  *A,
                               hypre_CSRMatrix **AT_ptr,
                               HYPRE_Int         data)
{
   HYPRE_Complex    *A_data   = hypre_CSRMatrixData(A);
   HYPRE_Int        *A_i      = hypre_CSRMatrixI(A);
   HYPRE_Int        *A_j      = hypre_CSRMatrixJ(A);
   HYPRE_Int         nrows_A  = hypre_CSRMatrixNumRows(A);
   HYPRE_Int         ncols_A  = hypre_CSRMatrixNumCols(A);
   HYPRE_Int         nnz_A    = hypre_CSRMatrixNumNonzeros(A);
   HYPRE_Complex    *C_data;
   HYPRE_Int        *C_i;
   HYPRE_Int        *C_j;
   hypre_CSRMatrix  *C;

   hypreDevice_CSRSpTrans(nrows_A, ncols_A, nnz_A, A_i, A_j, A_data, &C_i, &C_j, &C_data, data);

   C = hypre_CSRMatrixCreate(ncols_A, nrows_A, nnz_A);
   hypre_CSRMatrixI(C) = C_i;
   hypre_CSRMatrixJ(C) = C_j;
   hypre_CSRMatrixData(C) = C_data;
   hypre_CSRMatrixMemoryLocation(C) = HYPRE_MEMORY_DEVICE;

   *AT_ptr = C;

   hypre_SyncCudaComputeStream(hypre_handle());

   return hypre_error_flag;
}

/*--------------------------------------------------------------------------
 * hypre_CSRMatrixAddPartial:
 * adds matrix rows in the CSR matrix B to the CSR Matrix A, where row_nums[i]
 * defines to which row of A the i-th row of B is added, and returns a CSR Matrix C;
 * Repeated row indices are allowed in row_nums
 * Note: The routine does not check for 0-elements which might be generated
 *       through cancellation of elements in A and B or already contained
 *       in A and B. To remove those, use hypre_CSRMatrixDeleteZeros
 *--------------------------------------------------------------------------*/

hypre_CSRMatrix*
hypre_CSRMatrixAddPartialDevice( hypre_CSRMatrix *A,
                                 hypre_CSRMatrix *B,
                                 HYPRE_Int       *row_nums)
{
   HYPRE_Complex    *A_data   = hypre_CSRMatrixData(A);
   HYPRE_Int        *A_i      = hypre_CSRMatrixI(A);
   HYPRE_Int        *A_j      = hypre_CSRMatrixJ(A);
   HYPRE_Int         nrows_A  = hypre_CSRMatrixNumRows(A);
   HYPRE_Int         ncols_A  = hypre_CSRMatrixNumCols(A);
   HYPRE_Int         nnz_A    = hypre_CSRMatrixNumNonzeros(A);
   HYPRE_Complex    *B_data   = hypre_CSRMatrixData(B);
   HYPRE_Int        *B_i      = hypre_CSRMatrixI(B);
   HYPRE_Int        *B_j      = hypre_CSRMatrixJ(B);
   HYPRE_Int         nrows_B  = hypre_CSRMatrixNumRows(B);
   HYPRE_Int         ncols_B  = hypre_CSRMatrixNumCols(B);
   HYPRE_Int         nnz_B    = hypre_CSRMatrixNumNonzeros(B);
   HYPRE_Complex    *C_data;
   HYPRE_Int        *C_i;
   HYPRE_Int        *C_j;
   HYPRE_Int         nnzC;
   hypre_CSRMatrix  *C;

   if (ncols_A != ncols_B)
   {
      hypre_error_w_msg(HYPRE_ERROR_GENERIC,"Warning! incompatible matrix dimensions!\n");

      return NULL;
   }

   hypreDevice_CSRSpAdd(nrows_A, nrows_B, ncols_A, nnz_A, nnz_B, A_i, A_j, A_data, B_i, B_j, B_data, row_nums,
                        &nnzC, &C_i, &C_j, &C_data);

   C = hypre_CSRMatrixCreate(nrows_A, ncols_B, nnzC);
   hypre_CSRMatrixI(C) = C_i;
   hypre_CSRMatrixJ(C) = C_j;
   hypre_CSRMatrixData(C) = C_data;
   hypre_CSRMatrixMemoryLocation(C) = HYPRE_MEMORY_DEVICE;

   hypre_SyncCudaComputeStream(hypre_handle());

   return C;
}

HYPRE_Int
hypre_CSRMatrixColNNzRealDevice( hypre_CSRMatrix  *A,
                                 HYPRE_Real       *colnnz)
{
   HYPRE_Int *A_j      = hypre_CSRMatrixJ(A);
   HYPRE_Int  ncols_A  = hypre_CSRMatrixNumCols(A);
   HYPRE_Int  nnz_A    = hypre_CSRMatrixNumNonzeros(A);
   HYPRE_Int *A_j_sorted;
   HYPRE_Int  num_reduced_col_indices;
   HYPRE_Int *reduced_col_indices;
   HYPRE_Int *reduced_col_nnz;

   A_j_sorted = hypre_TAlloc(HYPRE_Int, nnz_A, HYPRE_MEMORY_DEVICE);
   hypre_TMemcpy(A_j_sorted, A_j, HYPRE_Int, nnz_A, HYPRE_MEMORY_DEVICE, HYPRE_MEMORY_DEVICE);
   HYPRE_THRUST_CALL(sort, A_j_sorted, A_j_sorted + nnz_A);

   reduced_col_indices = hypre_TAlloc(HYPRE_Int, ncols_A, HYPRE_MEMORY_DEVICE);
   reduced_col_nnz     = hypre_TAlloc(HYPRE_Int, ncols_A, HYPRE_MEMORY_DEVICE);

   thrust::pair<HYPRE_Int*, HYPRE_Int*> new_end =
   HYPRE_THRUST_CALL(reduce_by_key, A_j_sorted, A_j_sorted + nnz_A,
                     thrust::make_constant_iterator(1),
                     reduced_col_indices,
                     reduced_col_nnz);

   hypre_assert(new_end.first - reduced_col_indices == new_end.second - reduced_col_nnz);

   num_reduced_col_indices = new_end.first - reduced_col_indices;

   hypre_Memset(colnnz, 0, ncols_A * sizeof(HYPRE_Real), HYPRE_MEMORY_DEVICE);
   HYPRE_THRUST_CALL(scatter, reduced_col_nnz, reduced_col_nnz + num_reduced_col_indices,
                     reduced_col_indices, colnnz);

   hypre_TFree(A_j_sorted,          HYPRE_MEMORY_DEVICE);
   hypre_TFree(reduced_col_indices, HYPRE_MEMORY_DEVICE);
   hypre_TFree(reduced_col_nnz,     HYPRE_MEMORY_DEVICE);

   hypre_SyncCudaComputeStream(hypre_handle());

   return hypre_error_flag;
}

__global__ void
hypreCUDAKernel_CSRMoveDiagFirst( HYPRE_Int      nrows,
                                  HYPRE_Int     *ia,
                                  HYPRE_Int     *ja,
                                  HYPRE_Complex *aa )
{
   HYPRE_Int row = hypre_cuda_get_grid_warp_id<1,1>();

   if (row >= nrows)
   {
      return;
   }

   HYPRE_Int lane = hypre_cuda_get_lane_id<1>();
   HYPRE_Int p, q;

   if (lane < 2)
   {
      p = read_only_load(ia + row + lane);
   }
   q = __shfl_sync(HYPRE_WARP_FULL_MASK, p, 1);
   p = __shfl_sync(HYPRE_WARP_FULL_MASK, p, 0);

   for (HYPRE_Int j = p + lane + 1; __any_sync(HYPRE_WARP_FULL_MASK, j < q); j += HYPRE_WARP_SIZE)
   {
      hypre_int find_diag = j < q && ja[j] == row;

      if (find_diag)
      {
         ja[j] = ja[p];
         ja[p] = row;
         HYPRE_Complex tmp = aa[p];
         aa[p] = aa[j];
         aa[j] = tmp;
      }

      if ( __any_sync(HYPRE_WARP_FULL_MASK, find_diag) )
      {
         break;
      }
   }
}

HYPRE_Int
hypre_CSRMatrixMoveDiagFirstDevice( hypre_CSRMatrix  *A )
{
   HYPRE_Int      nrows  = hypre_CSRMatrixNumRows(A);
   HYPRE_Complex *A_data = hypre_CSRMatrixData(A);
   HYPRE_Int     *A_i    = hypre_CSRMatrixI(A);
   HYPRE_Int     *A_j    = hypre_CSRMatrixJ(A);
   dim3           bDim, gDim;

   bDim = hypre_GetDefaultCUDABlockDimension();
   gDim = hypre_GetDefaultCUDAGridDimension(nrows, "warp", bDim);

   HYPRE_CUDA_LAUNCH(hypreCUDAKernel_CSRMoveDiagFirst, gDim, bDim,
                     nrows, A_i, A_j, A_data);

   hypre_SyncCudaComputeStream(hypre_handle());

   return hypre_error_flag;
}

/* type == 0, sum,
 *         1, abs sum (l-1)
 *         2, square sum (l-2)
 */
template<HYPRE_Int type>
__global__ void
hypreCUDAKernel_CSRRowSum( HYPRE_Int      nrows,
                           HYPRE_Int     *ia,
                           HYPRE_Int     *ja,
                           HYPRE_Complex *aa,
                           HYPRE_Int     *CF_i,
                           HYPRE_Int     *CF_j,
                           HYPRE_Complex *row_sum,
                           HYPRE_Complex  scal,
                           HYPRE_Int      set)
{
   HYPRE_Int row_i = hypre_cuda_get_grid_warp_id<1,1>();

   if (row_i >= nrows)
   {
      return;
   }

   HYPRE_Int lane = hypre_cuda_get_lane_id<1>();
   HYPRE_Int p, q;

   if (lane < 2)
   {
      p = read_only_load(ia + row_i + lane);
   }
   q = __shfl_sync(HYPRE_WARP_FULL_MASK, p, 1);
   p = __shfl_sync(HYPRE_WARP_FULL_MASK, p, 0);

   HYPRE_Complex row_sum_i = 0.0;

   for (HYPRE_Int j = p + lane; __any_sync(HYPRE_WARP_FULL_MASK, j < q); j += HYPRE_WARP_SIZE)
   {
      if ( j >= q || (CF_i && CF_j && read_only_load(&CF_i[row_i]) != read_only_load(&CF_j[ja[j]])) )
      {
         continue;
      }

      HYPRE_Complex aii = aa[j];

      if (type == 0)
      {
         row_sum_i += aii;
      }
      else if (type == 1)
      {
         row_sum_i += fabs(aii);
      }
      else if (type == 2)
      {
         row_sum_i += aii * aii;
      }
   }

   row_sum_i = warp_reduce_sum(row_sum_i);

   if (lane == 0)
   {
      if (set)
      {
         row_sum[row_i] = scal * row_sum_i;
      }
      else
      {
         row_sum[row_i] += scal * row_sum_i;
      }
   }
}

void
hypre_CSRMatrixComputeRowSumDevice( hypre_CSRMatrix *A,
                                    HYPRE_Int       *CF_i,
                                    HYPRE_Int       *CF_j,
                                    HYPRE_Complex   *row_sum,
                                    HYPRE_Int        type,
                                    HYPRE_Complex    scal,
                                    const char      *set_or_add)
{
   HYPRE_Int      nrows  = hypre_CSRMatrixNumRows(A);
   HYPRE_Complex *A_data = hypre_CSRMatrixData(A);
   HYPRE_Int     *A_i    = hypre_CSRMatrixI(A);
   HYPRE_Int     *A_j    = hypre_CSRMatrixJ(A);
   dim3           bDim, gDim;

   bDim = hypre_GetDefaultCUDABlockDimension();
   gDim = hypre_GetDefaultCUDAGridDimension(nrows, "warp", bDim);

   if (type == 0)
   {
      HYPRE_CUDA_LAUNCH( hypreCUDAKernel_CSRRowSum<0>, gDim, bDim, nrows, A_i, A_j, A_data, CF_i, CF_j,
                         row_sum, scal, set_or_add[0] == 's' );
   }
   else if (type == 1)
   {
      HYPRE_CUDA_LAUNCH( hypreCUDAKernel_CSRRowSum<1>, gDim, bDim, nrows, A_i, A_j, A_data, CF_i, CF_j,
                         row_sum, scal, set_or_add[0] == 's' );
   }
   else if (type == 2)
   {
      HYPRE_CUDA_LAUNCH( hypreCUDAKernel_CSRRowSum<2>, gDim, bDim, nrows, A_i, A_j, A_data, CF_i, CF_j,
                         row_sum, scal, set_or_add[0] == 's' );
   }

   hypre_SyncCudaComputeStream(hypre_handle());
}

/* type 0: diag
 *      1: abs diag
 */
__global__ void
hypreCUDAKernel_CSRExtractDiag( HYPRE_Int      nrows,
                                HYPRE_Int     *ia,
                                HYPRE_Int     *ja,
                                HYPRE_Complex *aa,
                                HYPRE_Complex *d,
                                HYPRE_Int      type)
{
   HYPRE_Int row = hypre_cuda_get_grid_warp_id<1,1>();

   if (row >= nrows)
   {
      return;
   }

   HYPRE_Int lane = hypre_cuda_get_lane_id<1>();
   HYPRE_Int p, q;

   if (lane < 2)
   {
      p = read_only_load(ia + row + lane);
   }
   q = __shfl_sync(HYPRE_WARP_FULL_MASK, p, 1);
   p = __shfl_sync(HYPRE_WARP_FULL_MASK, p, 0);

   HYPRE_Int has_diag = 0;

   for (HYPRE_Int j = p + lane; __any_sync(HYPRE_WARP_FULL_MASK, j < q); j += HYPRE_WARP_SIZE)
   {
      hypre_int find_diag = j < q && ja[j] == row;

      if (find_diag)
      {
         if (type == 0)
         {
            d[row] = aa[j];
         }
         else if (type == 1)
         {
            d[row] = fabs(aa[j]);
         }
      }

      if ( __any_sync(HYPRE_WARP_FULL_MASK, find_diag) )
      {
         has_diag = 1;
         break;
      }
   }

   if (!has_diag && lane == 0)
   {
      d[row] = 0.0;
   }
}

void
hypre_CSRMatrixExtractDiagonalDevice( hypre_CSRMatrix *A,
                                      HYPRE_Complex   *d,
                                      HYPRE_Int        type)
{
   HYPRE_Int      nrows  = hypre_CSRMatrixNumRows(A);
   HYPRE_Complex *A_data = hypre_CSRMatrixData(A);
   HYPRE_Int     *A_i    = hypre_CSRMatrixI(A);
   HYPRE_Int     *A_j    = hypre_CSRMatrixJ(A);
   dim3           bDim, gDim;

   bDim = hypre_GetDefaultCUDABlockDimension();
   gDim = hypre_GetDefaultCUDAGridDimension(nrows, "warp", bDim);

   HYPRE_CUDA_LAUNCH( hypreCUDAKernel_CSRExtractDiag, gDim, bDim, nrows, A_i, A_j, A_data, d, type );

   hypre_SyncCudaComputeStream(hypre_handle());
}

#endif /* HYPRE_USING_CUDA */

