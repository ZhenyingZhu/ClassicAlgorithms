package algorithms.treeandgraph; 

import java.util.*; 

public class UniqueBinarySearchTrees {
    /* Function: Give a number of nodes, return how many unique BSTs these nodes can construct. 
     * Solution: If null, it is also a kind of solution. 
     */ 
    
    public int numTrees(int n) {
        if (n <= 0) {
            return 0; 
        }
        
        return numHelper(1, n); 
    }
    
    private int numHelper(int st, int ed) {
        if (st >= ed) {
            return 1; 
        }
        
        int sum = 0; 
        for (int i = st; i <= ed; ++i) {
            int left = numHelper(st, i - 1); 
            int right = numHelper(i + 1, ed); 
            sum += left * right; 
        }
        
        return sum; 
    }
}