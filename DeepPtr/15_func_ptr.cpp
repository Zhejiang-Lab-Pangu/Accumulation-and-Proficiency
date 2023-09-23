//
// Created by Administrator on 2023/9/12.
//
#include <iostream>
using namespace std;
#include <cstring>

/*
 * 函数指针：  函数的指针
 *
 * 函数指针也是指针变量
 *
 * 写法： int (*pfunc)(int, int) = &func;      函数返回类型 (* 指针变量名)(函数参数类型， ...) = &函数名;       (不要&也可以)
 * 调用： int r = (*pfunc)(1, 2);        返回值 = (* 指针变量名) (参数...)
 *
 * */


// 无参，无返回值
void func1(){
    cout << "func1" << endl;
}


// 有参，有返回值
int func2(int a, int b){
    int c = a+b;
    cout << a << "  " << b << endl;
    return c;
}

void demo1(){

    func1();

    int a=123;
    printf("%p\n", &a);

    // 获取函数指针

    void (*pfunc)() = &func1;
    void (*pfunc1)() = func1;       // 这样写也可以, 不要&也可以

    printf("%p\n", &func1);
    printf("%p\n", pfunc);

    // 调用函数指针
    (*pfunc)();
    (*pfunc1)();


    // 有参
    int (*pfunc2)(int, int) = &func2;
    printf("%p -- %p \n", &func2, pfunc2);

    // 调用
    int r = (*pfunc2)(1, 3);
    cout << r << endl;

    // 函数指针也是指针变量
    cout << sizeof(pfunc) << "  " << sizeof(pfunc2) << endl;

}





int main() {

    demo1();
    return 0;
}