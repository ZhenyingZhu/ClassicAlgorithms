package algorithms.linkedlist; 

import java.util.*; 
import lib.ListNode; 

public class FindTheKthToLast {
    /* Function: Return the kth last node of an linked list. 1 is the last one. 
     * Solution: Use two pointers. 
     */ 
    
    public ListNode nthToLast(ListNode head, int n) {
        if (head == null || head.next == null || n <= 0) {
            return head; 
        }
        
        ListNode slow = head, fast = head; 
        for (int i = 0; i < n; ++i) {
            fast = fast.next; 
            if (fast == null) {
                return head; // n is too long. 
            }
        }
        
        while (fast != null) {
            fast = fast.next; 
            slow = slow.next; 
        }
        
        return slow; 
    }
} 