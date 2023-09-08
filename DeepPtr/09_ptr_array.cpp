//
// Created by Administrator on 2023/9/6.
//
#include <iostream>
using namespace std;


/*
 * 指针数组
 *
 * 数组中存储指针变量元素
 *
 * */




void demo1(){

    int a = 11;
    int b = 22;
    int c = 33;

    int aArr[3] = {a, b, c};
    int *pArr[3] = {&a, &b, &c};

    // (1) 空间大小
    cout << sizeof(aArr) << endl;   // 3个int，12
    cout << sizeof(pArr) << endl;   // 3个ptr，24

    cout << endl;

    // (2) 步长
    cout << aArr << "  " << aArr+1 << endl;  //步长4
    cout << &aArr << "  " << &aArr+1 << endl;   // 步长12

    cout << pArr << "  " << pArr+1 << endl;     // 步长 8
    cout << &pArr << "  " << &pArr+1 << endl;   // 步长 3*8=24


    cout << endl;
    // (3) 赋值
    for(int i=0; i<3; i++){
        cout << &pArr[i] << "  " << pArr[i] << "  " << *pArr[i] << "  "<< *(pArr+i) << "  " << **(pArr+i) <<endl;

        *pArr[i] = *pArr[i] * 10;       // 通过a,b,c的地址，改了a,b,c的值
    }

    cout << a << "  " << b << "  " << c << endl;        // *10
    cout << aArr[0] << "  " << aArr[1] << "  " << aArr[2] << endl;  // 不变，因为aArr数组是新开辟的空间


    cout << endl;

    // (4) 元素地址：二级指针
    int **p = &pArr[0];

    cout << p << "  " << pArr << "  " << &pArr[0] << endl;

    int **p1 = pArr;
    cout << p1 << "  " << *p1 << "  " << **p1 << endl;
    cout << p1+1 << "  " << *(p1+1) << "  " << **(p1+1) << endl;
    cout << p1+2 << "  " << *(p1+2) << "  " << **(p1+2) << endl;

}


// 指针之间的运算
void demo2(){

}



int main(){

    demo1();
//    demo2();
    return 0;
}
