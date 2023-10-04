//
// Created by Administrator on 2023/9/14.
//
#include <iostream>
using namespace std;
#include <cxxabi.h>

/*
 * new 和 delete
 *
 * 1. new在分配空间的时候，还做了初始化操作，就是new一个类的时候，如果有构造函数，则会调用；同理，delete的时候，如果有析构，也会调用。malloc\free则不会
 * 2. 内置数据类型没有构造和析构，所以二者表现一样
 * 3. new [] 和 delete[] 一定成对使用
 * */

class T{
public:
    T(){
        cout << "cccccc" << "  " << "a" << endl;
    }
    ~T(){
        cout << "dddddd" << endl;
    }
};



void demo1(){

    T* p1 = (T*)malloc(sizeof(T));
    ::free(p1);

    cout << "-----------  " << endl;

    T* p2 = new T();
    delete(p2);

    /*
    int *p5 = (int *)malloc(sizeof(int)*4);
    free(p5);
    int *p6 = new int[4];
    delete []p6;
    */

    T* p3 = (T*)malloc(sizeof(T)*4);
    free(p3);

    T *p4 = new T[4]();
    delete [] p4;




}


int main() {

    demo1();


    return 0;
}