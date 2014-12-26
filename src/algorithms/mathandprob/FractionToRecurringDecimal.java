package algorithms.mathandprob; 

import java.util.*; 

public class FractionToRecurringDecimal {
    /* Function: Return the result of divide denominator by numerator. 
     * Solution: This code is too ugly that I am gonna cry
     */ 
    
    public String fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0) {
            return "Inf"; 
        }
        
        if (numerator == 0) {
            return "0"; 
        }
        
        StringBuffer sb = new StringBuffer(); 
        if ((((numerator ^ denominator) >>> 31) & 1) == 1) {
            sb.append("-"); 
        }
        
        long num = Math.abs((long)numerator); 
        long den = Math.abs((long)denominator);
        
        long cur = num / den; 
        sb.append(cur); 
        
        num = (num % den) * 10; 
        if (num != 0) {
            sb.append("."); 
        }
        
        Map<Long, Integer> map = new HashMap<Long, Integer>(); 
        StringBuffer fraction = new StringBuffer(); 
        int idx = 0; 
        while (num != 0) {
            if (map.containsKey(num)) {
                fraction.insert(map.get(num), "("); 
                sb.append(fraction).append(")"); 
                return sb.toString(); 
            }
            
            map.put(num, idx++); 
            cur = num / den; 
            fraction.append(cur); 
            num = (num % den) * 10; 
        }
        
        sb.append(fraction); 
        return sb.toString(); 
    }
} 
