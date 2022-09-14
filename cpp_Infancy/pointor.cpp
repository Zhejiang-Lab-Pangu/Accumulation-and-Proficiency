//
// Created by Administrator on 2022/9/12.
//

/*一、
 1.指针：int a;  &a;  int *a;  *a;
 2.函数参数：void func(int *a, int *b){}  -->> func(&a, &b);
 3.const:   ①const int * a;  不能解引用修改
            ②int * const a;  不能修改指向的变量地址
            ③const int * const a;
 4.void:  void *:
 */

/* 二、
 动态分配内存：new和delete：
 步骤：
 ① 声明一个指针
 ② 用new向系统申请一块内存，让指针指向这块内存
 ③ 指针解引用，像使用变量使用这块内存
 ④ 不用了用delete释放
 */

/* 三、
二级指针：指向指针的指针
 int **a;
 */

/* 四、
 空指针：声明指针后，在赋值之前可以指向空，表明没有指向任何地址；用nullptr示
 不可访问解引用；   一般在函数指针传递时要判断空指针；

 野指针：指针指向不合法（无效）的地址
 出现情况：①无初始化；②指向的动态分配地址释放后；③超出变量作用域（函数返回局部变量地址等）
 */

/* 五、一维数组和指针
 1.数组本质：数组是占用一块连续空间的内存
 2.动态创建一维数组：栈上内存太小。。
 */

/*六、二维数组和行指针
 * 行指针：int(*p)[3] -> 一维数组名取地址即为行指针
 * 函数传递：形参->行指针；实参->二位数组名；
 * */


/*七、函数指针和回调函数
 * 语法： int (*p_func)(int, char)
 *
 * */

#include <iostream>
using namespace std;
#include <string>


// 1.函数地址传递
void func1(int a, int b, int c, int *max, int *min)
{
    *max = a > b ? a: b;
    *min = a < b ? a: b;
    *max = *max > c ? *max: c;
    *min = *min < c ? *min: c;
}

void demo1()
{
    int a = 187, b= 175, c=168, m, n;
    func1(a, b, c, &m, &n);
    cout << m << ", " << n << endl;
}


// 2. void *
void func1(string varname, void *p)
{
    cout << varname << "的地址是" << p << endl;
}

void demo2()
{
    string s = "sss";
    int t = 44;
    func1(s, &s);
    func1(s, &t);
}

// 3.new,delete
void demo3()
{
    int *p = new int(5);
    cout << *p  << endl;
    *p = 8;
    cout << *p << endl;
}

// 4. int **
void func2()
{
    int * a = new int(3);
    int **i = &a;
    cout << "i = " << i << "  *i = " << *i << "  a = " << a << "  **i = " << **i << "  *a = " << *a << endl;
}
void func3(int ** a)
{
    cout << "**a=" << **a << endl;
    *a = new int(44);
}
void demo4()
{
    int *p = new int(4);
    func3(&p);
    cout << "*p = " << *p << endl;
}

// 5.nullptr、野指针
void demo5()
{
    int * p1 = nullptr;
//    cout << *p1 << endl;

    int *p2 = new int(3);
    delete p2;
//    cout << "p2=" << p2 << ", *p2=" << *p2 << endl;
}

//6. 一维数组的指针
void func6(int * arr, int len)  //数组做函数参数必须指针传递
{
    for(int i=0; i < len; i++)
    {
        cout << arr[i] << endl;
        cout << *(arr+i) << endl;
    }
}
void func6_1()
{
    int * p = new int [10];
    for(int i =0; i<10; i++)
    {
        p[i] = i + 10;
    }
    for(int j=0; j<10; j++)
    {
        cout << "*(p" << j << ") = " << *(p+j) << endl;
    }
    delete [] p;
}
void func6_2()
{
//    long arr[1000001];
//    arr[100000]= 0;
    long * arr1 = new (std::nothrow) long[10000000001];
    if(arr1 == nullptr)
    {
        cout << "内存分配失败" << endl;
    } else
    {
        arr1[1000000000]= 10;
        delete [] arr1;
    }

}

// 7. 一维数组
void demo6()
{
    int v[5] = {1, 2, 3, 4, 5};
    cout << "v的地址：" << (long long )v << endl;
    cout << "v的地址：" << (long long )&v << endl;
    cout << "v[0]的地址：" << (long long )&v[0] << endl;
    cout << "v[1]的地址：" << (long long )&v[1] << endl;

    func6(v, sizeof(v)/sizeof(int));
    func6_1();
    func6_2();

}

// 二维数组和行指针
void func7(int (*p)[3], int len)
{
    for(int i=0; i<len; i++)
    {
        for(int j=0; j < 3; j++)
        {
            cout << "p[" << i << "][" <<j <<"]=" << p[i][j] << "   ";
        }
        cout << endl;
    }
}

void demo7()
{
    int matrix[10];
    int (*p)[10] = &matrix; //一维数组名取地址即为行指针

    int bh[2][3] = {{1, 2, 3}, {4, 5, 6}};
    func7(bh, 2);
}

// 8.函数指针和回调函数
void person_func(int x)
{
    cout << x << "   ";
    cout << "实现特异化功能" << endl;
}

void main_function(void (*pf)(int), int x)
{
    cout << "调前准备" << endl;
    // 回调
    pf(x);
    cout << "调后准备" << endl;
}

void demo8()
{
    int a = 10;
    main_function(person_func, a);
}

int main()
{
//    demo1();
//    demo2();
//    demo3();
//    func2();
//    demo4();
//    demo5();
//    demo6();
    demo7();
    demo8();
    return 0;
}