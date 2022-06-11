package algorithms.rcanddp; 

import java.util.*; 

public class UniquePaths {
    /* Function: Find the total number of paths from top-left to right-down. 
     * Solution: (m+n)C(n). But will overflow. 
     */ 
    
    public int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) {
            return 0; 
        }
        
        int[][] f = new int[m + 1][n + 1]; 
        f[1][0] = 1; 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                f[i + 1][j + 1] = f[i + 1][j] + f[i][j + 1]; 
            }
        }
        
        return f[m][n]; 
    }
} 