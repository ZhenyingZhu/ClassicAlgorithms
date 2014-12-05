package algorithms.linkedlist; 

import java.util.*; 

public class IntersectionOfTwoLinkedLists {
    /* Function: Two linked lists may inserted. Find the inserted point. 
     * Solution: Two pointers move one node each time and check if same. 
     *     When one reach the end, move one to another's head and continue, 
     *     so when the one that reach the end later and redirect to the other's
     *     head, they are on the same length to the end. 
     */ 
    
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) {
            return null; 
        }
        
        int len1 = length(headA), len2 = length(headB); 
        ListNode p1 = len1 > len2 ? headA : headB; 
        ListNode p2 = len1 > len2 ? headB : headA; 
        
        for (int i = 0; i < Math.abs(len1 - len2); ++i) {
            p1 = p1.next; 
        }
        
        while (p1 != null && p2 != null) {
            if (p1 == p2) {
                return p1; 
            }
            p1 = p1.next; 
            p2 = p2.next; 
        }
        
        return null; 
    }
    
    private int length(ListNode head) {
        int cnt = 0; 
        while (head != null) {
            head = head.next; 
            ++cnt; 
        }
        
        return cnt; 
    }
}