package algorithms.arrandstring; 

import java.util.*;

public class ImplementStrStr {
    /* Function: If cannot find needle, return null.  
         else, return the first occurance of needle. 
     * Solution: Use one by one check. O(mn). 
    */
    public String strStr(String haystack, String needle) {
        if (needle == null || needle.length() == 0) {
            return haystack; 
        }
        if (haystack == null || haystack.length() < needle.length()) {
            return null; 
        }

        int i, j; 
        for (i = 0; i <= haystack.length() - needle.length(); ++i) {
            for (j = 0; j < needle.length(); ++j) {
                if (haystack.charAt(i + j) != needle.charAt(j)) {
                    break; 
                }
            }
            if (j == needle.length()) {
                return haystack.substring(i); 
            }
        }
        
        return null; 
    }
}
