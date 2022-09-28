//
// Created by Administrator on 2022/9/26.
//

#include <iostream>
using namespace std;


/* 成员函数模板
 * */

template<class T1>
class Cp1
{
public:
    Cp1()=default;

    // 成员函数模板
    template<class T2>
    void func2(T2 id)
    {
        cout << "func2 -- id "  << id << endl;
    }

    // 成员函数模板 -- 类外实现
    template<class T3>
    void func_3(T3 name);

    // 虚函数不能用类型参数模板，但可以用类的模板

};

template<class T1>
template<class T3>
void Cp1<T1>::func_3(T3 name)
{
    cout << "func3 -- name " << name << endl;
}


void demo1()
{
    Cp1<int> c1;
    c1.func2(123);
    c1.func_3("sun");
}



/* 拷贝构造函数模板
 * */
class CE
{
public:
    CE()
    {cout << "构造" << endl;}
    CE(const CE & c)
    {
        cout << "拷贝构造" << endl;
    }
    CE & operator=(const CE &c)
    {
        cout << "这是拷贝赋值运算符重载" << endl;
        return *this;
    }
};


template<class T1>
class CE2
{
public:
    CE2()
    {cout << "构造" << endl;}

    template<class T2>
    CE2(const CE2<T2> & c)
    {
        cout << "拷贝构造" << endl;
    }

    template<class T3>
    CE2<T1> & operator=(const CE2<T3> &c)
    {
        cout << "这是拷贝赋值运算符重载" << endl;
        return *this;
    }

    int id;
};

void demo2()
{
    CE c1;
    CE c2(c1);
    CE c3;
    c3 = c1;
    cout << endl;

    CE2<int> ce1;
    ce1.id = 123;

    CE2<int> ce2(ce1);      // 没调用拷贝构造模板，调用默认拷贝构造（按值拷贝）
    cout << ce2.id << endl;

    CE2<double> ce3(ce1);
    cout << ce3.id << endl;

    CE2<int> ce4 = ce1;     // 没调用运算符重载模板，调用默认默认重载构造（按值拷贝）
    CE2<float> ce5;
    ce5 = ce1;
}


int main()
{
//    demo1();
    demo2();
    return 0;
}