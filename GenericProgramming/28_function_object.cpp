//
// Created by Administrator on 2022/10/28.
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/* 函数对象： STL中的仿函数
 *
 * 仿函数：函数对象是一个类。不是一个函数；函数对象重载了()操作符，使类可以像函数一样调用
 *
 * 重载()时，根据参数个数，可分为一元仿函数、二元仿函数
 *
 * 谓词：返回值为bool的仿函数
 * */


/* STL 内置仿函数：
 *  template<class T> T plus<T>     加法
 *  template<class T> T minus<T>     减法
 *  template<class T> T multiplies<T>     乘法
 *  template<class T> T divides<T>     除法
 *  template<class T> T modulus<T>     取模
 *  template<class T> T negate<T>     取反
 *
 *  template<class T> bool equal_to<T>     等于
 *  template<class T> bool not_equal_to<T>     不等于
 *  template<class T> bool greater<T>     大于
 *  template<class T> bool greater_equal<T>     大于等于
 *  template<class T> bool less<T>     小于
 *  template<class T> bool less_equal<T>     小于等于
 *
 *  template<class T> bool logic_and<T>     与
 *  template<class T> bool logic_or<T>     或
 *  template<class T> bool logic_not<T>     非
 * */


template <class T>
struct myComp
{
    bool operator()(const T & a)
    {
        return a<10;
    }
};

void func1()
{
    vector<int> v1{1, 11, 111, 2, 22, 222, 3, 33, 333};
    sort(v1.begin(), v1.end());
    for(auto & it : v1)
    {
        cout << it << "\t";
    }
    cout << endl;


    // 使用内置方法
    sort(v1.begin(), v1.end(), greater<int>());     //greater<int>()函数对象
    for(auto & it : v1)
    {
        cout << it << "\t";
    }
    cout << endl;

    vector<int>::iterator iter = find_if(v1.begin(), v1.end(), myComp<int>());
    if(iter == v1.end())
    {
        cout << "没找到" << endl;
    }
    else
    {
        cout << *iter << endl;
    }
}

void demo1()
{

}

int main()
{
    func1();
    return 0;
}