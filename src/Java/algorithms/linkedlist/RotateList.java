package algorithms.linkedlist; 

import java.util.*; 

public class RotateList {
    /* Function: Retated the list by n to the right. n is non-negative. 
     * Solution: When n is larger than the length of the list, it will rotated again. 
     */ 
    
    public ListNode rotateRight(ListNode head, int n) {
        if (head == null || head.next == null || n <= 0) {
            return head; 
        }
        
        ListNode dummy = new ListNode(0), fast = dummy, slow = dummy; 
        dummy.next = head; 
        
        for (int i = 0; i < n; ++i) {
            fast = fast.next; 
            if (fast.next == null) {
                fast = dummy; 
            }
        }
        
        while (fast.next != null) {
            slow = slow.next; 
            fast = fast.next; 
        }
        
        fast.next = dummy.next; 
        head = slow.next; 
        slow.next = null; 
        return head; 
    }
}