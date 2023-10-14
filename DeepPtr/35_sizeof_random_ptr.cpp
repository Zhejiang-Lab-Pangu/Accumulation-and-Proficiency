//
// Created by Administrator on 2023/9/25.
//



#include <iostream>
using namespace std;
#include <memory>
#include <cxxabi.h>

/*
 * 智能指针的sizeof
 *
 * shared_ptr
 *          存储的时 堆区数据的地址(8B) + 额外的数据的指针地址(8B)
 *          同理，weak_ptr 也是两个裸指针的大小(16 B)
 *
 * unique_ptr [大小变化]
 *          不需要维护额外的数据，所以只要存储 一个指向数据区的指针大小即可 (8B)
 *          若使用 函数自定义删除器，则要维护一些删除器的信息，再加一个裸指针的空间大小(16)
 *          若使用 lambda函数 定义删除器，则为原始指针大小 (8B)
 *
 * */


void func0(int *p){
    delete p;
    p = nullptr;
}


void demo0(){

    int *p0 = new int(3);

    shared_ptr<int> p1(new int(123));
    shared_ptr<int> p2(make_shared<int>(123));
    shared_ptr<int> p3(p2);

    cout << sizeof(p0) << endl;
    cout << sizeof(p1) << "  " << sizeof(p2) << "  " << sizeof(p3) << endl;     // 16


    weak_ptr<int> p6(p2);
    cout << sizeof(p6) << endl;


    unique_ptr<int> p4(new int(222));
    unique_ptr<int> p5(make_unique<int>(222));

    auto lambda = [](int *a){
        delete a;
        a = nullptr;
    };
    unique_ptr<int, decltype(lambda)> p7(new int(99), lambda);

    using type = void(*)(int *);
    unique_ptr<int, type> p8(new int(99), func0);

    cout << sizeof(p4) << "  " << sizeof(p5) << endl;       // 8
    cout << sizeof(p7) << endl;     // 8
    cout << sizeof(p8) << endl;     // 16

    delete p0;
}


void demo1(){

}


int main(){
    demo0();
//    demo1();
    return 0;
}