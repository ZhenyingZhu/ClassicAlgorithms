package algorithms.arrandstring; 

import java.util.*; 

public class LongestSubstringWithoutRepeatingCharacters {
    /* Function: Find the longest substring string that has no repeate characters. 
     * Solution: Sliding window. 
     */ 
    
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() == 0) {
            return 0; 
        }
        
        int st = 0, max = 1; 
        Set<Character> set = new HashSet<Character>(); 
        for (int i = 0; i < s.length(); ++i) {
            while (set.contains(s.charAt(i))) {
                set.remove(s.charAt(st++)); 
            }
            set.add(s.charAt(i)); 
            max = Math.max(max, i - st + 1); 
        }
        
        return max; 
    }
}
