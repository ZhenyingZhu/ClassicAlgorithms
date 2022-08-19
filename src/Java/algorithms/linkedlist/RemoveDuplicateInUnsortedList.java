package algorithms.linkedlist; 

import java.util.*; 
import lib.ListNode; 

public class RemoveDuplicateInUnsortedList {
    /* Function: Remove duplicated in an unsorted singly linked list. 
     * Solution: Use a Hash set to record the shown node. 
     */ 
    
    public void deleteDups(ListNode head) {
        if (head == null || head.next == null) {
            return; 
        }
        
        Set<Integer> set = new HashSet<Integer>(); 
        set.add(head.val); 
        while (head.next != null) {
            if (set.contains(head.next.val)) {
                head.next = head.next.next; 
            } else {
                set.add(head.next.val); 
                head = head.next; 
            }
        }
    }
} 