package algorithms.arrandstring; 

import java.util.*; 

public class Permutations {
    /* Function: Return all the no-duplicate permutations of an array. 
     * Solution: If the current value is same as the previous one, if the previous one is not used, 
     *     then the next pass will add this in it and create duplicates. 
     */ 
    
    public List<List<Integer>> permute(int[] num) {
        List<List<Integer>> res = new ArrayList<List<Integer>>(); 
        if (num == null || num.length == 0) {
            return res; 
        }
        
        Arrays.sort(num); 
        boolean[] used = new boolean[num.length]; 
        List<Integer> list = new ArrayList<Integer>(); 
        permHelper(num, used, list, res); 
        return res; 
    }
    
    private void permHelper(int[] num, boolean[] used, List<Integer> list, List<List<Integer>> res) {
        if (list.size() == num.length) {
            res.add(new ArrayList<Integer>(list)); 
            return; 
        }
        
        for (int i = 0; i < num.length; ++i) {
            if (used[i] || (i != 0 && num[i] == num[i - 1] && !used[i - 1])) {
                continue; 
            }
            
            used[i] = true; 
            list.add(num[i]); 
            permHelper(num, used, list, res); 
            list.remove(list.size() - 1); 
            used[i] = false; 
        }
    }
}