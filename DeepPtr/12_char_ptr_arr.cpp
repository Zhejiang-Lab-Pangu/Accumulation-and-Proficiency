//
// Created by Administrator on 2023/9/11.
//
#include <iostream>
using namespace std;
#include <cstring>

/*
 * 字符指针 的 数组
 *
 *
 *
 * */




void demo1(){

    char a[] = "abc";
    char b[] = "def";
    char c[] = "xyz";

    char *p[3] = {a, b, c};

    cout << sizeof(p) << "  " << sizeof(p[0]) << "  " << sizeof(a) << "  " << sizeof(a[0]) << endl;

    for(int i=0; i<3; i++){
        printf("%p -- %p -- %s\n", &p[i], p[i], p[i]);

        *(p[i]+0) = 'A';
        p[i][1] = 'B';
    }

    cout << a << "  " << b << "  " << c << endl;


    cout << endl;

    char **pp = p;
    printf("%p -- %p -- %p -- %s\n", &pp, pp, *pp, *pp);
    for(int i=0; i<3;i++){
        cout << pp+i << "  " <<  *(pp+i) << endl;
//        **(pp+i) = 'Y';
        *(pp+i)[0] = 'O';
    }
    cout << a << "  " << b << "  " << c << endl;
}





int main(){

    demo1();
    return 0;
}