package algorithms.arrandstring; 

import java.util.*; 

public class ValidPalindrome {
    /*  Function: Check if a string is valid palindrome no matter 
     *      if it is upper case or lower case or number. Skip the specical characters. 
     *  Solution: Use while. Each time a step. 
     */

    public boolean isPalindrome(String s) {
        if (s == null) {
            return true; 
        }
        
        s = s.toLowerCase(); 
        int st = 0, ed = s.length() - 1; 
        while (st < ed) {
            if (!isChar(s, st)) {
                ++st; 
            } else if (!isChar(s, ed)) {
                --ed; 
            } else if (s.charAt(st) != s.charAt(ed)) {
                return false; 
            } else {
                ++st; 
                --ed; 
            }
        }
        
        return true; 
    }
    
    private boolean isChar(String s, int idx) {
        if (s.charAt(idx) >= 'a' && s.charAt(idx) <= 'z') {
            return true; 
        }
        
        if (s.charAt(idx) >= '0' && s.charAt(idx) <= '9') {
            return true; 
        }
        
        return false; 
    }
}
