//
// Created by zjlab on 9/26/23.
//

#include <iostream>
using namespace std;


// 内置函数  __powf
__global__ void intrinsic(float *ptr){
    *ptr = __powf(*ptr, 2.0f);
}


// 标准函数 powf
__global__ void standard(float *ptr){
    *ptr = powf(*ptr, 2.0);
}

