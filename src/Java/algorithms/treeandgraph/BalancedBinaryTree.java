package algorithms.treeandgraph; 

import java.util.*; 

public class BalancedBinaryTree {
    /* Function: Check if a binary tree is balance, i.e. all the two 
     *     childen of a node don't have depth difference larger than 1. 
     * Solution: Recursive check height. 
     */ 
    
    public boolean isBalanced(TreeNode root) {
        return balanceHelper(root) != -1; 
    }
    
    private int balanceHelper(TreeNode root) {
        if (root == null) {
            return 0; 
        }
        
        int l = balanceHelper(root.left); 
        int r = balanceHelper(root.right); 
        if (l == -1 || r == -1 || Math.abs(l - r) > 1) {
            return -1; 
        }
        
        return 1 + Math.max(l, r); 
    }
} 