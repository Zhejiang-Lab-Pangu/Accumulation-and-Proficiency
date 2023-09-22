//
// Created by Administrator on 2023/9/11.
//
#include <iostream>
using namespace std;
#include <cstring>

/*
 * 数组指针和指针数组
 *
 * */




void demo1(){

    char a[] ={'a', 'b', 'c'};

    // 1.数组和指针
    char *p = a;        // 本质是char指针，不过其指向了char数组的首元素地址,步长和a一致

    for (int i=0; i<3; i++){
        printf("%p -- %c\n", p+i, *(p+i));
    }


    // 2.数组指针
    char (*p2)[3] = &a;     // p2是一个指针变量，指向的是一个有3个元素的char类型的指针

    cout << sizeof(p2) << "  " << sizeof(a) << "  " << sizeof(*p2) << endl;

    for(int i=0; i<3; i++){
//        printf("%p -- %c\n", &(*p2)[i], (*p2)[i]);
        printf("%p -- %c\n", p2[i], (*p2)[i]);
    }


}





int main(){

    demo1();
    return 0;
}