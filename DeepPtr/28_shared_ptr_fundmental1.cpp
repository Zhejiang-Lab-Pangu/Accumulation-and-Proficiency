//
// Created by Administrator on 2023/9/19.
//
#include <iostream>
using namespace std;
#include <memory>


/*
 * shared_ptr 共享智能指针
 *
 * (1) 所谓共享，就是有别的指针也指向该内存，并有读写操作和销毁的权限;
 * (2) 实现智能管理的原理： 每个shared_ptr 指针变量都会维护一个指向自身指向的那个内存空间的引用计数器，并随时同步更新，可达到与shared_ptr 同步的目的;
 * (3) 引用计数器的增加：
 *                      ① 新建一个新的shared_ptr，并初始化，此时，引用计数为 1
 *                      ② 用上述①中的shared_ptr变量初始化一个新的shared_ptr，则指向同一个内存地址的shared_ptr的引用计数都 加1
 *                      ③ 将shared_ptr 作为一个实参传递到一个函数里面，在函数声明周期内，函数也有操作该内存的权限，且引用计数 加1    ;   但是引用传参不会加1
 *                      ④ 若函数将shared_ptr作为返回值，且有变量接收，则指向对应内存地址的shared_ptr，引用计数 都加1
 * (4) 引用计数器的减少和内存空间的释放：
 *                              当指向内存空间的shared_ptr 不再指向该内存空间的时候，其他指向该空间的shared_ptr的引用计数 都会减1
 *                              当最后一个指向该内存空间的shared_ptr被释放或销毁时，该内存释放
 *
 *
 *
 * 注： 函数的参数若未使用，会被编译器优化掉
 * */


void func1(std::shared_ptr<int> a){
    cout << a.use_count() << endl;
    cout << "func1" << endl;
}

shared_ptr<int> func2(shared_ptr<int> &a){
    return a;
}


void demo0(){

    shared_ptr<int> p1 = make_shared<int> (123);
    shared_ptr<int> p2 = p1;
    shared_ptr<int> p3(p2);

    func1(p1);

    shared_ptr<int> p4 = func2(p1);

    cout << p1.use_count() << "  " << p4.use_count() << endl;


    p1.reset();
    cout << p2.use_count() << "  " << p3.use_count() << endl;
    p2 = make_shared<int> (345);
    cout << p2.use_count() << "  " << p3.use_count() << endl;
}


int main(){
    demo0();
    return 0;

}