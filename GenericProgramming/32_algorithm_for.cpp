//
// Created by Administrator on 2022/10/31.
//

#include <iostream>
#include <vector>
#include <functional>       // 函数对象
#include <algorithm>        // 算法
#include <numeric>          // 算法补充
using namespace std;
#include <memory.h>



typedef struct MyPrint1
{
    void operator()(int a)
    {
        cout << a << " -- ";
        m++;
    }
    int m = 0;
} xxx;

typedef struct MyPrint2
{
    int operator()(int a)
    {
        return a * 100;
    }

} yyy;


typedef struct MyPrint3
{
    int operator()(int a, int b)
    {
        return a * b;
    }

} zzz;


// for_each(begin, end, callback)
void demo1()
{
    vector v1{1, 2, 3, 4};

    // 返回值为函数对象
    xxx rs;
    rs = for_each(v1.begin(), v1.end(), xxx());
    cout << endl;
    cout << rs.m << endl;
}


// transform: 将指定容器区间元素搬运到另一容器中， 必须给目标容器提前分配内存
void demo2()
{
    vector<int> v1{1, 2, 3, 4};
    vector<int> v2;
    v2.resize(v1.size());

    for(auto start = v2.begin(); start != v2.end(); start++)
    {
        cout << * start << '\t';
    }
    cout << endl;

    // 返回值为v2对应位置的迭代器
    auto rs = transform(v1.begin(), v1.end(), v2.begin(), yyy());
    cout << (rs == v2.end()) << endl;

    for(auto start = v2.begin(); start != v2.end(); start++)
    {
        cout << * start << '\t';
    }
    cout << endl;
    for(auto start = v1.begin(); start != v1.end(); start++)
    {
        cout << * start << '\t';
    }
    cout << endl;
}


// transform: 将两个指定容器的元素搬运到第三个容器
void demo3()
{
    vector<int> v1{1, 2, 3, 4, 5};
    vector<int> v2{10, 20, 30, 40, 50};
    vector<int> v3;
    v3.resize(5);

    for(auto & item : v3)
    {
        cout << item << "\t";
    }
    cout <<endl;

    auto it = transform(v1.begin()+2, v1.end(), v2.begin()+2, v3.begin(), zzz());
    cout << (it == v3.end() -2) << endl;


    for(auto & item : v3)
    {
        cout << item << "\t";
    }
    cout <<endl;
}


int main()
{
    demo1();
    demo2();
    demo3();
    return 0;
}