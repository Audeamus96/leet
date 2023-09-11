#include "..\catch.hpp"
#include "..\solutions\headers\dp_coins_2.hpp"

TEST_CASE("Test dp_coins_2 naive") {
    REQUIRE(num_ways_naive(0, {1, 4, 5}) == 1);
    REQUIRE(num_ways_naive(5, {1, 4, 5}) == 4);
    REQUIRE(num_ways_naive(6, {1, 4, 5}) == 6);
}

TEST_CASE("Test dp_coins_2 dp") {
    REQUIRE(num_ways_dp(0, {1, 4, 5}) == 1);
    REQUIRE(num_ways_dp(5, {1, 4, 5}) == 4);
    REQUIRE(num_ways_dp(6, {1, 4, 5}) == 6);
    REQUIRE(num_ways_dp(87, {1, 4, 5, 8}) == 3306149332861088);
}
