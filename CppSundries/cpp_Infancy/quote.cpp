//
// Created by Administrator on 2022/9/13.
//

/*quote:  int &别名 = 原名
 * 引用本质：指针常量
 * */

/*std::ref和std::cref
 * 在std::bind中的参数绑定是参数拷贝，而不是引用
 * ref用于包装按引用传递的值
 * cref用于包装按const引用传递的值
 * */


#include <iostream>
using namespace std;
#include <functional>


void demo1()
{
    int a = 10;
    int & q1 = a;  //自动转换为 int * const q1 = &a; 指针常量是指针的指向不可改，说明为什么引用不可更改
    q1 = 40;   //自动转换为*q1= 40;
    cout << q1 << endl;
    cout << a << endl;
}

int add(int &a, int &b)
{
    a = 0;
    b = 0;
    return a+b;
}

int add1(int &a, const int &b)
{
    a = 0;
//    b = 0;
    return a+b;
}


void demo2()
{
    int x = 4, y=5;
    int m=4, n=5;
    auto f1 = bind(add, x, y);      // 尽管引用传递，但x、y值仍不变
    cout << f1() << endl;
    cout << "x: " << x << "  y:  " << y << endl;

    auto f2 = bind(add, ref(x), ref(y));
    cout << f2() << endl;
    cout << "x: " << x << "  y:  " << y << endl;

    auto f3 = bind(add1, ref(m), cref(n));
    cout << f3() << endl;
    cout << "n: " << n << "  m:  " << m << endl;
}


int main()
{
//    demo1();
    demo2();
    return 0;
}