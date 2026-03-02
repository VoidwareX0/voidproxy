#include "http/parser.hpp"
#include <sstream>

namespace vp {

bool HttpParser::parse_request(const std::string& raw, HttpRequest& req) {
    std::istringstream stream(raw);
    stream >> req.method >> req.uri >> req.version;
    return true;
}

}