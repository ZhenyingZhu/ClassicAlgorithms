package algorithms; 

import java.util.*; 
import lib.TreeNode; 

public class LargestCommonSubtrees {
    /* Function: Find all the common subtrees root that have most number of roots  
     * in a tree. 
     * Solution: Give left node power 3, right node power 7. 
    */ 
    private class Node {
        int num = 0, hashing = 0; 
        TreeNode treeNode; 
        public Node(TreeNode treeNode, int num, int hashing) {
            this.treeNode = treeNode; 
            this.num = num; 
            this.hashing = hashing; 
        }
    }
    
    public List<TreeNode> largestCommonSubtrees(TreeNode root) {
        List<TreeNode> res = new ArrayList<TreeNode>(); 
        if (root == null || root.left == null || root.right == null) {
            return res; 
        }
        
        Queue<Node> queue = new PriorityQueue<Node>(100, NodeComparator); 
        search(root.left, queue); 
        search(root.right, queue); 
        
        List<List<Node>> lists = new ArrayList<List<Node>>(); 
        int max = Integer.MAX_VALUE; 
        while (!queue.isEmpty()) {
            Node top = queue.poll(); 
            
            if (max > top.num) { // The previous max-node-subtrees don't have a common subtree. 
                for (List<Node> maxCommonTrees : lists) {
                    if (maxCommonTrees.size() > 1) {
                        for (int i = 0; i < maxCommonTrees.size(); ++i) {
                            res.add(maxCommonTrees.get(i).treeNode); 
                        }
                    }
                }
                
                if (res.size() > 1) {
                    return res; 
                }
                lists.clear(); 
                max = top.num; 
            }

            boolean insert = false; 
            for (List<Node> list : lists) { // Find the common subtree for top. 
                if (list.get(0).hashing == top.hashing) {
                    list.add(top); 
                    insert = true; 
                    break; 
                }
            }
            if (!insert) {
                List<Node> list = new ArrayList<Node>(); 
                list.add(top); 
                lists.add(list); 
            }
        }
        
        // Those leaves
        for (List<Node> leaves : lists) {
            if (leaves.size() > 1) {
                for (int i = 0; i < leaves.size(); ++i) {
                    res.add(leaves.get(i).treeNode); 
                }
            }
        }
        
        return res; 
    }
    
    private Node search(TreeNode root, Queue<Node> queue) {
        if (root == null) {
            return new Node(null, 0, 1); 
        }
        
        Node left = search(root.left, queue); 
        Node right = search(root.right, queue); 
        Node node = new Node(root, left.num + right.num + 1, 3 * left.hashing + 7 * right.hashing); 
        queue.offer(node); 
        return node; 
    }
    
    private Comparator<Node> NodeComparator = new Comparator<Node>() {
        public int compare(Node n1, Node n2) {
            return n2.num - n1.num; 
        }
    }; 
}
