//
// Created by Administrator on 2023/8/18.
//
//
// Created by Administrator on 2023/8/16.
//
//
// Created by Administrator on 2023/8/15.
//

#include<iostream>
using namespace std;
#include <cxxabi.h>

/* 萃取 - 并不是某一种具体的技术或某个具体类库或函数；更像一种编程思想、模式
 *
 * 萃取 - traits(特质)
 * 萃取 - 主要用于对模板中的模板参数进行操作，这种模板一般称其为 traits 模板； 标准库中很常见
 *
 *
 * 分类：
 * 1.固定萃取 - fixed traits        给定一种类型。萃取另一种类型；这两个类型之间的对应关系是固定的；所以称为固定萃取
 * 2.值萃取 - value traits         给定一个类型，得到一个值
 * 3.类型萃取 - type traits         从boots库发展而来；实现了类型信息的提取和变换
 * */



class CC{
public:
    CC(int a, int b) : a_(a), b_(b){}

    CC & operator+=(CC other){
        this->a_ += other.a_;
        this->b_ += other.b_;
        return *(this);
    }

    int a_;
    int b_;
};



// 值萃取

template<class T>
struct sumType{};

template<>
struct sumType<char>{
    using type = int;
    static const type init_sum(){
        return 0;
    };
};

template<>
struct sumType<int>{
    using type = int64_t;
    static const type init_sum(){
        return 0;
    };
};

template<>
struct sumType<CC>{
    using type = CC;
    static const type init_sum(){
        return CC(0, 0);
    }
};


template<class T1>
auto func0(const T1 * start, const T1 * end)
{
    using sumT = typename sumType<T1>::type;
    sumT sum =sumType<T1>::init_sum();
    for(;;)
    {
        sum += *start;
        if(start == end)
        {
            break;
        }
        start++;
    }
    return sum;
}


int main()
{
    int a[] = {1, 2, 3};
    int b[] = {1000000000, 2000000000, 1500000000};
    char c[] = "abc";
    cout << func0(&a[0], &a[2]) << endl;
    cout << func0(&b[0], &b[2]) << endl;
    cout << func0(&c[0], &c[2]) << endl;



    cout<< endl;


    CC d[3]= {CC(1, 11), CC(2, 22), CC(3, 33)};
    auto e = func0(&d[0], &d[2]);
    cout << e.a_ << "\n" << e.b_ << endl;


    return 0;
}