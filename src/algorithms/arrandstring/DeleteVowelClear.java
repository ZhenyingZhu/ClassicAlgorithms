package algorithms.arrandstring; 

import java.util.*; 

public class DeleteVowelClear {
    /* Function: delete all the vowels in a string. 
     * Solution: use a string to make the judgement become shorter. 
     */ 
    
    public String deleteVowelClear(String s) {
        if (s == null || s.length() == 0) {
            return s; 
        }
        
        String vow = "aeiouAEIOU"; 
        
        StringBuffer res = new StringBuffer(); 
        for (int i = 0; i < s.length(); ++i) {
            if (vow.contains(String.valueOf(s.charAt(i)))) {
                continue; 
            }
            
            res.append(s.charAt(i)); 
        }
        
        return res.toString(); 
    }
}