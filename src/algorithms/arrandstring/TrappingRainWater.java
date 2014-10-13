package algorithms.arrandstring; 

import java.util.*; 

public class TrappingRainWater {
    /* Function: The array shows the barriers. Find the max volume of water it can take.   
     * Solution: Find the left boundary and right boundary. The min one minus is this 
     *     col's volume. 
     */ 
    
    public int trap(int[] A) {
        if (A == null || A.length == 0) {
            return 0; 
        }
        
        int n = A.length; 
        int[] left = new int[n], right = new int[n]; 
        for (int i = 1; i < n; ++i) {
            left[i] = Math.max(left[i - 1], A[i - 1]); 
            right[n - 1 - i] = Math.max(right[n - i], A[n - i]); 
        }
        
        int sum = 0; 
        for (int i = 0; i < n; ++i) {
            int vol = Math.min(left[i], right[i]) - A[i]; 
            sum += vol > 0 ? vol : 0; 
        }
        
        return sum; 
    }
}
