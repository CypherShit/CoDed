#pragma once

#include <core/algo/algo.h>
#include <string_view>

namespace coded::impl::atbash {

class AtbashCipherAlgo : public core::Algo {
public:
    AtbashCipherAlgo() = default;

    std::string Decode(std::string_view view) const override;
    std::string Encode(std::string_view view) const override;

private:
    static std::string Transform(std::string_view view);
};

}  // namespace coded::impl::atbash
