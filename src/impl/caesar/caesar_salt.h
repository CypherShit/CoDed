#pragma once

#include <fstream>
#include <vector>

#include <core/salt/salt.h>

namespace coded::impl::caesar {

class CaesarSaltImpl : public core::Salt<CaesarSaltImpl> {
  CaesarSaltImpl(std::span<std::byte> deserializedSalt) : core::Salt<CaesarSaltImpl>{deserializedSalt} {
  }

  static std::span<std::byte> Serialize(const core::Salt<CaesarSaltImpl> & /*salt*/) { return {}; }

  static CaesarSaltImpl Deserialize(std::span<std::byte> deserializedSalt) {
    return CaesarSaltImpl{deserializedSalt};
  }

  static void WriteToFile(std::string_view /*filename*/) {}

  static CaesarSaltImpl ReadFromFile(std::string_view filename) {
    std::ifstream file(filename.data(), std::ios::binary);
    if (!file.is_open()) {
      throw std::runtime_error("Could not open file for reading");
    }
 
    file.seekg(0, std::ios::end);
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);
 
    std::vector<std::byte> buffer(size);

    if (!file.read(reinterpret_cast<char*>(buffer.data()), size)) {
      throw std::runtime_error("Error reading file");
    }

    return CaesarSaltImpl{std::span<std::byte>(buffer)};
  }
};

} // namespace coded::impl::caesar
