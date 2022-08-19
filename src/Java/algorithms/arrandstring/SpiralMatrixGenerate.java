package algorithms.arrandstring; 

import java.util.*; 

public class SpiralMatrixGenerate {
    /* Function: Generate a n * n matrix that has number 1 to n^2 in spiral order. 
     * Solution: Notice don't miss the middle cell. 
     */ 
    
    public int[][] generateMatrix(int n) {
        if (n <= 0) {
            return new int[0][0]; 
        }
        
        int[][] res = new int[n][n]; 
        
        int cnt = 1; 
        for (int off = 0; off * 2 < n; ++off) {
            for (int i = off; i < n - off; ++i) {
                res[off][i] = cnt++; 
            }
            for (int j = off + 1; j < n - off; ++j) {
                res[j][n - off - 1] = cnt++; 
            }
            
            if (off * 2 == n - 1) { // When it is a square matrix, not necessary. 
                break; 
            }
            
            for (int i = n - off - 2; i >= off; --i) {
                res[n - off - 1][i] = cnt++; 
            }
            for (int j = n - off - 2; j >= off + 1; --j) {
                res[j][off] = cnt++; 
            }
        }
        
        return res; 
    }
} 