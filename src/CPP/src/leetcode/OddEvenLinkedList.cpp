/*
 * [Source] https://leetcode.com/problems/odd-even-linked-list/
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

// [Solution]: How could this be medium?
// [Corner Case]:
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode oddDummy(0), evenDummy(0);
        ListNode *oddPtr = &oddDummy, *evenPtr = &evenDummy;

        bool odd = true;
        while (head != NULL) {
            if (odd) {
                oddPtr->next = head;
                oddPtr = oddPtr->next;
                odd = false;
            } else {
                evenPtr->next = head;
                evenPtr = evenPtr->next;
                odd = true;
            }
            head = head->next;
        }

        oddPtr->next = evenDummy.next;
        evenPtr->next = NULL;

        return oddDummy.next;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5;

    ListNode *head = sol.oddEvenList(&n1);
    while (head != NULL) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;

    return 0;
}
