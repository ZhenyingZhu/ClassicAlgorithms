package algorithms.arrandstring; 

import java.util.*; 

public class ValidPalindromeIgnoreSpeical {
    /* Function: If there are special characters. Ignore them and check if it is a palindrome. 
     * Solution: To reuse code, process the string. 
     */ 
    
    /* Test Case
    public static void main(String[] args) {
        String in = "A man, a plan, a canal: Panama"; 
        String special = " ,:"; 
        System.out.println(new Test().isPalindrome(in, special)); 
    }
    */

    public boolean isPalindrome(String s) {
        s = removeSpecial(s); 
        return checkPalindrome(s); 
    }
    
    public boolean isPalindrome(String s, String special) {
        s = removeSpecial(s, special); 
        return checkPalindrome(s); 
    }
    
    private boolean checkPalindrome(String s) {
        if (s == null) {
            return false; 
        }

        int st = 0, ed = s.length() - 1; 
        while (st < ed) {
            if (s.charAt(st++) != s.charAt(ed--)) {
                return false; 
            }
        }
        return true; 
    }
    
    private String removeSpecial(String s) {
        if (s == null || s.length() == 0) {
            return s; 
        }
        
        StringBuffer sb = new StringBuffer(); 
        
        s = s.toLowerCase(); 
        for (int i = 0; i < s.length(); ++i) {
            if (Character.isLetterOrDigit(s.charAt(i))) {
                sb.append(s.charAt(i)); 
            }
        }
        
        return sb.toString(); 
    }
    
    private String removeSpecial(String s, String special) {
        if (s == null || s.length() == 0) {
            return s; 
        }
        
        StringBuffer sb = new StringBuffer(); 
        for (int i = 0; i < s.length(); ++i) {
            String cur = String.valueOf(s.charAt(i)).toLowerCase(); 
            if (special.contains(cur)) {
                continue; 
            }
            
            sb.append(cur); 
        }
        
        return sb.toString(); 
    }
} 