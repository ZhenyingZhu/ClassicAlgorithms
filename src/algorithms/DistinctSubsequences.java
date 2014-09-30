package algorithms; 

import java.util.*; 

public class DistinctSubsequences {
    /* Function: Give two string S and T, find the number of combinations that T is S's subsequences. 
     * Solution: DP. If two char match, can use this char to match, f[i][j] = f[i-1][j-1], or not,=f[i-1][j]. 
    */
    public int numDistinct(String S, String T) {
        if (S == null || T == null || S.length() < T.length()) {
            return 0; 
        }
        
        int m = S.length(), n = T.length(); 
        int[][] f = new int[m + 1][n + 1]; 
        for (int i = 0; i <= m; ++i) {
            f[i][0] = 1; 
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j <= i && j < n; ++j) {
                f[i + 1][j + 1] = f[i][j + 1]; 
                if (S.charAt(i) == T.charAt(j)) {
                    f[i + 1][j + 1] += f[i][j]; 
                }
            }
        }
        
        return f[m][n]; 
    }
}
