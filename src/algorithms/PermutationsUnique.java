package algorithms; 

import java.util.*; 

public class PermutationsUnique {
    /* Function: Return all the unique permutation of elements in num. 
     * Solution: DFS. First sort. If same as previous element, skip. 
    */
    public List<List<Integer>> permuteUnique(int[] num) {
        List<List<Integer>> res = new ArrayList<List<Integer>>(); 
        if (num == null || num.length == 0) {
            return res; 
        }
        
        Arrays.sort(num); 
        List<Integer> list = new ArrayList<Integer>(); 
        boolean[] used = new boolean[num.length]; 
        permuteHelper(num, used, list, res); 
        return res; 
    }
    
    private void permuteHelper(int[] num, boolean[] used, List<Integer> list, List<List<Integer>> res) {
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
            permuteHelper(num, used, list, res); 
            used[i] = false; 
            list.remove(list.size() - 1); 
        }
    }
}
