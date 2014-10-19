package algorithms.arrandstring; 

import java.util.*; 

public class CountAndSay {
    /* Function: At first 1. Count there is a one, so next is 11. Then 21, then 1211. 
     *     Return the n th string. 
     * Solution: Quite stright forward, but serval points need to be notice: 1. the first
     *     string is 1, so when n=1 should not do anything. 2. The last part of string should 
     *     also be counted. 3. The string buffer should be reseted each running time. 4. The 
     *     append order. 
     */ 
    
    public String countAndSay(int n) {
        if (n <= 0) {
            return ""; 
        }
        
        String prev = "1"; 
        StringBuffer sb = new StringBuffer(); 
        for (int i = 1; i < n; ++i) {
            sb.setLength(0); 
            int cnt = 1; 
            for (int j = 1; j < prev.length(); ++j) {
                if (prev.charAt(j) != prev.charAt(j - 1)) {
                    sb.append(cnt).append(prev.charAt(j - 1)); 
                    cnt = 1; 
                } else {
                    ++cnt; 
                }
            }
            sb.append(cnt).append(prev.charAt(prev.length() - 1)); 
            
            prev = sb.toString(); 
        }
        
        return prev; 
    }
}
