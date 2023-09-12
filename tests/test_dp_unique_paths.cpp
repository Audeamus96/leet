#include "..\solutions\headers\dp_unique_paths.hpp"
#include "..\catch.hpp"

TEST_CASE("Test dp_unique_paths") {
    REQUIRE(uniquePaths(1,1) == 1);
    REQUIRE(uniquePaths(1,7) == 1);
    REQUIRE(uniquePaths(7,1) == 1);
    REQUIRE(uniquePaths(3,2) == 3);
    REQUIRE(uniquePaths(3,7) == 28);
    // REQUIRE(uniquePaths(10,15) == 817190);
}
