#编译工具链
CC := gcc
CXX := g++

#变量集中定义区
SRCS := add.cpp sub.cpp mul.cpp main.cpp
OBJS := $(patsubst %.cpp, %.o, $(SRCS)) #将$(SRCS)中所有的.cpp改为.o

#缺省目标：编译可执行文件
test : $(OBJS)
	@$(CXX) $^ -o $@ #$^为所有依赖，$@为目标，$<为第一个依赖

#测试$@
all : test1 test2
test1 test2 :
	@echo "print test $@"

#测试if
VAL  := 40

testif:
ifeq ($(VAL), 20)
	@echo "val equal 20"
else ifeq ($(VAL), 30)
	@echo "val equal 30"
else
	@echo "val unsure!"
endif

#测试函数:替换函数subst
COMMA := a
EMPTY := e
FOO := a a a
BAR := $(subst $(COMMA), $(EMPTY), $(FOO))	#将FOO中的a全部替换成e

#测试函数：去首位空格strip(测试看不出来)
STRING :=    A B C 

#测试函数：文件夹操作
LIB = /home/hello/libhello.a
LIB1 = $(dir $(LIB))					#返回LIB中的目录：/home/hello/
LIB2 = $(notdir $(LIB))					#返回LIB中的非目录：libhello.a
LIB3 = $(suffix $(LIB))					#取后缀，如果没有，则返回""
LIB4 = $(basename $(LIB))				#取前缀：/home/hello/libhello
LIB5 = $(addsuffix .c,$(LIB4))			#添加后缀：/home/hello/libhello.c
LIB6 = $(addprefix /usr/lib/,$(LIB2))	#添加前缀：/usr/lib/libhello.a
SRCS = $(wildcard *.cpp)				#将当前目录下符合通配符规则的文件全部展开，没有则为""

fun :
	#echo $(BAR)
	#echo $(strip $(STRING))
#测试函数：查找字符串findstring
	#echo $(findstring a, b c)
	@echo "LIB1 = $(LIB1)"
	@echo "LIB2 = $(LIB2)"
	@echo "LIB3 = $(LIB3)"
	@echo "LIB4 = $(LIB4)"
	@echo "LIB5 = $(LIB5)"
	@echo "LIB6 = $(LIB6)"	
	@echo "SRCS = $(SRCS)"

#测试函数：foreach
A = 1 3 4 5 6 7 8 9
B = $(foreach i,$(A),$(addprefix 0.,$(i)))
C = $(foreach i,$(A),$(addsuffix .0,$(i)))

fun_foreach :
	@echo "A = $(A)"
	@echo "B = $(B)"
	@echo "C = $(C)"

#测试函数：shell
$(shell mkdir -p s1)	#-p表示如果目标文件夹不存在，那么就创建
$(shell mkdir -p s2)

fun_shell :
	@echo "hello world"

#静态库编译:目前需要先编译成.a，然后再编译成可执行文件
source := add.cpp sub.cpp mul.cpp
obj := $(patsubst %.cpp, %.o, $(source))	#将$(source)中所有的.cpp改为.o
deps := $(patsubst %.cpp, %.d, $(source))	#将$(source)中所有的.cpp改为.d

ifneq ("$(wildcard $(deps))", "")	#因为.d文件之后在第一次编译之后才会有，为了避免第一次执行脚本报错，所以加入一个include
include $(deps)
endif

result_static : main.o
	@g++ -o $@ $^ -L./ -lstatic

libstatic.a : $(obj) $(deps) #目标文件.o可以自动推到出来
	@ar rcs $@ $^
%.d : %.cpp
	@g++ -MM $^ > $@

#动态库编译:目前需要先编译成.so，然后再编译成可执行文件
source := add.cpp sub.cpp mul.cpp
obj := $(patsubst %.cpp, %.o, $(source))

result_dynamic : main.o
	@g++ -o $@ $^ -L./ -lstatic

libstatic.so : $(obj)
	@g++ -o $@ -shared $^

%.o : %.cpp
	@g++ -o $@ -fPIC -c $^

.PHONY:clean
clean:
	@rm *.o  *.a *.d test s1 s2 -rf	libstatic.* result*
	

