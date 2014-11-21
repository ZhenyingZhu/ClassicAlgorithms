package algorithms.arrandstring; 

import java.util.*; 

public class ValidPalindromePreProcess {
    /* Function: Check if a string is valid palindrome when ignore 
     *     cases and special characters. 
     * Solution: Preprocess input can reuse the function, which is better. 
     */ 
    
    public boolean isPalindrome(String s) {
        if (s == null || s.length() == 0) {
            return true; 
        }
        
        s = preprocess(s); 
        int st = 0, ed = s.length() - 1; 
        while (st < ed) {
            if (s.charAt(st++) != s.charAt(ed--)) {
                return false; 
            }
        }
        
        return true; 
    }
    
    private String preprocess(String s) {
        StringBuffer sb = new StringBuffer(); 
        for (int i = 0; i < s.length(); ++i) {
            char cur = s.charAt(i); 
            if ((cur >= 'a' && cur <= 'z') || (cur >= '0' && cur <= '9')) {
                sb.append(cur); 
            } else if (cur >= 'A' && cur <= 'Z') {
                sb.append((char)(cur - 'A' + 'a')); 
            }
        }
        
        return sb.toString(); 
    }
} 