//
// Created by Administrator on 2022/9/16.
//

/*keyword1
 * ① decltype
 * ② #define
 * ③ explict
 * */


#include <iostream>
using namespace std;
#include <typeinfo>
#include <string>

// 1. decltype -->> 选择并返回操作数的数据类型
/*decltype推导四规则：
 * ①e是一个没有带括号的标记符表达式或者类成员访问表达式，那么的decltype（e）就是e所命名的实体的类型；被重载的函数，decltype（e）会导致编译错误
 * ②假设e的类型是T，如果e是一个将亡值，那么decltype（e）为T&&
 * ③e的类型是T，如果e是一个左值，那么decltype（e）为T&
 * ④e的类型是T，则decltype（e）为T
 * */

int func0()
{
    int k = 100;
    return k;
}
void demo0()
{
    int i = 1;
    decltype(i) i_t;    // int

    decltype(func0()) i_t1;     // 将亡值。推导为类型的右值引用
    move(i_t1);

    decltype(true ? i : i) i_t2 = i;    // int&   左值，推导为类型的引用

}

// 2.#define:宏定义的参数是无类型的，不做语法检查，不做表达式求解，只做替换
/*语法：
 * #define 宏名 替换文本
 * #define 宏名（参数列表） 替换文本
 *
 * define中的三个特殊符号：##，#，#@
 * */

void demo1()
{
#define Pi 3.14
    float l =  2 * Pi;
    cout << l << endl;

#define AddOne(x) ((x)+1)
    int x = 0;
    x = AddOne(x);
    cout << x << endl;

#define Conn(x, y) (x##y)
    int r1 = Conn(123, 567);
    cout << r1 << endl;

//#define T(x) #@x
//    char a = T(1);

#define T2(x) #x
    char * r = T2(123av);
    cout << r << endl;
}


// explict
class A
{
public:
    int k;
    A() =default;
    A(int m):k(m){cout << "constructor: " << this->k << endl;}
};
class B
{
public:
    int k, v;
    B() =default;
    explicit B(int m):k(m){cout << "constructor: " << this->k << endl;}
};

void demo2()
{
    A a =10;    // 隐式调用，相当于A a = A(10);

//    B b = 10;   // 构造函数添加explicit, 不允许隐式调用；
}

int main()
{
    demo1();
    return 0;
}