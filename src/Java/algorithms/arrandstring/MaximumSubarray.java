package algorithms.arrandstring; 

import java.util.*; 

public class MaximumSubarray {
    /* Function: Find the subarray that has the maximum sum. 
     * Solution: A well developed algorithm. 
     */ 
    
    public int maxSubArray(int[] A) {
        if (A == null || A.length == 0) {
            return 0; 
        }
        
        int sum = 0, max = Integer.MIN_VALUE; 
        for (int i = 0; i < A.length; ++i) {
            sum += A[i]; 
            max = Math.max(max, sum); 
            if (sum < 0) {
                sum = 0; 
            }
        }
        
        return max; 
    }
}