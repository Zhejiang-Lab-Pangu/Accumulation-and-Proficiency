//
// Created by Administrator on 2022/9/16.
//

#include <iostream>
#include <memory>
using namespace std;
#include <string>

/*shared_ptr: 计数指针/共享指针：可以共享数据
 *① share_ptr创建了一个计数器，且与类对象所指的内存相关联
 *② copy则计数器加1，销毁则计数器减1
 * ③use_count()
 * */


// 1.常量类型的shared_ptr
void demo1()
{
    shared_ptr<int> s1 = make_shared<int>(10);
    shared_ptr<int> s2 = s1;    // s2,s1指向的地址相同
    shared_ptr<int> s3 = s1;
    cout << "value: " << *s1 << "\taddress:" << s1.get() << "\tuse_count: " << s1.use_count() << endl;
    cout << "value: " << *s2 << "\taddress:" << s2.get() << "\tuse_count: " << s2.use_count() << endl;
    cout << "value: " << *s3 << "\taddress:" << s3.get() << "\tuse_count: " << s3.use_count() << endl;
    cout << endl;
    s3 = nullptr;
    cout  << "s1 use_count: " << s1.use_count() << "\ts2 use_count: " << s2.use_count() << "\ts3 use_count: " << s3.use_count() << endl;

}

// 2.自定义类型的shared_ptr
class Cat
{
public:
    Cat()=default;
    Cat(string s): m_s(s)
    {
        cout << "constructor func" << endl;
    }
    void set_m(string k)
    {
        this->m_s = k;
        cout << "set star: " << this->m_s << endl;
    }
    void get_info(){cout << "star: " << this->m_s << endl;}
    ~Cat(){cout << "destructor func" << endl;}
private:
    string m_s;
};

void demo2()
{
    cout << "===========start==============" << endl;
    shared_ptr<Cat> c1 = make_shared<Cat>("sun");
    cout << "use_count: " << c1.use_count() << endl;
    shared_ptr<Cat> c2 = c1;
    shared_ptr<Cat> c3 = c1;
    cout << "use_count:\t c1:" << c1.use_count() << "\tc2:" << c2.use_count() << "\tc3:"  << c3.use_count() << endl;

    c1.reset();
    cout << "use_count:\t c1:" << c1.use_count() << "\tc2:" << c2.use_count() << "\tc3:"  << c3.use_count() << endl;

    cout << "==========end=========="<< endl;
    // 构造和析构始终只执行1次，因为只有一套数据。
}


// 3.shared_ptr和函数
void func3(shared_ptr<Cat> c)
{
    c->get_info();
    c->set_m("li");
    cout << c.use_count() << endl;  // 2 形参共享了一次
}

void func4(const shared_ptr<Cat> & c)
{
    c->get_info();
    c->set_m("li");
    cout << c.use_count() << endl;  // 1
}

void demo3()
{
    // passing by value
    shared_ptr<Cat> c0 = make_shared<Cat>("sun");
    func3(c0);
    c0->get_info();     // 虽然值传递，但共享内存，所以函数作用域下的修改即为全局修改
    cout << c0.use_count() << endl; // 形参的共享指针已被在函数作用域销毁
    c0->set_m("sun");
    cout << "==========end=========="<< endl;

    // pass by reference
    cout << c0.use_count() << endl;
    func4(c0);
    c0->get_info();

    cout << "==========end=========="<< endl;
}


// 4.shared_ptr和unique_ptr
/*① shared_ptr不能转成unique_ptr
 *② unique_ptr可以通过move转成shared_ptr
 * */

auto func5()
{
    unique_ptr<Cat> c = make_unique<Cat>("NIE");
    return c;
}

void demo4()
{
    unique_ptr<Cat> cp1 = make_unique<Cat>("liu");
    shared_ptr<Cat> cp2 = move(cp1);    //cp1用不了了
    cout << "cp2 use_count: " << cp2.use_count() << endl;

    //func返回直接转换
    shared_ptr<Cat> cp3 = func5();
    if(cp3)
    {
        cp3->get_info();
        cout << "cp3 use_count: " << cp3.use_count() << endl;
    }

    cout << "============endl===========" << endl;

}

int main()
{
//    demo1();
//    demo2();
//    demo3();
    demo4();
    return 0;
}