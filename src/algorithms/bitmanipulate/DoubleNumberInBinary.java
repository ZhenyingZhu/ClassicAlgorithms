package algorithms.bitmanipulate; 

import java.util.*; 

public class DoubleNumberInBinary {
    /* Function: Present a double number between 0 to 1 in binary. 
     * Solution: To avoid cycle, when the length is longer than 32, break. 
     */ 
    
    public String printBinary(double num) {
        if (num >= 1 || num <= 0) {
            return "ERROR"; 
        }
        
        StringBuffer res = new StringBuffer(); 
        res.append("0."); 
        // Set<Double> appears = new HashSet<Double>(); Doesn't work because 0.2 is 0.19999 in double. 
        while (num > 0) {
            int remain = (int) (num *= 2); 
            num -= remain; 
            
            if (res.length() > 32) {
                return "ERROR"; 
            }
            res.append(remain); 
        }
        
        return res.toString(); 
    }
} 