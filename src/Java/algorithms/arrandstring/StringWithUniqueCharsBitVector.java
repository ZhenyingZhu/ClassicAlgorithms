package algorithms.arrandstring; 

import java.util.*; 

public class StringWithUniqueCharsBitVector {
    /* Function: Check if a string only contains unique characters. 
     * Solution: Use integers as bit vectors. 
     */ 
    
    public boolean isUniqueChars(String s) {
        if (s == null || s.length() == 0) {
            return true; 
        }
        
        int[] mark = new int[256 / 32]; 
        for (char c : s.toCharArray()) {
            int pos = c; 
            int idx = pos / 32, off = pos % 32; 
            if ((mark[idx] >>> off & 1) == 1) {
                return false; 
            }
            
            mark[idx] |= 1 << off; 
        }
        
        return true; 
    }
} 