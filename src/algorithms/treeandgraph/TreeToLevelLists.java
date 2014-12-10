package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeNode; 

public class TreeToLevelLists {
    /* Function: link all tree nodes in same level and return a set of all levels. 
     * Solution: Use recursive. 
     */ 
    
    public List<LinkedList<TreeNode>> createLevelLinkedList(TreeNode root) {
        List<LinkedList<TreeNode>> res = new ArrayList<LinkedList<TreeNode>>(); 
        
        createHelper(root, 0, res); 
        return res; 
    }
    
    public void createHelper(TreeNode node, int height, List<LinkedList<TreeNode>> res) {
        if (node == null) {
            return; 
        }
        
        if (res.size() <= height) {
            res.add(new LinkedList<TreeNode>()); 
        }
        
        res.get(height).add(node); 
        
        createHelper(node.left, height + 1, res); 
        createHelper(node.right, height + 1, res); 
    }
} 