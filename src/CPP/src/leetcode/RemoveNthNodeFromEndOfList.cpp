/*
 * [Source] https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * [Difficulty]: Easy
 * [Tag]: Linked List
 * [Tag]: Two Pointers
 */

#include <iostream>

using namespace std;

// [Solution]: Use fast-slow pointers to find the previous node of the node that needs to be removed.
// [Corner Case]: If the node is the first node. So use dummy header.
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/linkedlist/RemoveNthNodeFromEndOfList.java
 */

/* Java solution
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null || n <= 0) {
            return head; 
        }
        ListNode fast = head; 
        while (n >= 0) {
            if (fast == null) {
                if (n == 0) {
                    return head.next; 
                } else {
                    return head; 
                }
            }
            fast = fast.next; 
            --n; 
        }
        ListNode cur = head; 
        while (fast != null) {
            cur = cur.next; 
            fast = fast.next; 
        }
        cur.next = cur.next.next; 
        return head; 
    }
}
 */


int main() {
    Solution sol;

    return 0;
}
