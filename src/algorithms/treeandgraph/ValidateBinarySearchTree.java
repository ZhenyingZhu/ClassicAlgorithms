package algorithms.treeandgraph; 

import java.util.*; 

public class ValidateBinarySearchTree {
    /* Function: Check if the tree is a valid BST. 
     * Solution: Cannot use inorder traversal when the defination of BST is left<=root<right. 
     */ 
    
    public boolean isValidBST(TreeNode root) {
        if (root == null) {
            return true; 
        }
        
        ResultType res = checkBST(root); 
        if (res == null) {
            return false; 
        }
        return true; 
    }
    
    private ResultType checkBST(TreeNode root) { // root cannot be null
        ResultType left = root.left == null ? new ResultType(root.val, root.val - 1) : checkBST(root.left); 
        ResultType right = root.right == null ? new ResultType(root.val + 1, root.val) : checkBST(root.right); 
        
        // If as the ITA describes, root.val=left is also valid
        if (left == null || right == null || root.val <= left.max || root.val >= right.min) { 
            return null; 
        }
        
        return new ResultType(left.min, right.max); 
    }
    
    private class ResultType {
        protected int min, max; 
        public ResultType(int min, int max) {
            this.min = min; 
            this.max = max; 
        }
    }
}