/*
 * [Source] https://leetcode.com/problems/plus-one-linked-list/
 * [Difficulty]: Medium
 * [Tag]: Linked List
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// [Solution]:
// [Corner Case]:
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if (head == NULL)
            return NULL;

        ListNode *tail = reverse(head);

        int carry = 1;
        ListNode *cur = tail, *pre = tail;
        while (cur != NULL && carry != 0) {
            cur->val += carry;
            if (cur->val > 9) {
                cur->val = cur->val % 10;
                carry = 1;
            } else {
                carry = 0;
            }
            pre = cur;
            cur = cur->next;
        }
        if (carry != 0) {
            pre->next = new ListNode(1);
            pre = pre->next;
        }

        return reverse(tail);
    }

    ListNode* reverse(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = head;
        while (cur->next != NULL) {
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            tmp->next = dummy->next;
            dummy->next = tmp;
        }
        ListNode *newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    ListNode n1(9), n2(9), n3(9), n4(9);
    n1.next = &n2; n2.next = &n3; n3.next = &n4;
    ListNode *head = sol.plusOne(&n1);

    while (head != NULL) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;

    return 0;
}
