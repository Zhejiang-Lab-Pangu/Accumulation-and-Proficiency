//
// Created by Administrator on 2022/10/28.
//

#include <iostream>
using namespace std;
#include <vector>
#include<algorithm>



/* 函数对象适配器
 *
 * 当函数对象的参数不够用，可以使用适配器来配置函数对象
 *
 * bind1st; bind2nd将二元函数配置成一元函数
 *
 * not1: 构造一个与谓词结果相反的一元函数对象
 * not2: 构造一个与谓词结果相反的二元函数对象
 *
 * */


typedef struct myPrint {
    void operator()(int a)
    {
        cout << a<< "----";
    }
} xxx;


// 适配器
// binary_function<参数1, 参数2, 返回类型> 将二元变一元
typedef struct myPrint1 : public binary_function<int, int, void>
{
    void operator()(int a, int b) const
    {
        cout << a << "--" << b  << "-- "<< a* b << "\t";
    }
} yyy;


void func1()
{
    vector<int> v1{1, 2, 3, 4};
    for_each(v1.begin(), v1.end(), xxx());

    cout<< endl;

    // 适配器调用
    for_each(v1.begin(), v1.end(), bind2nd(yyy(), 10));
    cout<<endl;
    for_each(v1.begin(), v1.end(), bind1st(yyy(), 10));
    // bind1st和bind2nd的区别在于参数占位不一样
    cout << endl;
}


// 一元谓词
typedef struct myFind
{
    bool operator()(int a)
    {
        return a>1000;
    }
} zzz;


typedef struct myFind1 : public unary_function<int, bool>
{
    bool operator()(int a) const
    {
        return a>1000;
    }
} uuu;

void func2()
{
    vector<int> v1{1, 11, 111, 2, 22, 22, 2222, 3, 33, 333, 3333};

    auto rs1 = find_if(v1.begin(), v1.end(), zzz());
    if(rs1 == v1.end())
    {
        cout << "no" << endl;
    }else
    {
        cout << *rs1 << endl;
    }

    // 一元谓词取反
    auto rs2 = find_if(v1.begin(), v1.end(), not1(uuu()));
    if(rs2 == v1.end())
    {
        cout << "no" << endl;
    }else
    {
        cout << *rs2 << endl;
    }
}


// 二元谓词
typedef struct mySort
{
    bool operator()(int a, int b)
    {
        return a>b;
    }
} vvv;

typedef  struct mySort1: public binary_function<int, int, bool>
{
    bool operator()(int a, int b) const
    {
        return a>b;
    }
} www;

void func3()
{
    vector<int> v1{1, 11, 111, 2, 22, 22, 2222, 3, 33, 333, 3333};
    sort(v1.begin(), v1.end(), vvv());
    for_each(v1.begin(), v1.end(), xxx());
    cout << endl;
    // 二元谓词取反
    sort(v1.begin(), v1.end(), not2(www()));
    for_each(v1.begin(), v1.end(), xxx());
    cout << endl;
}


int main()
{
    func1();
    cout << "=================================" << endl;
    func2();
    cout << "=================================" << endl;
    func3();
    return 0;
}