#!/bin/bash

:<<!

if else 条件语句
!


read -p "请输入成绩：" score

if ((score<60))
then
  echo "不合格"
elif ((score>=60 && score<70))
then
  echo "合格"
elif ((score>=70 && score <=100))
then
  echo "优秀"
else
  echo "成绩输入有误"
fi



read -p "请输入文件名:" filename
read -p "请输入数据:" data


if [[ -w $filename && -n $data ]]    # 文件存在 且 数据不为空
then
  echo $data > $filename
  echo "文件写入成功"
else
  echo "文件写入失败"
fi
