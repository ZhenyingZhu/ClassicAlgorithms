package algorithms.rcanddp; 

import java.util.*; 

public class JumpGame {
    /* Function: Given an array shows on every position how far can jump, 
     *     check if it can reach the end. 
     * Solution: Maintain two pointers. One shows how far it can reach, 
     *     another shows jump from where. If reach a position that cannot reach
     *     before, return false; 
     */ 
    
    public boolean canJump(int[] A) {
        if (A == null || A.length <= 1) {
            return true; 
        }
        
        int i = 0, far = 0; 
        while (far >= i) {
            far = Math.max(far, i + A[i++]); 
            if (far >= A.length - 1) {
                return true; 
            }
        }
        
        return false; 
    }
}
