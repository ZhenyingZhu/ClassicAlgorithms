package algorithms.sortandsearch; 

import java.util.*; 

public class SortColors {
    /* Function: Sort red(0), white(1), blue(2) so that they group together. 
     * Solution: Two pointer quick sort. Notice when p2 == p1, cannot swap. 
     */ 
    
    public void sortColors(int[] A) {
        if (A == null || A.length == 0) {
            return; 
        }
        
        int red = -1, white = -1; 
        for (int i = 0; i < A.length; ++i) {
            if (A[i] == 0) {
                swap(A, ++red, i); 
                ++white; 
                if (white > red) {
                    swap(A, white, i); 
                }
            } else if (A[i] == 1) {
                swap(A, ++white, i); 
            }
        }
        
        return; 
    }
    
    private void swap(int[] A, int p1, int p2) {
        int tmp = A[p1]; 
        A[p1] = A[p2]; 
        A[p2] = tmp; 
    }
}
