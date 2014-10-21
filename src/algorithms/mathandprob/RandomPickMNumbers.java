package algorithms.mathandprob; 

import java.util.*; 

public class RandomPickMNumbers {
    /* Function: Randomly pick m numbers from an array in even probability. 
     * Solution: First pick m out. Then swap it if the random element is 
     *     located in first m. 
     */ 
    
    public int[] pickM(int[] arr, int m) {
        if (arr == null || arr.length < m) {
            return null; 
        }
        
        int[] res = new int[m]; 
        for (int i = 0; i < m; ++i) {
            res[i] = arr[i]; 
        }
        
        for (int i = m; i < arr.length; ++i) {
            int k = rand(0, i); 
            if (k < m) {
                res[k] = arr[i]; 
            }
        }
        
        return res; 
    }
    
    private int rand(int st, int ed) {
        return st + (int)(Math.random() * (ed - st + 1)); 
    }
}
