package algorithms.bitmanipulate; 

import java.util.*; 

public class SingleNumber {
    /* Function: There is an array that each number appears twice excepte one, find it. 
     * Solution: Use XOR. 
     */ 
    
    public int singleNumber(int[] A) {
        if (A == null || A.length % 2 == 0) {
            return Integer.MAX_VALUE; 
        }
        
        int res = 0; 
        for (int num : A) {
            res ^= num; 
        }
        
        return res; 
    }
} 