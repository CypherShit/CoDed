#pragma once

#include <core/decoder/decoder.h>
#include <core/encoder/encoder.h>

#include <string>
#include <string_view>

namespace core {

class Algo : public Encoder, public Decoder {
public:
    const Encoder& GetEncoder() const;
    const Decoder& GetDecoder() const;

protected:
    virtual std::string Decode(std::string_view view) const = 0;
    virtual std::string Encode(std::string_view view) const = 0;
};

} // namespace core
