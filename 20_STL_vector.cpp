//
// Created by Administrator on 2022/10/13.
//

#include <iostream>
#include <cstdio>
using namespace std;
#include <array>
#include <vector>

/* vector: 不定长容器，容器空间大小可以动态改变；其元素的空间地址是连续的，可看成动态数组
 * vector扩容规则：开辟新的空间，将原来的数据copy过来，并追加新元素，再将原来的空间销毁（所有连续空间的动态扩容都是如此）
 *
 *
 * vector当从中间位置删除元素时，后续元素前移，后续的空内存保留
 * vector 扩容、删除、插入元素的过程特别耗费资源，效率低；可用reserve缓解
 * */


void demo1()
{
    vector<int> v1{};

    for(int i=0; i<5; i++)
    {
        cout << v1.size() << "\t" << v1.capacity() << endl;
        v1.push_back(i);
    }
    /*
     *   0	0
     *   1	1
     *   2	2
     *   3	4
     *   4	4
     *   5	8
     *   6	8
     *   7	8
     *   8	8
     *   9	16
     * */

    for (int & it : v1)
    {
        cout << &it <<endl;
    }

}


// 缩减, 插入
void demo2()
{
    vector<int> v1{1, 2, 3, 4, 5, 6};
    cout << v1.size() << "\t" << v1.capacity() << endl;
    for(auto &it:v1)
    {
        printf("%d -- %p\n", it, &it);
    }

    v1.erase(v1.begin()+2, v1.begin()+4);
    cout << v1.size() << "\t" << v1.capacity() << endl;
    for(auto &it:v1)
    {
        printf("%d -- %p\n", it, &it);
    }

    v1.insert(v1.begin()+2, 111);
    v1.insert(v1.begin()+2, 111);
    v1.insert(v1.begin()+2, 111);
    cout << v1.size() << "\t" << v1.capacity() << endl;
    for(auto &it:v1)
    {
        printf("%d -- %p\n", it, &it);
    }

    vector<int> v2{};
    cout << v2.size() << "\t" << v2.capacity() << endl;
    v2.reserve(10);
    cout << v2.size() << "\t" << v2.capacity() << endl;
}


// 构造、赋值、swap
void demo3()
{
    vector<int> v1(4, 2);
    vector<int> v2(v1.begin(), v1.end());
    vector<int> v3(v2);

    vector<int> v4 = {v2};
    vector<int> v5 = v4;
    vector<int> v6 = {1, 2, 3};

    cout << v1.size() << "\t" << v1.capacity() << endl;
    swap(v1, v6);   //指针交换
    cout << v1.size() << "\t" << v1.capacity() << endl;
}


// 函数
void demo4()
{
    vector<int> v1{1, 2, 3};
    v1.push_back(1111);
    cout << v1.size() << "\t" << v1.capacity() << endl;

    v1.resize(10);  // 小变大，要扩容
    cout << v1.size() << "\t" << v1.capacity() << endl;
    for(auto it:v1)
    {
        cout << it << endl;
    }

    v1.resize(2);  // 大变小，删除元素，空间不变
    cout << v1.size() << "\t" << v1.capacity() << endl;
    for(auto it:v1)
    {
        cout << it << endl;
    }

}

void demo5()
{
    // 扩容
    vector<int> v1;
    cout << v1.size() << "\t" << v1.capacity() << endl;
    v1.reserve(5);
    cout << v1.size() << "\t" << v1.capacity() << endl;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    cout << v1.front() << "\t" << v1.back() << endl;
    v1.front() = 999;
    v1.back() = 666;
    cout << v1.front() << "\t" << v1.back() << endl;
    v1.pop_back(); // 空间不变
    cout << v1.front() << "\t" << v1.back() << endl;

    v1.clear(); // 删元素，不删空间
    cout << v1.size() << "\t" << v1.capacity() << endl;
}

int main()
{
//    demo1();
//    demo2();
//    demo3();
//    demo4();
    demo5();

    return 0;
}