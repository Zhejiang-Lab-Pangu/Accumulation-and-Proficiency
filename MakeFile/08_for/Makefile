
# 循环

# makefile中只有一个循环 foreach

# foreach 只支持FUN Make， 其他平台需要在shell中实现

TARGET = A B C D
FILE=$(foreach v, $(TARGET), $(v).pdf)

all:
	#touch $(TARGET)
	touch $(FILE)

clean:
	$(RM) $(FILE)



all-shell:
	for v in $(TARGET);\
		do echo $$v.pdf;\
		done;\

all-v1:
	echo $(TARGET)
	#循环
	echo $(foreach v, $(TARGET), $(v))