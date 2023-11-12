//
// Created by Administrator on 2022/9/15.
//

/*enable_if: 满足条件时类型有效
 *
 *
 * */

#include <iostream>
//using namespace std;


// 源码
template <bool _Test, typename T=void>
struct enable_if {
};

template <typename T>
struct enable_if<true, T> { ///< 第一个模板参数为 true
    using type = T;           ///< type 才有定义
};

template<bool _Test, class _Ty = void>
using enable_if_t = typename enable_if<_Test, _Ty>::type;


template<typename T, typename U = typename std::enable_if_t<true, T*>>
void func0()
{
    T t;
    U t0;
    std::cout << std::is_same<T *, U>::value << std::endl;
}


void demo0()
{
    func0<int>();
}


// 筛选函数: 定义的模板函数，只希望特定的类型可以调用
class People
{
public:
    using type_size = unsigned int;
};
class Anamial
{
public:
    using type_size = unsigned int;
};

template<typename T, typename U = typename std::enable_if<std::is_same<T, People>::value>::type>
void launage()
{
    std::cout << "launage" << std::endl;
}

void demo1()
{
    launage<People>();
//    launage<Anamial>();   // 编译期报错
}


int main()
{
    demo0();
    demo1();
    return 0;
}