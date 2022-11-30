//
// Created by Administrator on 2022/11/3.
//

#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<algorithm>


/*
 *
 * int count(begin, end, val);
 *
 * int count(begin, end, func);
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

    int id;
    string name;
};

void demo1()
{
    vector<int> v1{1, 11, 111, 2, 22, 222, 111, 11, 1};
    int rs1 = count(v1.begin(), v1.end(), 22);
    cout << rs1 << endl;

    vector<C1> v2{C1(123, "sun"), C1(456, "zhao"), C1(456, "zhao"), C1(456, "li")};
    int rs2 = count(v2.begin(), v2.end(), C1(456, "zhao"));
    cout << rs2 << endl;
}


typedef struct MyCount
{
    bool operator()(int a)
    {
        return a==11;
    }
} xxx;


// 适配器
typedef struct MyCount1 : public unary_function<int, bool>
{
    bool operator()(int a) const
    {
        return a==11;
    }
} yyy;


typedef struct MyCount2
{
    bool operator()(const C1 & a)
    {
        return (a.id == 456 && a.name == "zhao");
    }
} zzz;

typedef struct MyCount3: public binary_function<C1, C1, bool>
{
    bool operator()(const C1 & a, const C1 & b) const
    {
        return (a.id == b.id && a.name == b.name);
    }
} uuu;

void demo2()
{
    vector<int> v1{1, 11, 111, 2, 22, 222, 111, 11, 1};
    int rs1 = count_if(v1.begin(), v1.end(), xxx());
    cout << rs1 << endl;

    int rs2 = count_if(v1.begin(), v1.end(), not1(yyy()));
    cout << rs2 << endl;


    vector<C1> v2{C1(123, "sun"), C1(456, "zhao"), C1(456, "zhao"), C1(456, "li")};
    int rs3 = count_if(v2.begin(), v2.end(), zzz());
    cout << rs3 << endl;

    int rs4;
    rs4 = count_if(v2.begin(), v2.end(), bind2nd(uuu(), C1(456, "zhao")));
    cout << rs4 << endl;
}

int main()
{
    demo1();
    demo2();
    return 0;
}