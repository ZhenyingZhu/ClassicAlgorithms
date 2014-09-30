package algorithms; 

import java.util.*; 

public class LongestCommonSubsequence {
    /* Function: Find the longest common subsequence. 
     * Solution: DP. 
    */
    public List<Integer> longestCommonSubsequence(int[] arr1, int[] arr2) {
        List<Integer> res = new ArrayList<Integer>(); 
        if (arr1 == null || arr1.length == 0 || arr2 == null || arr2.length == 0) {
            return res; 
        }
        
        int m = arr1.length,  n = arr2.length; 
        int[][] f = new int[m + 1][n + 1]; 
        int[][] d = new int[m][n]; 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (arr1[i] == arr2[j]) {
                    f[i + 1][j + 1] = f[i][j] + 1; 
                    d[i][j] = 1; 
                } else {
                    f[i + 1][j + 1] = Math.max(f[i][j + 1], f[i + 1][j]); 
                    d[i][j] = f[i][j + 1] > f[i + 1][j] ? 2 : 3; 
                }
            }
        }

        recovery(arr1, d, res); 
        return res; 
    }
    
    private void recovery(int[] arr1, int[][] d, List<Integer> res) {
        int i = d.length - 1, j = d[0].length - 1; 
        while (i >= 0 && j >= 0) {
            if (d[i][j] == 1) {
                res.add(0, arr1[i]); 
                --i; 
                --j; 
            } else if (d[i][j] == 2) {
                --i; 
            } else {
                --j; 
            }
        }
    }
}
