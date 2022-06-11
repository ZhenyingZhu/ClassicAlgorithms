package algorithms.mathandprob; 

import java.util.*; 

public class ShuffleCards {
    /* Function: Perfect shuffle cards that make every permutation equally appears. 
     * Solution: Randomly find a position and swap it with each elements. 
     */ 
    
    public void shuffle(int[] cards) {
        if (cards == null || cards.length == 0) {
            return; 
        }
        
        for (int i = 0; i < cards.length; ++i) {
            int k = rand(0, i); 
            swap(cards, k, i); 
        }
    }
    
    private int rand(int st, int ed) {
        return st + (int)(Math.random() * (ed - st + 1)); 
    }
    
    private void swap(int[] arr, int a, int b) {
        int tmp = arr[a]; 
        arr[a] = arr[b]; 
        arr[b] = tmp; 
    }
}
