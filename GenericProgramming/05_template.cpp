//
// Created by Administrator on 2022/9/26.
//

/*类模板的泛化与特化*/


#include<iostream>
using namespace std;
#include <string>


template<class T1, class T2>
class C1
{
public:
    C1()
    {
        cout << "无参" << endl;
    }

    void func1()
    {
        cout << "func1" << endl;
    }

    static int flag;
};

template<class T1, class T2>
int C1<T1, T2>::flag=123;



// 成员函数特化  -- 成员函数不支持半特化
template<>
void C1<int, int>::func1()
{
    cout << "func1的全特化" << endl;
}

// 成员变量特化
template<>
int C1<double, double>::flag=456;

void demo1()
{
    C1<int, float> c1;
    c1.func1();

    C1<int, int> c2;
    c2.func1();

    cout << C1<int, int>::flag << endl;
    cout << C1<double, double>::flag << endl;
}

// 类的特化
template<>
class C1<int, string>
{
public:
    C1()
    {
        cout << "特化==无参" << endl;
    }

    void func1()
    {
        cout << "特化==func1" << endl;
    }
};

template<class T>
class C1<T, string>
{
public:
    C1()
    {
        cout << "半特化==无参" << endl;
    }

    void func1()
    {
        cout << "半特化==func1" << endl;
    }
};


void demo2()
{
    C1<int, double> c1;
    c1.func1();

    C1<int, string> c2;
    c2.func1();

    C1<double, string> c3;
    c3.func1();
}

int main()
{
//    demo1();
    demo2();
    return 0;
}