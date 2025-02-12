#pragma once

#include "../core/algo/algo.h"

#include <array>
#include <climits>
#include <cstdint>
#include <string>
#include <string_view>
#include <sys/stat.h>
#include <vector>

namespace coded::impl::rc4 {

class RC4Algo : public core::Algo {
public:
  RC4Algo();
  RC4Algo(const std::string &key);
  RC4Algo(std::string &&key);

  virtual ~RC4Algo() = default;

private:
  virtual std::string Encode(std::string_view decodedString) const override;
  virtual std::string Decode(std::string_view encodedString) const override;

  std::string Process(std::string_view payload) const;

  void InitializeKeyBlock(const std::string &key);

private:
  constexpr inline static std::int16_t ALPH_MAX_VALUE = CHAR_MAX;
  constexpr inline static std::int16_t ALPH_MIN_VALUE = CHAR_MIN;
  constexpr inline static int DEFAULT_KEY_LENGTH = 25;

  constexpr inline static std::size_t KEY_BLOCK_SIZE = 256;

  std::array<std::uint8_t, KEY_BLOCK_SIZE> key_block_;
};

} // namespace coded::impl::rc4
