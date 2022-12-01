//
// Created by Administrator on 2022/11/4.
//

#include<iostream>
#include<vector>
using namespace std;
#include <algorithm>
#include <time.h>
#include <random>

/*
 * void random_shuffle(begin, end);
 *
 *
 * void shuffle(begin, end)
 *
 * */


typedef struct MyRand
{
    int operator()(int i)
    {
        return rand()%i;
    }
} xxx;

void demo1()
{
    srand((unsigned int)time(nullptr));   // 随机数种子。 每次传入不同的无符号整型

    vector<int> v1{1, 2, 3, 4, 5};
    random_shuffle(v1.begin(), v1.end(), xxx());

    for(auto & it : v1)
    {
        cout << it << "\t";
    }
    cout << endl;
}

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


// 自定义
void demo2()
{
    vector<C1> v1{C1(1, "zhao"), C1(2, "qian"), C1(3, "sun"), C1(4, "li")};
    random_shuffle(v1.begin(), v1.end(), xxx());
    for(auto & it : v1)
    {
        cout << it.id << "--" << it.name << "\t";
    }
    cout << endl;
}

void demo3()
{
    vector<int> v1{1, 2, 3, 4, 5};
    random_device rd;
    shuffle(v1.begin(), v1.end(), std::default_random_engine(rd()));        // 随机数生成器

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
    demo3();
    return 0;
}