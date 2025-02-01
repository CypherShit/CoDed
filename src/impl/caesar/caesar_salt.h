#pragma once

#include <core/salt/salt.h>

namespace coded::impl::caesar {

class CaesarSaltImpl : public core::Salt<CaesarSaltImpl> {
  static std::span<std::byte> Serialize(const core::Salt<CaesarSaltImpl> & /*salt*/) { return {}; }

  static CaesarSaltImpl Deserialize(std::span<std::byte> /*deserializedSalt*/) {
    return {};
  }

  static void WriteToFile(std::string_view /*filename*/) {}

  static CaesarSaltImpl ReadFromFile(std::string_view /*filename*/) {
    return {};
  }
};

} // namespace coded::impl::caesar
