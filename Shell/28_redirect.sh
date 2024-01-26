#!/bin/bash

:<<!

输入、输出的重定向
!


# 1. 输出重定向

# (1)默认接收正确信息
echo "hello " >> log1.txt
ls ddd >> log1.txt


# (2)只接收错误信息
echo "hello" 2>> log2.txt       #注意：2需放在输出信息后，有空格，重定向前无空格
ls ddd 2>> log2.txt


# (3)错误、正确信息都接收
echo "hello ">> log3.txt 2>&1
ls ddd >> log3.txt  2>&1



# 2. 输入重定向


# 统计文件函数
wc -l < abc.txt

# 循环读取文件
row_num=1
while read str
do
  echo "${row_num} : ${str}"
  let row_num++
done < abc.txt

wc -l << EOF
2
4
5
EOF
