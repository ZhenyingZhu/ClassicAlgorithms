package algorithms.arrandstring; 

import java.util.*; 

public class TwoSum {
    /* Function: Return the index of two number such that they sum up to target. 
     * Solution: Sort and start from the head and end. Should return non-zero base, 
     *     increasing index. 
     */ 
    
    private class ResultType {
        int idx, val; 
        public ResultType(int i, int x) {
            idx = i; 
            val = x; 
        }
    }
    
    public int[] twoSum(int[] numbers, int target) {
        int[] res = {-1, -1}; 
        if (numbers == null || numbers.length == 0) {
            return res; 
        }
        
        int n = numbers.length; 
        ResultType[] arr = new ResultType[n]; 
        for (int i = 0; i < n; ++i) {
            arr[i] = new ResultType(i + 1, numbers[i]); 
        }
        
        Arrays.sort(arr, ResComparator); 
        
        int st = 0, ed = n - 1; 
        while (st < ed) {
            int sum = arr[st].val + arr[ed].val; 
            if (sum == target) {
                res[0] = arr[st].idx < arr[ed].idx ? arr[st].idx : arr[ed].idx;
                res[1] = arr[st].idx > arr[ed].idx ? arr[st].idx : arr[ed].idx;
                return res; 
            }
            if (sum < target) {
                ++st; 
            } else {
                --ed; 
            }
        }
        
        return res; 
    }
    
    private Comparator<ResultType> ResComparator = new Comparator<ResultType>() {
        public int compare(ResultType a, ResultType b) {
            return a.val - b.val; 
        }
    }; 
}
