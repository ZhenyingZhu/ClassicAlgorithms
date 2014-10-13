package algorithms.rcanddp; 

import java.util.*; 

public class JumpGameMinStep {
    /* Function: An array indicate the jump length, find the min steps to reach the end. 
     * Solution: DP. 
    */
    public int jump(int[] A) {
        if (A == null || A.length == 0) {
            return 0; 
        }
        
        int[] f = new int[A.length]; 
        f[0] = 0; 
        for (int i = 1; i < A.length; ++i) {
            f[i] = Integer.MAX_VALUE; 
            for (int j = 0; j < i; ++j) {
                if (j + A[j] >= i) {
                    f[i] = f[j] + 1; 
                    break; 
                }
            }
        }
        
        return f[A.length - 1]; 
    }
}
