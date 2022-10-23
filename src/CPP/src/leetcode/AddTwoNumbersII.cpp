/*
 * [Source] https://leetcode.com/problems/add-two-numbers-ii/
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

// [Solution]: Use a reverse order list to store result first
// [Corner Case]:
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *r1 = l1, *r2 = l2;
        while (r1 != NULL && r2 != NULL) {
            r1 = r1->next;
            r2 = r2->next;
        }

        ListNode *h1 = l1, *h2 = l2;
        while (r1 != NULL) {
            h1 = h1->next;
            r1 = r1->next;
        }
        while (r2 != NULL) {
            h2 = h2->next;
            r2 = r2->next;
        }

        ListNode *cur = NULL;
        while (l1 != h1) {
            ListNode *tmp = new ListNode(l1->val);
            tmp->next = cur;
            cur = tmp;
            l1 = l1->next;
        }
        while (l2 != h2) {
            ListNode *tmp = new ListNode(l2->val);
            tmp->next = cur;
            cur = tmp;
            l2 = l2->next;
        }

        while (h1 != NULL) {
            ListNode *tmp = new ListNode(h1->val + h2->val);
            tmp->next = cur;
            cur = tmp;
            h1 = h1->next;
            h2 = h2->next;
        }

        ListNode *head = cur, *pre = cur;
        int carry = 0;
        while (cur != NULL) {
            cur->val += carry;
            if (cur->val > 9) {
                carry = cur->val / 10;
                cur->val = cur->val % 10;
            } else {
                carry = 0;
            }
            pre = cur;
            cur = cur->next;
        }
        if (carry > 0)
            pre->next = new ListNode(carry);

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        while (head->next != NULL) {
            ListNode *curr = head->next;
            ListNode *tmp = curr->next;
            curr->next = dummy->next;
            dummy->next = curr;
            head->next = tmp;
        }

        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};

// [Solution]: Use stack to push the list elements
/* Java solution

 */

int main() {
    Solution sol;
    ListNode l1(9), l2(4), l3(4), l4(3), l5(5), l6(6), l7(4);
    l1.next = &l2; l2.next = &l3; l3.next = &l4;
    l5.next = &l6; l6.next = &l7;

    ListNode *head = sol.addTwoNumbers(&l1, &l5);
    while (head != NULL) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;

    return 0;
}
