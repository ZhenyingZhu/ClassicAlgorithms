package algorithms.rcanddp; 

import java.util.*; 

public class MaxMinDistanceInArray {
    /* Function: Give and array, find the distance that a number between the max value
     *     and the min value of the array is most far away to any number. 
     * Solution: sort array, and find the biggest difference. Return the half. 
     */ 
    public int maxMinDiffer(int[] arr) {
        if (arr == null || arr.length == 0) {
            return 0; 
        }
        
        Arrays.sort(arr); 
        int diff = 0; 
        for (int i = 1; i < arr.length; ++i) {
            diff = Math.max(diff, arr[i] - arr[i - 1]); 
        }
        
        return diff / 2; 
    }
}
