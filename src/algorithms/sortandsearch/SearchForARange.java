package algorithms.sortandsearch; 

import java.util.*;

public class SearchForARange {
    /* Function: Find the left and the right index of a target.  
     * Solution: Binary search on the left boundary then right.  
    */
    public int[] searchRange(int[] A, int target) {
        int[] res = {-1, -1}; 
        if (A == null || A.length == 0) {
            return res; 
        }
        
        int st = 0, ed = A.length - 1, md; 
        while (st + 1 < ed) {
            md = st + (ed - st) / 2; 
            if (A[md] < target) {
                st = md; 
            } else {
                ed = md; 
            }
        }
        if (A[st] == target) {
            res[0] = st; 
        } else if (A[ed] == target) {
            res[0] = ed; 
        } else {
            return res; 
        }
        
        st = res[0]; 
        ed = A.length - 1; 
        while (st + 1 < ed) {
            md = st + (ed - st) / 2; 
            if (A[md] <= target) {
                st = md; 
            } else {
                ed = md; 
            }
        }
        if (A[ed] == target) {
            res[1] = ed; 
        } else {
            res[1] = st; 
        }
        
        return res; 
    }
}
