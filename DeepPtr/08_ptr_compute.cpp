//
// Created by Administrator on 2023/9/5.
//

#include <iostream>
using namespace std;


/*
 * ptr compute
 *
 * 指针运算的前提： 指针所指向的数据类型要一致
 *
 * */




void demo1(){

    // (1) 指针与整数的加减运算，步长是数据类型的空间大小
    int a[4] = {11, 22, 33, 44};

    cout << a << "  " << *a << endl;
    cout << a+1 << "  " << *(a+1) << endl;
    cout << a+2 << "  " << *(a+2) << endl;
    cout << a+3 << "  " << *(a+3) << endl;
    cout << a+10 << "  " << *(a+10) << endl;        // 下标越界，野指针
    cout << a-1 << "  " << *(a-1) << endl;          // 下标越界，野指针

    cout << endl;
    int *p = &a[3];
    cout << p << "  " << *p << endl;
    cout << p-2 << "  " << *(p-2) << endl;


    // (2) 指针自增自减
    cout << endl;
    int *p1 = &a[2];
    cout << p1 << "  " << *p1 << endl;
    p1--;
    cout << p1 << "  " << *p1 << endl;
    p1++;
    cout << p1 << "  " << *p1 << endl;

    cout << *a << endl;

}


// 指针之间的运算
void demo2(){

    int a[4] = {11, 22, 33, 44};

    // 1.比较
    int  *p = a;
    int *p0 = &a[0];
    int *p1 = &a[1];
    int *p2 = &a[2];

    cout << (p == p0) << endl;
    cout << (p0 < p1) << endl;
    cout << (p0 > p1) << endl;


    // 2.指针之间的减法
    cout << (p0-p2) << endl;        // -2个int
    cout << (p2-p0) << endl;        // 2个int
}



int main(){

//    demo1();
    demo2();
    return 0;
}
