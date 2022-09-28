//
// Created by Administrator on 2022/9/23.
//

/* 1. 函数模板和普通函数的重载：当同时满足调用规则，优先调用普通函数；若想调用函数模板，可显示指定类型
 *
 * 2. 函数模板与函数模板的重载
 *
 * */

#include<iostream>
using namespace std;

int func0(int a, int b)
{
    cout << "普通函数" << endl;
    return a+b;
}

template<typename T>
T func0(T a, T b)
{
    cout << "函数模板" << endl;
    return a+b;
}

template<typename T>
void func1(T a, T b)
{
    cout << "函数模板func1" << endl;

}

template<typename T>
void func1(T *a, T *b)
{
    cout << "函数模板func1 *" << endl;

}

template<typename T>
void func1(T *a)
{
    cout << "函数模板func1 * 一个参数" << endl;

}


template<typename T1, typename T2>
void func2(T1 *a, T2 b)
{
    cout << "T1: " << *a << "\tT2: " << *b << endl;
    cout << "函数模板func2 * 先T1, 后T2" << endl;
}

template<typename T1, typename T2>
void func2(T2 *a, T1 *b)
{
    cout << "T1: " << *b << "\tT2: " << *a << endl;
    cout << "函数模板func1 * 先T2, 后T1" << endl;
}


void demo1()
{
    int a=1, b=2;
    char c='a', d='b';

    func0(a, b);
    func0(c, d);
}

void demo2()
{
    int a=1, b=2;
    char c='a', d='b';

    func1(a, b);
    func1(&a, &b);
    func1(&c);
}

void demo3()
{
    int a=1, b=2;
    char c='a', d='b';

    func2(&a, &c);      // 调用func2(T1 *a, T2 b)， T2 是char *
    func2(&a, &b);
}

int main()
{
//    demo1();
//    demo2();
    demo3();
    return 0;
}
