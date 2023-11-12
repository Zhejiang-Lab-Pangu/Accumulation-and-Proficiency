//
// Created by Administrator on 2023/2/13.
//

#include <iostream>
using namespace std;

/* 内联函数:
 * 为了消除函数调用的时空开销，C++ 提供一种提高效率的方法，即在编译时将函数调用处用函数体替换，类似于C语言中的宏展开。这种在函数调用处直接嵌入函数体的函数称为内联函数（Inline Function），又称内嵌函数或者内置函数。
 * 注意:  要在函数定义处添加 inline 关键字，在函数声明处添加 inline 关键字虽然没有错，但这种做法是无效的，编译器会忽略函数声明处的 inline 关键字。
 * 缺点：  编译后的程序会存在多份相同的函数拷贝，如果被声明为内联函数的函数体非常大，那么编译后的程序体积也将会变得很大，所以再次强调，一般只将那些短小的、频繁调用的函数声明为内联函数。
 * */


inline void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << "m=" << m << ", n=" << n << endl;
                        // 当编译器遇到函数调用swap(&m, &n)时，会用 swap() 函数的代码替换swap(&m, &n)，同时用实参代替形参。这样，程序第 16 行就被置换成：
    swap(&m, &n);           /*          int temp;
                                        temp = *(&m);
                                        *(&m) = *(&n);
                                        *(&n) = temp;        */         // 编译器可能会将 *(&m)、*(&n) 分别优化为 m、n
    cout << "m=" << m << ", n=" << n << endl;
    return 0;
}