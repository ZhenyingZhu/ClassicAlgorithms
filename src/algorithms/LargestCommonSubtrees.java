package algorithms; 

import java.util.*; 

public class LargestCommonSubtrees {
    /* Function: Give the root of a n tree, find the common subtrees that have
     *    max nodes. 
     * Solution: Use priority queue to find the roots of subtrees that have max node. 
     *    One-one compare if they are common subtrees and record in a Nested-Hashtable. 
     */ 
    private static class TreeNode {
        int val; 
        List<TreeNode> children = new ArrayList<TreeNode>(); 
        public TreeNode(int x) {
            val = x; 
        }
    }
    
    // Count the nodes of this subtree
    private class Node {
        int num; 
        TreeNode treeNode; 
        public Node(TreeNode treeNode, int num) {
            this.num = num; 
            this.treeNode = treeNode; 
        }
    }
    
    public List<TreeNode> largestCommonSubtrees(TreeNode root) {
        List<TreeNode> res = new ArrayList<TreeNode>(); 
        if (root == null) {
            return res; 
        }
        
        Queue<Node> queue = new PriorityQueue<Node>(100, NodeComparator); 
        HashMap<TreeNode, HashMap<TreeNode, Boolean>> map = new HashMap<TreeNode, HashMap<TreeNode, Boolean>>(); 
        searchTree(root, queue, map); 
        
        List<Node> nodes = new ArrayList<Node>(); 
        List<TreeNode> list = new ArrayList<TreeNode>(); 
        
        int max = Integer.MAX_VALUE; // Number of nodes. 
        while (!queue.isEmpty()) {
            if (max > queue.peek().num) {
                insertRes(list, res, map); 
                if (res.size() > 1) {
                    return res; // find
                }
                
                list.clear(); 
                max = queue.peek().num; 
            }
            
            list.add(queue.poll().treeNode); 
        } 
        // The leaves. 
        insertRes(list, res, map); 
        return res; 
    }
    
    // Find all the nodes and create HashMap slots. 
    private int searchTree(TreeNode root, Queue<Node> queue, HashMap<TreeNode, HashMap<TreeNode, Boolean>> map) {
        if (root == null) {
            return 0; 
        }
        
        map.put(root, new HashMap<TreeNode, Boolean>()); 
        int sum = 1; // Number of nodes. Itself is a node. 
        for (TreeNode child : root.children) {
            sum += searchTree(child, queue, map); 
        }
        
        queue.offer(new Node(root, sum)); 
        return sum; 
    }
    
    // A largest heap. 
    private Comparator<Node> NodeComparator = new Comparator<Node>() {
        public int compare(Node n1, Node n2) {
            return n2.num - n1.num; 
        }
    }; 
    
    // Insert the groups of largest common subtrees' root into the result. 
    private void insertRes(List<TreeNode> list, List<TreeNode> res, HashMap<TreeNode, HashMap<TreeNode, Boolean>> map) {
        HashSet<TreeNode> set = new HashSet<TreeNode>(); // avoid duplicates
        for (int i = 0; i < list.size(); ++i) {
            for (int j = i + 1; j < list.size(); ++j) {
                if (isCommonTree(list.get(i), list.get(j), map)) {
                    set.add(list.get(i)); 
                    set.add(list.get(j)); 
                }
            }
        }
        
        for (TreeNode treeNode : set) {
            res.add(treeNode); 
        }
    }
    
    // DP and compare. 
    private boolean isCommonTree(TreeNode n1, TreeNode n2, HashMap<TreeNode, HashMap<TreeNode, Boolean>> map) {
        HashMap<TreeNode, Boolean> pair = map.get(n1); 
        if (pair.containsKey(n2)) {
            return pair.get(n2); 
        }
        
        if (n1.children.size() != n2.children.size()) {
            pair.put(n2, false); 
            return false; 
        }
        
        int i; 
        for (i = 0; i < n1.children.size(); ++i) {
            if (!isCommonTree(n1.children.get(i), n2.children.get(i), map)) {
                break; 
            }
        }
        
        if (i == n1.children.size()) { // All the children are same. 
            pair.put(n2, true); 
            return true; 
        } else {
            pair.put(n2, false); 
            return false; 
        }
    }
    /*  Test Case
    public static void main(String[] args) {
        TreeNode n1 = new Test.TreeNode(1); 
        TreeNode n2 = new Test.TreeNode(2); 
        TreeNode n3 = new Test.TreeNode(3); 
        TreeNode n4 = new Test.TreeNode(4); 
        TreeNode n5 = new Test.TreeNode(5); 
        TreeNode n6 = new Test.TreeNode(6); 
        TreeNode n7 = new Test.TreeNode(7); 
        TreeNode n8 = new Test.TreeNode(8); 
        TreeNode n9 = new Test.TreeNode(9); 
        TreeNode n10 = new Test.TreeNode(10); 
        TreeNode n11 = new Test.TreeNode(11); 
        TreeNode n12 = new Test.TreeNode(12); 
        TreeNode n13 = new Test.TreeNode(13); 
        TreeNode n14 = new Test.TreeNode(14); 
        TreeNode n15 = new Test.TreeNode(15); 
        TreeNode n16 = new Test.TreeNode(16); 
        TreeNode n17 = new Test.TreeNode(17); 
        TreeNode n18 = new Test.TreeNode(18); 
        n1.children.add(n2); 
        n1.children.add(n3); 
        n1.children.add(n4); 
        n3.children.add(n5); 
        n3.children.add(n6); 
        n4.children.add(n7); 
        n5.children.add(n8); 
        n6.children.add(n9); 
        n7.children.add(n10); 
        n7.children.add(n11); 
        n8.children.add(n12); 
        n8.children.add(n13); 
        n9.children.add(n14); 
        n9.children.add(n15); 
        n11.children.add(n16); 
        n12.children.add(n17); 
        n15.children.add(n18); 
        List<TreeNode> ans = new Test().largestCommonSubtrees(n1); 
        for (int i = 0; i < ans.size(); ++i) {
            System.out.print(ans.get(i).val + " "); 
        }
        System.out.println(); 
    }
    */
}
