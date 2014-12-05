package algorithms.datastructure; 

import java.util.*; 

public class TopplePlates {
    /* Function: Implement a set of stacks that when the size of a stack is 
     *     overwhelmed, create a new stack. 
     * Solution: When pop from a certain stack, decrease the top rather than 
     *     shift all elements. If it is empty, delete it when pop. 
     */ 
    
    /* Test Case
    public static void main(String[] args) {
        SetOfStacks<Integer> stacks = new SetOfStacks<Integer>(1); 
        stacks.push(1); 
        stacks.push(2); 
        stacks.push(3); 
        
        System.out.println(stacks.pop(1)); 
        System.out.println(stacks.pop()); 
        System.out.println(stacks.pop()); 
    }
    */
} 

class SetOfStacks<T> {
    List<T[]> stacks = new ArrayList<T[]>(); 
    List<Integer> tops = new ArrayList<Integer>(); 
    int threadhold = 1; 
    int last = -1; 
    
    public SetOfStacks(int threadhold) {
        if (threadhold <= 0) {
            System.out.println("auto create 1 size"); 
            threadhold = 1; 
        }
        
        this.threadhold = threadhold; 
    }
    
    public boolean empty() {
        return stacks.size() == 0; 
    }
    
    public void push(T item) {
        if (empty() || tops.get(last) == threadhold) {
            addStack(); 
        }
        
        stacks.get(last)[tops.get(last)] = item; 
        tops.set(last, tops.get(last) + 1); 
    }
    
    public T pop() {
        return pop(last); 
    }
    
    public T pop(int idx) {
        if (idx > last) {
            return null; 
        }
        
        int pos = tops.get(idx); 
        T res = stacks.get(idx)[pos - 1]; 
        
        if (pos == 1) {
            deleteStack(idx); 
        } else {
            tops.set(idx, pos - 1); 
        }
        
        return res; 
    }
    
    private void addStack() {
        stacks.add((T[])new Object[threadhold]); 
        tops.add(0); 
        ++last; 
    }
    
    private void deleteStack(int idx) {
        stacks.remove(idx); 
        tops.remove(idx); 
        --last; 
    }
}