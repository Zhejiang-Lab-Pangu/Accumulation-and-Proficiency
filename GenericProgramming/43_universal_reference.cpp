//
// Created by Administrator on 2022/12/15.
//

#include <iostream>
using namespace std;


/* 万能引用(universal reference)也称转发引用(forwarding reference),未定义引用
 *
 * 前提：
 *      1.发生在函数模板中；
 *      2.发生了类型推导
 *
 * 格式：
 *      template<class T>
 *      func(T && a){}
 *
 *
 *
 * template<class T>
 * func(vector<T> && a) //这是右值引用
 *
 * */


// 左值引用
void func1(int &a)
{
    cout << a << endl;
}

// 右值引用
void func2(int &&a)
{
    cout << a << endl;
}

void demo1()
{
    int a = 123;
    func1(a);
    // func2(a); // 右值引用不能绑定左值
    func2(123);
}


// 右值引用 -- 实际是万能引用 -- 能绑定左值，也能绑定右值
template<class T>
void func3(T && a)
{
    cout << a << endl;
}

void demo2()
{
    int a = 1223;
    func3(a);   // 万能引用绑定左值
    func3(1223);  //万能引用绑定右值
}


template<class T2>
class Ab
{
public:
    // 这是右值引用，因为T2不是推到的，在实例化类的时候会显示指定
    void func1(T2 && a)
    {
        cout << a << endl;
    }

    // 这是类成员函数的万能引用
    template<class T3>
    void func2(T3 && a)
    {
        cout << a << endl;
    }
};


void demo3()
{
    Ab<int> Ab1;
    // 右值引用
    Ab1.func1(999);

    // 万能引用
    int a = 912;
    Ab1.func2(22);
    Ab1.func2(a);

}

// 加const之后，万能引用变回右值引用
template<class T4>
void func4(const T4 && a)
{
    cout << a << endl;
}

void demo4()
{
    int a=100;
    func4(100);

    // func4(a); // 右值引用不能绑定左值
}



void demo5()
{
    // auto && x   也是万能引用
    auto && x = 120;
    auto && y = x;

    cout << x << endl;
    cout << y << endl;
}

int main()
{
    demo1();

    demo2();

    demo3();

    demo4();

    demo5();
    return 0;
}