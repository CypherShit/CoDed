#include <gtest/gtest.h>

#include <core/decoder/decoder.h>
#include <core/encoder/encoder.h>
#include <impl/playfair/playfair_algo.h>

#include "helper.h"

using namespace coded::impl::playfair;

TEST(TestPayfair, Base) {
    std::string testString = "abacabae";
    PlayfairCipherAlgo algo;
    algo.genSalt();

    const core::Decoder& decoder = algo.GetDecoder();
    const core::Encoder& encoder = algo.GetEncoder();

    const std::string encodedString = encoder.Encode(testString);

    const std::string decodedString = decoder.Decode(encodedString);

    ASSERT_EQ(decodedString, testString);
}

TEST(TestPayfair, Advance) {
    std::string testString = genString(20);
    PlayfairCipherAlgo algo;
    algo.genSalt();

    const core::Decoder& decoder = algo.GetDecoder();
    const core::Encoder& encoder = algo.GetEncoder();

    const std::string encodedString = encoder.Encode(testString);

    const std::string decodedString = decoder.Decode(encodedString);

    ASSERT_EQ(decodedString, testString);
}
