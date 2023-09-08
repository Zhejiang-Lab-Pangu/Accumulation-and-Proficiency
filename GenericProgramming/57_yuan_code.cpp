//
// Created by Administrator on 2023/8/25.
//
#include <iostream>
using namespace std;

// 阶乘
template<int a>
constexpr int func1(){
    return a * func1<a-1>();
}

template<>
constexpr int func1<0>(){
    return 1;
}


// 连续自然数求和  - 函数模板 - 递归拆包
template<int ...a>
constexpr int func2=0;

template<int first, int ...a>
constexpr int func2<first, a...> = first+func2<a...>;

int main()
{
    constexpr int a = func1<10>();
    cout << a << endl;

    constexpr int b = func2<1, 2, 3, 4, 5>;
    cout << b << endl;

    static_assert(b == 15, " b error");     // 静态断言，编译期进行判断
    return 0;
}