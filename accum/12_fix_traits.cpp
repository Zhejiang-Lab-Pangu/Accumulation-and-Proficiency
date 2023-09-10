//
// Created by Administrator on 2023/8/18.
//
#include <iostream>                // std::cout
#include <thread>                // std::thread
#include <mutex>                // std::mutex, std::unique_lock
#include <condition_variable>    // std::condition_variable
#include <vector>
#include <queue>
#include <string>
using namespace std;


struct A{

public:
    A(int a):a(a){
        cout << "aaaaaaaaa" << endl;
    };
    int a;
};

struct B{
public:
    B(int b):b(b){
        cout << "bbbbbbbbb" << endl;
    };
    int b;
};

struct C{
public:
    C(int c):c(c){
        cout << "cccccccc" << endl;
    };
    int c;
};





template<class T>
struct TensorType{
    using type = T;
};

template<>
struct TensorType<A>{
    using type = A;
};

template<>
struct TensorType<B>{
    using type = B;
};

template<>
struct TensorType<C>{
    using type = C;
};




template<class T3>
auto creat_tensor(int y){
    using TensorT= typename TensorType<T3>::type;
    return TensorT(y);      // 固定写法：类型(变量)
}

template<class T3>
auto creat_tensor(T3 x, int y){     // 在参数中引用了模板T 声明变量，则在调用时可省略显示类型指定 <>
    using TensorT= typename TensorType<T3>::type;
    x = TensorT(y);
    return x;
}

template<>
auto creat_tensor<C *>(C * x, int y){     // 在参数中引用了模板T 声明变量，则在调用时可省略显示类型指定 <>
//    using TensorT= typename TensorType<C*>::type;
    x = new C(y);
    return x;
}


int main()
{


    auto a = creat_tensor<A>(4);
    auto x = creat_tensor<int>(2344);
    cout << x << endl;


    B b(44);
    auto r = creat_tensor(b, 4);
    cout << r.b << endl;

    C * c;
    auto r1 = creat_tensor(c, 4);
    cout << r1->c << endl;

    return 0;
}