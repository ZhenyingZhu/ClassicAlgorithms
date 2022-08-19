package algorithms.arrandstring; 

import java.util.*; 

public class SetMatrixZeroes {
    /* Function: If there is a 0 in the matrix, set the whole row and col to 0 in O(1) space. 
     * Solution: Mark the matrix[i][0] and [0][j] as 0. Be careful that if there is 0 in the
     *     first row or first col. First judge this. 
     */ 
    
    public void setZeroes(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return; 
        }
        
        int m = matrix.length, n = matrix[0].length; 
        boolean col; 
        boolean row = col = matrix[0][0] == 0 ? true : false; 
        for (int i = 1; i < m && !col; ++i) {
            col = matrix[i][0] == 0 ? true : false; 
        }
        for (int j = 1; j < n && !row; ++j) {
            row = matrix[0][j] == 0 ? true : false; 
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0; 
                    matrix[i][0] = 0; 
                }
            }
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0; 
                }
            }
        }
        
        if (row) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0; 
            }
        }
        
        if (col) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0; 
            }
        }
    }
}
