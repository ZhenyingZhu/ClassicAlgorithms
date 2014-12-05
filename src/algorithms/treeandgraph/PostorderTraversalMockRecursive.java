package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeNode; 

public class PostorderTraversalMockRecursive {
    /* Function: Binary Tree postorder traversal. 
     * Solution: Use a stack to mock the system stack for recursive. 
     */ 
    
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>(); 
        if (root == null) {
            return res;
        }
        
        Stack<HelpNode> stack = new Stack<HelpNode>(); 
        stack.push(new HelpNode(root)); 
        while (!stack.empty()) {
            HelpNode tmp = stack.pop(); 
            TreeNode cur = tmp.node; 
            ++tmp.cnt; 
            if (tmp.cnt == 1) {
                stack.push(tmp); 
                if (cur.left == null) {
                    continue; 
                }
                
                stack.push(new HelpNode(cur.left)); 
            } else if (tmp.cnt == 2) {
                stack.push(tmp); 
                if (cur.right == null) {
                    continue; 
                }
                
                stack.push(new HelpNode(cur.right)); 
            } else {
                res.add(cur.val); 
            }
        }
        
        return res; 
    }
    
    private class HelpNode {
        int cnt = 0; 
        TreeNode node; 
        public HelpNode(TreeNode node) {
            this.node = node; 
        }
    }
    
    /*
    public static void main(String[] args) {
        TreeNode n0 = new TreeNode(0); 
        TreeNode n1 = new TreeNode(1); 
        TreeNode n2 = new TreeNode(2); 
        TreeNode n3 = new TreeNode(3); 
        TreeNode n4 = new TreeNode(4); 
        TreeNode n5 = new TreeNode(5); 
        n0.left = n1; n0.right = n2; 
        n1.left = n3; n1.right = n4; 
        n2.left = n5; 
        System.out.println(new Test().postorderTraversal(n0)); 
    }
    */
}
