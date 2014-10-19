package algorithms.rcanddp; 

import java.util.*; 

public class LongestPalindromicSubstring {
    /* Function: Find the longest palindrome in a string. 
     * Solution: Use a matrix to record if a substring is palindrome. Notice iterate ed to 
     *      make sure sub questions have been solve. So matrix is store[st][ed] tuple. 
     */ 
    
    public String longestPalindrome(String s) {
        if (s == null || s.length() == 0) {
            return ""; 
        }
        
        int n = s.length(), max = 1, pt = 0; 
        boolean[][] matrix = new boolean[n][n]; 
        for (int ed = 0; ed < n; ++ed) {
            for (int st = 0; st <= ed; ++st) {
                if (s.charAt(st) == s.charAt(ed) && (st + 1 >= ed || matrix[st + 1][ed - 1])) {
                    matrix[st][ed] = true; 
                    if (max < ed - st + 1) {
                        pt = st; 
                        max = ed - st + 1; 
                    } 
                }
            }
        }
        
        return s.substring(pt, pt + max); 
    }
}
