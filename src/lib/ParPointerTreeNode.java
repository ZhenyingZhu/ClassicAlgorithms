package lib; 

public class ParPointerTreeNode {
    public int val; 
    public ParPointerTreeNode parent, left, right; 
    
    public ParPointerTreeNode(int val) {
        this.val = val; 
    }
    
    public void addLeft(ParPointerTreeNode left) {
        this.left = left; 
        left.parent = this; 
    }
    
    public void addRight(ParPointerTreeNode right) {
        this.right = right; 
        right.parent = this; 
    }
    
    public String toString() {
        return "/" + val + "\\"; 
    }
}