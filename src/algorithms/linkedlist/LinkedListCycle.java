package algorithms.linkedlist; 

import java.util.*; 
import lib.ListNode; 

public class LinkedListCycle {
    /* Function: Check if a linked list has a cycle. 
     * Solution: Use two pointers. 
     */ 
    
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) {
            return false; 
        }
        
        ListNode slow = head, fast = head; 
        do {
            fast = fast.next.next; 
            slow = slow.next; 
        } while (fast != null && fast.next != null && fast != slow); 
        
        if (fast == slow) {
            return true; 
        }
        return false; 
    }
} 