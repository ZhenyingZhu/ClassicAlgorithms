package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeNode; 

public class CheckBalanceTree {
    /*  Function: Check if a tree is balanced means all its subtrees
     *     have at most 1 difference in height. 
     *  Solution: Recursive check the height. 
     */

    public boolean isBalance(TreeNode root) {
        if (root == null) {
            return true;
        }

        return balanceHelper(root) != -1; 
    }

    private int balanceHelper(TreeNode root) {
        if (root == null) {
            return 0; 
        }

        int left = balanceHelper(root.left); 
        int right = balanceHelper(root.right); 
        if (left == -1 || right == -1 || (Math.abs(left - right) > 1)) {
            return -1; 
        }

        return 1 + Math.max(left, right); 
    }
}
