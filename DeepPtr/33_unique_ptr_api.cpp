//
// Created by Administrator on 2023/9/22.
//
#include <iostream>
using namespace std;
#include <memory>

/*
 * unique_ptr的常用操作
 *
 * (1) get() 返回裸指针
 * (2)  = nullptr;  置空，将内存空间销毁
 * (3) reset()
 *            无参    置空
 *            有参    原空间销毁，指向新地址
 *
 * (4) release() 返回裸指针，并将unique_ptr置为空，即此处的unique_ptr不再维护原空间
 * (5) swap()
 *
 * */

void demo0(){

     unique_ptr<int> p1(make_unique<int>(123));
     int *tmp = p1.get();

     cout << *tmp << "  " << *p1 << endl;

     // delete p1; 非法

     p1 = nullptr;

    unique_ptr<int> p2 = make_unique<int>(456);

    p2.reset();
    cout << (p2 == nullptr) << endl;

    unique_ptr<int> p3 = make_unique<int>(789);
    cout << *p3 << endl;
    p3.reset(new int(444));
    cout << *p3 << endl;

    // p3.reset(make_unique<int>(444)); 不合法


    unique_ptr<int> p4 = make_unique<int>(111);
    cout << p4.get() << endl;

//    int * t = p4.release();

    cout << (p4 == nullptr) << endl;
//    cout << (*t) << endl;

    unique_ptr<int> p5(p4.release());
    cout << p5.get() <<endl;


    unique_ptr<int> s1(new int(100));
    unique_ptr<int> s2(make_unique<int>(200));
    cout << s1.get() << "  " << *s1 << "\t\t " << s2.get() << "  " << *s2 << endl;

    swap(s1, s2);
    cout << s1.get() << "  " << *s1 << "\t\t " << s2.get() << "  " << *s2 << endl;
}

class T{
public:
    T(){cout << " construct " << endl;}
    ~T(){cout << " deconstruct " << endl;}
};


void demo1(){
    unique_ptr<T[]> p(new T[4]);

}


int main(){
//    demo0();
    demo1();
    return 0;
}