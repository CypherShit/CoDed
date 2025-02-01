#pragma once

#include <core/decoder/decoder.h>
#include <core/encoder/encoder.h>
#include <core/salt/salt.h>

#include <string>
#include <string_view>

namespace core {

template <typename SaltImpl>
class Algo : public Encoder<SaltImpl>, public Decoder<SaltImpl> {
public:
    const Encoder<SaltImpl>& GetEncoder() const;
    const Decoder<SaltImpl>& GetDecoder() const;

protected:
    virtual std::string Decode(std::string_view view, const Salt<SaltImpl>& salt) const = 0;
    virtual std::string Encode(std::string_view view, const Salt<SaltImpl>& salt) const = 0;
};

} // namespace core
