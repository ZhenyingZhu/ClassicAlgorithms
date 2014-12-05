package algorithms.mathandprob; 

import java.util.*; 

public class NextPermutation {
    /* Function: Find the next permutation of an array. If is the last perm, return the first perm. 
     * Solution: Find the first dis-order element from the end, then swap it with the next larger value, 
     *     and sort the elements after it. 
     */ 
    
    public void nextPermutation(int[] num) {
        if (num == null || num.length <= 1) {
            return; 
        }
        
        int i = num.length - 2; 
        while (i >= 0 && num[i] >= num[i + 1]) {
            --i; 
        }
        
        if (i == -1) {
            reverse(num, 0); 
            return; 
        }
        
        for (int j = num.length - 1; j > i; --j) {
            if (num[j] > num[i]) {
                swap(num, i, j); 
                break; 
            }
        }
        
        reverse(num, i + 1); 
    }
    
    private void reverse(int[] num, int st) { // Since they are sorted in decrease order. 
        int ed = num.length - 1; 
        while (st < ed) {
            swap(num, st++, ed--); 
        }
    }
    
    private void swap(int[] num, int a, int b) {
        int tmp = num[a]; 
        num[a] = num[b]; 
        num[b] = tmp; 
    }
}