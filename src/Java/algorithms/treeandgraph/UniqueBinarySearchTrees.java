package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeNode; 

public class UniqueBinarySearchTrees {
    /* Function: Give an n, create all BSTs that have elements 1 to n. 
     * Solution: if st > ed, return a list with null. For all the left
     *     roots, company with each right root to create a BST. 
     */ 
    
    public List<TreeNode> generateTrees(int n) {
        List<TreeNode> res = new ArrayList<TreeNode>(); 
        if (n <= 0) {
            res.add(null); 
            return res; 
        }
        
        res = createBST(1, n); 
        return res; 
    }
    
    private List<TreeNode> createBST(int st, int ed) {
        List<TreeNode> res = new ArrayList<TreeNode>(); 
        if (st > ed) {
            res.add(null); 
            return res; 
        }
        
        for (int i = st; i <= ed; ++i) {
            List<TreeNode> lSubs = createBST(st, i - 1); 
            List<TreeNode> rSubs = createBST(i + 1, ed); 
            for (TreeNode left : lSubs) {
                for (TreeNode right : rSubs) {
                    TreeNode root = new TreeNode(i); 
                    root.left = left; 
                    root.right = right; 
                    res.add(root); 
                }
            }
        }
        
        return res; 
    }
}
