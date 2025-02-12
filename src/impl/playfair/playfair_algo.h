#pragma once

#include <core/algo/algo.h>
#include <cstdint>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace coded::impl::playfair {

class PlayfairCipherAlgo : public core::Algo {
public:
    PlayfairCipherAlgo() = default;

    PlayfairCipherAlgo(const std::string &salt, uint32_t edge = 16);

    PlayfairCipherAlgo(
        const std::unordered_map<char, std::pair<uint32_t, uint32_t>> &salt,
        uint32_t edge = 16
    );

    std::string Decode(std::string_view view) const override;

    std::string Encode(std::string_view view) const override;

    void setSalt(const std::string &salt);

    void setSalt(
        const std::unordered_map<char, std::pair<uint32_t, uint32_t>> &salt,
        uint32_t edge = 16
    );

    void genSalt(uint32_t edge = 16);

    std::unordered_map<char, std::pair<uint32_t, uint32_t>> getSalt() const;

private:
    uint32_t edge = 16;
    std::unordered_map<char, std::pair<uint32_t, uint32_t>> salt;
    std::vector<std::vector<char>> rev_salt;

private:
    std::unordered_map<char, std::pair<uint32_t, uint32_t>> stringToSalt(
        const std::string &salt
    );

    void fillRevSalt();

    static std::string prepareText(std::string_view view);
};

}  // namespace coded::impl::playfair
