package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeNode; 

public class BSTIterate implements Iterable<TreeNode> { 
    /* Function: A class that can iterate the tree in-order.  
     * Solution: Iterative search the tree. 
     */ 

    protected TreeNode root; // Can be used in same package but not others. 
    public BSTIterate(TreeNode root) {
        this.root = root; 
    }
    
    public Iterator<TreeNode> iterator() {
        return new Iterator<TreeNode>() {
            private TreeNode cur = root; 
            private Stack<TreeNode> stack = new Stack<TreeNode>(); 
            
            public boolean hasNext() {
                return (!stack.empty() || cur != null); 
            }
            
            public TreeNode next() {
                while (cur != null) {
                    stack.push(cur); 
                    cur = cur.left; 
                }
                TreeNode res = null; 
                if (!stack.empty()) {
                    res = stack.pop(); 
                    cur = res.right; 
                }
                if (res == null) {
                    res = next(); 
                }
                return res; 
            }
            
            public void remove() {} 
        }; 
    } 
    
    /* Test Case
    public static void main(String[] args) {
        TreeNode n0 = new TreeNode(0); 
        TreeNode n1 = new TreeNode(1); 
        TreeNode n2 = new TreeNode(2); 
        TreeNode n3 = new TreeNode(3); 
        TreeNode n4 = new TreeNode(4); 
        TreeNode n5 = new TreeNode(5); 
        n3.left = n1; n3.right = n5; 
        n1.left = n0; n1.right = n2; 
        n5.left = n4; 
        BSTIterate bst = new BSTIterate(n3); 
        Iterator<TreeNode> it = bst.iterator(); 
        while (it.hasNext()) {
            System.out.println(it.next().val + " "); 
        }
    }
    */
}
