#!/bin/bash


:<<!

shell 内置命令
!

# 1.type
type cd
type ifconfig


# 2. alias
#alias
#alias pList="ps -aux"
#pList
#unalias pList
#pList
#ps -aux


# 3.echo
echo -n "sunhongjiang"    # 不换行
echo    #换行

echo "sun\nhongjiang"
echo
echo -e "sun\nhong\njiang"


# 4.read
read name
echo $name

# 4.1 多个变量赋值
read -p "s输入姓名 年龄 爱好:" name age hobby
echo "姓名:${name}"
echo "年龄:${age}"
echo "爱好:${hobby}"


# 4.2 读取一个字符
#read -n 1 -p "是否删除？请输入y/n:" char
#echo $char

# 4.3 限制时间
read -p "请输入密码："  -t 20 first
read -sp "再次输入密码：" -t 10 second

echo


if [ ${first} == ${second} ]
then
  echo "成功!"
else
  echo "失败！！！"
fi


# 5.exit

exit 2


#