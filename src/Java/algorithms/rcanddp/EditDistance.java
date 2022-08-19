package algorithms.rcanddp; 

import java.util.*; 

public class EditDistance {
    /* Function: Can use insert, delete, replace each cost 1 to make word1 become word2. Get the lowest cost. 
     * Solution: if word1 is empty, then f[0][j]=j to insert all word2. if word1{i]=word2[j], the distance is 
     *     same as f[i-1][j-1]. if not, insert to word1 makes the distance same as f[i-1][j]+1, delete is 
     *     f[i][j-1]+1 that delete word2[j]. Replace is f[i-1][j-1]+1. 
     */ 
    
    public int minDistance(String word1, String word2) {
        if (word1 == null || word2 == null) {
            return 0; 
        }

        int m = word1.length(), n = word2.length(); 
        int[][] f = new int[m + 1][n + 1]; 
        f[0][0] = 0; 
        for (int i = 1; i <= m; ++i) {
            f[i][0] = i; // Need insert
        }
        for (int j = 1; j <= n; ++j) {
            f[0][j] = j; 
        }
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    f[i][j] = f[i - 1][j - 1]; 
                } else {
                    f[i][j] = 1 + Math.min(f[i - 1][j - 1], Math.min(f[i - 1][j], f[i][j - 1])); 
                }
            }
        }
        
        return f[m][n]; 
    }
}
