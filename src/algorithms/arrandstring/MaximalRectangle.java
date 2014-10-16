package algorithms.arrandstring; 

import java.util.*; 

public class MaximalRectangle {
    /* Function: Find the largest rectangle area that contains all '1' in a matrix. 
     * Solution: Create another matrix to record how many trailing 1s at this row 
     *     ending at this cell. Then it convert every column to a histogram. 
     */ 
    
    public int maximalRectangle(char[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return 0; 
        }
        
        int m = matrix.length, n = matrix[0].length; 
        int[][] rowHis = new int[m][n]; 
        for (int i = 0; i < m; ++i) {
            int cnt = 0; 
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    rowHis[i][j] = ++cnt; 
                } else {
                    cnt = rowHis[i][j] = 0; 
                }
            }
        }
        
        int max = 0; 
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                max = Math.max(max, findMax(rowHis, i, j)); 
            }
        }
        
        return max; 
    }
    
    private int findMax(int[][] rowHis, int row, int col) {
        int max = 0, h = 0, w = rowHis[row][col]; 
        for (int k = row; k >= 0; --k) {
            if (rowHis[k][col] == 0) {
                break; 
            }
            
            w = Math.min(w, rowHis[k][col]); 
            max = Math.max(max, w * ++h); 
        }
        
        return max; 
    }
}
