package algorithms.linkedlist; 

import java.util.*; 
import lib.RandomListNode; 

public class CopyListWithRandomPointer {
    /* Function: Deep copy a list that each node has two pointers. 
     * Solution: Can use hashmap to store node-node relation. But
     *     can also use O(1) space. First left copy points to origin's 
     *     next and origin points to copy. Then copy random pointers. 
     *     Notice cannot copy random pointer and reconnect to the right
     *     place, because random pointer can be removed while reconnect.
     */ 
    
    public RandomListNode copyRandomList(RandomListNode head) {
        if (head == null) {
            return null; 
        }
        
        RandomListNode cur = head; 
        while (cur != null) {
            RandomListNode cpy = new RandomListNode(cur.label); 
            cpy.next = cur.next; 
            cur.next = cpy; 
            cur = cpy.next; 
        }
        
        cur = head; 
        while (cur != null && cur.next != null) {
            RandomListNode cpy = cur.next;
            if (cur.random != null) {
                cpy.random = cur.random.next; 
            }
            cur = cpy.next; 
        }
        
        RandomListNode res = head.next; 
        cur = head; 
        while (cur != null && cur.next != null) {
            RandomListNode cpy = cur.next; 
            cur.next = cpy.next; 
            cpy.next = cur.next == null ? null : cur.next.next; 
            cur = cur.next; 
        }
        
        return res; 
    }
}
