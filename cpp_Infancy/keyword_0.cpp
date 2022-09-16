//
// Created by Administrator on 2022/9/15.
//

/* C++中的一些keyword--1
 * ①using
 * ②typename
 * ③constexpr
 * ④unsigned
 * ⑤malloc
 * ⑥memcpy
 * ⑦size_t
 * */

#include <iostream>
#include <string>
#include <malloc.h>
using namespace std;


// 1. using
template<typename Type>
void func0(Type t)
{
    using t0 = Type;    // 将Type类型指定另外一个别名t0
    const t0 & x = t;   // 使用t0的数据类型创建变量t的一个引用
    std::cout << x << std::endl;
}

void demo1()
{
    std::string s = "sunhongjiang";
    func0(s);
}

// 2. typename
/* ①限定名(cout)和非限定名(std::cout)
 * ②依赖名和非依赖名：依赖名(dependent name)是指依赖于模板参数的名称，而非依赖名(non-dependent name)则相反，指不依赖于模板参数的名称
 * ③类作用域：MyClass::name 包含(静态成员属性、静态成员函数、嵌套类型)
 * */

template<class T>
void func1()
{
    T::a;   // T::a 是一个依赖名，不能确定是否为类型
    typename T::a *it;   // 加typename限定，确定为类型

//    typename只能用于模板的定义中；如果类型是依赖于模板参数的限定名，那么在它之前必须加typename
}

// 3.constexpr:生成常量表达式，允许程序利用编译时的计算能力
/*constexpr修饰函数的限制: ①只能有1个return；②只能调用其他constexpr函数；③只能使用全局constexptr变量（字面值类型）*/

// 4.unsigned -->> 无符号修饰符，支持整形

// 5.malloc: 语法-> void * malloc(unsigned int num_bytes)
/*分配长度为num_bytes字节的内存块：如果成功则返回指向被分配内存的指针，否则返回空指针NULL*/
void demo5()
{
    char *p;
    p = (char *)malloc(100);
    if(p)
    {
        cout << "memory allocate at: " << (void *)p << endl;
        cout << sizeof(p) << endl;
    }
    else
    {
        cout << "memory allocated failed" << endl;
    }
    free(p);
}

// 6.memcpy: 语法 -> void * memcpy(void *dest, void const *src, size_t n);
/*由src指向地址为起始地址的连续n个字节的数据复制到以destin指向地址为起始地址的空间内*/
void demo6()
{
    int a = 444;
    int *b = new int;
    size_t u = 12;
    int * d = (int *)memcpy(b, &a, u);
    cout << *d << endl;
    cout << d << "  " << b << endl;

    int * x = new int(1000);
    int * d1 = (int*) memcpy(x, &a, 16);
    cout << *d1 << "\t"<< *x << endl;

    bool j = (x == d1);
    cout << j << endl;

    delete b;
    delete x;
    delete d;
}

// 7.size_t可以看成unsigned int
void demo7()
{
    size_t x = 100;
}

int main()
{
//    demo1();
//    demo5();
    demo6();
    return 0;
}