package algorithms.linkedlist; 

import java.util.*; 

public class PartitionList {
    /* Function: Partition the list so that the values smaller than x goes to left, and others goes to right in the relative order. 
     * Solution: Two lists. 
     */ 
    
    public ListNode partition(ListNode head, int x) {
        if (head == null || head.next == null) {
            return head; 
        }
        
        ListNode Ldummy = new ListNode(0), left = Ldummy, Rdummy = new ListNode(0), right = Rdummy; 

        while (head != null) {
            if (head.val < x) {
                left.next = head; 
                left = left.next; 
            } else {
                right.next = head; 
                right = right.next; 
            }
            head = head.next; 
        }
        
        left.next = Rdummy.next; 
        right.next = null; 
        return Ldummy.next; 
    }
}