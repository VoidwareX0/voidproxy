#include "utils/buffer.hpp"

namespace vp {

void Buffer::append(const uint8_t* data, size_t size) {
    buffer_.insert(buffer_.end(), data, data + size);
}

const std::vector<uint8_t>& Buffer::data() const {
    return buffer_;
}

void Buffer::clear() {
    buffer_.clear();
}

}