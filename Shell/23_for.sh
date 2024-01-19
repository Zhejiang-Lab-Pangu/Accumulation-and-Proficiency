#!/bin/bash

:<<!

for 循环控制
!



# 1.方式1
for i in sun 3 4 5
do
  echo "shell -- ${i}"
done


# 方式2
for i in {1..10}
do
  echo "sun == ${i}"
done


# 方式3
for((i=14; i<=18; i++))
do
  echo "hua ** ${i}"
done