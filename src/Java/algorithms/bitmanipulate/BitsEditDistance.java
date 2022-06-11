package algorithms.bitmanipulate; 

import java.util.*; 

public class BitsEditDistance {
    /* Function: Return the number of bits that need to convert from a to b. 
     * Solution: Use xor. 
     */ 
    
    public int bitSwapRequired(int a, int b) {
        int cnt = 0; 
        for (int c = a ^ b; c != 0; c &= c - 1) {
            cnt++; 
        }
        
        return cnt; 
    }
} 
