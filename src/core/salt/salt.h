#pragma once

#include <span>
#include <cstddef>
#include <string_view>

template<typename T>
concept SaltImplConcept = requires(T t, std::span<std::byte> deserializedSalt, std::string_view view) {
    {t.Serialize} -> std::same_as<std::span<std::byte>>;
    {t.Deserialize(deserializedSalt)};
    {t.WriteToFile(view)} -> std::same_as<void>;
    {t.ReadFromFile(view)};
};

template<SaltImplConcept SaltImpl>
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
