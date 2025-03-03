#include "trithemius_algo.h"
#include <string>

namespace coded::impl::trithemius {

std::string TrithemiusCipherAlgo::Decode(std::string_view view) const {
    return Transform(view, false);
}

std::string TrithemiusCipherAlgo::Encode(std::string_view view) const {
    return Transform(view, true);
}

std::string TrithemiusCipherAlgo::Transform(std::string_view view, bool encode) {
    std::string result;
    result.reserve(view.size());

    int shift = 0; 

    for (char ch : view) {
        if (std::isalpha(ch)) {
            char base = std::islower(ch) ? 'a' : 'A';
            char newChar = static_cast<char>((ch - base + (encode ? shift : -shift) + 26) % 26 + base);
            result.push_back(newChar);
            shift++;  
        } else {
            result.push_back(ch);  
        }
    }

    return result;
}

}  // namespace coded::impl::trithemius
