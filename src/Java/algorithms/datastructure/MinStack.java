package algorithms.datastructure; 

import java.util.*; 

public class MinStack<T extends Comparable<? super T>> extends Stack<T> {
    /* Function: Implement a stack that can peek the minimum element in O(1). 
     * Solution: Maintain a min stack. When the push element is same or smaller, 
     *     push it to min stack. 
     */ 
    
    Stack<T> min = new Stack<T>(); 
    
    public T push(T item) {
        super.push(item); 
        if (min.empty() || item.compareTo(min.peek()) <= 0) {
            min.push(item); 
        }
        
        return item; 
    }
    
    public T pop() {
        if (super.empty()) {
            return null; 
        }
        
        if (super.peek().equals(min.peek())) {
            min.pop(); 
        }
        return super.pop(); 
    }
    
    public T min() {
        if (min.empty()) {
            return null; 
        }
        return min.peek(); 
    }
}