package algorithms.bitmanipulate; 

import java.util.*; 

public class BitOnes {
    /* Function: Count how many ones in the binary present of a number. 
     * Solution: Use and operation to convert a one to zero each time. 
     */ 
    
    public int bitOnes(int x) {
        int total = 0; 
        while (x != 0) {
            x = x & (x - 1); 
            total++; 
        }
        
        return total; 
    }
} 