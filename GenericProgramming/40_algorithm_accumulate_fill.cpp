//
// Created by Administrator on 2022/11/7.
//


#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
#include <numeric>

/*
 * 算术生成算法
 * #include<numeric>
 * T accumulate(begin, end, val, func);
 *
 *
 *
 * 填充
 * fill(begin, end, Val)
 * */

void demo1()
{
    vector<int> v1{1, 2, 3, 4, 5};
    auto rs1 = accumulate(v1.begin(), v1.end(), 0);     //0+1+2+3+4+5
    cout << rs1 << endl;

    auto rs2 = accumulate(v1.begin(), v1.end(), 0, minus<int>());
    cout << rs2 << endl;

    auto rs3 = accumulate(v1.begin(), v1.end(), 1, multiplies<int>());
    cout << rs3 << endl;

    auto rs4 = accumulate(v1.begin(), v1.end(), 1200, divides<int>());
    cout << rs4 << endl;

    auto rs5 = accumulate(v1.begin(), v1.end(), 122, modulus<int>());  // 取模
    cout << rs5 << endl;

//    auto rs6 = accumulate(v1.begin(), v1.begin()+1, 122, negate<int>());  // 取反
//    cout << rs6 << endl;
}


void demo2()
{
    vector<int> v1;
    v1.resize(10);
    fill(v1.begin(), v1.end(), 100);
    for(auto & it : v1)
    {
        cout << it << "\t";
    }
    cout << endl;
}

int main()
{
    demo1();
    demo2();
    return 0;
}