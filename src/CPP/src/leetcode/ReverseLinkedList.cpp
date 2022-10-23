/*
 * [Source] https://leetcode.com/problems/reverse-linked-list/
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

// [Solution]: Keep a pointer to the previous node, and keep a pointer to next node. Link to previous node, and move to next node.
// [Corner Case]:
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return NULL;

        ListNode* pre = head;
        ListNode* cur = pre->next;
        pre->next = NULL;
        while (cur != NULL) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    ListNode n0(0), n1(1), n2(2);
    n0.next = &n1;
    n1.next = &n2;

    ListNode* t = sol.reverseList(&n0);
    while (t != NULL) {
        cout << t->val << "->";
        t = t->next;
    }
    cout << endl;

    return 0;
}
