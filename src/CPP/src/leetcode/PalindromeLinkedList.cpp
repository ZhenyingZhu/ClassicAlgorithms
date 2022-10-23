/*
 * [Source] https://leetcode.com/problems/palindrome-linked-list/
 * [Difficulty]: Easy
 * [Tag]: Linked List
 * [Tag]: Two Pointers
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
    bool isPalindrome(ListNode* head) {
        if (head == NULL)
            return true;

        ListNode* fast = head, * slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* tmp = slow->next;
        slow->next = NULL;
        ListNode* newStart = reverseList(tmp);

        while (newStart != NULL) {
            if (head->val != newStart->val)
                return false;
            newStart = newStart->next;
            head = head->next;
        }
        return true;
    }

    ListNode* reverseList(ListNode* node) {
        ListNode* pre = NULL, * cur = node;
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

    ListNode l1(1), l2(2), l3(3), l4(1);
    l1.next = &l2; l2.next = &l3; l3.next = &l4;
    cout << (sol.isPalindrome(&l1) ? "True":"False") << endl;

    return 0;
}
