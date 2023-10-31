//
// Created by root on 10/25/23.
//



//
// Created by root on 10/23/23.
//



#include <iostream>
#include "02_dynamic_repo/soTest.h"
#include "03_static_repo/aTest.h"


class Test : public SoTest{
public:

    void func2(){
        printf("TEST - func2\n");
    }

    void func3(){
        printf("TEST - func3\n");
    }
};



int main(){

    // 动态链接库 g++ -o main main.cpp -lsoTest -L./02_dynamic_repo
    Test t1;
    t1.func1();
    t1.func2();
    t1.func3();

    printf("\n");

    // 静态链接库
    aTest at1;
    at1.func1();

    return 0;
}

