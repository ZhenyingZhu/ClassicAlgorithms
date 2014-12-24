package algorithms.arrandstring; 

import java.util.*; 

public class MajorityElement {
    /* Function: Find the number that appears in the array more or equal than half times. 
     * Solution: Use offset thought. 
     */ 
    
    // Test Case
    public int majorityElement(int[] num) {
        if (num == null || num.length == 0) {
            return Integer.MAX_VALUE; 
        }
        
        int res = 0; 
        int cnt = 0; 
        
        for (int i = 0; i < num.length; ++i) {
            if (cnt == 0) {
                res = num[i]; 
            } 
            
            if (num[i] == res) {
                cnt++; 
            } else {
                cnt--; 
            }
        }
        
        return res; 
    }
} 
