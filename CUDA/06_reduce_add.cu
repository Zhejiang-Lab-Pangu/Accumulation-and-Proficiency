//
// Created by zjlab on 9/7/23.
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
 * reduce add
 *
 * */


__global__ void warmup(int * g_idata, int * g_odata, unsigned int n)
{
    //set thread ID
    unsigned int tid = threadIdx.x;
    //boundary check
    if (tid >= n) return;
    //convert global data pointer to the
    int *idata = g_idata + blockIdx.x*blockDim.x;
    //in-place reduction in global memory
    for (int stride = 1; stride < blockDim.x; stride *= 2)
    {
        if ((tid % (2 * stride)) == 0)
        {
            idata[tid] += idata[tid + stride];
        }
        //synchronize within block
        __syncthreads();
    }
    //write result for this block to global mem
    if (tid == 0)
        g_odata[blockIdx.x] = idata[0];

}


__global__ void reduceNeighbored(int * g_idata,int * g_odata,unsigned int n)
{
    unsigned int tid = threadIdx.x;

    if(tid>n) return;

    int *idata = g_idata+ blockDim.x * blockIdx.x;

    for(int stride=1; stride<blockDim.x; stride*=2){
        if((tid % (2 * stride)) == 0){
            idata[tid] += idata[tid + stride];
        }
        __syncthreads();        //synchronize within block  每轮操作都是并行的，不保证所有线程能同时执行完毕，所以需要等待；避免块内的线程竞争内存
    }

    if(tid == 0){
        g_odata[blockIdx.x] = idata[0];
    }
}


__global__ void reduceNeighboredLess(int * g_idata,int *g_odata,unsigned int n)
{
    unsigned int tid = threadIdx.x;
    unsigned idx = blockIdx.x*blockDim.x + threadIdx.x;
    // convert global data pointer to the local point of this block
    int *idata = g_idata + blockIdx.x*blockDim.x;
    if (idx > n)
        return;
    //in-place reduction in global memory
    for (int stride = 1; stride < blockDim.x; stride *= 2)
    {
        //convert tid into local array index
        int index = 2 * stride *tid;
        if (index < blockDim.x)
        {
            idata[index] += idata[index + stride];
        }
        __syncthreads();
    }
    //write result for this block to global men
    if (tid == 0)
        g_odata[blockIdx.x] = idata[0];
}


__global__ void reduceInterleaved(int * g_idata, int *g_odata, unsigned int n)
{
    unsigned int tid = threadIdx.x;
    unsigned idx = blockIdx.x*blockDim.x + threadIdx.x;
    // convert global data pointer to the local point of this block
    int *idata = g_idata + blockIdx.x*blockDim.x;
    if (idx >= n)
        return;
    //in-place reduction in global memory
    for (int stride = blockDim.x/2; stride >0; stride >>=1)
    {

        if (tid <stride)
        {
            idata[tid] += idata[tid + stride];
        }
        __syncthreads();
    }
    //write result for this block to global men
    if (tid == 0)
        g_odata[blockIdx.x] = idata[0];
}


// 展开的规约 - 展开尺度2
__global__ void reduceUnroll2(int *g_idata, int *g_odata, unsigned int n){

    unsigned int tid = threadIdx.x;
    unsigned int idx = blockDim.x * blockIdx.x * 2 + threadIdx.x;

    if(tid>=n) return;

    int *idata = g_idata + blockIdx.x * blockDim.x *2;

    if(idx+blockDim.x < n){
        g_idata[idx] += g_idata[idx+blockDim.x];
    }
    __syncthreads();

    for(int stride = blockDim.x/2; stride>0; stride>>=1){
        if(tid < stride){
            idata[tid] += idata[tid+stride];
        }
        __syncthreads();
    }

    if(tid == 0){
        g_odata[blockIdx.x] = idata[0];
    }
}



