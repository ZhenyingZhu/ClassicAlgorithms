package algorithms; 

import java.util.*;

public class SpiralMatrix {
    /* Function: Output the number in a matrix in sprial order.
     * Solution: Use an offset to record the start point. 
     *   2*2 and 3*3 has different request of the middle, so offset*2 as judge condition
     *   When 3*4 or the differ is larger, the middle row will go back. So if condition is needed
    */
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<Integer>(); 
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return res; 
        }
        
        int m = matrix.length, n = matrix[0].length; 
        for (int offset = 0; offset * 2 < m && offset * 2 < n; ++offset) { // m=3 and m=2
            for (int i = offset; i < n - offset; ++i) {
                res.add(matrix[offset][i]); 
            }
            for (int j = offset + 1; j < m - offset; ++j) {
                res.add(matrix[j][n - 1 -offset]); 
            }
            
            if (offset * 2 == m - 1 || offset * 2 == n - 1) {
                break; // To avoid go back
            }
            
            for (int i = n - 2 - offset; i >= offset; --i) {
                res.add(matrix[m - 1 - offset][i]); 
            }
            for (int j = m - 2 - offset; j >= offset + 1; --j) {
                res.add(matrix[j][offset]); 
            }
        }
        
        return res; 
    }
    
    public static void main(String[] args){
        String[] A = {"ab", "ab", "bb"}; 
        List<String> ans = new Solution().anagrams(A); 
        System.out.println(ans); 
    }
}
