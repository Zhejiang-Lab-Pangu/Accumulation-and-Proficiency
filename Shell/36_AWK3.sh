#!/bin/bash


:<<!

awk 详解
!

# 1.添加开始与结束内容

echo -e "abc\nabc" | awk 'BEGIN{print "start ... "}{print $0}END{print "end ..."}'


# 2.使用循环拼接分割后的字符串
echo "abc  sun  hongjiang" | awk '{print$1"&"$2"&"$3}'
echo "abc  sun  hongjiang" | awk -v str="" '{for(n=1;n<=NF;n++){str=str$n}} END{print str}'    # 循环拼接


# 3. 操作数学运算
echo -e "2.1\n3.4" | awk -v i=1 '{print $0+1}'


# 4. 切割字符串
ifconfig | awk '/broadcast/{print}' | tail -n 1 | awk '{print $2}'


# 5. 显示空行行号
sed 'G' sed_file.txt | awk '/^$/{print NR}'