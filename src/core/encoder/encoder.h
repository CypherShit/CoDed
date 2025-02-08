#pragma once

#include <string>
#include <string_view>

namespace core {

class Encoder {
public:
    virtual std::string Encode(std::string_view view) const = 0;
};

} // namespace core
