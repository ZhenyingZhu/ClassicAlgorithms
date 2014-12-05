package algorithms.rcanddp; 

import java.util.*; 

public class MinimumPathSum {
    /* Function: Find the minimum path from top-left to down-right. 
     * Solution: Can only move right or down. Use DP. 
     */ 
    
    public int minPathSum(int[][] grid) {
        if (grid == null || grid.length == 0 || grid[0].length == 0) {
            return 0; 
        }
        
        int m = grid.length, n = grid[0].length; 
        int[][] f = new int[m][n]; 
        f[0][0] = grid[0][0]; 
        for (int i = 1; i < m; ++i) {
            f[i][0] = f[i - 1][0] + grid[i][0]; 
        }
        for (int j = 1; j < n; ++j) {
            f[0][j] = f[0][j - 1] + grid[0][j]; 
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                f[i][j] = grid[i][j] + Math.min(f[i - 1][j], f[i][j - 1]); 
            }
        }
        
        return f[m - 1][n - 1]; 
    }
} 