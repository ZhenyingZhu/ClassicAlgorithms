package algorithms.mathandprob;

import java.util.*; 
import lib.ListNode; 

public class AddTwoNumbersFromReversedList {
    /* Function: Two numbers are stored as reversed order in two lists, add them up. 
     * Solution: Bit by bit add and record carry. 
    */
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null || l2 == null) {
            return l1 != null ? l1 : l2; 
        }
        
        ListNode dummy = new ListNode(0), cur = dummy; 
        int carry = 0; 
        while (l1 != null && l2 != null) {
            int sum = carry + l1.val + l2.val; 
            l1 = l1.next; 
            l2 = l2.next; 
            cur.next = new ListNode(sum % 10);  
            cur = cur.next; 
            carry = sum / 10; 
        }
        
        if (l1 == null) {
            l1 = l2; 
        }
        
        while (l1 != null) {
            int sum = carry + l1.val; 
            l1 = l1.next; 
            cur.next = new ListNode(sum % 10); 
            cur = cur.next; 
            carry = sum / 10; 
        }
        
        if (carry != 0) {
            cur.next = new ListNode(carry); 
        }
        
        return dummy.next; 
    }
}

