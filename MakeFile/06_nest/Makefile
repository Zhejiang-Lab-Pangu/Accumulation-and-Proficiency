# Makefile中的嵌套调用和多项目同时编译

# -C 指定工作目录

.PHONY:../04_header/001 ../04_header/002

DIR = ../04_header/001 ../04_header/002



all:$(DIR)

$(DIR):
	$(MAKE) -C $@

clean:
	$(shell for dir in $(DIR); do make -C $$dir clean;done)				# $$表示展开shell中的变量






all-v1:
	$(MAKE) -C ../04_header/001
	$(MAKE) -C ../04_header/002

clean-v1:
	$(MAKE) -C ../04_header/001 clean
	$(MAKE) -C ../04_header/002 clean