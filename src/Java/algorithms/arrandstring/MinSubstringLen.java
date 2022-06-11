package algorithms.arrandstring; 

import java.util.*; 

public class MinSubstringLen {
    /* Function: Return the minimun length of the substring that is consist of the whole string. 
     * Solution: Bruteforce. 
     */ 
    
    // Test Case
    public static void main(String[] args) {
        String s = "abcabcd"; 
        System.out.println(new Test().minSubstringLen(s)); 
    }
    
    public int minSubstringLen(String s) {
        if (s == null || s.length() == 0) {
            return 0; 
        }
        
        for (int i = 1; i <= s.length(); ++i) {
            String part = s.substring(0, i); 
            if (cover(s, part)) {
                return i; 
            }
        }
        
        return s.length(); 
    }
    
    private boolean cover(String str, String part) {
        int totalLen = str.length(); 
        int partLen = part.length(); 
        
        if (totalLen % partLen != 0) {
            return false; 
        }
        
        for (int i = partLen; i < totalLen - partLen; i += partLen) {
            if (!part.equals(str.substring(i, i + partLen))) {
                return false; 
            }
        }
        
        return true; 
    }
} 
