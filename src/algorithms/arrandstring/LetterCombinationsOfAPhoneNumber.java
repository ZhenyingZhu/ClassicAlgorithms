package algorithms.arrandstring; 

import java.util.*; 

public class LetterCombinationsOfAPhoneNumber {
    /* Function: Input a several numbers as a string, output all the combinations it can present on a cell phone. 
     * Solution: Notice 1 is "" so that it is a little different than others. 
     */ 
    
    public List<String> letterCombinations(String digits) {
        List<String> res = new ArrayList<String>(); 
        if (digits == null ||digits.length() == 0) {
            res.add(""); 
            return res; 
        }
        
        String[] map = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
        List<String> list = new ArrayList<String>(); 
        list.add(""); 
        letterHelper(digits, 0, map, list, res); 
        
        return res;
    }
    
    private void letterHelper(String digits, int pt, String[] map, List<String> prev, List<String> res) {
        if (pt == digits.length()) {
            res.addAll(prev); 
            return; 
        }
        
        if (digits.charAt(pt) - '0' == 1) {
            letterHelper(digits, pt + 1, map, prev, res); 
            return; 
        }
        
        String cur = map[digits.charAt(pt) - '0']; 
        List<String> list = new ArrayList<String>(); 
        for (int i = 0; i < prev.size(); ++i) {
            for (char c : cur.toCharArray()) {
                list.add(prev.get(i) + c); 
            }
        }
        
        letterHelper(digits, pt + 1, map, list, res); 
    }
}