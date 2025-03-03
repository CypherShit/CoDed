#include <gtest/gtest.h>

#include <core/decoder/decoder.h>
#include <core/encoder/encoder.h>
#include <impl/trithemius/trithemius_algo.h>

using namespace coded::impl::trithemius;

TEST(TrithemiusCipherAlgoTest, HandlesCase) {
    TrithemiusCipherAlgo algo;

    std::string input = "HelloWorld";
    std::string expectedEncoded = "HfnosYtver";  

    std::string encoded = algo.Encode(input);
    EXPECT_EQ(encoded, expectedEncoded);

    std::string decoded = algo.Decode(encoded);
    EXPECT_EQ(decoded, input);
}
