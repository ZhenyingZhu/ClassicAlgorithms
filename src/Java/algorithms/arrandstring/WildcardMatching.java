package algorithms.detail; 

import java.util.*; 

public class WildcardMatching {
    /* Function: Check is s matchs p's pattarn. ? means a char and * means 0 or more char. 
     * Solution: If find a *, mark the current s and p pointers. When dismatch, p move back 
     *    to the next of * and s move back to the next mark position to put a char in *. 
     */ 
    
    public boolean isMatch(String s, String p) {
        int i = 0, j = 0; 
        int star = -1, mark = -1; 
        
        while (i < s.length()) {
            if (j < p.length() && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '?')) {
                ++i; 
                ++j; 
            } else if (j < p.length() && p.charAt(j) == '*') {
                star = j++; 
                mark = i; 
            } else if (star != -1) {
                i = mark++; 
                j = star + 1; 
            } else {
                return false; 
            }
        }
        
        while (j < p.length() && p.charAt(j) == '*') {
            ++j; 
        }
        return j == p.length(); 
    }
}
