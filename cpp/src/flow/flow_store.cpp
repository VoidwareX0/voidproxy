#include "flow/flow_store.hpp"

namespace vp {

void FlowStore::add(std::shared_ptr<Flow> flow) {
    flows_.push_back(flow);
}

const std::vector<std::shared_ptr<Flow>>& FlowStore::all() const {
    return flows_;
}

}