cmake_minimum_required(VERSION 3.9)
project(answer)

# 添加answer子目录
add_subdirectory(answer)

add_executable(answer_app main.cpp)
target_link_libraries(answer_app libanswer)



