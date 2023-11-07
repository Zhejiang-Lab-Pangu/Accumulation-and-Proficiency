//
// Created by Administrator on 2022/9/16.
//

/*智能指针：unique_ptr:独占的智能指针
 *
 *
 * */

#include <iostream>
#include <memory>
using namespace std;


class Sky
{
public:
    Sky()=default;
    Sky(int k):colude(k){cout << "parameters constructor" << endl;};
    void set_cloud(int c)
    {
        this->colude = c;
        cout << "change cloud: " << this->colude << endl;
    }
    int get_cloud()
    {
        return this->colude;
    }

    ~Sky(){cout << "destructor" << endl;}

private:
    int colude;
};


// 1.raw ptr
void demo1()
{
    Sky * s = new Sky(10);
    cout << s->get_cloud() << endl;
    {
        Sky * s1 = new Sky(20);
        s1->set_cloud(30);
        delete s1;
        s1 = nullptr;
    };
//    delete s1;  // s1 被重复释放
    delete s;   // 栈区内存释放（即调用s对象的析构函数实在程序执行结束，而堆区有delete即释放）
    s = nullptr;
    cout << "============end==========" << endl;
}


// 2.unique_ptr: 语法 -- >> unique_ptr<T> = make_unique<T>()
void demo2()
{
    unique_ptr<Sky> p1 = make_unique<Sky>(11);      // 自动在本作用域所有程序完成后执行析构（内存释放）
    unique_ptr<int> p2 = make_unique<int>(22);
    cout << p1->get_cloud()<< endl;
    p1->set_cloud(110);
    {
        unique_ptr<Sky> p3 = make_unique<Sky>(81);
        cout << p3->get_cloud()<< endl;
        p3->set_cloud(110);
    }

    cout << p1.get() << "\t" << p2.get() << endl;   //取地址
    cout << *p2 << endl;

    // 独占：不可复制，但可move
    // unique_ptr<Sky> p4 = p1; // 非法
    // Sky * p5 = p1;   //非法
    unique_ptr<Sky> p6 = move(p1);
    cout << p6->get_cloud()<< endl;
    p6->set_cloud(44);
    //p1->set_cloud(22);  // p1已转移，不可再用
    {
        unique_ptr<Sky> p7 = make_unique<Sky>(1441);
//        unique_ptr<Sky> p8 = move(p7);
    }
//    unique_ptr<Sky> p9 = move(p7);       // p7已释放

    cout << "==============end===========" << endl;
}

// 3.unique_ptr与函数调用

void func3(unique_ptr<Sky> s)
{
    s->set_cloud(4);
    cout << s->get_cloud() << endl;
}

void func4(const unique_ptr<Sky> & s)
{
    s->set_cloud(56);
    cout << s->get_cloud() << endl;
//    s.reset(); //清空   添加const不允许修改了，会编译报错
}

unique_ptr<Sky> func5()
{
    unique_ptr<Sky> s = make_unique<Sky>(99);
    cout << "unique addres: " << s.get() << endl;
    return s;
}

void demo3()
{
    // ① 值传递 pass by value
    unique_ptr<Sky> s1 = make_unique<Sky>(1111);
//    func3(s1);        不能传递
    func3(move(s1));        // 这样传递析构直接执行
//    s1->set_cloud(12);      // 调用函数指针已被清空；可以编译，执行崩掉

    // ② 引用传递  pass by reference *****************
    unique_ptr<Sky> s2 = make_unique<Sky>(1111);
    cout << s2.get() << endl;
    func4(s2);
    cout << s2.get() << endl;
    s2->set_cloud(33);      // 形参传递建议加const

    // ③链式
    func5()->set_cloud(10000);
    cout << "=========end=============" << endl;
}




int main()
{
//    demo1();
//    demo2();
    demo3();
    return 0;
}