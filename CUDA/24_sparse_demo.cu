//
// Created by zjlab on 9/27/23.
//
#include <iostream>
using namespace std;
#include "cusparse.h"
#include "util.h"
#include "cuda_runtime.h"


/*
 * cuSparse中的数据类型
 *
 * 1.cusparseMatDescr_t 描述稀疏矩阵的形状特征
 *
 *   (1) cusparseDiagType_t     用于指示对角线元素是不是都是1(如果是的话，那API在执行的时候就不会去读写对角线元素)
 *          CUSPARSE_DIAG_TYPE_NON_UNIT
 *          CUSPARSE_DIAG_TYPE_UNIT
 *
 *   (2) cusparseFillMode_t     运算中计算矩阵上三角或下三角部分
 *          CUSPARSE_FILL_MODE_LOWER
 *          CUSPARSE_FILL_MODE_UPPER
 *
 *   (3) cusparseIndexBase_t    指标从0开始还是1开始
 *          CUSPARSE_INDEX_BASE_ZERO
 *          CUSPARSE_INDEX_BASE_ONE
 *
 * */



__global__ void gpu_print(float *mat, int n){
    printf("hello gpu\n");
    for(int i =0; i<n; i++){
        printf("%f\n", mat[i]);
    }
}

void demo0(){
    initDevice(0);


    float a[] = {
            1.0f, 0, 2.0f, 0,
            0, 3.0f, 0, 0,
            4.0f, 5.0f, 0, 0,
            0, 0, 7.0f, 8.0f
    };

    float csr_a[] = {1.0f, 4.0f, 3.0f, 5.0f, 2.0f, 7.0f, 8.0f};

    float b[] = {1.0f, 2.0f, 3.0f, 4.0f,
                 5.0f, 6.0f, 7.0f, 8.0f,
                 9.0f, 10.0f, 11.0f, 12.0f,
                 13.0f, 14.0f, 15.0f, 16.0f
    };

    cout << "sparse matrix dense format: " << endl;
    printMatrix(a, 4, 4);

    // host
    float *lhs = a, *rhs =b;
    float *res = new float [16];
    float *host_csr_lhs = csr_a;


    //device
    float *d_lhs, *d_rhs, *d_res;
    cudaMalloc((void **)&d_lhs, 16 * sizeof(float));
    cudaMalloc(&d_rhs, 16*sizeof(float));
    cudaMalloc(&d_res, 16* sizeof(float));


    cudaMemcpy(d_lhs, lhs, 16 * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_rhs, rhs, 16 * sizeof(float), cudaMemcpyHostToDevice);



    // 创建cuSPARSE库句柄
    cusparseHandle_t handle;
    cusparseCreate(&handle);


    // cusparseCreateMatDescr和cusparseSetMat*配置矩阵某一属性
    cusparseMatDescr_t dsr;
    cusparseCreateMatDescr(&dsr);
    cusparseSetMatType(dsr, CUSPARSE_MATRIX_TYPE_GENERAL);
    cusparseSetMatIndexBase(dsr, CUSPARSE_INDEX_BASE_ZERO);



    int * nnzPerRowColumn = new int[4];
    int num=0;
    int * nnzperrow = nullptr;
    cudaMalloc(&nnzperrow, sizeof(int) *4);

    // cusparseSnnz: 统计稠密矩阵中各列和各行非零元素的数目， 以及总数
    CHECK_SPARSE(cusparseSnnz(handle, CUSPARSE_DIRECTION_ROW, 4, 4, dsr, d_lhs, 4, nnzperrow, &num));


    cudaMemcpy(nnzPerRowColumn, nnzperrow, 16, cudaMemcpyDeviceToHost);

    cout << "nonzero elem nums pre row:" << endl;
    for(int i=0; i<4; i++){
        cout << nnzPerRowColumn[i] << "  ";
    }
    cout << endl;
    cout << "none zero nums: " << num << endl;

    // host
    float * csr_lhs = new float(num);
    int *csr_lhs_col_idx = new int (num);
    int *csr_lhs_row_idx = new int(5);

    // device
    float *d_csr_lhs;
    int *d_csr_lhs_col_idx, *d_csr_lhs_row_idx;
    cudaMalloc(&d_csr_lhs, num*sizeof(float));
    cudaMalloc(&d_csr_lhs_col_idx, num * sizeof(int));
    cudaMalloc(&d_csr_lhs_row_idx, 5 * sizeof(int));

    // dense转csr
    cusparseSdense2csr(handle, 4, 4, dsr, d_lhs, 4, nnzperrow, d_csr_lhs, d_csr_lhs_row_idx, d_csr_lhs_col_idx);

    cudaMemcpy(csr_lhs, d_csr_lhs, num* sizeof(float), cudaMemcpyDeviceToHost);
    cudaMemcpy(csr_lhs_col_idx, d_csr_lhs_col_idx, num* sizeof(int), cudaMemcpyDeviceToHost);
    cudaMemcpy(csr_lhs_row_idx, d_csr_lhs_row_idx, 5* sizeof(int), cudaMemcpyDeviceToHost);

    cout << "csr value: \n";
    for(int i=0; i<num; i++){
        cout << csr_lhs[i] << "  ";
    }
    cout << endl;

    float alpha = 1.0f, beta = 0.0f;

    cudaMemcpy(d_csr_lhs, host_csr_lhs, num* sizeof(float), cudaMemcpyHostToDevice);

    cusparseSpMatDescr_t matA;      // 稀疏矩阵的描述
    cusparseDnMatDescr_t matB, matC;        // 稠密矩阵的描述
    void *dBuffer = nullptr;
    size_t bufferSize = 0;
    cusparseSpSMDescr_t spSmDescr;      // 稀疏 * 稠密 的描述
    // 创建csr左矩阵
    CHECK_SPARSE(cusparseCreateCsr(&matA, 4, 4, num, csr_lhs_row_idx, csr_lhs_col_idx, csr_lhs, CUSPARSE_INDEX_32I, CUSPARSE_INDEX_32I, CUSPARSE_INDEX_BASE_ZERO, CUDA_R_32F));
    // 创建稠密的右矩阵和输出矩阵
    CHECK_SPARSE(cusparseCreateDnMat(&matB, 4, 4, 4, d_rhs, CUDA_R_32F, CUSPARSE_ORDER_COL));
    CHECK_SPARSE(cusparseCreateDnMat(&matC, 4, 4, 4, d_res, CUDA_R_32F, CUSPARSE_ORDER_COL));
    // 创建 spSM
    CHECK_SPARSE(cusparseSpSM_createDescr(&spSmDescr));

    // 给稀疏矩阵添加填充属性
    cusparseFillMode_t  fillmode = CUSPARSE_FILL_MODE_LOWER;    // 以下三角填充？
    cusparseSpMatSetAttribute(matA, CUSPARSE_SPMAT_FILL_MODE, &fillmode, sizeof(fillmode));
    // 给稀疏矩阵添加对角线属性
    cusparseDiagType_t  diagtype = CUSPARSE_DIAG_TYPE_NON_UNIT;
    cusparseSpMatSetAttribute(matA, CUSPARSE_SPMAT_DIAG_TYPE, &diagtype, sizeof(diagtype));

    cout << "start cal: " << endl;
    CHECK_SPARSE(cusparseSpSM_bufferSize(handle, CUSPARSE_OPERATION_NON_TRANSPOSE, CUSPARSE_OPERATION_NON_TRANSPOSE, &alpha, matA, matB, matC, CUDA_R_32F, CUSPARSE_SPSM_ALG_DEFAULT, spSmDescr, &bufferSize));

    CHECK_SPARSE(cusparseSpSM_analysis(handle, CUSPARSE_OPERATION_NON_TRANSPOSE, CUSPARSE_OPERATION_NON_TRANSPOSE, &alpha, matA, matB, matC, CUDA_R_32F, CUSPARSE_SPSM_ALG_DEFAULT, spSmDescr, dBuffer));
    cout<< "middle cal: " << endl;
    CHECK_SPARSE(cusparseSpSM_solve(handle, CUSPARSE_OPERATION_NON_TRANSPOSE, CUSPARSE_OPERATION_NON_TRANSPOSE, &alpha, matA, matB, matC, CUDA_R_32F, CUSPARSE_SPSM_ALG_DEFAULT, spSmDescr));
    cout << "end cal: " << endl;

    CHECK_SPARSE(cusparseDestroySpMat(matA));

    cusparseDestroyDnMat(matB);
    cusparseDestroyDnMat(matC);
    cusparseSpSM_destroyDescr(spSmDescr);

    cusparseDestroy(handle);


    cudaMemcpy(res, d_res, 16* sizeof(float), cudaMemcpyDeviceToHost);

    for(int i=0; i<16; i++){
        cout << res[i] << endl;
    }

    cudaFree(d_lhs);
    cudaFree(d_rhs);
    cudaFree(d_csr_lhs);
    cudaFree(d_csr_lhs_row_idx);
    cudaFree(d_csr_lhs_col_idx);

    delete csr_lhs, csr_lhs_col_idx, csr_lhs_row_idx;
    delete[] nnzPerRowColumn;
}

