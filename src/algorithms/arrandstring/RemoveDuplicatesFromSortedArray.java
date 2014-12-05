package algorithms.arrandstring; 

import java.util.*; 

public class RemoveDuplicatesFromSortedArray {
    /* Function: Only leave one copy of each element in the array. 
     * Solution: This could be a template. 
     */ 
    
    public int removeDuplicates(int[] A) {
        if (A == null || A.length == 0) {
            return 0; 
        }
        
        int pt = 0; 
        for (int i = 1; i < A.length; ++i) {
            if (A[i] != A[pt]) {
                A[++pt] = A[i]; 
            }
        }
        
        return pt + 1; 
    }
}