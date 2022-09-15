//
// Created by Administrator on 2022/9/13.
//

/*
 * 1. 左值和右值：当一个对象被用作右值时，用的是对象的值（内容）；当对象被用作左值时，用的是对象的身份（在内存中的位置）
 * 2. 左值是表达式（不一定是赋值表达式）后依然存在的持久对象；右值是指表达式结束后就不再存在的临时对象；左值持久，右值短暂
 * 3. 右值：
 *  （1）纯右值：
 *      ①纯粹的字面量，例如 10, true；除了字符串字面量，字符串字面量是一个左值，类型为 const char 数组
 *      ②求值结果相当于字面量或匿名临时对象，例如 1+2
 *      ③非引用返回的临时变量、运算表达式产生的临时变量、 原始字面量、Lambda 表达式
 *   (2) 将亡值：临时的值能够被识别、同时又能够被移动
 *      拿到将亡值：右值引用 T &&
 * 4.std::move 将左值参数无条件的转换为右值
 *
 * */


#include <iostream>
using namespace std;
#include <vector>
#include <type_traits>
#include <string>

void demo1()
{
    const char (&left)[6] = "01234";

    static_assert(is_same<decltype("01234"), const char (&)[6]>::value, "");

//    bool b = is_same<int, float>::value;
//    cout << b << endl;

}

void reference(string & s)
{
    cout << "左值" << endl;
}

void reference(string && s)
{
    cout << "右值" << endl;
}

template <typename T>
void pass(T&& v) {
    std::cout << "普通传参:";
//    reference(v); // 始终调用 reference(int&)
}

void demo2()
{
    string lv1 = "string";
//    string &&rv1 = lv1;   //非法, 右值引用不能引用左值
    string && rv1 = move(lv1);
    cout << rv1 << endl;

    const string & lv2 = lv1 + lv1;     //合法, 常量左值引用能够延长临时变量的生命周期
    // lv2 += "Test"; // 非法, 常量引用无法被修改
    cout << lv2 << endl;

    string && rv2 = lv1 + lv2;      //合法, 右值引用延长临时对象生命周期
    rv2 += "Test"; // 合法, 非常量引用能够修改临时变量
    cout << rv2 << endl; // string,string,string,Test


//    rv2 虽然引用了一个右值，但由于它是一个引用，所以 rv2 依然是一个左值。
}

void demo3()
{
//    int &a = move(1);     // 不合法，非常量左引用无法引用右值
    const int & a = move(1);    //合法, 常量左引用允许引用右值
}

void demo4()
{
    cout << "传递右值：" << endl;
    pass(1);

    cout << "传递左值：" << endl;
    int l = 1;
    pass(l);


    /* 引用坍缩规则的:
     * 函数形参类型	实参参数类型	推导后函数形参类型
        T&	            左引用	    T&
        T&	            右引用	    T&
        T&&	            左引用	    T&
        T&&	            右引用	    T&&
     */
}

int main()
{
//    demo1();
//    demo2();
    demo4();
    return 0;
}