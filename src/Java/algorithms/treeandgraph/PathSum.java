package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeNode; 

public class PathSum {
    /* Function: Find if there exist a path from root to a leaf that sum up to a target. 
     * Solution: Notice root cannot count as leaf. 
     */ 
    
    public boolean hasPathSum(TreeNode root, int sum) {
        if (root == null) {
            return false; 
        }
        
        return pathHelper(root, sum); 
    }
    
    private boolean pathHelper(TreeNode root, int sum) {
        if (root.left == null && root.right == null) {
            return sum == root.val; 
        }
        
        sum -= root.val; 
        boolean res = false; 
        if (root.left != null) {
            res |= pathHelper(root.left, sum); 
        }
        if (root.right != null) {
            res |= pathHelper(root.right, sum); 
        }
        
        return res; 
    }
} 