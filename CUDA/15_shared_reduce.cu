//
// Created by zjlab on 9/15/23.
//
//
// Created by zjlab on 9/13/23.
//
#include <cuda_runtime.h>
#include <stdio.h>
#include "util.h"
#define DIM 1024


__global__ void reduceGmem(int *g_idata, int *g_odata, unsigned int n){

    // 块内的线程id
    unsigned int tid = threadIdx.x;
    // 全局的线程id
    unsigned int idx = blockIdx.x * blockDim.x + threadIdx.x;

    if(idx > n) return ;

    // 当前线程块的首地址
    int *idata = g_idata + blockIdx.x * blockDim.x;


    if(blockDim.x >= 1024 && tid < 512){
        idata[tid] += idata[tid+512];
    }
    __syncthreads();

    if(blockDim.x >= 512 && tid < 256){
        idata[tid] += idata[tid+256];
    }
    __syncthreads();

    if(blockDim.x >= 256 && tid < 128){
        idata[tid] += idata[tid+128];
    }
    __syncthreads();

    if(blockDim.x >= 128 && tid < 64){
        idata[tid] += idata[tid+64];
    }
    __syncthreads();


    if(tid<32){
        volatile int *vmem = idata;
        vmem[tid] += vmem[tid+32];
        vmem[tid] += vmem[tid+16];
        vmem[tid] += vmem[tid+8];
        vmem[tid] += vmem[tid+4];
        vmem[tid] += vmem[tid+2];
        vmem[tid] += vmem[tid+1];
    }

    if(tid == 0){
        g_odata[blockIdx.x] = idata[0];
    }
}


__global__ void reduceSmem(int *g_idata, int *g_odata, unsigned int n){


    __shared__ int smem[DIM];

    unsigned int tid = threadIdx.x;

    if(tid > n) return ;

    // 当前线程块的首地址
    int *idata = g_idata + blockIdx.x * blockDim.x;


    smem[tid] = idata[tid];
    __syncthreads();


    if(blockDim.x >= 1024 && tid < 512){
        smem[tid] += smem[tid+512];
    }
    __syncthreads();

    if(blockDim.x >= 512 && tid < 256){
        smem[tid] += smem[tid+256];
    }
    __syncthreads();

    if(blockDim.x >= 256 && tid < 128){
        smem[tid] += smem[tid+128];
    }
    __syncthreads();

    if(blockDim.x >= 128 && tid < 64){
        smem[tid] += smem[tid+64];
    }
    __syncthreads();


    if(tid<32){
        volatile int *vmem = smem;
        vmem[tid] += vmem[tid+32];
        vmem[tid] += vmem[tid+16];
        vmem[tid] += vmem[tid+8];
        vmem[tid] += vmem[tid+4];
        vmem[tid] += vmem[tid+2];
        vmem[tid] += vmem[tid+1];
    }

    if(tid == 0){
        g_odata[blockIdx.x] = smem[0];
    }
}


__global__ void reduceUnroll4Smem(int *g_idata, int *g_odata, unsigned int n){


    __shared__ int smem[DIM];

    // 这两个是同一个线程的两个索引，一个块内索引， 一个全局索引
    unsigned int tid = threadIdx.x;
    unsigned int idx = blockDim.x * blockIdx.x * 4 + threadIdx.x;

    if(tid > n) return ;

    int tempSum = 0;
    if(idx + 3*blockDim.x <= n){
        int a1 = g_idata[idx];
        int a2 = g_idata[idx + blockDim.x];
        int a3 = g_idata[idx + blockDim.x * 2];
        int a4 = g_idata[idx + blockDim.x * 3];

        tempSum = a1 + a2 + a3 + a4;
    }

    // 将4个块的中存储的值相加copy到共享内存中，这里 tid 与 上面的 idx 相对应
    smem[tid] = tempSum;
    __syncthreads();


    if(blockDim.x >= 1024 && tid < 512){
        smem[tid] += smem[tid+512];
    }
    __syncthreads();

    if(blockDim.x >= 512 && tid < 256){
        smem[tid] += smem[tid+256];
    }
    __syncthreads();

    if(blockDim.x >= 256 && tid < 128){
        smem[tid] += smem[tid+128];
    }
    __syncthreads();

    if(blockDim.x >= 128 && tid < 64){
        smem[tid] += smem[tid+64];
    }
    __syncthreads();


    if(tid<32){
        volatile int *vmem = smem;
        vmem[tid] += vmem[tid+32];
        vmem[tid] += vmem[tid+16];
        vmem[tid] += vmem[tid+8];
        vmem[tid] += vmem[tid+4];
        vmem[tid] += vmem[tid+2];
        vmem[tid] += vmem[tid+1];
    }

    if(tid == 0){
        g_odata[blockIdx.x] = smem[0];
    }
}



int main(int argc,char **argv)
{

    initDevice(0);


    int Elemts = 1 << 24;
    int blocksize = 1024;

    dim3 block(blocksize, 1);
    dim3 grid((Elemts-1)/blocksize+1, 1);

    int nBytes = Elemts * sizeof(int);
    int *h_g_idata = new int[Elemts];
    int *h_o_idata = new int[grid.x];
    int *tmp = new int[Elemts];

    initialData_int(h_g_idata, Elemts);
    memcpy(tmp, h_g_idata, nBytes);

    // CPU
    int cpu_sum = 0;
    cpu_sum = recursiveReduce(tmp, Elemts);
    printf("cpu sum:%d \n", cpu_sum);


    int *d_idata = nullptr;
    int *d_odata = nullptr;

    CHECK(cudaMalloc((void **)&d_idata, nBytes));
    CHECK(cudaMalloc((void**)&d_odata, grid.x * sizeof(int)));

    // Global Mem
    CHECK(cudaMemcpy(d_idata, h_g_idata, nBytes, cudaMemcpyHostToDevice));
    reduceGmem<<<grid, block>>>(d_idata, d_odata, Elemts);
    cudaDeviceSynchronize();
    CHECK(cudaMemcpy(h_o_idata, d_odata, grid.x* sizeof(int), cudaMemcpyDeviceToHost));
    int global_sum =0;
    for(int i=0; i<grid.x; i++){
        global_sum += h_o_idata[i];
    }
    printf("global sum:%d\n", global_sum);


    // Shared Mem
    CHECK(cudaMemcpy(d_idata, h_g_idata, nBytes, cudaMemcpyHostToDevice));
    reduceSmem<<<grid, block>>>(d_idata, d_odata, Elemts);
    cudaDeviceSynchronize();
    CHECK(cudaMemcpy(h_o_idata, d_odata, grid.x* sizeof(int), cudaMemcpyDeviceToHost));
    int shared_sum =0;
    for(int i=0; i<grid.x; i++){
        shared_sum += h_o_idata[i];
    }
    printf("shared sum:%d\n", shared_sum);


    // global mem unroll + Shared Mem
    dim3 grid_unroll4(grid.x/4);
    CHECK(cudaMemcpy(d_idata, h_g_idata, nBytes, cudaMemcpyHostToDevice));
    reduceUnroll4Smem<<<grid_unroll4, block>>>(d_idata, d_odata, Elemts);
    cudaDeviceSynchronize();
    CHECK(cudaMemcpy(h_o_idata, d_odata, grid.x* sizeof(int), cudaMemcpyDeviceToHost));
    int unroll_shared_sum =0;
    for(int i=0; i<grid.x; i++){
        unroll_shared_sum += h_o_idata[i];
    }
    printf("unroll shared sum:%d\n", unroll_shared_sum);

    return 0;
}