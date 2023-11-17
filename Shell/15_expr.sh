#!/bin/bash

:<<!

expr 命令详解
!

# 1.算数运算求值 。。。

# 2. 字符串长度
expr length "sun hong jiang"

# 2. 截取字符串
expr substr "sun hong jiang" 1 3

# 3. 字符索引
expr index "sun hong jiang" s     # 第一次出现的位置


# 4.正则表达式
expr match "sun hong jiang " ".*u"      #2
expr match "sun hong jiang " ".*aaaa"   #0


expr "abcd" : ".*a"