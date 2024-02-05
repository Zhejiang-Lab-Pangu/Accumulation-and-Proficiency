#!/bin/bash

:<<!

批量生成文件名
!


read -t 30 -p "请输入创建文件的数量: " nums

# 校验 nums
test=$(echo $nums | sed 's/[0-9]//g')     # 将所有的数字都替换为空字符串
if [ -n "$nums" -a -z "$test" ]
then
    for((i=0;i<$nums;i++))
    do
      name=$(date +%N)      #文件名采用“纳秒”命名
      [ ! -d ./tmp ] && mkdir -p ./tmp      # 如果tmp目录不存在，创建目录
      touch "./tmp/$name"
      echo "创建 $name 成功"
    done
else
  echo "创建失败 ！"
  exit 1
fi
