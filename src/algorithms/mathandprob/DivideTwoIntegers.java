package algorithms.mathandprob; 

import java.util.*; 

public class DivideTwoIntegers {
    /* Function: Divide two numbers a/b without using multiplication, division or mod. 
     * Solution: <<1 is multiple 2. To avoid overflow, check a/2 > b first. If a = 2*b+1, 
     *     it should also compute, so a/2>=b is the judgement. exp is 1 at first, so if
     *     a-(b*previous exp)<tmp, the function should stop. 
     *     Edge case is b=0, a=-inf, b=-inf which makes abs useless. 
     */ 
    
    public int divide(int dividend, int divisor) {
        if (divisor == 0) {
            return Integer.MAX_VALUE; 
        }

        int res = 0; 
        if (dividend == Integer.MIN_VALUE) { // abs functions doesn't work
            dividend += Math.abs(divisor); 
            ++res; 
        }
        
        if (divisor == Integer.MIN_VALUE) {
            return res; // can only be 0 or 1. 
        }

        boolean pos = (((dividend >>> 31) ^ (divisor >>> 31)) == 1) ? false : true; 
        
        dividend = Math.abs(dividend); 
        divisor = Math.abs(divisor); 
        
        int exp = 1;
        int tmp = divisor; 
        while (dividend >= tmp) {
            while (dividend >> 1 >= tmp) {
                exp = exp << 1; 
                tmp = tmp << 1; 
            }
            
            res += exp; 
            dividend -= tmp; 
            tmp = divisor; 
            exp = 1; 
        }
        
        return pos ? res : -res; 
    }
}
