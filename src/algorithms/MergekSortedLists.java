package algorithms;

import java.util.*; 
import lib.ListNode; 

public class MergekSortedLists {
    /* Function: Merge k sorted lists of ListNodes. 
     * Solution: Use heap to track the smallest node. 
    */
    public ListNode mergeKLists(List<ListNode> lists) {
        if (lists == null || lists.size() == 0) {
            return null; 
        }
        
        Queue<ListNode> heap = new PriorityQueue<ListNode>(lists.size(), ListNodeComparator); 
        for (ListNode node : lists) {
            if (node != null) { // Be careful! 
                heap.offer(node); 
            }
        }
        
        ListNode dummy = new ListNode(0), cur = dummy; 
        while (!heap.isEmpty()) {
            cur.next = heap.poll(); 
            cur = cur.next; 
            if (cur.next != null) {
                heap.offer(cur.next); 
            }
        }
        
        return dummy.next; 
    }
    
    private Comparator<ListNode> ListNodeComparator = new Comparator<ListNode>() {
        public int compare(ListNode n0, ListNode n1) {
            if (n0 == null) {
                return -1; 
            }
            if (n1 == null) {
                return 1; 
            }
            return n0.val - n1.val; 
        }
    }; 
}
