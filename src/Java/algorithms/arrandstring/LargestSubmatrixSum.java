package algorithms.arrandstring; 

import java.util.*; 

public class LargestSubmatrixSum {
    /* Function: Find the max sum that a submatrix will have in a matrix. 
     * Solution: Use suffix sum matrix to compute the sum suffix array of column. 
     *     Then do maximum subarray on each row. 
     */ 
    
    public int maxSubMatrix(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return 0; 
        }
        
        int[][] sumColMatrix = sumHelper(matrix); // A row more than matrix
        
        int max = Integer.MIN_VALUE; 
        for (int st = 0; st < matrix.length; ++st) {
            for (int ed = st + 1; ed <= matrix.length; ++ed) {
                int cum = 0; 
                for (int i = 0; i < matrix[0].length; ++i) {
                    cum += sumColMatrix[ed][i] - sumColMatrix[st][i]; 
                    max = Math.max(max, cum); 
                    if (cum < 0) {
                        cum = 0; 
                    }
                }
            }
        }
        
        return max; 
    }
    
    private int[][] sumHelper(int[][] matrix) {
        int[][] res = new int[matrix.length + 1][matrix[0].length]; 
        for (int j = 0; j < matrix[0].length; ++j) {
            res[0][j] = 0; 
            for (int i = 0; i < matrix.length; ++i) {
                res[i + 1][j] = res[i][j] + matrix[i][j]; 
            }
        }
        
        return res; 
    }
}
