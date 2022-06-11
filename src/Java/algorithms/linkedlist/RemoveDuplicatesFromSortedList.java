package algorithms.linkedlist; 

import java.util.*; 

public class RemoveDuplicatesFromSortedList {
    /* Function: Remove all the duplicates elements such that each number only appears once. 
     * Solution: A pointer. 
     */ 
    
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) {
            return head; 
        }
        
        ListNode dummy = new ListNode(0), cur = head; 
        dummy.next = head; 
        
        while (cur.next != null) {
            if (cur.next.val == cur.val) {
                cur.next = cur.next.next; 
            } else {
                cur = cur.next; 
            }
        }
        
        return dummy.next; 
    }
} 