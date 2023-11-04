# 公共makefile


SOURCE=$(wildcard ./*.cpp ./*.c)
OBJ=$(patsubst %.cpp,%.o,$(SOURCE))
OBJ:=$(patsubst %.c,%.o,$(OBJ))


ifdef TARGET
TARGET:=$(TARGET)-test
endif

.PHONY:clean	#伪目标




$(TARGET):$(OBJ)
	$(CXX) $^ -o $@

#%.o:%.cpp
#	$(CXX) -c $^ -o $@

clean:
	$(RM) $(TARGET) $(OBJ)

show:
	echo $(SOURCE)
	echo $(OBJ)
