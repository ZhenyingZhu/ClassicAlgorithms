package algorithms.sortandsearch; 

import java.util.*; 
import lib.ListNode; 

public class LinkedListMergeSort {
    /* Function: Merge sort the linkedlist. 
     * Solution: Use two pointers to find the middle. 
    */
    public ListNode mergeSort(ListNode head) {
        if (head == null || head.next == null) {
            return head; 
        }
        
        ListNode slow = head, fast = head.next; 
        while (fast != null && fast.next != null) {
            slow = slow.next; 
            fast = fast.next.next; 
        }
        
        ListNode right = mergeSort(slow.next); 
        slow.next = null; 
        ListNode left = mergeSort(head); 
        
        return merge(left, right); 
    }    
    
    private ListNode merge(ListNode head1, ListNode head2) {
        ListNode dummy = new ListNode(0), cur = dummy; 
        while (head1 != null && head2 != null) {
            if (head1.val < head2.val) {
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
        
        return dummy.next; 
    }
}
