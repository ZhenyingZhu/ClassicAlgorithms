package algorithms.arrandstring; 

import java.util.*; 

public class DeleteVowelInPlace {
    /* Function: Delete all vowels in a string in place.  
     * Solution: Check if current char is vowel. If not, move to the unsorted slot. 
     */ 
    
    public String deleteVowel(String str) {
        char[] arr = str.toCharArray(); 
        int p = 0; 
        for (int i = 0; i < arr.length; ++i) {
            if (arr[i] != 'a' && arr[i] != 'e' && arr[i] != 'i' && arr[i] != 'o' && arr[i] != 'u' ) {
                arr[p++] = arr[i]; 
            }
        }
        return new String(arr, 0, p); 
    }
}
