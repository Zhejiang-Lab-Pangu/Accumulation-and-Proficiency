#!/bin/bash

:<<!
字符串拼接
!

VAR1=AAA
VAR2=" hello shell"

# 1.无符号拼接

VAR3=${VAR1}${VAR2}
echo $VAR3




# 2.双引号拼接

VAR4="${VAR1}${VAR2}"
echo $VAR4



# 3.混合拼接

VAR5=${VAR1}' SUN '${VAR2}
echo $VAR5

VAR6=${VAR1}" NI "${VAR2}
echo $VAR6

VAR7=${VAR1}" ${VAR1} "${VAR2}
echo $VAR7