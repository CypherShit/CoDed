#include <core/decoder/decoder.h>
#include <core/encoder/encoder.h>
#include <gtest/gtest.h>
#include <impl/rc4/rc4_algo.h>

using namespace coded::impl::rc4;

TEST(TestRc4, SimpleKey) {
    std::string testString = "abacaba";
    RC4Algo algo("aboba");

    const core::Decoder &decoder = algo.GetDecoder();
    const core::Encoder &encoder = algo.GetEncoder();

    const std::string encodedString = encoder.Encode(testString);
    const std::string decodedString = decoder.Decode(encodedString);

    ASSERT_EQ(decodedString, testString);
}

TEST(TestRc4, AdvancedKey) {
    std::string testString = "abacaba";
    RC4Algo algo("asdfghjkllkjhgfdsz");

    const core::Decoder &decoder = algo.GetDecoder();
    const core::Encoder &encoder = algo.GetEncoder();

    const std::string encodedString = encoder.Encode(testString);
    const std::string decodedString = decoder.Decode(encodedString);

    ASSERT_EQ(decodedString, testString);
}
