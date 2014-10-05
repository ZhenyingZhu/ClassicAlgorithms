package algorithms; 

import java.util.*; 

public class ContainerWithMostWater {
    /* Function: The array shows the barriers. Find the most volume between two barriers. 
     * Solution: If one barrier is smaller than another, it should be replaced. 
     */ 
    
    public int maxArea(int[] height) {
        if (height == null || height.length == 0) {
            return 0; 
        }
        
        int max = 0; 
        int st = 0, ed = height.length - 1; 
        while (st < ed) {
            int h = Math.min(height[st], height[ed]); 
            max = Math.max(max, h * (ed - st)); 
            
            if (height[st] > height[ed]) {
                --ed; 
            } else {
                ++st; 
            }
        }
        
        return max; 
    }
}
