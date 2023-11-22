#!/bin/bash


:<<!

系统函数 --
(1) basename
(2) dirname
!


filename=`basename "${PWD}/abc.txt"`
echo $filename

# 去文件名后缀
basename "${PWD}/abc.txt" .txt



# 路径前缀
dir=`dirname "${PWD}/abc.txt"`
echo $dir
