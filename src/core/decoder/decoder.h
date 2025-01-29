#pragma once

#include <salt/salt.h>

#include <string>
#include <string_view>

namespace core {

class Decoder {
public:
    virtual std::string Decode(std::string_view view, const Salt& salt) const = 0;
};

} // namespace core
