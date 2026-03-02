#pragma once

#include <vector>
#include <memory>
#include "flow/flow.hpp"

namespace vp {

class FlowStore {
public:
    void add(std::shared_ptr<Flow> flow);
    const std::vector<std::shared_ptr<Flow>>& all() const;

private:
    std::vector<std::shared_ptr<Flow>> flows_;
};

}