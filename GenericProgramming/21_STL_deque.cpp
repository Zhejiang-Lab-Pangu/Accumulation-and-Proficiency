//
// Created by Administrator on 2022/10/18.
//

#include<iostream>
using namespace std;
#include <deque>


// deque 也是线性容器，但连续是假象，分段才是事实；逻辑上连续，物理上相对连续（分段的）


void demo1()
{
    deque<int> d1;
    deque<int> d2;
    d1.assign(4, 2);
    d2.assign(d1.begin(), d1.end());

    deque<int> d3 = d2;
    deque<int> d4{1, 2, 3};

    for(auto it: d3)
    {
        cout << it << "\t";
    }
    cout << d3.size() << "\t" << d4.size() << endl;
    cout << endl;
    d3.swap(d4);
    for(auto it: d4)
    {
        cout << it << "\t";
    }
    cout << d3.size() << "\t" << d4.size() << endl;
    cout << endl;


}


void demo2()
{
    deque<int> d1;
    deque<int> d2{1, 2, 3};
    // max_size 最大可维护
    cout << d1.empty() << "\t" << d1.size() << "\t" << d1.max_size() << endl;
    cout << d2.empty() << "\t" << d2.size() << "\t" << d2.max_size() << endl;

    d2.resize(10);
    for(auto start = d2.begin(); start != d2.end(); start++)
    {
        cout << *start << "\t";
    }
    cout << endl;
    cout << d2.empty() << "\t" << d2.size() << endl;
    cout << d2.front() << "\t" << d2.back() << endl;
}

void demo3()
{
    deque<int> d1;
    deque<int> d2{1, 2, 3};
    d2.push_front(222);
    d2.push_back(111);
    d2.insert(++d2.begin(), 999);
    for(auto &it : d2)
    {
        cout << it << "\t";
    }
    cout << endl;
    d2.pop_back();
    d2.pop_front();
    for(auto &it : d2)
    {
        cout << it << "\t";
    }
    cout << endl;

    d2.erase(d2.begin()+2, d2.end()-1);
    for(auto &it : d2)
    {
        cout << it << "\t";
    }
    cout << endl;
    d2.erase(d2.begin());
    for(auto &it : d2)
    {
        cout << it << "\t";
    }
}



int main()
{
//    demo1();
//    demo2();
    demo3();
    return 0;
}