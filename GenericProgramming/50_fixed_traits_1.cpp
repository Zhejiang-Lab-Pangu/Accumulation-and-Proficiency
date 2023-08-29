//
// Created by Administrator on 2023/8/16.
//
//
// Created by Administrator on 2023/8/15.
//

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
 * */


template<class T1, class T2>
T1 func0(const T2 * start, const T2 * end)
{
    T1 sum = 0;
    for(;;)
    {
        sum += *start;
        if(start == end)
        {
            break;
        }
        start++;
    }
    return sum;
}


// 固定萃取

template<class T>
struct sumType{};

template<>
struct sumType<char>{
    using type = int;
};

template<>
struct sumType<int>{
    using type = int64_t;
};

template<class T>
auto func1(const T * start, const T * end)
{
    using sumT = typename sumType<T>::type;
    sumT sum = 0;
    for(;;)
    {
        sum += *start;
        if(start == end)
        {
            break;
        }
        start++;
    }

    return sum;
}


int main()
{
    int a[] = {1, 2, 3};
    int b[] = {1000000000, 2000000000, 1500000000};
    char c[] = "abc";
    cout << func0<int>(&a[0], &a[2]) << endl;
    cout << func0<int64_t>(&b[0], &b[2]) << endl;
    cout << func0<int>(&c[0], &c[2]) << endl;

    cout<< endl;

    cout << func1(&a[0], &a[2]) << endl;
    cout << func1(&b[0], &b[2]) << endl;
    cout << func1(&c[0], &c[2]) << endl;
    return 0;
}