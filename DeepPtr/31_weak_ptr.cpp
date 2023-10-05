//
// Created by Administrator on 2023/9/20.
//
#include <iostream>
#include <memory>
using namespace std;


/*
 * shared_ptr     strong
 * weak_ptr       weak
 *
 * 1. weak_ptr 不能用裸指针初始化,可用make_shared初始化，但无任何意义（因为不能直接用weak_ptr操作其内存空间，必须依附于shared_ptr）
 *
 * 2.当一个shared_ptr新增一个weak_ptr时，其weak_ptr 计数器会加1，当销毁一个weak_ptr时，其weak_ptr 引用计数减1
 *
 * 3. 不能直接使用weak_ptr去操作指向的内存；当一个shared_ptr销毁时，指向其的weak_ptr会过期(expired)；
 *
 * 4. lock();       返回值为shared_ptr,      增加一个shared_ptr 计数器
 *
 * 5. expired();    当其对应的shared_ptr销毁，返回true
 *
 * 6. reset();      其他指针的弱引用减1，该指针变为空指针
 * */



void demo0(){

    shared_ptr<int> p1(new int(123));

    //weak_ptr<int> p2(new int(123));


    weak_ptr<int> p3(make_shared<int>(456));
    weak_ptr<int> p4 = make_shared<int>(789);
    weak_ptr<int> p5;


    weak_ptr<int> p6(p1);
    cout << p6.use_count() << "  " << p1.use_count()<< endl;
    weak_ptr<int> p7 = p6;

    p7.reset();
    p1.reset();

    cout << p6.expired() << endl;



}


// 用法和api
void demo1(){
    shared_ptr<int> p1(new int(123));
    weak_ptr<int> p2(p1);

    shared_ptr<int> p3 = p2.lock();     // 增加一个shared_ptr 计数器

    *p3 = 456;
    cout << *p1 << endl;


    cout << p1.use_count() << "   " << p2.use_count() << "  " << p3.use_count() << endl;

}


int main(){
    demo0();
    demo1();
    return 0;
}