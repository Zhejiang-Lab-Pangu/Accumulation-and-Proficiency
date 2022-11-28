//
// Created by Administrator on 2022/11/7.
//

#include<iostream>
using namespace std;
#include <bitset>
#include <cmath>
//#include "tmp.hpp"

#define VERSION "2.5"
#define PRINT_VERSION

void demo1()
{
    enum {
        DMA_COUNTER_BITS = 16,
        DMA_DIM_SIZE_MAX = (1 << DMA_COUNTER_BITS) - 1
    };

    cout << DMA_DIM_SIZE_MAX << endl;


    // << 二进制左移运算符。将一个运算对象的各二进制位全部左移若干位（左边的二进制位丢弃，右边补0）。
    // 即 1 变为 10000000000000000
    int rs = (1 << 16) -1;
    cout << rs << endl;

    // 十进制转2进制
    bitset<10> bit(6553);
    cout << bit << endl;

    // >> 二进制右移运算符。将一个数的各二进制位全部右移若干位，正数左补0，负数左补1，右边丢弃。
    int rs1 = (65536 >> 16);
    cout << rs1 << endl;

    cout << pow(2, 16) << endl;
}

int main()
{
    demo1();
    return 0;
}