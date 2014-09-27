package algorithms; 

import java.util.*; 
import lib.TreeNode; 

public class BinaryTreeInorderTraversal {
    /* Function: In-Order traversal a Binary Tree. 
     * Solution: First push all left nodes to stack, then shift right. 
    */
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>(); 
        if (root == null) {
            return res; 
        }
        
        Stack<TreeNode> stack = new Stack<TreeNode>(); 
        TreeNode cur = root; 
        while (!stack.empty() || cur != null) {
            while (cur != null) {
                stack.push(cur); 
                cur = cur.left; 
            }
            
            if (!stack.empty()) {
                cur = stack.pop(); 
                res.add(cur.val); 
                cur = cur.right; 
            }
        }
        
        return res; 
    }
}
