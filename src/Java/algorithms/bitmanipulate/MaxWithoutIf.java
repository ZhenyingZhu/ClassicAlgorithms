package algorithms.bitmanipulate; 

import java.util.*; 

public class MaxWithoutIf {
    /* Function: Find the max value in two numbers without using if else. 
     * Solution: max*1+min*0. Let a*p+b*k. If a b have different sign, p=a sign; 
     *     else, p=a-b sign. This can avoid overflow. Notice if positive, sign = 0. 
     */ 
    
    public int getMax(int a, int b) {
        int sa = getSign(a), sb = getSign(b), sc = getSign(a - b); 
        int k = (sa ^ sb & sa) | (flip(sa ^ sb) & sc); 
        int p = flip(k); 
        return p * a + k * b; 
    }
    
    private int getSign(int num) {
        return num >>> 31; 
    }
    
    private int flip(int k) {
        return k ^ 1; 
    }
}
