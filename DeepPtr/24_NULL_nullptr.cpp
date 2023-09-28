//
// Created by Administrator on 2023/9/14.
//
#include <iostream>
using namespace std;
#include <cxxabi.h>

/*
 * NULL 和 nullptr
 *
 * nullptr, NULL都是空指针
 * 但是是完全不一样的数据类型，
 * */



int main(){

    int *p1 = NULL;
    int *p2 = nullptr;

    char *p3 = NULL;
    char *p4 = nullptr;

    cout << (p1 == p2) << endl;     // 1
    cout << (p3 == p4) << endl;     // 1

    // cout << (p2 == p4) << endl;     //error     数据不一致，不能运算
    // cout << (p1 == p3) <<endl;      //error     数据不一致，不能运算


    cout << abi::__cxa_demangle(typeid(nullptr).name(), 0, 0, 0) << endl;   // std::
    cout << abi::__cxa_demangle(typeid(NULL).name(), 0, 0, 0) << endl;      // long long

    cout << (0 == NULL) << endl;        // 1
    return 0;
}