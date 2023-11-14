#!/bin/bash

:<<!
  字符串截取

!


var0="welcome to myworld"

# 1. ${变量名:start:length}

var1=${var0:0:2}
echo $var1


# 2. ${变量名:start}   截取右侧所有

var2=${var0:11}
echo ${var2}


# 3. ${变量名:0-start:length}    从右侧的start向右截取length (右侧的起始索引是1)
var3=${var0:0-5:2}
echo $var3


# 4. ${变量名:0-start}    从右侧的start向右截取所有 (右侧的起始索引是1)
var4=${var0:0-6}
echo $var4


# 5. ${变量名#*char}   截取左侧第一次出现char的右边所有字符
var5=${var0#*e}
echo $var5        # lcome to myworld


# 6. ${变量名##*char}   截取左侧最后一次出现char的右边所有字符
var6=${var0##*m}
echo $var6        # yworld


# 7. ${变量名%char*}   截取右侧第一次出现char的 左 边所有字符
var7=${var0%m*}
echo $var7


# 8. ${变量名%char*}   截取右侧最后一次出现char的 左 边所有字符
var8=${var0%%m*}
echo $var8