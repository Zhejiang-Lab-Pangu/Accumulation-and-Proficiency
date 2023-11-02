
A:=123

RS1:=
RS2:=
RS3:=
RS4:=


# ifeq,ifneq 与条件之间要求空格，不然报错


ifeq ($(A), 123)
	RS1:=YES
else
	RS1:=NO
endif

ifneq ($(A), 123)
	RS2:=YES
else
	RS2:=NO
endif


# ifdef ifndef 与条件之间要加空格；且直接用变量进行判断

ifdef A
	RS3:=yes
else
	RS3:=no
endif


ifndef FLAG
	RS4:=NO
	FLAG=default
else
	RS4:=YES
endif


all:
	echo $(RS1)
	echo $(RS2)
	echo $(RS3)
	echo $(RS4)

	echo flag=$(FLAG)		#手动传参： make FLAG=3

