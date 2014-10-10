package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeNode; 

public class TreePathSumToTarget {
    /* Function: Find paths in a tree (cannot turn) that sum to target. 
     * Solution: Use DFS with recording the parents value. 
     */ 
    
    public List<List<Integer>> findPath(TreeNode root, int target) {
        List<List<Integer>> res = new ArrayList<List<Integer>>(); 
        if (root == null) {
            return res; 
        }

        List<Integer> list = new ArrayList<Integer>(); 
        findPathHelper(root, target, list, res); 

        return res; 
    }
    
    private void findPathHelper(TreeNode root, int target, List<Integer> list, List<List<Integer>> res) {
        if (root == null) {
            return; 
        }
        
        if (root.val == target) {
            List<Integer> sol = new ArrayList<Integer>(); 
            sol.add(root.val); 
            res.add(sol); 
        }
        
        int sum = 0; 
        for (int i = list.size() - 1; i >= 0; --i) {
            
            sum += list.get(i); 
            if (sum + root.val == target) {
                List<Integer> sol = new ArrayList<Integer>(); 
                for (int j = i; j < list.size(); ++j) {
                    sol.add(list.get(j)); 
                }
                sol.add(root.val); 
                res.add(sol); 
            }
        }
        
        list.add(root.val); 
        findPathHelper(root.left, target, list, res); 
        findPathHelper(root.right, target, list, res); 
        list.remove(list.size() - 1); 
    }
}
