package algorithms.sortandsearch; 

import java.util.*; 

public class FindPeakElement {
    /*  Function: Find the peek element in an unduplicate array. 
     *  Solution: Use binary search. 
     */

    public int findPeakElement(int[] num) {
        int md = 0;
        if (num == null || num.length <= 1) {
            return md;
        }
        
        int st = 0, ed = num.length - 1;
        while (st + 1 < ed) {
            md = st + (ed - st) / 2;
            if (num[md] > num[md - 1] && num[md] > num[md + 1]) {
                return md;
            }
            
            if (num[md] < num[md - 1]) {
                ed = md;
            } else {
                st = md;
            }
        }
        
        if (md == 1 && num[md] < num[0]) {
            return 0;
        }
        
        if (md == num.length - 2 && num[md] < num[num.length - 1]) {
            return num.length - 1;
        }
        
        return md; 
    }
}
