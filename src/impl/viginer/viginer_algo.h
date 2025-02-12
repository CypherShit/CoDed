#pragma once

#include <core/algo/algo.h>

#include <climits>
#include <cstdint>
#include <string>
#include <string_view>
#include <sys/stat.h>

namespace coded::impl::viginer {

class ViginerAlgo : public core::Algo {
public:
    ViginerAlgo();
    ViginerAlgo(const std::string& key);
    ViginerAlgo(std::string&& key);

    void SetKey(const std::string& key);
    void SetKey(std::string&& key);

    virtual ~ViginerAlgo() = default;

private:
    virtual std::string Encode(std::string_view decodedString) const override;
    virtual std::string Decode(std::string_view encodedString) const override;

    static char ShiftValue(char symbol, char shiftValue, bool isDecode = false);
    static std::string GenerateRandomKey();

private:
    std::string key_;

    constexpr inline static std::int16_t ALPH_MAX_VALUE = CHAR_MAX;
    constexpr inline static std::int16_t ALPH_MIN_VALUE = CHAR_MIN;
    constexpr inline static int DEFAULT_KEY_LENGTH = 25;
};

} // namespace coded::impl::viginer
