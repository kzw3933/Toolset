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
all: hello

objects := main.o


hello: $(objects)
	$(CXX) -o $@ $(objects)

main.o: main.cpp
	$(CXX) -c main.cpp

.PHONY: clean
clean:
	rm -f hello $(objects)