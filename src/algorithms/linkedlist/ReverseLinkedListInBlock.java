package algorithms.linkedlist; 

import java.util.*; 
import lib.ListNode; 

public class ReverseLinkedListInBlock {
    /* Function: Reverse a linked list in block with k width. The length of the 
     * last block can be smaller than k. 
     * Example: Input: (1-2-3-4-5, 2); Output: (4-5-2-3-1). 
     * Solution: First go ahead with k or len % k. Then reverse. 
    */    
    public ListNode reverseInBlock(ListNode head, int k) {
        if (head == null) {
            return head; 
        }
        
        int len = countLen(head); 
        ListNode dummy = new ListNode(0), cur = dummy; 
        dummy.next = head; 
        int step = len % k == 0 ? k : len % k; 
        for (int i = 0; i < step; ++i) {
            cur = cur.next; 
        }
        
        while (cur.next != null) {
            ListNode ahead = cur; 
            for (int i = 0; i < k; ++i) {
                ahead = ahead.next; 
            }
            ListNode tmp = ahead.next; 
            ahead.next = dummy.next; 
            dummy.next = cur.next; 
            cur.next = tmp; 
        }
        
        return dummy.next; 
    }
    
    private int countLen(ListNode head) {
        int len = 0; 
        while (head != null) {
            ++len; 
            head = head.next; 
        }
        
        return len; 
    }
}
