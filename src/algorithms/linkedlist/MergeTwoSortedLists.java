package algorithms.linkedlist; 

import java.util.*; 
import lib.ListNode; 

public class MergeTwoSortedLists {
    /* Function: Merge two sorted lists in a new sorted list. 
     * Solution: A pointer. 
     */ 
    
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0), cur = dummy; 
        while (l1 != null || l2 != null) {
            if (l1 == null || (l2 != null && l2.val < l1.val)) {
                cur.next = l2; 
                l2 = l2.next; 
            } else {
                cur.next = l1; 
                l1 = l1.next; 
            }
            
            cur = cur.next; 
        }
        
        return dummy.next; 
    }
} 