#pragma once

#include <salt/salt.h>

#include <string>
#include <string_view>

namespace core {

template <SaltImplConcept SaltImpl>
class Decoder {
public:
    virtual std::string Decode(std::string_view view, const Salt<SaltImpl>& salt) const = 0;
};

} // namespace core
