//
// Created by Administrator on 2022/9/28.
//

/*
 * 模板中的多态
 *
 * */

#include <iostream>
using namespace std;


/*
 * 模板里的多态：不需要继承，也没有虚函数，就是类和方法；但模板里面的多态，在编译期就确定了具体要调用的代码，不需要执行的时候去处理，性能更好；又称之为静态多态
 *
 * 传统多态：父类指针和引用调用子类里面重载的方法，要用虚函数，并在执行时处理，动态多态；
 * */

class Son1
{
public:
    void say()
    {
        cout << "son1" << endl;
    }
};
class Son2
{
public:
    void say()
    {
        cout << "son2" << endl;
    }
};

template<typename T>
void func0(T & a)
{
    a.say();
}

void demo()
{
    Son1 s1;
    Son2 s2;
    func0(s1);
    func0(s2);
}

int main()
{
    demo();
    return 0;
}
