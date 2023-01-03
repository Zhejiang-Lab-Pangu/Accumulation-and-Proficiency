//
// Created by Administrator on 2022/12/15.
//

#include <iostream>
using namespace std;


/*
 * 完美转发
 *
 * */


void func2(int &a, int && b)
{
    cout << a << "\t" << b << endl;
}


template<class T1, class T2>
void func1(T1 && a, T2 && b)
{
    // 转发： 通过中间函数间接调用目标函数，若目标函数有参数，则参数也要通过中间函数传递 func2相当于跳板函数
    // func2(a, b);

    // 完美转发 - 在转发的过程中，实参属性完全保留，通过跳板函数，完全传递给目标函数
    // 在万能引用中，通std::forward<>()配合实现完美转发
    func2(forward<T1>(a), forward<T2>(b));
    func2(a, forward<T2>(b));
}


void demo1()
{
    int a = 123;

    func1(a, 123);
}


void func(int & a)
{
    cout << "left" << endl;
}

void func(const int & a)
{
    cout << "const left" << endl;
}

void func(int && a)
{
    cout << "right" << endl;
}


template <class T>
void func4(T && x)
{
    func(forward<T>(x));
}


void demo2()
{
    int i = 1;
    const int j = 2;
    int & k = i;
    int && l = 3;

    const int & m = i;
    const int && n = 3;


    func4(i);  // 左值引用
    func4(123); // 右值引用
    func4(move(i)); //右值引用
    func4(int(123)); // 右值引用 -- 临时对象
    func4(j); // const左值引用

    func4(k);  // 左值引用
    func4(l);  // 左值引用
    func4(m);  // const左值引用
    func4(n);  //const 左值引用

}

int main()
{
    demo1();

    demo2();
    return 0;
}