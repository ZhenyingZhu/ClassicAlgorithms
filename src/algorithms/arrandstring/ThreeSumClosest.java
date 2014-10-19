package algorithms.arrandstring; 

import java.util.*; 

public class ThreeSumClosest {
    /* Function: Find the sum of three numbers that cloest to a target. 
     * Solution: Record the difference of each two sum results. 
     */ 
    
    public int threeSumClosest(int[] num, int target) {
        if (num == null || num.length == 0) {
            return Integer.MAX_VALUE; 
        }
        
        Arrays.sort(num); 
        
        int min = Integer.MAX_VALUE; 
        for (int i = 0; i < num.length - 2; ++i) {
            int diff = twoSum(num, i + 1, target - num[i]); 
            if (diff == 0) {
                return target; 
            }
            
            if (Math.abs(min) > Math.abs(diff)) {
                min = diff; 
            }
        }
        
        return target + min; 
    }
    
    private int twoSum(int[] num, int st, int target) {
        int res = Integer.MAX_VALUE; 
        int ed = num.length - 1; 
        while (st < ed) {
            int diff = num[st] + num[ed] - target; 
            if (diff == 0) {
                return 0; 
            }
            
            if (Math.abs(diff) < Math.abs(res)) {
                res = diff; 
            }
            
            if (diff > 0) {
                --ed; 
            } else {
                ++st; 
            }
        }
        
        return res; 
    }
}