// 展开的规约 - 展开尺度4
__global__ void reduceUnroll4(int *g_idata, int *g_odata, unsigned  int n){

    unsigned int tid = threadIdx.x;
    unsigned int idx = blockDim.x * blockIdx.x * 4 + threadIdx.x;

    if(tid >=n) return;

    int *idata = g_idata + blockDim.x * blockIdx.x * 4;

    if(idx + 3 * blockDim.x < n){
        g_idata[idx] += g_idata[idx+blockDim.x];
        g_idata[idx] += g_idata[idx+blockDim.x * 2];
        g_idata[idx] += g_idata[idx+blockDim.x * 3];
    }
    __syncthreads();

    for(int stride = blockDim.x/2; stride>0; stride>>=1){
        if(tid < stride){
            idata[tid] += idata[tid+stride];
        }
        __syncthreads();
    }

    if(tid == 0){
        g_odata[blockIdx.x] = idata[0];
    }
}


// 展开的规约 - 展开尺度8
__global__ void reduceUnroll8(int *g_idata, int *g_odata, unsigned  int n){

    unsigned int tid = threadIdx.x;
    unsigned int idx = blockDim.x * blockIdx.x * 8 + threadIdx.x;

    if(tid >=n) return;

    int *idata = g_idata + blockDim.x * blockIdx.x * 8;

    if(idx + 7 * blockDim.x < n){
        g_idata[idx] += g_idata[idx+blockDim.x];
        g_idata[idx] += g_idata[idx+blockDim.x * 2];
        g_idata[idx] += g_idata[idx+blockDim.x * 3];
        g_idata[idx] += g_idata[idx+blockDim.x * 4];
        g_idata[idx] += g_idata[idx+blockDim.x * 5];
        g_idata[idx] += g_idata[idx+blockDim.x * 6];
        g_idata[idx] += g_idata[idx+blockDim.x * 7];
    }
    __syncthreads();

    for(int stride = blockDim.x/2; stride>0; stride>>=1){
        if(tid < stride){
            idata[tid] += idata[tid+stride];
        }
        __syncthreads();
    }

    if(tid == 0){
        g_odata[blockIdx.x] = idata[0];
    }
}



