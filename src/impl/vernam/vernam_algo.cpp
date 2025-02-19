#include "vernam_algo.h"

namespace coded::impl::vernam {

VernamAlgo::VernamAlgo() = default;

VernamAlgo::VernamAlgo(const std::string &key) : key_(key) {}

VernamAlgo::VernamAlgo(std::string &&key) : key_(std::move(key)) {}

std::string VernamAlgo::Encode(std::string_view decodedString) const {
    return Process(decodedString);
}

std::string VernamAlgo::Decode(std::string_view encodedString) const {
    return Process(encodedString);
}

std::string VernamAlgo::Process(std::string_view payload) const {
    std::string result;
    result.reserve(payload.size());
    const size_t key_len = key_.size();
    for (size_t i = 0; i < payload.size(); ++i) {
        char key_char = key_len == 0 ? 0 : key_[i % key_len];
        result.push_back(payload[i] ^ key_char);
    }
    return result;
}

} // namespace coded::impl::vernam
