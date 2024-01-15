#!/bin/bash

:<<!

bc命令详解
!


echo "1+1" | bc

# 保留三位小数
echo "scale=3;10/3" | bc

# 调用数学库
echo "e(2)" | bc -l

# 输出进制转换
echo "obase=2;7" | bc

# 引用shell变量
a=10
echo "b=$a+4;b" | bc


# 将bc计算结果赋值给shell变量
var=`echo "2+3" | bc`
echo $var


# 输入重定向
x=`bc -lq << EOF
1+1
2+2
3+3
EOF
`
echo $x    # 2 4 6
