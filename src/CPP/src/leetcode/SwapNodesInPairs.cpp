/*
 * [Source] https://leetcode.com/problems/swap-nodes-in-pairs/
 * [Difficulty]: Easy
 * [Tag]: Linked List
 */

#include <iostream>

using namespace std;

// [Solution]: pre->a->b, so next=b->next, b->next=a, a->next=next, pre->next=b, pre=next
// [Corner Case]: If there are odd number of nodes
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/linkedlist/SwapNodesInPairs.java
 */

/* Java solution
public class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head; 
        }
        ListNode slow = head; 
        ListNode fast = head.next; 
        ListNode cur = new ListNode(0); 
        head = head.next; 
        while (fast != null) {
            cur.next = fast; 
            slow.next = fast.next; 
            fast.next = slow; 
            cur = slow; 
            slow = slow.next; 
            fast = (slow == null) ? null : slow.next; 
        }
        return head; 
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
