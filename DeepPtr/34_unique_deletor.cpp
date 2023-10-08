//
// Created by Administrator on 2023/9/25.
//


#include <iostream>
using namespace std;
#include <memory>
#include <cxxabi.h>

/*
 * unique_ptr的删除器
 *
 * 形式
 *      unique_ptr<数据类型，删除器类型> 变量名(new 数据类型(初始值), 函数名);
 *
 * unique_ptr 转 shared_ptr
 * 前提： 当unique_ptr为右值时，才可以转shared_ptr
 *
 * */



void func1(int *p){
    cout << " deletor func1" << endl;
    delete p;
    p = nullptr;
}

void demo0(){

    shared_ptr<int> p1(new int(123), func1);


    //typedef void(*pf)(int *p);
    using pf = void(*)(int *);
    unique_ptr<int, pf> p2(new int(222), func1);


    //lambda

    auto lambda = [](int *a){
        cout << "lambda deletor" << endl;
        delete a;
        a = nullptr;
    };

    unique_ptr<int, decltype(lambda)> p3(new int(456), lambda);


}


void demo1(){
    unique_ptr<int> p1 = make_unique<int>(123);

    shared_ptr<int> p2 = make_unique<int>(123);     // 右值的unique_ptr可转为shared_ptr
    // shared_ptr<int> p3 =p1;     // 左值不可转
    shared_ptr<int> p4 = std::move(p1);     // 这样没毛病
    cout << (p1 == nullptr) << endl;    //1
}


int main(){
//    demo0();
    demo1();
    return 0;
}