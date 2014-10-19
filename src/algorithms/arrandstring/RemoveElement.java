package algorithms.arrandstring; 

import java.util.*; 

public class RemoveElement {
    /* Function: Remove the instance same as the given 
     *     element in an array and return the new length; 
     * Solution: This can be a template of pointer usage. 
     */ 
    
    public int removeElement(int[] A, int elem) {
        if (A == null || A.length == 0) {
            return 0; 
        }
        
        int len = 0; 
        for (int i = 0; i < A.length; ++i) {
            if (A[i] == elem) {
                continue; 
            }
            A[len++] = A[i]; 
        }
        
        return len; 
    }
}
