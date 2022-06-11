package algorithms.rcanddp; 

import java.util.*; 

public class ClimbingStairs {
    /* Function: Each time can climb one or two steps. Find out the total ways
     *     to climb to n th floor. 
     * Solution: Dynamic Program. 
     */ 
    
    public int climbStairs(int n) {
        if (n <= 0) {
            return 0; 
        }
        
        int[] f = new int[n + 1]; 
        f[0] = 1; 
        f[1] = 1; 
        for (int i = 1; i < n; ++i) {
            f[i + 1] = f[i] + f[i - 1]; 
        }
        
        return f[n]; 
    }
}
