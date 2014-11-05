package algorithms.mathandprob; 

import java.util.*; 

public class Sqrt {
    /* Function: Compute the sqare root of x. 
     * Solution: Use binary search. Because sqrt(x) is smaller or equal to x/2 when x>1. So reduce the range. 
     */ 
    
    public int sqrt(int x) {
        if (x < 0) {
            return Integer.MIN_VALUE; 
        }
        if (x <= 1) {
            return x; 
        }
        
        int st = 0, ed = x / 2, md; 
        while (st + 1 < ed) {
            md = st + (ed - st) / 2; 
            if (md == x / md) {
                return md; 
            }
            
            if (md > x / md) {
                ed = md; 
            } else {
                st = md; 
            }
        }
        
        if (ed <= x / ed) {
            return ed; 
        }
        return st; 
    }
}