package algorithms.datastructure; 

import java.util.*; 

public class GetRankOfANumberInSteam {
    /* Function: Inplement a datastructure that can track the number of Integers 
     *     that smaller or equal to a given Integer except itself. 
     * Solution: Maintains a BST. Each node record the number of nodes that are
     *     on the left which is its rank. If the input is larger, rank+1+get(right)
     *     is the rank. Notice how to handle the not appeared number. 
     */ 
    
    /* Test Case
    public static void main(String[] args) {
        TrackHeap list = new TrackHeap(); 
        System.out.println(list.getRank(1)); 
        list.track(3); 
        list.track(2); 
        list.track(5); 
        list.track(1); 
        list.track(4); 
        System.out.println(list.getRank(1)); 
        System.out.println(list.getRank(2)); 
        System.out.println(list.getRank(3)); 
        System.out.println(list.getRank(4)); 
        System.out.println(list.getRank(5)); 
        System.out.println(list.getRank(6)); 
    }
    */
}

class TrackHeap {
    Node root = null; 
    public void track(int x) {
        if (root == null) {
            root = new Node(x); 
        } else {
            insert(x, root); 
        }
    }
    
    public int getRank(int x) {
        return getRank(x, root); 
    }
    
    public int getRank(int x, Node root) {
        if (root == null) {
            return -1; 
        }
        if (root.val == x) {
            return root.rank; 
        }
        
        if (root.val > x) {
            int tmp = getRank(x, root.left); 
            if (tmp == -1) {
                return -1; // Not found
            }
            return tmp; 
        } else {
            int tmp = getRank(x, root.right); 
            if (tmp == -1) {
                return -1; 
            }
            return 1 + root.rank + tmp; 
        }
    }
    
    private void insert(int x, Node root) {
        if (x <= root.val) {
            if (root.left == null) {
                root.left = new Node(x); 
            } else {
                insert(x, root.left); 
            }
            ++root.rank; // a new smaller node appears
        } else {
            if (root.right == null) {
                root.right = new Node(x); 
            } else {
                insert(x, root.right); 
            }
        }
    }
    
    private class Node {
        int rank = 0; 
        int val; 
        Node left, right; 
        public Node(int val) {
            this.val = val; 
        }
    }
}