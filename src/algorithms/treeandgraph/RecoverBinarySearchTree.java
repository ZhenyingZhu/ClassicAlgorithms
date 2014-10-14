package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeLinkNode; 

public class RecoverBinarySearchTree {
    /* Function: There are two nodes in wrong order in BST, swap it in O(1) space. 
     * Solution: The return is void, so can only swap number of nodes. O(1) space
     *     means using recursive. Tricky part is only have two nodes. So if find 
     *     a misorder node, the previous one and this one may both be dis order one. 
     */ 
    
    TreeNode pre = null, a = null, b = null; 
    
    public void recoverTree(TreeNode root) {
        if (root == null) {
            return; 
        }
        
        search(root); 
        if (a != null) {
            int tmp = a.val; 
            a.val = b.val; 
            b.val = tmp; 
        }
    }
    
    private void search(TreeNode root) {
        if (root == null) {
            return; 
        }
        
        search(root.left); 
        
        if (pre != null && pre.val > root.val) {
            if (a == null) {
                a = pre; 
            } 
            b = root; 
        }
        pre = root; 
        
        search(root.right); 
    }
}
