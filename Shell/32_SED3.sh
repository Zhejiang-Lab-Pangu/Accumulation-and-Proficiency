#!/bin/bash

:<<!

sed 文本处理工具

!


# 查询文件或管道中的数据

# 1.查询有itcast的行

sed -n '/itcast/p' sed_file.txt     # -n代表只输入操作行，p代表打印。二者联合使用


# 2. 管道过滤查询

# 管道查询所有进程中有sshd进程信息的命令
ps -aux | sed -n '/sshd/p'


echo "***********************************"


# 3. 多sed命令执行
# (1) 将文件第一行删除，并将itheima替换为sun


sed -e '1d' -e's/itheima/sun/g' sed_file.txt     # 方式1： -e


sed '1d;s/itheima/sun/g' sed_file.txt     # 方式2：;