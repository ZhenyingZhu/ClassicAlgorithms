package algorithms.sortandsearch; 

import java.util.*; 

public class FindMinimumInRotatedSortedArray {
    /* Function: A sorted array is rotated, find the minimum element in it. 
     * Solution: Binary search. Three condition: sorted, rotated point is 
     *     left to the mid, or right. 
     */ 
    
    public int findMin(int[] num) {
        if (num == null || num.length == 0) {
            return Integer.MAX_VALUE; 
        }
        
        int st = 0, ed = num.length - 1, md; 
        while (st + 1 < ed) {
            md = st + (ed - st) / 2; 
            if (num[md] < num[ed]) {
                ed = md; 
            } else {
                st = md; 
            }
        }
        
        return num[st] < num[ed] ? num[st] : num[ed]; 
    }
}
