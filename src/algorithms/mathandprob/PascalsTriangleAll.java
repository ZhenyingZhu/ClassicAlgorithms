package algorithms.mathandprob; 

import java.util.*; 

public class PascalsTriangleAll {
    /* Function: Output the whole pascal triangle. 
     * Solution: First process a 1. Then use the previous two sum. 
     */ 
    
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<List<Integer>>(); 
        if (numRows <= 0) {
            return res; 
        }
        
        List<Integer> list = new ArrayList<Integer>(); 
        list.add(1); 
        res.add(list); 
        
        for (int i = 0; i < numRows - 1; ++i) {
            list = new ArrayList<Integer>(); 
            list.add(1); 
            
            List<Integer> prev = res.get(i); 
            for (int j = 0; j < i; ++j) {
                list.add(prev.get(j) + prev.get(j + 1)); 
            }
            
            list.add(1); 
            res.add(list); 
        }
        
        return res; 
    }
} 