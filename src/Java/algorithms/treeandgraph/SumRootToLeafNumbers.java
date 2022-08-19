package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeNode; 

public class SumRootToLeafNumbers {
    /* Function: Find the sum of all paths in the tree presented as number. 
     * Solution: previous path nodes sum * 10 add this node is the value of 
     *     this path to this node. Notice only when left and right all null, 
     *     it can count as a finished path. 
     */ 
    
    public int sumNumbers(TreeNode root) {
        return sumHelper(root, 0); 
    }
    
    private int sumHelper(TreeNode root, int pre) {
        if (root == null) {
            return 0; 
        }
        
        int cum = pre * 10 + root.val; 

        if (root.left == null && root.right == null) {
            return cum; 
        }
        
        return sumHelper(root.left, cum) + sumHelper(root.right, cum); 
    }
}
