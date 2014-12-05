package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeNode; 

public class ConvertSortedArrayToBinarySearchTree {
    /* Function: Give an sorted array, construct a BST from it. 
     * Solution: Recursive. 
     */ 
    
    public TreeNode sortedArrayToBST(int[] num) {
        if (num == null || num.length == 0) {
            return null; 
        }
        
        return builder(num, 0, num.length - 1); 
    }
    
    private TreeNode builder(int[] num, int st, int ed) {
        if (st > ed) {
            return null; 
        }
        
        int md = st + (ed - st) / 2; 
        TreeNode root = new TreeNode(num[md]); 
        root.left = builder(num, st, md - 1); 
        root.right = builder(num, md + 1, ed); 
        
        return root; 
    }
}