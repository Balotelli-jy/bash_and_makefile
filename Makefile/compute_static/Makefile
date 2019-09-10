#静态库编译
source := add.cpp sub.cpp mul.cpp
obj := $(patsubst %.cpp, %.o, $(source))

result : main.o
	@g++ -o $@ $^ -L./ -lstatic

libstatic.a : $(obj)
	@ar rcs $@ $^	


.PHONY:clean
clean:
	@rm *.o  *.a test s1 s2 -rf	libstatic.a result
	

