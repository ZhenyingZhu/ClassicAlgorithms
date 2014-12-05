package algorithms.linkedlist; 

import java.util.*; 
import lib.ListNode; 

public class SwapNodesInPairs {
    /* Function: Swap each two nodes in a singly linked list. 
     * Solution: Two pointers is enough. 
     */ 
    
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head; 
        }
        
        ListNode dummy = new ListNode(0); 
        dummy.next = head; 
        
        ListNode pre = dummy, cur = head; 
        while (cur != null && cur.next != null) { // Here is and not or!
            pre.next = cur.next; 
            cur.next = cur.next.next; 
            pre.next.next = cur; 
            
            pre = cur; 
            cur = cur.next; 
        }
        
        return dummy.next; 
    }
}