/*
 * [Source] https://leetcode.com/problems/delete-node-in-a-linked-list/
 * [Difficulty]: Easy
 * [Tag]: Linked List
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// [Solution]: Move val of the next node to this node, and delete next node.
// [Corner Case]:
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == NULL || node->next == NULL)
            return; // exception case

        node->val = node->next->val;
        node->next = node->next->next;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    return 0;
}
