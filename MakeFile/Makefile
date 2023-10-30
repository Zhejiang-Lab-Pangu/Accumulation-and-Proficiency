TARGET=main

#预设全局变量
LDFLAGS=-L./02_dynamic_repo -L./03_static_repo	#指示库文件搜索目录
LIBS=-lsoTest -laTest	#指示链接库


$(TARGET):
	$(CXX) -o $(TARGET) main.cpp $(LDFLAGS) $(LIBS)

clean:
	$(RM) $(TARGET)