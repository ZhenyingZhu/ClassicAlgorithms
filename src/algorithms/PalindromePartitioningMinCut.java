package algorithms; 

import java.util.*; 

public class PalindromePartitioningMinCut {
    /* Function: Return the min cut number to part a string with all palindrome. 
     * Solution: DP with preprocess. 
    */
    public int minCut(String s) {
        if (s == null || s.length() == 0) {
            return 0; 
        }
        
        int n = s.length(); 
        boolean[][] matrix = new boolean[n][n]; 

        int[] f = new int[n + 1]; 
        f[0] = -1; 
        for (int ed = 0; ed < n; ++ed) {
            f[ed + 1] = Integer.MAX_VALUE; 
            for (int st = 0; st <= ed; ++st) {
                if (isPalindrome(s, st, ed, matrix)) {
                    f[ed + 1] = Math.min(f[ed + 1], f[st] + 1); 
                }
            }
        }
        
        return f[n]; 
    }
    
    private boolean isPalindrome(String s, int st, int ed, boolean[][] matrix) {
        if (s.charAt(st) == s.charAt(ed) && (st + 1 >= ed || matrix[st + 1][ed - 1])) {
            matrix[st][ed] = true; 
            return true; 
        }
        return false; 
    }
}
