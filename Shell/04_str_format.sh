#!/bin/bash


# 1.单引号
var=abc
var1='${var} hello world'
echo $var1      # 原样输出


# 2.双引号
var3="${var} hello world"
echo $var3    # 拼接成功,可解析变量

var4="\"${var}\" hello world"
echo $var4



# 3.不加引号
var5=${var}helloworld   #不能有空格
echo $var5    # 拼接成功，可解析变量



# 4.字符串长度
echo ${#var}
echo ${#var1}
echo ${#var3}   #空格也计数

