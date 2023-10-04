//
// Created by Administrator on 2023/9/20.
//
#include <iostream>
using namespace std;
#include <memory>


/*
 * shared_ptr 删除器
 *
 * 自定义删除器：
 *          make_shared 不支持
 *
 *
 * */


void func0(const int *p){
    cout << "this is deleteor" << endl;
    delete p;
}

void func1(const int *p){
    cout << " 222222" << endl;
    delete p;
}


void demo0(){

    shared_ptr<int> p(new int(123), func0);
    cout << "------------------------------" << endl;
    shared_ptr<int> p1(new int(345), func1);
    p1 = p;

    shared_ptr<int> p2(new int(789), [](const int *p){
        cout << " 3333 " << endl;
        delete p;
    });

    auto lambda = [](const int *p){
        cout << " 444 " << endl;
        delete p;
    };
    shared_ptr<int> p3(new int(111), lambda);       // 销毁顺序： 栈机，先进后出

}


class T{
public:
    T(){
        cout << "construct" << endl;
    }
    ~T(){
        cout << "deconstruct" << endl;
    }
};

void demo1(){

    int *p = new int[4];
    delete [] p;

    T *pt = new T[4];
    delete [] pt;


}


void demo2(){
    // shared_ptr<T> p1(new T[4]);     // 只会调用一次析构，程序报错
    shared_ptr<T> p1(new T[4], [](const T* t){
        delete [] t;
    });

    shared_ptr<T> p2(new T[2], default_delete<T[]>());

    shared_ptr<T[]> p3(new T[3]);
}

int main(){
//    demo0();
//    demo1();
    demo2();
    return 0;
}