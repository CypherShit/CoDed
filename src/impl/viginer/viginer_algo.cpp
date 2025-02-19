#include "viginer_algo.h"

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <random>
#include <string>
#include <string_view>

namespace coded::impl::viginer {

ViginerAlgo::ViginerAlgo() : key_(GenerateRandomKey()){
}

ViginerAlgo::ViginerAlgo(std::string&& key) : key_(key) {
}


ViginerAlgo::ViginerAlgo(const std::string& key) : key_(key) {
}

void ViginerAlgo::SetKey(const std::string& key) {
    key_ = key;
}

void ViginerAlgo::SetKey(std::string&& key) {
    std::swap(key_, key);
}

std::string ViginerAlgo::Encode(std::string_view decodedString) const {
    std::string result;
    result.reserve(decodedString.length());
    for (std::size_t index = 0, keyIndex = 0; index < decodedString.length(); index++, keyIndex++) {
        if (keyIndex >= key_.length()) {
            keyIndex -= key_.length();
        }

        result.push_back(ShiftValue(decodedString[index], key_[keyIndex]));
    }

    return result;
}

std::string ViginerAlgo::Decode(std::string_view encodedString) const {
    std::string result;
    result.reserve(encodedString.length());
    for (std::size_t index = 0, keyIndex = 0; index < encodedString.length(); index++, keyIndex++) {
        if (keyIndex >= key_.length()) {
            keyIndex -= key_.length();
        }

        result.push_back(ShiftValue(encodedString[index], key_[keyIndex], true));
    }

    return result;
}

char ViginerAlgo::ShiftValue(char symbol, char shiftValue, bool isDecode) {
    std::int16_t intSymbol = static_cast<std::int16_t>(symbol);
    std::int16_t intShift = static_cast<std::int16_t>(shiftValue);
    if (isDecode) {
        intShift = -intShift;
    }

    std::int16_t result = intSymbol + intShift;

    if (result > ALPH_MAX_VALUE) {
        result = ALPH_MIN_VALUE + result - ALPH_MAX_VALUE;
    }

    if (result < ALPH_MIN_VALUE) {
        result = ALPH_MAX_VALUE - (ALPH_MIN_VALUE - result);
    }

    return static_cast<char>(result);
}

std::string ViginerAlgo::GenerateRandomKey() {
    static std::uniform_int_distribution<int> DISTRIBUTION(CHAR_MIN, CHAR_MAX);

    std::default_random_engine generator;
    std::string result;
    result.reserve(DEFAULT_KEY_LENGTH);

    std::generate_n(std::back_inserter(result), DEFAULT_KEY_LENGTH, [&](){
        return DISTRIBUTION(generator);
    });

    return result;
}

} // namespace coded::impl::viginer
