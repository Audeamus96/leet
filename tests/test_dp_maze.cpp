#include "..\solutions\headers\dp_maze.hpp"
#include "..\catch.hpp"

TEST_CASE("Test dp_maze naive") {
    REQUIRE(maze_paths_naive(1,4) == 1);
    REQUIRE(maze_paths_naive(1,3) == 1);
    REQUIRE(maze_paths_naive(2,2) == 2);
    REQUIRE(maze_paths_naive(18,6) == 26334);
}

TEST_CASE("Test dp_maze dp") {
    REQUIRE(maze_paths_dp(1,4) == 1);
    REQUIRE(maze_paths_dp(1,3) == 1);
    REQUIRE(maze_paths_dp(2,2) == 2);
    REQUIRE(maze_paths_dp(18,6) == 26334);
    REQUIRE(maze_paths_dp(75,19) == 5873182941643167150);
}
