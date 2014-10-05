package algorithms; 

import java.util.*; 

public class WordBreakSolution {
    /* Function: Give a string and a dictionary, find all ways to break the string 
     *     using words in dictionary. 
     * Solution: Use memory cache while DFS. Deal with string don't need recover to 
     *     prev state while DFS. Also when reach the end, inserting word is different. 
     */ 
    public List<String> wordBreak(String s, Set<String> dict) {
        if (s == null || s.length() == 0 || dict.size() == 0) {
            return new ArrayList<String>(); 
        }

        Map<String, List<String>> map = new HashMap<String, List<String>>(); 
        return search(s, dict, map); 
    }

    private List<String> search(String s, Set<String> dict, Map<String, List<String>> map) {
        if (map.containsKey(s)) {
            return map.get(s); 
        }
        List<String> res = new ArrayList<String>(); 
        
        int n = s.length(); 
        for (int i = 1; i <= n; ++i) {
            if (dict.contains(s.substring(0, i))) {
                String prev = s.substring(0, i); 
                if (i == n) {
                    res.add(prev); 
                } else {
                    List<String> tmp = search(s.substring(i), dict, map); 
                    for (String next : tmp) {
                        res.add(prev + " " + next); 
                    }
                }
            }
        }
        
        map.put(s, res); 
        return res; 
    }
}
