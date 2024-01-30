#!/bin/bash

:<<!

sed 文本处理工具

!


# 1.向文件中添加数据

# (1) 指定行号添加数据
sed -i '3ahello' sed_file.txt     # 在第三行后添加hello，并对原文件修改（-i）
sed '3ihello' sed_file.txt        # 在第三行前添加hello


echo "=================="
# (2) 指定的内容前后添加数据
sed '/itheima/ihello' sed_file.txt    # 在有itheima的行前都插入hello
sed '/itheima/ahello' sed_file.txt    # 在有itheima的行前都插入hello


echo "=================="
# (3) 最后一行前后添加
sed '$ahello' sed_file.txt      # $ 代表最后一行
sed '$ihello' sed_file.txt      # $ 代表最后一行


echo "**********************"


# 2.删除

# (1) 删除指定行
sed '2d' sed_file.txt     # 删除第二行

echo "================="
# (2) 删除奇数行
sed '1~2d' sed_file.txt    # 从第一行开始，每隔两行删1行

echo "================="
# (3) 删除指定范围的多行数据
sed '1,4d' sed_file.txt    # 删除第1~4行的数据

echo "================="
# (4) 删除指定范围 取反 的多行数据
sed '1,4!d' sed_file.txt    # 删除第1~4行 之外 的数据

echo "================="
# (5) 删除最后一行数据
sed '$d' sed_file.txt

echo "================="
# (6) 删除匹配行
sed '/itheima/d' sed_file.txt   # 删除匹配itheima的行

echo "================="
# (7) 删除匹配行到最后一行
sed '/itheima/,$d' sed_file.txt   # 删除匹配itheima的行至最后一行

echo "================="
# (8) 删除匹配行和其后面一行
sed '/itheima/,+1d' sed_file.txt   # 删除匹配itheima的行和他后面的一行

echo "================="
# (9) 删除不匹配的行
sed '/itheima\|itcast/!d' sed_file.txt   # 删除不匹配itheima和itcast的行