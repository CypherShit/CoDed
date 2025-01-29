#pragma once

#include <span>
#include <cstddef>
#include <string_view>

namespace core {

template<typename T>
concept SaltImplConcept = requires(T t, std::span<std::byte> deserializedSalt, std::string_view filename) {
    {t.Serialize} -> std::same_as<std::span<std::byte>>;
    {t.Deserialize(deserializedSalt)};
    {t.WriteToFile(filename)} -> std::same_as<void>;
    {t.ReadFromFile(filename)};
};

template<SaltImplConcept SaltImpl>
class Salt {
public:
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