// 完全展开的规约 - 在warp级别中
__global__ void reduceUnrollWarp8(int *g_idata, int *g_odata, unsigned  int n){

    unsigned int tid = threadIdx.x;
    unsigned int idx = blockDim.x * blockIdx.x * 8 + threadIdx.x;

    if(tid >=n) return;

    int *idata = g_idata + blockDim.x * blockIdx.x * 8;

    if(idx + 7 * blockDim.x < n){
        g_idata[idx] += g_idata[idx+blockDim.x];
        g_idata[idx] += g_idata[idx+blockDim.x * 2];
        g_idata[idx] += g_idata[idx+blockDim.x * 3];
        g_idata[idx] += g_idata[idx+blockDim.x * 4];
        g_idata[idx] += g_idata[idx+blockDim.x * 5];
        g_idata[idx] += g_idata[idx+blockDim.x * 6];
        g_idata[idx] += g_idata[idx+blockDim.x * 7];
    }
    __syncthreads();

    for(int stride = blockDim.x/2; stride>32; stride>>=1){
        if(tid < stride){
            idata[tid] += idata[tid+stride];
        }
        __syncthreads();
    }

    if(tid < 32){

        // 添加volatile，防止编译器优化数据传输而打乱执行顺序
        volatile int *vmem = idata;     // 控制变量结果写回到内存，而不是存在共享内存，或者缓存中;

        vmem[tid] += vmem[tid+32];      // 当执行 tid+32的时候，这32个线程都在执行这步,不会进入到下一句，以下同理
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



// 模板函数的归约
__global__ void reduceCompleteUnrollWarp8(int * g_idata,int * g_odata,unsigned int n)
{
    //set thread ID
    unsigned int tid = threadIdx.x;
    unsigned int idx = blockDim.x*blockIdx.x*8+threadIdx.x;
    //boundary check
    if (tid >= n) return;
    //convert global data pointer to the
    int *idata = g_idata + blockIdx.x*blockDim.x*8;
    if(idx+7 * blockDim.x<n)
    {
        int a1=g_idata[idx];
        int a2=g_idata[idx+blockDim.x];
        int a3=g_idata[idx+2*blockDim.x];
        int a4=g_idata[idx+3*blockDim.x];
        int a5=g_idata[idx+4*blockDim.x];
        int a6=g_idata[idx+5*blockDim.x];
        int a7=g_idata[idx+6*blockDim.x];
        int a8=g_idata[idx+7*blockDim.x];
        g_idata[idx]=a1+a2+a3+a4+a5+a6+a7+a8;

    }
    __syncthreads();

    //in-place reduction in global memory
//    printf("blockdim: %d\n", blockDim.x);
    if(blockDim.x>=1024 && tid <512)
        idata[tid]+=idata[tid+512];
    __syncthreads();

//    printf("blockdim: %d\n", blockDim.x);
    if(blockDim.x>=512 && tid <256)
        idata[tid]+=idata[tid+256];
    __syncthreads();

    if(blockDim.x>=256 && tid <128)
        idata[tid]+=idata[tid+128];
    __syncthreads();

    if(blockDim.x>=128 && tid <64)
        idata[tid]+=idata[tid+64];
    __syncthreads();

    //write result for this block to global mem
    if(tid<32)
    {
        volatile int *vmem = idata;
        vmem[tid]+=vmem[tid+32];
        vmem[tid]+=vmem[tid+16];
        vmem[tid]+=vmem[tid+8];
        vmem[tid]+=vmem[tid+4];
        vmem[tid]+=vmem[tid+2];
        vmem[tid]+=vmem[tid+1];

    }

    if (tid == 0)
        g_odata[blockIdx.x] = idata[0];

}




int main(int argc, char **argv){
    int dev = 0;
    cudaDeviceProp deviceProp;
    cudaGetDeviceProperties(&deviceProp, dev);
    printf("%s using Device %d: %s\n", argv[0], dev, deviceProp.name);

    //set up data size
    int size = 1 << 24;
    printf("Data size %d ", size);
    int blocksize = 1024;
    if (argc > 1)
    {
        blocksize = atoi(argv[1]);
    }


    //set up execution configuration
    dim3 block(blocksize,1);
    dim3 grid((size - 1) / block.x + 1,1);
    printf("Execution Configure (block %d grid %d)\n", block.x, grid.x);

    //allocate host memory
    size_t nBytes = size * sizeof(int);
    int * idata_host=(int*)malloc(nBytes);
    int *odata_host = (int*) malloc(grid.x * sizeof(int));
    int * tmp = (int*)malloc(nBytes);

    //initialize the array
    initialData_int(idata_host, size);
    memcpy(tmp, idata_host, nBytes);

//    cudaMalloc((float**)&C_dev, nBytes);
    double iStart, iElaps;
    int gpu_sum = 0;


    // device memory
    int * idata_dev = nullptr;
    int * odata_dev = nullptr;
    CHECK(cudaMalloc((void**)&idata_dev, nBytes));
    CHECK(cudaMalloc((void**)&odata_dev, grid.x * sizeof(int)));


    //cpu reduction
    int cpu_sum = 0;
    iStart = cpuSecond();
    //cpu_sum = recursiveReduce(tmp, size);
    for (int i = 0; i < size; i++)
        cpu_sum += tmp[i];
    printf("cpu sum:%d \n", cpu_sum);
    iElaps = cpuSecond() - iStart;
    printf("cpu reduce                 elapsed %lf ms cpu_sum: %d\n", iElaps, cpu_sum);


    //cpu reduction1
    iStart = cpuSecond();
    //cpu_sum = recursiveReduce(tmp, size);
    cpu_sum = recursiveReduce(tmp, size);
    printf("cpu sum:%d \n", cpu_sum);
    iElaps = cpuSecond() - iStart;
    printf("cpu recursiveReduce        elapsed %lf ms cpu_sum: %d\n", iElaps, cpu_sum);

    // warmup
    CHECK(cudaMemcpy(idata_dev, idata_host, nBytes, cudaMemcpyHostToDevice));
    CHECK(cudaDeviceSynchronize());
    iStart = cpuSecond();
    warmup <<<grid, block >>>(idata_dev, odata_dev, size);
    cudaDeviceSynchronize();
    iElaps = cpuSecond() - iStart;
    cudaMemcpy(odata_host, odata_dev, grid.x * sizeof(int), cudaMemcpyDeviceToHost);
    gpu_sum = 0;
    for (int i = 0; i < grid.x; i++)
        gpu_sum += odata_host[i];
    printf("gpu warmup                 elapsed %lf ms gpu_sum: %d<<<grid %d block %d>>>\n", iElaps, gpu_sum, grid.x, block.x);

    //kernel 1:reduceNeighbored

    CHECK(cudaMemcpy(idata_dev, idata_host, nBytes, cudaMemcpyHostToDevice));
    CHECK(cudaDeviceSynchronize());
    iStart = cpuSecond();
    reduceNeighbored <<<grid, block >>>(idata_dev, odata_dev, size);
    cudaDeviceSynchronize();
    iElaps = cpuSecond() - iStart;
    cudaMemcpy(odata_host, odata_dev, grid.x * sizeof(int), cudaMemcpyDeviceToHost);
    gpu_sum = 0;
    for (int i = 0; i < grid.x; i++)
        gpu_sum += odata_host[i];
    printf("gpu reduceNeighbored       elapsed %lf ms gpu_sum: %d<<<grid %d block %d>>>\n", iElaps, gpu_sum, grid.x, block.x);

    //kernel 2:reduceNeighboredLess

    CHECK(cudaMemcpy(idata_dev, idata_host, nBytes, cudaMemcpyHostToDevice));
    CHECK(cudaDeviceSynchronize());
    iStart = cpuSecond();
    reduceNeighboredLess <<<grid, block>>>(idata_dev, odata_dev, size);
    cudaDeviceSynchronize();
    iElaps = cpuSecond() - iStart;
    cudaMemcpy(odata_host, odata_dev, grid.x * sizeof(int), cudaMemcpyDeviceToHost);
    gpu_sum = 0;
    for (int i = 0; i < grid.x; i++)
        gpu_sum += odata_host[i];
    printf("gpu reduceNeighboredLess   elapsed %lf ms gpu_sum: %d<<<grid %d block %d>>>\n", iElaps, gpu_sum, grid.x, block.x);

    //kernel 3:reduceInterleaved
    CHECK(cudaMemcpy(idata_dev, idata_host, nBytes, cudaMemcpyHostToDevice));
    CHECK(cudaDeviceSynchronize());
    iStart = cpuSecond();
    reduceInterleaved << <grid, block >> >(idata_dev, odata_dev, size);
    cudaDeviceSynchronize();
    iElaps = cpuSecond() - iStart;
    cudaMemcpy(odata_host, odata_dev, grid.x * sizeof(int), cudaMemcpyDeviceToHost);
    gpu_sum = 0;
    for (int i = 0; i < grid.x; i++)
        gpu_sum += odata_host[i];
    printf("gpu reduceInterleaved      elapsed %lf ms gpu_sum: %d<<<grid %d block %d>>>\n", iElaps, gpu_sum, grid.x, block.x);



    //kernel 4:reduceUnrolling2
    CHECK(cudaMemcpy(idata_dev, idata_host, nBytes, cudaMemcpyHostToDevice));
    CHECK(cudaDeviceSynchronize());
    iStart = cpuSecond();
    reduceUnroll2 <<<grid.x/2, block >>>(idata_dev, odata_dev, size);       // 由于合并了一半的线程块，这里的网格个数都要对应的减少一半
    cudaDeviceSynchronize();
    iElaps = cpuSecond() - iStart;
    cudaMemcpy(odata_host, odata_dev, grid.x * sizeof(int), cudaMemcpyDeviceToHost);
    gpu_sum = 0;
    for (int i = 0; i < grid.x/2; i++)
        gpu_sum += odata_host[i];
    printf("gpu reduceUnrolling2       elapsed %lf ms gpu_sum: %d<<<grid %d block %d>>>\n", iElaps, gpu_sum, grid.x/2, block.x);


    //kernel 5:reduceUnrolling4
    CHECK(cudaMemcpy(idata_dev, idata_host, nBytes, cudaMemcpyHostToDevice));
    CHECK(cudaDeviceSynchronize());
    iStart = cpuSecond();
    reduceUnroll4 <<<grid.x/4, block >>>(idata_dev, odata_dev, size);       // 由于每次合并4个线程块，这里的网格个数都要对应的要变为1、4
    cudaDeviceSynchronize();
    iElaps = cpuSecond() - iStart;
    cudaMemcpy(odata_host, odata_dev, grid.x * sizeof(int), cudaMemcpyDeviceToHost);
    gpu_sum = 0;
    for (int i = 0; i < grid.x/4; i++)
        gpu_sum += odata_host[i];
    printf("gpu reduceUnrolling4       elapsed %lf ms gpu_sum: %d<<<grid %d block %d>>>\n", iElaps, gpu_sum, grid.x/4, block.x);


    //kernel 5:reduceUnrolling8
    CHECK(cudaMemcpy(idata_dev, idata_host, nBytes, cudaMemcpyHostToDevice));
    CHECK(cudaDeviceSynchronize());
    iStart = cpuSecond();
    reduceUnroll8 <<<grid.x/8, block >>>(idata_dev, odata_dev, size);       // 由于每次合并8个线程块，这里的网格个数都要对应的要变为1/8
    cudaDeviceSynchronize();
    iElaps = cpuSecond() - iStart;
    cudaMemcpy(odata_host, odata_dev, grid.x * sizeof(int), cudaMemcpyDeviceToHost);
    gpu_sum = 0;
    for (int i = 0; i < grid.x/8; i++)
        gpu_sum += odata_host[i];
    printf("gpu reduceUnrolling8       elapsed %lf ms gpu_sum: %d<<<grid %d block %d>>>\n", iElaps, gpu_sum, grid.x/8, block.x);


    //kernel 6:reduceUnrollingWarp8
    CHECK(cudaMemcpy(idata_dev, idata_host, nBytes, cudaMemcpyHostToDevice));
    CHECK(cudaDeviceSynchronize());
    iStart = cpuSecond();
    reduceUnrollWarp8 <<<grid.x/8, block >>>(idata_dev, odata_dev, size);       // 由于每次合并8个线程块，这里的网格个数都要对应的要变为1/8
    cudaDeviceSynchronize();
    iElaps = cpuSecond() - iStart;
    cudaMemcpy(odata_host, odata_dev, grid.x * sizeof(int), cudaMemcpyDeviceToHost);
    gpu_sum = 0;
    for (int i = 0; i < grid.x/8; i++)
        gpu_sum += odata_host[i];
    printf("gpu reduceUnrollingWarp8   elapsed %lf ms gpu_sum: %d<<<grid %d block %d>>>\n", iElaps, gpu_sum, grid.x/8, block.x);


    //kernel 7:reduceCompleteUnrollWarp8
    CHECK(cudaMemcpy(idata_dev, idata_host, nBytes, cudaMemcpyHostToDevice));
    CHECK(cudaDeviceSynchronize());
    iStart = cpuSecond();
    reduceCompleteUnrollWarp8 <<<grid.x/8, block >>>(idata_dev, odata_dev, size);       // 由于每次合并8个线程块，这里的网格个数都要对应的要变为1/8
    cudaDeviceSynchronize();
    iElaps = cpuSecond() - iStart;
    cudaMemcpy(odata_host, odata_dev, grid.x * sizeof(int), cudaMemcpyDeviceToHost);
    gpu_sum = 0;
    for (int i = 0; i < grid.x/8; i++)
        gpu_sum += odata_host[i];
    printf("gpu reducCompleteUnrollingWarp8        elapsed %lf ms gpu_sum: %d<<<grid %d block %d>>>\n", iElaps, gpu_sum, grid.x/8, block.x);


    free(idata_host);
    free(odata_host);
    CHECK(cudaFree(idata_dev));
    CHECK(cudaFree(odata_dev));

    //reset device
    cudaDeviceReset();

    //check the results
    if (gpu_sum == cpu_sum)
    {
        printf("Test success!\n");
    }
    return EXIT_SUCCESS;

}