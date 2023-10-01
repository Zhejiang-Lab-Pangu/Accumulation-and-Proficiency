//
// Created by Administrator on 2023/9/18.
//
#include <iostream>
using namespace std;
#include <memory>

/*
 * shared_ptr的定义和初始化
 *
 * 1.类模板格式定义： shared_ptr<数据类型> 指针变量名;
 *
 * */

shared_ptr<int> func1(int a){
    return shared_ptr<int>(new int(a));
}
void demo0(){


    // 1.定义
    shared_ptr<int> p1;     // shared_ptr 定义完之后就是空指针
    cout << (p1 == NULL) << "  " << ( p1 == nullptr) << endl;       // 1    1

    int * p2 = new int;     //野指针
    cout << (p2 == NULL) << "  " << ( p2 == nullptr) << endl;       // 0    0
    delete(p2);


    // 2.初始化
    // shared_ptr<int> p3 = new int(124);      // shread_ptr不支持隐式类型转换
    shared_ptr<int> p4(new int(124));
    shared_ptr<int> p5 = func1(124);
    shared_ptr<int> p6 = p5;
    shared_ptr<int> p7(p6);

    int *p8 = new int(124);
    shared_ptr<int> p9(p8);     // 不建议裸指针初始化智能指针；即不建议裸指针和智能指针混用（大忌！！！）


}


struct T{
public:
    T(int a, char b): a_(a), b_(b){}
    int a_;
    char b_;
};


void demo1(){
    shared_ptr<int> p1 = make_shared<int>(124);
    shared_ptr<int> p2 = p1;
    shared_ptr<int> p3(p2);

    T t(123, 'A');
    shared_ptr<T> p4 = make_shared<T>(T(123, 'A'));
    shared_ptr<T> p5 = make_shared<T>(t);
}


int main(){

//    demo0();
    demo1();
    return 0;
}