package algorithms.arrandstring; 

import java.util.*; 

public class CompressString {
    /* Function: Compress the string by use a number to record the appear times of a character. 
     *     If the result is longer, return origin string. 
     * Solution: First don't forget append the last char. Next don't compare the length in the 
     *     loop, because "ab" or "aab" will cause error. 
     */ 
    
    public String compress(String s) {
        if (s == null || s.length() <= 1) {
            return s; 
        }
        
        StringBuffer sb = new StringBuffer(); 
        int cnt = 1; 
        for (int i = 1; i < s.length(); ++i) {
            if (s.charAt(i) != s.charAt(i - 1)) {
                sb.append(s.charAt(i - 1)).append(String.valueOf(cnt)); 
                cnt = 1; 
            } else {
                ++cnt; 
            }
        }
        sb.append(s.charAt(s.length() - 1)).append(String.valueOf(cnt)); 
        
        return sb.length() < s.length() ? sb.toString() : s; 
    }
} 