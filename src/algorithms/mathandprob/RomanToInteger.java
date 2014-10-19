package algorithms.mathandprob; 

import java.util.*; 

public class RomanToInteger {
    /* Function: Given a roman number, convert it into integer. 
     * Solution: Each time add the current value. Notice only 4, 9
     *     does not obey the role, so use minus double: IV=1+5-2.
     */ 
    
    public int romanToInt(String s) {
        if (s == null || s.length() == 0) {
            return 0; 
        }
        
        int sum = 0, pre = 0; 
        for (int i = 0; i < s.length(); ++i) {
            int cur = romanList(s.charAt(i)); 
            sum += cur; 
            if (cur > pre) {
                sum -= 2 * pre; 
            }
            pre = cur; 
        }
        
        return sum; 
    }
    
    private int romanList(char c) {
        switch (c) {
            case 'I': return 1; 
            case 'V': return 5; 
            case 'X': return 10; 
            case 'L': return 50; 
            case 'C': return 100; 
            case 'D': return 500; 
            case 'M': return 1000; 
            default: return 0; 
        }
    }
}
