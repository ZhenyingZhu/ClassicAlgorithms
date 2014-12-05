package algorithms.sortandsearch; 

import java.util.*; 

public class SearchA2DMatrix {
    /* Function: The matrix is sorted in each row and the end of each row is smaller than the first of next row. 
     * Solution: Binary search. 
     */ 
    
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return false; 
        }
        
        int len = matrix.length * matrix[0].length; 
        int st = 0, ed = len - 1, md; 
        while (st + 1 < ed) {
            md = st + (ed - st) / 2; 
            int val = getVal(matrix, md); 
            if (val == target) {
                return true; 
            }
            
            if (target > val) {
                st = md; 
            } else {
                ed = md; 
            }
        }
        
        if (getVal(matrix, st) == target || getVal(matrix, ed) == target) {
            return true; 
        }
        return false; 
    }
    
    private int getVal(int[][] matrix, int idx) {
        int i = idx / matrix[0].length; 
        int j = idx % matrix[0].length; 
        return matrix[i][j]; 
    }
}