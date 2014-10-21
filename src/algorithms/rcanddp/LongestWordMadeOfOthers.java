package algorithms.rcanddp; 

import java.util.*; 

public class LongestWordMadeOfOthers {
    /* Function: Given an array of strings. Find the longest word that is combined
     *     by other strings except itself. 
     * Solution: First sort the array from longest to shortest. Then use a hasp map 
     *     to record if a string can be combined even by it self. Use a flag to check
     *     if it is the origin string or not. 
     */ 
    
    public String printLongestWord(String[] strs) {
        if (strs == null || strs.length == 0) {
            return null; 
        }
        
        Map<String, Boolean> map = new HashMap<String, Boolean>(); 
        for (String str : strs) {
            map.put(str, true); 
        }
        
        Arrays.sort(strs, LengthComparator); // Fron the longest to shortest
        
        for (String str : strs) {
            if (canBuild(str, true, map)) {
                return str; 
            }
        }
        
        return ""; 
    }
    
    private boolean canBuild(String str, boolean isOrigin, Map<String, Boolean> map) {
        if (map.containsKey(str) && !isOrigin) { // This is a right part of the previous call
            return true; // str is one of the component
        }
        
        for (int i = 0; i < str.length(); ++i) {
            String left = str.substring(0, i); 
            String right = str.substring(i); 
            if (map.containsKey(left) && map.get(left) && canBuild(right, false, map)) {
                map.put(str, true); // Not necessary, because when it happen, the function will done
                return true; // This part can be combined by other words. 
            }
        }
        
        map.put(str, false); 
        return false; 
    }
    
    private Comparator<String> LengthComparator = new Comparator<String>() {
        public int compare(String s1, String s2) {
            return s2.length() - s1.length(); 
        }
    }; 
}
