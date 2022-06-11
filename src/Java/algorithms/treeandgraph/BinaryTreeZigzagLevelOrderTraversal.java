package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeNode; 

public class BinaryTreeZigzagLevelOrderTraversal {
    /* Function: Traverse binary tree in level order and the even row is in reverse order. 
     * Solution: Collections have method reverse. 
     */ 
    
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<List<Integer>>(); 
        if (root == null) {
            return res; 
        }
        
        Queue<TreeNode> queue = new LinkedList<TreeNode>(); 
        queue.offer(root); 
        
        int lev = 0; 
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
            
            if ((lev++) % 2 == 0) {
                res.add(list); 
            } else {
                Collections.reverse(list); 
                res.add(list); 
            }
        }
        
        return res; 
    }
} 