int main(){
    // Host problem definition
    const int A_num_rows      = 4;
    const int A_num_cols      = 4;
    const int A_nnz           = 9;
    const int nrhs            = 2;
    const int ldb             = A_num_cols;
    const int ldc             = A_num_rows;
    int       hA_csrOffsets[] = { 0, 3, 4, 7, 9 };
    int       hA_columns[]    = { 0, 2, 3, 1, 0, 2, 3, 1, 3 };
    float     hA_values[]     = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f,
                                  6.0f, 7.0f, 8.0f, 9.0f };
    float     hB[]            = { 1.0f, 8.0f, 23.0f, 52.0f,
                                  1.0f, 8.0f, 23.0f, 52.0f };
    float     hC[]            = { 0.0f, 0.0f, 0.0f, 0.0f,
                                  0.0f, 0.0f, 0.0f, 0.0f };
    float     hY_result[]     = { 1.0f, 2.0f, 3.0f, 4.0f,
                                  1.0f, 2.0f, 3.0f, 4.0f };
    float     alpha           = 1.0f;
    //--------------------------------------------------------------------------
    // Device memory management
    int   *dA_csrOffsets, *dA_columns;
    float *dA_values, *dB, *dC;
    CHECK( cudaMalloc((void**) &dA_csrOffsets,
                           (A_num_rows + 1) * sizeof(int)) );
    CHECK( cudaMalloc((void**) &dA_columns, A_nnz * sizeof(int))       );
    CHECK( cudaMalloc((void**) &dA_values,  A_nnz * sizeof(float))     );
    CHECK( cudaMalloc((void**) &dB, nrhs * A_num_cols * sizeof(float)) );
    CHECK( cudaMalloc((void**) &dC, nrhs * A_num_rows * sizeof(float)) );

    CHECK( cudaMemcpy(dA_csrOffsets, hA_csrOffsets,
                           (A_num_rows + 1) * sizeof(int),
                           cudaMemcpyHostToDevice) );
    CHECK( cudaMemcpy(dA_columns, hA_columns, A_nnz * sizeof(int),
                           cudaMemcpyHostToDevice) );
    CHECK( cudaMemcpy(dA_values, hA_values, A_nnz * sizeof(float),
                           cudaMemcpyHostToDevice) );
    CHECK( cudaMemcpy(dB, hB, nrhs * A_num_cols * sizeof(float),
                           cudaMemcpyHostToDevice) );
    CHECK( cudaMemcpy(dC, hC, nrhs * A_num_rows * sizeof(float),
                           cudaMemcpyHostToDevice) );
    //--------------------------------------------------------------------------
    // CUSPARSE APIs
    cusparseHandle_t     handle = NULL;
    cusparseSpMatDescr_t matA;
    cusparseDnMatDescr_t matB, matC;
    void*                dBuffer    = NULL;
    size_t               bufferSize = 0;
    cusparseSpSMDescr_t  spsmDescr;
    CHECK_SPARSE( cusparseCreate(&handle) );
    // Create sparse matrix A in CSR format
    CHECK_SPARSE( cusparseCreateCsr(&matA, A_num_rows, A_num_cols, A_nnz,
                                      dA_csrOffsets, dA_columns, dA_values,
                                      CUSPARSE_INDEX_32I, CUSPARSE_INDEX_32I,
                                      CUSPARSE_INDEX_BASE_ZERO, CUDA_R_32F) );
    // Create dense vector X
    CHECK_SPARSE( cusparseCreateDnMat(&matB, A_num_cols, nrhs, ldb, dB,
                                        CUDA_R_32F, CUSPARSE_ORDER_COL) );
    // Create dense vector y
    CHECK_SPARSE( cusparseCreateDnMat(&matC, A_num_rows, nrhs, ldc, dC,
                                        CUDA_R_32F, CUSPARSE_ORDER_COL) );
    // Create opaque data structure, that holds analysis data between calls.
    CHECK_SPARSE( cusparseSpSM_createDescr(&spsmDescr) );
    // Specify Lower|Upper fill mode.
    cusparseFillMode_t fillmode = CUSPARSE_FILL_MODE_LOWER;
    CHECK_SPARSE( cusparseSpMatSetAttribute(matA, CUSPARSE_SPMAT_FILL_MODE,
                                              &fillmode, sizeof(fillmode)) );
    // Specify Unit|Non-Unit diagonal type.
    cusparseDiagType_t diagtype = CUSPARSE_DIAG_TYPE_NON_UNIT;
    CHECK_SPARSE( cusparseSpMatSetAttribute(matA, CUSPARSE_SPMAT_DIAG_TYPE,
                                              &diagtype, sizeof(diagtype)) );
    // allocate an external buffer for analysis
    CHECK_SPARSE( cusparseSpSM_bufferSize(
            handle, CUSPARSE_OPERATION_NON_TRANSPOSE,
            CUSPARSE_OPERATION_NON_TRANSPOSE,
            &alpha, matA, matB, matC, CUDA_R_32F,
            CUSPARSE_SPSM_ALG_DEFAULT, spsmDescr,
            &bufferSize) );
    CHECK( cudaMalloc(&dBuffer, bufferSize) );
    CHECK_SPARSE( cusparseSpSM_analysis(
            handle, CUSPARSE_OPERATION_NON_TRANSPOSE,
            CUSPARSE_OPERATION_NON_TRANSPOSE,
            &alpha, matA, matB, matC, CUDA_R_32F,
            CUSPARSE_SPSM_ALG_DEFAULT, spsmDescr, dBuffer) );
    // execute SpSM
    CHECK_SPARSE( cusparseSpSM_solve(handle, CUSPARSE_OPERATION_NON_TRANSPOSE,
                                       CUSPARSE_OPERATION_NON_TRANSPOSE,
                                       &alpha, matA, matB, matC, CUDA_R_32F,
                                       CUSPARSE_SPSM_ALG_DEFAULT, spsmDescr) );

    // destroy matrix/vector descriptors
    CHECK_SPARSE( cusparseDestroySpMat(matA) );
    CHECK_SPARSE( cusparseDestroyDnMat(matB) );
    CHECK_SPARSE( cusparseDestroyDnMat(matC) );
    CHECK_SPARSE( cusparseSpSM_destroyDescr(spsmDescr));
    CHECK_SPARSE( cusparseDestroy(handle) );
    //--------------------------------------------------------------------------
    // device result check
    CHECK( cudaMemcpy(hC, dC, nrhs * A_num_rows * sizeof(float),
                           cudaMemcpyDeviceToHost) );

    for (int i = 0; i < nrhs * A_num_rows; i++) {
        cout << hC[i] << endl;
    }

    //--------------------------------------------------------------------------
    // device memory deallocation
    CHECK( cudaFree(dBuffer) );
    CHECK( cudaFree(dA_csrOffsets) );
    CHECK( cudaFree(dA_columns) );
    CHECK( cudaFree(dA_values) );
    CHECK( cudaFree(dB) );
    CHECK( cudaFree(dC) );
    return 0;
}