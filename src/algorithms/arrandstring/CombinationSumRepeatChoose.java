package algorithms.arrandstring; 

import java.util.*; 

public class CombinationSumRepeatChoose {
    /* Function: Use the numbers in array to sum to the target, the elements can be choosen several times. 
     * Solution: DFS, sort to remove duplicates, even though the number can be choosen several times. 
    */
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<List<Integer>>(); 
        if (candidates == null || candidates.length == 0 || target <= 0) {
            return res; 
        }
        
        Arrays.sort(candidates); 
        List<Integer> list = new ArrayList<Integer>(); 
        combinationHelper(candidates, target, 0, list, res); 
        
        return res; 
    }
    
    private void combinationHelper(int[] candidates, int target, int st, List<Integer> list, List<List<Integer>> res) {
        if (st == candidates.length || target < 0) {
            return; 
        }
        if (target == 0) {
            res.add(new ArrayList<Integer>(list)); 
            return; 
        }
        
        for (int i = st; i < candidates.length; ++i) {
            if (i != st && candidates[i] == candidates[i - 1]) {
                continue; 
            }
            
            list.add(candidates[i]); 
            combinationHelper(candidates, target - candidates[i], i, list, res); 
            list.remove(list.size() - 1); 
        }
    }
}
