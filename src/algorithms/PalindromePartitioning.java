package algorithms; 

import java.util.*; 

public class PalindromePartitioning {
    /* Function: Return all the partitions of a string that all parts are palindrome. 
     * Solution: DFS, use a matrix to preprocess the palindrome judgement. 
    */
    public List<List<String>> partition(String s) {
        List<List<String>> res = new ArrayList<List<String>>(); 
        if (s == null || s.length() == 0) {
            return res; 
        }
        
        boolean[][] matrix = new boolean[s.length()][s.length()]; 
        List<String> list = new ArrayList<String>(); 
        partitionHelper(s, matrix, 0, list, res); 
        
        return res; 
    }
    
    private void partitionHelper(String s, boolean[][] matrix, int st, List<String> list, List<List<String>> res) {
        if (st == s.length()) {
            res.add(new ArrayList<String>(list)); 
            return; 
        }
        
        for (int i = st; i < s.length(); ++i) {
            if (isPalindrome(s, st, i, matrix)) {
                list.add(s.substring(st, i + 1)); 
                partitionHelper(s, matrix, i + 1, list, res); 
                list.remove(list.size() - 1); 
            }
        }
    }
    
    private boolean isPalindrome(String s, int st, int ed, boolean[][] matrix) {
        if (s.charAt(st) == s.charAt(ed) && (st + 1 >= ed || matrix[st + 1][ed - 1])) {
            matrix[st][ed] = true; 
            return true; 
        }
        
        return false; 
    }
}
