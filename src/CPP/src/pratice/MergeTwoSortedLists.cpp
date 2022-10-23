#include <iostream>

using namespace std;

struct ListNode {
    ListNode(int x): val(x), next(NULL) { }
    int val;
    ListNode *next;
};

// [Source]: https://leetcode.com/problems/merge-two-sorted-lists/
// http://www.1point3acres.com/bbs/thread-227329-1-1.html

// Recursive
class Solution {
public:
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

int main() {
    Solution sol;
    ListNode l1(1),l2(2),l3(3),l4(4),l5(5),l6(6);
    l1.next = &l3; l3.next = &l4;
    l2.next = &l5; l5.next = &l6;

    ListNode *head = sol.mergeTwoLists(&l1, &l2);
    while (head != NULL) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;

    return 0;
}
