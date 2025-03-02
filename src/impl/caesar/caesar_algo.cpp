#include "caesar_algo.h"

#include <string>

namespace coded::impl::caesar {

CaesarCipherAlgo::CaesarCipherAlgo(std::uint32_t shift) : shift_(shift) {
}

std::string CaesarCipherAlgo::Decode(std::string_view view) const {
    return ShiftString(view, -shift_);
}

std::string CaesarCipherAlgo::Encode(std::string_view view) const {
    return ShiftString(view, shift_);
}

void CaesarCipherAlgo::setShift(std::uint32_t shift) {
    shift_ = shift;
}

std::string CaesarCipherAlgo::ShiftString(std::string_view view, int shift) const {
    std::string result;
    result.reserve(view.size());

    for (char ch : view) {
        if (std::isalpha(ch)) {
        char base = std::islower(ch) ? 'a' : 'A';
        ch = static_cast<char>((ch - base + shift + 26) % 26 + base);
        }
        result.push_back(ch);
    }

    return result;
}

} // namespace coded::impl::caesar
