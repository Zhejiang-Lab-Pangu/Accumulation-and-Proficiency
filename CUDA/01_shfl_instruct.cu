//
// Created by root on 10/18/23.
//


#include <iostream>
using namespace std;


__global__ void bcast(int arg){
    int laneId = threadIdx.x & 0x1f;        // 与16进制的数等价于求余
//    printf("%d\n", laneId);

    int value = 0;
    if(laneId == 0){
        value = arg;
    }

    printf("threadidx(%d) -- value(%d)\n", threadIdx.x, value);

    __syncthreads();

    value = __shfl_sync(0xffffffff, value, 0, 32);
    if(value != arg){
        printf("thread %d failed\n", threadIdx.x);
    }
    printf("threadidx(%d) -- value(%d)\n", threadIdx.x, value);

}


__global__ void scan4(){

    int laneId = threadIdx.x % 32;
    int value = 31 - laneId;

    printf("threadidx(%d) -- value(%d)\n", threadIdx.x, value);

    __syncthreads();

    value = __shfl_up_sync(0xfffffff, value, 2, 32);
    printf("threadidx(%d) -- value(%d)\n", threadIdx.x, value);

}

__global__ void reduce(){
    int laneId = threadIdx.x & 0x1f;
    int value = 31 -laneId;

    printf("threadidx(%d) -- value(%d)\n", threadIdx.x, value);
    __syncthreads();

    value = __shfl_xor_sync(0xffffffff, value, 1, 32);
    printf("threadidx(%d) -- value(%d)\n", threadIdx.x, value);
}

int main(){

//    bcast<<<2, 32>>>(1234);
//    scan4<<<1, 32>>>();
    reduce<<<1, 32>>>();
    cudaDeviceReset();

    return 0;
}