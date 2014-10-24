package algorithms.rcanddp; 

import java.util.*; 

public class OptimizedParseString {
    /* Function: Given a string and a dictionary, find the minimum number of unrecognized chars. 
     * Solution: Recursively set a boundary between first and second words. P(thit) = Min(t + P(hit), P(th it)). 
     * P(th it) = Min(th + P(it), P(thi t)); 
     */ 
    
    public int parseOptimized(String s, Set<String> dict) {
        if (s == null || s.length() == 0) {
            return 0; 
        }
        if (dict == null || dict.size() == 0) {
            return s.length(); 
        }
        
        Map<String, Integer> map = new HashMap<String, Integer>(); 
        return parseHelper(s, 0, dict, map); 
    }
    
    private int parseHelper(String s, int bound, Set<String> dict, Map<String, Integer> map) {
        if (map.containsKey(s)) {
            return map.get(s); 
        }

        if (s.length() == 0 || dict.contains(s)) {
            return 0; 
        }
        int prefix = dict.contains(s.substring(0, bound + 1)) ? 0 : bound + 1; 
        if (bound == s.length() - 1) {
            return prefix; 
        }
        
        int sep = prefix + parseHelper(s.substring(bound + 1), 0, dict, map); 
        int bnd = parseHelper(s, bound + 1, dict, map); 
        int res = Math.min(sep, bnd); 
        
        map.put(s, res); 
        return res; 
    }
    
    /* Test Case
    public static void main(String[] args) {
        String a = "thit"; 
        String s = "jesslookedjustliketimherbrother"; 
        Set<String> dict = new HashSet<String>(); 
        dict.add("hi"); 
        dict.add("hit"); 
        dict.add("it"); 
        dict.add("look"); 
        dict.add("looked"); 
        dict.add("just"); 
        dict.add("like"); 
        dict.add("her"); 
        dict.add("brother"); 
        int ans = new Test().parseOptimized(a, dict); 
        System.out.print(ans + " "); 
    }
    */
}
