//
// Created by Administrator on 2023/1/17.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * enable_if 结构体模板
 *
 * // 泛化版
    template<bool, class _Tp = void >
    struct enable_if
    {

    };

    // 特化版
    template<class _Tp>
    struct enable_if<true, _Tp>
    {
        typedef _Tp type;
    };
 *
 *
 * enable_if中的条件特化可以看成一个条件分支语句，在编译期就能决定走哪个分支
 * 但是，代码中的条件分支语句，必须得执行的时候才知道条件是否成立，走哪个分支
 * */

/*
 * std::is_convertible<T1, T2>::value
 * 判断T1是否能隐式的转为T2类型，返回值是bool
 *
 * */


template<class T>
struct S1{
//    using type = T;
    typedef T type;
};


template<bool, class T>
struct S2{

};

template<class T>
struct S2<true, T>{
//    using type = T;
    typedef T type;
};

void demo1()
{
    S1<int>::type a = 123;
    cout << a << endl;

    S1<string>::type b = "abc";
    cout << b << endl;
}


void demo2()
{
    enable_if<true>::type * p1 = nullptr; // void *p1 = nullptr
    enable_if<true, string>::type s = "abc";    // string s = "abc"

    enable_if<(1<2), int>::type x =999;
}


template<class T1>
typename enable_if<(sizeof(T1) > 2), T1>::type func1(T1 a){
    return a;
}

void demo3()
{
    int a = func1<int>(4);
    cout << a << endl;

    double b = 12.3;
    double c = func1(b);
    cout << c << endl;
}


class C1
{
public:
    template<
            class T1,
            //class T2 = typename std::enable_if<is_convertible<T1, string>::value>::type
            class T2 = typename std::enable_if_t<is_convertible<T1, string>::value>
            >
    C1(T1 && name){
        this->name = std::forward<T1>(name);
        cout << "template" << endl;
    }

    C1(const C1 & c1)
    {
        this->name = c1.name;
        cout << "copy function" << endl;
    }
    string name;
};

void demo4()
{
    string name = "sunhongjiang";


    C1 c1(name);
    C1 c2(c1);
}


void demo5()
{
    bool rs = std::is_convertible<string, int>::value;
    cout << rs << endl;

    bool rs2 = std::is_convertible<double, int>::value;
    cout << rs2 << endl;
}

int main()
{
    demo1();
    demo2();
    demo3();
    cout << endl;
    demo4();
    cout << endl;
    demo5();
    return 0;
}