#include "..\solutions\headers\dp_fib.hpp"
#include "..\catch.hpp"

TEST_CASE("Fib 0 or 1") {
    REQUIRE(fib(0) == 0);
    REQUIRE(fib(1) == 1);
}

TEST_CASE("Fib n") {
    REQUIRE(fib(2) == 1);
    REQUIRE(fib(3) == 2);
    REQUIRE(fib(4) == 3);
    REQUIRE(fib(14) == 377);
}