package algorithms; 

import java.util.*; 
import lib.TreeNode; 

public class DeleteNodeInBST {
    /* Function: Delete a node in BST. 
     * Solution: Find the node and use the biggest node that smaller 
     *     than it to alternate it
     * Three situations: the delete node don't have left child; 
     *     the left child of the delete node has no right child; 
     *     the biggest node is the right most node. 
    */
    public TreeNode delete(TreeNode root, int del) {
        TreeNode dummy = new TreeNode(0); 
        dummy.left = root; 
        
        TreeNode parent = dummy, node = root; 
        while (node != null) {
            if (node.val == del) {
                break; 
            }
            
            parent = node; 
            if (del < node.val) {
                node = node.left; 
            } else {
                node = node.right; 
            }
        }
        if (node == null) {
            return root; // Don't find the value. 
        }
        
        if (node.left == null) {
            if (node == parent.left) {
                parent.left = node.right; 
            } else {
                parent.right = node.right; 
            }
            
        } else {
            TreeNode alter = node.left, ahead = node; 
            while (alter.right != null) {
                ahead = alter; 
                alter = alter.right; 
            }
            
            if (alter == ahead.right) {
                ahead.right = alter.left; 
                alter.left = node.left; 
            }
            alter.right = node.right; 
            
            if (node == parent.left) {
                parent.left = alter; 
            } else {
                parent.right = alter; 
            }
        }
        
        return dummy.left; 
    }
}
