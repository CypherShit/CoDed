#include "rc4_algo.h"

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <random>
#include <string>
#include <string_view>

namespace {

constexpr std::uint16_t DEFAULT_KEY_LENGTH = 25;

std::string GenerateRandomKey() {
  static std::uniform_int_distribution<int> DISTRIBUTION(CHAR_MIN, CHAR_MAX);

  std::default_random_engine generator;
  std::string result;
  result.reserve(DEFAULT_KEY_LENGTH);

  std::generate_n(std::back_inserter(result), DEFAULT_KEY_LENGTH,
                  [&]() { return DISTRIBUTION(generator); });

  return result;
}

} // namespace

namespace coded::impl::rc4 {

RC4Algo::RC4Algo() { InitializeKeyBlock(GenerateRandomKey()); }

RC4Algo::RC4Algo(std::string &&key) { InitializeKeyBlock(std::move(key)); }

RC4Algo::RC4Algo(const std::string &key) { InitializeKeyBlock(key); }

std::string RC4Algo::Encode(std::string_view payload) const {
  return Process(payload);
}

std::string RC4Algo::Decode(std::string_view payload) const {
  return Process(payload);
}

std::string RC4Algo::Process(std::string_view payload) const {
  std::string result(payload.size(), ' ');

  std::array<std::uint8_t, KEY_BLOCK_SIZE> key_block = key_block_;

  size_t i = 0;
  size_t j = 0;
  for (size_t k = 0; k < payload.size(); ++k) {
    i = (i + 1) % KEY_BLOCK_SIZE;
    j = (j + key_block[i]) % KEY_BLOCK_SIZE;
    std::swap(key_block[i], key_block[j]);
    std::uint8_t rnd =
        key_block[(key_block[i] + key_block[j]) % KEY_BLOCK_SIZE];
    result[k] = payload[k] ^ rnd;
  }

  return result;
}

void RC4Algo::InitializeKeyBlock(const std::string &key) {
  for (size_t i = 0; i < KEY_BLOCK_SIZE; ++i) {
    key_block_[i] = static_cast<uint8_t>(i);
  }

  size_t j = 0;
  for (size_t i = 0; i < KEY_BLOCK_SIZE; ++i) {
    j = (j + key_block_[i] + key[i % key.size()]) % KEY_BLOCK_SIZE;
    std::swap(key_block_[i], key_block_[j]);
  }
}

} // namespace coded::impl::rc4
