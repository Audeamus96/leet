// Leetcode 141: https://leetcode.com/problems/linked-list-cycle/
// Note: this question is weird in that it asks you to track the position of the node at the end of the loop
// but you don't return it  or anything.

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "utils\catch.hpp"
#include <unordered_map>
#include <cstdint>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };

// returns true if the linked list has a loop in it.
bool hasCycle(ListNode *head) {
    if(head == nullptr)
        return false;

    std::unordered_map<uintptr_t, int> umap;
    int p = -1;
    int idx = 0;
    ListNode *curr = head;

    while(curr->next != nullptr){
        if(auto srch_itr = umap.find(curr->next->val); srch_itr != umap.end()){
            p = srch_itr->first;
            printf("%i\n", p);
            return true;
        }

        umap.insert({reinterpret_cast<uintptr_t>(curr), idx});
        printf("%li", reinterpret_cast<uintptr_t>(curr));
        idx++;
        curr = curr->next;
    }

    printf("%i\n", p);
    return false;
}

// ---------- Tests -----------
TEST_CASE("Empty List") {
    REQUIRE_FALSE(hasCycle(nullptr));
}

TEST_CASE( "Simple linked list", "[hasCycle]" ) {
    ListNode head = ListNode(1);
    ListNode n0 = ListNode(2);
    head.next = &n0;

    SECTION("no loop"){
        REQUIRE_FALSE(hasCycle(&head));
    }
    
    SECTION("loop 1"){
        n0.next = &head;
        REQUIRE(hasCycle(&head));
    }

    SECTION("no loop - longer list"){
        ListNode n1 = ListNode(0);
        ListNode n2 = ListNode(-4);
        n0.next = &n1;
        n1.next = &n2;
        REQUIRE_FALSE(hasCycle(&head));
    }

    SECTION("loop - longer list"){
        ListNode n1 = ListNode(0);
        ListNode n2 = ListNode(-4);
        n0.next = &n1;
        n1.next = &n2;
        n2.next = &n0;
        REQUIRE(hasCycle(&head));
    }
}

// TEST_CASE("Complex List") {
//     ListNode head = ListNode(-21);
//     ListNode n0 = ListNode(10);
//     ListNode n1 = ListNode(17);
//     ListNode n2 = ListNode(8);
//     ListNode n3 = ListNode(4);
//     ListNode n4 = ListNode(26);
//     ListNode n5 = ListNode(5);
//     ListNode n6 = ListNode(35);
//     ListNode n7 = ListNode(-7);
//     ListNode n8 = ListNode(14);
//     ListNode n9 = ListNode(14);
//     ListNode n10 = ListNode(5);
//     head.next = &n0;
//     n0.next = &n1;
//     n1.next = &n2;
//     n2.next = &n3;
//     n3.next = &n4;
//     n4.next = &n5;
//     n5.next = &n6;
//     n6.next = &n7;
//     n7.next = &n8;
//     n8.next = &n9;
//     n9.next = &n10;
//     REQUIRE_FALSE(hasCycle(&head));

// }



