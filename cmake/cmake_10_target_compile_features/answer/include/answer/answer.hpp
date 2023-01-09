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

    // 使用 c++14 的auto 返回类型, c++17 的if constexpr 和 c++20 的constraints
    namespace impl {
        template <typename T>
        auto to_string(T &&t) {
            if constexpr (requires { std::to_string(t); }) {
                return std::to_string(std::forward<T>(t));
            } else if constexpr (requires { std::string(t); }) {
                return std::string(std::forward<T>(t));
            }
        }
    }

    template <typename T, typename U>
    requires requires(T &&t, U &&u) {
        impl::to_string(std::forward<T>(t));
        impl::to_string(std::forward<T>(u));
    }
    auto check_the_answer(T &&given, U &&expected) {
        return impl::to_string(std::forward<T>(given)) == impl::to_string(std::forward<U>(expected));
    }

    using namespace v2;
}