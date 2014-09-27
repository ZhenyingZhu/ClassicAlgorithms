package algorithms; 

import java.util.*; 
import lib.TreeNode; 

public class BinaryTreeLevelOrderTraversalBottomUp {
    /* Function: Bottom up level order traversal a binary tree. 
     * Solution: Use a indicater to count nodes on a level. 
    */
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> res = new ArrayList<List<Integer>>(); 
        if (root == null) {
            return res; 
        }
        
        Queue<TreeNode> queue = new LinkedList<TreeNode>(); 
        queue.offer(root); 
        while (!queue.isEmpty()) {
            List<Integer> list = new ArrayList<Integer>(); 
            int size = queue.size(); 
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
        
        Collections.reverse(res); 
        return res; 
    }
}
