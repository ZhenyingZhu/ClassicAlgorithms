package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeNode; 

public class ConstructBinaryTreeFromInorderAndPostorderTraversal {
    /* Function: Give two arrays that present the inorder and post order traversal of a binary tree, construct the tree. 
     * Solution: Cannot deal with the duplicate elements or inorder different from postorder elements. 
     */ 
    
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (inorder == null || postorder == null || inorder.length == 0 || postorder.length != inorder.length) {
            return null; 
        }
        
        return buildHelper(inorder, 0, inorder.length - 1, postorder, 0, postorder.length - 1); 
    }
    
    private TreeNode buildHelper(int[] inorder, int is, int ie, int[] postorder, int ps, int pe) {
        if (is > ie) {
            return null; 
        }
        
        int key = postorder[pe]; 
        int md = is; 
        while (md <= ie && inorder[md] != key) {
            ++md; 
        }
        
        TreeNode root = new TreeNode(key); 
        root.left = buildHelper(inorder, is, md - 1, postorder, ps, ps + md - is - 1); 
        root.right = buildHelper(inorder, md + 1, ie, postorder, ps + md - is, pe - 1); 
        return root; 
    }
}