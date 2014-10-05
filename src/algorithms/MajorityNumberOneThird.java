package algorithms; 

import java.util.*; 

public class MajorityNumberOneThird {
    /* Function: Find a number that shows more than one-third times in an array.  
     * Solution: Find two candidates, if a different number shows, there appear 
     *     times decrease. When decreased to 0, use new candidates. 
     */ 
    
    public int majorityNumber(int[] arr) {
        if (arr == null || arr.length == 0) {
            return Integer.MAX_VALUE; 
        }
        if (arr.length < 3) {
            return arr[0]; 
        }
        
        int can1 = Integer.MIN_VALUE, can2 = Integer.MIN_VALUE; 
        int freq1 = 0, freq2 = 0; 
        for (int num : arr) {
            if (num == can1) {
                ++freq1; 
            } else if (num == can2) {
                ++freq2; 
            } else if (freq1 == 0) {
                can1 = num; 
                ++freq1; 
            } else if (freq2 == 0) {
                can2 = num; 
                ++freq2; 
            } else {
                --freq1; 
                --freq2; 
            }
        }
        
        freq1 = 0; 
        freq2 = 0; 
        for (int num : arr) {
            if (num == can1) {
                ++freq1; 
            } else if (num == can2) {
                ++freq2; 
            }
        }
        
        if (freq1 > arr.length / 3) {
            return can1; 
        }
        if (freq2 > arr.length / 3) {
            return can2; 
        }
        return Integer.MAX_VALUE; 
    }
}
