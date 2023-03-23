//
// Created by Administrator on 2023/2/9.
//
#include <iostream>
using namespace std;


/*补码*/
/*
 * 定义：正数的补码符号为0，数值部分是它本身；负数的补码等于模与该负数的绝对值只差
 *
 * "0为正，1为负；各位取反，末位加1"
 *
 *
 * */

int main()
{
    int x = -1;
    unsigned u = 2147483648;

    // 符号整形和无符号整形的转化
    printf("x = %u = %d\n", x, x);
    printf("u = %u = %d\n", u, u);

    return 0;
}
