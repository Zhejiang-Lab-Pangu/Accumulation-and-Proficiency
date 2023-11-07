//
// Created by Administrator on 2022/9/14.
//

/*面对对象 -->> 继承
 * ①继承语法，权限继承变动，构造析构继承
 * ②同名成员加作用域
 * ③多继承、虚继承
 * */

/*面对对象 -->> 多态
 * ①静态多态和动态多态，动态多态的实现（子类重写父类虚函数，父类引用或指针指向子类对象）
 * ②抽象类和纯虚函数
 * ③虚析构：virtual ~类名(){}；②纯虚析构：virtual ~类名() = 0;
 * */


#include <iostream>
using namespace std;


class Cpp0
{
public:
    int a = 1;
};

class Cpp
{
public:
    Cpp()
    {
        a = 10;
        cout << "构造" << endl;
    }

    void func()
    {
        cout << "father`s function" << endl;
    }

    ~Cpp()
    {
        cout << "析构" << endl;
    }

    int a;
};

class Python1: virtual public Cpp{};       // 继承之前加关键字 virtual 变为虚继承; Animal称为虚基类{}

class Python : public Cpp
{
public:
    Python()
    {
        a = 12;
        cout << "son`s 构造" << endl;
    }
    void func()
    {
        cout << "子类同名函数" << endl;
    }
    void func1()
    {
        cout << "son`s function" << endl;
    }
    ~Python()
    {
        cout << "son`s 析构" << endl;
    }
    int a;
};

class Sun: public Cpp, public Cpp0
{
public:
    int x = 0;
};



void demo1()
{
    Python p;
//    p.func1();
//    p.func();
}

void demo2()
{
    // 子类若想访问父类的同名成员需要添加作用域，静态成员也一样
    Python p;
    cout << p.a << endl;
    cout << p.Cpp::a << endl;
    p.func();
    p.Cpp::func();
}

void demo3()
{
    Sun s;
    cout << s.x << endl;
    cout << s.Cpp0::a << endl;
    s.Cpp::func();
}


//======================================================================================================
class Animal
{
public:
    // 虚函数
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};

class Cat: public Animal
{
public:
    void speak()
    {
        cout << "猫在说话" << endl;
    }
};

class Dog: public Animal
{
public:
    void speak()
    {
        cout << "🐶在说话" << endl;
    }
};

// 地址早绑定 ->> 地址晚绑定  通过虚函数
void do_speak(Animal & animal)
{
    animal.speak();
}

void demo4()
{
    Cat c;
    Dog d;
    do_speak(c);
    do_speak(d);

}

void demo5()
{
    cout << sizeof(Animal) << endl;
    cout << sizeof(Cat) << endl;
}

class Base // 抽象类
{
public:
    // 纯虚函数
    virtual void fun() = 0;
};

class Son: public Base
{
public:
    // 子类必须重写抽象类中的纯虚函数，否则也属于抽象类
    void fun()
    {
        cout << "fuck" << endl;
    }
};

void demo6()
{
    Son s;
    s.fun();
}

int main()
{
//    demo1();
//    demo2();
//    demo3();
    demo4();
    demo5();
    demo6();
    return 0;
}
