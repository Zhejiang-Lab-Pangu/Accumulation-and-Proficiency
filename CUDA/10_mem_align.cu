//
// Created by zjlab on 9/12/23.
//
#include <iostream>
using namespace std;
#include <mma.h>
#include <stdio.h>
#include <cuda_runtime.h>
#include "util.h"

/*
 * CUDA 内存对齐
 *
 * nvcc 指令
 *      (1) nvcc  -Xptxas -dlcm=cg     禁用一级缓存
 *      (2) nvcc  -Xptxas -dlcm=ca     启用一级缓存
 *
 *
 *  结构体数组 ： 并行编程范式，尤其是SIMD（单指令多数据）对SoA更友好。CUDA中普遍倾向于SoA因为这种内存访问可以有效地合并。
 *
 * */

void sumArrays(float * a,float * b,float * res,int offset,const int size)
{

    for(int i=0,k=offset;k<size;i++,k++)
    {
        res[i]=a[k]+b[k];
    }

}

__global__ void sumArraysGPU(float*a, float*b, float*res, int offset, int n)
{
    //int i=threadIdx.x;
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    int k = i + offset;
    if(k<n)
        res[i]=a[k]+b[k];
}


struct naiveStruct{
    float a;
    float b;
};



// cudaMalloc
void demo0(int argc, char **argv){
    int dev = 0;
    cudaSetDevice(dev);

    int nElem=1<<18;
    int offset=0;
    if(argc>=2)
        offset=atoi(argv[1]);
    printf("Vector size:%d\n",nElem);
    int nByte=sizeof(float)*nElem;

    float *a_h=(float*)malloc(nByte);
    float *b_h=(float*)malloc(nByte);
    float *res_h=(float*)malloc(nByte);
    float *res_from_gpu_h=(float*)malloc(nByte);
    memset(res_h,0,nByte);
    memset(res_from_gpu_h,0,nByte);


    float *a_d,*b_d,*res_d;
    CHECK(cudaMalloc((float**)&a_d,nByte));
    CHECK(cudaMalloc((float**)&b_d,nByte));
    CHECK(cudaMalloc((float**)&res_d,nByte));
    CHECK(cudaMemset(res_d,0,nByte));
    initialData(a_h,nElem);
    initialData(b_h,nElem);

    CHECK(cudaMemcpy(a_d,a_h,nByte,cudaMemcpyHostToDevice));
    CHECK(cudaMemcpy(b_d,b_h,nByte,cudaMemcpyHostToDevice));


    dim3 block(1024);
    dim3 grid(nElem/block.x);
    double iStart,iElaps;
    iStart=cpuSecond();
    sumArraysGPU<<<grid,block>>>(a_d,b_d,res_d, offset,nElem);
    cudaDeviceSynchronize();
    iElaps=cpuSecond()-iStart;
    CHECK(cudaMemcpy(res_from_gpu_h,res_d,nByte,cudaMemcpyDeviceToHost));
    printf("Execution configuration<<<%d,%d>>> Time elapsed %f sec --offset:%d \n", grid.x, block.x, iElaps, offset);

    sumArrays(a_h,b_h,res_h,offset,nElem);

    checkResult(res_h,res_from_gpu_h,nElem);
    cudaFree(a_d);
    cudaFree(b_d);
    cudaFree(res_d);

    free(a_h);
    free(b_h);
    free(res_h);
    free(res_from_gpu_h);


}




int main(int argc, char **argv) {
    demo0(argc, argv);
//    cout << endl;
//    demo1();
    return 0;
}