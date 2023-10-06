//
// Created by Administrator on 2023/9/21.
//
#include <iostream>
using namespace std;
#include <memory>

/*
 * unique_ptr 定义核初始化
 *
 * unique_ptr 独占式智能指针，同一时间，智能有一个unique_ptr 变量 指向同一个内存空间，且只有此unique_ptr 对该内存空间有操作权限
 *
 * 定义：unique_ptr<int> p;    定义完成即是一个空指针
 *
 * 初始化：
 *          make_unique<>()     c++14后定义，不支持自定义删除器
 *          unique_ptr<Type> p(new Type(value));
 *          unique_ptr<Type> p2 = std::move(p1);        将p1销毁，并将p1原来维护的内存空间的权限转移给p2
 * */

void demo0(){

    // 定义
    unique_ptr<int> p1;

    cout << (p1 == nullptr) << endl;

    // 初始化

    unique_ptr<int> p2;
    p2 = make_unique<int>(122);

    unique_ptr<int> p3(make_unique<int>(222));

    unique_ptr<int> p4(new int(333));

    // 不支持
    // unique_ptr<int> p5(p4);
    // unique_ptr<int> p6= p4;


    unique_ptr<int> p7 = std::move(p2);

    cout << (p2 == nullptr) << endl;
    cout << (*p7) << endl;
}

int main(){

    demo0();
    return 0;
}