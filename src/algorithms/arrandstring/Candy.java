package algorithms.arrandstring; 

import java.util.*; 

public class Candy {
    /* Function: Given ratings for N children on a line, the higher rating one should 
     *     have more candies than neighbors. Every one has at least one candy. 
     * Solution: If a child's rating is less than his neighbors, he get one. So search
     *     from left and from right. If not int increasing order, assign 1. Then combine
     *     and sum the max. 
     */ 
    
    public int candy(int[] ratings) {
        if (ratings == null || ratings.length == 0) {
            return 0; 
        }
        
        int n = ratings.length; 
        int[] left = new int[n], right = new int[n]; 
        left[0] = 1; 
        right[n - 1] = 1; 
        for (int i = 1; i < n; ++i) {
            left[i] = ratings[i] > ratings[i - 1] ? left[i - 1] + 1 : 1; 
            right[n - 1 - i] = ratings[n - 1 - i] > ratings[n - i] ? right[n - i] + 1 : 1; 
        }
        
        int sum = 0; 
        for (int i = 0; i < n; ++i) {
            sum += Math.max(left[i], right[i]); 
        }
        
        return sum; 
    }
}
