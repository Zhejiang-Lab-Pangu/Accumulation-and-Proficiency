#!/bin/bash

:<<!

sed 文本处理工具

!


# 1.更改文件中的数据

# (1) 将文件的第一行改为hello
sed '1chello' sed_file.txt

echo "===================="
# (2) 将包含itheima的行修改为sunhongjiang
sed '/itheima/csunhongjiang' sed_file.txt

echo "===================="
# (3) 将最后一行修改为sun
sed '$csun' sed_file.txt


echo "**************************"

# 2.替换数据

# (1) 将itheima替换为sun，默认只替换每行的第一个itheima
sed 's/itheima/sun/' sed_file.txt

echo "===================="
# (2) 将itheima全部替换为sun
sed 's/itheima/sun/g' sed_file.txt    #g表示全局替换

echo "===================="
# (3) 将每行第二个itheima替换为sun
sed 's/itheima/sun/2' sed_file.txt    #2表示第二个

echo "===================="
# (4) 将每行第二个itheima替换为sun，然后写入文件
sed 's/itheima/sun/2w sed_file2.txt' sed_file.txt    #只写入了替换的行

echo "===================="
# (5) 正则表达式匹配替换
sed '/i/s/t.*//' sed_file.txt    #匹配有i的行，替换匹配行中t后面的所有内容为空

echo "===================="
# (6) 每行末尾拼接test
sed 's/$/& test/' sed_file.txt

echo "===================="
# (7) 每行行首添加 #
sed 's/^/&# /' sed_file.txt