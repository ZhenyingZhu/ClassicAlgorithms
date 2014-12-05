package algorithms.arrandstring; 

import java.util.*; 

public class DeleteVowelInplaceClear {
    /* Function: Delete all the vowels in the string. 
     * Solution: It is a fake inplace algorithm. 
     */ 
    
    public String deleteVowelInplaceClear(String str) {
        if (str == null || str.length() == 0) {
            return str; 
        }
        
        String vow = "aeiouAEIOU"; 
        char[] arr = new char[str.length()]; 
        
        int pt = 0; 
        for (int i = 0; i < str.length(); ++i) {
            if (!vow.contains(String.valueOf(str.charAt(i)))) {
                arr[pt++] = str.charAt(i); 
            }
        }
        
        return new String(arr, 0, pt); 
    }
}