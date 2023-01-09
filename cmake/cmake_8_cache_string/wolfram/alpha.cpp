#include "wolfram/alpha.hpp"

#include <curl_wrapper/curl_wrapper.hpp>

namespace wolfram {
    const std::string API_BASE = "https://api.wolframalpha.com/v1/result";

    std::string simple_query(const std::string& appid, const std::string& query) {
        using curl_wrapper::url_encode;
        using curl_wrapper::http_get_string;
        const auto url = API_BASE + "?appid=" + url_encode(appid) + "&i=" + url_encode(query);
        return http_get_string(url);
    }
}