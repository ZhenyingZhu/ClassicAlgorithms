package algorithms.arrandstring; 

import java.util.*; 

public class CombinationSum {
    /* Function: Given an array and a target, find all solutions to sum up to target. 
     * Solution: DFS. Notice when target < 0, can return. 
     */ 
    
    public List<List<Integer>> combinationSum2(int[] num, int target) {
        List<List<Integer>> res = new ArrayList<List<Integer>>(); 
        if (num == null || num.length == 0) {
            return res; 
        }
        
        Arrays.sort(num); 
        List<Integer> list = new ArrayList<Integer>(); 
        sumHelper(num, target, 0, list, res); 
        return res; 
    }
    
    private void sumHelper(int[] num, int target, int st, List<Integer> list, List<List<Integer>> res) {
        if (target == 0) {
            res.add(new ArrayList<Integer>(list)); 
        } else if (target < 0) {
            return; 
        }
        
        for (int i = st; i < num.length; ++i) {
            if (i != st && num[i] == num[i - 1]) {
                continue; 
            }
            
            list.add(num[i]); 
            sumHelper(num, target - num[i], i + 1, list, res); 
            list.remove(list.size() - 1); 
        }
    }
}