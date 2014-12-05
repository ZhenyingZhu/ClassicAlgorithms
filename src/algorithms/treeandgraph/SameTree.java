package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeNode; 

public class SameTree {
    /* Function: Check if two trees are same. 
     * Solution: Recursively check left and right. 
     */ 
    
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null) {
            return q == null; 
        }
        if (q == null) {
            return p == null; 
        }
        
        if (p.val != q.val || !isSameTree(p.left, q.left) || !isSameTree(p.right, q.right)) {
            return false; 
        }
        return true; 
    }
} 