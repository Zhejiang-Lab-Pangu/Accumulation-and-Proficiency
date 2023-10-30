//
// Created by root on 10/25/23.
//

#include "aTest.h"
#include <iostream>


void aTest::func1() {
    printf("func1\n");
}


// 编译静态库：
// g++ -c aTest.cpp -o aTest.o 先编译出二进制
// ar -r libaTest.a aTest.o  再使用ar编出静态库文件