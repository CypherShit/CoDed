#include "algo.h"
#include <encoder/encoder.h>

namespace core {

const Encoder& Algo::GetEncoder() const {
    return *this;
}

const Decoder& Algo::GetDecoder() const {
    return *this;
}

} // namespace core
