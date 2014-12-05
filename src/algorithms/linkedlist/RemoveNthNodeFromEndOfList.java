package algorithms.linkedlist; 

import java.util.*; 
import lib.ListNode; 

public class RemoveNthNodeFromEndOfList {
    /* Function: Remove the nth node from the end of the list in one pass, where n is non-zero based. 
     * Solution: Be careful if n is larger than the list size, or the head is deleted. 
     */ 
    
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head == null || n <= 0) {
            return head; 
        }
        
        ListNode dummy = new ListNode(0); 
        dummy.next = head; 
        
        ListNode fast = dummy, slow = dummy; 
        for (int i = 0; i < n; ++i) {
            fast = fast.next; 
            if (fast == null) {
                return head; // So head would never be null
            }
        }
        
        while (fast.next != null) {
            fast = fast.next; 
            slow = slow.next; 
        }
        
        slow.next = slow.next.next; 
        return dummy.next; 
    }
}