//
// Created by Administrator on 2022/9/28.
//

/*
 * 可变参表达式
 *
 * */

#include <iostream>
using namespace std;


template<typename ...T2>
auto func2(T2 ... y)
{

    cout << (...+y) << endl;
    return (...+y);
}


template<typename ...T1>
auto func1(T1 ...x)
{
    auto res = func2(2 * x...);    // 可变参表达式：逐项运算(乘2)再传给func2()
    return res;
}


void demo()
{
    int r;
    r = func1(1, 2, 3, 4);
    cout << r<< endl;
}

int main()
{
    demo();
    return 0;
}