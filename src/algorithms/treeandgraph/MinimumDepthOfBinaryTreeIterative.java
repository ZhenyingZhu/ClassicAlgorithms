package algorithms.treeandgraph; 

import java.util.*; 

public class MinimumDepthOfBinaryTreeIterative {
    /* Function: Find the minimum depth of the binary tree. 
     * Solution: Use level order traversal. 
     */ 
    
    public int minDepth(TreeNode root) {
        if (root == null) {
            return 0; 
        }
        
        Queue<TreeNode> queue = new LinkedList<TreeNode>(); 
        queue.offer(root); 
        int h = 0; 
        while (!queue.isEmpty()) {
            int size = queue.size(); 
            ++h; 
            for (int i = 0; i < size; ++i) {
                TreeNode cur = queue.poll(); 
                if (cur.left == null && cur.right == null) {
                    return h; 
                }
                if (cur.left != null) {
                    queue.offer(cur.left); 
                }
                if (cur.right != null) {
                    queue.offer(cur.right); 
                }
            }
        }
        
        return h; 
    }
} 