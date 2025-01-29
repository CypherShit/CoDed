#pragma once

#include "../../core/salt/salt.h"

namespace coded::impl::caesar {

class CaesarSaltImpl : public Salt<CaesarSaltImpl> {
  static std::span<std::byte> Serialize(const Salt & /*salt*/) { return {}; }

  static CaesarSaltImpl Deserialize(std::span<std::byte> /*deserializedSalt*/) {
    return {};
  }

  static void WriteToFile(std::string_view /*filename*/) {}

  static CaesarSaltImpl ReadFromFile(std::string_view /*filename*/) {
    return {};
  }
};

} // namespace coded::impl::caesar
