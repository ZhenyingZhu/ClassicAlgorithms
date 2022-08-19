package algorithms.arrandstring; 

import java.util.*; 

public class Subsets {
    /* Function: Give an array, find all the subsets it has. 
     * Solution: DFS
     */ 
    
    public List<List<Integer>> subsets(int[] S) {
        List<List<Integer>> res = new ArrayList<List<Integer>>(); 
        if (S == null || S.length == 0) {
            return res; 
        }
        
        Arrays.sort(S); 
        List<Integer> list = new ArrayList<Integer>(); 
        subsetHelper(S, 0, list, res); 
        return res; 
    }
    
    private void subsetHelper(int[] S, int st, List<Integer> list, List<List<Integer>> res) {
        res.add(new ArrayList<Integer>(list)); 
        if (st == S.length) {
            return; 
        }
        
        for (int i = st; i < S.length; ++i) {
            if (i != 0 && S[i] == S[i - 1]) {
                continue; 
            }
            
            list.add(S[i]); 
            subsetHelper(S, i + 1, list, res); 
            list.remove(list.size() - 1); 
        }
    }
} 