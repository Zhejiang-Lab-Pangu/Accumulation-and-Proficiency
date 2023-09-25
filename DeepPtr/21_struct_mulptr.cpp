//
// Created by Administrator on 2023/9/14.
//
#include <iostream>
using namespace std;
#include <cstring>

/*
 * 结构体 多级指针
 *
 * 1.指针在使用前一定要初始化，否则就是野指针
 * 2.记得free，而且注意释放层级，防止内存泄漏
 *
 *
 * */



struct T1{
    int a;
    char *b;
    struct T2 * t2;
};

struct T2{
    int c;
};

void demo0(){

    struct T1 * p1 = (struct T1*)malloc(sizeof(T1));        // 堆区

    p1->a = 123;
    p1->b = "abc";

    // 野指针不可直接copy，必须先分配空间
    p1->b = (char *)malloc(16);
    strcpy(p1->b, "deg");

    cout << p1->a << "  " << p1->b << endl;

    free(p1->b);
    std::free(p1);
}

void demo1(){

    struct T2 t2{};
    t2.c = 456;

    struct T1 * t1 = (struct T1*)malloc(sizeof(T1));
    t1->a=123;
    t1->b = "sun";
    t1->t2 = &t2;

    // 野指针不可直接copy，必须先分配空间
    t1->t2 = (struct T2 *)malloc(sizeof(T2));
    t1->t2->c = 789;

    cout << t1->a << "  " << t1->b << "  " << t1->t2->c << endl;

    free(t1->t2);
    free(t1);

}

int main(){

    demo0();
    demo1();
    return 0;
}