package algorithms.linkedlist; 

import java.util.*; 
import lib.ListNode; 

public class IsPalindromeSinglyLinkedList {
    /* Function: Check if a singly linked list is palindrome. 
     * Solution: Use a global and recursive to solve the problem. 
     */ 
    
    ListNode head; 
    public boolean isPalindrome(ListNode node) {
        if (node == null || node.next == null) {
            return true; 
        }
        
        head = node; 
        return palinHelper(node); 
    }
    
    private boolean palinHelper(ListNode tail) {
        boolean res = true; 
        if (tail.next != null) {
            res = palinHelper(tail.next); 
        }
        
        res &= head.val == tail.val; 
        head = head.next; 
        return res; 
    }
} 