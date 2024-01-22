#!/bin/bash

:<<!

select in 选择流程控制
!


echo "您的爱好是什么？"
select var in "编程" "篮球" "游泳" "足球"
do
  echo "选择完成"
  break
done
echo "您的爱好是 ${var}"