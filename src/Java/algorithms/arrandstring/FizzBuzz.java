package algorithms.arrandstring; 

import java.util.*; 

public class FizzBuzz {
    /* Function: When reach the multiple of 3, say fizz; when reach the multiple of 5, say buzz. 
     * Solution: If case. 
     */ 
    
    public String fizzbuzz(int n) {
        if (n <= 0) {
            return ""; 
        }
        
        StringBuffer sb = new StringBuffer(); 
        for (int i = 1; i <= n; ++i) {
            if (i % 3 == 0) {
                sb.append("Fizz"); 
            }
            if (i % 5 == 0) {
                sb.append("Buzz"); 
            }
            if (i % 3 != 0 && i % 5 != 0) {
                sb.append(i); 
            }
            
            if (i != n) {
                sb.append(", "); 
            }
        }
        
        return sb.toString(); 
    }
} 