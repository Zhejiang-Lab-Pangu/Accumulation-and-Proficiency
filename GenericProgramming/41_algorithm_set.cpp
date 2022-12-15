//
// Created by Administrator on 2022/11/7.
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
 * 交集   原容器元素都必须是有序的，且排序规则一致， 目标容器使用前要分配空间
 * iterator set_intersection(begin1, end1, begin2, end2, begin3, func);
 *
 *
 * 并集   原容器元素都必须是有序的，且排序规则一致， 目标容器使用前要分配空间
 * iterator set_union(begin1, end1, begin2, end2, begin3, func);
 *
 * 差集   原容器元素都必须是有序的，且排序规则一致， 目标容器使用前要分配空间
 * iterator set_difference(begin1, end1, begin2, end2, begin3, func);
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



void demo1()
{
    vector<int> v1{1, 2, 3, 4, 5};
    vector<int> v2{3, 4, 5, 5, 7};
    vector<int> v3;
    v3.resize(min(v1.size(), v2.size()));

    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

    for(auto & it : v3)
    {
        cout << it << "\t";
    }
    cout << endl;

}

void demo2()
{
    // 自定义数据类型
    vector<C1> v1{C1(1, "zhao"), C1(2, "qian"), C1(3, "sun"), C1(4, "li")};
    vector<C1> v2{C1(3, "sun"), C1(4, "li"), C1(5, "zhou"), C1(6, "wu")};
    vector<C1> v3;
    v3.resize(min(v1.size(), v2.size()));
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
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