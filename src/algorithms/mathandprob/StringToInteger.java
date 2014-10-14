package algorithms.mathandprob; 

import java.util.*; 

public class StringToInteger {
    /* Function: Given a string, convert it into integer. The previous space should be omit. Stop 
     *     if encounter a none number character. If overflow 32 bit, return Integer.MAX/MIN_VALUE; 
     * Solution: When previous value is bigger than Integer.MAX_VALUE / 10 or equals it and current
     *     char is larger than Integer.MAX_VALUE % 10, can have 3 conditions: 1. just equals Integer.MAX; 
     *     2. larger than Integer.MAX; 3. equals to Integer.MIN_VALUE; 
     */ 
    
    public int atoi(String str) {
        if (str == null || str.length() == 0) {
            return 0; 
        }
        
        str = str.trim(); 
        int sign = str.charAt(0) == '-' ? -1 : 1; 
        if (str.charAt(0) == '+' || str.charAt(0) == '-') {
            str = str.substring(1); 
        }
        
        int sum = 0, pt = 0; 
        while (pt < str.length() && str.charAt(pt) >= '0' && str.charAt(pt) <= '9') {
            if (sum > Integer.MAX_VALUE / 10 || sum >= Integer.MAX_VALUE / 10 && str.charAt(pt) > Integer.MAX_VALUE % 10 + '0') {
                return sign > 0 ? Integer.MAX_VALUE : Integer.MIN_VALUE; 
            }
            sum = sum * 10 + str.charAt(pt++) - '0'; 
        }
        
        return sign * sum; 
    }
}
