package algorithms.sortandsearch; 

import java.util.*; 

public class FirstMissingPositive {
    /* Function: Find the first missing consecutive interger start from 1 in an 
     *     array. Using O(n) time and O(1) space. 
     * Solution: Can only use O(n) time, so it is bucket sorting. When find an
     *     element in a wrong place, swap it until the right element shows up. 
     *     Each time several elements sorted. So the total running time is O(2n). 
     *     The edge cases are that 1. Meet an out range element, leave it there. 
     *     2. Duplicate elements. This will cause dead-end cycle since they occupy 
     *     the same position. So when find the target is sorted, break. 
     */ 
    
    public int firstMissingPositive(int[] A) {
        if (A == null || A.length == 0) {
            return 1; 
        }
        
        bucketSorting(A); 
        for (int i = 0; i < A.length; ++i) {
            if (A[i] != i + 1) {
                return i + 1; 
            }
        }
        
        return A.length + 1; 
    }
    
    private void bucketSorting(int[] A) {
        for (int i = 0; i < A.length; ++i) {
            int tmp = 0; 
            while (A[i] > 0 && A[i] <= A.length && A[i] != i + 1) {
                tmp = A[i]; 
                if (A[tmp - 1] == tmp) {
                    break; // Already sorted
                }
                
                A[i] = A[tmp - 1]; 
                A[tmp - 1] = tmp; 
            }
            
        }
    }
}
