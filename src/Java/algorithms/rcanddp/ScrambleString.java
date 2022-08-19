package algorithms.rcanddp; 

import java.util.*; 

public class ScrambleString {
    /* Function: Create a binary tree by partition a strings two subtree recursively. Now swap any two 
     *     children of nodes and create a new string, check if it is scramble of the origin string. 
     * Solution: The false case is that a char in a left subtree appears in the right subtree. 
     *     There are two ways of swap: abc de = de abc, and abc de = abc de; f[k][i][j] where k means 
     *     the len of substring, i means the start of s1, and j means the start of s2. 
     */ 
    
    public boolean isScramble(String s1, String s2) {
        if (s1 == null || s2 == null || s1.length() == 0 || s1.length() != s2.length()) {
            return false; 
        }
        
        int len = s1.length(); 
        boolean[][][] f = new boolean[len + 1][len][len]; 
        
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                f[1][i][j] = s1.charAt(i) == s2.charAt(j) ? true : false; 
            }
        }
        
        for (int k = 2; k <= len; ++k) {
            for (int i = 0; i <= len - k; ++i) {
                for (int j = 0; j <= len - k; ++j) {
                    // The k length strings start from s1[i] and s2[j] are scramble? 
                    for (int p = 1; p < k && !f[k][i][j]; ++p) {
                        f[k][i][j] = (f[p][i][j + k - p] && f[k - p][i + p][j]) || (f[p][i][j] && f[k - p][i + p][j + p]); 
                    }
                }
            }
        }
        
        return f[len][0][0]; 
    }
}
