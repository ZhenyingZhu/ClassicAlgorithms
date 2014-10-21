package algorithms.mathandprob; 

import java.util.*; 

public class CountTwosBeforeN {
    /* Function: How many 2s are there from 0 to num. 
     * Solution: Notice 121 has 12=12+0 2s at last digit, and 110=(10+1)*10 
     *     2s at second digit, which are related to the previous digits. 
     */ 

    public int count2sInRangeAtDigit(int num) {
        if (num <= 1) {
            return 0; 
        }
        
        int sum = 0, exp = 1; 
        
        while (num > 0) {
            int twos =  num % 10 < 2 ? num / 10 : num / 10 + 1; 
            sum += twos * exp; 
            exp *= 10; 
            num /= 10; 
        }
        
        return sum; 
    }
         
    public int count2sBruteForce(int num) {
        int res = 0; 
        for (int i = 0; i <= num; ++i) {
            res += countTwo(i); 
        }
        return res; 
    }
    
    private int countTwo(int val) {
        int sum = 0; 
        while (val > 0) {
            if (val % 10 == 2) {
                ++sum; 
            }
            val = val / 10; 
        }
        return sum; 
    }
}
