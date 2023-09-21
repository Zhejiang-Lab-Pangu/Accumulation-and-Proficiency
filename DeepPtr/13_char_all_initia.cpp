//
// Created by Administrator on 2023/9/11.
//
#include <iostream>
using namespace std;
#include <cstring>

/*
 * 字符变量、指针、数组、数组的指针、指针的数组  初始化
 *
 * 字符串两种初始化：
 *              1. char x[] = "abc";    常量区的数据拷贝到栈区 (栈区有数据)
 *              2. char *x = "abc";     常量区指针地址放到栈区 (栈区无数据)
 *
 * */




void demo1(){
    char a = 'a';       // 字符类型的变量
    char b = 'b';       // 字符类型的变量
    char *p = &a;       // 字符指针类型

    char c[] = {a, b, 'c'};     // 字符数组类型；此处a,b 对上面的变量a，b做了拷贝，内存空间独立；

    printf("%p -- %p -- %c -- %c\n", &a, &b, a, b);
    printf("%p -- %p -- %c -- %c\n", c, c+1, c[0], c[1]);


    char *p2[] = {&a, p, c};    // 字符指针类型的数组
    for(int i=0; i<3; i++){
        printf("%p -- %p --%p -- %c -- %c\n", p2+i, p2[i], *(p2+i) , **(p2+i), *p2[i]);
    }
}


void demo2(){

    char d[] = "abc";       // 初始化过程：1.先在栈区定义char 数组 变量， 并分配空间； 2.去常量去找"abc"，若无，写一份；再往栈区拷贝一份至char数组的空间

    printf("%p -- %p\n", d, &d);

    // 错误写法
    /*
    d[] = "def";        数组不能这样赋值
    d[0] = "D";         双引号后有\0，内存长度不够
    char a[2] = "ab";   双引号后有\0，内存长度不够
    */

    // 正确写法；
    d[0] = 'D';



    char *p1 = "abc";   // 初始化过程：1.先在栈区定义char * 变量， 并分配空间； 2.去常量去找"abc\0"，若无，写一份；再将常量区的指针地址给到栈区的变量
    char *p2 = "abc";
    char *p3 = "def";

    cout << &p1 << "  " << &p2 << "  " << &p3 << endl;
    cout << p1 << "  " << p2 << "  " << p3 << endl;
    printf("%p -- %p\n", p1, p2);

    cout << endl;
    const char *p4[] = {"abc", "abc", p1};
    for(int i=0; i<3; i++){
        printf("%p -- %p\n", p4[i], &p4[i]);
    }

    cout << endl;
    const char *p5[] = {d, p1, p2, "abc"};
    for(int i=0; i<4; i++){
        printf("%p -- %p\n", p5[i], &p5[i]);
    }
}




int main(){

//    demo1();
    demo2();
    return 0;
}