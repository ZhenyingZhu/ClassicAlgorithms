package algorithms; 

import java.util.*; 

public class FindKMaxValueInArray {
    /* Function: While input an array, find the k most largest number. 
     * Solution: Use heap to record the input. If the exceed the size, 
     *     abandon the smallest value. Can be modified for online alg. 
     */ 
    
    public int[] findKMax(int[] arr, int k) {
        if (arr == null || arr.length <= k) {
            return arr; 
        }
        
        Queue<Integer> queue = new PriorityQueue<Integer>(k); 
        for (int i = 0; i < arr.length; ++i) {
            queue.offer(arr[i]); 
            if (queue.size() > k) {
                queue.poll(); 
            }
        }
        
        int[] res = new int[k]; 
        int i = 0; 
        while (!queue.isEmpty()) {
            res[i++] = queue.poll(); 
        }
        
        return res; 
    }
}
