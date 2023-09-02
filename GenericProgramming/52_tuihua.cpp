//
// Created by Administrator on 2023/8/17.
//
//
// Created by Administrator on 2022/11/10.
//

#include <iostream>
using namespace std;
#include <string>
#include <cxxabi.h>

/*
 * 退化
 * std::decay<T>  去掉T的各种修饰：
 * 1.丢弃const、左右引用修饰符
 * 2.数组转指针(const不丢弃)
 * 3.函数名转函数指针
 * */

void demo1()
{
    int a = 123;
    const int b = 456;

    int &c = a;
    int &&d = 789;

    const int &e = 321;
    const int &&f = 765;

    std::decay<decltype(b)>::type t1;

    // is_same<T1, T2>  判断T1、T2是否为同一类型
    cout << std::is_same<int, const int>::value << endl;
    cout << std::is_same<int, std::decay<const int>::type >::value << endl;
    cout << std::is_same<int, std::decay<const int &>::type >::value << endl;
    cout << std::is_same<int, std::decay<const int &&>::type >::value << endl;

    cout << endl;

    // 数组转指针
    int g[4]{};
    const int h[4]{};
    cout << abi::__cxa_demangle(typeid(decltype(g)).name(), 0, 0, 0) << endl;
    cout << abi::__cxa_demangle(typeid(decay<decltype(g)>::type).name(), 0, 0, 0) << endl;
    cout << abi::__cxa_demangle(typeid(decay<decltype(h)>::type).name(), 0, 0, 0) << endl;
}


void func1(){};

/*萃取实现退化*/

// 去const
template<class T1>
struct clearConst{
    using type = T1;
};
template<class T1>
struct clearConst<const T1>{
    using type = T1;
};


// 去引用
template<class T1>
struct clearRefernce{
    using type = T1;
};
template<class T1>
struct clearRefernce<T1&>{
    using type = T1;
};
template<class T1>
struct clearRefernce<T1&&>{
    using type = T1;
};

template<class T>
struct myDecay: clearRefernce<clearConst<T>>::type {

};

// 数组转指针
template<class T>
struct myDecay<T[]>{
    using type = T*;
};
template<class T, size_t size>
struct myDecay<T[size]>{
    using type = T*;
};

// 函数转指针
template<class T, class ...args>
struct myDecay<T(args...)>{
    using type = T(*)(args...);
};

void demo2()
{
    int a = 123;
    const int b = 456;

    int &c = a;
    int &&d = 789;

    const int &e = 321;
    const int &&f = 765;

    // 去const
    cout << std::is_same<decltype(a), clearConst<decltype(b)>::type>::value << endl;

    // 去引用
    cout << std::is_same<decltype(a), clearRefernce<decltype(c)>::type>::value << endl;
    cout << std::is_same<decltype(a), clearRefernce<decltype(d)>::type>::value << endl;

    // 先去引用，再去const
    cout << std::is_same<decltype(a), clearConst<clearRefernce<decltype(e)>::type>::type >::value << endl;
    cout << std::is_same<decltype(a), clearConst<clearRefernce<decltype(f)>::type>::type >::value << endl;

    // 数组转指针
    int g[4]{};
    const int h[]{};
    cout << abi::__cxa_demangle(typeid(myDecay<decltype(g)>::type).name(), 0, 0, 0) << endl;
    cout << abi::__cxa_demangle(typeid(myDecay<decltype(h)>::type).name(), 0, 0, 0) << endl;


    // 函数转指针

    cout << abi::__cxa_demangle(typeid(decltype(func1)).name(), 0, 0, 0) << endl;
    cout << abi::__cxa_demangle(typeid(decay<decltype(func1)>::type).name(), 0, 0, 0) << endl;
    cout << abi::__cxa_demangle(typeid(myDecay<decltype(func1)>::type).name(), 0, 0, 0) << endl;

}




int main()
{
    demo1();
    cout << endl;
    demo2();

    return 0;
}