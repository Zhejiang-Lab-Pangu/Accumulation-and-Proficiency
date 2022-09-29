//
// Created by Administrator on 2022/9/28.
//

/*
 * 可变参类模板的递归继承
 *
 * 可变参数模板的递归组合
 *
 * */

#include <iostream>
using namespace std;
#include <cxxabi.h>


// 递归继承解包
template<class ...T1>
class C1
{
public:
    C1()
    {
        printf("C1--T1\n");
    }
};

template<class T2, class ...T3>
class C1<T2, T3...>: private C1<T3...>
{
public:
    C1()
    {
        printf("C1--T2--T3 -- %s -- %d\n", abi::__cxa_demangle(typeid(T2).name(), 0,0,0), sizeof...(T3));
    }
};

/* 递归继承解包过程：
 *
 * C1<int, double, float> c1;
 *      class C1<int, double, float>: private C1<double, float>{}
 *          class C1<double, float>: private C1<float>{}
 *              class C1<float>: private C1<>{}
 *                  class C1{}
 *
 *
 * */


void demo1()
{
    C1<int, double, float> c1;
}


// 递归组合解包
template<class ...T1>
class B1
{
public:
    B1()
    {
        printf("B1--T1\n");
    }
};

template<class T2, class ...T3>
class B1<T2, T3...>
{
public:
    B1()
    {
        printf("B1--T2--T3 -- %s -- %d\n", abi::__cxa_demangle(typeid(T2).name(), 0,0,0), sizeof...(T3));
    }

    B1<T3...> b1;
};

void demo2()
{
    B1<int, double, float> b1;
}

/* 递归组合解包过程：
 *
 * C1<int, double, float> c1;
 *      class C1<int, double, float>{
 *          class C1<double, float>
 *          {
 *              class C1<float>
 *              {
 *                  class C1<>{}
 *              }
 *          }
 *      }
 *
 *
 *
 * */


int main()
{
//    demo1();
    demo2();
    return 0;
}