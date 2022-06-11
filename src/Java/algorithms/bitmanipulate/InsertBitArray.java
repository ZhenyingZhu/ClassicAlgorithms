package algorithms.bitmanipulate; 

import java.util.*; 

public class InsertBitArray {
    /* Function: Insert m to n from i to j bits counting from right. 
     * Solution: Create a mask to reset i to j. And use OR. 
     */ 
    
    public int updateBits(int n, int m, int i, int j) {
        int mask = ~(((1 << (j - i + 1)) - 1) << i); 
        printBit(mask); 
        n = n & mask; 
        return n | (m << i); 
    }
} 