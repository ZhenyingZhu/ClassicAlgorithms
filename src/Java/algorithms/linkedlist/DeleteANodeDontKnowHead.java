package algorithms.linkedlist; 

import java.util.*; 
import lib.ListNode; 

public class DeleteANodeDontKnowHead {
    /* Function: Delete a node in the middle of the singly linked list. 
     * Solution: Copy the next node value and delete next. Notice it 
     *     cannot delete the last node. 
     */ 
    
    public boolean delete(ListNode node) {
        if (node == null || node.next == null) {
            return false; 
        }
        
        node.val = node.next.val; 
        node.next = node.next.next; 
        return true; 
    }
} 