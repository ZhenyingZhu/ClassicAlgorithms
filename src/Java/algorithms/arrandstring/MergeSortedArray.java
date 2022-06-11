package algorithms.arrandstring; 

import java.util.*; 

public class MergeSortedArray {
    /* Function: A and B are sorted arrays in first m and n cells. Now merge B into A. 
     * Solution: Three pointers. 
     */ 
    
    public void merge(int A[], int m, int B[], int n) {
        if (A == null || B == null || B.length < n || A.length < m + n) {
            return; 
        }
        
        int pt = m + n - 1, pt1 = m - 1, pt2 = n - 1; 
        while (pt1 >= 0 && pt2 >= 0) {
            if (A[pt1] > B[pt2]) {
                A[pt--] = A[pt1--]; 
            } else {
                A[pt--] = B[pt2--]; 
            }
        }
        
        while (pt2 >= 0) {
            A[pt--] = B[pt2--]; 
        }
    }
} 