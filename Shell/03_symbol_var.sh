#!/bin/bash


# 1.$n 接收参数
echo "当前脚本名称：$0"
echo "第一个参数：$1"
echo "第二个参数：$2"
echo "第10个参数：${10}"
echo "$10"

# 2.$# 参数个数
echo "参数个数：$#"


# 3.$* 和 $@     所有参数
echo '使用$*直接输出：'$*      # 注意这里是单引号，实现符号变量的转义(转为字符串)
echo '使用$@直接输出：'$@

# 循环打印
echo '循环遍历输出$*所有参数：'
for item in "$*"
do
  echo $item
done

echo '循环遍历输出$@所有参数：'
for item in "$@"
do
  echo $item
done

