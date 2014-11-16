package algorithms.treeandgraph; 

import java.util.*; 
import TreeLinkNode; 

public class PopulatingNextRightPointersInEachNodePerfectBinaryTree {
    /* Function: In a perfect binary tree, connect each level of tree nodes. 
     * Solution: Left points to right, right points to the next parent's left. 
     */ 
    
    public void connect(TreeLinkNode root) {
        if (root == null || (root.left == null && root.right == null)) {
            return; 
        }
        
        root.left.next = root.right; 
        root.right.next = root.next == null ? null : root.next.left; 
        
        connect(root.right); 
        connect(root.left); 
    }
} 