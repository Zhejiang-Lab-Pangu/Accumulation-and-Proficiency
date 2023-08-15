//
// Created by Administrator on 2023/8/14.
//



#include<iostream>
#include <vector>
using namespace std;
#include <cxxabi.h>

/* remove_all_extent
 *
 * 获取数组元素中的具体类型
 *
 * */


void demo1()
{
    int a[2][3]{};
    char b[2][3]{};

    int * c[2][3]{};
    vector<int> d[2][3]{};


    // decltype(a)相当于 int[2][3]
    std::remove_all_extents<decltype(a)>::type t1;
    remove_all_extents<decltype(b)>::type t2;
    remove_all_extents<decltype(c)>::type t3;
    remove_all_extents<decltype(d)>::type t4;


    cout << abi::__cxa_demangle(typeid(t1).name(), 0, 0, 0) << endl;
    cout << abi::__cxa_demangle(typeid(t2).name(), 0, 0, 0) << endl;
    cout << abi::__cxa_demangle(typeid(t3).name(), 0, 0, 0) << endl;
    cout << abi::__cxa_demangle(typeid(t4).name(), 0, 0, 0) << endl;
}


int main()
{
    demo1();
    return 0;
}