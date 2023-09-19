//
// Created by Administrator on 2023/9/9.
//

#include <iostream>
using namespace std;
#include <cstring>

/*
 * 字符数组的指针
 *
 * 1. char a[] = {'a', 'b', 'c'}
 *    char a[] = "abc"      // "abc"会以\0 结尾，sizeof会加1
 *    char *p =a;
 *
 * 2. const char * p = "abc";       // 栈区的指针p指向常量区的"abc",不可修改; 加const修饰
 *    *p = "xxx";       // 不合法
 *    p = "xxx";        // 合法
 *
 * */




void demo1(){

    char a = 'a';
    char *p = &a;

    cout << a  << "  " << sizeof(a) << endl;
//    cout << p << "  " << sizeof(p) << endl;     // << p 重载了char*，输出的并不是地址
//    printf("\n %p \n", p);

    *p = 'D';
    cout << a << endl;

}


void demo2(){

//    char a[] = {'a', 'b', 'c'};
    char a[] = "abc";       // sizeof(a) 中计算了结尾的 /0 ;所以为4

    char *p = a;

    printf("%c -- %s -- %ld -- %ld\n", *a, a, sizeof(a), strlen(a));
    printf("%c -- %s -- %ld -- %ld\n", *p, p, sizeof(p), strlen(p));

    cout << a << endl;
    cout << p <<endl;

    *p = 'A';
    *(p+1) = 'X';
    cout << a << endl;


    //
    char * p2 = "abc";
    p2 = "def";
    cout << p2 << endl;

    const char *p3 = "xxx";         // xxx 是存在内存常量区的数据; p3是栈区的指针，即p3指向了xxx的地址
    // *p3 = "def";    // 常量指针，不合法
    p3 = "def";     // 常量指针，修改指向，合法
    cout << *p3 << "  " << p3  << endl;
}



int main(){

//    demo1();
    demo2();
    return 0;
}