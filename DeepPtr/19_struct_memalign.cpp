//
// Created by Administrator on 2023/9/14.
//
#include <iostream>
using namespace std;

/*
 * 结构体内存对齐
 *
 * 结构体整体大小与其所有成员的大小有关
 *
 * (1) 结构体变量的 起始地址 要能被其 最大的成员整除
 * (2) 结构体变量的 总体大小 要能被其 最大的成员整除
 * (3) 结构体变量的 每个成员 相对于开始地址的偏移量，要能被自身整除
 * (4)  如果有数组成员，则内存对齐取是 取得数组首元素来进行计算
 *
 * */



struct T1{
    int a;
    int *c;
    char d;
};

struct T2{
    int *c;
    int a;
    char d;
};

struct T3{
    int id;
    char name[10];
};

int main(){
    struct T1 t1{};


    printf("%p\n", &t1.a);
    printf("%p\n", &t1.c);
    printf("%p\n", &t1.d);


    cout << sizeof(t1) << endl;


    struct T2 t2{};
    cout << sizeof(t2) << endl;

    struct T1 t3{};
    cout << sizeof(t3) << endl;     // 20;  如果有数组成员，则内存对齐取是 取得数组首元素来进行计算


    return 0;
}