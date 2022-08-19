package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeNode; 

public class InsertIntoBST {
    /* Function: Insert a node into binary search tree. 
     * Solution: Find the leaf, link the node as its child. 
    */
    public TreeNode insert(TreeNode root, TreeNode node) {
        if (root == null) {
            return node; 
        }
        
        TreeNode par = findParent(root, node); 
        if (node.val <= par.val) {
            par.left = node; 
        } else {
            par.right = node; 
        }
        
        return root; 
    }
    
    private TreeNode findParent(TreeNode root, TreeNode node) {
        TreeNode pt = root, par = null; 
        while (pt != null) {
            par = pt; 
            if (node.val <= pt.val) {
                pt = pt.left; 
            } else {
                pt = pt.right; 
            }
        }
        
        return par; 
    }
}
