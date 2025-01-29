#pragma once

#include <salt/salt.h>

#include <string>
#include <string_view>

class Encoder {
public:
    virtual std::string Encode(std::string_view view, const Salt& salt);
};
