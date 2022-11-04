//
// Created by Administrator on 2022/10/25.
//


// c++枚举类型

/* 枚举类型的定义格式为：
 * enum <类型名> {<枚举常量表>};
 * */


#include<iostream>
using namespace std;


void demo1()
{
    // 枚举常量只能以标识符形式表示
    enum week {Sun=7, Mon=1, Tue, Wed, Thu, Fri, Sat};      //枚举常量Sun,Mon,Tue,Wed,Thu,Fri,Sat的值分别为7、1、2、3、4、5、6。

    enum class T : char {A='a', B, C};     // 枚举常量默认char类型

    enum T1 {X, Y, Z};


    cout << Tue << endl;
//    cout << T::B << endl;
    cout << X << endl;

    week w = Tue;
    cout << w << endl;
}

int main()
{
    demo1();
    return 0;
}