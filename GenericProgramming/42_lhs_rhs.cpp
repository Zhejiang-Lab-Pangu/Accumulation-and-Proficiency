//
// Created by Administrator on 2022/11/10.
//

#include <iostream>
using namespace std;
#include <string>



void demo1()
{
    int a;
    a = 123;
    // 先定义int类型变量（给变量分配了一个内存空间）；再赋值（把数据存放到内存中去）；

    int b = 456;

    // (1)从字面上说，左值就是放在赋值运算的左边，右值就是放在赋值运算的右边；如上（a，b是左值； 123，456是右值）

    a = a+1;        // a(这里用的是内存空间 左值) = a(这里用的是值123 还是左值，当成右值使用) + 1
    b = b+2;
    int c = a+b;    //c(取内存地址 左值) = a(取值124 左值当右值使用) + b(取值458 左值当右值使用)


    // (2)左值一般代表一个内存地址，右值一般用具体数据
    // (3)左值在某些场景下可以当右值使用，此时具有右值属性；但右值不可当左值使用
    // (4)在分析一个表达是或变量是左值还是右值时，先看是不是左值，不是左值就是右值
    //
}





/*
 * 左值引用 - 绑定左值
 * const 左值引用，  可以绑定右值
 *
 * 右值引用 - 绑定右值 - c++11 引入
 *
 *
 * 引用类型在定义时就要求初始化，且不能用null赋值
 * */



/*
 *
 * 返回左值的运算一般有：
 * ① 赋值=； ② 取特定索引[]; ③ 解引用&； ④ 前置自增++i;
 * 可将一个左值引用绑定在这些运算的返回值上
 *
 *
 * 返回非引用类型的运算一般有：
 * ① 算数+-*除;② 关系、位，后置自增i++;
 * 这些返回的都是右值，可用右值引用或const 左值引用绑定
 *
 *
 * 不论左值引用还是右值引用，其本身也是左值，还是可以被左值引用绑定
 *
 * 所有的变量，都要看成左值，都可以被左值引用绑定（虽然有时可以当成右值使用）
 *
 * 函数里面的参数都要看成左值
 *
 * */


// 左值引用  -->> 绑定左值
void demo2()
{
    int a = 123;
    int & b = a;
    b = 456;
    cout << a << "--" << b << endl;

    const int & c = a;
    // c = 789;  常量引用，不可改其值

    const int & d = 123;
    // 常量引用可绑定右值
    cout << d << endl;

    const string & s = "shakaj";        // 临时对象是右值
    cout << s << endl;

    // int & e = a + 1; // a+123(右值，无法用左值引用绑定)
    const int & e = a+1;
}


// 右值引用 &&
void demo3()
{
    int a = 123;
    //int && b = a;   // 右值引用不能绑定左值

    int && c = 123;
    c = 456;
    cout << c << endl;

    string && d = string{"sunhongjiang"};          // 临时对象是右值
    d = "li";
    cout << d << endl;


    const int && e = 123;
    // e = 456;         // 不能修改

    const string && f = string{"sunhongjiang"};

    int && g = a+1;
    cout << g << endl;

    const int && h = a+2;
    cout << h << endl;
    cout << endl << endl;
}


// 运算返回左值还是右值
void demo4()
{
    int i= 123;

    // ++i 左值
    int & b = ++i;  // 先++, 再返回； i = i+1; int & b = i;

    // 左值可被赋值
    ++i = 456;
    printf("%d - %d -- %p - %p\n", i, b, &i, &b);


    // i++ 右值
    int && c = i++;     // int tmp = i; int && c = tmp; i = i+1;    tmp（临时变量）有新的内存地址
    printf("%d - %d -- %p - %p\n", i, c, &i, &c);
}



void demo5()
{
    int a = 123;
    int & b = a;    // 左值引用 变量b本身也是左值
    int & c = b;

    cout << a << "\t" << &a << "\t" << b << "\t" << &b << "\t" << c << "\t" << &c << endl;

    int && e = 456;     // 右值引用 变量e是右值
    int & f = e;

    cout << e << "\t" << &e << "\t" << f << "\t" << &f << endl;
}


void func0(int a, int & b, int && c)
{
    cout << endl;
}

void demo6()
{
    int x = 123;
    func0(x, x, 123);
}


// 左值转右值    c++11引入
// std::move()  左值转右值，没有移动的意思
void demo7()
{
    int a =123;
    int & b = a;

    int && c = std::move(a);

    printf("%d - %d - %d --- %p - %p - %p\n", a, b, c, &a, &b, &c);

    c = 456;
    printf("%d - %d - %d --- %p - %p - %p\n", a, b, c, &a, &b, &c);

    int d =a;
    int e = std::move(a);
    printf("%d - %d - %d --- %p - %p - %p\n", a, d, e, &a, &d, &e);

    string f = "sunhongjiang";
    string g = f;
    string h = std::move(f);        // move之后，h中的数据不见了，不是移走了； 而是触发了string里面的移动构造，然后f中的值没有了
    printf("%s - %s - %s --- %p - %p - %p\n", f.c_str(), g.c_str(), h.c_str(), &f, &g, &h);

}

int main()
{
    demo1();
    demo2();
    demo3();
    demo4();
    demo5();
    demo6();
    demo7();
    return 0;
}