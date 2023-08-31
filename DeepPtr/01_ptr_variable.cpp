//
// Created by Administrator on 2023/8/27.
//
#include <iostream>
using namespace std;

// 指针和指针变量

void demo0(){
    int a = 123;
    cout << &a << endl;

    // 指针变量
    int *p = &a;
    cout << p << endl;

    // 解引用
    cout << *p << endl;

    // 指针地址
    cout << &p << endl;

    // 二级指针
    int **p1 = &p;
    cout << p1 << endl;

    // 解引用
    cout << *p1 << "\t" << **p1 << endl;
}

// 指针变量的空间大小：32位机是4B， 64位机是8B
class A{};
void demo2(){
    int *p1;
    A *p2;

    cout << sizeof(p1) << "  " << sizeof(p2) << "  " << sizeof(char*) << endl;
}

int main(){
    demo0();
    demo2();
    return 0;
}