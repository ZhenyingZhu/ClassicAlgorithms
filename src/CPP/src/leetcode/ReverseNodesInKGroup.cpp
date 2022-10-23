/*
 * [Source] https://leetcode.com/problems/reverse-nodes-in-k-group/
 * [Difficulty]: Hard
 * [Tag]: Linked List
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// [Solution]: Reverse a piece of list by keep moving the nodes to the head
// [Corner Case]: If k = list length, k = list length + 1, k = 0
class Solution {
private:
    ListNode* reversePiece(ListNode* slow, ListNode* fast) {
        // reverse nodes from slow+1 to fast, and return the last node
        const ListNode* next = fast->next;
        ListNode* tail = slow->next;
        while (tail->next != next) {
            ListNode* tmp = tail->next;
            tail->next = tmp->next;
            tmp->next = slow->next;
            slow->next = tmp;
        }
        return tail;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* slow = &dummy, * fast = slow;
        while (fast != NULL) {
            // first move fast
            for (int i = 0; i < k; ++i) {
                if (fast == NULL)
                    break;
                fast = fast->next;
            }

            if (fast == NULL)
                return dummy.next;

            slow = reversePiece(slow, fast);
            fast = slow;
        }
        return dummy.next;
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/linkedlist/ReverseNodesInk-Group.java
 */

/* Java solution
public class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || k <= 1) {
            return head; 
        }
        ListNode fast = head; 
        ListNode slow = head; 
        int i; 
        for (i = k; i > 1; --i) {
            fast = fast.next; 
            if (fast == null) {
                return head; // The list is shorter than k. 
            }
        }
        head = fast; // Head set only once
        
        ListNode linkHead; 
        ListNode linkTail = new ListNode(0); 
        ListNode current; 
        ListNode temp; 
        while (fast != null) {
            linkHead = fast; 
            linkTail.next = fast; // Link previous list
            linkTail = slow; 
            fast = fast.next; 
            current = fast; 
            while (slow != linkHead) { // Reverse
                temp = slow.next; 
                linkHead.next = slow; 
                slow.next = current; 
                current = slow; 
                slow = temp; 
            }
            
            slow = fast; // Find next k list
            for (i = k; i > 1; --i) {
                if (fast == null) { // fast may alreay null
                    return head; 
                }
                fast = fast.next; // if fast is null, while exit
            }
        }
        return head; 
    }
}
 */

int main() {
    Solution sol;

    ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.next = &n2; n2.next = &n3; n3.next = &n4; n4.next = &n5;

    //ListNode* head = sol.reverseKGroup(&n1, 6);
    //ListNode* head = sol.reverseKGroup(&n1, 5);
    //ListNode* head = sol.reverseKGroup(&n1, 3);
    ListNode* head = sol.reverseKGroup(&n1, 2);
    while (head != NULL) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;

    return 0;
}
