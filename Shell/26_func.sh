#!/bin/bash

:<<!

shell自定义函数
!


# 1.无参无返回值
demo1()
{
  echo "demo1 fun ...."
}

demo1


# 2. 无参有返回值
#sum(){
#  echo "求两数之和"
#  read -p "请输入第一个数：" n1
#  read -p "请输入第二个数：" n2
#
#  echo "输入的两数为： ${n1} 和 ${n2}"
#  return $(($n1+$n2))
#}
#
#sum   #函数调用
#echo "两数之和为 $?"



# 3.有参函数
funParam()
{
  echo "第一个参数： $1 !"
  echo "第二个参数： $2 !"
  echo "第十个参数： ${10} !"

  echo "参数总个数： $#"
  echo "获取所有的参数作为一个字符串 $*"

}
funParam 1 2 3 4 5 6 7 8 9 10 22
