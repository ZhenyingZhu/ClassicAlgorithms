package algorithms.mathandprob; 

import java.util.*; 

public class AddBinary {
    /* Function: Add two numbers that present in binary. 
     * Solution: Can be a template. 
     */ 
    
    public String addBinary(String a, String b) {
        if (a == null || a.length() == 0) {
            return b; 
        }
        if (b == null || b.length() == 0) {
            return a; 
        }
        
        StringBuffer sb = new StringBuffer(); 
        int pt1 = a.length() - 1, pt2 = b.length() - 1; 
        int c = 0; 
        while (pt1 >= 0 || pt2 >= 0 || c > 0) {
            int val1 = pt1 >= 0 ? a.charAt(pt1) - '0' : 0;
            int val2 = pt2 >= 0 ? b.charAt(pt2) - '0' : 0; 
            int num = c + val1 + val2; 
            sb.insert(0, num % 2); 
            c = num / 2; 
            --pt1; 
            --pt2; 
        }
        
        return sb.toString(); 
    }
}