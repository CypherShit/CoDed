#include <gtest/gtest.h>

#include <core/decoder/decoder.h>
#include <core/encoder/encoder.h>
#include <impl/caesar/caesar_algo.h>

namespace {

int Factorial(int n) {
    if (n < 0) return -1;
    int res = 1;
    if (n < 2) return 1; 
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

} // namespace

using namespace coded::impl::caesar;

TEST(TestFactorial, HandlesZeroInput) {
    ASSERT_EQ(1, Factorial(0));
}

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

int main(int argc, char**argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
