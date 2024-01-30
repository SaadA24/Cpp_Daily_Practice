#include <gtest/gtest.h>
#include "HeaderFiles/usefulFunctions.h"

TEST(testa, sum)
{
    GTEST_ASSERT_EQ(sum(20, 10), 30);
}

