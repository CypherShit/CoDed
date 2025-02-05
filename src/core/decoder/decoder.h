#pragma once

#include <string>
#include <string_view>

namespace core {

class Decoder {
public:
    virtual std::string Decode(std::string_view view) const = 0;
};

} // namespace core
