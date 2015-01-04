package algorithms.arrandstring; 

import java.util.*; 

public class LongestIncreasingSubsequence {
    /* Function: Find the longest inscreasing subsequence length. 
     * Solution: DP. 
    */
    public int longestIncreasingSubsequence(int[] arr) {
        if (arr == null || arr.length == 0) {
            return 0; 
        }
        
        int n = arr.length; 
        int[] f = new int[n]; 
        int res = 0; 
        for (int i = 0; i < n; ++i) {
            f[i] = 1; 
            for (int j = 0; j < i; ++j) {
                if (arr[j] < arr[i]) {
                    f[i] = Math.max(f[i], f[j] + 1); 
                }
            }
            res = Math.max(res, f[i]); 
        }

        return res; 
    }
}
