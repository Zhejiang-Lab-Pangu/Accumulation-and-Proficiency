//
// Created by Administrator on 2022/10/31.
//

#include<iostream>
using namespace std;
#include <utility>
#include <vector>
#include <algorithm>
#include <string>



/* 普通函数适配器：
 * ptr_fun 把普通函数转为函数对象，再加适配器
 *
 *
 * 类中成员函数适配器：
 * 当容器中存储的是对象，则用mem_fun_ref 来适配其成员函数
 * 当容器中存储的是对象指针。 则用mem_fun 来适配其成员函数
 *
 * */



void myPrint(int a)
{
    cout << a << " -- ";
}

void myPrint2(int a, int b)
{
    cout << a * b << " -- ";
}

void demo1()
{
    vector<int> v1{1, 2, 3, 4};
    // 普通函数
    for_each(v1.begin(), v1.end(), myPrint);
    cout << endl;

    // 普通函数转函数对象
    for_each(v1.begin(), v1.end(), ptr_fun(myPrint));
    cout << endl;

    // 普通函数转函数对象, 再加适配器
    for_each(v1.begin(), v1.end(), bind2nd(ptr_fun(myPrint2), 10));
    cout << endl;
}


class C1
{
public:
    C1(int id, string name): m_id(id), m_name(std::move(name)){};
    ~C1()= default;
    void printC1()
    {
        cout << this->m_id << "-- " << this->m_name << "\t";
    }

    int m_id;
    string m_name;
};

void printC1(const C1 & c)
{
    cout << c.m_id << "-- " << c.m_name << "\t";
}

void demo2()
{
    vector<C1> v1{C1(123, "sun"), C1(234, "li"), C1(345, "wang"), C1(567, "zhao")};

    // 普通函数
    for_each(v1.begin(), v1.end(), printC1);
    cout << endl;

    // 当容器中存储的是对象，则用mem_fun_ref 来适配其成员函数
    for_each(v1.begin(), v1.end(), mem_fun_ref(& C1::printC1));
    cout << endl;

    // 当容器中存储的是对象指针。 则用mem_fun 来适配其成员函数
    vector<C1 *> v2{new C1(123, "sun"), new C1(234, "li"), new C1(345, "wang"), new C1(567, "zhao")};
    for_each(v2.begin(), v2.end(), mem_fun(& C1::printC1));
    cout << endl;

}

int main()
{
    demo1();
    demo2();
    return 0;
}
