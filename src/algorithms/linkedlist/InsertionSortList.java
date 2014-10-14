package algorithms.linkedlist; 

import java.util.*; 
import lib.ListNode; 

public class InsertionSortList {
    /* Function: Use insertion sorting to sort a list. 
     * Solution: The previous part are sorted. Find the position of current
     *     element in the previous part. Be careful when current is larger 
     *     than all elements in the previous part. 
     */ 
    
    public ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null) {
            return head; 
        }
        
        ListNode dummy = new ListNode(0); 
        dummy.next = head; 
        
        ListNode done = head, cur = done.next; 
        while (cur != null) {
            ListNode run = dummy; 
            while (run.next != cur && run.next.val < cur.val) {
                run = run.next; 
            }
            
            if (run.next != cur) {
                done.next = cur.next; 
                cur.next = run.next; 
                run.next = cur; 
            } else {
                done = cur; 
            }
            cur = done.next; 
        }
        
        return dummy.next; 
    }
}
