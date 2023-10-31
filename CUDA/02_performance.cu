
//
#include <iostream>
using namespace std;
#include <mma.h>
#include <stdio.h>
#include <cuda_runtime.h>
//using namespace nvcuda;
#include <sys/time.h>


/*
 *
 * cpu计时
 *
 * 核函数计时：
 *      nvprof [nvprof_args] <application>[application_args]
 *
 * */

#define CHECK(call)\
{\
  const cudaError_t error=call;\
  if(error!=cudaSuccess)\
  {\
      printf("ERROR: %s:%d,",__FILE__,__LINE__);\
      printf("code:%d,reason:%s\n",error,cudaGetErrorString(error));\
      exit(1);\
  }\
}

void initialData(float* ip,int size)
{
    time_t t;       // ime_t 这种类型就是用来存储从1970年到现在经过了多少秒
    srand((unsigned )time(&t));
    for(int i=0;i<size;i++)
    {
        ip[i]=(float)(rand()&0xffff)/1000.0f;   // 0xffff 2^16-1
    }
}

double cpuSecond(){
    timeval tp;
    gettimeofday(&tp, nullptr);     // 初始化tp：即返回现在距1970的时间

    return ((double)tp.tv_sec + (double)tp.tv_usec * 1e-6);
}


//void sumArrays(float * a,float * b,float * res,const int size)
//{
//    for(int i=0;i<size;i+=4)
//    {
//        res[i]=a[i]+b[i];
//        res[i+1]=a[i+1]+b[i+1];
//        res[i+2]=a[i+2]+b[i+2];
//        res[i+3]=a[i+3]+b[i+3];
//    }
//}

//void printRslt(float*p, int size){
//    for(int i=0; i<size; i++){
//        cout << p[i] << "  ";
//    }
//    cout << endl;
//}

// 线程如何组织：threadIdx(dim3) 和 blockIdx (dim3)
__global__ void sumArraysGPU(float * a,float * b,float * res){
    int idx = threadIdx.x + blockIdx.x * gridDim.x;
    res[idx] = a[idx] + b[idx];
}


void demo0(){
    int dev = 0;
    cudaSetDevice(dev);

    int nElem= (1 << 16) + 1 ;
    printf("Vector size:%d\n",nElem);
    int nByte=sizeof(float) * nElem;
    float *a_h=(float*)malloc(nByte);
    float *b_h=(float*)malloc(nByte);
    float *res_h=(float*)malloc(nByte);
    float *res_from_gpu_h=(float*)malloc(nByte);
    memset(res_h,0,nByte);
    memset(res_from_gpu_h,0,nByte);

    float *a_d, *b_d, *res_d;
    CHECK(cudaMalloc((void **)&a_d, nByte));
    CHECK(cudaMalloc((void **)&b_d, nByte));
    CHECK(cudaMalloc((void **)&res_d, nByte));

    initialData(a_h,nElem);
    initialData(b_h,nElem);

    CHECK(cudaMemcpy(a_d,a_h,nByte,cudaMemcpyHostToDevice));
    CHECK(cudaMemcpy(b_d,b_h,nByte,cudaMemcpyHostToDevice));

    unsigned int block_size = 1024;
    dim3 block(block_size);
    dim3 grid((nElem-1)/block.x+1);
    printf("grid.x %d block.x %d\n",grid.x,block.x);

    // 时间分析
    double iStart,iElaps;
    iStart=cpuSecond();
    sumArraysGPU<<<grid, block>>>(a_d, b_d, res_d);
    cudaDeviceSynchronize();
    iElaps=cpuSecond()-iStart;
    printf("time cost: %f\n", iElaps);

    CHECK(cudaMemcpy(res_from_gpu_h,res_d,nByte,cudaMemcpyDeviceToHost));

//    sumArrays(a_h,b_h,res_h,nElem);

    cudaFree(a_d);
    cudaFree(b_d);
    cudaFree(res_d);

    free(a_h);
    free(b_h);
    free(res_h);
    free(res_from_gpu_h);
}

int main()
{
    demo0();

    return 0;
}
