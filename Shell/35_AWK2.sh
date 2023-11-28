#!/bin/bash


:<<!

awk 详解
!

# 1.打印第二行信息
awk -F ':' 'NR==2{printf("filename:%s, 内容: %s\n",FILENAME,$0)}' awk_file


# 2. 查找以1开头的文件
ls -a | awk '/^1/'


# 3. 打印第一列
awk -F: '{print $1}' awk_file


# 4. 打印最后一列
awk -F: '{print $NF}' awk_file


# 5. 打印倒数第二列
awk -F: '{print $(NF-1)}' awk_file


# 6. 打印第10行到20行的第一列
awk -F: '{if(NR>=10 && NR<20){print $1}}' awk_file

# 7. 多分割符
echo "one:two/three for" | awk -F "[:/ ]" '{print $1$2$3$4}'
