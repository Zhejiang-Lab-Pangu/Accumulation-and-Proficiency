//
// Created by Administrator on 2023/2/2.
//

#include<iostream>
#include <vector>
using namespace std;

// std - conditional
/*
 * conditional<bool, T1, T2>
 * 结构体模板
 * 有些类似于3目运算
 *
 * 泛化版：
 * template<bool _Bp, class _If, class _Then>
 * struct conditional{
 *          typedef _If type;
 * }
 *
 *
 * 特化版：
 * template<class _If, class Then>
 * struct conditional<false, _If, _Then>{
 *          typedef _Then type;
 * }
 *
 *
 *
 * */

void demo1()
{
    conditional<true, int, char>::type t1;    //int
    conditional<false, int, char>::type t2;   // char

    cout << typeid(t1).name() << endl;
    cout << typeid(t2).name() << endl;

    constexpr int a = 13;
    conditional<
            (a>100),
            conditional<(a>150), int, char>::type,
            conditional<(a>50), bool, double>::type
            >::type t3;

    cout << typeid(t3).name() << endl;
}

int main()
{
    demo1();
    return 0;
}