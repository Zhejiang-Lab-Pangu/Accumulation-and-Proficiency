//
// Created by Administrator on 2023/8/15.
//

#include<iostream>
using namespace std;
#include <cxxabi.h>

/* true_type 、 false_type  本质是一种数据类型
 *
 * is_union、is_class 判断是否是union和class
 * */

void demo()
{
    true_type t1;
    cout << t1.value << endl;

    false_type t2;
    cout << t2.value << endl;

    cout << abi::__cxa_demangle(typeid(true_type::value_type).name(), 0, 0, 0) << endl;
    cout << abi::__cxa_demangle(typeid(false_type::value_type).name(), 0, 0, 0) << endl;

}

class A{};
union B{};


void demo2()
{
    cout << is_class<A>::value << endl;
    cout << is_class<B>::value << endl;
    cout << "\n";
    cout << is_union<A>::value << endl;
    cout << is_union<B>::value << endl;
}


int main()
{
    demo();
    demo2();
    return 0;
}