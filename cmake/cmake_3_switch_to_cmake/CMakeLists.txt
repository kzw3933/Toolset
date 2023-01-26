# 1. 指定最小的 CMake 版本要求
cmake_minimum_required(VERSION 3.9)

# 2. 设置项目名称
project(answer)

# 3. 添加可执行文件 target, 类似于原来的 Makefile
#     answer: main.o answer.o
#     main.o: main.cpp answer.hpp
#     answer.o: answer.cpp answer.hpp
#    Cmake会自动找到依赖的头文件,因此无需特别指定

add_executable(answer main.cpp answer.cpp)


# 4. 使用以下命令构建本项目
#    cmake -B build         生成构建目录
#    cmake --build build    执行构建
#    ./build/answer         运行 answer 程序
