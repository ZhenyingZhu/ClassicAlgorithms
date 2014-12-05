package algorithms.sortandsearch; 

import java.util.*; 

public class SearchInRotatedSortedArrayDup {
    /* Function: An sorted array with duplicate values is rotated. Check if a target exists. 
     * Solution: Binary search. When md equals st or ed, cannot judge which part target in. 
     */ 
    
    public boolean search(int[] A, int target) {
        if (A == null || A.length == 0) {
            return false; 
        }
        
        int st = 0, ed = A.length - 1, md; 
        while (st + 1 < ed) {
            md = st + (ed - st) / 2; 
            if (A[md] == target) {
                return true; 
            }
            
            if (A[md] > target) {
                if (A[md] < A[ed] || target >= A[st]) {
                    ed = md; 
                } else {
                    if (A[md] == A[ed] && rangeSearch(A, st, md - 1, target)) {
                        return true; 
                    }
                    st = md; 
                }
            } else {
                if (A[md] > A[st] || target <= A[ed]) {
                    st = md; 
                } else {
                    if (A[md] == A[st] && rangeSearch(A, md + 1, ed, target)) {
                        return true; 
                    }
                    ed = md; 
                }
            }
        }

        if (A[st] == target) {
            return true; 
        }
        if (A[ed] == target) {
            return true; 
        }
        return false; 
    }
    
    private boolean rangeSearch(int[] A, int st, int ed, int target) {
        for (int i = st; i <= ed; ++i) {
            if (A[i] == target) {
                return true;
            }
        }
        return false; 
    }
}