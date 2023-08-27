//
// Created by Administrator on 2023/8/25.
//
#include <iostream>
using namespace std;


/*
 * 元编程 - 模板元编程
 * 与萃取类似，是一种编程方式或思想，而不是某种具体的技术或方法，或某种具体的类库
 * 这种编程方式，能让代码在编译期间就执行并返回结果，以达到提升程序执行效率的作用 - 相当于执行前置
 *
 * 元函数
 * 用元编程思想写的函数，可在编译期被执行的函数
 * 元函数包含模板
 *
 * constexpr 关键字，标识变量或函数在编译器执行
 * */


int func1(int a, int b){
    return a+b;
}

constexpr int func2(int a, int b){
    return a+b;
}

template<class T>
constexpr T func3(T a, T b){
    return a+b;
}


int main()
{
    int a = func1(1, 2);

    constexpr int b = func2(1, 2);  // 编译期执行
    /*
     * objdump -DC .\a.exe >> 56_objdum.txt
     * 反编译后会发现没有func2，直接是一个结果
     *
     * */
    cout << a << "\t" << b << endl;

    int c = func2(1, 2);  // 不会在 编译期执行

    constexpr int d = func3(4, 5);   // 编译期执行
    cout << d <<  endl;

    return 0;
}