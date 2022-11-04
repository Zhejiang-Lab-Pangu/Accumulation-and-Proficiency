//
// Created by Administrator on 2022/10/31.
//

#include<iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

/* 分配器：
 * 又叫空间配置器， 负责空间的配置与管理， 是一个实现了动态空间分配与释放的类模板
 * 统一对容器中需要的内存空间进行管理（申请，释放）
 *
 * 用内存池可以节省申请和释放内存的时间，也可以减少内存碎片
 *
 *  new -->> malloc -->> system call
 *  delete -->> free -->> system call
 * */


void demo1()
{
    vector<int> v1{1, 2, 3, 4};

    vector<int, allocator<int>> v3{1, 2, 4};


    // 内存管理过程
    allocator<int> all1;
    int * p = all1.allocate(4); // 表示分配了4个int大小的空间

    for(int i=0; i<4; i++)
    {
        *p = i;
        p++;
    }

    all1.deallocate(p, 4);
}

int main()
{
    demo1();
    return 0;
}