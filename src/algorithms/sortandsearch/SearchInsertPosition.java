package algorithms.sortandsearch; 

import java.util.*; 

public class SearchInsertPosition {
    /* Function: 
     * Solution: 
     */ 
    
    public int searchInsert(int[] A, int target) {
        if (A == null || A.length == 0) {
            return 0; 
        }
        
        int st = 0, ed = A.length - 1, md; 
        while (st + 1 < ed) {
            md = st + (ed - st) / 2; 
            if (A[md] == target) {
                return md; 
            }
            
            if (A[md] > target) {
                ed = md; 
            } else {
                st = md; 
            }
        }
        
        if (A[st] >= target) {
            return st; 
        }
        if (A[ed] >= target) {
            return ed; 
        }
        return ed + 1; 
    }
}