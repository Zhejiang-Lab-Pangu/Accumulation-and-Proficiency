//
// Created by Administrator on 2022/11/7.
//

#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;


/*
 * iterator copy(begin1, end1, begin2)
 *
 * void replace(begin, end, oldVal, newVal)
 *
 * void replace_if(begin, end, func, newVal)
 *
 * 将begin1, end1范围的元素cp到容器2中，从begin2处开始填充，当源容器中的元素等于oldVal时，目标容器中用newVal替换，目标容器使用前需要先确定空间
 * iterator replace_copy(begin1, end1, begin2, oldVal, newVal)
 *
 *
 * iterator replace_copy_if(begin1, end1, begin2, func, newVal)
 *
 * void swap(v1, v2)
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
    vector<int> v2;
    v2.resize(v1.size());
    auto rs = copy(v1.begin(), v1.end(), v2.begin());
    for(auto & it : v2)
    {
        cout << it << "\t";
    }
    cout << endl;
    cout << (rs == v2.end()) << endl;

    // 自定义数据类型
    vector<C1> v3{C1(1, "zhao"), C1(11, "qian"), C1(2, "sun"), C1(22, "li")};
    vector<C1> v4;
    v4.resize(v3.size());
    auto rs2 = copy(v3.begin(), v3.end(), v4.begin());
    for(auto & it : v4)
    {
        cout << it.id << "--" << it.name << "\t";
    }
    cout << endl;
}


void demo2()
{
    vector<int> v1{1, 2, 1, 4, 1};
    replace(v1.begin(), v1.end(), 1, 100);
    for(auto & it : v1)
    {
        cout << it << "\t";
    }
    cout << endl;

    // 自定义数据类型
    vector<C1> v2{C1(1, "zhao"), C1(11, "qian"), C1(2, "sun"), C1(22, "li")};
    replace(v2.begin(), v2.end(), C1(1, "zhao"), C1(521, "ZHU"));
    for(auto & it : v2)
    {
        cout << it.id << "--" << it.name << "\t";
    }
    cout << endl;
}


// 函数对象
typedef struct myCopar
{
    bool operator()(int a)
    {
        return a<=3;
    }
} xxx;

// 函数对象+适配器
typedef struct myCopar1 : public binary_function<int, int, bool>
{
    bool operator()(int a, int b) const
    {
        return a>=b;
    }
} yyy;

void demo3()
{
    vector<int> v1{1, 2, 3, 4, 5};
    replace_if(v1.begin(), v1.end(), xxx (), 100);
    for(auto & it : v1)
    {
        cout << it << "\t";
    }
    cout << endl;

    // 适配器
    replace_if(v1.begin(), v1.end(), bind2nd(yyy(), 5), 300);
    for(auto & it : v1)
    {
        cout << it << "\t";
    }
    cout << endl;

}

void demo4()
{
    vector<int> v1{1, 2, 3, 4, 5};
    vector<int> v2;
    v2.resize(v1.size());
    replace_copy(v1.begin(), v1.end(), v2.begin(),1, 100);
    for(auto & it : v2)
    {
        cout << it << "\t";
    }
    cout << endl;

    // 自定义数据类型
    vector<C1> v3{C1(1, "zhao"), C1(11, "qian"), C1(2, "sun"), C1(22, "li")};
    vector<C1> v4;
    v4.resize(v3.size());
    replace_copy(v3.begin(), v3.end(), v4.begin(), C1(1, "zhao"), C1(521, "ZHU"));
    for(auto & it : v4)
    {
        cout << it.id << "--" << it.name << "\t";
    }
    cout << endl;
}


void demo5()
{
    vector<int> v1{1, 2, 3, 4, 5};
    vector<int> v2{4, 5, 6};

    v1.begin();
    auto start1 = v1.begin();
    auto start2 = v2.begin();

    printf("%p -- %d\n", start1, *start1);
    printf("%p -- %d\n", start2, *start2);

    swap(v1, v2);

    cout << endl;
    auto start3 = v1.begin();
    auto start4 = v2.begin();

    printf("%p -- %d\n", start3, *start3);
    printf("%p -- %d\n", start4, *start4);

}

int main()
{
    demo1();
    demo2();
    demo3();
    demo4();
    demo5();
    return 0;
}