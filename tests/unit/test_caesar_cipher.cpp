#include <gtest/gtest.h>

#include <core/decoder/decoder.h>
#include <core/encoder/encoder.h>
#include <impl/caesar/caesar_algo.h>

using namespace coded::impl::caesar;

TEST(TestCeasar, HandlesZeroInput) {
    std::string testString = "abacaba";
    CaesarCipherAlgo algo(1);

    const core::Decoder& decoder = algo.GetDecoder();
    const core::Encoder& encoder = algo.GetEncoder();

    const std::string encodedString = encoder.Encode(testString);

    ASSERT_EQ(encodedString, "bcbdbcb");

    const std::string decodedString = decoder.Decode(encodedString);

    ASSERT_EQ(decodedString, testString);
}
