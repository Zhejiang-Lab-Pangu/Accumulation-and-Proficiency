#!/bin/bash

:<<!

test 命令详解   ----   和[]完全等价
!

# 1.整数比较
test 1 -eq 1
echo $?


# 2.字符串
a="abc"
b="abc"

test $a == $b;echo $?
test $a != $b;echo $?
test -n ${a};echo $?    #字符串长度不为0则真


# 3.文件

test -e abc.txt;echo $?   #存在为0
test -r abc.txt;echo $?   #读
test -w abc.txt;echo $?   #写
test -x abc.txt;echo $?   #可执行
test -f abc.txt;echo $?   #普通文件
test -d abc.txt;echo $?   #目录文件


test 1 -eq 1 -a 1 \< 2;echo $?
