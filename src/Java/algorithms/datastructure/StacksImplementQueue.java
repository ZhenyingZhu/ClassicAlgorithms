package algorithms.datastructure; 

import java.util.*; 

public class StacksImplementQueue {
    /* Function: Use two stacks to implement a queue. 
     * Solution: When the second stack is empty, push every thing in the first one here. 
     */ 
    
    /* Test Case
    public static void main(String[] args) {
        MyQueue<Integer> q = new MyQueue<Integer>(); 
        q.offer(0); 
        q.offer(1); 
        q.offer(2); 
        while (!q.isEmpty()) {
            System.out.println(q.peek()); 
            System.out.println(q.poll()); 
        }
    }
    */
} 

class MyQueue<T> {
    Stack<T> s1, s2; 
    public MyQueue() {
        s1 = new Stack<T>(); 
        s2 = new Stack<T>(); 
    }
    
    public int size() {
        return s1.size() + s2.size(); 
    }
    
    public boolean isEmpty() {
        if (size() == 0) {
            return true; 
        }
        
        return false; 
    }
    
    public void offer(T item) {
        s1.push(item); 
    }
    
    public T poll() {
        if (s2.empty()) {
            shift(); 
        }
        
        return s2.empty() ? null : s2.pop(); 
    }
    
    public T peek() {
        if (s2.empty()) {
            shift(); 
        }
        
        return s2.empty() ? null : s2.peek(); 
    }
    
    private void shift() {
        while (!s1.empty()) {
            s2.push(s1.pop()); 
        }
    }
}