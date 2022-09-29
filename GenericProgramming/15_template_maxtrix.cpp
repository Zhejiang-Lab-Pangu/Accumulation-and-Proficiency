//
// Created by Administrator on 2022/9/28.
//


/*类模板的混入
 *
 * 把模板参数当作父类继承，调用传递类
 * */

#include <iostream>
using namespace std;

class A
{
public:
    int a;
};

class B
{
public:
    int b;
};


// 将传过来的类变量当作父类继承，成为混入
template<class ...T1>
class C: public T1...
{
public:
    C(){cout << "c" << endl;}
};

template<class ...T2>
class D: public C<T2...>
{

};


void demo1()
{
    C<A> c1;
    c1.a = 123;
    cout << c1.a << endl;

    C<A, B> c2;
    c2.a = 909;
    c2.b = 678;
    cout << c2.a << "---" << c2.b << endl;
}


void demo2()
{
    D<A> d;
    d.a = 123;
    cout << d.a << endl;
}
int main()
{
//    demo1();
    demo2();
    return 0;
}