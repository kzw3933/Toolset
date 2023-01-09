#pragma once

#include <string>

#include <wolfram/alpha.hpp>

// header-only 库的所有实现代码均在头文件中

namespace answer {
    namespace v1 {
        int find_the_ultimate_answer() {
            return 42;
        }
    }
    
    namespace v2 {
        std::string find_the_ultimate_answer() {
            // 改为调用 wolfram 库的API , 而不是使用 CURL 发请求

            return wolfram::simple_query(WOLFRAM_APPID, "What is the ultimate answer?");
        }
    }
}