//
// Created by Administrator on 2022/10/11.
//

#include <iostream>
using namespace std;

/*
 * typedef
 *
 * */


// 1.定义类型别名，而不是简单的替换

typedef int* INTP;
#define INTP1 int*

void demo1()
{
    int a = 1, b = 2;
    INTP x, y;      // 起别名了
    x = &a;
    y = &b;
    cout << *x << "  " << *y << endl;

    INTP1 x1, y1;       // 这里只是简单的替换，相当于：int *x1, y1;  因此y1是int型
    x1 = &a;
    y1 = b;
    cout << *x1 << "  " << y1 << endl;
}

// 2.定义平台无关类型
/*编译宏可以很好的控制编译流，我们在编译跨平台程序的时候，很多时候是靠编译流的*/
/*类型定义有更好的typedef, 关于类型的定义，我们完全可以使用typedef来替换#define*/
void demo2()
{
    // 在一些机器上，int为16位，long为32位，可以这样定义：
    typedef int INT16;
    typedef long INT32;

    // 有的机器上变成short位16位，int 32位，long变成了64位
    /*typedef short INT16;
    typedef int INT32;*/
}


// 3.为复杂声明定义一个简单的别名

void func0(int x){cout << x << endl;}
void func1(int x){cout << x+1 << endl;}
void demo3()
{

    //使用typedef来重命名函数指针
    typedef void (*fp)(int x);   //

    fp f1, f2;
    f1 = func0;
    f1(1);
    f2 = func1;
    f2(1);
}

// 4.辅助声明结构体  -->> C++中是不需要的
typedef struct sunhongjiang
{
    double weight;
    int id;
} shj;
void demo4()
{
    shj s1;
    s1.id = 40;
    s1.weight = 99.99;
    cout << s1.id << "\t" << s1.weight << endl;
}

int main()
{
    demo1();
    demo3();
    demo4();
    return 0;
}