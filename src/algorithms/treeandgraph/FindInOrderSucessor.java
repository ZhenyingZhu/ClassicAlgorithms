package algorithms.treeandgraph; 

import java.util.*; 
import lib.ParPointerTreeNode; 

public class FindInOrderSucessor {
    /* Function: Find the inorder successor of a node that linked to its parent. 
     * Solution: Three situation: it has right; it is left of parent; it is right of parent. 
     */ 
    
    public ParPointerTreeNode inorderSucc(ParPointerTreeNode n) {
        if (n == null) {
            return null; 
        }
        
        if (n.right == null) {
            while (n.parent != null && n == n.parent.right) {
                n = n.parent; 
            }
            
            return n.parent; 
        }
        
        ParPointerTreeNode t = n.right; 
        while (t.left != null) {
            t = t.left; 
        }
        
        return t; 
    }
} 