package algorithms.datastructure; 

import java.util.*; 

public class ValidParentheses {
    /* Function: Check if a string that contains only parentheses is valid. 
     * Solution: Use stack. 
     */ 
    
    public boolean isValid(String s) {
        if (s == null) {
            return false; 
        }
        
        String par = "(){}[]"; 
        Stack<Integer> stack = new Stack<Integer>(); 
        for (int i = 0; i < s.length(); ++i) {
            int n = par.indexOf(String.valueOf(s.charAt(i)));
            if (n < 0) { // Not a parenthese
                return false; 
            }
            
            if (n % 2 == 0) { // left
                stack.push(n); 
            } else if (stack.empty() || stack.pop() != n - 1) { // right
                return false; 
            }
        }
        
        return stack.size() == 0; 
    }
} 