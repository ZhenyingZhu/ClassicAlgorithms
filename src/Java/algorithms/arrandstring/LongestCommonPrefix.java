package algorithms.arrandstring; 

import java.util.*; 

public class LongestCommonPrefix {
    /* Function: Find the longest common prefix of an array of strings. 
     * Solution: Compare each two, or compare each column. 
     */ 
    
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) {
            return ""; 
        }
        
        int len = strs[0].length(); 
        char[] arr = strs[0].toCharArray(); 
        for (int i = 1; i < strs.length; ++i) {
            int j = 0; 
            while (j < len && j < strs[i].length() && strs[i].charAt(j) == arr[j]) {
                ++j; // Becareful j should stop at the shortest length
            }
            
            len = j; 
        }
        
        StringBuffer res = new StringBuffer(); 
        for (int i = 0; i < len; ++i) {
            res.append(arr[i]); 
        }
        
        return res.toString(); 
    }
}