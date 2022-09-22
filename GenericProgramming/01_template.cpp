//
// Created by Administrator on 2022/9/22.
//

#include <iostream>
using namespace std;


/*
 * demo: 函数模板定义、调用、参数推导
 *
 * demo1: 函数模板的实现原理
 *
 * 
 * */



template<typename T>
T func(T x, T y)
{
    cout << x+y << endl;
    return x+y;
}

template<typename T>
void func1()
{
    cout << "no parameters" << endl;
}

template<typename T>
void funckkkk()
{
    cout << "no use" << endl;
}

void demo()
{
    int a=1, b=2;
    double c=1.1, d=2.2;

//    func(a, c);   // 模板无法进行隐式类型推到
    func<int>(a, c);    // 显示指定会强行转换

    func1<int>();   // 没参数要显示指定
}


/*
 * objdump -DC .\a.exe > c.txt      #将二进制文件以可读的方式导出（反编译）
 *
 * 实例化（调用的时候）而且同种类型的只实例化一次（一个地址）
 * int func<int>(int, int)
 * double func<double>(double, double)
 *
 *
 * 如果函数定义完了，但没有调用，编译器会优化掉；同理，如果一个参数没有被使用，也会被编译器优化
 *
 * */
void demo1()
{
    int a=1, b=2;
    double c=1.1, d=2.2;

    cout << func(a, b) << endl;         // 402e10 <int func<int>(int, int)>
    cout << func(c, d) << endl;        // 402db0 <double func<double>(double, double)>
}

int main() {
//    demo();
    demo1();
    return 0;
}
