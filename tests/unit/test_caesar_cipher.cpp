#include <gtest/gtest.h>

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

TEST(TestFactorial, HandlesZeroInput) {
    ASSERT_EQ(1, Factorial(0));
}

int main(int argc, char**argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
