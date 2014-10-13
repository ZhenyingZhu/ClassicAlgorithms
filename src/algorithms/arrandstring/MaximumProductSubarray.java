package algorithms.arrandstring; 

import java.util.*; 

public class MaximumProductSubarray {
    /* Function: Return the subarray that has max product. 
     * Solution: The idea is same as max subarray. -- is +. 
     *     so keep a max and a min. When encounter a negative, 
     *     max and min become negative at same time. Then if 
     *     new A[i] is positive, max abandon the previous value. 
     */ 
    
    public int maxProduct(int[] A) {
        if (A == null || A.length == 0) {
            return 0; 
        }
        
        int res = Integer.MIN_VALUE, max = 1, min = 1; 
        for (int i = 0; i < A.length; ++i) {
            int pos = max * A[i]; 
            int neg = min * A[i]; 
            max = Math.max(Math.max(pos, neg), A[i]); 
            min = Math.min(Math.min(pos, neg), A[i]); 
            res = Math.max(max, res); 
        }
        
        return res; 
    }
}
