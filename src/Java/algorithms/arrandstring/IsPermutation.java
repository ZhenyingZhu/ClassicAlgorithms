package algorithms.arrandstring; 

import java.util.*; 

public class IsPermutation {
    /* Function: Check if two strings are permutation. 
     * Solution: Sort and compare. 
     */ 
    
    public boolean permutation(String s1, String s2) {
        if (s1 == null) {
            return s2 == null; 
        }
        if (s2 == null) {
            return s1 == null; 
        }
        if (s1.length() != s2.length()) {
            return false; 
        }
        
        char[] c1 = s1.toCharArray(), c2 = s2.toCharArray(); 
        Arrays.sort(c1); 
        Arrays.sort(c2); 
        String t1 = new String(c1); 
        String t2 = new String(c2); 
        return t1.equals(t2); 
    }
    
    public static void main(String[] args) {
        String s1 = "abc", s2 = "acc"; 
        boolean ans = new Test().permutation(s1, s2); 
        System.out.println(ans); 
    }
} 