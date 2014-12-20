package algorithms.bitmanipulate; 

import java.util.*; 

public class CheckPowerOfTwo {
    /* Function: Check if a number is power of 2. 
     * Solution: n & (n - 1)
     */ 
    
    /* Test Case
    public static void main(String[] args) {
        int n = 8; 
        System.out.println(new Test().checkPowerOfTwo(n)); 
    }
    */
    
    public boolean checkPowerOfTwo(int n) {
        if (n < 0) {
            return false; 
        }
        
        return (n & (n - 1)) == 0; 
    }
} 
