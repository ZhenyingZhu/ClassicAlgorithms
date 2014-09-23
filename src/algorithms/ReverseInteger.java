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
    
    public static void main(String[] args){
        int A = 1000000002; 
        int ans = new Solution().reverse(A); 
        System.out.println(ans); 
    }
}
