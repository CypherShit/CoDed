#pragma once

#include <core/salt/salt.h>

#include <string>
#include <string_view>

namespace core {

template <typename SaltImpl>
class Decoder {
public:
    virtual std::string Decode(std::string_view view, const Salt<SaltImpl>& salt) const = 0;
};

} // namespace core
