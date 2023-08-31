//
// Created by Administrator on 2023/8/16.
//
//
// Created by Administrator on 2023/8/14.
//



#include<iostream>
#include <vector>
#include <list>
#include <array>
using namespace std;
#include <cxxabi.h>

/* remove_all_extent
 *
 * 获取数组元素中的具体类型
 *
 * */


template<class T1>
struct getType{};


template<class T1>
struct getType<vector<T1>>{
    using type = T1;
};

template<class T1>
struct getType<list<T1>>{
    using type = T1;
};

template<class T1, size_t size>
struct getType<array<T1, size>>{
    using type = T1;
};


// 别名
template<class T>
using TYPE = typename getType<T>::type;

template<class T>
void func0(const T & a){
//    TYPE<T> t4;
    cout << abi::__cxa_demangle(typeid(TYPE<T>).name(), 0, 0, 0) << endl;
}


void demo1()
{

    vector<int> a{};
    list<double> b{};
    array<char, 10> c{};


    getType<decltype(a)>::type t1;
    getType<decltype(b)>::type t2;
    getType<decltype(c)>::type t3;
    cout << abi::__cxa_demangle(typeid(t1).name(), 0, 0, 0) << endl;
    cout << abi::__cxa_demangle(typeid(t2).name(), 0, 0, 0) << endl;
    cout << abi::__cxa_demangle(typeid(t3).name(), 0, 0, 0) << endl;

    cout << endl;

    TYPE<decltype(a)> t4;
    TYPE<decltype(b)> t5;
    TYPE<decltype(c)> t6;
    cout << abi::__cxa_demangle(typeid(t4).name(), 0, 0, 0) << endl;
    cout << abi::__cxa_demangle(typeid(t5).name(), 0, 0, 0) << endl;
    cout << abi::__cxa_demangle(typeid(t6).name(), 0, 0, 0) << endl;

    cout << endl;

    func0(a);
    func0(b);
    func0(c);
}


int main()
{
    demo1();
    return 0;
}