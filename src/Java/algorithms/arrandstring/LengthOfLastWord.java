package algorithms.arrandstring; 

import java.util.*; 

public class LengthOfLastWord {
    /* Function: Return the length of the last word. 
     * Solution: Be careful if there is no words. 
     */ 
    
    public int lengthOfLastWord(String s) {
        if (s == null || s.length() == 0) {
            return 0; 
        }
        
        String[] arr = s.split(" "); 
        int pt = arr.length - 1; 
        while (pt >= 0 && arr[pt].length() == 0) {
            --pt; 
        }
        
        if (pt == -1) {
            return 0; 
        }
        return arr[pt].length(); 
    }
}