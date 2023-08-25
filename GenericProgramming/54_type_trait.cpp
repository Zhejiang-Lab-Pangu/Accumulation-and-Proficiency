#include<iostream>
using namespace std;
#include <cxxabi.h>

/* 萃取 - 并不是某一种具体的技术或某个具体类库或函数；更像一种编程思想、模式
 *
 * 萃取 - traits(特质)
 * 萃取 - 主要用于对模板中的模板参数进行操作，这种模板一般称其为 traits 模板； 标准库中很常见
 *
 *
 * 分类：
 * 1.固定萃取 - fixed traits        给定一种类型。萃取另一种类型；这两个类型之间的对应关系是固定的；所以称为固定萃取
 * 2.值萃取 - value traits         给定一个类型，得到一个值
 * 3.类型萃取 - type traits         从boots库发展而来；实现了类型信息的提取和变换
 *
 *
 *  类型萃取 -- 就是一堆接口，官方文档称其为 type traits (https://en.cppreference.com/w/cpp/meta#Type_traits)
 *
 * */

template<class T1, class T2>
struct myIsSame{
    using type = bool;
    static const type value = false;
};


template<class T>
struct myIsSame<T, T>{
    using type = bool;
    static const type value = true;
};


void demo()
{
    int a = 123, b = 456;
    double c = 789;
    const int d = 222;

    cout << is_same<decltype(a), decltype(b)>::value << endl;
    cout << is_same<decltype(a), decltype(c)>::value << endl;

    cout << endl;
    cout << is_const<decltype(a)>::value << endl;
    cout << is_const<decltype(d)>::value << endl;

    cout << endl;
    cout << myIsSame<decltype(a), decltype(b)>::value << endl;
    cout << myIsSame<decltype(a), decltype(c)>::value << endl;
}

int main()
{
    demo();
    return 0;
}