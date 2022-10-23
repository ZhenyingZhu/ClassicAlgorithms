/*
 * [Source] https://leetcode.com/problems/linked-list-random-node/
 * [Difficulty]: Medium
 * [Tag]: Reservoir Sampling
 */

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// [Solution]:
// [Corner Case]:
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        head_ = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        int res = head_->val;

        ListNode *cur = head_;
        int idx = 1;
        while (cur != NULL) {
            int random = rand() % idx;
            if (random == 0)
                res = cur->val;

            ++idx;
            cur = cur->next;
        }

        return res;
    }

private:
    ListNode *head_;
};

// [Solution]:
/* Java solution

 */

int main() {
    ListNode l1(1), l2(2), l3(3);
    l1.next = &l2; l2.next = &l3;
    Solution sol(&l1);

    cout << sol.getRandom() << endl;
    cout << sol.getRandom() << endl;
    cout << sol.getRandom() << endl;
    cout << sol.getRandom() << endl;
    cout << sol.getRandom() << endl;
    cout << sol.getRandom() << endl;
    cout << sol.getRandom() << endl;
    cout << sol.getRandom() << endl;
    cout << sol.getRandom() << endl;
    cout << sol.getRandom() << endl;

    return 0;
}
