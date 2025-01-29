#pragma once

#include "../../core/algo/algo.h"

namespace coded::impl::caesar {

class CaesarCipherAlgo : public Algo<CaesarSaltImpl> {
public:
  std::string Decode(std::string_view view,
                     const Salt<CaesarSaltImpl> & /*salt*/) const override {
    return ShiftString(view, -shift_);
  }

  std::string Encode(std::string_view view,
                     const Salt<CaesarSaltImpl> & /*salt*/) const override {
    return ShiftString(view, shift_);
  }

private:
  std::uint32_t shift_ = 3;

private:
  std::string ShiftString(std::string_view view, int shift) const {
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
}

} // namespace coded::impl::caesar
