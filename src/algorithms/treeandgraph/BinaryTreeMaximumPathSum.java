package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeNode; 

public class BinaryTreeMaximumPathSum {
    /* Function: Find the max-sum path in a binary tree. 
     * Solution: Three problems: if only has negative nodes; 
     *     if root is negative; if left or right path < 0; 
     *     So cannot compare max with left or right directly, 
     *     otherwise max must >= 0. If left path < 0, let it 
     *     return 0, so left + root + right must largest. 
     */ 
    
    int max = Integer.MIN_VALUE; 
    
    public int maxPathSum(TreeNode root) {
        if (root == null) {
            return 0; 
        }
        
        maxPathHelper(root); 
        return max; 
    }
    
    private int maxPathHelper(TreeNode root) {
        if (root == null) {
            return 0; 
        }
        
        int left = maxPathHelper(root.left); 
        int right = maxPathHelper(root.right); 
        
        max = Math.max(max, left + right + root.val); 
        
        int res = Math.max(left + root.val, right + root.val); 
        return res < 0 ? 0 : res; 
    }
}
