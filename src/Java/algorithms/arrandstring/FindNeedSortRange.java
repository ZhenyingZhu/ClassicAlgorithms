package algorithms.arrandstring; 

import java.util.*; 

public class FindNeedSortRange {
    /* Function: Find the minimum sort range of an array such that sort this part 
     *     can sort the array. 
     * Solution: Seperate the array into three parts: the left sorted part, middle, 
     *     and the right sorted part. Then find the max of the first two parts and 
     *     find its position in right part. Vice visa. 
     */ 
    
    public ResultType findUnsortedSequence(int[] arr) {
        ResultType res = new ResultType(0, 0); 
        if (arr == null || arr.length <= 1) {
            return res; 
        }
        
        int i = 0; 
        
        int leftEd = -1, rightSt = -1; // leftEd must < rightSt
        for (i = 0; i <= arr.length - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                leftEd = i; 
                break; 
            }
        }
        if (i == arr.length - 1) { // Sorted
            return res; 
        }
        
        for (i = arr.length - 1; i >= 1; --i) {
            if (arr[i - 1] > arr[i]) {
                rightSt = i; 
                break; 
            }
        }
        
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE; 
        for (i = leftEd; i <= rightSt; ++i) {
            min = Math.min(min, arr[i]); 
            max = Math.max(max, arr[i]); 
        }
        
        // leftEnd must larger than min, so stop at it is okay
        for (i = 0; i < leftEd; ++i) { 
            if (arr[i] > min) {
                break; 
            }
        }
        res.st = i; 
        
        // rightSt might be the last, and must smaller than max, so stop at it is okay
        for (i = rightSt + 1; i < arr.length; ++i) { 
            if (arr[i] >= max) {
                break; 
            }
        }
        res.ed = i - 1; 
        
        return res; 
    }
    
    private class ResultType {
        int st; 
        int ed; 
        public ResultType(int st, int ed) {
            this.st = st; 
            this.ed = ed; 
        }
        
        public String toString() {
            return "st: " + st + ", ed: " + ed; 
        }
    }
}
