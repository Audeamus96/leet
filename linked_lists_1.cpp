// Leetcode 141: https://leetcode.com/problems/linked-list-cycle/
// Note: this question is weird in that it asks you to track the position of the node at the end of the loop
// but you don't return it  or anything.

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "utils\catch.hpp"
#include <unordered_map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };

// returns true if the linked list has a loop in it.
// Assumes that the values of linked list elements are unique
bool hasCycle(ListNode *head) {
    std::unordered_map<int, int> umap;
    int p = -1;
    int idx = 0;
    ListNode *curr = head;

    while(curr->next != nullptr){
        if(auto srch_itr = umap.find(curr->next->val); srch_itr != umap.end()){
            p = srch_itr->first;
            printf("%i\n", p);
            return true;
        }

        umap.insert({curr->val, idx});
        idx++;
        curr = curr->next;
    }

    printf("%i\n", p);
    return false;
}

// ---------- Tests -----------
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



