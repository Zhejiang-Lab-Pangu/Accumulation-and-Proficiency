//
// Created by root on 8/30/23.
//
#include <iostream>
using namespace std;
#include <mma.h>
#include <stdio.h>
#include <cuda_runtime.h>
//using namespace nvcuda;


/*
 * check dim
 * 线程的组织形式： dim3
 *
 * i = threadIdx + gridDim * blockIdx;
 *
 * */


// 线程如何组织：threadIdx(dim3) 和 blockIdx (dim3)
__global__ void checkIndex(void){
    printf("threadIdx:(%d,%d,%d) blockIdx:(%d,%d,%d) blockDim:(%d,%d,%d)  gridDim(%d,%d,%d)\n",
           threadIdx.x,threadIdx.y,threadIdx.z,
           blockIdx.x,blockIdx.y,blockIdx.z,
           blockDim.x,blockDim.y,blockDim.z,
           gridDim.x,gridDim.y,gridDim.z);
}

void demo0(){
    int nElem=6;
    dim3 block(3, 3);
    dim3 grid((nElem+block.x-1)/block.x, (nElem+block.y-1)/block.y);
    printf("grid.x %d grid.y %d grid.z %d\n",grid.x,grid.y,grid.z);
    printf("block.x %d block.y %d block.z %d\n",block.x,block.y,block.z);
    checkIndex <<<grid,block>>> ();
    cudaDeviceReset();

}
void demo1(){
    int nElem=1024;
    dim3 block(1024);
    dim3 grid((nElem-1)/block.x+1);
    printf("grid.x %d block.x %d\n",grid.x,block.x);

    block.x=512;
    grid.x=(nElem-1)/block.x+1;
    printf("grid.x %d block.x %d\n",grid.x,block.x);

    block.x=256;
    grid.x=(nElem-1)/block.x+1;
    printf("grid.x %d block.x %d\n",grid.x,block.x);

    block.x=128;
    grid.x=(nElem-1)/block.x+1;
    printf("grid.x %d block.x %d\n",grid.x,block.x);

//    cudaDeviceReset();
}

int main()
{
    demo0();
    cout << endl;
    demo1();
    return 0;
}
