package algorithms.linkedlist; 

import java.util.*; 
import lib.ListNode; 

public class SortList {
    /* Function: Sort linked list in O(nlogn). 
     * Solution: Merge sort. 
     */ 
    
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head; 
        }
        
        return sortHelper(head); 
    }
    
    private ListNode sortHelper(ListNode head) {
        if (head == null || head.next == null) {
            return head; 
        }
        
        ListNode fast = head.next, slow = head; 
        while (fast != null && fast.next != null) {
            fast = fast.next.next; 
            slow = slow.next; 
        }
        
        ListNode right = sortHelper(slow.next); 
        slow.next = null; 
        ListNode left = sortHelper(head); 
        return merge(left, right); 
    }
    
    private ListNode merge(ListNode left, ListNode right) {
        ListNode dummy = new ListNode(0), cur = dummy; 
        while (left != null || right != null) {
            if (right == null || (left != null && left.val < right.val)) {
                cur.next = left; 
                left = left.next; 
            } else {
                cur.next = right; 
                right = right.next; 
            }
            
            cur = cur.next; 
        }
        
        return dummy.next; 
    }
} 