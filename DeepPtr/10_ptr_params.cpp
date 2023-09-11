//
// Created by Administrator on 2023/9/8.
//
#include <iostream>
using namespace std;


/*
 * 指针作为函数参数
 *
 * 数组做函数参数
 *
 * 指针做函数返回值（使用了以销毁的内存地址 -->> 野指针）
 * */



// 1.指针作为函数参数
void func1(int x, int y){
    int z = x;
    x = y;
    y = z;
}

void func1(int *x, int *y){
    int z = *x;
    *x = *y;
    *y = z;
}


void demo1(){

    int a = 11;
    int b = 22;
    int c = 33;

    cout << a << "  " << b << endl;
    func1(a, b);
    cout << a << "  " << b << endl;
    func1(&a, &b);
    cout << a << "  " << b << endl;
}



// 2.数组做函数参数
void func2(int a[4]){       //  int *a ;    a[0] == (a+0)
    cout << sizeof(a) << "  " << sizeof(a[0]) << "  " << sizeof(a)/ sizeof(a[0]) << endl;
}

void func2(int *a, int size){

    for(int i=0; i<size; i++){
        cout << *(a+i) << "  ";
    }
    cout << endl;
}


void demo2(){
    int a[4] = {11, 22, 33, 44};
    cout << sizeof(a) << "  " << sizeof(a[0]) << "  " << sizeof(a)/ sizeof(a[0]) << endl;

    func2(a);

    func2(a, sizeof(a)/ sizeof(a[0]));
}



// 3. 指针做函数返回值（使用了以销毁的内存地址 -->> 野指针）
int *func3(){
    int a =123;
    return &a;
}

int a ;
int *func4(){
    a = 123;
    return &a;
}


void demo3(){
    int *p = func3();   //野指针， 使用了以销毁的内存地址
//    cout << p << "  " << *p << endl;

    int *p2 = func4();  // 全局变量的地址
    cout << p2 << "  " << *p2 << endl;

}



int main(){

//    demo1();
//    demo2();
    demo3();
    return 0;
}
