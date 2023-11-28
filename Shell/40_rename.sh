#!/bin/bash


:<<!

批量修改文件名

问题： 将./tmp目录下的所有文件名重新命名为 旧文件名-递增数字


语法： rename 旧文件名 新文件名 旧文件位置
!

filenames=$(ls ./tmp)
num=1
for name in $filenames
do
  printf "重命名前：%s\n" ${name}
  newname= ${name}"-"$num
  rename ${name} ${newname} "./tmp/*"
  let num++
  printf "重命名后：%s\n" ${newname}
done


echo "================"
ls ./tmp
