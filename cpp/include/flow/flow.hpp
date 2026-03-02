#pragma once

#include "http/request.hpp"
#include "http/response.hpp"

namespace vp {

class Flow {
public:
    HttpRequest request;
    HttpResponse response;
};

}