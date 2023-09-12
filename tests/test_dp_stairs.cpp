#include "..\solutions\headers\dp_stairs.hpp"
#include "..\catch.hpp"

TEST_CASE("Test dp_stairs") {
    REQUIRE(climbStairs_improved(0) == 1);
    REQUIRE(climbStairs_improved(1) == 1);
    REQUIRE(climbStairs_improved(14) == 610);
}
