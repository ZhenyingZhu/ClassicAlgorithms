package algorithms.datastructure; 

import java.util.*; 

public class SingleArrayThreeStacks {
    /* Function: Use an array to implement three stacks.  
     * Solution: When there is still space, can always push. 
     */ 
    
    /* Test case
    public static void main(String[] args) {
        ThreeStack<Integer> stacks = new ThreeStack<Integer>(6); 
        System.out.println(stacks.push(0, 1)); 
        System.out.println(stacks.push(1, 3)); 
        System.out.println(stacks.push(0, 2)); 
        
        System.out.println(stacks.pop(1)); 
        System.out.println(stacks.pop(0)); 
        System.out.println(stacks.pop(0)); 
        
    }
    */
} 

class ThreeStack<T> {
    T[] array; 
    int[] sts = new int[3], eds = new int[3]; 
    int vol = 3; 
    
    public void printInfo() {
        System.out.println("==="); 
        for (int i = 0; i < 3; ++i) {
            System.out.println("st" + i + ": " + sts[i] + " ed" + i + ":" + eds[i]); 
        }
        System.out.println("==="); 
    }
    
    public ThreeStack(int vol) {
        if (vol < 3) {
            System.out.println("Auto create 3 slots"); 
            vol = 3; 
        } 
        
        this.vol = vol; 
        
        array = (T[])new Object[vol]; 
        for (int i = 0; i < 3; ++i) {
            sts[i] = vol / 3 * i; 
            eds[i] = sts[i]; 
        }
    }
    
    public boolean empty(int idx) {
        return (sts[idx] == eds[idx]); 
    }
    
    public int size(int idx) {
        return (eds[idx] + vol - sts[idx]) % vol; 
    }
    
    public T pop(int idx) {
        if (empty(idx)) {
            return null; 
        }
        
        int top = locate(eds[idx] - 1); 
        T res = array[top]; 
        eds[idx] = top; 
        
        return res; 
    }
    
    public boolean push(int idx, T item) {
        if (size(0) + size(1) + size(2) == vol) {
            return false; 
        }
        
        if (full(idx)) {
            shift(next(idx)); 
        }
        
        array[eds[idx]] = item; 
        eds[idx] = locate(eds[idx] + 1); 
        
        return true; 
    }
    
    private int locate(int pt) {
        if (pt >= array.length) {
            pt -= array.length; 
        } else if (pt < 0) {
            pt += array.length; 
        }
        
        return pt; 
    }
    
    private int next(int idx) {
        return (idx + 1) % 3; 
    }
    
    private boolean full(int idx) {
        return eds[idx] == sts[next(idx)]; 
    }
    
    private void shift(int idx) {
        int nxt = next(idx); 
        if (full(nxt)) {
            shift(nxt); 
        }
        
        for (int i = locate(eds[idx] - 1); i >= sts[idx]; --i) {
            array[locate(i) + 1] = array[i]; 
        }
        
        sts[idx] = locate(sts[idx] + 1); 
        eds[idx] = locate(eds[idx] + 1); 
    }
}