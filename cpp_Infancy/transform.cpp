//
// Created by Administrator on 2022/9/19.
//

/* transform
 * 作用：将函数应用到序列的元素上，并将这个函数返回的值保存到另一个序列中，返回的迭代器指向输出序列所保存的最后一个元素的下一个位置
 * 语法：transform(iterator beg1, iterator end1, iterator beg2, _func)
 * _func: 返回一个可以保存在输出序列中的值
 * */

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

#define Pi 3.1415926

// 1.for each (函数返回值必须时void)
void demo1()
{
    auto print_val = [](int val)
    {
        val = val+10;
        cout << val << "\t";
    };
    vector<int> v1 = {1, 2, 3, 4, 5};
    for_each(v1.begin(), v1.end(), print_val);
}

// 2.transform
void demo2()
{
    auto change_val = [](double val)
    {
        val = val * Pi;
        return val;
    };
    vector<double> v2 = {1.0, 2.0, 3.0, 4.0};
    vector<double> v3;
    v3.resize(v2.size());
    cout << v3.size() << "\t" << v3.capacity() << endl;
    transform(v2.begin(), v2.end(), v3.begin(), change_val);

    auto print_val = [&v3]()
    {
        for(auto it = v3.begin(); it < v3.end(); it++)
        {
            cout << (*it) << "\t";
        }
        cout << endl;
    };
    print_val();
}

int main()
{
    demo1();
//    demo2();
    return 0;
}