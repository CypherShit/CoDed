#include "algo.h"
#include <encoder/encoder.h>

namespace core {
    
template <typename SaltImpl>
const Encoder<SaltImpl>& Algo<SaltImpl>::GetEncoder() const {
    return *this;
}

template <typename SaltImpl>
const Decoder<SaltImpl>& Algo<SaltImpl>::GetDecoder() const {
    return *this;
}

} // namespace core
