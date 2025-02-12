#include "playfair_algo.h"

#include <cassert>
#include <algorithm>
#include <random>

namespace coded::impl::playfair {

PlayfairCipherAlgo::PlayfairCipherAlgo(const std::string &salt, uint32_t edge) {
    assert(salt.size() % edge == 0);
    this->edge = edge;
    this->salt = stringToSalt(salt);
    this->fillRevSalt();
}

PlayfairCipherAlgo::PlayfairCipherAlgo(
    const std::unordered_map<char, std::pair<uint32_t, uint32_t>> &salt,
    uint32_t edge
) {
    assert(salt.size() % edge == 0);
    this->edge = edge;
    this->salt = salt;
    this->fillRevSalt();
}

std::string PlayfairCipherAlgo::Decode(std::string_view view) const {
    assert(view.size() % 2 == 0);

    std::string result;

    for (size_t i = 0; i < view.size(); i += 2) {
        auto [first_row, first_column] = salt.at(view[i]);
        auto [second_row, second_column] = salt.at(view[i + 1]);

        if (first_row == second_row) {
            result += rev_salt[first_row][(first_column + edge - 1) % edge];
            result += rev_salt[second_row][(second_column + edge - 1) % edge];
        } else if (first_column == second_column) {
            result += rev_salt[(first_row + edge - 1) % (edge / 2)][first_column];
            result += rev_salt[(second_row + edge - 1) % (edge / 2)][second_column];
        } else {
            result += rev_salt[first_row][second_column];
            result += rev_salt[second_row][first_column];
        }
    }

    return result;
}

std::string PlayfairCipherAlgo::Encode(std::string_view view) const {
    std::string preparedText = prepareText(view);
    std::string result;

    for (size_t position = 0; position < preparedText.size(); position += 2) {
        auto [first_row, first_column] = salt.at(preparedText[position]);
        auto [second_row, second_column] = salt.at(preparedText[position + 1]);

        if (first_row == second_row) {
            result += rev_salt[first_row][(first_column + 1) % edge];
            result += rev_salt[second_row][(second_column + 1) % edge];
        } else if (first_column == second_column) {
            result += rev_salt[(first_row + 1) % (edge / 2)][first_column];
            result += rev_salt[(second_row + 1) % (edge / 2)][second_column];
        } else {
            result += rev_salt[first_row][second_column];
            result += rev_salt[second_row][first_column];
        }
    }

    return result;
}

void PlayfairCipherAlgo::genSalt(uint32_t edge) {
    std::string asciiString;
    for (unsigned char c = 0; c < 128; c++) {
        asciiString += c;
    }

    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(asciiString.begin(), asciiString.end(), rng);

    this->salt = stringToSalt(asciiString);
    this->fillRevSalt();
}

void PlayfairCipherAlgo::setSalt(const std::string &salt) {
    this->salt = stringToSalt(salt);
    this->fillRevSalt();
}

void PlayfairCipherAlgo::setSalt(
    const std::unordered_map<char, std::pair<uint32_t, uint32_t>> &salt,
    uint32_t edge
) {
    assert(salt.size() % edge == 0);
    this->salt = salt;
    this->fillRevSalt();
}

std::unordered_map<char, std::pair<uint32_t, uint32_t>>
PlayfairCipherAlgo::getSalt() const {
    return this->salt;
}

std::unordered_map<char, std::pair<uint32_t, uint32_t>>
PlayfairCipherAlgo::stringToSalt(const std::string &salt) {
    std::unordered_map<char, std::pair<uint32_t, uint32_t>> salt_map;
    for (auto row = 0; row < edge; row++) {
        for (auto column = 0; column < edge; column++) {
            const auto pos = row * edge + column;
            if (salt.size() == pos) {
                return salt_map;
            }
            salt_map[salt[pos]] = {row, column};
        }
    }
    return salt_map;
}

void PlayfairCipherAlgo::fillRevSalt() {
    rev_salt.clear();
    rev_salt.resize(edge);
    for (auto &row : rev_salt) {
        row.resize(edge, -1);
    }
    for (const auto [symbol, position] : salt) {
        rev_salt[position.first][position.second] = symbol;
    }
}

std::string PlayfairCipherAlgo::prepareText(std::string_view view) {
    std::string prepared(view);
    if (prepared.size() % 2 == 1) {
        prepared.push_back(char{0});
    }
    return prepared;
}

}  // namespace coded::impl::playfair
