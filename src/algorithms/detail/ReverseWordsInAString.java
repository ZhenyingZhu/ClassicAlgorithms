package algorithms.detail; 

import java.util.*; 

public class ReverseWordsInAString {
    /* Function: Reverse words and output as string without trailing spaces. 
     * Solution: Use split to devide the words, skip "" and append to a string buffer. 
     */ 
    
    public String reverseWords(String s) {
        if (s == null || s.length() == 0) {
            return s; 
        }
        
        String[] arr = s.split(" "); 
        
        StringBuffer sb = new StringBuffer(); 
        for (int i = arr.length - 1; i >= 0; --i) {
            if (arr[i].equals("")) {
                continue; 
            }
            sb.append(arr[i] + " "); 
        }
        
        if (sb.length() == 0) {
            return ""; 
        }
        sb.deleteCharAt(sb.length() - 1); 
        return sb.toString(); 
    }
}
