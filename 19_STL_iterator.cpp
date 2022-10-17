//
// Created by Administrator on 2022/10/12.
//

#include <iostream>
using namespace std;
#include <array>
#include <vector>

/*迭代器：  是一种数据类型*/
// 在stl中尽量用迭代器来操作元素，更安全，功能更强大，更方便
// 概念：迭代器是仿指针的类模板，封装了原生指针，是指针概念的一种提升，提供了比指针更高级的行为；迭代器很大程度隔离了容器的底层实现

void demo1()
{
    array<int, 3> arr1{1, 2, 3};
    vector<int> v1{1, 2, 3};

    // 构造
    array<int, 3>::iterator iter1;
    vector<int>::iterator iter2;

    // 赋值: 指向容器中某个位置的元素, 类似指针
    iter1 = arr1.begin();
    iter2 = v1.begin();
}



// end()是指向容器尾元素的下一个位置，指向的并不是一个有效位，而是标志位，也称哨兵位，无法解引用，不能读写，只能判断
void demo2()
{
    vector<int> v1{1, 2, 3};
    vector<int>::iterator start = v1.begin();
    vector<int>::iterator end = v1.end();
    while(start != end)
    {
        cout << *start << endl;
        *start += 10;
        start++;
    }

    for(auto start = v1.begin(); start != v1.end(); start++)
    {
        cout << *start << "\t";
    }
    cout << endl;

    //不论编译是否通过，都是错误，类似野指针
    cout << *end << endl;
    *end=123;
    cout << *end << endl;
}


// const begin/end
void demo3()
{
    vector<int> v1{1, 2, 3};
    vector<int>::const_iterator start = v1.cbegin();
    auto end = v1.cend();
    while(start !=end)
    {
        // *start+=1; const迭代器不能更改指向元素
        cout << *start << endl;
        start += 1;
    }

    // 用const修饰的容器必须用const_iterator来操作
    const vector<int> v2{4, 5, 6};
    //vector<int>::iterator b = v2.begin();
}

// rbegin, rend
void demo4()
{
    vector<int> v1{1, 2, 3};
    vector<int>::reverse_iterator rstart;   // 必须用reverse_iterator来操作
    rstart = v1.rbegin();
    auto rend = v1.rend();
    while(rstart != rend)
    {
        cout << *rstart << endl;
        rstart++;
    }

}

typedef struct ABS
{
    int id=123;
} shj;

void demo5()
{
    shj a, b, c;
    vector<shj>v{a, b, c};
    for(auto & start : v)
    {
        cout << start.id << endl;
    }
}

int main()
{
//    demo1();
//    demo2();
//    demo3();
    demo4();
    demo5();
    return 0;
}