package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeNode; 

public class FindCommonAncestor {
    /* Function: Find common ancestor of two nodes in a tree. If a node is not in
     *     the tree, return false. 
     * Solution: If know parents, create two lists to root, and from root check which
     *     is the last node is appear in two lists; If not, check if two sub tree contains
     *     either n1 or n2. 
     */ 
    
    boolean find1 = false, find2 = false; 
    
    public TreeNode findCommonAncestor(TreeNode root, TreeNode n1, TreeNode n2) {
        if (root == null || n1 == null || n2 == null) {
            return null; 
        }
        
        if (n1 == n2) {
            return n1; 
        }
        
        TreeNode res = findHelper(root, n1, n2); 
        
        if (find1 && find2) {
            return res; 
        }
        
        return null; // One node is not in the tree. 
    }
    
    private TreeNode findHelper(TreeNode root, TreeNode n1, TreeNode n2) {
        if (root == null) {
            return null; 
        }
        
        TreeNode left = findHelper(root.left, n1, n2); 
        TreeNode right = findHelper(root.right, n1, n2); 
        if ((left == n1 && right == n2) || (left == n2 && right == n1)) {
            return root; // Find
        }
        
        if (root == n1) {
            find1 = true; 
            return n1; 
        }
        
        if (root == n2) {
            find2 = true; 
            return n2; 
        }
        
        if (left != null) {
            return left; 
        } else {
            return right; 
        }
    }
}
