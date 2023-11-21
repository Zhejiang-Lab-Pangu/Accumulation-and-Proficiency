#!/bin/bash

:<<!

until 循环控制
!


read -p "请输入循环截止数：" nums


i=0
until [[ ! $i < $nums ]]
do
  echo "shell -- ${i}"
  let i++
done