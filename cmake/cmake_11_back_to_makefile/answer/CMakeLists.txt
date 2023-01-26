set(WOLFRAM_APPID
    ""
    CACHE STRING "WolframAlpha APPID")

if(WOLFRAM_APPID STREQUAL "")
    message(SEND_ERROR "WOLFRAM_APPID must not be empty")
endif()

# INTERFACE 类型的 target 一般用于没有源文件的情况, 比如 header-only 库,
# 或者只是为了抽象地提供一组 target_xxx 的配置

# INTERFACE target 的后续所有 target_xxx 都必须也使用 INTERFACE, 效果将会
# 直接应用到链接此库的 target 上

add_library(libanswer INTERFACE)
target_include_directories(libanswer 
                            INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_definitions(libanswer INTERFACE WOLFRAM_APPID="${WOLFRAM_APPID}")
target_link_libraries(libanswer INTERFACE wolfram)


# 指明 libanswer 要求 c++20
# 与直接设置 CMAKE_CXX_STANDARD 的区别是:
#   1. 设置 CMAKE_CXX_STANDARD 之后, 从设置它的那一级开始
#      include 的 subdirectory 都会继承这个变量, 且应用于
#      所有能看到这个变量的 target; 而 target_compile_features
#      只应用于单个 target
#   2. target_compile_features 可以指定更细粒度的 C++ 特性,
#      例如 cxx_auto_type、cxx_lambda 等

target_compile_features(libanswer INTERFACE cxx_std_20)