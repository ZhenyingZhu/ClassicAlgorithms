package algorithms.treeandgraph; 

import java.util.*; 

public class SymmetricTreeRecursive {
    /* Function: Check if a tree is symmetric by its center. 
     * Solution: Recursive. 
     */ 
    
    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true; 
        }
        
        return symmetricHelper(root.left, root.right); 
    }
    
    private boolean symmetricHelper(TreeNode a, TreeNode b) {
        if (a == null) {
            return b == null; 
        }
        if (b == null) {
            return a == null; 
        }
        
        if (a.val != b.val || !symmetricHelper(a.left, b.right) || !symmetricHelper(a.right, b.left)) {
            return false; 
        }
        return true; 
    }
} 