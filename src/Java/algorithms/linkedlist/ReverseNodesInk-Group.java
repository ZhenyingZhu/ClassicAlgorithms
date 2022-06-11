package algorithms.linkedlist; 

import java.util.*; 
import lib.ListNode; 

public class ReverseNodesInk-Group {
    /* Function: Reverse each k nodes in a linked list. If the last group doesn't 
     *     has k nodes, leave it. 
     * Solution: First use a pointer to check if there are k nodes ahead. Then keep
     *     a pointer to the head, move its next to the very beginning of the group. 
     */ 
    
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || k <= 1) {
            return head; 
        }
        
        ListNode dummy = new ListNode(0), slow = dummy, fast; 
        dummy.next = head; 
        
        while (head != null) {
            fast = slow; 
            int cnt = 0; 
            while (fast != null && k > cnt++) {
                fast = fast.next; 
            }
            if (fast == null) { // The last
                return dummy.next; 
            }
            
            head = slow.next; 
            for (int i = 0; i < k - 1; ++i) {
                ListNode tmp = slow.next; 
                slow.next = head.next; 
                head.next = head.next.next; 
                slow.next.next = tmp; 
            }
            slow = head; 
        }
        
        return dummy.next; 
    }
}
