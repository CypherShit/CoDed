#pragma once

#include <salt/salt.h>

#include <string>
#include <string_view>

namespace core {

class Encoder {
public:
    virtual std::string Encode(std::string_view view, const Salt& salt) const = 0;
};

} // namespace core
