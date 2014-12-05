package algorithms.linkedlist; 

import java.util.*; 
import java.ListNode; 

public class LinkedListCycleStart {
    /* Function: Find the start node of the cycle in a linked list in one pass. 
     * Solution: Two pointers running. When touch, move one back. 
     */ 
    
    public ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null) {
            return null; 
        }
        
        ListNode fast = head, slow = head; 
        do {
            fast = fast.next.next; 
            slow = slow.next; 
        } while (fast != null && fast.next != null && fast != slow); 
        
        if (fast != slow) {
            return null; // No cycle. 
        }
        
        fast = head; 
        while (fast != slow) {
            fast = fast.next; 
            slow = slow.next; 
        }
        
        return slow; 
    }
} 