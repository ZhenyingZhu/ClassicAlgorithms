package algorithms.datastructure; 

import java.util.*; 

public class EvaluateReversePolishNotation {
    /* Function: Given an array of strings that present the RPN. 
     * Solution: Use a stack to push the number. When encounter an operation, pop. 
    */ 
    public int evalRPN(String[] tokens) {
        if (tokens == null || tokens.length == 0) {
            return 0; 
        }
        
        String ops = "+-*/"; 
        Stack<Integer> stack = new Stack<Integer>(); 
        for (String cur : tokens) {
            if (ops.contains(cur)) {
                if (stack.size() < 2) { // Hasn't enough oprands
                    return 0; 
                }
                
                compute(stack, cur); 
            } else {
                try {
                    stack.push(Integer.parseInt(cur)); 
                } catch (NumberFormatException ne) {
                    System.out.println("Contains invalid String"); 
                    return 0; // Not number
                }
            }
        }
        
        if (stack.size() != 1) {
            return 0; // Too many numbers. 
        }
        
        return stack.pop(); 
    }
    
    private void compute(Stack<Integer> stack, String op) {
        int sec = stack.pop(); 
        int fir = stack.pop(); 
        switch(op) {
            case "+": stack.push(fir + sec); 
                return; 
            case "-": stack.push(fir - sec); 
                return; 
            case "*": stack.push(fir * sec); 
                return; 
            case "/": stack.push(fir / sec); 
                return; 
        }
    }
}
