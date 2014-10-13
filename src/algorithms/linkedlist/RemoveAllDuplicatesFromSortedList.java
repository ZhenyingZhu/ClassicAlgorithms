package algorithms.linkedlist; 

import java.util.*; 
import lib.ListNode; 

public class RemoveAllDuplicatesFromSortedList {
    /* Function: Only leave disctinct numbers. 
     * Solution: Check if the next and the next of the next is dup. 
    */
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) {
            return head; 
        }
        
        ListNode dummy = new ListNode(0); 
        dummy.next = head; 
        head = dummy; 
        while (head.next != null && head.next.next != null) {
            if (head.next.val == head.next.next.val) {
                ListNode tmp = head.next.next; 
                while (tmp != null && tmp.val == head.next.val) {
                    tmp = tmp.next; 
                }
                head.next = tmp; 
            } else {
                head = head.next; 
            }
        }
        
        return dummy.next; 
    }
}
