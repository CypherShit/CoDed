#pragma once

#include <algorithm>
#include <random>

inline std::string genString(uint32_t sz) {
    std::string asciiString;
    for (unsigned char c = 0; c < 128; c++) {
        asciiString += c;
    }

    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(asciiString.begin(), asciiString.end(), rng);
    return asciiString.substr(0, sz);
}
