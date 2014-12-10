package lib; 

public class TreeNode {
    public TreeNode left; 
    public TreeNode right; 
    public int val; 
    public TreeNode(int x) {
        val = x; 
    }
    
    public String toString() {
        return "node: " + val + ";"; 
    }
}