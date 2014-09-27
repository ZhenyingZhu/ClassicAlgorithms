package algorithms; 

import java.util.*; 
import lib.TreeNode; 

public class BinaryTreePreorderTraversal {
    /* Function: Preorder-Traversal a Binary Tree. 
     * Solution: Use a stack to simulate the recursive way. 
    */
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>(); 
        if (root == null) {
            return res; 
        }
        
        Stack<TreeNode> stack = new Stack<TreeNode>(); 
        stack.push(root); 
        
        while (!stack.empty()) {
            TreeNode cur = stack.pop(); 
            res.add(cur.val); 
            
            if (cur.right != null) {
                stack.push(cur.right); 
            }
            if (cur.left != null) {
                stack.push(cur.left); 
            }
        }
        
        return res; 
    }
}
