package algorithms.treeandgraph; 

import java.util.*; 

public class BinaryTreeLevelOrderTraversal {
    /* Function: Traverse the binary tree in level order. 
     * Solution: Use the queue size as the counter. 
     */ 
    
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<List<Integer>>(); 
        if (root == null) {
            return res; 
        }
        
        Queue<TreeNode> queue = new LinkedList<TreeNode>(); 
        queue.offer(root); 
        while (!queue.isEmpty()) {
            int size = queue.size(); 
            List<Integer> list = new ArrayList<Integer>(); 
            for (int i = 0; i < size; ++i) {
                TreeNode cur = queue.poll(); 
                list.add(cur.val); 
                
                if (cur.left != null) {
                    queue.offer(cur.left); 
                }
                if (cur.right != null) {
                    queue.offer(cur.right); 
                }
            }
            res.add(list); 
        }
        
        return res; 
    }
} 