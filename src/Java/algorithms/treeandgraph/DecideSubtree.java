package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeNode; 

public class DecideSubtree {
    /* Function: Check if the second tree is a subtree of the first one. 
     * Solution: Use serialize by inorder and postorder to check. 
     */ 
    
    public boolean containsTree(TreeNode t1, TreeNode t2) {
        if (t1 == null || t2 == null) {
            return false; 
        }
        
        String i1 = inorderSerialize(t1), i2 = inorderSerialize(t2); 
        String p1 = postorderSerialize(t1), p2 = postorderSerialize(t2); 
        return (i1.contains(i2) && p1.contains(p2)); 
    }
    
    private String inorderSerialize(TreeNode root) {
        StringBuffer sb = new StringBuffer(); 
        Stack<TreeNode> stack = new Stack<TreeNode>(); 
        
        TreeNode cur = root; 
        while (cur != null || !stack.empty()) {
            while (cur != null) {
                stack.push(cur); 
                cur = cur.left; 
            }
            
            // sb.append("#").append(','); No need to do this. Always be #a#b. 
            
            if (!stack.empty()) {
                cur = stack.pop(); 
                sb.append(cur.val).append(','); 
                cur = cur.right; 
            }
        }
        
        System.out.println(sb); 
        return sb.toString(); 
    }

    private String postorderSerialize(TreeNode root) {
        StringBuffer sb = new StringBuffer(); 
        Stack<TreeNode> stack = new Stack<TreeNode>(); 
        
        TreeNode cur = root; 
        stack.push(cur); 
        
        int c = 0, t = 0; 
        while (!stack.empty()) {
            boolean leaf = false; 
            while (cur != null) {
                leaf = true; 
                stack.push(cur); 
                cur = cur.left; 
            }
            
            if (leaf) {
                sb.append("#").append(','); 
            }
            
            TreeNode pre = null; 
            cur = stack.pop(); 
            while (!stack.empty()) {
                if (pre == cur.right) {
                    if (pre == null) {
                        sb.append("#").append(','); 
                    }
                    
                    sb.append(cur.val).append(','); 
                    pre = cur; 
                    cur = stack.pop(); 
                } else {
                    stack.push(cur); 
                    cur = cur.right; 
                    break; 
                }
            }
        }
        
        System.out.println(sb); 
        return sb.toString(); 
    }
    
    /* Test case
    public static void main(String[] args) {
        TreeNode n0 = new TreeNode(1); 
        TreeNode n1 = new TreeNode(1); 
        TreeNode n2 = new TreeNode(1); 
        TreeNode n3 = new TreeNode(1); 
        TreeNode n4 = new TreeNode(1); 
        TreeNode n5 = new TreeNode(1); 
        TreeNode n6 = new TreeNode(1); 
        
        n0.left = n1; n0.right = n2; 
        n1.left = n3; // n1.right = n4; 
        n2.left = n5; // n2.right = n6; 
        
        n0.right = n2; n2.left = n5; 
        TreeNode m0 = new TreeNode(1); 
        TreeNode m1 = new TreeNode(1); 
        TreeNode m2 = new TreeNode(1); 
        //m0.left = m1; 
        m0.right = m2; 
        
        System.out.println(new Test().containsTree(n0, m0)); 
    }
    */
} 