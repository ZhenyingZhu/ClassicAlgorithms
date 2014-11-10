package algorithms.datastructure; 

import java.util.*; 

public class MinStackSimple {
    /* Function: Implement a stack that can track the minimum element in the stack in O(1) time. 
     * Solution: Implement another stack. 
     */ 
}

class MinStack {
    private Stack<Integer> track = new Stack<Integer>(); 
    private Stack<Integer> stack = new Stack<Integer>(); 
    
    public void push(int x) {
        stack.push(x); 
        if (track.empty() || x <= track.peek()) {
            track.push(x); 
        }
    }

    public void pop() {
        if (stack.empty()) {
            return; 
        }
        
        int min = stack.pop(); 
        if (min == track.peek()) {
            track.pop(); 
        }
    }

    public int top() {
        if (stack.empty()) {
            return Integer.MAX_VALUE; 
        }
        return stack.peek(); 
    }

    public int getMin() {
        if (track.empty()) {
            return Integer.MAX_VALUE; 
        }
        return track.peek(); 
    }
}
