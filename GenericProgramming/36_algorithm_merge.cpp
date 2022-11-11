//
// Created by Administrator on 2022/11/4.
//

#include <iostream>
#include<vector>
#include <string>
#include <algorithm>
using namespace std;


/*
 * iterator merge(begin1, end1, begin2, end2, begin3, func)
 *
 * */


class C1
{
public:
    C1() =default;
    C1(int id, string name) : id(id), name(move(name)){};

    // 重载 ==
    bool operator==(const C1 &c) const
    {
        return (c.id == this->id && c.name == this->name);
    }

    bool operator<(const C1 & c) const
    {
        return (c.id > this->id);
    }

    int id{};
    string name;
};


// 函数对象
typedef struct myComp
{
    bool operator()(const C1 & c1, const C1 & c2)
    {
        return (c1.id < c2.id);
    }
} xxx;

void demo1()
{
    vector<int> v1{1, 2, 3, 4};
    vector<int> v2{3, 4, 5, 6};
    vector<int> v3;
    v3.resize(v1.size()+v2.size());

//    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin(), greater<int>());

    for(auto & it : v3)
    {
        cout << it << "\t";
    }
    cout << endl;
}


// 自定义
void demo2()
{
    vector<C1> v1{C1(1, "zhao"), C1(2, "qian"), C1(3, "sun"), C1(4, "li")};
    vector<C1> v2{C1(3, "sun"), C1(4, "li"),  C1(5, "zhou"),  C1(6, "wu")};
    vector<C1> v3;
    v3.resize(v1.size()+v2.size());

//    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin(), xxx());     // 函数对象
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());          // 自定义类型重载比较方法

    for(auto & it : v3)
    {
        cout << it.id << "--" << it.name << "\t";
    }
    cout << endl;
}

int main()
{
    demo1();
    demo2();
    return 0;
}