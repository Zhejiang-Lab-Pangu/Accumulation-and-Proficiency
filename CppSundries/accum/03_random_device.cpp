//
// Created by Administrator on 2023/2/15.
//
#include <iostream>
using namespace std;
#include <random>


/*
 * 随机数：
 *
 * 1.seed:
 *      (1) time(nullptr)
 *      (2) random_device rd; rd()
 *      (3) mt19937 engine(rd());
 *
 * 2.distribution 对象:
 *      (1) 均匀分布：
 *          uniform_int_distribution<_Type=int> dis1(min, max);
 *          uniform_real_distribution<_Type=double> dis(min, max);
 *      (2) 正态分布：
 *          normal_distribution<Type = double> nd(均值, 方差);
 *
 * 3.随机数：
 *      obj(seed);
 *      obj: distribution对象；    seed为可用于创建随机数的对象
 * */


//平均分布
void demo(){

    std::random_device rd;
    cout << time(nullptr) << endl;

//    default_random_engine e;
//    default_random_engine e(time(nullptr));
    default_random_engine e(rd());
    uniform_real_distribution<float> dis(-1.0, 1.0);
    uniform_int_distribution<> dis1(0, 9);

    for(int i=0; i<10; i++){
        cout << dis(e) << endl;
    }

    for(int j =0; j<5; j++){
        cout << dis1(e) << endl;
    }
}


void demo2(){

    // random_device 可用于生成随机数
    std::random_device rd;
    cout << rd() << endl;       //返回一个 min() 到 max() 之间的一个数字

    std::mt19937 engine(rd());      // 梅森旋转算法
    for(int i=0; i<5; i++){
        cout << engine() << endl;
    }
}

//正太分布
void demo3(){
    random_device rd;
    mt19937 gen(rd());

    normal_distribution<double> nd(5, 2);
    for(int i=0; i<5; i++){
        cout << nd(gen) << endl;
    }
}

int main()
{


//    demo();
    demo2();
    demo3();
    return 0;
}
