package algorithms.linkedlist; 

import java.util.*; 
import lib.ListNode; 

public class PartitionSinglyLinkedList {
    /* Function: Partition a singly linked list such that nodes bigger or 
     *     equal to a target appear after the others. 
     * Solution: Use two lists and linked them together. 
     */ 
    
    public ListNode partation(ListNode head, int target) {
        if (head == null || head.next == null) {
            return head; 
        }
        
        ListNode left = new ListNode(0), right = new ListNode(0); 
        ListNode p1 = left, p2 = right; 
        
        while(head != null) {
            if (head.val < target) {
                p1.next = head; 
                p1 = p1.next; 
            } else {
                p2.next = head; 
                p2 = p2.next; 
            }
            
            head = head.next; 
        }
        
        p2.next = null; // it might be point to a node in left. 
        p1.next = right.next; 
        return left.next; 
    }
} 