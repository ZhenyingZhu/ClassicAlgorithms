package algorithms.arrandstring; 

import java.util.*; 

public class Combinations {
    /* Function: Find all the combinations that using 1 to n to combine k numbers without diplicate. 
     * Solution: Use DFS. 
     */ 
    
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new ArrayList<List<Integer>>(); 
        if (n <= 0 || k > n) {
            return res; 
        }
        
        List<Integer> list = new ArrayList<Integer>(); 
        combineHelper(n, k, 1, list, res); 
        return res; 
    }
    
    private void combineHelper(int n, int k, int st, List<Integer> list, List<List<Integer>> res) {
        if (list.size() == k) {
            res.add(new ArrayList<Integer>(list)); 
            return; 
        }
        
        int ed = n + 1 - k + list.size(); 
        for (int i = st; i <= ed; ++i) {
            list.add(i); 
            combineHelper(n, k, i + 1, list, res); 
            list.remove(list.size() - 1); 
        }
    }
} 