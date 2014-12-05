package algorithms.mathandprob; 

import java.util.*; 

public class CheckGrayCodeClear {
    /* Function: Check if two bytes are gray code. 
     * Solution: Use a & (a - 1) == 0 to check if a has only one 1 in binary presentation. 
     */ 
    
    public boolean checkGrayCodeClear(byte b1, byte b2) {
        if (b1 == b2) {
            return false; 
        }
        
        byte b3 = (byte) (b1 ^ b2); 
        return (byte) (b3 & (b3 - 1)) == 0; 
    }
}