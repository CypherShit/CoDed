#pragma once

#include <span>
#include <cstddef>
#include <string_view>


template<class SaltImpl>
class Salt {
public:
    Salt(std::span<std::byte> deserializedSalt);

    static std::span<std::byte> Serialize(const Salt &salt) {
        return SaltImpl::Serialize(salt);
    }

    static Salt Deserialize(std::span<std::byte> deserializedSalt) {
        return SaltImpl::Deserialize(deserializedSalt);
    }

    static void WriteToFile(std::string_view view) {
        SaltImpl::WriteToFile(view);
    }

    static Salt ReadFromFile(std::string_view view){
        return SaltImpl::ReadFromFile(view);
    }
};
