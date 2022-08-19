package algorithms.rcanddp; 

import java.util.*; 

public class WordBreak {
    /* Function: Check if a string can be combined by words in a dictionary. 
     * Solution: Use a hash map to reduce the time complexity. 
     */ 
    
    public boolean wordBreak(String s, Set<String> dict) {
        if (s == null || dict == null || dict.size() == 0) {
            return false; 
        }
        if (s.length() == 0) {
            return true; 
        }
        
        Map<Integer, Boolean> map = new HashMap<Integer, Boolean>(); 
        return isWord(s, 0, dict, map); 
    }
    
    private boolean isWord(String s, int st, Set<String> dict, Map<Integer, Boolean> map) {
        if (map.containsKey(st)) {
            return map.get(st); 
        }
        if (st == s.length()) {
            return true; 
        }
        
        for (int i = st + 1; i <= s.length(); ++i) {
            if (dict.contains(s.substring(st, i)) && isWord(s, i, dict, map)) {
                map.put(st, true); 
                return true; 
            }
        }
        
        map.put(st, false); 
        return false; 
    }
} 