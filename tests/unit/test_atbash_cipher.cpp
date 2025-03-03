#include <gtest/gtest.h>

#include <core/decoder/decoder.h>
#include <core/encoder/encoder.h>
#include <impl/atbash/atbash_algo.h>

using namespace coded::impl::atbash;

TEST(TestAtbash, HandlesBasicEncryptionDecryption) {
    std::string testString = "HelloWorld";
    AtbashCipherAlgo algo;  

    const core::Decoder& decoder = algo.GetDecoder();
    const core::Encoder& encoder = algo.GetEncoder();

    const std::string encodedString = encoder.Encode(testString);
    ASSERT_EQ(encodedString, "SvoolDliow"); 

    const std::string decodedString = decoder.Decode(encodedString);
    ASSERT_EQ(decodedString, testString);
}