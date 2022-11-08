//
// Created by Administrator on 2022/10/27.
//

#include <iostream>
using namespace std;
#include <map>
#include <string>


// map: 所有元素都是pair first:key; second: value
/*
 * multimap: 可以有重复的键值
 * key 不能改； value可以改
 * */

void demo1()
{
    map<int, string> m1{};
    map<int, string> m2{pair<int, string>(1, "aa")}; // pair的临时对象
    map<int, string> m3(m2);
    map<int, string> m4;
    m4 = m2;

    for(auto & it: m4)
    {
        cout << it.first << ":  " << it.second << endl;
    }


}


//insert
void demo2()
{
    map<int, string> m1{};
    m1.insert(pair<int, string>(1, "aaa"));

    m1.insert(map<int, string>::value_type(2, "bbbb"));

    m1.insert(make_pair(3, "ccc"));

    m1[4] = "sun";

    pair<int, string> p1(5, "eee");
    m1.insert(p1);

    for(auto start = m1.begin(); start != m1.end(); start++)
    {
        pair<int, string> tmp = *start;
        cout << tmp.first << ":  " << tmp.second << endl;
    }

    // insert 返回值
    pair<map<int, string>::iterator, bool> rs = m1.insert(pair<int, string>(6, "xxx"));
    cout << rs.second << endl;
    if (!rs.second)
    {
        cout << "插入失败" << endl;
    }
    else
    {
        map<int, string>::iterator first = rs.first;
        cout << first->first << "---" << (*first).second << endl;
    }
}


void demo3()
{
    map<int, string> m1{};
    m1.insert(pair<int, string>(1, "aaa"));

    m1.insert(map<int, string>::value_type(2, "bbbb"));

    m1.insert(make_pair(3, "ccc"));

    m1[4] = "sun";

    pair<int, string> p1(5, "eee");
    m1.insert(p1);
    for(auto & it: m1)
    {
        it.second = "ssss";
    }
    for(auto & it: m1)
    {
        cout << it.first << " --- " << it.second << endl;
    }

}

// 自定排序
typedef struct xxx
{
    bool operator()(const int &a, const int &b) const   // 必须加const
    {
        return a>b;
    }
} x_sort;
void demo4()
{
    map<int, string, x_sort> m1;
    m1.insert(pair<int, string>(1, "aaa"));

    m1.insert(map<int, string>::value_type(2, "bbbb"));

    m1.insert(make_pair(3, "ccc"));

    m1[4] = "sun";

    for(auto & it : m1)
    {
        cout << it.first << "\t" << it.second << endl;
    }
}



int main()
{
//    demo1();
//    demo2();
    demo3();
    demo4();
    return 0;
}