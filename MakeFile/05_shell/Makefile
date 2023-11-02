
FILE=abc

A:=$(shell ls)
B:=$(shell ls ../)
C:=$(shell pwd)
D:=$(shell if [ ! -f $(FILE) ];then touch $(FILE); fi;)


a:
	echo $(A)
	echo $(B)
	echo $(C)
	echo $(D)

clean:
	$(RM) $(FILE)
