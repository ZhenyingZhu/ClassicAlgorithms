package algorithms.arrandstring; 

import java.util.*; 

public class TwoSumHash {
    /* Function: Use hash map to solve two sum. 
     * Solution: Notice the result is non zero based. 
     */ 
    
    public int[] twoSum(int[] numbers, int target) {
        int[] res = {-1, -1}; 
        if (numbers == null || numbers.length < 2) {
            return res; 
        }
        
        Map<Integer, Integer> map = new HashMap<Integer, Integer>(); 
        for (int i = 0; i < numbers.length; ++i) {
            if (map.containsKey(target - numbers[i])) {
                res[0] = map.get(target - numbers[i]) + 1; 
                res[1] = i + 1;
                return res; 
            }
            
            map.put(numbers[i], i); 
        }

        return res; 
    }
}