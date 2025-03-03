#pragma once

#include <core/algo/algo.h>
#include <string_view>

namespace coded::impl::trithemius {

class TrithemiusCipherAlgo : public core::Algo {
public:
    TrithemiusCipherAlgo() = default;

    std::string Decode(std::string_view view) const override;
    std::string Encode(std::string_view view) const override;

private:
    static std::string Transform(std::string_view view, bool encode);
};

}  // namespace coded::impl::trithemius
