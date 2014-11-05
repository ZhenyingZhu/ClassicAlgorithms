package algorithms.mathandprob; 

import java.util.*; 

public class PermutationSequence {
    /* Function: Find the kth permutation in the permutations consist by 1~n. 
     * Solution: Each time, use k / n!, to find the first element should be which element. 
     */ 
    
    public String getPermutation(int n, int k) {
        if (n <= 0 || k <= 0) {
            return ""; 
        }
        
        k = k - 1; 
        boolean[] used = new boolean[n]; 
        StringBuffer sb = new StringBuffer(); 
        
        int step = 1; 
        for (int i = 1; i < n; ++i) {
            step *= i; 
        }
        
        for (int i = n; i > 1; --i) {
            int val = k / step; 
            sb.append(findVal(used, val)); 
            k = k % step; 
            step /= i - 1; 
        }
        
        sb.append(findVal(used, k)); 
        return sb.toString(); 
    }
    
    private int findVal(boolean[] used, int val) {
        int pt = 0; 
        while (val >= 0) {
            if (!used[pt++]) {
                --val; 
            }
        }
        used[pt - 1] = true; // This element is used. 
        return pt; 
    }
}