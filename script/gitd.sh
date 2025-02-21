#!/bin/bash

# 获取远程分支列表并存入数组
remote_branches=($(git branch -r | sed 's/origin\///'))  # 使用sed移除前缀'origin/'

skip_branch0="HEAD"
skip_branch1="main"
skip_branch2="master"
skip_branch3="->"


# 遍历远程分支数组
for branch in "${remote_branches[@]}"
do
  if [[ "$branch" != *"$skip_branch0"* ]] && [[ "$branch" != *"$skip_branch1"* ]] && [[ "$branch" != *"$skip_branch2"* ]] && [[ "$branch" != *"$skip_branch3"* ]]; then
    echo $branch
    git push origin --delete $branch
  fi
done
