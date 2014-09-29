package algorithms;

import java.util.*; 
import lib.ListNode; 

public class ReverseLinkedListBetweenRange {
    /* Function: Reverse the order of nodes indexed m to n. 
     * Solution: Insert next node to the next of start node. 
    */
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (head == null || n < m) {
            return null; 
        }
        
        ListNode dummy = new ListNode(0), cur = dummy; 
        dummy.next = head; 
        int i, j; 
        if (m > 0) {
            for (i = 1; i < m; ++i) {
                cur = cur.next; 
                if (cur == null) {
                    return dummy.next; 
                }
            }
        }
        if (cur.next == null) {
            return dummy.next; 
        }
        
        
        ListNode pre = cur; 
        cur = cur.next; 
        for (i = m; i < n; ++i) {
            if (cur.next == null) {
                return dummy.next; 
            }
            ListNode rev = cur.next; 

            cur.next = rev.next; 
            rev.next = pre.next; 
            pre.next = rev; 
        }
        
        return dummy.next; 
    }
}
