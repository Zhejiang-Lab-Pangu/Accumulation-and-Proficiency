//
// Created by Administrator on 2023/8/31.
//
//
// Created by Administrator on 2023/8/29.
//
#include <iostream>
using namespace std;


/*
 * 万能指针（void ptr）
 *
 * 1.不能直接解引用；需要强转指针类型，再解引用
 *
 * */



void demo1(){

    int *p0 = new int(4);
    bool *p1 = new bool(false);

//    int *p3 = p1;
    void *p3 = p1;

    cout << p0<< endl;
    cout << p1 << endl;
    cout << p3 << endl;
    p3 = p0;

    cout << *p1 << endl; //4
    // cout << *p3 << endl;     // 'void*' is not a pointer-to-object type(void 长度不定)
    cout << *(int*)p3 << endl;      // 先强转指针类型
    *(int*)p3 = 123;
    cout << *p0 << endl;
    cout << *(int*)p3 << endl;


    cout << sizeof(int) << endl;    // 4
    // cout << sizeof(void) << endl;   // 取不了
}


int main(){

    demo1();
    return 0;
}