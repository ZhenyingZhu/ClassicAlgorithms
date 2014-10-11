package algorithms.detail; 

import java.util.*; 

public class RegularExpressionMatching {
    /* Function: Check if s match p. . means any char and * means zero or more previous char. 
     *     .* means any char. 
     * Solution: Recursive. Base case is p is empty or is only one char. Make sure * always shows
     *     on p.charAt(1). Check all the s.charAt(0) == p.charAt(0) and let s = s.substring(1); 
     */ 
    
    public boolean isMatch(String s, String p) {
        if (p.length() == 0) {
            return s.length() == 0; 
        }
        
        if (p.length() == 1) {
            return (s.length() == 1 && (s.equals(p) || p.equals(".")));  
        }
        
        if (p.charAt(1) != '*') {
            if (s.length() == 0 || (s.charAt(0) != p.charAt(0) && p.charAt(0) != '.')) {
                return false; 
            }
            return isMatch(s.substring(1), p.substring(1)); 
        }
        
        while (s.length() > 0 && (s.charAt(0) == p.charAt(0) || p.charAt(0) == '.')) {
            if (isMatch(s, p.substring(2))) {
                return true; 
            }
            s = s.substring(1); 
        }
        
        return isMatch(s, p.substring(2)); 
    }
}
