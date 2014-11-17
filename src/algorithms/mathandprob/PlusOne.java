package algorithms.mathandprob; 

import java.util.*; 

public class PlusOne {
    /* Function: Plus one to an array that present a number. 
     * Solution: Notice if the last carry is 1, need a larger array. 
     */ 
    
    public int[] plusOne(int[] digits) {
        if (digits == null || digits.length == 0) {
            return new int[]{1}; 
        }
        
        List<Integer> list = new ArrayList<Integer>(); 
        int c = 1; 
        for (int i = digits.length - 1; i >= 0; --i) {
            int num = digits[i] + c; 
            list.add(num % 10); 
            c = num / 10; 
        }
        
        if (c != 0) {
            list.add(c); 
        }
        
        int[] res = new int[list.size()]; 
        int pt = list.size() - 1; 
        for (int i = 0; i < res.length; ++i) {
            res[i] = list.get(pt--); 
        }
        
        return res; 
    }
} 