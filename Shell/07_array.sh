#!/bin/bash

:<<!
  数组

!


# 1.定义

arr1=(sun hong jiang 1 4 5)
arr2=(1 3 4 "hhh")

aar3[6]=100
arr4=([0]=1 [3]="abc" [10]=abc)



# 2.数组获取
echo ${arr1[2]}

# 2.1 获取赋值
var0=${arr2[3]}
echo $var0

# 2.2 获取所有元素
var1=${arr1[@]}
echo $var1

var2=${arr1[*]}
echo $var2

# 2.3 元素个数
echo ${#arr1[*]}

# 2.4 元素长度
echo ${#arr1[2]}


# 3.数组拼接
arr5=(${arr1[@]} ${arr2[@]})
echo ${arr5[*]}

arr6=(${arr1[*]} ${arr2[*]})
echo ${arr6[*]}

arr7=(${arr1[@]} ${arr2[*]})
echo ${arr7[*]}


# 4.删除
# 4.1删除指定元素
unset arr1[0]
echo ${arr1[*]}

#4.2删除整个数组
unset arr1
echo ${arr1[*]}
