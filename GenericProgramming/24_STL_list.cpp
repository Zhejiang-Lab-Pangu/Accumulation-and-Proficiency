//
// Created by Administrator on 2022/10/19.
//

#include<iostream>
using namespace std;
#include <list>

// 双向链表


void demo1()
{
    list<int> l1;
    list<int> l2(4, 2);
    list<int> l3(l2.begin(), l2.end());
    list<int> l4(l3);
    list<int> l5 = {1, 2, 3, 4, 5};

    for(auto &i: l5)
    {
        cout << i << "\t";
    }
    cout << endl;

}


void demo2()
{
    list<int> l1;
    list<int> l2 = {1, 2, 3, 4};
    cout << l1.empty() << "\t" << l1.size() << "\t" << l1.max_size() << endl;
    cout << l2.empty() << "\t" << l2.size() << "\t" << l2.max_size() << endl;

    for(auto &i: l2)
    {
        cout << i << "\t";
    }
    cout << endl;
    l2.resize(3);
    for(auto &i: l2)
    {
        cout << i << "\t";
    }
    cout << endl;
    l2.resize(10);
    for(auto &i: l2)
    {
        cout << i << "\t";
    }
    cout << endl;

    cout << l2.front() << "\t" << l2.back() << endl;
    l2.resize(4);

    // push插入
    l2.push_back(111);
    l2.push_front(666);
    for(auto &i: l2)
    {
        cout << i << "\t";
    }
    cout << endl;

    // 删除
    l2.pop_front();
    l2.pop_back();
    for(auto &i: l2)
    {
        cout << i << "\t";
    }
    cout << endl;

    // insert插入
    l2.insert(++l2.begin(), 333);
    for(auto &i: l2)
    {
        cout << i << "\t";
    }
    cout << endl;
    l2.insert(++l2.begin(), 2, -333);
    for(auto &i: l2)
    {
        cout << i << "\t";
    }
    cout << endl;

}


void demo3()
{
    list<int> l1;
    list<int> l2{1, 2, 3, 4};

    cout << l2.size() << endl;
    l2.erase(++l2.begin());
    cout << l2.size() << endl;
    for(auto &x : l2) {cout << x << "\t";}
    cout << endl;

    l2.resize(5);
    for(auto &x : l2) {cout << x << "\t";}
    cout << endl;
    l2.erase(++l2.begin(), --l2.end());
    for(auto &x : l2) {cout << x << "\t";}
    cout << endl;
    l2.clear();
    cout << l2.size()<< endl;

    list<int> l3{1, 1, 1, 12, 2};
    l3.remove(1);
    for(auto &x : l3) {cout << x << "\t";}
    cout << endl;
}


bool my_sort(int a, int b)
{
    return a> b;
}



void demo4()
{
    list<int> l1{2, 4, 6,7, 0};
    l1.reverse();
    for(auto &x : l1) {cout << x << "\t";}
    cout << endl;

    l1.sort();
    for(auto &x : l1) {cout << x << "\t";}
    cout << endl;

    l1.sort(my_sort);
    for(auto &x : l1) {cout << x << "\t";}
    cout << endl;

    auto f = [](int x, int y){return x<y;};
    l1.sort(f);
    for(auto &x : l1) {cout << x << "\t";}
    cout << endl;
}

int main()
{
//    demo1();
//    demo2();
//    demo3();
    demo4();
    return 0;
}