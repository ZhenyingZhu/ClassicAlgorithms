package algorithms.arrandstring; 

import java.util.*;

public class RemoveDuplicatesFromSortedArrayII {
    /* Function: Each dup can appear at most twice.  
     * Solution: Use set to mark, use len as pointer. 
    */
    public int removeDuplicates(int[] A) {
        if (A == null || A.length == 0) {
            return 0; 
        }
        
        int len = 0; 
        HashSet<Integer> set = new HashSet<Integer>(); 
        for (int i = 0; i < A.length; ++i) {
            if (!set.contains(A[i])) {
                if (i != 0 && A[i] == A[i - 1]) {
                    set.add(A[i]); 
                }
                A[len++] = A[i]; 
            }
        }
        
        return len; 
    }
}
