add_library(wolfram STATIC alpha.cpp)
target_include_directories(wolfram PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(wolfram PRIVATE curl_wrapper)

