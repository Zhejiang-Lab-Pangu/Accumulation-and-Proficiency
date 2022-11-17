//
// Created by Administrator on 2022/11/16.
//

#include <iostream>
using namespace std;

/*
 * 内存对齐需要遵循的规则：
 * (1) 结构体第一个成员的偏移量（offset）为0，以后每个成员相对于结构体首地址的 offset 都是该成员大小与有效对齐值(对齐单位)中较小那个的整数倍，如有需要编译器会在成员之间加上填充字节。
 * (2) 结构体的总大小为 有效对齐值 的整数倍，如有需要编译器会在最末一个成员之后加上填充字节。
 *
 * */



struct s1{
    char a;
    char b;
    int c;
};

struct s2{
    int c;
    char a;
    char b;
};

struct s3{
    char a;
    int c;
    char b;
};


void demo1()
{
    printf("%d\n",sizeof(s1));  // 输出8
    printf("%d\n",sizeof(s2));  // 输出8
    printf("%d\n",sizeof(s3));  // 输出12
}


#pragma pack(1)     // 设置对齐单位
struct s11{
    char a;
    char b;
    int c;
};

struct s22{
    int c;
    char a;
    char b;
};

struct s33{
    char a;
    int c;
    char b;
};
void demo2()
{
    printf("%d\n",sizeof(s11));  // 输出6
    printf("%d\n",sizeof(s22));  // 输出6
    printf("%d\n",sizeof(s33));  // 输出6
}

#pragma pack(2)
struct s111{
    char a;
    char b;
    int c;
};

struct s222{
    int c;
    char a;
    char b;
};

struct s333{
    char a;
    int c;
    char b;
};
void demo3()
{
    printf("%d\n",sizeof(s111));  // 输出6
    printf("%d\n",sizeof(s222));  // 输出6
    printf("%d\n",sizeof(s333));  // 输出8
}

#pragma pack()
struct s1111{
    char a;
    char b;
    int c;
};

struct s2222{
    int c;
    char a;
    char b;
};

struct s3333{
    char a;
    int c;
    char b;
};
void demo4()
{
    printf("%d\n",sizeof(s1));  // 输出8
    printf("%d\n",sizeof(s2));  // 输出8
    printf("%d\n",sizeof(s3));  // 输出12
}

int main()
{
    demo1();
    cout << endl;
    demo2();
    cout << endl;
    demo3();
    cout << endl;
    demo4();
    cout << endl;

    cout << sizeof(int *) << endl;
    cout << sizeof(int) << endl;
    return 0;
}