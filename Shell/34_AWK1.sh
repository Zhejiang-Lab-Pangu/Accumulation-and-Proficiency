#!/bin/bash


:<<!

awk 详解
!

# 1. 默认每行空格切割数据
echo "abc 123 456" | awk '{print $1"&"$2"&"$3}'


# 2. 打印含有匹配信息的行
#(1) 含有root的所有行
awk '/root/' awk_file

#(2) 以 : 拆分并打印输出第7列
awk -F ":" '/root/{print $7}' awk_file


# 3.打印文件每行属性信息
# (1) 统计awk_file:文件名，每行的行号，每行的列数，对应的完整行内容
awk -F ':' '{print "文件名："FILENAME", 行号："NR", 列数："NF", 内容："$0""}' awk_file

awk -F ':' '{printf("文件名：%s， 行号：%s, 列数：%s, 内容： %s\n", FILENAME, NR, NF, $0)}' awk_file

