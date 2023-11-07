//
// Created by Administrator on 2022/9/9.
//
//lambda函数(匿名函数)
/*
语法：
 f = [捕获列表](参数列表) mutable(可选) 异常属性 -> 返回类型 {// 函数体}
f = [OuterVar](int x, int y) -> int{return OuterVar+x+y;}
 */
#include <iostream>
using namespace std;


auto f = [](int a, int b){return a + b;};

//Capture Clause: 匿名函数访问、修改函数外部变量

// 1.值捕获（不能修改外围变量的值）：被捕获的变量在 Lambda 表达式被创建时拷贝， 而非调用时才拷贝
int n = 100;
auto f_v = [n](int a){
    cout << "n = " << n << endl;
    return a+n;};

// 2. 引用捕获:引用捕获保存的是引用，值会发生变化
int m = 10;
auto f_q = [&m](){
    m = 200;
    cout << "m = " << m << endl;
};


// 3. 隐式捕获: 在捕获列表中写一个 & 或 = 向编译器声明采用引用捕获或者值捕获
int a=10;
int b = 20;
int c = 30;
int d = 40;

// 全部按值捕获
auto f1 = [=](){
    cout << a << "  " << b << "  " << c << "  " << d << endl;
};

// 全部按引用捕获
auto f2 = [&](){
    a = 100;
    d = 1000;
    cout << a << "  " << b << "  " << c << "  " << d << endl;
};




int main()
{
    cout << f(10,1) << endl;
    cout << f_v(22) << endl;
    f_q();
    f1();
    f2();
    return 0;
}
