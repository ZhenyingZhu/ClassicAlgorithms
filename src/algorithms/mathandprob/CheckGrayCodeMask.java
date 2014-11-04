package algorithms.mathandprob; 

import java.util.*; 

public class CheckGrayCodeMask {
    /* Function: Check if two bytes are grey codes. 
     * Solution: When they are same or the different bit is the highest bit, 
     *     error may occur. 
     */ 
    
    public boolean checkGrayCode(byte b1, byte b2) {
        if (b1 == b2) {
            return false; 
        }
        
        int b3 = (b1 ^ b2) & (1 << 8 - 1); 
        System.out.println(b3); 
        return ((b3 & (b3 - 1)) == 0); 
    }
    
    public static void main(String[] args) {
        boolean ans = new Test().checkGrayCode((byte)-127,(byte)1); 
        System.out.println(ans); 
    }
}