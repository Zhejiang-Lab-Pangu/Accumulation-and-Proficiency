//
// Created by Administrator on 2022/10/31.
//

#include <iostream>
#include<string>
#include <utility>
#include <vector>
#include <algorithm>
#include<numeric>
using namespace std;


void demo1()
{
    vector<int> v1{1, 0, 9, 2, 3, 4};

    // 返回值为迭代器
    auto rs = find(v1.begin(), v1.end(), 3);
    if(rs != v1.end())
    {
        cout << *rs << endl;
    }
    else
    {
        cout << "no elem" << endl;
    }
}


// find 自定义类型
class C1
{
public:
    C1(int id, string name) : id(id), name(move(name)){};

    // 重载 ==
    bool operator==(const C1 &c) const
    {
        return (c.id == this->id && c.name == this->name);
    }
    int id;
    string name;
};

void demo2()
{
    vector<C1> v1{C1(123, "sun"), C1(456, "zhao")};

    auto rs = find(v1.begin(), v1.end(), C1(456, "zhao"));
    if(rs != v1.end())
    {
        cout << rs->id << "\t" << rs->name << endl;
    }
    else
    {
        cout << "no elem" << endl;
    }
}


// 普通函数对象
typedef struct myFind1
{
    bool operator()(int a)
    {
        return a==3;
    }
} xxx;

// 用适配器
typedef struct myFind2 : public binary_function<int, int, bool>
{
    bool operator()(int a, int b) const
    {
        return a==b;
    }
} yyy;

// 自定义数据类型
typedef struct myFind3
{
    bool operator()(C1 & c) const
    {
        return (c.id == 123 && c.name == "sun");
    }
} zzz;

// 自定义数据类型+适配器
typedef struct myFind4 : public binary_function<C1, C1, bool>
{
    bool operator()(const C1 & c1, const C1 & c2) const
    {
        return (c1.id == c2.id && c1.name == c2.name);
    }
} uuu;

//find_if
void demo3()
{
    vector<int> v1{1, 0, 9, 2, 3, 4};

    // 返回值为迭代器
    auto rs = find_if(v1.begin(), v1.end(), xxx());
    if(rs != v1.end())
    {
        cout << *rs << endl;
    }
    else
    {
        cout << "no elem" << endl;
    }

    // 适配器调用
    auto rs1 = find_if(v1.begin(), v1.end(), bind2nd(yyy(), 33));
    if(rs1 != v1.end())
    {
        cout << *rs1 << endl;
    }
    else
    {
        cout << "no elem" << endl;
    }

    // 自定义数据类型
    vector<C1> v3{C1(123, "sun"), C1(456, "zhao")};

    auto rs3 = find_if(v3.begin(), v3.end(), zzz());
    if(rs3 != v3.end())
    {
        cout << rs3->id << "\t" << rs3->name << endl;
    }
    else
    {
        cout << "no elem" << endl;
    }

    // 自定义数据类型， 加适配器

    auto rs4 = find_if(v3.begin(), v3.end(), bind2nd(uuu(), C1(456, "zhao")));
    if(rs4 != v3.end())
    {
        cout << rs4->id << "\t" << rs4->name << endl;
    }
    else
    {
        cout << "no elem" << endl;
    }
}

int main()
{
    demo1();
    demo2();
    demo3();
    return 0;
}