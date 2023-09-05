//
// Created by Administrator on 2023/9/1.
//

#include <iostream>
using namespace std;




/*
 * const ptr
 *
 * 1.常量指针 const T * ptr;(修饰的是*)    可修改其指向，不能修改其指向空间的值
 *
 * 2.指针常量 T * const ptr;(修饰的是指针变量)        可修改指向空间的值，不可修改指向
 *
 * */



void demo1(){

    int a = 123, b = 456;
    const int *p0 = &a;
    // *p0 = 456;      // 不可修改指向空间的值

    p0 = &b;        // 可修改指针的指向
    cout << *p0 << endl;

    int * const p1 = &a;
    *p1 = b;        // 可修改指向空间的值
    cout << a << endl;
    //p1 = &b;        // 不可修改指针的指向

    const int * const p2 = &a;  // 既不可修改指向，亦修改不了内容

}


int main(){

    demo1();
    return 0;
}