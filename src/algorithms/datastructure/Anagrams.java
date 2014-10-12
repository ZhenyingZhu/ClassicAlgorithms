package algorithms.datastructure; 

import java.util.*;

public class Anagrams {
    /* Function: Group anagrams together. If a word has no anagram, don't output. 
     * Solution: Use the time of appearance of every char as key. 
    */
    public List<String> anagrams(String[] strs) {
        List<String> res = new ArrayList<String>(); 
        if (strs == null || strs.length <= 1) {
            return res; 
        }
        
        List<Integer> freq = new ArrayList<Integer>(26); 
        for (int i = 0; i < 26; ++i) {
            freq.add(0); 
        }
        
        HashMap<List<Integer>, List<String>> map = new HashMap<List<Integer>, List<String>>(); 
        for (int i = 0; i < strs.length; ++i) {
            List<Integer> appTime = countWord(strs[i], freq); 
            if (!map.containsKey(appTime)) {
                map.put(appTime, new ArrayList<String>()); 
            }
            map.get(appTime).add(strs[i]); 
        }
        
        for (List<Integer> key : map.keySet()) {
            if (map.get(key).size() > 1) {
                res.addAll(map.get(key)); 
            }
        }
        
        return res; 
    }
    
    private List<Integer> countWord(String str, List<Integer> freq) {
        List<Integer> res = new ArrayList<Integer>(freq); 
        for (int i = 0; i < str.length(); ++i) {
            int idx = str.charAt(i) - 'a';
            res.set(idx, res.get(idx) + 1); 
        }
        return res; 
    }
}