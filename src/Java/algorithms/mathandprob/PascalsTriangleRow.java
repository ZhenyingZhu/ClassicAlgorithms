package algorithms.mathandprob; 

import java.util.*; 

public class PascalsTriangleRow {
    /* Function: Construct the kth row of Pascal's Triangle. 
     * Solution: Cannot use combination because of the overflow. 
     */ 
    
    public List<Integer> getRow(int rowIndex) {
        List<Integer> res = new ArrayList<Integer>(); 
        if (rowIndex < 0) {
            return res; 
        }
        
        res.add(1); 
        for (int i = 0; i < rowIndex; ++i) {
            int pt = res.size() - 1; 
            res.add(1); 
            for (; pt > 0; --pt) {
                res.set(pt, res.get(pt) + res.get(pt - 1)); 
            }
        }

        return res; 
    }    
    
    public List<Integer> getRowSmall(int rowIndex) {
        List<Integer> res = new ArrayList<Integer>(); 
        if (rowIndex < 0) {
            return res; 
        }
        
        for (int i = 0; i <= rowIndex; ++i) {
            res.add(comb(rowIndex, i)); 
        }
        
        return res; 
    }
    
    private int comb(int sub, int idx) { // overflow when 30Ci. 
        long a = 1, b = 1; 
        for (int i = idx; i > 0; --i) {
            a *= sub--; 
        }
        
        while (idx > 0) {
            b *= idx--; 
        }
        
        return (int) (a / b); 
    }
}