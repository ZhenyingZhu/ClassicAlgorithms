package algorithms.arrandstring; 

import java.util.*; 

public class LongestPrefixBetweenTwo {
    /* Function: find the longest prefix between two words in an array. 
     * Solution: This is used to shorten the string using the longest prefix. 
     */ 
    
    public int longestSamePrefix(String[] data) {
        if (data == null || data.length == 0) {
            return 0; 
        }
    
        int max = 1; 
        Arrays.sort(data); 
        for (int i = 1; i < data.length; ++i) {
            max = Math.max(max, checkPrefix(data[i], data[i - 1])); 
        }
    
        return max; 
    }

    private int checkPrefix(String s1, String s2) {
        for (int i = 0; i < s1.length(); ++i) {
            if (s1.charAt(i) != s2.charAt(i)) {
                return i; 
            }
        }
    
        return s1.length(); 
    } 
} 