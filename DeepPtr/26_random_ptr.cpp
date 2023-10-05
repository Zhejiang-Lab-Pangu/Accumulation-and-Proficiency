//
// Created by Administrator on 2023/9/15.
//
#include <iostream>
using namespace std;

/*
 * 智能指针
 *          malloc/free  和 new/delete 很容易造成内存泄露；
 *          引入智能指针： 其实就是将new/delete作了一层封装，让开发者更方便的去做内存管理 （主要就是在各种场景下，帮忙delete）
 *
 *          智能指针 -->> new/delete -->> malloc/free
 *
 *
 * auto_ptr(c++98) 不建议使用
 *
 *
 * shared_ptr   共享
 * unique_ptr   独占
 * weak_ptr     配合shared_ptr使用
 *
 *
 * */

void demo0(){

    int *p1 = new int;
    int *p2 = p1;
    int *p3 = p2;
    int *p4 = p3;

    cout << &p1  << "  " << p1 << endl;     // 前面是栈上地址，后面指向了堆区的同一个地址
    cout << &p2  << "  " << p2 << endl;
    cout << &p3  << "  " << p3 << endl;
    cout << &p4  << "  " << p4 << endl;


    // 释放一次即可，释放谁都行
    delete p1;
    //delete p2;
    //delete p3;
    //delete p4;
}

int main(){
    demo0();

    return 0;
}