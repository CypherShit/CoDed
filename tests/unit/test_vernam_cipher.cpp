#include <gtest/gtest.h>

#include <impl/vernam/vernam_algo.h>

using namespace coded::impl::vernam;

TEST(TestVernam, SimpleKey) {
    std::string testString = "abacaba";
    VernamAlgo algo("aboba");

    const core::Decoder &decoder = algo.GetDecoder();
    const core::Encoder &encoder = algo.GetEncoder();

    const std::string encodedString = encoder.Encode(testString);
    const std::string decodedString = decoder.Decode(encodedString);

    ASSERT_EQ(decodedString, testString);
}

TEST(TestVernam, AdvancedKey) {
    std::string testString = "abacaba";
    VernamAlgo algo("asdfghjkllkjhgfdsz");

    const core::Decoder &decoder = algo.GetDecoder();
    const core::Encoder &encoder = algo.GetEncoder();

    const std::string encodedString = encoder.Encode(testString);
    const std::string decodedString = decoder.Decode(encodedString);

    ASSERT_EQ(decodedString, testString);
}
