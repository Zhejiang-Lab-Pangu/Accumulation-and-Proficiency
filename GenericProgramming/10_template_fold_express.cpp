//
// Created by Administrator on 2022/9/28.
//


/*
 * 可变参数模板 --- 折叠表达式
 *
 *
 * */


#include <iostream>
using namespace std;

// 递归求和
int sum = 0;

template<typename T1, typename ...T2>
void func1(T1 a, T2 ...b)
{
    sum += a;
    if constexpr(sizeof...(b) > 0)
    {
        func1(b...);
    }
    else
    {
        cout << sum << endl;
    }
}

void demo1()
{
    func1(2, 3, 4, 1);
}


/*
 * 折叠表达式：
 *
 * 一元折叠表达式 - 左折
 * (... 运算符 参数名)
 * a,b,c,d  ==>>  (((a-b)-c)-d)     从左侧开始计算
 *
 *
 * 一元折叠表达式 - 右折
 * (参数名 运算符 ...)
 * a,b,c,d  ==>>  (a-(b-(c-d)))     从右侧开始计算
 *
 *
 * 二元折叠表达式 - 左折
 * (初始值 运算符 ... 运算符 参数名)
 * default,a,b,c,d  ==>>  ((((default-a)-b)-c)-d)     从左侧开始计算，初识值在左侧
 *
 *
 * 二元折叠表达式 - 右折
 * (参数名 运算符 ... 运算符 初始值)
 * a,b,c,d,default  ==>>  a-(b-(c-(d-default)))     从右侧开始计算，初识值在右侧
 *
 * */

template<typename ...T4>
void func4(T4 ... x)
{
    cout << (... - x) << endl;  // (1, 2, 3, 4)  -->>  (((1-2)-3)-4)        -8
    cout << (x - ...) << endl;  // (1, 2, 3, 4)  -->>  (1-(2-(3-4)))        -2
    //(cout << ... << x);

}


template<typename ... T5>
void func5(T5 ...y)
{
    cout << (10 - ... - y) << endl;     // (10, 1, 2, 3, 4)  -->> ((((10-1)-2)-3)-4))       0
    cout << (y - ... - 10) << endl;     // (1, 2, 3, 4 10)  -->> (1-(2-(3-(4-10))))         8
}


void demo2()
{
    func4(1, 2, 3, 4);

    func5(1, 2, 3, 4);
}

int main()
{
//    demo1();
    demo2();
    return 0;
}