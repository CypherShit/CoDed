#pragma once

#include "../core/algo/algo.h"

#include <cstdint> 
#include <string_view>


namespace coded::impl::caesar {

class CaesarCipherAlgo : public core::Algo {
public:
  CaesarCipherAlgo() = default;

  CaesarCipherAlgo(std::uint32_t shift);

  std::string Decode(std::string_view view) const override;

  std::string Encode(std::string_view view) const override;

  void setShift(std::uint32_t shift);

private:
  std::uint32_t shift_ = 1;

private:
  std::string ShiftString(std::string_view view, int shift) const;
};

} // namespace coded::impl::caesar
