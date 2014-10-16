package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeNode; 

public class ConstructBinaryTreeFromPreorderAndInorderTraversal {
    /* Function: Given two arrays that are inorder and preorder traversal of a BST, construct the BST. 
     * Solution: The first of preorder array is must the middle. Find it in inorder array and divide 
     *      and comquer. 
     */ 
    
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder == null || inorder == null || preorder.length == 0 || inorder.length != preorder.length) {
            return null; 
        }
        
        return buildHelper(inorder, 0, inorder.length - 1, preorder, 0, preorder.length - 1); 
    }
    
    private TreeNode buildHelper(int[] ino, int is, int ie, int[] pro, int ps, int pe) {
        if (is > ie) {
            return null; 
        }
        
        int im = indexOf(ino, is, ie, pro[ps]); 
        if (im == -1) {
            return null; // Wrong
        }
        
        TreeNode res = new TreeNode(ino[im]); 
        res.left = buildHelper(ino, is, im - 1, pro, ps + 1, ps + im - is); 
        res.right = buildHelper(ino, im + 1, ie, pro, ps + im - is + 1, pe); 
        
        return res; 
    }
    
    private int indexOf(int[] arr, int st, int ed, int tar) {
        for (int i = st; i <= ed; ++i) {
            if (arr[i] == tar) {
                return i; 
            }
        }
        
        return -1; 
    }
}
