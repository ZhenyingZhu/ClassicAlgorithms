package algorithms; 

import java.util.*; 

public class DeleteVowel {
    /* Function: Give a string, return the string with no vowel. 
     * Solution: Walk through the string, if current char is not vowel, append to the StringBuffer. 
    */ 
    public String deleteVowel(String str) {
        if (str == null || str.length() == 0) {
            return str; 
        }
        
        StringBuffer sb = new StringBuffer(); 
        for (int i = 0; i < str.length(); ++i) {
            if (str.charAt(i) == 'a' || str.charAt(i) == 'e' || str.charAt(i) == 'i' || str.charAt(i) == 'o' || str.charAt(i) == 'u') {
                continue; 
            }
            
            sb.append(str.charAt(i)); 
        }
        
        return sb.toString(); 
    }
}
