#include "catch2/catch_test_macros.hpp"

TEST_CASE (
"Test Case"
)
{
    SECTION("Section 1")
    {
        REQUIRE(1 == 1);
    }
    SECTION("Section 2")
    {
        REQUIRE(1 != 1 + 3 );
    }
}
