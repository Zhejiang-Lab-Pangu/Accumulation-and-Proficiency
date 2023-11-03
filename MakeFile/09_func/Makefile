

A:=123


define FUNC1
	echo func1 $(0)
	echo $(A)
	echo $(1) $(2) $(3)
endef

A:=456

all:
	$(call FUNC1, ABC, DEF, $A)
	#echo $(A)

