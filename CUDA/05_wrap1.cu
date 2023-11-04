//
// Created by zjlab on 9/5/23.
//

#include <iostream>
using namespace std;
#include <mma.h>
#include <stdio.h>
#include <cuda_runtime.h>
#include<math.h>
#include "util.h"


/*
 *
 * wrap1
 *
 * */


// warmup部分是提前启动一次GPU，因为第一次启动GPU时会比第二次速度慢一些
__global__ void warmup(float *c){
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    float a = 0.0, b= 0.0;

    if((tid / warpSize) % 2 == 0){
        a = 100.0f;
    } else{
        b = 200.0f;
    }

    c[tid] = a + b;
}

__global__ void mathKernel1(float *c){
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    float a = 0.0, b= 0.0;

    if(tid % 2 == 0){
        a = 100.0f;
    } else{
        b = 200.0f;
    }

    c[tid] = a + b;
}

__global__ void mathKernel2(float *c)
{
    int tid = blockIdx.x* blockDim.x + threadIdx.x;
    float a = 0.0;
    float b = 0.0;
    if ((tid/warpSize) % 2 == 0)
    {
        a = 100.0f;
    }
    else
    {
        b = 200.0f;
    }
    c[tid] = a + b;
}

__global__ void mathKernel3(float *c)
{
    int tid = blockIdx.x* blockDim.x + threadIdx.x;
    float a = 0.0;
    float b = 0.0;
    bool ipred = (tid % 2 == 0);
    if (ipred)
    {
        a = 100.0f;
    }
    else
    {
        b = 200.0f;
    }
    c[tid] = a + b;
}

int main(int argc, char **argv){
    int dev = 0;
    cudaDeviceProp deviceProp;
    cudaGetDeviceProperties(&deviceProp, dev);
    printf("%s using Device %d: %s\n", argv[0], dev, deviceProp.name);

    //set up data size
    int size = 64;
    int blocksize = 64;
    if (argc > 1) blocksize = atoi(argv[1]);
    if (argc > 2) size = atoi(argv[2]);
    printf("Data size %d ", size);

    //set up execution configuration
    dim3 block(blocksize,1);
    dim3 grid((size - 1) / block.x + 1,1);
    printf("Execution Configure (block %d grid %d)\n", block.x, grid.x);

    //allocate memory
    float * C_dev;
    size_t nBytes = size * sizeof(float);
    float * C_host=(float*)malloc(nBytes);
    cudaMalloc((float**)&C_dev, nBytes);

    //run a warmup kernel to remove overhead
    double iStart, iElaps;
    cudaDeviceSynchronize();
    iStart = cpuSecond();
    warmup<<<grid,block>>> (C_dev);
    cudaDeviceSynchronize();
    iElaps = cpuSecond() - iStart;
    printf("warmup	  <<<%d,%d>>>elapsed %lf sec \n", grid.x, block.x, iElaps);

    //run kernel 1
    iStart = cpuSecond();
    mathKernel1 <<< grid,block >>> (C_dev);
    cudaDeviceSynchronize();
    iElaps = cpuSecond() - iStart;
    printf("mathKernel1<<<%4d,%4d>>>elapsed %lf sec \n", grid.x, block.x, iElaps);
    cudaMemcpy(C_host,C_dev,nBytes,cudaMemcpyDeviceToHost);

    //run kernel 2
    iStart = cpuSecond();
    mathKernel2 <<<grid,block >>> (C_dev);
    cudaDeviceSynchronize();
    iElaps = cpuSecond() - iStart;
    printf("mathKernel2<<<%4d,%4d>>>elapsed %lf sec \n", grid.x, block.x, iElaps);

    //run kernel 3
    iStart = cpuSecond();
    mathKernel3 << <grid, block >> > (C_dev);
    cudaDeviceSynchronize();
    iElaps = cpuSecond() - iStart;
    printf("mathKernel3<<<%4d,%4d>>>elapsed %lf sec \n", grid.x, block.x, iElaps);

    cudaFree(C_dev);
    free(C_host);
    cudaDeviceReset();
    return EXIT_SUCCESS;

}




