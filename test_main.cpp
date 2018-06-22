#include <gtest/gtest.h>
#include "lib.h"

TEST(version_test_case, version_test)
{
    EXPECT_GT(library1::version(), 0);
}

TEST(square_test_case, square_zero_test)
{
    EXPECT_EQ(library1::square(0), 0);
}

TEST(square_test_case, square_negative_test)
{
    EXPECT_EQ(library1::square(-2), 4);
}

TEST(square_test_case, square_pozitive_test)
{
    EXPECT_EQ(library1::square(2), 4);
}
