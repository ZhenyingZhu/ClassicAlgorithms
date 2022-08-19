ackage algorithms.arrandstring; 

import java.util.*; 

public class ReplaceSpace {
    /* Function: Replace all the space with "%20" in place. 
     * Solution: Need first count the length of the result string. 
     */ 

     /* Test Case
    public static void main(String[] args) {
        char[] arr = "a c     ".toCharArray(); 
        new Test().replaceSpaces(arr, 4); 
        System.out.println(new String(arr)); 
    }
    */
    
    public void replaceSpaces(char[] arr, int len) {
        if (arr == null || len <= 0 || arr.length < len) {
            return; 
        }
        
        int pt = len - 1; 
        for (int i = 0; i < len; ++i) {
            if (arr[i] == ' ') {
                pt += 2; // space to %20 let length increase by 2
            }
        }
        
        if (pt >= arr.length) {
            return; //Origin array is too short
        }
        
        for (int i = len - 1; i >= 0; --i) {
            if (arr[i] == ' ') {
                arr[pt--] = '0'; 
                arr[pt--] = '2'; 
                arr[pt--] = '%'; 
            } else {
                arr[pt--] = arr[i]; 
            }
        }
    }
} 