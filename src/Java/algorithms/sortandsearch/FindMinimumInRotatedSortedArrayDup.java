package algorithms.sortandsearch; 

import java.util.*; 

public class FindMinimumInRotatedSortedArrayDup {
    /* Function: Find the minimum value in a retated sorted array which has duplicates. 
     * Solution: Draw _/-. There are 5 possibilities to seperate it. And each has serval 
     *     possibility to place the mid point. While the only different situations to
     *     the no-dup version is that st=ed, md is >st or <ed, >ed or <ed. 
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
            } else if (num[md] > num[ed]) {
                st = md; 
            } else {
                // Cannot distinguish
                for (int i = st; i < ed; ++i) {
                    if (num[i + 1] < num[i]) {
                        return num[i + 1]; 
                    }
                }
                return num[st]; 
            }
        }
        
        return Math.min(num[st], num[ed]); 
    }
}
