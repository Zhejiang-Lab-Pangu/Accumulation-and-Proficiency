#!/bin/bash

:<<!

shell函数和命令的区别

!


funID()
{
  echo "当前shell进程的ID号： $$ "
}
funID
echo $$