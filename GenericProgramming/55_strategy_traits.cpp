#include<iostream>
using namespace std;
#include <cxxabi.h>

/* 策略萃取
 *
 * 策略 - 某种算法，或实现方式，或某种规则
 * 策略萃取 - 给定一个类型，萃取出一种算法或实现方式 【其实就是用模板的方式实现一些算法，再根据类型参数调用】
 *
 * */



#include<iostream>
using namespace std;
#include <cxxabi.h>

// 固定萃取

template<class T>
struct sumType{
    using type = T;
};

template<>
struct sumType<char>{
    using type = int;
};

template<>
struct sumType<int>{
    using type = int64_t;
};


// 策略萃取
struct myAdd{
    template<class T1, class T2>
    static void algori(T1 & sum, T2 &val){
        sum += val;
    }
};

struct mySub{
    template<class T1, class T2>
    static void algori(T1 & sum, T2 &val){
        sum -= val;
    }
};


template<class T, class T1=myAdd>
auto func1(const T * start, const T * end)
{
    using sumT = typename sumType<T>::type;
    sumT sum = 0;
    for(;;)
    {
//        sum += *start;
//        myAdd::algori(sum, *start);
        T1::algori(sum, *start);
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

    cout << func1(&a[0], &a[2]) << endl;
    cout << func1<int, mySub>(&a[0], &a[2]) << endl;

//    cout << func1(&b[0], &b[2]) << endl;
//    cout << func1(&c[0], &c[2]) << endl;
    return 0;
}