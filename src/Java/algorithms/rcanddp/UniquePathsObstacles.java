package algorithms.rcanddp; 

import java.util.*; 

public class UniquePathsObstacles {
    /* Function: Find how many paths to go from top left to right down. 
     * Solution: DP. 
     */ 
    
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if (obstacleGrid == null || obstacleGrid.length == 0 || obstacleGrid[0].length == 0) {
            return 0; 
        }
        
        int m = obstacleGrid.length, n = obstacleGrid[0].length; 
        int[][] paths = new int[m + 1][n + 1]; 
        paths[1][0] = 1; 
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    paths[i + 1][j + 1] = 0; 
                } else {
                    paths[i + 1][j + 1] = paths[i][j + 1] + paths[i + 1][j]; 
                }
            }
        }
        
        return paths[m][n]; 
    }
}