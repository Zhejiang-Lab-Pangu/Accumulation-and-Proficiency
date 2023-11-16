#!/bin/bash

:<<!
算术运算符

!

# 运算符表达式中字符和字符之间右空格
expr 1 + 1


# 接收结果 --- 注意反引号里面表达式中的空格
res=`expr 1 + 3`
echo $res



read -p "第一个数：" a
read -p "第二个数：" b


# 四则运算

echo "a=${a}; b=${b}"
echo "a+b=`expr $a + $b`"
echo "a-b=`expr $a - $b`"
echo "a*b=`expr $a \* $b`"
echo "a/b=`expr $a / $b`"
echo "a%b=`expr $a % $b`"

