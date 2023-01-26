cmake_minimum_required(VERSION 3.9)
project(answer)

# 设置项目使用的 C++ 版本
set(CMAKE_CXX_STANDARD 11)

# 添加answer子目录
add_subdirectory(answer)

add_subdirectory(curl_wrapper)
add_subdirectory(wolfram)

add_executable(answer_app main.cpp)
target_link_libraries(answer_app libanswer)



