package algorithms.mathandprob; 

import java.util.*; 
import lib.ListNode; 

public class AddTwoNumberLists {
    /* Function: Add two numbers that present in forward lists.
     * Solution: Another solution is to reverse the lists first. 
     */ 
    
    public ListNode addLists(ListNode l1, ListNode l2) {
        if (l1 == null || l2 == null) {
            return l1 == null ? l2 : l1; 
        }
        
        ListNode dummy = new ListNode(1); 
        int len1 = length(l1), len2 = length(l2); 
        if (len1 < len2) {
            l1 = padding(l1, len2 - len1); 
        } else {
            l2 = padding(l2, len1 - len2); 
        }
        
        if (addHelper(l1, l2, dummy) == 0) {
            return dummy.next; 
        } else {
            return dummy; 
        }
    }
    
    private int addHelper(ListNode l1, ListNode l2, ListNode head) {
        if (l1 == null && l2 == null) {
            return 0; 
        }
        
        int carry = addHelper(l1.next, l2.next, head); 
        int sum = l1.val + l2.val + carry; 
        
        ListNode cur = new ListNode(sum % 10); 
        cur.next = head.next; 
        head.next = cur; 
        
        return sum / 10; 
    }
    
    private ListNode padding(ListNode head, int num) {
        ListNode cur = head; 
        for (int i = 0; i < num; ++i) {
            ListNode pre = new ListNode(0); 
            pre.next = cur; 
            cur = pre; 
        }
        
        return cur; 
    }
    
    private int length(ListNode head) {
        int res = 0; 
        while (head != null) {
            ++res; 
            head = head.next; 
        }
        
        return res; 
    }
} 