//
// Created by Administrator on 2023/9/12.
//
#include <iostream>
using namespace std;
#include <cstring>

/*
 * 函数指针底层原理
 *
 * void func(){};
 * 调用： func();或(&func)()      -->> func 或 &func 是定位到函数对应的地址， ()代表执行其对应的代码
 *
 * 因此， 函数名就是一个隐式的指针，即函数名在程序里面，就是函数指针的一个别名。
 *
 *
 *
 *
 * */


void demo0(){
    // 复习
    int arr[3] = {1, 2, 3};
    int *p3 = arr;
    int (*p4)[3] = &arr;
    cout << p3 << "  " << p4 << endl;

    cout << p4[0] << "  " << p4[1] << endl;     // 步长为  12 = 3*4
    cout << (*p4)[0] << "  " << (*p4)[1] << "  " << (*p4)[2] << endl;
    // cout << (p3 == p4) << endl;      类型不一样，不能比较
}



void func0(){
    cout << " func0 " << endl;
}

void func1(){
    cout << " func1 " << endl;
}

void demo1(){

    void (*p1)() = func0;
    void (*p2)() = &func0;

    //cout << (p1 == p2) << endl;     //1
    cout << (func0 == &func0) << endl;  //1
    //cout << (p2 == func0) << endl;      //1


    func0();
    func1();
    (&func0)();     // func或&func定位到某一个内存地址， ()表示执行其对应的代码块

    void (*p)() = func0;
    cout << sizeof(&func0) << "  " << sizeof(p) << endl;

}


// func == &func 完全等价，所以可以套娃
void demo2(){
    void (*p1)() = func0;
    void (*p2)() = &func0;

    func0();
    (*p1)();
    p1();
    (&func0)();
    (*func0)();
    (**p1)();
    (***p1)();
    (******p2)();
    (*********(&func0))();

    // 爆栈
}



int main() {

//    demo1();
    demo2();
    return 0;
}