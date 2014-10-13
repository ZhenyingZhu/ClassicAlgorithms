package algorithms.bitmanipulate; 

import java.util.*; 

public class SingleNumberInThree {
    /* Function: All numbers repeate 3 times except one. Find that one. 
     * Solution: On each bit, there can only be 1 or 0 and the sum of repeate 
     *     numbers must have 3 or 0 on that bit. So use this to create res. 
     */ 

    public int singleNumber(int[] A) {
        int res = 0; 
        for (int i = 0; i < 32; ++i) {
            int bit = 0; 
            for (int j = 0; j < A.length; ++j) {
                bit += (A[j] >>> i) & 0x01; 
            }
            
            res |= (bit % 3) << i; 
        }
        
        return res; 
    }
}
