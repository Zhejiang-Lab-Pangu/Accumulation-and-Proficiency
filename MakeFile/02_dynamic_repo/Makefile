test:libsoTest.so
	$(CXX) -o test test.cpp -lsoTest -L./
	cp libsoTest.so /usr/lib
	# 或者设置export LD_LIBRARY_PATH为当前目录(Linux)
libsoTest.so:
	$(CXX) -shared -fPIC soTest.cpp -o libsoTest.so

clean:
	$(RM) *.so test

