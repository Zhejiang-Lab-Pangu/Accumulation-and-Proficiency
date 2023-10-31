//
// Created by root on 10/23/23.
//



#include <iostream>
#include "soTest.h"


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

    Test t1;
    t1.func1();
    t1.func2();
    t1.func3();

    return 0;
}

