# 1. `:=` 用于给变量赋值, 除此之外还有 `=`、 `?=`、`+=` 等不同的赋值方式
# 2. 一般全大写变量表示允许调用cmake的时候传入的变量, 全小写的变量表示仅供内部使用的变量
# 3. `CC`和`CXX`指定要使用的C和C++编译器

CC := clang
CXX := clang++

# 4. Makefile的核心概念是target,定义target的基本格式是(每一行command必须使用TAB缩进)
#       name: dependencies
#			commands
#    要构建某个target是,使用命令 make target_name

# 5. Makefile中常用的变量名
#    $@     目标文件
#    $^     所有的依赖文件
#    $<     第一个依赖文件

# 6. `.PHONY`定义伪target, 实际上不会被生成

.PHONY: all
all: answer

objects := main.o answer.o


answer: $(objects)
	$(CXX) -o $@ $(objects)

# 7. Make可以自行推断 .o 目标文件需要依赖同名的 .cpp或.c 文件以及生成规则, 因此无需指定 .o文件的依赖与生成规则

main.o: answer.hpp
answer.o: answer.hpp

.PHONY: clean
clean:
	rm -f answer $(objects)