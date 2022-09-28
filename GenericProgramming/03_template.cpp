//
// Created by Administrator on 2022/9/23.
//

#include <iostream>
using namespace std;
#include <cxxabi.h>


/* 1.函数模板类型参数默认值
 *
 * 2.函数模板参数默认值
 *
 * 3. 函数模板的泛化与特化
 * */



template<typename T1, typename T2=int>
void func0(T1 a, T2 b=123)
{
    cout << a << "--" << abi::__cxa_demangle(typeid(a).name(), 0, 0, 0) << "\t";
    cout << b << "--" << abi::__cxa_demangle(typeid(b).name(), 0, 0, 0) << endl;
}


void demo1()
{
    int a = 1;
    double b = 2.3;
    func0(a);
    func0(a, b);
}


//支持整形、枚举、指针
template<typename T1, int T2=123>
void func1(T1 a)
{
    cout << a << "--" << T2 << endl;
}

void demo2()
{
    int a = 1;
    double b = 2.3;

    func1(a);

    //func1<int, b>(a); // 不支持变量指定

    // 支持常量指定：因为这个值在编译的时候就需要确定，而不是在运行的时候确定
    func1<int, 456>(a);
    int const c = 789;
    func1<int, c>(a);
}


// 特化和泛化的概念是相对的，默认函数模板（没有默认值）的都是泛化
template<typename T1, typename T2>
void funcT1(T1 x, T2 y)
{
    cout << "泛化函数模板" << endl;
}

template<>
void  funcT1<int, double>(int a, double b)
{
    cout << "特化函数模板" << endl;
}


void  funcT1(int a, double b)
{
    cout << "普通函数" << endl;
}

void demo3()
{
    int u = 9;
    double v = 9.9;

    funcT1(u, v);       // 函数重载优先级：普通>特化>泛化
    funcT1<int, double>(u, v);
    funcT1(u, u);

}

int main()
{
//    demo1();
//    demo2();
    demo3();
    return 0;
}