//
// Created by Administrator on 2022/9/13.
//
#include <iostream>
#include <functional>
using namespace std;

/*std::functional   函数包装模板
 *支持4中函数封装1、正常函数，2.lambda函数3.类的成员函数4.仿函数（重载了（）运算符的函数）
 * */

int func(int i, int j)
{
    cout << i-j << endl;
    return i-j;
}

template<typename T>
T func0(T i, T j)
{
    cout << i+j << endl;
    return i+j;
}

auto l = [](char c)
        {cout << c<< endl;
            return c; };

struct Minus
{
    int operator()(int i, int j)
    {
        int m = i<j? i:j;
        cout << m << endl;
        return m;
    }
};

class Ctest
{
public:
    Ctest()= default;

    static int mytest(int n)
    {
        cout << n << endl;
        return n;
    }

    void mytest01(int i, int j, int k)
    {
        cout <<i << "  " << j << "  "<< k << endl;
    }

    int myprint(int x, int y)
    {
        cout << x+y << endl;
        return x+y;
    }

    void operator()(int o, int p)
    {
        cout << o << "  " << p << endl;
    }
};

void demo()
{
    // 封装普通函数
    function<int(int, int)> f = func;
    f(2, 4);

    // 封装模板函数
    function<double(double, double)> f0 = func0<double>;
    f0(3.4, 4.3);

    // 封装lambda表达式
    function<char(char)> f1 = l;
    f1('j');

    // 封装函数对象
    function<int(int, int)> f2 = Minus();
    f2(10, 14);

    // 类静态成员函数
    function<int(int)> f3 = &Ctest::mytest;
    f3(55);

    // 类成员函数
    Ctest c;
    // 1.bind绑定
    function<void(int, int, int)> f4 = bind(&Ctest::mytest01, &c, placeholders::_1, placeholders::_2, placeholders::_3);
    f4(1, 2, 3);
    // 2.传地址
    function<int(Ctest*, int, int)> f5 = &Ctest::myprint;   //参数列表需要传递类指针
    f5(&c, 2, 4);

    // 仿函数
    function<void(Ctest*, int, int)> f6 = &Ctest::operator();
    f6(&c, 3, 4);


}

// std::bind和std::placeholder
void foo(int x, int y, int z)
{
    cout << x << "  " << y << "  " << z << endl;
}
void demo1()
{
    auto bindFoo = bind(foo, placeholders::_1, 2, 4);
    bindFoo(1, 4);
    Ctest c;
    auto bindCtest = bind(&Ctest::mytest01, &c, placeholders::_1, placeholders::_2, placeholders::_3);  //bind绑定类成员函数时，第一个参数表示对象的成员函数的指针，第二个参数表示对象的地址
    bindCtest(5, 3, 8);
}

int main()
{
    demo();
    demo1();
    return 0;
}