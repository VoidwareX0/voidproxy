#pragma once

#include <string>
#include <unordered_map>

namespace vp {

class HttpResponse {
public:
    std::string version;
    int status_code;
    std::string reason;
    std::unordered_map<std::string, std::string> headers;
    std::string body;
};

}