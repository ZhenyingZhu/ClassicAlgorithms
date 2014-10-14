package algorithms.arrandstring; 

import java.util.*; 

public class MinimumWindowSubstring {
    /* Function: Find the substring in S that contains all words in T. 
     * Solution: T may has duplicate words. So first need to count all words frequency. 
     *     Can use two hashtable (or arrays using char as index). But can also use one 
     *     hashtable. When search S, if find one in T, that freq-1. Freq becomes negative
     *     means shows more times than in T. So when freq>=0, cnt++. When cnt==T.length(), 
     *     all appears. Now move the left boundary pt. When map.get(pt)>0, pt points to 
     *     the first char in T. 
     */ 
    
    public String minWindow(String S, String T) {
        if (S == null || T == null || S.length() == 0 || S.length() < T.length()) {
            return ""; 
        }
        
        HashMap<Character, Integer> map = new HashMap<Character, Integer>(); 
        for (char c : T.toCharArray()) {
            if (!map.containsKey(c)) {
                map.put(c, 1); 
            } else {
                map.put(c, map.get(c) + 1); 
            }
        }
        
        Stack<Integer> stack = new Stack<Integer>(); 
        
        int pt = 0, st = -1, min = Integer.MAX_VALUE; 
        int contain = 0; 
        for (int i = 0; i < S.length(); ++i) {
            char cur = S.charAt(i); 
            if (!map.containsKey(cur)) {
                continue; 
            }
            
            map.put(cur, map.get(cur) - 1); 
            if (map.get(cur) >= 0) { // can be negative
                ++contain; 
            }
            
            while (contain == T.length()) {
                char c = S.charAt(pt); 
                if (!map.containsKey(c)) {
                    ++pt; 
                    continue; 
                }
                
                map.put(c, map.get(c) + 1); 
                if (map.get(c) > 0) {
                    if (i - pt + 1 < min) {
                        min = i - pt + 1; 
                        st = pt; 
                    }
                    --contain;
                }
                ++pt; 
            }
        }
        
        if (st == -1) {
            return ""; 
        }
        
        return S.substring(st, st + min); 
    }
}
