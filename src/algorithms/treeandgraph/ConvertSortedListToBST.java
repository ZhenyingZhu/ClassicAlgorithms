package algorithms.treeandgraph;

import java.util.*; 
import lib.ListNode; 
import lib.TreeNode; 

public class ConvertSortedListToBST {
    /* Function: Give a listed list, convert it into a balanced BST.  
     * Solution: Since the list is sorted, the order is the order of BST. 
    */
    private ListNode cur; 
    public TreeNode sortedListToBST(ListNode head) {
        if (head == null) {
            return null; 
        }
        
        int len = count(head); 
        cur = head; 
        return createBSTHelper(len); 
    }
    
    private TreeNode createBSTHelper(int len) {
        if (len <= 0 || cur == null) {
            return null; 
        }
        
        TreeNode left = createBSTHelper(len / 2); 
        TreeNode root = new TreeNode(cur.val); 
        cur = cur.next; 
        TreeNode right = createBSTHelper(len - 1 - len / 2); 
        
        root.left = left; 
        root.right = right; 
        return root; 
    }
    
    private int count(ListNode head) {
        int len = 0; 
        while (head != null) {
            ++len; 
            head = head.next; 
        }
        return len; 
    }
}
