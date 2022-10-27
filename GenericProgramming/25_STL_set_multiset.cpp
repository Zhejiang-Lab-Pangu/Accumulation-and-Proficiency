//
// Created by Administrator on 2022/10/20.
//

#include <iostream>
using namespace std;
#include <set>
//#include <multiset>


// 底层是红黑树（平行二叉树的一种）

void demo1()
{
    set<int> s1;
    set<int> s2{1, 11, 111, 2, 22, 222};
    set<int> s3{};
    set<int> s4(s2);
    set<int> s5 = s2;

    for(int it : s2)
    {
        cout << it << "\t";
    }
    cout << endl;

    set<int> s6;
    s6 = s5;

    set<int> s7{77, 7777};
    s5.swap(s7);

    cout << *s7.begin();
    for(auto start = s7.begin(); start != s7.end(); start++)
    {
        cout << *start << "\t";
    }
    cout << endl;
}

void demo2()
{
    // insert
    set<int> s1{1, 11, 111, 2, 22, 222};
    s1.insert(4);
    s1.insert(4);   // 再插入之前会find，若存在，直接返回，不会报错；
    for(auto s: s1)
    {
        cout << s << "\t";
    } cout << endl;


    // multiset
    multiset<int> s2{1, 1, 1};
    s2.insert(1);
    s2.insert(1);
    for(auto & s: s2)
    {
        cout << s << "\t";
    } cout << endl;

    // iter  双向迭代器，前后每次只能走一次
    /*iter += 2;*/

    //erase
    s1.erase(1);
    for(auto s: s1)
    {
        cout << s << "\t";
    } cout << endl;

    //find  -->> 返回迭代器
    auto iter = s1.find(222);
    if(iter == s1.end()) // 没找到
    {
        cout << "没找到，返回end()迭代器";
    }
    else
    {
        cout << "*iter: " << *iter << endl;
    }

    // count
    cout << s1.count(22) << endl;



}

void demo3()
{
    set<int> s1 = {1, 2, 3, 4};
    pair<set<int>::iterator, set<int>::iterator> rs = s1.equal_range(3);
    auto rs1 = rs.first;
    auto rs2 = rs.second;

    if(rs1 == s1.end())
    {
        cout << "no" << endl;
    }else
    {cout << *rs1 << endl;}
    if(rs2 == s1.end())
    {
        cout << "no" << endl;
    }else{cout << *rs2 << endl;}
}


class C1
{
public:
    C1(int id, int age): m_age(age), m_id(id){}
    int m_id;
    int m_age;
};

typedef struct sortById {
    bool operator()(const C1 & a, const C1 & b)
    {
        return a.m_id < b.m_id;
    }
} sortById;

void demo4()
{
    set<C1, sortById> s1{C1(1, 11), C1(2, 22), C1(3, 333), C1(4, 44444)};

    for(auto start : s1)
    {
        cout << start.m_id << endl;
    }
}

int main()
{
//    demo1();
//    demo2();
//    demo3();
    demo4();
    return 0;
}