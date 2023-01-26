#include "answer/answer.hpp"

#include <curl/curl.h>

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