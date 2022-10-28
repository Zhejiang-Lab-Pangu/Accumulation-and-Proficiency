//
// Created by Administrator on 2022/10/18.
//

#include<iostream>
using namespace std;
#include <stack>

// stack

void demo1()
{
    stack<int> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    stack<int> s2 =s1;
    stack<int> s3;

    cout << s2.empty() << "\t" << s2.size() << endl;
    cout << s3.empty() << "\t" << s3.size() << endl;
}

void demo2()
{
    stack<int> s1{};
    stack<int> s2={};
    s2.push(1);
    s2.push(2);
    s2.push(3);
    stack<int> s3{s2};

    s2.emplace(4);

    // tops
    cout << s2.top() << endl;   // 只读取不删除
    //cout << s1.top() << endl;   // 空栈报错

    // pop
    s2.pop();
    cout << s2.top() << endl;

}

int main()
{
//    demo1();
    demo2();
    return 0;
}