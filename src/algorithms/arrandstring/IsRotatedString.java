package algorithms.arrandstring; 

import java.util.*; 

public class IsRotatedString {
    /* Function: Check if two strings are rotated constructed. 
     * Solution: Copy one string twice, check another one is its substring, and then vice visa. 
    */ 
    public boolean isRotated(String s1, String s2) {
        if (s1 == null || s2 == null) {
            return s1 == s2; 
        }
        
        if (s1.length() != s2.length()) {
            return false; 
        }
        
        return ((s1 + s1).indexOf(s2) != -1); 
    }
}
