#!/bin/bash


:<<!

比较运算符  --  整数
!

a=1
b=2

# 等于
[ $a -eq $b ]
echo $?

# 不等于
[ $a -ne $b ]
echo $?

# 小于
[ $a -lt $b ]
echo $?

# 大于
[ $a -gt $b ]
echo $?

# 大于等于
[ $a -ge $b ]
echo $?

# 小于等于
[ $a -le $b ]
echo $?



# 小括号模式
(($a<$b))
echo $?

(($a>$b))
echo $?

(($a!=$b))
echo $?

(($a>=$b))
echo $?

(($a<=$b))
echo $?

(($a==$b))
echo $?
