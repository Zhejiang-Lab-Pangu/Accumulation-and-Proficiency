//
// Created by Administrator on 2023/9/14.
//

#include <iostream>
using namespace std;
#include <cstring>

/*
 * 结构体指针
 *
 * */



struct T1{
    int id;
    char name[10];
};

void demo0(){
    struct T1 t1{123,  "abc"};
    // cout << sizeof(t1) << endl;     // 20;  如果有数组成员，则内存对齐取是 取得数组首元素来进行计算

    struct T1 *p  = &t1;
    cout << sizeof(p) << endl;

    cout << p->name << "  " << p->id << endl;

    p->id = 456;
    //p->name = "sun";      //name为char[]类型，不是char*，不能赋值字符串
    strcpy(p->name, "sun");
    cout << p->name << "  " << p->id << endl;

}

// 避免野指针：分配内存空间
void demo1(){

    struct T1 *p1 = (T1*)malloc(sizeof(T1));        // 堆区分配一个
    p1->id = 222;
    strcpy(p1->name, "hong");
    cout << p1->name << "  " << p1->id << endl;
    free(p1);
}


int main(){

    demo0();
    demo1();
    return 0;
}