package algorithms.detail; 

import java.util.*; 

public class ValidNumber {
    /* Function: Check if a string is valid number with space, sign, dot and exp. 
     * Solution: First delete space at the head and tail. 
     *     Second find dot and exp, check if only 0 and exp+1 is sign bit, and all others are numbers.
     *     Third check exp is not at head or tail and dot is not after exp. 
     *     Fourth check if exp is valid because if before exp has a dot, it always needs to be checked. 
     *     Fifth check if dot is valid. Not valid only the parts before and after are both empty. 
     */ 
    
    public boolean isNumber(String s) {
        if (s == null || s.length() == 0) {
            return false; 
        }
        
        s = s.trim(); // space
        
        int dot = -1, exp = s.length(); 
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '+' || s.charAt(i) == '-') {
                if (i != 0 && i != exp + 1) {
                    return false; // Only this two place
                }
                continue; // sign
            }
            
            if (s.charAt(i) == '.') {
                if (dot != -1) {
                    return false; // two dots
                }
                dot = i; 
            } else if (s.charAt(i) == 'e' || s.charAt(i) == 'E') {
                if (exp != s.length()) {
                    return false; 
                }
                exp = i; 
            } else if (s.charAt(i) < '0' || s.charAt(i) > '9') {
                return false; 
            }
        }
        
        if (exp == 0 || exp == s.length() - 1 || exp < dot) { 
            return false; // Also fit for all space condition
        }
        
        if (exp != s.length()) {
            if (s.charAt(exp - 1) == '+' || s.charAt(exp - 1) == '-') {
                return false; // Empty before. Don't need to judge dot
            }
            String afterExp = removeSign(s.substring(exp + 1, s.length())); 
            if (afterExp.length() == 0) {
                return false; 
            }
        }
        
        if (dot != -1) {
            String beforeDot = removeSign(s.substring(0, dot)); 
            String afterDot = s.substring(dot + 1, exp); 
            if (beforeDot.length() == 0 && afterDot.length() == 0) {
                return false; 
            }
        }
        
        return true; 
    }
    
    private String removeSign(String s) {
        // Don't need to worry about empty here. 
        if (s.length() == 0) {
            return s; 
        }
        return (s.charAt(0) == '+' || s.charAt(0) == '-') ? s.substring(1) : s; 
    }
}
