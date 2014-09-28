package algorithms; 

import java.util.*; 
import lib.ListNode; 

public class ReorderListIterative {
    /* Function: Reorder list such that 1-2-3-4-5 become 1-5-2-4-3. 
     * Solution: Speperate into two parts. 
    */
    public void reorderList(ListNode head) {
        if (head == null || head.next == null) {
            return; 
        }
        
        ListNode slow = head, fast = head.next; 
        while (fast != null && fast.next != null) {
            slow = slow.next; 
            fast = fast.next.next; 
        }
        
        ListNode head2 = reverse(slow.next); 
        slow.next = null; 
        
        merge(head, head2); 
    }
    
    private ListNode reverse(ListNode head) {
        ListNode newHead = null; 
        while (head != null) {
            ListNode tmp = head.next; 
            head.next = newHead; 
            newHead = head; 
            head = tmp; 
        }
        
        return newHead; 
    }
    
    private void merge(ListNode head1, ListNode head2) {
        ListNode dummy = new ListNode(0), cur = dummy; 
        int cnt = 0; 
        while (head1 != null && head2 != null) {
            if (cnt++ % 2 == 0) {
                cur.next = head1; 
                head1 = head1.next; 
            } else {
                cur.next = head2; 
                head2 = head2.next; 
            }
            cur = cur.next; 
        }
        
        if (head1 != null) {
            cur.next = head1; 
        } else {
            cur.next = head2; 
        }
    }
}
