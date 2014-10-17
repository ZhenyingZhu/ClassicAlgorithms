package algorithms.arrandstring; 

import java.util.*; 

public class RotateImage {
    /* Function: Rotate a square matrix 90 degree clockwise. 
     * Solution: Notice not rotate too much. from i to n - 1 -i, where i<n/2. 
     */ 
    
    public void rotate(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length != matrix.length) {
            return; 
        }
        
        int n = matrix.length; 
        for (int i = 0; i < n / 2; ++i) {
            for (int j = i; j < n - 1 - i; ++j) {
                int tmp = matrix[i][j]; 
                matrix[i][j] = matrix[n - 1 - j][i]; 
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j]; 
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i]; 
                matrix[j][n - 1 - i] = tmp; 
            }
        }
    }
}
