#include "..\solutions\headers\dp_max_subarray.hpp"
#include "..\catch.hpp"

TEST_CASE("Test dp_max_subarray") {
    std::vector<int> nums;

    SECTION("Single Element Vector"){
        nums = {1};
        REQUIRE(maxSubArray(nums) == 1);
    }

    SECTION("Two Element Vector"){
        nums = {-2, 1};
        REQUIRE(maxSubArray(nums) == 1);
    }

    SECTION("Standard Example"){
        nums = {-2,1,-3,4,-1,2,1,-5,4};
        REQUIRE(maxSubArray(nums) == 6);
    }

    SECTION("Standard Example 2"){
        nums = {5,4,-1,7,8};
        REQUIRE(maxSubArray(nums) == 23);
    }

    SECTION("All Negatives"){
        nums = {-2,-3,-4,-4,-5};
        REQUIRE(maxSubArray(nums) == -2);
    }

}
