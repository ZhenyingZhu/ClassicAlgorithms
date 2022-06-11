package algorithms.datastructure; 

import java.util.*;

public class LongestValidParentheses {
    /* Function: Find the longest valid parentheses. 
     * Solution: To deal the case (()(), stack record the last invalid position
     *   If stack is empty, an integer is needed. 
    */
     public int longestValidParentheses(String s) {
        if (s == null || s.length() < 1) {
            return 0; 
        }
        
        int len = 0; 
        Stack<Integer> stack = new Stack<Integer>(); 
        int last = -1; 
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '(') {
                stack.push(i); 
            } else if (s.charAt(i) == ')') {
                if (stack.empty()) {
                    last = i; 
                } else {
                    stack.pop(); 
                    if (stack.empty()) {
                        len = Math.max(len, i - last); 
                    } else {
                        len = Math.max(len, i - stack.peek()); 
                    }
                }
            } else {
                last = i; // Unexcepted char
            }
        }
        
        return len; 
    }
}
