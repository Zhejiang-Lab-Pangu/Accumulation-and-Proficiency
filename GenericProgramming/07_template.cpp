//
// Created by Administrator on 2022/9/26.
//

#include<iostream>
using namespace std;

/*
 * 类模板的嵌套
 * */


template<class T1>
class A1
{
public:
    void func1()
    {
        cout << "A1-T1-func1" << endl;
    }

    template<class T2>
    class A2
    {
    public:
        void func1()
        {
            cout << "A1-T1-A2-T2-func1" << endl;
        }
    };

    template<class T4>
    void func4()
    {
        A3<T4> a3;
        a3.func1();
    }

private:
    template<class T3>
    class A3
    {
    public:
        void func1()
        {
            cout << "A1-T1-A3-T3" << endl;
        }
    };
};



void demo1()
{
    A1<int> a1;
    a1.func1();
    A1<double>::A2<float> a2;
    a2.func1();

    a1.func4<float>();
}


// 泛化特化
template <class TM1>
class B1
{
public:
    void func1()
    {
        cout << "B1-TM1-func1" << endl;
    }

    // B1泛化--B2类内泛化
    template<class TM2>
    class B2
    {
    public:
        void func2()
        {
            cout << "B1-TM1---B2-TM2-func2" << endl;
        }
    };

    // B1泛化--B2类内特化
    /*
    template<>
    class B2<int>
    {
    public:
        void func2()
        {
            cout << "B1-TM1---B2-int-func2" << endl;
        }
    };
    */
};
//
//template<class TM1>
//template<>
//class B1<TM1>::B2<int>
//{
//
//};


template<>
class B1<double>
{
public:
    template<class TM3>
    class B2
    {
    public:
        void func2()
        {
            cout << "B1-double---B2-TM3-func2" << endl;
        }

    };
};

template<>
template<>
class B1<double>::B2<double>
{
public:
    void func1()
    {
        cout << "特化特化" << endl;
    }
};

void demo2()
{
    B1<int> b1;
    b1.func1();

    // B1 泛化 B2 泛化
    B1<float>::B2<int> b2;
    b2.func2();

    // B1 特化 B2 泛化
    B1<double>::B2<int> b3;
    b3.func2();

    // B1 特化 B2 特化
    B1<double>::B2<double> b4;
    b4.func1();
}


int main()
{
//    demo1();
    demo2();
    return 0;
}