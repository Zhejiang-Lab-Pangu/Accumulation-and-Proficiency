//
// Created by Administrator on 2023/9/14.
//
#include <iostream>
using namespace std;


/*
 * C/C++ 内存分区：
 *              栈区: 局部变量，由程序自己控制，分配和销毁非常快，无法手动管理； 但空间有限，会出现爆栈
 *              堆区: 手动开辟的内存空间，只要不是特别大，一般都能分配成功； malloc和new分配，free和delete释放
 *              常量区
 *              静态区、全局变量区
 *              代码区
 *
 *
 * malloc/free      函数
 * new/delete       运算符
 *
 *
 * new 写法：
 * 1. 指针变量名 = new 类型关键字
 * 2. 指针变量名 = new 类型关键字(初始值)
 * 3. 指针变量名 = new 类型关键字[]       -->> delete[](指针变量名)
 *
 *
 * */



void demo0(){
    // malloc 最严格写法

    int *p = nullptr;
    p = (int*) malloc(sizeof(int) * 99);

    if(p!= nullptr){
        *p = 123;
        cout << p[0] << endl;
        ::free(p);
    }else{
        cout << " malloc error !!! " << endl;
    }

}

void demo1(){

    int *p = new int;
    *p = 123;
    cout << p[0] << endl;
    delete (p);

    int *p1 = new int(123);
    cout << p1[0] << endl;
    delete(p1);

    int *p2 = new int[4];
    p2[0] = 123;
    cout << p2[0]  << endl;
    delete[](p2);
}

int main(){
//    demo0();
    demo1();

    return 0;
}