package algorithms.arrandstring; 

import java.util.*; 

public class MaximumSubarrayTwo {
    /* Function: Find two subarray in the input to get the max sum. 
     * Solution: Find max subarray from head to end and back. Sum them. 
     */ 
    
    public int maxTwoSubArray(int[] arr) {
        if (arr == null || arr.length == 0) {
            return 0; 
        }
        
        int n = arr.length; 
        int cum = 0; 
        int[] first = new int[n]; 
        for (int i = 0; i < n; ++i) {
            cum += arr[i]; 
            first[i] = i == 0 ? cum : Math.max(cum, first[i - 1]); 
            cum = cum < 0 ? 0 : cum; 
        }
        
        cum = 0; 
        int[] second = new int[n]; 
        for (int i = n - 1; i >= 0; --i) {
            cum += arr[i]; 
            second[i] = i == n - 1 ? cum : Math.max(cum, second[i + 1]); 
            cum = cum < 0 ? 0 : cum; 
        }
        
        int res = 0; 
        for (int i = 0; i < n - 1; ++i) {
            res = Math.max(res, first[i] + second[i + 1]); 
        }
        return res; 
    }
}
