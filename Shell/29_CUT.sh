#!/bin/bash

:<<!

cut 工具

!


# 1.按列提取
# 以空格为分割符，提取第一列
cut cut_file.txt -d " " -f 1

# 以空格为分割符，提取第1、3、4列
cut cut_file.txt -d " " -f 1,3,4

# 以空格为分割符，提取第2列之后的
cut cut_file.txt -d " " -f 2-

# 以空格为分割符，提取第4列之前的
cut cut_file.txt -d " " -f -4

echo "============================="


# 2.按字符提取
# 提取1、5、6列的字符
cut cut_file.txt -c 1,5,6

echo "============================="


# 3.管道提取
echo "hello" | cut -c 1,4
echo "A B C D" | cut -d " " -f 1,4

echo "============================="



# 4. 提取文本中的指定字符
# (1) 在 cut_file中截取itheima中的itheima
cat cut_file.txt | grep itheima | cut -d " " -f 3

echo "-----------------------------"

# (2) 切割提取bash进程的PID号
ps -aux | grep bash | head -n 1 | cut -d " " -f 7

# 注意：
# head -n 数字   获取前多少条
# tail -n 数字   获取后多少条

# (3) 切割提取ip地址
ifconfig | grep broadcast | tail -n 1 | cut -d " " -f 10