package algorithms; 

import java.util.*;

public class ReverseInteger {
    /* Function: Return a reverse of int.  
     * Solution: Consider +-, overflow, 0 at end.  
    */
    public int reverse(int x) {
        int res = 0, tmp = x; 
        
        while (tmp != 0) {
            res = res * 10 + tmp % 10; 
            tmp /= 10; 
        }
        
        if ((x ^ res) >>> 31 == 1) {
            return -1; // Overflow, the sign change
        }
        
        return res; 
    }
}
