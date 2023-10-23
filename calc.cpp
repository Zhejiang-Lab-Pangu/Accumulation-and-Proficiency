//
// Created by root on 10/17/23.
//

#include <iostream>
#include "add.h"
#include "sub.h"
#include "multi.h"
using namespace std;



int main(){

    int a= 1, b=2;

    std::cout << "a+b=" << add(a, b) << std::endl;
    std::cout << "a-b=" << sub(a, b) << std::endl;
    std::cout << "a*b=" << multi(a, b) << std::endl;

}