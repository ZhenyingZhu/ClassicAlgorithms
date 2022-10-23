#include <iostream>

using namespace std;

struct ListNode {
    ListNode(int x): val(x), next(NULL) { }
    int val;
    ListNode *next;
};

// [Source]: https://leetcode.com/problems/linked-list-cycle-ii/
// http://www.1point3acres.com/bbs/thread-223433-1-1.html

class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        if (head == NULL)
            return NULL;

        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }

        if (fast == NULL || fast->next == NULL)
            return NULL;

        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main() {
    Solution sol;

    return 0;
}
