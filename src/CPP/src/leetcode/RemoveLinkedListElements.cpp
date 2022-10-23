/*
 * [Source] https://leetcode.com/problems/remove-linked-list-elements/
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

// [Solution]: Check next node. Notice shouldn't move forward if next node is deleted
// [Corner Case]:
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy = ListNode(0);
        dummy.next = head;
        ListNode* running = &dummy;
        while (running->next != NULL) {
            if (running->next->val == val) {
                running->next = running->next->next;
            } else {
                running = running->next;
            }
        }
        return dummy.next;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    ListNode n0(0), n1(1), n2(2), n3(2), n4(3), n5(2);
    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    sol.removeElements(&n0, 2);
    ListNode* cur = &n0;
    while (cur != NULL) {
        cout << cur->val << "->";
        cur = cur->next;
    }
    cout << endl;

    return 0;
}
