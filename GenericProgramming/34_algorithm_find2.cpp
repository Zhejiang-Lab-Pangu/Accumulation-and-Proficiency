//
// Created by Administrator on 2022/11/1.
//

#include <iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>


/* 查找相邻重复元素
 * iterator adjacent_find(begin, end)
 *
 *
 * 二分查找
 * bool binary_search(begin, end, val, less<T>)
 *
 * */


class C1
{
public:
    C1(int id, string name) : id(id), name(move(name)){};

    // 重载 ==
    bool operator==(const C1 &c) const
    {
        return (c.id == this->id && c.name == this->name);
    }

    // 重载 <
    bool operator<(const C1 &c1) const
    {
        cout << this->id  << " -- " << c1.id << endl;
        return this->id < c1.id;
    }
    int id;
    string name;
};


// adjacent_find
void demo1()
{
    vector<int> v1{1, 11, 111, 2, 22, 22, 3, 3, 33, 333};
    auto rs1 = adjacent_find(v1.begin(), v1.end());

    if(rs1 == v1.end())
    {
        cout << "no" << endl;
    }
    else
    {
        cout << *rs1 << endl;
    }


    // 自定义类型
    vector<C1> v2{C1(123, "sun"), C1(456, "zhao"), C1(456, "zhao")};
    auto rs2 = adjacent_find(v2.begin(), v2.end());

    if(rs2 == v2.end())
    {
        cout << "no" << endl;
    }
    else
    {
        cout << (*rs2).id << " -- " << (*rs2).name << endl;
    }
}


// binary_search
void demo2()
{
    vector<int> v1{2, 4, 6, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};

    bool rs1 = binary_search(v1.begin(), v1.end(), 4);
    if(!rs1)
    {
        cout << "no" << endl;
    }
    else
    {
        cout << "yes" << endl;
    }

    sort(v1.begin(), v1.end(), greater<int>());
    for(auto item : v1)
    {
        cout << item << "\t";
    }
    cout << endl;

    bool rs2 = binary_search(v1.begin(), v1.end(), 4, greater<int>());
    if(!rs2)
    {
        cout << "no" << endl;
    }
    else
    {
        cout << "yes" << endl;
    }

    // 自定义类型
    vector<C1> v2{C1(123, "sun"), C1(456, "zhao"), C1(678, "li"), C1(1230, "sun"), C1(4560, "zhao"), C1(6780, "li")};
    bool rs3 = binary_search(v2.begin(), v2.end(), C1(456, "zhao"));
    if(!rs3)
    {
        cout << "no" << endl;
    }
    else
    {
        cout << "yes" << endl;
    }
}

int main()
{
    demo1();
    demo2();
    return 0;
}