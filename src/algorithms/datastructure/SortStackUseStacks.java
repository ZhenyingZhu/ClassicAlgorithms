package algorithms.datastructure; 

import java.util.*; 

public class SortStackUseStacks {
    /* Function: Use two stacks to sort a stack without using any other data structure. 
     * Solution: Insertion sort. 
     */ 
    
    public void sort(Stack<Integer> ori) {
        if (ori == null || ori.size() <= 1) {
            return; 
        }
        
        Stack<Integer> tmp = new Stack<Integer>(); 
        for (int i = 1; i < ori.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                tmp.push(ori.pop()); 
            }
            
            sortPush(ori, tmp, ori.pop()); 
        }
    }
    
    private void sortPush(Stack<Integer> ori, Stack<Integer> tmp, int cur) {
        while (!tmp.empty() && tmp.peek() < cur) {
            ori.push(tmp.pop()); 
        }
        ori.push(cur); 
        while (!tmp.empty()) {
            ori.push(tmp.pop()); 
        }
    }
} 
