#pragma once

#include "http/request.hpp"
#include <string>

namespace vp {

class HttpParser {
public:
    static bool parse_request(const std::string& raw, HttpRequest& req);
};

}