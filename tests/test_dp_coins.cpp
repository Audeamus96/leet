#include "..\solutions\headers\dp_coins.hpp"
#include "..\catch.hpp"

TEST_CASE("Naive Tests") {
    REQUIRE(min_coins_naive(0, {1, 2, 5}) == 0);
    REQUIRE(min_coins_naive(13, {1, 4, 5}) == 3);
    //REQUIRE(min_coins_naive(150, {1, 4, 5}) == 30); // Very slow
}

TEST_CASE("Memo Tests") {
    REQUIRE(min_coins_memoized(0, {1, 2, 5}) == 0);
    REQUIRE(min_coins_memoized(13, {1, 4, 5}) == 3);
    // REQUIRE(min_coins_memoized(150, {1, 4, 5}) == 30);
}