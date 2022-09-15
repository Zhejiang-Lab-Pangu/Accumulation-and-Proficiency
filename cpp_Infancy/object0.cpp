//
// Created by Administrator on 2022/9/14.
//

/*面向对象 -->> 封装
 * ①类、成员属性；
 * ②初始化：构造(无参、有参、拷贝)，析构，深浅拷贝，静态成员变量、静态成员函数、初始化列表
 * ③this指针
 * ④友元(普通函数、类、成员函数)
 * ⑤重载：运算符、仿函数(()的重载)
 * */

#include <iostream>
using namespace std;


class Sun
{
    // 友元
    friend class NIE;
public:
//    Sun()
//    {
//        cout << "constructor function" << endl;
//    }

    explicit Sun(int h, int a)
    {
        this->height = h;
        this->age = new int(a);
        this->qq = 1037137720;
//        cout << *(this->age) << endl;
        cout << "有参构造" << endl;
    }

    Sun(const Sun &s)
    {
        this->height = s.height;
        cout << "拷贝构造" << endl;

//        this->age = new int(*s.age);

    }

    // 运算符重载
    Sun operator+(Sun &s)
    {
        Sun temp(0, 0);
        temp.height = this->height + s.height;
        cout << *(this->age) << *(s.age)<< endl;
        *(temp.age) = *(this->age) + *(s.age);
        return temp;
    }

    // 仿函数
    void operator()(int k)
    {
        cout << this->height + k << endl;
        cout << "调用仿函数" << endl;
    }

    static void func0()
    {
    cout << "静态成员函数只能访问静态成员变量：" << weight << endl;
    }

    Sun & func1()
    {
        cout << "返回对象本身" << endl;
        return *this;
    }

    ~Sun()
    {
        cout << "析构函数" << endl;

        if(this->age != nullptr)
        {
            delete this->age;
            this->age = nullptr;
        }
    }

    int height;
    int *age;
    static int weight;

private:
    int qq;
};

int Sun::weight = 140;  // 类外初始化静态成员


class NIE
{
public:
    NIE()
    {
        sun = new Sun(187, 178);
    }

    void visit()
    {
        cout << "友元类访问Sun类的私有属性qq: " << sun->qq << endl;
    }

    ~NIE()
    {
        if(this->sun != nullptr)
        {
            delete this->sun;
            this->sun = nullptr;
        }
    }

public:
    Sun * sun;
};


void demo1()
{
    Sun s(189, 199);
    Sun s1 = Sun(179, 201);
    Sun s2(s1);
    Sun s3 = Sun(s1);
    cout << s3.height << endl;
    cout << *s3.age << endl;
    cout << Sun::weight  << endl;
    Sun::func0();
    Sun s4 = s3.func1();
}

void demo2()
{
    NIE n;
    n.visit();
}

void demo3()
{
    Sun s1(123, 14), s2(1, 1);
    Sun s0 = s1+s2;
    cout << s0.height  << endl;
    cout << *(s0.age) << endl;

}

void demo4()
{
    // 仿函数调用
    Sun s(1, 1);
    s(10);
}


//初始化列表
class Kun
{
public:
    Kun(int a, int b, int c): m_a(a), m_b(b), m_c(c){};

    int m_a, m_b, m_c;
};
void demo5()
{
    // 初始化列表
    Kun k(1, 2, 3);
    cout << k.m_a << k.m_b << k.m_c << endl;

}

int main()
{
//    demo1();
//    demo2();
//    demo3();
    demo4();
    demo5();
    return 0;
}