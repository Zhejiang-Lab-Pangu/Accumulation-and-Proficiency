#!/bin/bash

:<<!

let命令详解
!


# 1.赋值
let a=1+6
let b=a-1
let c=a+b

echo "a=${a},b=${b},c=${c}"


# 2.多表达式赋值

let a=1+6,b=a-1,c=a+b
echo "a=${a},b=${b},c=${c}"