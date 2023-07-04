// Leetcode 141: https://leetcode.com/problems/linked-list-cycle/

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "utils\catch.hpp"
#include <unordered_map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };

bool hasCycle(ListNode *head) {
    std::unordered_map<int, int> umap;
    bool loop_exists = false;
    int idx = 0;
    ListNode *curr = head;

    while(curr->next != nullptr){
        if(!umap.contains(curr->val)){
            return true;
        }
        idx++;
        curr = curr->next;
    }

    return loop_exists;
}



TEST_CASE( "Simple, no loop", "[hasCycle]" ) {
    ListNode head = ListNode(1);
    ListNode n0 = ListNode(2);
    head.next = &n0;

    REQUIRE( hasCycle(&head) == 0 );
}


