//
// Created by zjlab on 10/7/23.
//

#include <iostream>
using namespace std;
#include "cusparse.h"
#include "util.h"
#include "cuda_runtime.h"
#include "cublas.h"
#include "cublas_v2.h"


/*
 * cuBLAS的数据类型
 *      1. cublasOperation_t
 *          (1) CUBLAS_OP_N         non-transpose operation
 *          (2) CUBLAS_OP_T         transpose operation
 *          (3) CUBLAS_OP_C         conjugate transpose operation
 *
 *
 * */

void demo(){

    initDevice(0);

    int M=4, K=4, N=4;
    float *lhs = new float[M*K];
    float *rhs = new float[K*N];
    float *res = new float[M*N];
    initialData(lhs, M*K);
    initialData(rhs, K*N);
    memset(res, 0, M*N);

    float *h_res = new float[M*N];
    cpuGEMM(M, K, N, lhs, rhs,h_res);

    // 分配设备内存
    float *d_lhs = nullptr;
    float *d_rhs = nullptr;
    float *d_res = nullptr;
    cudaMalloc((void**)&d_lhs, sizeof(float)*M*K);
    cudaMalloc((void**)&d_rhs, sizeof(float)*K*N);
    cudaMalloc((void**)&d_res, sizeof(float)*M*N);


    // 创建cublas句柄
    cublasHandle_t handle;
    cublasCreate(&handle);


    // H2D
    cublasSetMatrix(M, K, sizeof(float), lhs, M, d_lhs, M);
    cublasSetMatrix(K, N, sizeof(float), rhs, K, d_rhs, K);


    // Sgemm
    const float alpha = 1.0;
    const float beta = 0.0;
    cublasSgemm(handle, CUBLAS_OP_T, CUBLAS_OP_T, M, N, K, &alpha, d_lhs, K, d_rhs, N, &beta, d_res, M);        //返回的是列主序的结果矩阵（转置矩阵）

    // D2H
    cublasGetMatrix(M, N, sizeof(float), d_res, M, res, M);


    printMatrix(res, M, N);

    cout << endl;

    printMatrix(h_res, M, N);


    cudaFree(d_lhs);
    cudaFree(d_res);
    cudaFree(d_rhs);
    delete [] lhs;
    delete [] rhs;
    delete [] res;
    delete [] h_res;

}

int main(){
    demo();
    return 0;
}