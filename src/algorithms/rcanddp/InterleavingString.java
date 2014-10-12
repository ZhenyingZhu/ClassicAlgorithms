package algorithms.rcanddp; 

import java.util.*; 

public class InterleavingString {
    /* Function: Check if a string is interleaving combined by two strings. 
     * Solution: DP. 
    */
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1 == null || s2 == null || s3 == null) {
            return false; 
        }

        int m = s1.length(), n = s2.length(), l = s3.length(); 
        if (l != m + n) {
            return false; 
        }
        
        boolean[][] f = new boolean[m + 1][n + 1]; 
        f[0][0] = true; 
        for (int i = 0; i < m; ++i) {
            if (s1.charAt(i) != s3.charAt(i)) {
                break; 
            } else {
                f[i + 1][0] = true; 
            }
        }
        for (int j = 0; j < n; ++j) {
            if (s2.charAt(j) != s3.charAt(j)) {
                break; 
            } else {
                f[0][j + 1] = true; 
            }
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                f[i + 1][j + 1] |= s1.charAt(i) == s3.charAt(i + j + 1) ? f[i][j + 1] : false; 
                f[i + 1][j + 1] |= s2.charAt(j) == s3.charAt(i + j + 1) ? f[i + 1][j] : false; 
            }
        }
        
        return f[m][n]; 
    }
}
