#!/bin/bash

:<<!

while 循环控制
!

read -p "请输入循环次数: " nums

i=0
while [ ${i} \< ${nums} ]
do
    echo "hello shell !"
    let i++
done



j=0
while true
do

  let j++

  if ((j==nums))
  then
    continue
  fi

  echo "第 ${j} 次"

  if ((j>4))
    then
      break
  fi


done




k=0
while :
do
  echo "sunsun"
  if ((k==nums))
  then
    break
  fi
  let k++
done