//
// Created by Administrator on 2023/8/29.
//
#include <iostream>
using namespace std;


/*
 * 野指针（wild ptr）
 *
 * 1.局部变量定义后，若无初始化，会有一个随机值
 *
 * */

int * f1(){
    int x = 123;
    return &x;
}

void demo1(){

    //1.指针变量未初始化,是随机值
    int *p;

    // 2. 数组(指针地址越界)索引越界 或 访问不存在的元素
    int a[3] = {0, 0, 0};   //4个字节 * 3个元素 = 12B空间
    for(int i=0;i<5; i++){
        cout << "a[" << i << "] = " << &a[i] << endl;
    }

    // 3.使用了已销毁的内存地址
    int *p1 = f1();
    cout << p1 << endl;     // 地址还在
    cout << *p1 << endl;    // 局部变量的值已被系统回收，获取随机值
}



/*
 * 空指针 nullptr
 * 不能解引用，不能对解引用赋值
 *
 * */

void demo2(){
    int *p = nullptr;       // 系统保留地址
    cout << p << endl;

    p = new int(3);
    cout << sizeof(nullptr) << endl;
}

int main(){
//    demo1();
    demo2();
    return 0;
}