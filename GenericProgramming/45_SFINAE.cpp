//
// Created by Administrator on 2023/1/17.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 * SFINAE(Substitution failure is not an error) - 替换失败不是错误
 *
 * 此处只针对函数（类）模板而言
 *
 * 当用一个具体的类型去替换函数模板中的类型参数时，编译器认为该类型无法匹配模板时，会掠过此处，寻找更合适的函数，若没找到会报note，继而报错
 *
 * */


template<class T>
typename T::size_type func1(T a)
{

    return 123;
}

//template<class T>
//int func1(T a)
//{
//
//    return 456;
//}


void demo1()
{
//    cout << func1(1) << endl;
    cout << func1(vector<int>{1}) << endl;

    vector<string> x = {"123","a", "b", "c"};

    vector<int>::size_type a = x.size();
    cout << a << endl;
}


int main()
{
    demo1();
    return 0;
}