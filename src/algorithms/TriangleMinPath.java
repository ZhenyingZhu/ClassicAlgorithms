package algorithms;

import java.util.*; 

public class TriangleMinPath {
    /* Function: Numbers stores in a triangle, find the min path from top to bottom. 
     * Solution: Use DP to compute. Use rolling array to save space. 
    */
     public int minimumTotal(List<List<Integer>> triangle) {
        if (triangle == null || triangle.size() == 0) {
            return 0; 
        }

        int n = triangle.size(); 
        int[][] f = new int[2][n + 1]; 
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0; j < triangle.get(i).size(); ++j) {
                f[i % 2][j] = triangle.get(i).get(j) + Math.min(f[(i + 1) % 2][j], f[(i + 1) % 2][j + 1]); 
            }
        }
        
        return f[0][0]; 
    }
}
