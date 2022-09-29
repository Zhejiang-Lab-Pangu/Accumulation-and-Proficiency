//
// Created by Administrator on 2022/9/28.
//


/*  类模板中的友元
 *
 * */

#include<iostream>
using namespace std;



template<class T2> class C2;
template< class T1>
class C1
{
friend class C2<int>;

template<class T3> friend class C3;         // 泛化友元写法

friend T1;  // 类型参数做模板友元

friend class C4;    // 普通类做类模板友元

template<typename TV1, typename TV2> friend void func1();   // 函数模板做类模板友元(无参)
template<class TW1, typename TW2> friend void func2(TW1, TW2);      // 函数模板做类模板友元(有参)

friend void func3(C1<T1> &c1)       // 编译后会成为全局函数
{
    c1.id = 900;
    cout << c1.id << endl;
}

private:
    int id;
};


template<class T2>
class C2
{
public:
    void func0()
    {
        C1<int> c1{};
        c1.id=123;
        cout << c1.id << endl;
    }
};

template<class T3>
class C3
{
public:
    void func0()
    {
        C1<int> c1{};
        c1.id=456;
        cout << c1.id << endl;
    }
};

class C4
{
public:
    void func1()
    {
        C1<C4> c1;
        c1.id = 789;
        cout << c1.id << endl;
    }

    void func4()
    {
        C1<int> c1;
        c1.id = 321;
        cout << c1.id << endl;
    }
};

/*
 * 1. 特化版的类模板做另一个类的友元
 * 2. 泛化
 * 3. 类型参数做模板友元
 * 4. 普通类做类模板的友元
 * */
void demo1()
{
    C2<int> c2;
    c2.func0();


    C3<double> c3;
    c3.func0();
    C3<float> c4;
    c4.func0();

    C4 c44;
    c44.func1();
    c44.func4();
}



template<typename TV1, typename TV2>
void func1()
{
    C1<int> c1;
    c1.id = 100;
    cout << c1.id << endl;
}

template<typename TV1, typename TV2>
void func2(TV1 a, TV2 b)
{
    C1<int> c1;
    c1.id = 400;
    cout << c1.id << endl;
}


void demo2()
{
    cout << "====================" << endl;
    func1<float, char>();

    func2(3, 4);

    C1<int> c1;
    func3(c1);      // 若不调用，编译时，C1类中无func3
}


int main()
{
    demo1();
    demo2();
    return 0;
}
