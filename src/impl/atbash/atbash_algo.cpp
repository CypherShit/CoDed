#include "atbash_algo.h"
#include <string>

namespace coded::impl::atbash {

std::string AtbashCipherAlgo::Decode(std::string_view view) const {
    return Transform(view);
}

std::string AtbashCipherAlgo::Encode(std::string_view view) const {
    return Transform(view);
}

std::string AtbashCipherAlgo::Transform(std::string_view view) {
    std::string result(view.begin(), view.end()); 

    for (char &c : result) {
        if (std::isalpha(c)) {
            if (std::islower(c))
                c = 'z' - (c - 'a');
            else
                c = 'Z' - (c - 'A');
        }
    }
    return result;
}

}  // namespace coded::impl::atbash
