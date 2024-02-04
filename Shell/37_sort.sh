#!/bin/bash

:<<!

sort
!


# 1. 按照数字升序

sort -t " " -k 2n,2 sort_file.txt     # -k 2, 2代表第二列开始，第二列结束，n代表数字


echo "====================="


sort -t " " -k 2n,2 -uk1,2 sort_file.txt     # -uk1,2 表示去重按1，2两列去重


echo "====================="

sort -t " " -k 2n,2 -uk1,2 sort_file.txt -o sort2.txt     # 保存到sort2.txt中
cat sort2.txt
rm -rf sort2.txt

echo "====================="

sort -t " " -k 2nr,2 -uk1,2 sort_file.txt     # 2r 表示按第二列降序