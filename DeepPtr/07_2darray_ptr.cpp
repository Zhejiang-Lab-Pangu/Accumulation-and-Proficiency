//
// Created by Administrator on 2023/9/5.
//


#include <iostream>
using namespace std;


/*
 * 2D-array  ptr
 *
 * int arr[][];
 * (1) arr 的步长为a[0]的空间大小
 * (2) &arr 的步长为整个数组的空间大小
 * (3) 类比一维指针，二维指针的 a[i] 等价于 一维指针的a
 *
 *
 * */



void demo1(){

    int a[2][3] = {{111, 222, 333}, {444, 555, 666}};

    cout << a << endl;      // 等价于 &a[0]
    cout << &a << endl;     // 数组a的地址，其是指向首元素的指针
    cout << a[0] << endl;  // 数组a[0]首元素的指针
    cout << &a[0] << endl;  // 数组a[0]的首元素的指针
    cout << &a[0][0] << endl;  // 数组首元素的指针

    cout << endl;
    cout << a << "  " << a+1 << "  " << a+2 << endl;                        // 步长为3个int，即a[0]的空间长度
    cout << &a[0] << "  " << &a[0] + 1 << "  " << &a[0] +2 << endl;         //步长为3个int，即a[0]的空间长度
    cout << &a << "  " << &a+1 << "  " << &a+2 << endl;                     // 步长为6个int，即整个数组的空间长度
    cout << a[0] << "  " << a[0]+1 << "  " << a[0]+2 << endl;               // 步长为1个int，即元素的长度
    cout << &a[0][0] << "  " << &a[0][0]+1 << "  " << &a[0][0]+2 << endl;   // 步长为1个int，即元素的长度

    cout << endl;
    cout << sizeof(a) << "  " << sizeof(a[0]) << endl;      // 注意a，代表整个数组
    cout << sizeof(&a) << "  " << sizeof(&a[0]) << endl;    // 指针变量的长度
    cout << sizeof(a[0][0]) << "  " << sizeof(&a[0][0])<< endl;

    cout << endl;
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            cout << a[i][j] << "  " << &a[i][j] << "  " << a[i]+j << "  " << *(a[i]+j) << endl;
        }

    }
}


int main(){

    demo1();
    return 0;
}
