package algorithms.datastructure; 

import java.util.*; 

public class LongestConsecutiveSequence {
    /* Function: Find the longest consecutive sequence in an unsorted array in O(n) time. 
     * Solution: Since time should be O(n), cannot sort, use bucket sorting. Use hashset 
     *     to record slots. When reach a number, find it left and right and count. The reached
     *     element can be removed because all consecutive sequence won't overlap with others. 
     */ 
    
    public int longestConsecutive(int[] num) {
        if (num == null || num.length == 0) {
            return 0; 
        }
        
        HashSet<Integer> set = new HashSet<Integer>(); 
        for (int number : num) {
            set.add(number); 
        }
        
        int tmp, cnt, max = 0; 
        for (int number : num) {
            cnt = 0; 
            tmp = number; 
            while (set.contains(tmp)) {
                ++cnt; 
                set.remove(tmp++); 
            }
            
            tmp = number - 1; 
            while (set.contains(tmp)) {
                ++cnt; 
                set.remove(tmp--); 
            }
            
            max = Math.max(max, cnt); 
        }
        
        return max; 
    }
}
