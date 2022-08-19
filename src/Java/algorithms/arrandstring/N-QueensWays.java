package algorithms.arrandstring; 

import java.util.*; 

public class N-QueensWays {
    /* Function: Place n queens that won't affacted each others. Return the number of ways. 
     * Solution: Use an array to record the previous configuration. Use it to find it current
     *     position is valid. 
     */ 
    
    int sum = 0; 
    public int totalNQueens(int n) {
        if (n <= 0) {
            return 0; 
        }
        
        int[] conf = new int[n]; 
        queenHelper(n, 0, conf); 
        return sum; 
    }
    
    private void queenHelper(int n, int idx, int[] conf) {
        if (idx == n) {
            ++sum; 
            return; 
        }
        
        boolean[] invalid = new boolean[n]; 
        for (int i = 0; i < idx; ++i) {
            int pos = conf[i]; 
            invalid[pos] = true; 
            if (pos - idx + i >= 0) {
                invalid[pos - idx + i] = true; 
            }
            if (pos + idx - i < n) {
                invalid[pos + idx - i] = true; 
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (!invalid[i]) {
                conf[idx] = i; 
                queenHelper(n, idx + 1, conf); 
            }
        }
    }
}
