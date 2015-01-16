package algorithms.treeandgraph; 

import java.util.*; 
import lib.TreeNode; 

public class TreePathFromRoot {
    /* Function: Find a path between root and a node. 
     * Solution: BFS
     */ 
    
    // Test Case
    public static void main(String[] args) {
        TreeNode n0 = new TreeNode(0); 
        TreeNode n1 = new TreeNode(1); 
        TreeNode n2 = new TreeNode(2); 
        TreeNode n3 = new TreeNode(3); 
        TreeNode n4 = new TreeNode(4); 
        TreeNode n5 = new TreeNode(5); 
        TreeNode n6 = new TreeNode(6); 
        
        n0.left = n1; n0.right = n2; 
        n1.left = n3; n1.right = n4; 
        n2.left = n5; n2.right = n6; 
        
        List<TreeNode> res = new Test().findPath(n0, n5); 
        System.out.println(res); 
    }
    
    public List<TreeNode> findPath(TreeNode root, TreeNode target) {
        List<TreeNode> res = new ArrayList<TreeNode>(); 
        if (root == null || target == null) {
            return res; 
        }
        
        TreeNodeHelper src = new TreeNodeHelper(root, null); 
        Queue<TreeNodeHelper> queue = new LinkedList<TreeNodeHelper>(); 
        queue.offer(src); 
        
        while (queue != null) {
            TreeNodeHelper cur = queue.poll(); 
            if (cur.node == target) {
                createPath(cur, res); 
                break; 
            }
            
            if (cur.node.left != null) {
                queue.offer(new TreeNodeHelper(cur.node.left, cur)); 
            }

            if (cur.node.right != null) {
                queue.offer(new TreeNodeHelper(cur.node.right, cur)); 
            }
        }
        
        return res; 
    }
    
    private void createPath(TreeNodeHelper target, List<TreeNode> path) {
        while (target != null) {
            path.add(target.node); 
            target = target.parent; 
        }
        
        Collections.reverse(path); 
    }
    
    private class TreeNodeHelper {
        TreeNode node; 
        TreeNodeHelper parent; 
        
        public TreeNodeHelper(TreeNode node, TreeNodeHelper parent) {
            this.node = node; 
            this.parent = parent; 
        }
    }
} 
