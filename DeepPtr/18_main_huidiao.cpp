//
// Created by Administrator on 2023/9/13.
//
#include <iostream>
using namespace std;
#include <cstring>

/*
 * main 函数参数和回调函数
 *
 * 回调函数就是一个被作为参数传递的函数；在C语言中，回调函数只能用函数指针实现；在C++等中，还可用仿函数或匿名函数
 *
 *
 * */



int func1(int a, int b){return a+b;}
int func2(int a, int b){return a-b;}


int test(int (*p)(int, int), int a, int b){
    return p(a, b);
}

void demo1(){

    int a = 10;
    int b = 2;

    // func1、 func2就是test的回调函数； 作用： 解耦，让调用者和被调用者可以互不关联
    cout << test(func1, a, b) << endl;
    cout << test(func2, a, b) << endl;

}





int main(int argc, char *argv[]) {

    cout << argc << endl;

    for(int i=0; i<argc; i++){
        cout << argv[i] << endl;
    }

    cout << endl;

    demo1();
    return 0;
}
