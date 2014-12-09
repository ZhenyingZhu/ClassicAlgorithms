package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeNode; 

public class CreateBalanceTreeFromArray {
    /* Function: Give an sorted array. Return a minimal BST. 
     * Solution: Recursive. 
     */ 
    
    public TreeNode createMinimalBST(int[] arr) {
        if (arr == null || arr.length == 0) {
            return null; 
        }
        
        return treeHelper(arr, 0, arr.length - 1); 
    }
    
    private TreeNode treeHelper(int[] arr, int st, int ed) {
        if (st > ed) {
            return null; 
        }
        
        int md = st + (ed - st) / 2; 
        TreeNode root = new TreeNode(arr[md]); 
        root.left = treeHelper(arr, st, md - 1); 
        root.right = treeHelper(arr, md + 1, ed); 
        
        return root; 
    }
} 