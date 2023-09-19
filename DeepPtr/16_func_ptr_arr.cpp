//
// Created by Administrator on 2023/9/12.
//
#include <iostream>
using namespace std;
#include <cstring>

/*
 * 函数指针数组： 本质上是数组，里面的元素都是函数指针
 *
 * 形式： int (*p[4])(int, int)= { p1, p2, p3, p4};
 * 调用： (*p[i])(1, 2);
 * */


int func1(int a, int b) {return a+b;}
int func2(int a, int b) {return a-b;}
int func3(int a, int b) {return a*b;}
int func4(int a, int b) {return a/b;}



void demo1(){
    int a =10, b =2;
    int(*p1)(int, int) = func1;
    int(*p2)(int, int) = func2;
    int(*p3)(int, int) = func3;
    int(*p4)(int, int) = func4;

    int (*p[4])(int, int)= { p1, p2, p3, p4};
    int (*pA[4])(int, int)= {func1, func2, func3, func4};           // 可直接写成这样

    for(int i=0; i<4; i++){
        cout << (*p[i])(a, b) << endl;
    }

    for(auto & i : p){
        cout << (*i)(a, b) << endl;
    }

}





int main() {

    demo1();
    return 0;
}