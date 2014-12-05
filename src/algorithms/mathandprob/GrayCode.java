package algorithms.mathandprob; 

import java.util.*; 

public class GrayCode {
    /* Function: Give a number of bits, return the sequence of gray code of that bits. 
     * Solution: Notice 0 bits of gray code is 0. 
     */ 
    
    public List<Integer> grayCode(int n) {
        List<Integer> res = new ArrayList<Integer>(); 
        if (n < 0) {
            return res; 
        }
        
        res.add(0); 
        int off = 1; 
        for (int i = 0; i < n; ++i) {
            int pt = res.size() - 1; 
            for (; pt >= 0; --pt) {
                res.add(res.get(pt) + off); 
            }
            off *= 2; 
        }
        
        return res; 
    }
}