//
// Created by zjlab on 9/26/23.
//

#include <stdio.h>

/*
 * 使用 nvcc 的 --fmad 指令对编译进行优化
 *
 * */


__global__ void foo(float *ptr){

    *ptr = (*ptr) * (*ptr) + (*ptr);

}