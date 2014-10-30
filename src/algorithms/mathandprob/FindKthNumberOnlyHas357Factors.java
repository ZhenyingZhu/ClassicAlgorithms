package algorithms.mathandprob; 

import java.util.*; 

public class FindKthNumberOnlyHas357Factors {
    /* Function: Find the k th number that is 3^a * 5^b * 7^c. 
     * Solution: Use three queues. When dequeue, enqueue the multiples of 
     *     this value. To avoid repeate, the 3 multiples add 3,5,7. While 
     *     5 only add 5, 7, and 7 only add 7. 
     */ 
    
    public int getKthMagicNumber(int k) {
        if (k <= 0) {
            return 0; 
        }
        
        int[] arr = {3, 5, 7}; 
        Queue<Integer>[] queues = new Queue[3]; 
        for (int i = 0; i < 3; ++i) {
            queues[i] = new LinkedList<Integer>(); 
            queues[i].offer(arr[i]); 
            
        }
        
        int tmp = 1; 
        for (int i = 1; i < k; ++i) {
            int min = 0; 
            tmp = queues[0].peek(); 
            for (int j = 1; j < 3; ++j) {
                if (queues[j].peek() < tmp) {
                    tmp = queues[j].peek(); 
                    min = j; 
                }
            }
            
            queues[min].poll(); 
            for (; min < 3; ++min) {
                queues[min].offer(tmp * arr[min]); 
            }
        }
        
        return tmp; 
    }
}