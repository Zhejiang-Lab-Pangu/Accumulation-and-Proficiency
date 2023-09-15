//
// Created by Administrator on 2023/9/4.
//
#include <iostream>
using namespace std;


/*
 * array  ptr
 *
 * int arr[];
 * (1) arr 的步长为int
 * (2) &arr de
 *
 *
 * */



void demo1(){

    int a[3] = {111, 222, 333,};

    cout << a << endl;      // 等价于 &a[0]
    cout << &a << endl;     // 数组a的地址，其是指向首元素的指针
    cout << &a[0] << endl;  // 数组首元素的指针

    cout << a << "  " << a+1 << "  " << a+2 << endl;        // 步长为int
    cout << &a[0] << "  " << &a[0] + 1 << "  " << &a[0] +2 << endl;     //步长为int
    cout << &a << "  " << &a+1 << "  " << &a+2 << endl;             // 步长为3个int，即整个数组的空间长度

    cout << endl;
    cout << sizeof(a) << "  " << sizeof(a[0]) << endl;      // 注意a，代表整个数组
    cout << sizeof(&a) << "  " << sizeof(&a[0]) << endl;    // 指针变量的长度

    cout << endl;
    for(int i=0; i<3; i++){
        cout << a[i] << "  " << &a[i] << "  " << a+i << "  " << *(a+i) << endl;
    }
}


int main(){

    demo1();
    return 0;
}
