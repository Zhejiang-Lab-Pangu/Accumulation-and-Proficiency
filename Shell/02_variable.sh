

# 1.子定义局部变量的增删改查
name=sunhongjiang
team="hh jjjj"  # 有空格要用”“括起来
echo $name
echo $team
echo ${name}123   # 拼接字符串需要加{}
unset name
echo ${name}

# 2.自定义常量
readonly sex=male
#sex=123  #不能修改
echo $sex


# 3.自定全局变量
export sun=smart
export sex
bash ./02_variable_son.sh