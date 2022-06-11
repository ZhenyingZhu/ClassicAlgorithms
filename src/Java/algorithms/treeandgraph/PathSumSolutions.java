package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeNode; 

public class PathSumSolutions {
    /* Function: Return all the root to leaf paths that sum to a value. 
     * Solution: Since only need root to leaf, so only when touch a leaf, should check if reach the sum. 
     *     Notice if use (root == null) return, will cause a path shows twices. 
     */ 
    
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> res = new ArrayList<List<Integer>>(); 
        if (root == null) {
            return res; 
        }
        
        List<Integer> list = new ArrayList<Integer>(); 
        pathHelper(root, sum, list, res); 
        return res; 
    }
    
    private void pathHelper(TreeNode root, int sum, List<Integer> list, List<List<Integer>> res) {
        list.add(root.val); 
        sum -= root.val; 
        if (root.left == null && root.right == null) {
            if (sum == 0) {
                res.add(new ArrayList<Integer>(list)); 
            }
        } else {
            if (root.left != null) {
                pathHelper(root.left, sum, list, res); 
            }
            if (root.right != null) {
                pathHelper(root.right, sum, list, res); 
            }
        }
        
        list.remove(list.size() - 1); 
    }
}