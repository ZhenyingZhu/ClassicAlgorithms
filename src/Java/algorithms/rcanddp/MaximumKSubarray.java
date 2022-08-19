package algorithms.rcanddp; 

import java.util.*; 

public class MaximumKSubarray {
    /* Function: Find the maximum sum of the k subarrays' in an array. 
     * Solution: DP with prifix sum. 
    */
    public int maxKSubarray(int[] arr, int k) {
        if (k <= 0 || arr == null || arr.length == 0) {
            return 0; 
        }
        
        int n = arr.length; 
        int[] sum = new int[n + 1]; 
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + arr[i - 1]; 
        }
        
        int[][] f = new int[k + 1][n + 1]; 
        for (int i = 0; i < k; ++i) { 
            for (int j = i; j < n; ++j) {
                f[i + 1][j + 1] = Integer.MIN_VALUE; 
                for (int st = i; st < j + 1; ++st) { 
                    for (int ed = st; ed < j + 1; ++ed) {
                        f[i + 1][j + 1] = Math.max(f[i + 1][j + 1], f[i][st] + sum[j + 1] - sum[ed]); 
                    }
                }
            }
        }
        
        int res = Integer.MIN_VALUE; 
        for (int i = k; i <= n; ++i) {
            res = Math.max(res, f[k][i]); 
        }
        return res; 
    }
}
