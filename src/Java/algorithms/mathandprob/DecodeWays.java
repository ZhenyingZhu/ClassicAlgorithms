package algorithms.mathandprob; 

import java.util.*; 

public class DecodeWays {
    /* Function: Give a serious of number, find how many ways to explain it to 26 words. 
     * Solution: Situations: current char is 0: if prev is 0 or is >2, return 0; else, 
     *     decode with prev number; If current value is > 26 or < 10 cannot decode with
     *     prev number; 
     */ 
    
    public int numDecodings(String s) {
        if (s == null || s.length() == 0 || s.charAt(0) == '0') {
            return 0; 
        }
        
        int[] f = new int[s.length() + 1]; 
        f[0] = 1; 
        f[1] = 1; 
        int num, pre = s.charAt(0) - '0'; 
        for (int i = 1; i < s.length(); ++i) {
            if (s.charAt(i) < '0' || s.charAt(i) > '9') {
                return 0; 
            }
            
            num = s.charAt(i) - '0'; 
            int val = pre * 10 + num; 
            pre = num; 
            
            if (num == 0) {
                if (val == 0 || val > 26) { // So 130 cannot decode
                    return 0; 
                } else {
                    f[i + 1] = f[i - 1]; 
                    continue; 
                }
            }
            
            f[i + 1] = f[i]; 
            if (val > 10 && val <= 26) {
                f[i + 1] += f[i - 1]; 
            }
        }
        
        return f[s.length()]; 
    }
}
