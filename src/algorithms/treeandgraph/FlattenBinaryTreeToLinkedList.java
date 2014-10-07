package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeNode; 

public class FlattenBinaryTreeToLinkedList {
    /* Function: Let the tree nodes' right child point to its pre-order successor. 
     * Solution: Iterative pre-order. Keep a pointer on parent. 
     */ 
    
    public void flatten(TreeNode root) {
        if (root == null) {
            return; 
        }
        
        Stack<TreeNode> stack = new Stack<TreeNode>(); 
        stack.push(root); 
        TreeNode par = new TreeNode(0); 
        while (!stack.empty()) {
            TreeNode cur = stack.pop(); 
            par.right = cur; 
            
            if (cur.right != null) {
                stack.push(cur.right); 
            }
            if (cur.left != null) {
                stack.push(cur.left); 
            }
            
            par = cur; 
            cur.left = null; 
        }
    }
}
