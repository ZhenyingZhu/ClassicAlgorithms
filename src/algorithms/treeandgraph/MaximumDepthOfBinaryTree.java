package algorithms.treeandgraph; 

import java.util.*; 

public class MaximumDepthOfBinaryTree {
    /* Function: Find the depth of the binary tree. 
     * Solution: Recursive. 
     */ 
    
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0; 
        }
        
        return 1 + Math.max(maxDepth(root.left), maxDepth(root.right)); 
    }
} 