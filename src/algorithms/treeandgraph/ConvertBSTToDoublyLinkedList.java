package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeNode; 

public class ConvertBSTToDoublyLinkedList {
    /* Function: Convert the BST to a doubly linked list that left is prev and right is next.  
     * Solution: Recursive version of inorder traversal and make sure to disconnect the head and tail. 
     */ 
    
    public TreeNode convert(TreeNode root) {
        if (root == null) {
            return null; 
        }
        
        TreeNode dummy = new TreeNode(0); 
        TreeNode pre = dummy, pnt = null, cur = root; 
        
        Stack<TreeNode> stack = new Stack<TreeNode>(); 
        while (cur != null || !stack.empty()) {
            while (cur != null) {
                stack.push(cur); 
                cur = cur.left; 
            }
            
            if (!stack.empty()) {
                pnt = cur = stack.pop(); 
                cur = cur.right; 
                
                pre.right = pnt; 
                pnt.left = pre; 
                pre = pnt; 
            }
        }
        
        pnt.right = null; 
        pnt = dummy.right; 
        pnt.left = null; 
        return pnt; 
    }
}
