#pragma once

#include <core/salt/salt.h>

#include <string>
#include <string_view>

namespace core {

template <typename SaltImpl>
class Encoder {
public:
    virtual std::string Encode(std::string_view view, const Salt<SaltImpl>& salt) const = 0;
};

} // namespace core
