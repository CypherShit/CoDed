#pragma once

#include <salt/salt.h>

#include <string>
#include <string_view>

namespace core {

template <SaltImplConcept SaltImpl>
class Encoder {
public:
    virtual std::string Encode(std::string_view view, const Salt<SaltImpl>& salt) const = 0;
};

} // namespace core
