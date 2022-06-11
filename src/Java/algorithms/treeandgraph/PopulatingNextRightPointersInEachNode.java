package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeLinkNode; 

public class PopulatingNextRightPointersInEachNode {
    /* Function: Link the nodes that on the same level in a not balanced tree, 
     *     using constant space. 
     * Solution: Cannot use any data structure. So do level by level. Using the 
     *     previous level, find the first node that has a left or right, that is
     *     the next of this level. Notice when recursive, first do right, then do
     *     left so that the previous level has already done. 
     */ 
    
    public void connect(TreeLinkNode root) {
        if (root == null) {
            return; 
        }
        
        TreeLinkNode pt = findNext(root); 
        if (root.left != null) {
            if (root.right != null) {
                root.left.next = root.right; 
            } else {
                root.left.next = pt; 
            }
        }
        
        if (root.right != null) {
            root.right.next = pt; 
        }
        
        connect(root.right); 
        connect(root.left); 
    }
    
    private TreeLinkNode findNext(TreeLinkNode root) {
        TreeLinkNode pt = root.next; 
        while (pt != null && pt.left == null && pt.right == null) {
            pt = pt.next; 
        }
        
        if (pt == null) {
            return null; 
        }
        
        return pt.left != null ? pt.left : pt.right; 
    }
}
