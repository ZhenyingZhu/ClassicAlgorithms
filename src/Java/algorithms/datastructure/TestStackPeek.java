package algorithms.datastructure; 

import java.util.*; 

public class TestStackPeek {
    /*  Function: Stack peek return objects. 
     *  Solution: So even though they are int, they aren't same. 
     */

    public static void main(String[] args) {
        MinStack ms = new MinStack(); 
        ms.push(512); 
        ms.push(-1024); 
        ms.push(-1024); 
        ms.push(512); 
        ms.pop(); 
        System.out.println(ms.getMin()); 
        ms.pop(); 
        System.out.println(ms.getMin()); 
        ms.pop(); 
        System.out.println(ms.getMin()); 
    }
}


class MinStack {
    Stack<Integer> s = new Stack<Integer>(); 
    Stack<Integer> m = new Stack<Integer>(); 
    
    public void push(int x) {
        if (m.empty() || x <= m.peek()) {
            m.push(x); 
        }
        
        s.push(x); 
    }

    public void pop() {
        if (s.empty()) {
            return; 
        }
        
        if (m.peek().equals(s.peek())) { // if use == wrong
            m.pop(); 
        }
        
        s.pop(); 
    }

    public int top() {
        if (s.empty()) {
            return Integer.MAX_VALUE; 
        }
        
        return s.peek(); 
    }

    public int getMin() {
        if (m.empty()) {
            return Integer.MAX_VALUE; 
        }
        return m.peek(); 
    }
}
