#pragma once

#include <vector>
#include <cstdint>

namespace vp {

class Buffer {
public:
    void append(const uint8_t* data, size_t size);
    const std::vector<uint8_t>& data() const;
    void clear();

private:
    std::vector<uint8_t> buffer_;
};

}