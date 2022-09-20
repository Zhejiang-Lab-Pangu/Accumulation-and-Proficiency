//
// Created by Administrator on 2022/9/16.
//

#include <iostream>
#include<memory>
using namespace std;
#include <string>

/*weak_ptr
 * 若A类需要存储其他A类对象的信息，若使用shard_ptr，在释放时会出现循环依赖的问题
 * weak_ptr: 不需要拥有所有权的指针标记同类对象，可解决现循环依赖
 * weak_ptr可通过lock()函数提升为shared_ptr
 * 语法：weak_ptr<> wp(shard_ptr的对象)
 * */

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

    void set_friend(shared_ptr<Cat> c)
    {
        this->m_f=c;
    }
    ~Cat(){cout << "destructor func" << endl;}
private:
    string m_s="sun";
    weak_ptr<Cat> m_f;
};


void demo0()
{
   shared_ptr<Cat> cp1 = make_shared<Cat>("cp1");
   weak_ptr<Cat> wp1(cp1);      // 创建weak_ptr
   cout << "cp1 use_count: " << cp1.use_count() << "\twp1 use_count: " << wp1.use_count() << endl;

   //转化shared_pt
   auto sp2 = wp1.lock();
   sp2->get_info();
   cout << "地址：" << cp1.get() << "\t" << sp2.get() << endl;

   cout << "=======end======="<< endl;
}


// 解决循环依赖
void demo1()
{
    shared_ptr<Cat> cp1 = make_shared<Cat>("CP1");
    shared_ptr<Cat> cp2 = make_shared<Cat>("CP2");

    //循环：cp1,cp2均不能销毁 (换成weak_ptr可以解决)
    cp1->set_friend(cp2);
    cp2->set_friend(cp1);
}

int main()
{
//    demo0();
    demo1();
    return 0;
}