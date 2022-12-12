//
// Created by Administrator on 2022/11/4.
//

#include <iostream>
#include<vector>
#include <algorithm>
#include <random>
using namespace std;

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

// 函数对象适配器
typedef struct MySort: public binary_function<C1, C1, bool>
{
    // 二元谓词
    bool operator()(const C1 & c1, const C1 & c2) const
    {
        return c1.id < c2.id;
    }
} yyy;


void demo1()
{
    vector<int> v1{1, 11, 111, 2, 22, 222};
    sort(v1.begin(), v1.end());

    for(auto & it: v1)
    {
        cout << it << "\t";
    }
    cout << endl;

    // 自定义数据类型
    vector<C1> v2{C1(1, "zhao"), C1(11, "qian"), C1(2, "sun"), C1(22, "li")};
    sort(v2.begin(), v2.end());

    for(auto & it: v2)
    {
        cout << it.id << "--" << it.name << "\t";
    }
    cout << endl;


    random_device rd;
    shuffle(v1.begin(), v1.end(), default_random_engine(rd()));
    for(auto & it: v1)
    {
        cout << it << "\t";
    }
    cout << endl;


    // 适配器调用
    vector<C1> v4{C1(122, "zhao"), C1(11, "qian"), C1(24, "sun"), C1(22, "li")};
    sort(v4.begin(), v4.end(), not2(yyy()));

    for(auto & it: v4)
    {
        cout << it.id << "--" << it.name << "\t";
    }
    cout << endl;
}


// reverse
void demo2()
{
    vector<int> v1{1, 11, 111, 2, 22, 222};
    reverse(v1.begin(), v1.end());

    for(auto & it: v1)
    {
        cout << it << "\t";
    }
    cout << endl;


    // 自定义数据类型
    vector<C1> v2{C1(1, "zhao"), C1(11, "qian"), C1(2, "sun"), C1(22, "li")};
    reverse(v2.begin(), v2.end());

    for(auto & it: v2)
    {
        cout << it.id << "--" << it.name << "\t";
    }
    cout << endl;
}

int main()
{
    demo1();
    cout << endl;
    demo2();
    return 0;
}