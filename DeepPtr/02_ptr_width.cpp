//
// Created by Administrator on 2023/8/28.
//
#include<iostream>
using namespace std;


/*
 * 指针的宽度/步长：
 *
 * 指针宽度与指针变量的数据类型有关，是对应数据类型所占的内存空间大小
 *
 * */

struct A{
    int x;
    bool j;
};

void demo1(){

    int *p1 = new int(123);

    cout << p1 << endl;
    cout << ++p1 << endl;   // 指针移动4B

    bool *p2;
    cout << p2 << endl;
    cout << ++p2 << endl;   // 指针移动1B

    A * p3 = new A;
    cout << p3 << endl;
    cout << ++p3 << endl;       // 移动 8B; 因为内存对齐

    A ** p4 = &p3;
    cout << p4 << endl;
    cout << p4+1 << endl;

    cout << sizeof(double) << "\t" << sizeof(float) << endl;

    cout << endl;
    // 数组
    int arr[3] = {1, 2, 3};     // 给arr分配 4*3的空间大小
    cout << arr << endl;
    cout << &arr[0] << "  " << arr << endl;
    cout << &arr[1] << "  " << arr+1 << endl;
    cout << &arr[2] << "  " << arr+2 << endl;

}


int main(){
    demo1();
    return 0;
}