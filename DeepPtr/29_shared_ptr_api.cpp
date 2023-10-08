//
// Created by Administrator on 2023/9/19.
//
#include <iostream>
using namespace std;
#include <memory>

/*
 * shared_ptr 的常用操作
 *
 * (1) use_count()  变量所指向内存空间的引用次数
 * (2) unique()     shared_ptr是否是独占其指向的内存地址： 若只有一个shared_ptr指向，则为true；若有其他指向，或者为空指针，则为false;
 * (3) reset()      重置
 *                          无参： 如果独占，则释放内存空间，并将shared_ptr置为空指针; 如果不是独占，则将其他指向该内存的shared_ptr变量的引用计数减1，并将当前shared_ptr变量置为空指针;
 *                          有参： 如果独占，则释放内存空间，并将当前shared_ptr指向参数的新内存地址; 如果不是独占，则将其他指向该内存的shared_ptr变量的引用计数减1，并将当前shared_ptr指向参数的新内存地址,引用计数为1;
 * (4) get()        取指针地址
 * (5) swap()       交换两指针的指向
 *
 * */


void demo0(){

    // 1. use_count()   2. unique()
    shared_ptr<int> p1(make_shared<int>(123));
    cout << p1.use_count() << endl;
    cout << p1.unique() << endl;

    shared_ptr<int> p2(p1);
    cout << p1.use_count() << "  " << p2.use_count() << endl;
    cout << p1.unique() << endl;

    shared_ptr<int> p3;
    cout << p3.unique() << endl;


}


// reset()
void demo1(){

    // 无参
    shared_ptr<int> p1 = make_shared<int>(123);
    p1.reset();
    cout << p1.use_count() << "  " << p1.unique() << endl;


    shared_ptr<int> p2 = make_shared<int>(143);
    shared_ptr<int> p3(p2);
    p2.reset();
    cout << p2.use_count() << "  " << p2.unique() << endl;
    cout << p3.use_count() << "  " << p3.unique() << endl;

    cout << " ==================" << endl;

    // 有参

    shared_ptr<int> p4 = make_shared<int>(443);
    cout << p4 << endl;
    p4.reset(new int(456));
    cout << p4.unique() << "  " << p4.use_count() << endl;
    cout << p4 << endl;

    shared_ptr<int> p5 = make_shared<int>(443);
    shared_ptr<int> p6(p5);
    cout << p5 << "  " << p6 << endl;
    p5.reset(new int(444));
    cout << p5.unique() << "  " << p5.use_count() << endl;
    cout << p6.unique() << "  " << p6.use_count() << endl;
    cout << p5 << "  " << p6 << endl;
}


//get
void demo2(){

    shared_ptr<int> p1 = make_shared<int>( 234);
    cout << p1 << "  " << *p1 <<  endl;

    int * p = p1.get();
    cout << p << "  " << *p<< endl;
}


//swap
void demo3(){

    shared_ptr<int> p1 = make_shared<int>( 234);
    shared_ptr<int> p2 = make_shared<int>(111);
    cout << p1 << "  " << *p1 << "  " << p2 << "  " << *p2 << endl;
    swap(p1, p2);       // p1.swap(p2);
    cout << p1 << "  " << *p1 << "  " << p2 << "  " << *p2 << endl;
}

int main(){

//    demo0();
//    demo1();
//    demo2();
    demo3();
    return 0;
}