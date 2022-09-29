//
// Created by Administrator on 2022/9/28.
//

/*
 * 子类做父类的模板参数 -- 只是编程技巧
 *
 * */


#include <iostream>
using namespace std;


template<class T>
class Father
{
public:
    void sonsay()
    {
        // static_cast操作符可用于将一个指向基类的指针转换为指向子类的指针 -->> 语法：static_cast<目标类型> 指针
        T &s = static_cast<T &>(*this);     // 把父类强转成子类对象
        s.say();
    }
};


class Son: public Father<Son>
{
public:
    void say()
    {
        cout << "son" << endl;
    }
};

template<class T1>
class Son2: public Father<Son2<T1>>
{
public:
    void say()
    {
        cout << "son2" << endl;
    }
};

void demo()
{
    Son s;
    s.sonsay();

    Son2<float> s2;
    s2.sonsay();
}

int main()
{
    demo();
    return 0;
}