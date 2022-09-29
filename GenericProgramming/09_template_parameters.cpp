//
// Created by Administrator on 2022/9/28.
//


/*
 *
 * 可变参数的函数模板
 *
 *
 * */


#include <iostream>
using namespace std;


template<typename T1, typename T2>
void func1(T1 a, T2 b)
{
    cout << a << "----" << b << endl;
}

template<typename ... T3>       // T3时类型参数的变量名， ...是修饰符， 类似 *p的 *
void func3(T3 ...a)         // T3表示类型， a表示变量名， 类似于 int *p； 但a是可变参
{
    // 参数个数
    cout << sizeof...(T3) << "----" << sizeof...(a) << endl;        // sizeof... 是固定写法，专门用在可变参里面（c++11）

    // 取出所有的参数值 --- 只能是相同类型

    int sum = 0;
    for(auto val: {a...})
    {
        cout << val << endl;
        sum+=val;
    }
    cout << sum << endl;

}

void demo1()
{
    func1(1, 2.4);

//    func3();
    func3(1);
//    func3(1, 3.4);
//    func3(1, 2.3, "3.3");
//    func3(1, 2.3, "3.3", nullptr);
}


void demo2()
{
    func3(1, 2, 3, 5);
}


// 递归取值 ； 参数包---取值（解包）int， double， float， string， 指针，...


// 递归出口函数
void func4()
{
    cout << "这里是递归出口函数" << endl;
}

template<typename T41, typename ...T4>
void func4(T41 x, T4 ...y)
{
    cout << x << endl;

    // 这种写法可省略递归出口函数
    if constexpr(sizeof...(y) > 0)
    {
        func4(y...);
    }
    /*else
    {
        cout << "递归结束" << endl;
    }
    */

}

void demo3()
{
    func4(1, 2, 3, 4);
    func4(1, 2.2, 'b', "sun");
}

/*
 *
 * 递归取值：实质上在编译的时候就编译出所有要调用的函数，而不是反复调用自身
 *
 * func4(1, 2, 3, 4) ------------------------ void func4<int, int, int, int>(int, int, int, int)
 *      func4(2, 3, 4) ---------------------- void func4<int, int, int>(int, int, int)
 *          func4(3, 4) --------------------- void func4<int, int>(int, int)
 *              func4(4) -------------------- void func4<int>(int)
 *                  func4() ----------------- func4()
 *
 *
 * */


int main()
{
//    demo1();
//    demo2();
    demo3();
    return 0;

}