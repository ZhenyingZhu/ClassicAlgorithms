package algorithms.sortandsearch; 

import java.util.*;

public class MedianOfTwoSortedArrays {
    /* Function: Find the statistic median of two sorted array.  
     * Solution: Use the find k algorithm. 
    */
    public double findMedianSortedArrays(int A[], int B[]) {
        if (A == null || B == null) {
            return Integer.MIN_VALUE; 
        }
        int m = A.length, n = B.length, len = m + n; 
        if (len % 2 == 0) {
            return (double)(medianHelper(A, B, 0, 0, len / 2) + medianHelper(A, B, 0, 0, len / 2 + 1)) / 2; 
        } else {
            return medianHelper(A, B, 0, 0, len / 2 + 1); 
        }
    }
    
    private int medianHelper(int[] A, int[] B, int st1, int st2, int k) {
        if (st1 >= A.length) {
            return B[st2 + k - 1]; 
        }
        if (st2 >= B.length) {
            return A[st1 + k - 1]; 
        }
        if (k == 1) {
            return Math.min(A[st1], B[st2]); 
        }
        
        int key1 = st1 + k / 2 - 1 < A.length ? A[st1 + k / 2 - 1] : Integer.MAX_VALUE; 
        int key2 = st2 + k / 2 - 1 < B.length ? B[st2 + k / 2 - 1] : Integer.MAX_VALUE; 
        if (key1 < key2) {
            return medianHelper(A, B, st1 + k / 2, st2, k - k / 2); 
        } else {
            return medianHelper(A, B, st1, st2 + k / 2, k - k / 2); 
        }
    }
}
