package algorithms.arrandstring; 

import java.util.*; 

public class SubstringWithConcatenationOfAllWords {
    /* Function: Find all the start index of strings that only contain all words
     *     in a list exactly once. These words are same length. 
     * Solution: Sliding window. When find a string not in the list, reset the window. 
     *     if find the current word appears too many times, forward the window start
     *     to the word where if first appear. 
     */ 
    
    public List<Integer> findSubstring(String S, String[] L) {
        List<Integer> res = new ArrayList<Integer>(); 
        if (L == null || L.length == 0) {
            return res; 
        }
        int len = L[0].length(), amt = L.length; 
        if (S == null || S.length() < amt * len) {
            return res; 
        }
        
        Map<String, Integer> dict = new HashMap<String, Integer>(); 
        for (String word : L) {
            if (!dict.containsKey(word)) {
                dict.put(word, 1); 
            } else {
                dict.put(word, dict.get(word) + 1); 
            }
        }
        
        for (int i = 0; i < len; ++i) {
            findHelper(S, i, len, amt, dict, res); 
        }
        
        return res; 
    }
    
    private void findHelper(String S, int offset, int len, int amt, Map<String, Integer> dict, List<Integer> res) {
        Map<String, Integer> map = new HashMap<String, Integer>(); 
        int cnt = 0, st = offset; 
        for (int i = offset; i <= S.length() - len; i += len) {
            String cur = S.substring(i, i + len); 
            if (!dict.containsKey(cur)) { // reset
                st = i + len; 
                cnt = 0; 
                map = new HashMap<String, Integer>(); 
                continue; 
            }
            
            ++cnt; 
            if (!map.containsKey(cur)) {
                map.put(cur, 1); 
            } else {
                map.put(cur, map.get(cur) + 1); 
            }
            
            while (map.get(cur) > dict.get(cur)) { // more than needed
                deleteHead(S, map, st, len); 
                st += len; 
                --cnt; 
            }
            
            if (cnt == amt) { // find 
                res.add(st); 
                deleteHead(S, map, st, len); 
                st += len; 
                --cnt; 
            }
        }
    }
    
    private void deleteHead(String S, Map<String, Integer> map, int st, int len) {
        String head = S.substring(st, st + len); 
        map.put(head, map.get(head) - 1); 
    }
}
