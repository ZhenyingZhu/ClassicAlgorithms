package algorithms; 

import java.util.*;

public class MaximumProductSubarray {
    /* Function: Return the max product of subarray.  
     * Solution: Consider -- is + and 0. Use prefix product. 
    */
    public int maxProduct(int[] A) {
        if (A == null || A.length == 0) {
            return 0; 
        }
        
        int res = Integer.MIN_VALUE, mul = 1, negMax = 1;
        for (int i = 0; i < A.length; ++i) {
            mul *= A[i]; 
            if (mul > 0) {
                res = Math.max(res, mul); 
            } else if (mul < 0) {
                res = Math.max(res, mul / negMax); 
                if (negMax == 1) {
                    negMax = mul; 
                } else {
                    negMax = Math.max(negMax, mul); 
                }
            } else {
                res = Math.max(res, mul); 
                mul = 1; 
                negMax = 1; 
            }
        }
        
        return res; 
    }
}
