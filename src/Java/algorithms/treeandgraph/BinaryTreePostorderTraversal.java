package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeNode; 

public class BinaryTreePostorderTraversal {
    /* Function: Post-Order traversal a tree. 
     * Solution: add all left child in. Use a point to record 
     *     previous result. Output all right child until middle. 
     *     move to right, start again. 
     */ 
    
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>(); 
        if (root == null) {
            return res; 
        }
        
        Stack<TreeNode> stack = new Stack<TreeNode>(); 
        TreeNode cur = root; 
        stack.push(cur); 
        while (!stack.empty()) {
            while (cur != null) {
                stack.push(cur); 
                cur = cur.left; 
            }
            
            cur = stack.pop(); 
            TreeNode pre = null; 
            while (!stack.empty()) {
                if (cur.right == pre) {
                    res.add(cur.val); 
                    pre = cur; 
                    cur = stack.pop(); 
                } else {
                    stack.push(cur); 
                    cur = cur.right; 
                    break; 
                }
            }
        }
        
        return res; 
    }
}
