#!/bin/bash

:<<!

文件检测计算
!

file1="./01_write_file.sh"
file2="./02_variable.sh"


# 1.测试文件是否可写
if [[ -w ${file1} ]]
then
  echo "file1 可写"
else
  echo "file1 不可写"
fi


# 2.测试文件是否可读
if [[ -r ${file2} ]]
then
  echo "file2 可读"
else
  echo "file2 不可读"
fi


# 3.测试文件是否可执行
if [[ -x ${file2} ]]
then
  echo "file2 可执行"
else
  echo "file2 不可执行"
fi


# 4.测试文件是否是普通文件
if [[ -f ${file2} ]]
then
  echo "file2 是普通文件"
else
  echo "file2 不是普通文件"
fi


# 5.测试文件是否是为空
if [[ -s ${file2} ]]
then
  echo "file2 不为空"
else
  echo "file2 为空"
fi


# 6.测试文件是否存在
if [[ -e ${file2} ]]
then
  echo "file2 存在"
else
  echo "file2 不存在"
fi


# 7.测试文件是否是目录
if [[ -d ${file2} ]]
then
  echo "file2 是目录"
else
  echo "file2 不是目录"
fi


# 8.测试文件的新旧
if [[ ${file1} -nt ${file2} ]]     #file1 是否比 file2 新  （nt 即 new than）
then
  echo "file1 比 file2 新"
else
  echo "file1 比 file2 旧"
fi