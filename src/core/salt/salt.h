#pragma once

#include <span>
#include <cstddef>
#include <string_view>

namespace core {

template<typename SaltImpl>
class Salt {
public:
    Salt() = default;
    
    explicit Salt(std::span<std::byte> deserializedSalt);

    static std::span<std::byte> Serialize(const Salt &salt) {
        return SaltImpl::Serialize(salt);
    }

    static Salt Deserialize(std::span<std::byte> deserializedSalt) {
        return SaltImpl::Deserialize(deserializedSalt);
    }

    static void WriteToFile(std::string_view filename) {
        SaltImpl::WriteToFile(filename);
    }

    static Salt ReadFromFile(std::string_view filename){
        return SaltImpl::ReadFromFile(filename);
    }
};

} // namespace core
