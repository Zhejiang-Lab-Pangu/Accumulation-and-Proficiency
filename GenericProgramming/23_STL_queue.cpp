//
// Created by Administrator on 2022/10/18.
//
#include <iostream>
using namespace std;
#include <queue>

void demo1()
{
    queue<int> q1;
    cout << q1.size() << "\t" << q1.empty() << endl;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    queue<int>q2(q1);
    cout << q2.size() << "\t" << q2.empty() << endl;


    deque<int> q3{};
    deque<int> q4={};
    deque<int> q5;
}


void demo2()
{
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);


    cout << q1.back() << endl;
    int size = q1.size();
    for(int i=0; i< size; i++)
    {
        cout << q1.front() << '\t';   // 若容器没有数据会报错
        q1.pop();   // 若容器没有数据会报错
    }
    cout << endl;


    queue<int> q2;

}


int main()
{
    demo1();
    demo2();
    return 0;
}