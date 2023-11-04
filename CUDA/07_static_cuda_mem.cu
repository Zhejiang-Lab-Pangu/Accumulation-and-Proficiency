//
// Created by zjlab on 9/11/23.
//
#include <iostream>
using namespace std;
#include <mma.h>
#include <stdio.h>
#include <cuda_runtime.h>
//using namespace nvcuda;


/*
 * CUDA 的静态全局内存
 *
 * 三个接口：
 *      (1) cudaMemcpyToSymbol;
 *      (2) cudaMemcpyFromSymbol;
 *      (3) cudaGetSymbolAddress;
 *
 * */



__device__ float devData;
__global__ void checkGlobalVariable(void){
    printf("Device: The value of the global variable is %f\n", devData);
    devData += 2.0;
}

void demo0(){
    float value = 3.14f;

    // 静态H2D内存搬运需要用此接口API
    cudaMemcpyToSymbol(devData, &value, sizeof(float));
    printf("Host: copy %f to the global variable\n",value);

    checkGlobalVariable<<<1, 1>>>();

    // 静态D2H内存搬运需要用此接口API
    cudaMemcpyFromSymbol(&value, devData, sizeof(float));
    printf("Host: the value changed by the kernel to %f \n",value);

    cudaDeviceReset();

}


// 非用cudaMemcpy
void demo1(){
    float value = 3.14f;

    // 首先得到devData的动态地址
    float *dptr = nullptr;
    cudaGetSymbolAddress((void **)&dptr, devData);


    cudaMemcpy(dptr, &value, sizeof(float), cudaMemcpyHostToDevice);
    printf("Host: copy %f to the global variable\n",value);

    checkGlobalVariable<<<1, 1>>>();

    cudaMemcpy(&value, dptr, sizeof(float), cudaMemcpyDeviceToHost);
    printf("Host: the value changed by the kernel to %f \n",value);

    cudaDeviceReset();
}

int main()
{
    demo0();
    cout << endl;
    demo1();
    return 0;
}