#pragma once

#include <decoder/decoder.h>
#include <encoder/encoder.h>
#include <salt/salt.h>

#include <string>
#include <string_view>

namespace core {

class Algo : public Encoder, public Decoder {
public:
    const Encoder& GetEncoder() const;
    const Decoder& GetDecoder() const;

protected:
    virtual std::string Decode(std::string_view view, const Salt& salt) const = 0;
    virtual std::string Encode(std::string_view view, const Salt& salt) const = 0;
};

} // namespace core
