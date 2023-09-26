//
// Created by Administrator on 2023/9/14.
//
#include <iostream>
using namespace std;


/*
 * calloc 和 realloc
 *
 * 1. malloc和calloc都是在堆区手动分配内存
 *      (1) 参数不一样；
 *      (2) calloc 分配内存完成后会清零，malloc不会，calloc相当于malloc + memset(0)
 *
 *
 * 2. realloc 表示将原有的指针空间进行扩充；
 *      (1) 若原指针后面空间足够，直接扩充；
 *      (2) 若原指针后面空间不足，则开辟新空间，并拷贝数据
 * */

void demo0(){

    int *p1 = (int *)malloc(sizeof(int) * 10);
    int *p2 = (int *)calloc(10, sizeof(int));

    for (int i=0; i<10; i++){
        cout << p1[i] << "  ";
    }
    cout << endl;
    for(int i=0; i<10; i++){
        cout << p2[i] << "  ";
    }

    free(p1);
    ::free(p2);

}


void demo1(){

    int *p1 = (int *)malloc(sizeof(int) * 4);
    cout << p1 << endl;
    for(int i =0; i<10; i++){
        cout << p1[i] << "  ";
    }
    cout << endl;

    int *p2 = (int *)malloc(sizeof(int) * 3);

    p1 = (int *) realloc(p1, sizeof(int)*10);        // 表示把p1的内存空间扩大到10个int
    cout << p1 << endl;
    for(int i =0; i<10; i++){
        cout << p1[i] << "  ";
    }
    cout << endl;


    free(p1);
    free(p2);
}

int main(){
//    demo0();
    demo1();
    return 0;
}