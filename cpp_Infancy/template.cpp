// 模板
// Created by Administrator on 2022/9/9.
//

#include <iostream>
using namespace std;


// 1.函数模板
template <typename T>  //声明一个模板，告诉编译器后面代码中紧跟的T不要报错，T指代一个通用数据类型
void Swap(T &x, T &y)
{
    T tmp = x;
    x = y;
    y = tmp;
}
//和函数相比，优点在于可以使用任何类型（int char double）


void demo1()
{
    int n=1, m=2;
    Swap(n, m);    //编译器自动生成 void Swap (int &, int &)函数
    double f = 1.2, g = 2.3;
    Swap(f, g);
    cout << "n: "<< n << "; " << "m: " << m << endl;
    cout << "f: " << f << "; " << "g: " << g << endl;
}



// 2.类模板
template <class Type>
class Compare
{
public:
    Compare(Type x, Type y)    //构造函数进行初始化
    {
        this->x = x;
        this->y = y;
    }

    Type max()      //类模板中的成员函数在调用的时候才创建出来
    {
        return (x>y) ? x: y;
    }
    int cc = 44;    //共有属性
private:
    Type x, y;      //私有属性
};

int demo2()
{
    Compare<int> c1(3, 5);
    cout << "最大： " << c1.max() << endl;
    Compare<float> c2 (2.2, 3.3);       // 类模板中没有自动类型推导的使用方式
    cout << "最大： " << c2.max() << endl;
    cout << c2.cc << endl;
    return 0;
}


//3. 可变参数模板
void FormatPrint()      //若要递归调用参数，必须提供递归终止函数
{
    cout << "empty" << endl;
}

template <typename T, typename... Args>
void FormatPrint(T first, Args... args)
{
    cout << "[" << first << "]";
    FormatPrint(args...);

}

int demo3()
{
    FormatPrint(1, 2, 3, 4);
    FormatPrint("GOOD", 2, "HELLO", 4, 110);    //若要递归调用参数，必须提供递归终止函数
    return 0;
}



//int main()
//{
//    demo1();
//    demo2();
//    demo3();
//    return 0;
//}