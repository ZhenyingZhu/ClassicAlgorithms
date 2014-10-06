package algorithms.arrandstring; 

import java.util.*; 

public class ThreeSum {
    /* Function: Find all the ways that use three numbers to sum up to 0 without duplicate.  
     * Solution: Recurse all the numbers and find two sum in the left array. Notice when find
     *     a result, start point must move forward, so use do while structure. 
     */ 
    
    public List<List<Integer>> threeSum(int[] num) {
        List<List<Integer>> res = new ArrayList<List<Integer>>(); 
        if (num == null || num.length == 0) {
            return res; 
        }
        
        Arrays.sort(num); 
        
        List<Integer> list = new ArrayList<Integer>(); 
        for (int i = 0; i < num.length - 2; ++i) {
            if (i != 0 && num[i] == num[i - 1]) {
                continue; 
            }
            list.add(num[i]); 
            twoSum(num, i + 1, -num[i], list, res); 
            list.remove(list.size() - 1); 
        }
        
        return res; 
    }
    
    private void twoSum(int[] num, int idx, int target, List<Integer> list, List<List<Integer>> res) {
        int st = idx, ed = num.length - 1;
        while (st < ed) {
            if (num[st] + num[ed] == target) {
                List<Integer> sol = new ArrayList<Integer>(list); 
                sol.add(num[st]); 
                sol.add(num[ed]); 
                res.add(sol); 
                --ed; 
                do {
                    ++st; 
                } while (st < ed && num[st] == num[st - 1]); 
            } else if (num[st] + num[ed] < target) {
                ++st; 
            } else {
                --ed; 
            }
        }
    }
}
