package algorithms.arrandstring; 

import java.util.*; 

public class SubsetsUnique {
    /* Function: Return all the subsets of an array including empty set. 
     * Solution: DFS with sort to remove duplicates. 
    */
    public List<List<Integer>> subsetsWithDup(int[] num) {
        List<List<Integer>> res = new ArrayList<List<Integer>>(); 
        if (num == null || num.length == 0) {
            return res; 
        }
        
        Arrays.sort(num); 
        List<Integer> list = new ArrayList<Integer>(); 
        subsetsHelper(num, 0, list, res); 
        
        return res; 
    }
    
    private void subsetsHelper(int[] num, int st, List<Integer> list, List<List<Integer>> res) {
        res.add(new ArrayList<Integer>(list)); 
        
        for (int i = st; i < num.length; ++i) {
            if (i != st && num[i] == num[i - 1]) {
                continue; 
            }
            
            list.add(num[i]); 
            subsetsHelper(num, i + 1, list, res); 
            list.remove(list.size() - 1); 
        }
    }
}
