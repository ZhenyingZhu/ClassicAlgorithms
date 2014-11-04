package algorithms.sortandsearch; 

import java.util.*; 

public class SearchInRotatedSortedArray {
    /* Function: Find the target in a sorted array that has been rotated. 
     * Solution: Three case: array in this part isn't rotated, mid is on 
     *     the left of rotate point, or right. When target>mid, 3 case: 
     *     1. mid>st, must in the right; 2. mid<st, target<st, in the right; 
     *     3. target>=st, in the left; Notice 1 and 2 can combine by md>st or
     *     target<st. 
     *     How: first draw three pictures. Compare target with md. If target>md, 
     *     there are two situations make sure target is in the right, and both 
     *     of them have md>st. The last one has two situations. 
     */ 
    
    public int search(int[] A, int target) {
        if (A == null || A.length == 0) {
            return -1; 
        }
        
        int st = 0, ed = A.length - 1, md; 
        while (st + 1 < ed) {
            md = st + (ed - st) / 2;
            if (A[md] == target) {
                return md; 
            }
            
            if (target > A[md]) {
                if (A[md] > A[st] || target < A[st]) {
                    st = md; 
                } else {
                    ed = md; 
                }
            } else {
                if (A[md] < A[ed] || target >= A[st]) {
                    ed = md; 
                } else {
                    st = md; 
                }
            }
        }
        
        if (A[st] == target) {
            return st; 
        }
        if (A[ed] == target) {
            return ed; 
        }
        return -1; 
    }
}
