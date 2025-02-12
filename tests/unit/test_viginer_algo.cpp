#include <climits>
#include <gtest/gtest.h>

#include <core/decoder/decoder.h>
#include <core/encoder/encoder.h>
#include <impl/viginer/viginer_algo.h>


using namespace coded::impl::viginer;

TEST(DefaultTestViginer, HandlesZeroInput) {
    const std::string testString = "abacaba";
    const ViginerAlgo algo;

    const core::Decoder& decoder = algo.GetDecoder();
    const core::Encoder& encoder = algo.GetEncoder();

    const std::string encodedString = encoder.Encode(testString);
    const std::string decodedString = decoder.Decode(encodedString);

    ASSERT_EQ(decodedString, testString);
}

TEST(TestCustomKey, HandlesZeroInput) {
    const std::string testString = "abacaba";
    std::string customKey;
    customKey.push_back(static_cast<char>(0));

    const ViginerAlgo algo(customKey);

    const core::Decoder& decoder = algo.GetDecoder();
    const core::Encoder& encoder = algo.GetEncoder();

    const std::string encodedString = encoder.Encode(testString);

    ASSERT_EQ(encodedString, testString);

    const std::string decodedString = decoder.Decode(encodedString);

    ASSERT_EQ(decodedString, testString);
}

TEST(TestChangeKey, HandlesZeroInput) {
    const std::string testString = "testString";

    ViginerAlgo algo("testKey");

    const core::Decoder& decoder = algo.GetDecoder();
    const core::Encoder& encoder = algo.GetEncoder();

    const std::string encodedString = encoder.Encode(testString);

    algo.SetKey("new");

    const std::string decodedString = decoder.Decode(encodedString);

    ASSERT_NE(decodedString, testString);
}

TEST(TestViginerOverflow, HandlesZeroInput) {
    const std::string testString = "testOverflow";

    std::string maxKey;
    maxKey.push_back(CHAR_MAX);

    const ViginerAlgo algo(maxKey);

    const core::Decoder& decoder = algo.GetDecoder();
    const core::Encoder& encoder = algo.GetEncoder();

    const std::string encodedString = encoder.Encode(testString);
    const std::string decodedString = decoder.Decode(encodedString);

    ASSERT_EQ(decodedString, testString);
}
