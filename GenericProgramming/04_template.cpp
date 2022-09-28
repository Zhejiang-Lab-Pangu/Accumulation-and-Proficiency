//
// Created by Administrator on 2022/9/23.
//

#include <iostream>
#include <string>
using namespace std;

/*类模板中参数推导
 *
 * 自动推到：C++17后开始
 * */

template<class T1, class T2=int>  // 可以设置默认值
class C
{
public:
    C(T1 a, T2 b): id(a), name(b)
    {
        cout << "constructor" << endl;
    }

    T1 id;
    T2 name;
};

/*
template<class T1, class T2>
class C2
{
public:
    T1 id;
    T2 name;
};
 // 自定义类型推导
template<class T1, class T2>
C2(T1, T2) -> C2<T1, T2>;
*/


void demo1()
{
    // C c1(123, "sun");    c++17是可以过的；支持类模板的类型自动推到
    C<int, string> c0(123, "sunhongjiang");
}



/* 编译规则：
 * ① 没有实例化，则不会编译类模板（被编译器优化，认为是无效代码）
 * ② 若实例化，只编译出对应的参数类型的代码
 * ③ 若成员函数不调用，则不编译
 * */


/*特化1*/
template<class T1, class T2=T1*>
class C1
{
public:
    C1(T1 id, T2 name): id(id), name(name) {};
    T1 id;
    T2 name;
};

/*特化：类外定义*/
template<class T1=int, class T2=int>
class C3
{
public:
    C3(T1, T2);
    T1 id;
    T2 name;
};

template<class T1, class T2>
C3<T1, T2>::C3(T1 id, T2 name)
{
    this->name = name;
    this->id = id;
}
void demo3()
{
    C3<int, double> c3(1, 2.3);
    cout << c3.name << "--" << c3.id << endl;
}

int main()
{
    demo1();
    demo3();
    return 0;
}